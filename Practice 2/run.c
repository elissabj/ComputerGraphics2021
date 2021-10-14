#include "run.h"
#include "Point.h"


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define endl printf("\n\n");                                                    //Debug option 1
#define debug printf("NOT DIES HERE (:\n");                                     //Debug option 2


Point *arr_point;                                                               //Dinamic array that saves points
Faces *arr_faces;                                                               //Dinamic array to save the faces 


float miniPointX;                                                               //Variables that help to make the  
float miniPointY;                                                               //convertions of all points to the 
int j; int i;                                                                   //first octanct


void initialize(void){                                                          //Initialize the above variables

    i = 0; j = 0;
    miniPointX = 1e7;
    miniPointY = 1e7;

    arr_point = (Point*)malloc(sizeof(Point)*10000000); 
    arr_faces = (Faces*)malloc(sizeof(Faces)*10000000);

return;
}

void run (void){

    FILE * file = fopen("model.obj", "r");                                      //Open .obj File

    if(file == NULL){                                                           //If not, send a message
        printf("Can't open file.\n");
        return;
    }

    
    char type;                                                                  //We have vertexs 'v' and faces 'f' 
    float x,y,z;                                                                //If Vertex as 3D we have (x,y,z) point


    Point point;                                                                //Create my data type Point that only have (x,y) coordinates

    while(fscanf(file, "%c", &type) == 1){                                      //While we have vertexs and faces to read make...


        if(type == 'v'){                                                        //If its vertex
            
            fscanf(file, "%f" "%f" "%f", &x, &y, &z);                           //Read the coordinates
            point.x = x*100; point.y = y*100;                                   //Make this adecuation for have a bigger result in .pmm File

            miniPointX = minPoint(miniPointX, point.x);                         //That helps to move the points to the first octanct
            miniPointY = minPoint(miniPointY, point.y); 

            arr_point[i] = point;                                               //Add to my array of my data type Point
            i++;

            char s[100];                                                        //Buffer clean 
            fgets(s, 100, file);
            
        }else{                                                                  //If its face

            int pos; int k;                                                     //Variables that helps to save the info
            int it; it = 0; 

            Faces connect;                                                      //Create my data type Faces that inside have an array

            while(fscanf(file, "%d", &pos) == 1){                               //Read the connection faces that we have in the .obj File
                connect.connections[it] = pos-1;                                //Save the face - 1 cuz' indexing 0
                it++;  
            }

            for(int k = 0; k < MAXSIZE; k++){                                   //Save all the faces for each line of the .obj File

                arr_faces[j].connections[k] = connect.connections[k];
                
            }

            j++;
        }
    }  

    fclose(file);                                                               //Close the .obj File

return;
}


void continueProcess (void){

    coordinatesPositives(arr_point, miniPointX, miniPointY, i);                  //Move points to the first octanct
    printFaces(arr_faces, j, arr_point);                                         //Call the algorithm of Render Lines

return;
}

