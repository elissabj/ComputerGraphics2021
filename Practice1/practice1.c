#include<stdio.h>

int main(){

    int x1,y1, x2, y2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    printf("%d, %d, %d, %d\n", x1, y1, x2, y2);

    int cota_infX, cota_supX;
  	int cota_infY, cota_supY;
  
  	if(x1 > x2){
        cota_infX = x2;
        cota_supX = x1;
    }else{
        cota_infX = x1;
        cota_supX = x2;
    }
  	
  	if(y1 > y2){
    	cota_infY = y2;
        cota_supY = y1;
    }else{
        cota_infY = y1;
        cota_supY = y2;
    }

    //printf("%d, %d : %d, %d\n", cota_infX, cota_supX, cota_infY, cota_supY);

    printf("X\tY\n");
    int i, j;
    for(i = cota_infX; i <= cota_supX; i++){
        for(j = cota_infY; j <= cota_supY; j++){
            int x = i*(y2-y1); int y = j * (x2+x1);
            int c = -(y2*x1) + (y1*x2);
            printf("%d\t%d\n", i, j);
        }
    } 


return 0;
}