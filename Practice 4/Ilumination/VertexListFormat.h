#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_N 500
#define SIZE_M 500

typedef struct Point{                                                   //Define points
    int index;
    double x;
    double y;
    double z;
    double w;

}Point;

typedef struct RGB {                                                    //Define RGB as datatype

    int red;
    int green;
    int blue;

} RGB;


typedef struct Light {

	Point position;
	RGB color;
	double a, b, c;

} Light;

double absD (double n);                                                 //Math functions for doubles
double distance (Point p0, Point p1);
double attenuationLight (double d, Light light);
double attenuation (double d, double a, double b, double c);



