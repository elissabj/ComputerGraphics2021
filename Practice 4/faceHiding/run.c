#include "run.h"

void run(void){


    VertexListFormat figure;
    Point pointView;

    FILE* file = fopen("input.txt", "r");

    if(file == NULL){
        printf("Can't open file.\n");
        return;
    }

    
    int numPoints, numEdges, numFaces;
    while (!feof(file)) {

        fscanf(file, "%lf %lf %lf", &pointView.x, &pointView.y, &pointView.z);
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
    continueProcess(figure, pointView);


return;
}


void continueProcess(VertexListFormat figure, Point focalPoint){

    for(int i = 0; i < figure.numFaces; i++){

        if(isFaceHiding(figure.faces[i], focalPoint) == 1 ){
            printf("No se ve la cara %d\n", i+1);
        } else {
            printf("Si se ve la cara %d\n", i+1);
        }
    }

return;
}