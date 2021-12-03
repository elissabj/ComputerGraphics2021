#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "VertexListFormat.h"

double dotProduct(Point a, Point b);                                        //Operations with points
Point sumVectors (Point a, Point b);
Point crossProduct(Point a, Point b);
int areEqualsPoints(Point a, Point b);
Point substractVectors(Point a, Point b);

Point * obtaintTreePointsOfAFace(Face f);                                   //Obtain with point are involve
int isFaceHiding(Face f, Point focalPoint);                                 //Tell if the face its seen or not




