/*
INSTITUTO POLITECNICO NACIONAL 
Escuela Superior de Computo
Computer Graphics
Ramos Gomez Elisa
Practice 5 Curves
3CV14
*/

#include <stdio.h>
#include <math.h>

/*

t parameter

x (t) = a_x * t^3 + b_x * t^2 + c_x * t + d_x
y (t) = a_y * t^3 + b_y * t^2 + c_y * t + d_x 


t | x(t) | y(t) |
  | 	 |      |
  |      |      |

*/


int main(){

	int numberLines;

	double ax, bx, cx, dx;
	double ay, by, cy, dy;

	printf("Number of lines: ");
	scanf("%d", &numberLines);

	printf("Parameters of x(t)\n");

	printf("ax = ");
	scanf("%lf", &ax);

	printf("bx = ");
	scanf("%lf", &bx);

	printf("cx = ");
	scanf("%lf", &cx);

	printf("dx = ");
	scanf("%lf", &dx);


	printf("Parameters of y(t)\n");

	printf("ay = ");
	scanf("%lf", &ay);

	printf("by = ");
	scanf("%lf", &by);

	printf("cy = ");
	scanf("%lf", &cy);

	printf("dy = ");
	scanf("%lf", &dy);

	double linesInTheCurve;

	linesInTheCurve = 1.0 / (double)numberLines;


	for(double t = 0; t <= 1; t += linesInTheCurve){

		printf("\nFor t = %lf:\n", t);

		double x_t = ax * pow(t,3) + bx * pow(t,2) + cx * pow(t,1) + dx;
		double y_t = ay * pow(t,3) + by * pow(t,2) + cy * pow(t,1) + dy;

		printf("x(%lf) = %lf\n", t, x_t);
		printf("y(%lf) = %lf\n", t, y_t);

	} 

	
	// Bezier

	// Hermite

	return 0;
}