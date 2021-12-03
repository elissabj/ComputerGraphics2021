#include "ScanLine.h"


double absD (double n){
    return ( (n>0) ? n : ( n * (-1)));
}
double maxD(double a, double b){
    if(a >= b) return a;
    return b;
}
double minD(double a, double b){
    if(a <= b) return a;
    return b;
}


void DrawLineDDA (Point p0, Point p1, RGB frame[SIZE_N+1][SIZE_M+1]) {


    double dx = p1.x - p0.x;                                                //X and Y differentials
    double dy = p1.y - p0.y;

    int steps;

    double x_buffer = p0.x;                                                 //X and Y values of the pixel that will be turned ON
    double y_buffer = p0.y;


    double x_increment;                                                     //X and Y increments
    double y_increment;

    
    if (absD(dx) > absD(dy)) {                                              //Define the number of steps based on the greater differential
        steps = absD(dx); 
    } else {
        steps = absD(dy);
    }

    
    x_increment = dx / steps;                                               //Calculate X and Y increment
    y_increment = dy / steps;
    

    for (int i = 0; i < steps; i++) {                                       //Loop for incrementing X and Y coordinates 
        x_buffer += x_increment;
        y_buffer += y_increment;
        
        int x = round(x_buffer);
        int y = round(y_buffer);

        frame[x][y].red = 132;
        frame[x][y].green = 182;
        frame[x][y].blue = 244;
        
    } 

    return;
}

void DigitalDifferentialAnalyser (Point p0, Point p1, int indexList, ListOfPixels listPixels[3], RGB frame[SIZE_N+1][SIZE_M+1]) {


    double dx = p1.x - p0.x;                                                //X and Y differentials
    double dy = p1.y - p0.y;

    int steps;                                                              //unit steps

    double x_buffer = p0.x;                                                 //X and Y values of the pixel that will be turned ON
    double y_buffer = p0.y;

    double x_increment;                                                     //X and Y increments
    double y_increment;


    if (absD(dx) > absD(dy)) {                                              //Define the number of steps based on the greater differential
        steps = absD(dx); 
    } else {
        steps = absD(dy);
    }

   
    x_increment = dx / steps;                                               //Calculate X and Y increment
    y_increment = dy / steps;
    

    int * listX = malloc(sizeof(int)*steps);                                //Turn on the first pixel (exact coordinates of p0)
    int * listY = malloc(sizeof(int)*steps);

    
    for (int i = 0; i < steps; i++) {                                       //Loop for incrementing X and Y coordinates 
    
        x_buffer += x_increment;
        y_buffer += y_increment;
        
        int x = round(x_buffer);
        int y = round(y_buffer);

        frame[x][y].red = 132;
        frame[x][y].green = 182;
        frame[x][y].blue = 244;
        

        listX[i] = x;                                                       //Store the list of the pixels in x
        listY[i] = y;                                                       //Store the list of the pixels in y
    } 

    listPixels[indexList].x_pixels = listX;  
    listPixels[indexList].y_pixels = listY;

    listPixels[indexList].numberOf_x_pixels = steps;  
    listPixels[indexList].numberOf_y_pixels = steps;  
  

    indexList++;
   
    return;
}


MaxMinOfFace obtainMaxMinOfFace(Face f){

    double minX = 1e9, minY = 1e9, maxX = -1, maxY = -1;


    Edge e = f.e1;                                                          //For the Edge 1

    minX = minD(minX, e.from.x);                                            //Min of the edge
    minY = minD(minY, e.from.y);

    minX = minD(minX, e.to.x);
    minY = minD(minY, e.to.y);

    
    maxX = maxD(maxX, e.from.x);                                            //Max of the edge
    maxY = maxD(maxY, e.from.y);

    maxX = maxD(maxX, e.to.x);
    maxY = maxD(maxY, e.to.y);


    e = f.e2;                                                               //For the Edge 2

    minX = minD(minX, e.from.x);                                            //Min of the edge 2
    minY = minD(minY, e.from.y);

    minX = minD(minX, e.to.x);
    minY = minD(minY, e.to.y);

    maxX = maxD(maxX, e.from.x);                                            //Max of the edge 2
    maxY = maxD(maxY, e.from.y);

    maxX = maxD(maxX, e.to.x);
    maxY = maxD(maxY, e.to.y);


    e = f.e3;                                                               //For the Edge 3

    
    minX = minD(minX, e.from.x);                                            //Min for the edge 3
    minY = minD(minY, e.from.y);

    minX = minD(minX, e.to.x);
    minY = minD(minY, e.to.y);
    
    maxX = maxD(maxX, e.from.x);                                            //Max of the edge 3
    maxY = maxD(maxY, e.from.y);

    maxX = maxD(maxX, e.to.x);
    maxY = maxD(maxY, e.to.y);

    MaxMinOfFace result;                                                    //The resultant struct

    result.min_x = minX;
    result.min_y = minY;
    
    result.max_x = maxX;
    result.max_y = maxY;
    
    return result;
}


void scanlineAlgorithm(Face faceToRender, ListOfPixels listPixels[3], RGB frame[SIZE_N+1][SIZE_M+1]){

    MaxMinOfFace mmf = obtainMaxMinOfFace(faceToRender);                    //Obtain the maximum and minimum of the face


    for(int it = mmf.min_y+1; it < mmf.max_y; it++){ 

        Point p1, p2;

        int pixel_x1 = -1, pixel_x2 = -1;                                   //From-To what pixel redering in x 

        for(int i = 0; i < 3; i++){                                         //Render all the faces
            for(int j = 0; j < listPixels[i].numberOf_y_pixels; j++){       

                int y = listPixels[i].y_pixels[j];
                if(y == it && pixel_x1 == -1){
                    pixel_x1 = listPixels[i].x_pixels[j];
                } else if(y == it && pixel_x2 == -1){
                    pixel_x2 = listPixels[i].x_pixels[j];
                }

            }
        }

        p1.x = pixel_x1;                                                    //Save values of pixels
        p1.y = it;
        p1.z = 1;
        p1.w = 1;

        p2.x = pixel_x2;
        p2.y = it;
        p2.z = 1;
        p2.w = 1;

        DrawLineDDA(p1, p2, frame);                                                //Fill the figure
    }

    drawFinalFigure(frame);

    return;
}

void drawFinalFigure(RGB frame[SIZE_N+1][SIZE_M+1]){

    FILE  *fobj = fopen("imagenScanLine.ppm", "w");
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