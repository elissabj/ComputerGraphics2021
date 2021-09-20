#include <stdio.h>
#include <stdlib.h>

#include "Point.h"
#include "DrawLinePPM.h"

RGB matrixToDraw[MAXN][MAXN];                                                   //Declare the data type RGB for the figure, I choose white

int min (int a, int b){                                                         //Function to obtain MIN value for int 
    return (a<b)? a:b;
}

int max (int a, int b){                                                         //Function to obtain MAX value for int
    return (a>b)? a:b;
}

void swapPoints (int x1, int y1, int x2, int y2){                               //Function to make swap for a pair of points
    int temp;
    temp = x1; x1 = x2; x2 = temp;

    temp = y1; y1 = y2; y2 = temp;

return;
}

void NaiveApproach (int x1, int y1, int x2, int y2){
    
   
    if(abs(y2-y1) == abs(x2-x1)){                                               //Case when its equal

        matrixToDraw[x1][y1].red = 255;
        matrixToDraw[x1][y1].green = 255;
        matrixToDraw[x1][y1].blue = 255;
        return;

    }

    if(abs(y2-y1) < abs(x2-x1)){                                                //If the diference of x win 
        
        for(int itX = min(x1, x2); itX <= max(x1,x2); itX++){
            int itY = (y1*(x2-x1) + itX * (y2-y1) - x1*(y2-y1)) / (x2-x1);          //Calculate the Y for each X                                   
            
            matrixToDraw[itX][itY].red = 255;                                       //Save to draw
            matrixToDraw[itX][itY].green = 255;
            matrixToDraw[itX][itY].blue = 255;
        } 
        

    }else{
        
        for(int itY = min(y1, y2); itY <= max(y1,y2); itY++){            
            int itX = (x1*(y2-y1) + itY *(x2-x1) - y1*(x2-x1)) / (y2-y1);           //Calculate X for each Y
            itX = abs(itX);
                                
            matrixToDraw[itX][itY].red = 255;                                       //Save to draw
            matrixToDraw[itX][itY].green = 255;
            matrixToDraw[itX][itY].blue = 255;           
        }

    }

return; 
}


void DDA (int x1, int y1, int x2, int y2){


    if(abs(y2-y1) == abs(x2-x1)){                                               //Case when its equal
        matrixToDraw[x1][y1].red = 255;
        matrixToDraw[x1][y1].green = 255;
        matrixToDraw[x1][y1].blue = 255;
        return;
    }

    if(abs(y2-y1) < abs(x2-x1)){

        if(x1 > x2){
            swapPoints(x1,y1,x2,y2);
        }


        int itX = x1;
        int itY = y1; 
        
        for(; itX <= x2; itX++){
            itY += ((y2-y1)/(x2-x1));                                           //Calculate the Y for each X using the past point
            int Y = (int)itY;                                                   //and the new one was the slope 

            matrixToDraw[itX][Y].red = 255;                                     //Save to draw
            matrixToDraw[itX][Y].green = 255;
            matrixToDraw[itX][Y].blue = 255;
        }

    }else{
        
        if(y1 > y2){
            swapPoints(x1,y1,x2,y2);
        }

        int itX = x1;
        int itY = y1; 
        
        for(; itY <= y2; itY++){
            itX += ((x2-x1)/(y2-y1));                                           //Calculate the X for each Y using the past point
            int X = (int)itX;                                                   //and the new one was the slope

            matrixToDraw[X][itY].red = 255;                                     //Save to draw
            matrixToDraw[X][itY].green = 255;
            matrixToDraw[X][itY].blue = 255;
        }

    }  
    
return;
}    

void Bresenham(int x1, int y1, int x2, int y2){                                

    int slope = 2 * (y2-y1);                                                    //Calculate the possible update of slope to the E
    int curr_slope = slope - (x2 - x1);                                         //Calculate the possible update of slope to the NE

    int itX = x1; 
    int itY = y1;

    for(; itX <= x2; itX++){

        matrixToDraw[itX][itY].red = 255;                                       //Save to draw
        matrixToDraw[itX][itY].green = 255;
        matrixToDraw[itX][itY].blue = 255;

        curr_slope += slope;                                                    //Sum of both possible updates

        if(curr_slope >= 0){                                                    //Cheack that it's greater than 0 
            itY++;                                                              //that means that we move NE (it's Bresenham observation)
            curr_slope -= 2 * (x2 - x1);                                    
        }

    }

return;
}

void goesToMagic(void){                                                         //Function to draw in the .ppm File
    drawFigure(matrixToDraw);
}

