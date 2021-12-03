#include "FaceHiding.h"

int isFaceHiding(Face f, Point focalPoint){

    Point u, v, w;
    Point * points = obtaintTreePointsOfAFace(f);
    u = points[0];
    v = points[1];
    w = points[2];

    Point normalVec = crossProduct( substractVectors(u,v), substractVectors(w,v));
    double escalar = dotProduct(normalVec, focalPoint);

    return escalar > 0 ? 1 : 0;                                                         //If the esc value is greather than 0, face not shows
}

Point * obtaintTreePointsOfAFace(Face f){


    Edge e1 = f.e1;
    Edge e2 = f.e2;
    Edge e3 = f.e3;
    Point * points = malloc(sizeof(Point)*3);


    points[0] = e1.from;                                                        //Taking the points of the edge
    points[1] = e1.to;


    if (areEqualsPoints(e2.from, e1.from) == 1 ){                               //Check if they're equal
        points[2] = e2.to;
    } else { 
        
        if( areEqualsPoints(e2.to, e1.from) == 1 ){ 
            points[2] = e2.from;
        } else { 

            if ( areEqualsPoints(e2.from, e1.to) == 1 ){ 
                points[2] = e2.to;
            } else {
                points[2] = e2.from;
            }

        }

    }

    return points;
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