#define MAXSIZE 5                                                                           //Static size for faces per line, this can modify 

typedef struct Point{                                                                       //Data Type Point 
    
    float x;
    float y;

}Point;

typedef struct Faces{                                                                       //Data Type Faces

    int connections[MAXSIZE];

}Faces;

float minPoint ( float a, float b);                                                         //Function to calculate the MIN for floats
float maxPoint ( float a, float b);                                                         //Function to calculate the MAX for floats

void coordinatesPositives(Point *points, float miniPointX, float miniPointY, int i);        //Move the points to the fisrt octant
void printFaces(Faces * arr_face, int MAXI, Point *points);                                 //Make the magic with the RederAlgorithm library