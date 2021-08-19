/*
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Computer Graphics 
Ramos Gómez Elisa
Practice 1
3CV14

        Remembering that the formula is
                Y2 - Y1
            m = -------
                X2 - X1 

        Depending on which part is the largest, iteration
        of the points is inc by one and we will calculate
        the value missing (x or y) as the case may be.
 
*/

#include<stdio.h>
#include <stdlib.h>

int main(void){

    int x1,y1, x2, y2;                                                  //Declare variables

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);                           //Read the points 

    int i, j;                                                           //Declare iterators

    printf("\nX\tY\n");                                                 //Print the table

    if(abs(y2-y1) < abs(x2-x1)){                                        //If the diference of x win 

        int cota_infX, cota_supX;                                       //Calculate the limits

        if(x1 > x2){
            cota_infX = x2; cota_supX = x1;
        }else{
            cota_infX = x1; cota_supX = x2;
        }

        for(i = cota_infX; i <= cota_supX; i++){
            j = (y1*(x2-x1) + i * (y2-y1) - x1*(y2-y1)) / (x2-x1);      //Calculate the Y for each X
            printf("%d\t%d\n", i, j);                                   //Print values of points x, y
        } 
        

    }else{

        int cota_infY, cota_supY;
        if(y1 > y2){
    	    cota_infY = y2; cota_supY = y1;
        }else{
            cota_infY = y1; cota_supY = y2;
        }
        
        for(i = cota_infY; i <= cota_supY; i++){            
            j = (x1*(y2-y1) + i *(y2-y1) - y1*(y2-y1)) / (y2-y1);        //Calculate X for each Y
            printf("%d\t%d\n", j, i);                                    //Print values of points x, y
        }

    }

return 0;
}
