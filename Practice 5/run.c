#include "run.h"

void run(void){

    FILE* file = fopen("input.txt", "r");

    if(file == NULL){
        printf("Can't open file.\n");
        return;
    }

    int numLines;
    double ax, bx, cx, dx;
    double ay, by, cy, dy; 
    
    while (!feof(file)) {
        fscanf(file, "%d", &numLines);

        fscanf(file, "%lf", &ax);
        fscanf(file, "%lf", &bx);
        fscanf(file, "%lf", &cx);
        fscanf(file, "%lf", &dx);
        
        fscanf(file, "%lf", &ay);
        fscanf(file, "%lf", &by);
        fscanf(file, "%lf", &cy);
        fscanf(file, "%lf", &dy);        
    
        break;
    }

    fclose(file);
    continueProcess(numLines, ax, bx, cx, dx, ay, by, cy, dy);

return;
}


void continueProcess(int numLines, double ax, double bx, double cx, double dx, double ay, double by, double cy, double dy){

    double linesCurve = 1.0 / (double)numLines;
    Point * controlPoints = malloc(sizeof(Point) * 4);
	controlPoints[0].x = 100.0, controlPoints[0].y = 100.0;
	
	controlPoints[1].x = 600.0, controlPoints[1].y = 800.0;
	controlPoints[2].x = 800.0, controlPoints[2].y = 400.0;
	
	controlPoints[3].x = 100.0, controlPoints[3].y = 1000.0;

	/*controlPoints[0].x = 100.0, controlPoints[0].y = 100.0;
	
	controlPoints[1].x = 500.0, controlPoints[1].y = 500.0;
	controlPoints[2].x = 700.0, controlPoints[2].y = 200.0;
	
	controlPoints[3].x = 200.0, controlPoints[3].y = 1000.0;*/

	double x0 = controlPoints[0].x;
	double y0 = controlPoints[0].y;

	double x1 = controlPoints[1].x;
	double y1 = controlPoints[1].y;

	double x2 = controlPoints[2].x;
	double y2 = controlPoints[2].y;

	double x3 = controlPoints[3].x;
	double y3 = controlPoints[3].y;

    Point * points = malloc(sizeof(Point) * (numLines+1) );
	int itPoints = 0;
	
	for (double t = 0.0; t <= 1; t += linesCurve){

		double x_t = x0 * pow((1-t),3) + 3*x1*pow((1-t),2)*t + 3*x2*(1-t)*pow(t,2) + x3*pow(t,3); 
		double y_t = y0 * pow((1-t),3) + 3*y1*pow((1-t),2)*t + 3*y2*(1-t)*pow(t,2) + y3*pow(t,3);
		points[itPoints].x = x_t;
		points[itPoints].y = y_t;
		itPoints++;
	}


    int N, M; N = 1500; M = 1500;
	RGB ** frame = malloc(sizeof(RGB) * N);
	for(int i = 0; i < N; i++){
		frame[i] = malloc(sizeof(RGB) * M);
	}

	RGB color;
	color.red = 255, color.green = 255, color.blue = 255;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			frame[i][j] = color;
		}
	}

    color.red = 255, color.green = 0, color.blue = 0; 
	srand(time(NULL));

	for(int i = 0; i < numLines; i++){
		color.red = rand()%255, color.green = rand()%255, color.blue = rand()%255; 
		DigitalDifferentialAnalyser(points[i], points[i+1], frame, color);
	}

    RGB controlColor;
	controlColor.red = 0, controlColor.green = 0, controlColor.blue = 255;

	frame[(int)x0][(int)y0] = controlColor;
	frame[(int)x1][(int)y1] = controlColor;
	frame[(int)x2][(int)y2] = controlColor;
	frame[(int)x3][(int)y3] = controlColor;

    DigitalDifferentialAnalyser(controlPoints[1], controlPoints[2], frame, controlColor);
    drawFinalCurve("Bezier", frame, N, M);

return;
}