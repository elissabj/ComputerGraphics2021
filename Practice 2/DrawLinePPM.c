#include <stdio.h>
#include <stdlib.h>

#include "DrawLinePPM.h"
#include "RenderAlgorithm.h"

void drawFigure (RGB matrixToDraw[MAXN][MAXN]){                                                                             //To draw in a .ppm File

    int i, j;

    FILE  *fobj = fopen("model.ppm", "wb");                                                                                 //Open the .ppm File and write the new result
    (void) fprintf(fobj, "P3\n%d %d\n255\n", MAXN, MAXN);

    for(i = 0; i  < MAXN; i++){
        for(j = 0; j < MAXN; j++){

            fprintf(fobj, "%d %d %d\n", matrixToDraw[i][j].red, matrixToDraw[i][j].green, matrixToDraw[i][j].blue);
            
        }
    }

return;
}
