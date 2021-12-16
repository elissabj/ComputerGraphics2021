#include "VertexListFormat.h"

int IsSamePoint( Point p0, Point p1 ) {
	if(p0.x == p1.x && p0.y == p1.y && p0.z == p1.x) return 1;
	return 0;
}

Point sumVectors (Point a, Point b){
    Point ans;

    ans.x = a.x + b.x;
    ans.y = a.y + b.y;
    ans.z = a.z + b.z;

    return ans;

}


Point substractVectors(Point a, Point b){
    Point ans;

    ans.x = a.x - b.x;
    ans.y = a.y - b.y;
    ans.z = a.z - b.z;

    return ans;
}


Point crossProduct(Point a, Point b){

    Point result;

    result.x = a.y*b.z - a.z*b.y;
    result.y = -(a.x*b.z - a.z*b.x);
    result.z = a.x*b.y - a.y*b.x;

    return result;
}


double dotProduct(Point a, Point b){

    double result = a.x*b.x + a.y*b.y + a.z*b.z;
    return result;
}


int areEqualsPoints(Point a, Point b){

    if(a.x == b.x && a.y == b.y && a.z == b.z) return 1;
    return 0;
}


Point * obtaintTreePointsOfAFace(Face f){

    Edge e1 = f.e1;
    Edge e2 = f.e2;
    Edge e3 = f.e3;

    Point * points = malloc(sizeof(Point)*3);
    points[0] = e1.from;
    points[1] = e1.to;

   
    if (areEqualsPoints(e2.from, e1.from) == 1){ 
        points[2] = e2.to;

    } else { 
        if(areEqualsPoints(e2.to, e1.from) == 1){ 
            
            points[2] = e2.from;

        } else { 
            if (areEqualsPoints(e2.from, e1.to) == 1){ 
                points[2] = e2.to;
            } else {
                points[2] = e2.from;
            }

        }

    }

    return points;

}


MaxMinOfFace obtainMaxMinOfFace(Face f){

    double minX = 1e9, minY = 1e9, maxX = -1, maxY = -1;
    
    Edge e = f.e1;
    minX = minD(minX, e.from.x);
    minY = minD(minY, e.from.y);

    minX = minD(minX, e.to.x);
    minY = minD(minY, e.to.y);

    maxX = maxD(maxX, e.from.x);
    maxY = maxD(maxY, e.from.y);

    maxX = maxD(maxX, e.to.x);
    maxY = maxD(maxY, e.to.y);


    e = f.e2;
    minX = minD(minX, e.from.x);
    minY = minD(minY, e.from.y);

    minX = minD(minX, e.to.x);
    minY = minD(minY, e.to.y);

    maxX = maxD(maxX, e.from.x);
    maxY = maxD(maxY, e.from.y);

    maxX = maxD(maxX, e.to.x);
    maxY = maxD(maxY, e.to.y);


    e = f.e3;
    minX = minD(minX, e.from.x);
    minY = minD(minY, e.from.y);

    minX = minD(minX, e.to.x);
    minY = minD(minY, e.to.y);

    maxX = maxD(maxX, e.from.x);
    maxY = maxD(maxY, e.from.y);

    maxX = maxD(maxX, e.to.x);
    maxY = maxD(maxY, e.to.y);


    MaxMinOfFace result;

    result.min_x = minX;
    result.min_y = minY;
    
    result.max_x = maxX;
    result.max_y = maxY;
    
    return result;
}


int max (int a, int b){
    if(a >= b) return a;
    return b;
}

int min (int a, int b){
    if(a <= b) return a;
    return b;
}

double maxD(double a, double b){

    if(a >= b) return a;
    return b;
}

double minD(double a, double b){

    if(a <= b) return a;
    return b;
}

int abs (int n){
    return ( (n>0) ? n : ( n * (-1)));
}

double absD (double n){
    return ( (n>0) ? n : ( n * (-1)));   
}