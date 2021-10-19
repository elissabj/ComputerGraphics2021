#include "TransformationMatrix.h"
#define PI 3.141592654                                                                              // Defining PI value


void makeTransformation(Point *points, int size){

    float sx = 1.0011;                                                                              // Factors of scaling to make it bigger
    float sy = 1.0011;
    float sz = 1.0011;

    float tx = 10;                                                                                  // Factors of translation in 3 axis
    float ty = 4;
    float tz = 10;

    float angle = (2*PI)/500;                                                                       // The angle for the rotation movement


    float FinalMatrix[4][4] = {                                                                     // Final Transformation Matrix 
        {sx*cos(angle), -sx*sin(angle), 0, tx}, 
        {sy*sin(angle), sy*cos(angle), 0, ty}, 
        {0,0,sz,tz}, 
        {0,0,0,1}
    };

    

    int i, j, k;
    for(i = 0 ; i < size; i++){                                                                     // For each point made the mutiplication 
        for(j = 0; j < 4; j++){                                                                     // with the transformation matrix to made
            float aux = 0.0;                                                                        // all the frames for the video.
            for(k = 0; k < 4; k++){

                if(k == 0){
                    aux += FinalMatrix[j][k] * points[i].x;
                }else if (k == 1){
                    aux += FinalMatrix[j][k] * points[i].y;
                }else if(k == 2){
                    aux += FinalMatrix[j][k] * points[i].z;
                }else{
                    aux += FinalMatrix[j][k] * points[i].w;
                }
                
            }

            if(j == 0){
                points[i].x = aux;
            }else if (j == 1){
                points[i].y = aux;
            }else if(j == 2){
                points[i].z = aux;
            }else{
                points[i].w = aux;
            }

        }
        
        points[i].x /= points[i].w;
        points[i].y /= points[i].w;
        points[i].z /= points[i].w;
    }

return;
}

