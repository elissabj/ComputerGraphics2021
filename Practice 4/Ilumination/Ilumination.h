#include "VertexListFormat.h"

void drawFinalFigure(RGB frame[SIZE_N][SIZE_M]);                                                        //Drawing figure without zBuffer
RGB finalColor(RGB pixel, RGB light, double attenuation);
void DrawLineDDA(Point p0, Point p1, RGB color, RGB frame[SIZE_N][SIZE_M], Light light);
void drawIlumination(Light l1, Light l2, Light l3, Point pixel, RGB pixelColor, RGB frame[SIZE_N][SIZE_M]);