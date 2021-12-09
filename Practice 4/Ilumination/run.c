#include "run.h"


void run(void){

    RGB frame[SIZE_N][SIZE_M];
    
    for(int i = 0; i < SIZE_N; i++){
        for(int j = 0; j < SIZE_M; j++){
            frame[i][j].red = 0;
            frame[i][j].green = 0;
            frame[i][j].blue = 0;
        }
    }


    FILE* file = fopen("input.txt", "r");

    if(file == NULL){
        printf("Can't open file.\n");
        return;
    }

    double a, b, c;
    while (!feof(file)) {
        fscanf(file, "%lf %lf %lf", &a, &b, &c);
        break;
    }

    fclose(file);

    continueProcess(a, b, c, frame);

return;
}


void continueProcess(double a, double b, double c, RGB frame[SIZE_N][SIZE_M]){

    Point p;
    RGB pixelColor;
    p.x = 0; p.y = 0; p.z = 0;
    pixelColor.red = 0; pixelColor.green = 0; pixelColor.blue = 0;


    Light l1 = initializeLight(a, b, c, 1);
    Light l2 = initializeLight(a, b, c, 2);
    Light l3 = initializeLight(a, b, c, 3);
    
    drawIlumination(l1, l2, l3, p, pixelColor, frame);

return;
}

Light initializeLight (double a, double b, double c, int type){

    Light l;
    if(type == 1){
        l.position.x = 166;
        l.position.y = 332;
        l.position.z = 0;

        l.color.red = 255;
        l.color.green = 0;
        l.color.blue = 0;


    }else if(type == 2){

        l.position.x = 332;
        l.position.y = 332;
        l.position.z = 0;

        l.color.red = 0;
        l.color.green = 255;
        l.color.blue = 0;

    }else{

        l.position.x = 250;
        l.position.y = 166;
        l.position.z = 0;

        l.color.red = 0;
        l.color.green = 0;
        l.color.blue = 255;

    }

    l.a = a;
	l.b = b;
	l.c = c;

return l;
}