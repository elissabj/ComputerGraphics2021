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

typedef struct Face {                                                   //Define faces

    int index;
    Edge e1;
    Edge e2;
    Edge e3;

}Face;

typedef struct VertexListFormat {

    Point * points;                                                     //List of points
    int numPoints;

    Edge * edges;                                                       //List of edges
    int numEdges;

    Face * faces;                                                       //List of faces
    int numFaces;

} VertexListFormat;

