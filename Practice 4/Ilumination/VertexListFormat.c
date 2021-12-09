#include "VertexListFormat.h"

double absD (double n){
    return ( (n>0) ? n : ( n * (-1)));   
}

double distance (Point p0, Point p1){

	double dist = sqrt( pow( p0.x-p1.x , 2 ) + pow( p0.y-p1.y, 2 ) + pow( p0.z-p1.z ,2 ) );	
	return dist;
}

double attenuation (double d, double a, double b, double c){
	return 1.0 / ( a*d*d + b*d + c);
}

double attenuationLight (double d, Light light){
	return 1.0 / (light.a*d*d + light.b*d + light.c);
}