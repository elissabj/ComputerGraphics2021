#include "VertexListFormat.h"

void drawFinalFigure(RGB frame[SIZE_N+1][SIZE_M+1]);                                                        //Drawing figure without zBuffer
void drawFinalFigureWithZBuffer( RGB refresh[SIZE_N][SIZE_M]);                                              //Drawing figure with zBuffer
void renderFace (Face faceToRender, RGB frame[SIZE_N+1][SIZE_M+1], RGB color);                              //Check which faces are goint to process
void DrawLineDDA (Point p0, Point p1, RGB frame[SIZE_N+1][SIZE_M+1], RGB color);                            //Fill the figure

ListOfPixels obtainPixelsOfFace (Face face);                                                                //Auxiliar functions to make easy getting information
ListOfPixels obtainPixelsOfFaceWithScanLine (Face face);                                                    //about the pixels that have to be fill
void obtainPixelsOfEdge (Edge edge, ListOfPixels * listPixels);


void scanlineAlgorithm(Face faceToRender, RGB color, RGB frame[SIZE_N+1][SIZE_M+1]);                        //Scanline algorithm
void zbufferAlgorithm(VertexListFormat vlf, int useScanline, RGB frame [SIZE_N+1][SIZE_M+1]);               //zBuffer algorithm