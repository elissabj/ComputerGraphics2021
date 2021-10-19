#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#include "Point.h"
#include "RenderAlgorithm.h"


float minPoint ( float a, float b){                                                                     //Function to calculate the MIN for floats
    return (a<b)? a:b;
}

float maxPoint ( float a, float b){                                                                     //Function to calculate the MAX for floats
    return (a>b)? a:b;
}

void coordinatesPositives(Point *points, float miniPointX, float miniPointY, int size){                 //Move the points to the fisrt octant

    for(int j = 0; j < size; j++){

        points[j].x = (points[j].x - miniPointX);
        points[j].y = (points[j].y - miniPointY);
    }

return;
}

void printFaces(Faces * arr_face, int MAXI, Point *points, int ctFrame){                                //Make the magic with the RederAlgorithm library
    clean();
    int i; int j; 

    for(i = 0; i < MAXI; i++){
        for(j = 0; j < MAXSIZE-1; j++){

            int posPointA = arr_face[i].connections[j];                                                 //Obtain which points are connected 
            int posPointB = arr_face[i].connections[j+1];

            int x1 = (int)points[posPointA].x;                                                          //Obtain the pair por points 
            int y1 = (int)points[posPointA].y;

            int x2 = (int)points[posPointB].x;
            int y2 = (int)points[posPointB].y;

            //NaiveApproach (x1, y1, x2, y2);                                                           //Calls any render algorithm avaible that its
            //DDA(x1, y1, x2, y2);                                                                      //Naive approach, DDA or Bresenham and pass 
            Bresenham(x1, y1, x2, y2);                                                                  //the pair of poins to draw lines
        }
    }

    goesToMagic(ctFrame);                                                                               //Calls the funtion to draw all the figure

return;
}


