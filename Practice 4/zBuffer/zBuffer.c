#include "zBuffer.h"

void renderFace (Face faceToRender, RGB frame[SIZE_N+1][SIZE_M+1], RGB color){

    Edge auxEdge;
    Point p1, p2;


    auxEdge = faceToRender.e1;
    p1 = auxEdge.from;
    p2 = auxEdge.to;

    DrawLineDDA(p1, p2, frame, color);


    auxEdge = faceToRender.e2;
    p1 = auxEdge.from;
    p2 = auxEdge.to;

    DrawLineDDA(p1, p2, frame, color);

    
    auxEdge = faceToRender.e3;
    p1 = auxEdge.from;
    p2 = auxEdge.to;

    DrawLineDDA(p1, p2, frame, color);

return;
}

void DrawLineDDA (Point p0, Point p1, RGB frame[SIZE_N+1][SIZE_M+1], RGB color) {


    double dx = p1.x - p0.x;                                                                            //X and Y differentials
    double dy = p1.y - p0.y;

    int steps;

    double x_buffer = p0.x;                                                                             //X and Y values of the pixel that will be turned ON
    double y_buffer = p0.y;


    double x_increment;                                                                                 //X and Y increments
    double y_increment;

    
    if (absD(dx) > absD(dy)) {                                                                          //Define the number of steps based on the greater differential
        steps = absD(dx); 
    } else {
        steps = absD(dy);
    }

    
    x_increment = dx / steps;                                                                           //Calculate X and Y increment
    y_increment = dy / steps;
    

    for (int i = 0; i < steps; i++) {                                                                   //Loop for incrementing X and Y coordinates 
        x_buffer += x_increment;
        y_buffer += y_increment;
        
        int x = round(x_buffer);
        int y = round(y_buffer);

        frame[x][y] = color;
        
    } 

return;
}

void obtainPixelsOfEdge (Edge edge, ListOfPixels * listPixels) {
    
    Point p0, p1;
    p0 = edge.from;
    p1 = edge.to;


    float dx = p1.x - p0.x;                                                                             //X and Y differentials
    float dy = p1.y - p0.y;


    int steps;

   
    float x_buffer = p0.x;                                                                              //X and Y values of the pixel that will be turned ON
    float y_buffer = p0.y;

    float x_increment;
    float y_increment;

    
    if (abs(dx) > abs(dy)) {
        steps = abs(dx); 
    } else {
        steps = abs(dy);
    }


    x_increment = dx / steps;
    y_increment = dy / steps;
    
    for (int i = 0; i < steps; i++) {
        
        x_buffer += x_increment;
        y_buffer += y_increment;
        
        int x = round(x_buffer);
        int y = round(y_buffer);

        listPixels->x_pixels[ listPixels->numberOfPixels ] = x;   
        listPixels->y_pixels[ listPixels->numberOfPixels ] = y;   

        listPixels->numberOfPixels++;

    } 

return;
}

ListOfPixels obtainPixelsOfFace (Face face){


    ListOfPixels listPixels;
    listPixels.x_pixels = malloc(sizeof(double) * 100000);
    listPixels.y_pixels = malloc(sizeof(double) * 100000);


    obtainPixelsOfEdge(face.e1, &listPixels);
    obtainPixelsOfEdge(face.e2, &listPixels);
    obtainPixelsOfEdge(face.e3, &listPixels);
    
return listPixels;
}

ListOfPixels obtainPixelsOfFaceWithScanLine (Face face){

    MaxMinOfFace mmf = obtainMaxMinOfFace(face); 
    ListOfPixels listPixels = obtainPixelsOfFace(face); 


    for(int it = mmf.min_y+1; it < mmf.max_y; it++){ 

        Point p1, p2;
        int pixel_x1 = -1, pixel_x2 = -1; 
        
        for(int i = 0; i < listPixels.numberOfPixels; i++){

            int ypixel = listPixels.y_pixels[i];
            if(ypixel == it && pixel_x1 == -1){
                pixel_x1 = listPixels.x_pixels[i];
            } else if(ypixel == it && pixel_x2 == -1){
                pixel_x2 = listPixels.x_pixels[i];
            }
        }

        p1.x = pixel_x1;
        p1.y = it;
        p1.z = 1;
        p1.w = 1;

        p2.x = pixel_x2;
        p2.y = it;
        p2.z = 1;
        p2.w = 1;

     
        Edge edge;
        edge.from = p1;
        edge.to = p2;

        obtainPixelsOfEdge(edge, &listPixels);
    }

return listPixels;
}

void scanlineAlgorithm(Face faceToRender, RGB color, RGB frame[SIZE_N+1][SIZE_M+1]){

    MaxMinOfFace mmf = obtainMaxMinOfFace(faceToRender); 
    ListOfPixels listPixels = obtainPixelsOfFace(faceToRender);


    for(int it = mmf.min_y+1; it < mmf.max_y; it++){ 

        Point p1, p2;
        int pixel_x1 = -1, pixel_x2 = -1; 
        
        for(int i = 0; i < listPixels.numberOfPixels; i++){

            int ypixel = listPixels.y_pixels[i];
            if(ypixel == it && pixel_x1 == -1){
                pixel_x1 = listPixels.x_pixels[i];
            } else if(ypixel == it && pixel_x2 == -1){
                pixel_x2 = listPixels.x_pixels[i];
            }
        }


        p1.x = pixel_x1;
        p1.y = it;
        p1.z = 1;
        p1.w = 1;

        p2.x = pixel_x2;
        p2.y = it;
        p2.z = 1;
        p2.w = 1;

        DrawLineDDA(p1, p2, frame, color);
    }

return;
}

void zbufferAlgorithm(VertexListFormat vlf, int useScanline, RGB frame [SIZE_N+1][SIZE_M+1]){


    double depth[SIZE_N][SIZE_M];                                                                       //Depth matrix por each pixel  
    RGB refresh[SIZE_N][SIZE_M];                                                                        //Depending depth to color or not frame

    for(int i = 0; i < SIZE_N; i++){
        for(int j = 0; j < SIZE_M; j++){
            refresh[i][j].red = 100;
            refresh[i][j].green = 100;
            refresh[i][j].blue = 100;

            depth[i][j] = 100000000.0; 
        }
    }


    for(int i = 0; i < vlf.numFaces; i++){                                                              //For each face

        Point * points = obtaintTreePointsOfAFace(vlf.faces[i]);
        Point u, v, w;
        u = points[0];
        v = points[1];
        w = points[2];

        Point normalVector = crossProduct( substractVectors(u,v), substractVectors(w,v) );              //Calculate the normal vector for the plane ecuation


        double A = normalVector.x;                                                                      //Calculate coefficients
        double B = normalVector.y;
        double C = normalVector.z;
        double D = A*v.x + B*v.y + C*v.z;

        ListOfPixels listPixels;                                                                        //List of pixels and check the scanline

        if (useScanline == 1){
            ListOfPixels listPixels = obtainPixelsOfFaceWithScanLine(vlf.faces[i]);    
        } else if (useScanline == 0) {
            ListOfPixels listPixels = obtainPixelsOfFace(vlf.faces[i]);   
        } else {
            exit(1);
        }


        for(int j = 0; j < listPixels.numberOfPixels; j++){                                             //Iterate for all pixels that are in the face 

            int x = listPixels.x_pixels[j];
            int y = listPixels.y_pixels[j];

            double z = (-A*x - B*y - D) / C;

            if(z < depth[x][y]){                                                                        //Wins the "z battle" and painted
                depth[x][y] = z;
                refresh[x][y] = vlf.faces[i].colorOfFace;
            }

        }

    }


    drawFinalFigure(frame);
    drawFinalFigureWithZBuffer(refresh);

    return;
}

void drawFinalFigureWithZBuffer( RGB refresh[SIZE_N][SIZE_M]){

    FILE  *fobj = fopen("imagezBuffer.ppm", "w");
    (void) fprintf(fobj, "P3\n%d %d\n255\n", SIZE_N, SIZE_M);  

    for(int i = 0; i < SIZE_N; i++){
        for(int j = 0; j < SIZE_M; j++){
            fprintf(fobj, "%d %d %d ", refresh[i][j].red, refresh[i][j].green, refresh[i][j].blue);
        }
        fprintf(fobj, "\n");
    }

    fprintf(fobj, "\n");
    fclose(fobj);

return;
}

void drawFinalFigure(RGB frame[SIZE_N+1][SIZE_M+1]){

    FILE  *fobj = fopen("imageWithoutzBuffer.ppm", "w");
    (void) fprintf(fobj, "P3\n%d %d\n255\n", SIZE_N, SIZE_M);  

    for(int i = 0; i < SIZE_N; i++){
        for(int j = 0; j < SIZE_M; j++){
            fprintf(fobj, "%d %d %d ", frame[i][j].red, frame[i][j].green, frame[i][j].blue);
        }
        fprintf(fobj, "\n");
    }

    fprintf(fobj, "\n");
    fclose(fobj);

return;
}