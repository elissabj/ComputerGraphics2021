/*
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Computer Graphics
Ramos Gómez Elisa
Practice 2
3CV14

    Input:      .obj File (that it's a figure in 3D)
    Output:     .ppm File (the same figure in 2D with render Algorithm that we check in class)

    To compile use the Makefile 

*/

#include<stdio.h>
#include "run.h"


int main(void){

    initialize();                       //Initialize all the components 
    run();                              //Run Algorithms
    continueProcess();                  //Convert in a .ppm
    return 0;
}
