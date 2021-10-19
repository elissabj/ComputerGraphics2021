/*
INSTITUTO POLITECNICO NACIONAL 
Escuela Superior de Computo
Computer Graphics
Ramos Gomez Elisa
Practice 3
3CV14
    Input:      .obj File (that it's a figure in 3D)
    Output:     video made it by ppm frames
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