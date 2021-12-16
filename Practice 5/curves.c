#include "curves.h"


void DigitalDifferentialAnalyser ( Point p0, Point p1, RGB ** frame, RGB color ) {   

    float dx = p1.x - p0.x;                                                                                          //X and Y differentials
    float dy = p1.y - p0.y;

    int steps;
    float x_buffer = p0.x;                                                                                           //X and Y values of the pixel that will be turned ON
    float y_buffer = p0.y;

    
    float x_increment;                                                                                               //X and Y increments
    float y_increment;


    if (abs(dx) > abs(dy)) {
        steps = abs(dx); 
    } else {
        steps = abs(dy);
    }

    
    x_increment = dx / steps;                                                                                        //Calculate X and Y increment
    y_increment = dy / steps;
    
    
    for (int i = 0; i < steps; i++) {                                                                                //Loop for incrementing X and Y coordinates 
        x_buffer += x_increment;
        y_buffer += y_increment;

		int x = (int)x_buffer;
		int y = (int)y_buffer;

		frame[x][y] = color;
    }

	return;
}

void Bresenham ( Point p0, Point p1, RGB ** frame, RGB color ) {   
	
    if (IsSamePoint(p1, p0)) {
		int x = p0.x;
		int y = p0.y;
		frame[x][y] = color;

    } else {
        
        int dx = p1.x - p0.x;                                                                                        //X and Y differentials
        int dy = p1.y - p0.y;

        
        int twice_dy = 2 * dy;                                                                                       //Auxilary variables
        int twice_dy_dx = twice_dy - 2*dx;
        int decision_variable = twice_dy - dx;


        int buffer_x = p0.x;                                                                                         //X and Y values of the pixel that will be turned ON
        int buffer_y = p0.y;

        while (buffer_x != p1.x) {
            
			frame[buffer_x++][buffer_y] = color;
            
			if (decision_variable < 0) {
                decision_variable += twice_dy;
            } else {
                buffer_y++;
                decision_variable += twice_dy_dx;
            }
        }
    }
	return;
}



void drawFinalCurve(char * nameOfPPM, RGB ** frame, int SIZE_N, int SIZE_M){
	
	char finalName [100];                                                                                            //Name File
    memset(finalName, '\0', sizeof(finalName));                                                                      //Clean Buff

    strcat(finalName, nameOfPPM);                                                                                    //Create .ppm file
    strcat(finalName, ".ppm"); 

	FILE  *fobj = fopen( finalName, "w");
    (void) fprintf(fobj, "P3\n%d %d\n255\n", SIZE_N, SIZE_M);  


    for(int i = 0; i < SIZE_N; i++){
        for(int j = 0; j < SIZE_M; j++){
            fprintf(fobj, "%d %d %d ", frame[i][j].red, frame[i][j].green, frame[i][j].blue);
        }
        fprintf(fobj, "\n");
    }

	fprintf(fobj, "\n");
    fclose(fobj);

return;
}