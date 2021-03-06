/*Unit of measure is millimeter*/

#include <stdlib.h>
#include <stdio.h>
#include "drawing.h"

void draw_cube_20mm(){
	FILE *arquivo;
	arquivo = fopen("cube.stl","w");
	begin_draw(arquivo);
    //if puts height = 1, will draw a cube with 0.1 x 0.1 x 0.1
	//draw_rectangle(arquivo,0,0,0,200);
    //drawing a cube 2 cm x 2 cm x 2 cm with rectangle 
    int iteratorY;
    int iteratorX;
    int drawY = 0;
    int drawX = 0;
    for(iteratorY = 0; iteratorY < 2; iteratorY++){
        for(iteratorX = 0; iteratorX < 2; iteratorX++){
            draw_rectangle(arquivo, drawX, drawY, 0, 1.5, 10);
            drawX = drawX + 1.000000*1000;
        }
        drawX = 0;
       drawY = drawY + 1.000000*1000;
    } 
    //draw_rectangle(arquivo, drawX, drawY, 0, 1, 20000);   
	//draw_cube(arquivo,0.5,0.5,0,0.5);
	//draw_cube(arquivo,-0.5,0.5,0,0.5);
	//draw_cube(arquivo,-0.5,-0.5,0,0.5);
	//draw_cube(arquivo,0.5,-0.5,0,0.5);
	//draw_cube(arquivo,2,0,0,0.5);
	//recursive_draw(arquivo,10, 1);
	end_draw(arquivo);
	fclose(arquivo);
}

void draw_signal_sum(){
	int width = 5; //5cmX5cm
	int roof = 3;
    int ground = 0.5;
	int band = width * 20/100;
	int limit_less = (width - band)/2;
	int limit_upper = width - limit_less;
	FILE *arquivo;
	arquivo = fopen("signal_sum.stl","w");
	begin_draw(arquivo);
    int iteratorY;
    int iteratorX;
    int drawY = 0;
    int drawX = 0;
    for(iteratorY = 0; iteratorY < width; iteratorY++){
        for(iteratorX = 0; iteratorX < width; iteratorX++){
        	if (iteratorX >= limit_less && iteratorX < limit_upper || iteratorY >= limit_less && iteratorY < limit_upper){
        		draw_rectangle(arquivo, drawX, drawY, 0, roof, 10);
        	}
        	else{
        		draw_rectangle(arquivo, drawX, drawY, 0, ground, 10);
        	}
            printf("\n\t\titeratorX: %d", iteratorX);
            drawX = drawX + 1.000000*1000;
        }
        drawX = 0;
        printf("\n\titeratorY: %d", iteratorY);
       drawY = drawY + 1.000000*1000;
    } 

	end_draw(arquivo);
	fclose(arquivo);
}


void draw_figure_5x5_cm(int matrix_figure[5][5]){
 	int width = 5; //figure with dimension 5cmx5cm
	int roof = 3;
    int ground = 0.5;
	int band = width * 20/100;
	int limit_less = (width - band)/2;
	int limit_upper = width - limit_less;
	FILE *arquivo;
	arquivo = fopen("figure_5X5.stl","w");
	begin_draw(arquivo);
    int iteratorY;
    int iteratorX;
    int drawY = 0;
    int drawX = 0;
    for(iteratorY = 0; iteratorY < width; iteratorY++){
        for(iteratorX = 0; iteratorX < width; iteratorX++){
        	
            draw_rectangle(arquivo, drawX, drawY, 0, ((matrix_figure[iteratorX][iteratorY])/102 + 0.5), 10);
        
            drawX = drawX + 1.000000*1000;
        }
        drawX = 0;
       drawY = drawY + 1.000000*1000;
    } 

	end_draw(arquivo);
	fclose(arquivo);   

}

int main(){
    int matrix_figure[5][5];
    //Drawing the points of matrix
    /*matrix_figure[0][4] = 255; matrix_figure[1][4] = 0; matrix_figure[2][4] = 0; matrix_figure[3][4] = 0; matrix_figure[4][4] = 255;
    matrix_figure[0][3] = 0; matrix_figure[1][3] = 255; matrix_figure[2][3] = 128; matrix_figure[3][3] = 255; matrix_figure[4][3] = 0;
    matrix_figure[0][2] = 0; matrix_figure[1][2] = 128; matrix_figure[2][2] = 255; matrix_figure[3][2] = 128; matrix_figure[4][2] = 0;
    matrix_figure[0][1] = 0; matrix_figure[1][1] = 255; matrix_figure[2][1] = 128; matrix_figure[3][1] = 255; matrix_figure[4][1] = 0;
    matrix_figure[0][0] = 255; matrix_figure[1][0] = 0; matrix_figure[2][0] = 0; matrix_figure[3][0] = 0; matrix_figure[4][0] = 255;
    */

    //Drawing figure 2
    /*matrix_figure[0][4] = 64; matrix_figure[1][4] = 64; matrix_figure[2][4] = 64; matrix_figure[3][4] = 64; matrix_figure[4][4] = 64;
    matrix_figure[0][3] = 64; matrix_figure[1][3] = 128; matrix_figure[2][3] = 128; matrix_figure[3][3] = 128; matrix_figure[4][3] = 64;
    matrix_figure[0][2] = 64; matrix_figure[1][2] = 128; matrix_figure[2][2] = 255; matrix_figure[3][2] = 128; matrix_figure[4][2] = 64;
    matrix_figure[0][1] = 64; matrix_figure[1][1] = 128; matrix_figure[2][1] = 128; matrix_figure[3][1] = 128; matrix_figure[4][1] = 64;
    matrix_figure[0][0] = 64; matrix_figure[1][0] = 64; matrix_figure[2][0] = 64; matrix_figure[3][0] = 64; matrix_figure[4][0] = 64;
*/

    FILE *figura_leitura;
    figura_leitura = fopen("figure.txt","r");
    //printf("%c\n", fgetc(figura_leitura));
    //int a,b,c,d,e;
    //fscanf(figura_leitura,"%d %d %d %d %d\n", &a, &b, &c, &d, &e);
    //printf("%d %d %d %d %d\n",a,b,c,d,e);
    int i;
    for (i = 4; i >= 0; i--)
    {
        fscanf(figura_leitura,"%d %d %d %d %d\n", &matrix_figure[0][i], &matrix_figure[1][i], &matrix_figure[2][i], &matrix_figure[3][i], &matrix_figure[4][i]);
    }
    

    draw_figure_5x5_cm(matrix_figure);         


	draw_cube_20mm();
	draw_signal_sum();	

    printf("\n\n\tFIM\n\n");
	return 0;
}

/*255 - 3
  x   - y
255y = 3x
y = (3/255)x*/
