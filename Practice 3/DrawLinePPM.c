#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DrawLinePPM.h"
#include "RenderAlgorithm.h"

void drawFigure (RGB matrixToDraw[MAXN][MAXN], int ctFrame){                                                                      //To draw in a .ppm File

    int i, j;
    char aux[4];
    char numberFrame[20] = "model";
    

    sprintf(aux,"%d", ctFrame);  

    strcat(numberFrame,aux);
    strcat(numberFrame,".ppm");


    FILE  *fobj = fopen(numberFrame, "w");
    (void) fprintf(fobj, "P3\n%d %d\n255\n", MAXN, MAXN);                                                                         //Create the .ppm File and write the new frame

    for(i = MAXN-1; i  >= 0; i--){
        for(j = 0; j < MAXN; j++){

            fprintf(fobj, " %d %d %d   ", matrixToDraw[j][i].red, matrixToDraw[j][i].green, matrixToDraw[j][i].blue);          
        }
        fprintf(fobj, "\n");          
    }

    fprintf(fobj, "\n");
    fclose(fobj);

return;
}
