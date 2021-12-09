#include "Ilumination.h"

void drawIlumination(Light l1, Light l2, Light l3, Point pixel, RGB pixelColor, RGB frame[SIZE_N][SIZE_M]){
    
    RGB black;
    black.red = 0;
    black.green = 0;
    black.blue = 0;

    frame[(int)pixel.x][(int)pixel.y] = black;
	frame[(int)l1.position.x][(int)l1.position.y] = l1.color;
	frame[(int)l2.position.x][(int)l2.position.y] = l2.color;
	frame[(int)l3.position.x][(int)l3.position.y] = l3.color;

    
    double dist = distance (pixel, l1.position);
    double attenuation1 = attenuation(dist, l1.a, l1.b, l1.c);

    pixel.x = 500;
	pixel.y = 500;

	for(int i = 0; i < 500; i++){
		DrawLineDDA(pixel, l1.position, black, frame, l1);
		pixel.y -= 1;
	}
	
	pixel.x = 0;
	pixel.y = 500;
	
	for(int i = 0; i < 500; i++){
		DrawLineDDA(pixel, l2.position, black, frame, l2);
		pixel.y -= 1;
	}

	pixel.x = 0;
	pixel.y = 500;

	for(int i = 0; i < 500; i++){
		DrawLineDDA(pixel, l3.position, black, frame, l3);
		pixel.x += 1;
	}

    drawFinalFigure(frame);

return;
}

void drawFinalFigure(RGB frame[SIZE_N][SIZE_M]){

    FILE  *fobj = fopen("imageLight.ppm", "w");
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

void DrawLineDDA(Point p0, Point p1, RGB color, RGB frame[SIZE_N][SIZE_M], Light light){

    //X and Y differentials
    double dx = p1.x - p0.x;
    double dy = p1.y - p0.y;

    // printf("dx = %lf\n", dx);
    // printf("dy = %lf\n", dy);

    //unit steps
    int steps;

    //X and Y values of the pixel that will be turned ON
    double x_buffer = p0.x;
    double y_buffer = p0.y;

    //X and Y increments
    double x_increment;
    double y_increment;

    //Define the number of steps based on the greater differential
    if (absD(dx) > absD(dy)) {
        steps = absD(dx); 
    } else {
        steps = absD(dy);
    }

    //Calculate X and Y increment
    x_increment = dx / steps;
    y_increment = dy / steps;
    

    //Loop for incrementing X and Y coordinates 
    for (int i = 0; i < steps; i++) {
        x_buffer += x_increment;
        y_buffer += y_increment;
        
        int x = round(x_buffer);
        int y = round(y_buffer);

        // printf("  (%d, %d), color: (%d, %d, %d)\n", x, y, color.red, color.green, color.blue);
        //frame[x][y] = color;

        Point newPixel;
        newPixel.x = x;
        newPixel.y = y;

        double dist = distance(newPixel, light.position);
		double att = attenuationLight(dist, light);
        
        //Calcular el color del pixel dependiendo del color de la luz
        frame[x][y] = finalColor(frame[x][y], light.color, att);

        //printf("[%d][%d] : (%d, %d, %d)\n", x, y, frame[x][y].red, frame[x][y].green, frame[x][y].blue);
        
    } 

    return;
}

RGB finalColor(RGB pixel, RGB light, double attenuation){

	RGB final;
	RGB attLight;

	attLight.red = attenuation * light.red;
	attLight.green = attenuation * light.green;
	attLight.blue = attenuation * light.blue;


	final.red = pixel.red + attLight.red;
	final.green = pixel.green + attLight.green;
	final.blue = pixel.blue + attLight.blue;

	return final;
}