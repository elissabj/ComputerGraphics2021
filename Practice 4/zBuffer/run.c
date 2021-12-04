#include "run.h"
#define debug printf("todo bien\n");

void run(void){

    VertexListFormat figure;
    RGB frame[SIZE_N+1][SIZE_M+1];
    
    for(int i = 0; i < SIZE_N; i++){
        for(int j = 0; j < SIZE_M; j++){
            frame[i][j].red = 0;
            frame[i][j].green = 0;
            frame[i][j].blue = 0;
        }
    }


    FILE* file = fopen("input.txt", "r");

    if(file == NULL){
        printf("Can't open file.\n");
        return;
    }

    int numPoints, numEdges, numFaces;
    while (!feof(file)) {
        fscanf(file, "%d %d %d", &numPoints, &numEdges, &numFaces);
        
        Point* points = (Point*)malloc(sizeof(Point)*numPoints);
        Face* faces = (Face*)malloc(sizeof(Face) *numFaces);
        Edge* edges = (Edge*)malloc(sizeof(Edge)*numEdges);
        
        
        for(int i = 0; i < numPoints; i++){                                 //Reading points
            
            Point p; 
            p.index = i+1;
            fscanf(file, "%lf %lf %lf", &p.x, &p.y, &p.z);
            p.w = 1;
            points[i] = p;
        }

        
        for(int i = 0; i < numEdges; i++){                                  //Reading edges
            
            Edge edge; 
            int from, to;
            
            fscanf(file, "%d %d", &from, &to);
            edge.index = i+1;

            edge.from = points[from-1];
            edge.to = points[to-1];
            edges[i] = edge;
        }

        
        for(int i = 0; i < numFaces; i++){                                  //Reading faces
            
            int e1, e2, e3;
            fscanf(file, "%d %d %d", &e1, &e2, &e3);

            Face face;
            face.index = i+1;
            
            face.e1 = edges[e1-1];
            face.e2 = edges[e2-1];
            face.e3 = edges[e3-1];
            faces[i] = face;
        }
        
        figure.points = points;
        figure.numPoints = numPoints;

        figure.edges = edges;
        figure.numEdges = numEdges;

        figure.faces = faces;
        figure.numFaces = numFaces;

        break;
    }

    fclose(file);

    continueProcess(figure, frame);

return;
}



void continueProcess(VertexListFormat figure, RGB frame[SIZE_N+1][SIZE_M+1]){

    for(int i = figure.numFaces-1; i >= 0; i--){
        RGB color;
        if(i == 0){
            color.red = 255;
            color.green = 0;
            color.blue = 0;
        }else if(i == 1){
            color.red = 0;
            color.green = 0;
            color.blue = 255;
        }else if(i == 2){
            color.red = 0;
            color.green = 255;
            color.blue = 0;
        }else{
            color.red = 255;
            color.green = 255;
            color.blue = 255;
        }
        
        figure.faces[i].colorOfFace = color;
        renderFace(figure.faces[i], frame, color);
    }

    zbufferAlgorithm(figure, 1, frame);

return;
}