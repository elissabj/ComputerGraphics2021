#include<stdio.h>
#include<stdlib.h>

void colorea_rojo(FILE  *fp);
void colorea_verde(FILE  *fp);
void colorea_blanco(FILE  *fp);

int main(void){

    const int x = 100, y = 60; 

    int i, j;

    FILE  *fp = fopen("bandera.ppm", "wb");

    (void) fprintf(fp, "P6\n%d %d\n255\n", x, y);

    for(i = 0; i < y; i++){
        for(j = 0; j < x; j++){
            if(j >= 0 && j <= 33){
                colorea_verde(fp);
                
            }else if(j > 33 && j < 67){
                colorea_blanco(fp);
            }else{
                colorea_rojo(fp);
            }
        }
    }

    (void)fclose(fp);
    return EXIT_SUCCESS;
}

void colorea_rojo(FILE  *fp){
    static unsigned char rojo[3];
    rojo[0] = 255;
    rojo[1] = 0;
    rojo[2] = 0;

    (void)fwrite(rojo, 1,3, fp);
return;
}

void colorea_verde(FILE  *fp){
    static unsigned char verde[3];
    verde[0] = 34;
    verde[1] = 139;
    verde[2] = 34;

    (void)fwrite(verde, 1,3, fp);
return;
}

void colorea_blanco(FILE  *fp){
    static unsigned char blanco[3];
    blanco[0] = 255;
    blanco[1] = 255;
    blanco[2] = 255;

    (void)fwrite(blanco, 1,3, fp);
return;
}