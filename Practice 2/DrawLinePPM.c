#include <stdio.h>
#include <stdlib.h>

#include "DrawLinePPM.h"
#include "RenderAlgorithm.h"

void drawFigure (RGB matrixToDraw[MAXN][MAXN]){                                                                                  //To draw in a .ppm File

    int i, j;

    FILE  *fobj = fopen("model.ppm", "wb");
    (void) fprintf(fobj, "P3\n%d %d\n255\n", MAXN, MAXN);                                                                         //Open the .ppm File and write the new result

    for(i = MAXN-1; i  >= 0; i--){
        for(j = 0; j < MAXN; j++){

            fprintf(fobj, "%d %d %d\n", matrixToDraw[j][i].red, matrixToDraw[j][i].green, matrixToDraw[j][i].blue);          
        }
    }
    
    return;
}
