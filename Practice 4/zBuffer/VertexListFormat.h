#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_N 400
#define SIZE_M 400

typedef struct Point{                                                   //Define points
    int index;
    double x;
    double y;
    double z;
    double w;

}Point;

typedef struct Edge {                                                   //Define edges

    int index;
    Point from;
    Point to;

}Edge;

typedef struct RGB {                                                    //Define RGB as datatype

    int red;
    int green;
    int blue;

} RGB;

typedef struct ListOfPixels{                                            //To save all pixels 

    int numberOfPixels;
    int * x_pixels;
    int * y_pixels;

} ListOfPixels;

typedef struct Face {                                                   //Define faces

    int index;
    Edge e1;
    Edge e2;
    Edge e3;

    ListOfPixels listOfPixels;
    RGB colorOfFace;

}Face;

typedef struct VertexListFormat {

    Point * points;                                                     //List of points
    int numPoints;

    Edge * edges;                                                       //List of edges
    int numEdges;

    Face * faces;                                                       //List of faces
    int numFaces;

} VertexListFormat;

typedef struct MaxMinOfFace {                                           //To know maximum or minimum values

    double min_x;
    double max_x;
    double min_y;
    double max_y;

} MaxMinOfFace;


double dotProduct(Point a, Point b);                                    //Vectorial operation functions to help
Point sumVectors (Point a, Point b);                                    //for calculate specific vector to make
Point crossProduct(Point a, Point b);                                   // the scanline and zBuffer algorithm
int areEqualsPoints(Point a, Point b);
Point substractVectors(Point a, Point b);

Point * obtaintTreePointsOfAFace(Face f);                               //Auxiliar functions to make easier
MaxMinOfFace obtainMaxMinOfFace(Face f);                                //taking information

int abs (int n);                                                        //Math functions
int max (int a, int b);
int min (int a, int b);

double absD (double n);                                                 //Math functions for doubles
double maxD(double a, double b);
double minD(double a, double b);