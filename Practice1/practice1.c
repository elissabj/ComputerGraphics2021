/*
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Computer Graphics 
Ramos Gómez Elisa
Practice 1
3CV14

        Recordando que la formula para la pendiente es
                Y2 - Y1
            m = -------
                X2 - X1 

        Dependiendo de que parte sea la mayor, el barrido 
        de los puntos es creciente y calcularemos el valor 
        faltante (x o y) segun sea el caso.
 
*/

#include<stdio.h>
#include <stdlib.h>

int main(void){

    int x1,y1, x2, y2;                                          //Declaramos los puntos

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);                   //Leemos los puntos 


    int pendiente = (y2 - y1) / (x2 - x1);                      //Declaracion y calculo de la pendiente
    int i, j;                                                   //Declaro iteradores

    printf("\nX\tY\n");                                         //Imprimimos el encabezado de la tabla

    if(abs(y2-y1) < abs(x2-x1)){                                //Si x gano en valor 

        int cota_infX, cota_supX;                               //Calculo cotas

        if(x1 > x2){
            cota_infX = x2; cota_supX = x1;
        }else{
            cota_infX = x1; cota_supX = x2;
        }

        for(i = cota_infX; i <= cota_supX; i++){
            j = (y1*(x2-x1) + i * (y2-y1) - x1*(y2-y1)) / (x2-x1);      //calculo del Y por cada punto X
            printf("%d\t%d\n", i, j);  
        } 
        

    }else{

        int cota_infY, cota_supY;
        if(y1 > y2){
    	    cota_infY = y2; cota_supY = y1;
        }else{
            cota_infY = y1; cota_supY = y2;
        }
        
        for(i = cota_infY; i <= cota_supY; i++){            
            j = (x1*(y2-y1) + i *(y2-y1) - y1*(y2-y1)) / (y2-y1);        //calculo del X por cada punto Y
            printf("%d\t%d\n", j, i);            
        }

    }

return 0;
}
