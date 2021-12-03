#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "VertexListFormat.h"
#define debug printf("todo bien\n");

#define SIZE_N 400
#define SIZE_M 400

typedef struct RGB {

    int red;
    int green;
    int blue;

} RGB;

typedef struct ListOfPixels{

    int * x_pixels;
    int numberOf_x_pixels;

    int * y_pixels;
    int numberOf_y_pixels;

} ListOfPixels;

typedef struct MaxMinOfFace {

    double min_x;
    double max_x;
    double min_y;
    double max_y;

} MaxMinOfFace;



double absD (double n);
double maxD(double a, double b);
double minD(double a, double b);


MaxMinOfFace obtainMaxMinOfFace(Face f);
void drawFinalFigure(RGB frame[SIZE_N+1][SIZE_M+1]);
void DrawLineDDA (Point p0, Point p1, RGB frame[SIZE_N+1][SIZE_M+1]);
void scanlineAlgorithm(Face faceToRender, ListOfPixels listPixels[3], RGB frame[SIZE_N+1][SIZE_M+1]);
void DigitalDifferentialAnalyser(Point p0, Point p1, int indexList, ListOfPixels listPixels[3], RGB frame[SIZE_N+1][SIZE_M+1]);