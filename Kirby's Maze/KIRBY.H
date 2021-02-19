#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <mouse.h>
#include <time.h>
#include <math.h>

void kirby(int x, int y)
{
    setfillstyle(SOLID_FILL,RED);
    ellipse(x + 16, y + 24, 0, 360, 10, 5); /*pata derecha */
    floodfill(x + 16, y + 24, WHITE);

    ellipse(x - 4, y + 24, 0, 360, 10, 5);/*pata izquierda*/
    floodfill(x - 4, y + 24, WHITE);

    setfillstyle(SOLID_FILL,LIGHTRED);

	  circle(x + 5, y, 20); /*cuerpo*/
    floodfill(x, y, WHITE);

    /*line(x - 10, y - 5, x - 10, y - 10);
    line(x - 5, y - 10, x - 5, y - 7);*/

    settextstyle(0, 0, 1);
    outtextxy(x - 5, y - 1, "^ ^");
    outtextxy(x + 3, y, "u");

    setfillstyle(SOLID_FILL,RED);
    setcolor(RED);
    circle(x - 6, y + 7, 3);
    /*floodfill(x - 6, y + 7, RED);*/

    setfillstyle(SOLID_FILL,RED);
    setcolor(RED);
    circle(x + 18, y + 7, 3);
    /*floodfill(x + 18, y + 7, RED);*/


}

void circulo(int x, int y) /*imprime un circulo rosa en la posicion de los parametros*/
{
  setfillstyle(SOLID_FILL,LIGHTRED);
  circle(x, y, 20);
  floodfill(x, y, WHITE);
  /*setfillstyle(SOLID_FILL, RED);
  ellipse(x + 5,y + 20, 0, 360, 10, 5);
  floodfill(x + 5, y + 20, WHITE);
  ellipse(x - 5,y + 20, 0, 360, 10, 5);
  floodfill(x - 5, y + 20, WHITE);*/
}

void circuloB(int x, int y) /*imprime un circulo rosa en la posicion de los parametros*/
{
  setfillstyle(SOLID_FILL,BLACK);
  circle(x, y, 20);
  floodfill(x, y, BLACK);
  /*ellipse(x + 5,y + 20, 0, 360, 10, 5);
  floodfill(x + 5, y + 20, BLACK);
  ellipse(x - 5,y + 20, 0, 360, 10, 5);
  floodfill(x - 5, y + 20, BLACK);*/
}

void meta(int x, int y)/*imprime cuadrado amarillo, parametros(posicion_inicial_x, posicion_inical_y)*/
{
  setfillstyle(SOLID_FILL, YELLOW);
  rectangle(x, y, x + 50, y + 50);
  floodfill(x + 10, y + 10, WHITE);
}

void laberinto(void)/*imprime las lineas del laberinto*/
{
  /*Lineas verticales*/
  line(75 ,0, 75, 75);
  line(150, 100, 150, 225);
  line(225, 75, 225, 125);
  line(450, 0, 450, 125);
  line(375, 125, 375, 200);
  line(570, 0, 570, 200);
  line(510, 70, 510, 150);
  line(75, 410, 140, 410);
  line(140, 290, 140, 410);
  line(75, 220, 75, 290);
  /*lineas horizontales*/
  line(0  ,150, 150, 150);
  line(225, 125, 375, 125);
  line(325, 55, 450, 55);
  line(150, 225, 300, 225);
  line(375, 200, 450, 200);
  line(510, 150, 570, 150);
  line(0, 350, 75, 350);
  line(75, 410, 75, 480);
  line(75, 290, 200, 290);
  line(210, 370, 210, 480);

  line(210, 425, 290, 425);
  line(380, 290, 380, 480);
  line(285, 340, 380, 340);
  line(440, 290, 440, 415);
  line(440, 415, 640, 415);
  line(510, 290, 510, 335);
  line(510, 335, 640, 335);
  line(580, 265, 640, 265);

}

void levelUp(void)/*pantalla de nivel siguiente*/
{
  cleardevice();
  setbkcolor(GREEN);/*fondo de pantalla*/
  settextstyle(DEFAULT_FONT, 0, 7);/*estilo de fuente, orientacion, tamanio :p*/
  outtextxy(100, 200, "LEVEL UP");/*posicion x, posicion y, texto*/
  sleep(3);
}

int level1(void)/*nivel 1*/
{
  int circulo_x = 0, circulo_y = 0, movientos = 0;
  char tecla;
  clrscr();
  cleardevice();
  setbkcolor(BLACK);
  setcolor(15);
  fflush(stdin);
  circulo_x = 25; /*posicion x para la funcion circulo*/
  circulo_y = 25; /*posicion y para la funcion circulo*/
  inicio:
  cleardevice();
  meta(580, 350);
  laberinto();
  do
  {
    fflush(stdin);
    /*cleardevice();*/
    circulo(circulo_x, circulo_y);

    tecla = getch();
    if (tecla == 87 || tecla == 119)/*w*/
    {
      if (circulo_y > 25)
      {
        if (circulo_x > 50 && circulo_x < 100 && (circulo_y - 25) <= 75 ||
            circulo_x < 150 && (circulo_y - 25) == 150||
            circulo_x > 200 && circulo_x < 375 && (circulo_y - 25) == 125 ||
            circulo_x > 425 && circulo_x < 475 && (circulo_y - 25) == 125 ||
            circulo_x > 300 && circulo_x < 450 && (circulo_y - 25) == 55 ||
            circulo_x > 115 && circulo_x < 325 && (circulo_y - 25) == 225 ||
            circulo_x > 350 && circulo_x < 475 && (circulo_y - 25) == 200 ||
            circulo_x > 550 && circulo_x < 590 && (circulo_y - 25) == 200 ||
            circulo_x > 500 && circulo_x < 570 && (circulo_y - 25) == 150 ||
            circulo_x > 0 && circulo_x < 75 && (circulo_y - 25) == 350 ||
            circulo_x > 55 && circulo_x < 165 && (circulo_y - 25) == 410 ||
            circulo_x > 55 && circulo_x < 225 && (circulo_y - 25) == 290||
            circulo_x > 190 && circulo_x < 310 && (circulo_y - 25) == 425||
            circulo_x > 255 && circulo_x < 410 && (circulo_y - 25) == 340||
            circulo_x > 420 && circulo_x < 640 && (circulo_y - 25) == 415||
            circulo_x > 480 && circulo_x < 640 && (circulo_y - 25) == 335 ||
            circulo_x > 550 && circulo_x < 640 && (circulo_y - 25) == 265)
        {

        }
        else
        {
          circulo_y-=5;
          movientos++;
          circuloB(circulo_x, circulo_y + 5);
        }
      }
    }
    if (tecla == 83 || tecla == 115)/*s*/
    {
      if (circulo_y < 454)
      {
        if (circulo_x < 150 && (circulo_y + 25) == 150||
            circulo_x > 125 && circulo_x < 175 && (circulo_y + 25) <= 100 ||
            circulo_x > 200 && circulo_x < 250 && (circulo_y + 25) <= 75 ||
            circulo_x > 225 && circulo_x < 375 && (circulo_y + 25) == 125 ||
            circulo_x > 300 && circulo_x < 450 && (circulo_y + 25) == 55 ||
            circulo_x > 115 && circulo_x < 325 && (circulo_y + 25) == 225 ||
            circulo_x > 350 && circulo_x < 475 && (circulo_y + 25) == 200 ||
            circulo_x > 490 && circulo_x < 530 && (circulo_y + 25) == 70 ||
            circulo_x > 500 && circulo_x < 570 && (circulo_y + 25) == 150 ||
            circulo_x > 0 && circulo_x < 75 && (circulo_y + 25) == 350 ||
            circulo_x > 55 && circulo_x < 165 && (circulo_y + 25) == 410 ||
            circulo_x > 45 && circulo_x < 225 && (circulo_y + 25) == 290 ||
            circulo_x > 55 && circulo_x < 100 && (circulo_y + 25) == 220 ||
            circulo_x > 190 && circulo_x < 235 && (circulo_y + 25) == 370||
            circulo_x > 190 && circulo_x < 310 && (circulo_y + 25) == 425 ||
            circulo_x > 350 && circulo_x < 410 && (circulo_y + 25) == 290 ||
            circulo_x > 255 && circulo_x < 410 && (circulo_y + 25) == 340 ||
            circulo_x > 420 && circulo_x < 460 && (circulo_y + 25) == 290 ||
            circulo_x > 420 && circulo_x < 640 && (circulo_y + 25) == 415 ||
            circulo_x > 480 && circulo_x < 539 && (circulo_y + 25) == 290 ||
            circulo_x > 480 && circulo_x < 640 && (circulo_y + 25) == 335 ||
            circulo_x > 550 && circulo_x < 640 && (circulo_y + 25) == 265)
        {
          /* code */
        }
        else
        {
          circulo_y+=5;
          movientos++;
          circuloB(circulo_x, circulo_y - 5);
        }
      }
    }
    if (tecla == 68 || tecla == 100)/*d*/
    {
      if (circulo_x < 614)
      {
        if ((circulo_x + 25) == 75 && circulo_y <= 100 ||
            (circulo_x + 25) == 150 && circulo_y >= 80 && circulo_y <= 225||
            (circulo_x + 25) == 225 && circulo_y >= 75 && circulo_y <= 150||
            (circulo_x + 25) == 450 && circulo_y <= 150 ||
            (circulo_x + 25) == 300 && circulo_y >= 30 && circulo_y <= 80 ||
            (circulo_x + 25) == 375 && circulo_y >= 100 && circulo_y <= 225||
            (circulo_x + 25) == 570 && circulo_y >= 0 && circulo_y <= 220 ||
            (circulo_x + 25) == 510 && circulo_y >= 70 && circulo_y <= 150 ||
            (circulo_x + 25) == 75 && circulo_y >= 390 && circulo_y <= 480 ||
            (circulo_x + 25) == 75 && circulo_y >= 390 && circulo_y <= 430 ||
            (circulo_x + 25) == 140 && circulo_y >= 290 && circulo_y <= 420 ||
            (circulo_x + 25) == 75 && circulo_y >= 200 && circulo_y <= 310||
            (circulo_x + 25) == 210 && circulo_y >= 350 && circulo_y <= 480 ||
            (circulo_x + 25) == 380 && circulo_y >= 270 && circulo_y <= 480 ||
            (circulo_x + 25) == 285 && circulo_y >= 310 && circulo_y <= 370 ||
            (circulo_x + 25) == 440 && circulo_y >= 270 && circulo_y <= 430 ||
            (circulo_x + 25) == 510 && circulo_y >= 270 && circulo_y <= 335 ||
            (circulo_x + 25) == 580 && circulo_y >= 240 && circulo_y <= 290)
        {
          /* code */
        }
        else
        {
          circulo_x+=5;
          movientos++;
          circuloB(circulo_x - 5, circulo_y);
        }

      }
    }
    if (tecla == 65 || tecla == 97)/*a*/
    {
      if (circulo_x > 25)
      {
        if ((circulo_x - 25) == 75 && circulo_y <= 100 ||
            (circulo_x - 25) == 150 && circulo_y >= 80 && circulo_y <= 225 ||
            (circulo_x - 25) == 225 && circulo_y >= 75 && circulo_y <= 125 ||
            (circulo_x - 25) == 450 && circulo_y <= 150 ||
            (circulo_x - 25) == 375 && circulo_y >= 100 && circulo_y <= 225 ||
            (circulo_x - 25) == 450 && circulo_y >= 175 && circulo_y <= 225 ||
            (circulo_x - 25) == 570 && circulo_y >= 0 && circulo_y <= 220 ||
            (circulo_x - 25) == 510 && circulo_y >= 70 && circulo_y <= 150 ||
            (circulo_x - 25) == 75 && circulo_y >= 325 && circulo_y <= 375 ||
            (circulo_x - 25) == 75 && circulo_y >= 390 && circulo_y <= 480 ||
            (circulo_x - 25) == 140 && circulo_y >= 290 && circulo_y <= 420 ||
            (circulo_x - 25) == 200 && circulo_y >= 270 && circulo_y <= 310 ||
            (circulo_x - 25) == 75 && circulo_y >= 200 && circulo_y <= 310 ||
            (circulo_x - 25) == 210 && circulo_y >= 350 && circulo_y <= 480 ||
            (circulo_x - 25) == 290 && circulo_y >= 400 && circulo_y <= 450||
            (circulo_x - 25) == 380 && circulo_y >= 270 && circulo_y <= 480 ||
            (circulo_x - 25) == 440 && circulo_y >= 270 && circulo_y <= 430 ||
            (circulo_x - 25) == 510 && circulo_y >= 270 && circulo_y <= 335||
            (circulo_x - 25) == 300 && circulo_y >= 200 && circulo_y <= 250)
        {
          /* code */
        }
        else
        {
          circulo_x-=5;
          movientos++;
          circuloB(circulo_x + 5, circulo_y);
        }
      }
    }
    if (circulo_x>=580&&circulo_x<=630&&circulo_y>=350&&circulo_y<=400)
    {
      /*sleep(3);*/
      return movientos;
    }
    if (tecla == 82 || tecla == 114)
    {
      gotoxy(0,0);printf("x: %d", circulo_x);
      printf("\ny: %d", circulo_y);
      getch();
      goto inicio;
    }
    if (tecla == 27)
    {
      if ((pausa())== 0)
      {
        goto inicio;
      }
      else
      {
        cleardevice();
        return 0;
      }
    }
  } while(tecla != 87 || tecla != 119 || tecla != 83 || tecla != 115 ||
     tecla != 68 || tecla != 100 || tecla != 65 || tecla != 97 );
}

int level2(int movientos)/*nivel 2*/
{
  int circulo_x = 0, circulo_y = 0;
  char tecla;
  circulo_x = 425; /*posicion x para la funcion circulo*/
  circulo_y = 25; /*posicion y para la funcion circulo*/
  inicio:
  cleardevice();
  setbkcolor(BLACK);
  meta(10, 425);
  laberinto();
  do
  {
    fflush(stdin);
    /*cleardevice();*/
    circulo(circulo_x, circulo_y);

    tecla = getch();
    if (tecla == 87 || tecla == 119)/*w*/
    {
      if (circulo_y > 25)
      {
        if (circulo_x > 50 && circulo_x < 100 && (circulo_y - 25) <= 75 ||
            circulo_x < 150 && (circulo_y - 25) == 150||
            circulo_x > 200 && circulo_x < 375 && (circulo_y - 25) == 125 ||
            circulo_x > 425 && circulo_x < 475 && (circulo_y - 25) == 125 ||
            circulo_x > 300 && circulo_x < 450 && (circulo_y - 25) == 55 ||
            circulo_x > 115 && circulo_x < 325 && (circulo_y - 25) == 225 ||
            circulo_x > 350 && circulo_x < 475 && (circulo_y - 25) == 200 ||
            circulo_x > 550 && circulo_x < 590 && (circulo_y - 25) == 200 ||
            circulo_x > 500 && circulo_x < 570 && (circulo_y - 25) == 150 ||
            circulo_x > 0 && circulo_x < 75 && (circulo_y - 25) == 350 ||
            circulo_x > 55 && circulo_x < 165 && (circulo_y - 25) == 410 ||
            circulo_x > 55 && circulo_x < 225 && (circulo_y - 25) == 290||
            circulo_x > 190 && circulo_x < 310 && (circulo_y - 25) == 425||
            circulo_x > 255 && circulo_x < 410 && (circulo_y - 25) == 340||
            circulo_x > 420 && circulo_x < 640 && (circulo_y - 25) == 415||
            circulo_x > 480 && circulo_x < 640 && (circulo_y - 25) == 335 ||
            circulo_x > 550 && circulo_x < 640 && (circulo_y - 25) == 265)
        {

        }
        else
        {
          circulo_y-=5;
          movientos++;
          circuloB(circulo_x, circulo_y + 5);
        }
      }
    }
    if (tecla == 83 || tecla == 115)/*s*/
    {
      if (circulo_y < 454)
      {
        if (circulo_x < 150 && (circulo_y + 25) == 150||
            circulo_x > 125 && circulo_x < 175 && (circulo_y + 25) <= 100 ||
            circulo_x > 200 && circulo_x < 250 && (circulo_y + 25) <= 75 ||
            circulo_x > 225 && circulo_x < 375 && (circulo_y + 25) == 125 ||
            circulo_x > 300 && circulo_x < 450 && (circulo_y + 25) == 55 ||
            circulo_x > 115 && circulo_x < 325 && (circulo_y + 25) == 225 ||
            circulo_x > 350 && circulo_x < 475 && (circulo_y + 25) == 200 ||
            circulo_x > 490 && circulo_x < 530 && (circulo_y + 25) == 70 ||
            circulo_x > 500 && circulo_x < 570 && (circulo_y + 25) == 150 ||
            circulo_x > 0 && circulo_x < 75 && (circulo_y + 25) == 350 ||
            circulo_x > 55 && circulo_x < 165 && (circulo_y + 25) == 410 ||
            circulo_x > 45 && circulo_x < 225 && (circulo_y + 25) == 290 ||
            circulo_x > 55 && circulo_x < 100 && (circulo_y + 25) == 220 ||
            circulo_x > 190 && circulo_x < 235 && (circulo_y + 25) == 370||
            circulo_x > 190 && circulo_x < 310 && (circulo_y + 25) == 425 ||
            circulo_x > 350 && circulo_x < 410 && (circulo_y + 25) == 290 ||
            circulo_x > 255 && circulo_x < 410 && (circulo_y + 25) == 340 ||
            circulo_x > 420 && circulo_x < 460 && (circulo_y + 25) == 290 ||
            circulo_x > 420 && circulo_x < 640 && (circulo_y + 25) == 415 ||
            circulo_x > 480 && circulo_x < 539 && (circulo_y + 25) == 290 ||
            circulo_x > 480 && circulo_x < 640 && (circulo_y + 25) == 335 ||
            circulo_x > 550 && circulo_x < 640 && (circulo_y + 25) == 265)
        {
          /* code */
        }
        else
        {
          circulo_y+=5;
          movientos++;
          circuloB(circulo_x, circulo_y - 5);
        }
      }
    }
    if (tecla == 68 || tecla == 100)/*d*/
    {
      if (circulo_x < 614)
      {
        if ((circulo_x + 25) == 75 && circulo_y <= 100 ||
            (circulo_x + 25) == 150 && circulo_y >= 80 && circulo_y <= 225||
            (circulo_x + 25) == 225 && circulo_y >= 75 && circulo_y <= 150||
            (circulo_x + 25) == 450 && circulo_y <= 150 ||
            (circulo_x + 25) == 300 && circulo_y >= 30 && circulo_y <= 80 ||
            (circulo_x + 25) == 375 && circulo_y >= 100 && circulo_y <= 225||
            (circulo_x + 25) == 570 && circulo_y >= 0 && circulo_y <= 220 ||
            (circulo_x + 25) == 510 && circulo_y >= 70 && circulo_y <= 150 ||
            (circulo_x + 25) == 75 && circulo_y >= 390 && circulo_y <= 480 ||
            (circulo_x + 25) == 75 && circulo_y >= 390 && circulo_y <= 430 ||
            (circulo_x + 25) == 140 && circulo_y >= 290 && circulo_y <= 420 ||
            (circulo_x + 25) == 75 && circulo_y >= 200 && circulo_y <= 310||
            (circulo_x + 25) == 210 && circulo_y >= 350 && circulo_y <= 480 ||
            (circulo_x + 25) == 380 && circulo_y >= 270 && circulo_y <= 480 ||
            (circulo_x + 25) == 285 && circulo_y >= 310 && circulo_y <= 370 ||
            (circulo_x + 25) == 440 && circulo_y >= 270 && circulo_y <= 430 ||
            (circulo_x + 25) == 510 && circulo_y >= 270 && circulo_y <= 335 ||
            (circulo_x + 25) == 580 && circulo_y >= 240 && circulo_y <= 290)
        {
          /* code */
        }
        else
        {
          circulo_x+=5;
          movientos++;
          circuloB(circulo_x - 5, circulo_y);
        }

      }
    }
    if (tecla == 65 || tecla == 97)/*a*/
    {
      if (circulo_x > 25)
      {
        if ((circulo_x - 25) == 75 && circulo_y <= 100 ||
            (circulo_x - 25) == 150 && circulo_y >= 80 && circulo_y <= 225 ||
            (circulo_x - 25) == 225 && circulo_y >= 75 && circulo_y <= 125 ||
            (circulo_x - 25) == 450 && circulo_y <= 150 ||
            (circulo_x - 25) == 375 && circulo_y >= 100 && circulo_y <= 225 ||
            (circulo_x - 25) == 450 && circulo_y >= 175 && circulo_y <= 225 ||
            (circulo_x - 25) == 570 && circulo_y >= 0 && circulo_y <= 220 ||
            (circulo_x - 25) == 510 && circulo_y >= 70 && circulo_y <= 150 ||
            (circulo_x - 25) == 75 && circulo_y >= 325 && circulo_y <= 375 ||
            (circulo_x - 25) == 75 && circulo_y >= 390 && circulo_y <= 480 ||
            (circulo_x - 25) == 140 && circulo_y >= 290 && circulo_y <= 420 ||
            (circulo_x - 25) == 200 && circulo_y >= 270 && circulo_y <= 310 ||
            (circulo_x - 25) == 75 && circulo_y >= 200 && circulo_y <= 310 ||
            (circulo_x - 25) == 210 && circulo_y >= 350 && circulo_y <= 480 ||
            (circulo_x - 25) == 290 && circulo_y >= 400 && circulo_y <= 450||
            (circulo_x - 25) == 380 && circulo_y >= 270 && circulo_y <= 480 ||
            (circulo_x - 25) == 440 && circulo_y >= 270 && circulo_y <= 430 ||
            (circulo_x - 25) == 510 && circulo_y >= 270 && circulo_y <= 335||
            (circulo_x - 25) == 300 && circulo_y >= 200 && circulo_y <= 250)
        {
          /* code */
        }
        else
        {
          circulo_x-=5;
          movientos++;
          circuloB(circulo_x + 5, circulo_y);
        }
      }
    }
    if (circulo_x>=10&&circulo_x<=60&&circulo_y>=425&&circulo_y<=475)
    {
      /*sleep(3);*/
      return movientos;
    }
    if (tecla == 82 || tecla == 114)
    {
      gotoxy(0,0);printf("x: %d", circulo_x);
      printf("\ny: %d", circulo_y);
      getch();
      goto inicio;
    }
    if (tecla == 27)
    {
      if ((pausa())== 0)
      {
        goto inicio;
      }
      else
      {
        cleardevice();
        return 0;
      }
    }
  } while(tecla != 87 || tecla != 119 || tecla != 83 || tecla != 115 ||
     tecla != 68 || tecla != 100 || tecla != 65 || tecla != 97);
}

int level3(int movientos)/*nivel 3*/
{
  int circulo_x = 0, circulo_y = 0;
  char tecla;
  circulo_x = 35; /*posicion x para la funcion circulo*/
  circulo_y = 440; /*posicion y para la funcion circulo*/
  inicio:
  cleardevice();
  setbkcolor(BLACK);
  meta(515, 90);
  laberinto();
  do
  {
    fflush(stdin);
    /*cleardevice();*/
    circulo(circulo_x, circulo_y);

    tecla = getch();
    if (tecla == 87 || tecla == 119)/*w*/
    {
      if (circulo_y > 25)
      {
        if (circulo_x > 50 && circulo_x < 100 && (circulo_y - 25) <= 75 ||
            circulo_x < 150 && (circulo_y - 25) == 150||
            circulo_x > 200 && circulo_x < 375 && (circulo_y - 25) == 125 ||
            circulo_x > 425 && circulo_x < 475 && (circulo_y - 25) == 125 ||
            circulo_x > 300 && circulo_x < 450 && (circulo_y - 25) == 55 ||
            circulo_x > 115 && circulo_x < 325 && (circulo_y - 25) == 225 ||
            circulo_x > 350 && circulo_x < 475 && (circulo_y - 25) == 200 ||
            circulo_x > 550 && circulo_x < 590 && (circulo_y - 25) == 200 ||
            circulo_x > 500 && circulo_x < 570 && (circulo_y - 25) == 150 ||
            circulo_x > 0 && circulo_x < 75 && (circulo_y - 25) == 350 ||
            circulo_x > 55 && circulo_x < 165 && (circulo_y - 25) == 410 ||
            circulo_x > 55 && circulo_x < 225 && (circulo_y - 25) == 290||
            circulo_x > 190 && circulo_x < 310 && (circulo_y - 25) == 425||
            circulo_x > 255 && circulo_x < 410 && (circulo_y - 25) == 340||
            circulo_x > 420 && circulo_x < 640 && (circulo_y - 25) == 415||
            circulo_x > 480 && circulo_x < 640 && (circulo_y - 25) == 335 ||
            circulo_x > 550 && circulo_x < 640 && (circulo_y - 25) == 265)
        {

        }
        else
        {
          circulo_y-=5;
          movientos++;
          circuloB(circulo_x, circulo_y + 5);
        }
      }
    }
    if (tecla == 83 || tecla == 115)/*s*/
    {
      if (circulo_y < 454)
      {
        if (circulo_x < 150 && (circulo_y + 25) == 150||
            circulo_x > 125 && circulo_x < 175 && (circulo_y + 25) <= 100 ||
            circulo_x > 200 && circulo_x < 250 && (circulo_y + 25) <= 75 ||
            circulo_x > 225 && circulo_x < 375 && (circulo_y + 25) == 125 ||
            circulo_x > 300 && circulo_x < 450 && (circulo_y + 25) == 55 ||
            circulo_x > 115 && circulo_x < 325 && (circulo_y + 25) == 225 ||
            circulo_x > 350 && circulo_x < 475 && (circulo_y + 25) == 200 ||
            circulo_x > 490 && circulo_x < 530 && (circulo_y + 25) == 70 ||
            circulo_x > 500 && circulo_x < 570 && (circulo_y + 25) == 150 ||
            circulo_x > 0 && circulo_x < 75 && (circulo_y + 25) == 350 ||
            circulo_x > 55 && circulo_x < 165 && (circulo_y + 25) == 410 ||
            circulo_x > 45 && circulo_x < 225 && (circulo_y + 25) == 290 ||
            circulo_x > 55 && circulo_x < 100 && (circulo_y + 25) == 220 ||
            circulo_x > 190 && circulo_x < 235 && (circulo_y + 25) == 370||
            circulo_x > 190 && circulo_x < 310 && (circulo_y + 25) == 425 ||
            circulo_x > 350 && circulo_x < 410 && (circulo_y + 25) == 290 ||
            circulo_x > 255 && circulo_x < 410 && (circulo_y + 25) == 340 ||
            circulo_x > 420 && circulo_x < 460 && (circulo_y + 25) == 290 ||
            circulo_x > 420 && circulo_x < 640 && (circulo_y + 25) == 415 ||
            circulo_x > 480 && circulo_x < 539 && (circulo_y + 25) == 290 ||
            circulo_x > 480 && circulo_x < 640 && (circulo_y + 25) == 335 ||
            circulo_x > 550 && circulo_x < 640 && (circulo_y + 25) == 265)
        {
          /* code */
        }
        else
        {
          circulo_y+=5;
          movientos++;
          circuloB(circulo_x, circulo_y - 5);
        }
      }
    }
    if (tecla == 68 || tecla == 100)/*d*/
    {
      if (circulo_x < 614)
      {
        if ((circulo_x + 25) == 75 && circulo_y <= 100 ||
            (circulo_x + 25) == 150 && circulo_y >= 80 && circulo_y <= 225||
            (circulo_x + 25) == 225 && circulo_y >= 75 && circulo_y <= 150||
            (circulo_x + 25) == 450 && circulo_y <= 150 ||
            (circulo_x + 25) == 300 && circulo_y >= 30 && circulo_y <= 80 ||
            (circulo_x + 25) == 375 && circulo_y >= 100 && circulo_y <= 225||
            (circulo_x + 25) == 570 && circulo_y >= 0 && circulo_y <= 220 ||
            (circulo_x + 25) == 510 && circulo_y >= 70 && circulo_y <= 150 ||
            (circulo_x + 25) == 75 && circulo_y >= 390 && circulo_y <= 480 ||
            (circulo_x + 25) == 75 && circulo_y >= 390 && circulo_y <= 430 ||
            (circulo_x + 25) == 140 && circulo_y >= 290 && circulo_y <= 420 ||
            (circulo_x + 25) == 75 && circulo_y >= 200 && circulo_y <= 310||
            (circulo_x + 25) == 210 && circulo_y >= 350 && circulo_y <= 480 ||
            (circulo_x + 25) == 380 && circulo_y >= 270 && circulo_y <= 480 ||
            (circulo_x + 25) == 285 && circulo_y >= 310 && circulo_y <= 370 ||
            (circulo_x + 25) == 440 && circulo_y >= 270 && circulo_y <= 430 ||
            (circulo_x + 25) == 510 && circulo_y >= 270 && circulo_y <= 335 ||
            (circulo_x + 25) == 580 && circulo_y >= 240 && circulo_y <= 290)
        {
          /* code */
        }
        else
        {
          circulo_x+=5;
          movientos++;
          circuloB(circulo_x - 5, circulo_y);
        }
      }
    }
    if (tecla == 65 || tecla == 97)/*a*/
    {
      if (circulo_x > 25)
      {
        if ((circulo_x - 25) == 75 && circulo_y <= 100 ||
            (circulo_x - 25) == 150 && circulo_y >= 80 && circulo_y <= 225 ||
            (circulo_x - 25) == 225 && circulo_y >= 75 && circulo_y <= 125 ||
            (circulo_x - 25) == 450 && circulo_y <= 150 ||
            (circulo_x - 25) == 375 && circulo_y >= 100 && circulo_y <= 225 ||
            (circulo_x - 25) == 450 && circulo_y >= 175 && circulo_y <= 225 ||
            (circulo_x - 25) == 570 && circulo_y >= 0 && circulo_y <= 220 ||
            (circulo_x - 25) == 510 && circulo_y >= 70 && circulo_y <= 150 ||
            (circulo_x - 25) == 75 && circulo_y >= 325 && circulo_y <= 375 ||
            (circulo_x - 25) == 75 && circulo_y >= 390 && circulo_y <= 480 ||
            (circulo_x - 25) == 140 && circulo_y >= 290 && circulo_y <= 420 ||
            (circulo_x - 25) == 200 && circulo_y >= 270 && circulo_y <= 310 ||
            (circulo_x - 25) == 75 && circulo_y >= 200 && circulo_y <= 310 ||
            (circulo_x - 25) == 210 && circulo_y >= 350 && circulo_y <= 480 ||
            (circulo_x - 25) == 290 && circulo_y >= 400 && circulo_y <= 450||
            (circulo_x - 25) == 380 && circulo_y >= 270 && circulo_y <= 480 ||
            (circulo_x - 25) == 440 && circulo_y >= 270 && circulo_y <= 430 ||
            (circulo_x - 25) == 510 && circulo_y >= 270 && circulo_y <= 335 ||
            (circulo_x - 25) == 300 && circulo_y >= 200 && circulo_y <= 250)
        {
          /* code */
        }
        else
        {
          circulo_x-=5;
          movientos++;
          circuloB(circulo_x + 5, circulo_y);
        }
      }
    }
    if (circulo_x>=515&&circulo_x<=565&&circulo_y>=90&&circulo_y<=140)
    {
      /*sleep(3);*/
      return movientos;
    }
    if (tecla == 82 || tecla == 114)
    {
      gotoxy(0,0);printf("x: %d", circulo_x);
      printf("\ny: %d", circulo_y);
      getch();
      goto inicio;
    }
    if (tecla == 27)
    {
      if ((pausa())== 0)
      {
        goto inicio;
      }
      else
      {
        cleardevice();
        return 0;
      }
    }
  } while(tecla != 87 || tecla != 119 || tecla != 83 || tecla != 115 ||
     tecla != 68 || tecla != 100 || tecla != 65 || tecla != 97);
}

void niveles()/*funcion que agrupa los niveles y escribe el score en un fichero*/
{
  int pass = 0, aux = 0;
  char auxilar[7], auxilar2[7];
  FILE *fichero;
  cleardevice();
  pass = level1();
  if (pass > 0)
  {
    levelUp();
    pass = level2(pass);
    if (pass > 0)
    {
      levelUp();
      pass = level3(pass);
      if (pass > 0)
      {
        if (pass > 900)
        {
          aux = pass / 900;
          if (aux > 10)
          {
            aux -= 10;
          }
          aux *= 10;
          setbkcolor(RED);
          settextstyle(DEFAULT_FONT, 0, 2);
          outtextxy(250, 100, "YOU LOSE");
          settextstyle(DEFAULT_FONT, 0, 2);
          outtextxy(190, 140, "BETTER LUCK FOR THE NEXT TIME!");
          rectangle(350, 200, 450, 245);
          sprintf(auxilar, "%d", aux);
          outtextxy(370, 220, auxilar);
          outtextxy(105, 220, "YOUR SCORE WAS:");

          rectangle(100, 340, 200, 405);
          outtextxy(50, 420, "MIN. MOVEMENTS ");
          outtextxy(50, 440, "ALLOWED");
          outtextxy(125, 370, "900");

          rectangle(420, 340, 520, 405);
          outtextxy(370, 420, "YOUR MOVEMENTS");
          sprintf(auxilar2, "%d", pass);
          outtextxy(450, 370, auxilar2);
          sleep(5);
        }
        else
        {
          aux = pass * 100;
          cleardevice();
          setbkcolor(GREEN);
          settextstyle(DEFAULT_FONT, 0, 2);
          outtextxy(250, 100, "YOU WIN");
          settextstyle(DEFAULT_FONT, 0, 2);
          outtextxy(190, 140, "CONGRATULATIONS!");
          rectangle(350, 200, 450, 245);
          sprintf(auxilar, "%d", aux);
          outtextxy(370, 220, auxilar);
          outtextxy(105, 220, "YOUR SCORE WAS:");

          rectangle(100, 340, 200, 405);
          outtextxy(50, 420, "MIN. MOVEMENTS ");
          outtextxy(50, 440, "ALLOWED");
          outtextxy(125, 370, "900");


          rectangle(420, 340, 520, 405);
          outtextxy(370, 420, "YOUR MOVEMENTS");
          sprintf(auxilar2, "%d", pass);
          outtextxy(450, 370, auxilar2);
          sleep(5);
        }
        fichero = fopen("C:\\TC20\\FICHEROS\\score.txt","a");
        fprintf(fichero,"\t\t\t\t    %05d\n", aux);
        fclose(fichero);
      }
    }
  }
}

int pausa(void)/*menu de pausa, devuelve 1 si es continuar, 0 si es salir*/
{
  int opcion = 0, ciclo = 0;
  cleardevice();
  /*pausa*/
  setcolor(5);
  arc(79,71,80,166,19);/*costado izquierdo*/
  line(60,66,60,405);
  arc(80,405,180,260,20);
  line(76,52,560,52);/*superior*/
  line(76,425,560,425);/*inferior*/
  arc(549,70,-7,59,21);/*costado derecho*/
  line(570,76,570,400);
  arc(549,406,-60,10,21);

  setcolor(14);
  settextstyle(DEFAULT_FONT, 0, 5);
  outtextxy(230, 125, "PAUSE");

  /*boton regresar*/
  setcolor(13);
  rectangle(137, 225, 257, 270);
  rectangle(147, 235, 247, 260);
  line(137, 225, 147, 235);
  line(137, 270, 147, 260);
  line(257, 225, 247, 235);
  line(257, 270, 247, 260);
  setcolor(15);
  settextstyle(DEFAULT_FONT, 0, 1);
  outtextxy(160, 245, "CONTINUE");

  /*boton salir*/
  setcolor(13);
  rectangle(379, 225, 499, 270);
  rectangle(389, 235, 489, 260);
  line(379, 225, 389, 235);
  line(379, 270, 389, 260);
  line(499, 225, 489, 235);
  line(499, 270, 489, 260);
  setcolor(15);
  settextstyle(DEFAULT_FONT, 0, 1);
  outtextxy(420, 245, "EXIT");

  do
  {
    mver();
    if (((minlimit(1, 137, 225, 257, 270)) == 1) && (mclick() == 1))/*boton continuar*/
    {
      mocultar();
      opcion = 0;
      ciclo = 1;
    }
    if ((minlimit(1, 379, 225, 499, 270)) == 1 && mclick() == 1)/*boton salir*/
    {
      mocultar();
      opcion = 1;
      ciclo = 1;
    }
  }while(ciclo == 0);
  return opcion;
}

void teclaW(void)/*tutorial tecla W*/
{
  int circulo_x = 0, circulo_y = 0, contador = 0;
  char tecla;
  cleardevice();
  setcolor(15);
  fflush(stdin);
  rectangle(400, 100, 500, 200);
  rectangle(415, 115, 485, 185);
  line(400, 100, 415, 115);
  line(400, 200, 415, 185);
  line(500, 100, 485, 115);
  line(500, 200, 485, 185);
  settextstyle(DEFAULT_FONT, 0, 7);
  outtextxy(425, 125, "W");
  circulo_x = 320;
  circulo_y = 400;
  circulo(circulo_x, circulo_y);
  do
  {
    tecla = getch();
    if (tecla == 87 || tecla == 119)
    {
      circuloB(circulo_x, circulo_y);
      circulo_y -= 5;
      circulo(circulo_x, circulo_y);
      contador++;
    }
    if (contador == 50)
    {
      sleep(3);
      break;
    }
  }while(tecla != 87 || tecla != 119);
}

void teclaS(void)/*tutorial tecla S*/
{
  int circulo_x = 0, circulo_y = 0, contador = 0;
  char tecla;
  cleardevice();
  setcolor(15);
  fflush(stdin);
  rectangle(400, 100, 500, 200);
  rectangle(415, 115, 485, 185);
  line(400, 100, 415, 115);
  line(400, 200, 415, 185);
  line(500, 100, 485, 115);
  line(500, 200, 485, 185);
  settextstyle(DEFAULT_FONT, 0, 7);
  outtextxy(425, 125, "S");
  circulo_x = 320;
  circulo_y = 150;
  circulo(circulo_x, circulo_y);
  do
  {
    tecla = getch();
    if (tecla == 83 || tecla == 115)
    {
      circuloB(circulo_x, circulo_y);
      circulo_y += 5;
      circulo(circulo_x, circulo_y);
      contador++;
    }
    if (contador == 50)
    {
      sleep(3);
      break;
    }
  }while(tecla != 83 || tecla != 115);
}

void teclaD(void)/*tutorial tecla D*/
{
  int circulo_x = 0, circulo_y = 0, contador = 0;
  char tecla;
  cleardevice();
  setcolor(15);
  fflush(stdin);
  rectangle(400, 100, 500, 200);
  rectangle(415, 115, 485, 185);
  line(400, 100, 415, 115);
  line(400, 200, 415, 185);
  line(500, 100, 485, 115);
  line(500, 200, 485, 185);
  settextstyle(DEFAULT_FONT, 0, 7);
  outtextxy(425, 125, "D");
  circulo_x = 320;
  circulo_y = 400;
  circulo(circulo_x, circulo_y);
  do
  {
    tecla = getch();
    if (tecla == 68 || tecla == 100)
    {
      circuloB(circulo_x, circulo_y);
      circulo_x += 5;
      circulo(circulo_x, circulo_y);
      contador++;
    }
    if (contador == 50)
    {
      sleep(3);
      break;
    }
  }while(tecla != 68 || tecla != 100);
}

void teclaA(void)/*tutorial tecla A*/
{
  int circulo_x = 0, circulo_y = 0, contador = 0;
  char tecla;
  cleardevice();
  setcolor(15);
  fflush(stdin);
  rectangle(400, 100, 500, 200);
  rectangle(415, 115, 485, 185);
  line(400, 100, 415, 115);
  line(400, 200, 415, 185);
  line(500, 100, 485, 115);
  line(500, 200, 485, 185);
  settextstyle(DEFAULT_FONT, 0, 7);
  outtextxy(425, 125, "A");
  circulo_x = 320;
  circulo_y = 400;
  circulo(circulo_x, circulo_y);
  do
  {
    tecla = getch();
    if (tecla == 65 || tecla == 97)
    {
      circuloB(circulo_x, circulo_y);
      circulo_x -= 5;
      circulo(circulo_x, circulo_y);
      contador++;
    }
    if (contador == 50)
    {
      sleep(3);
      break;
    }
  }while(tecla != 65 || tecla != 97);
}

void script(void)/*lee las indicaciones de como jugar*/
{
  FILE *archivo;
	char caracter;
  clrscr();
  cleardevice();
  setbkcolor(BLACK);
  fflush(stdin);
	archivo = fopen("C:\\TC20\\FICHEROS\\tutorial.txt","r");

	if (archivo == NULL)
  {
    printf("\nError de apertura del archivo. \n\n");
  }
  else
  {
    rewind(archivo);
    while((caracter = fgetc(archivo)) != EOF)
	  {
		  printf("%c",caracter);
	  }
  }
  fclose(archivo);
  setcolor(15);
  arc(79,71,80,166,19);/*costado izquierdo*/
  line(60,66,60,405);
  arc(80,405,180,260,20);

  line(76,52,560,52);/*superior*/
  line(76,425,560,425);/*inferior*/

  arc(549,70,-7,59,21);/*costado derecho*/
  line(570,76,570,400);
  arc(549,406,-60,10,21);
  kirby(100, 390);
  sleep(5);
}

void tutorial(void)/*tutorial completo*/
{
  cleardevice();
  script();
  teclaW();
  teclaS();
  teclaD();
  teclaA();
}

void pantalla (void)/*marco blanco pantalla*/
{
  setcolor(15);
	arc(79,71,80,166,19);/*costado izquierdo*/
    line(60,66,60,405);
    arc(80,405,180,260,20);

    line(76,52,560,52);/*superior*/
    line(76,425,560,425);/*inferior*/

	arc(549,70,-7,59,21);/*costado derecho*/
    line(570,76,570,400);
    arc(549,406,-60,10,21);
    setcolor(7);
    /*line(76,52,560,52);*/
    line(61,82,170,82);                                                             line(460,82,569,82);
    line(171,82,181,92);line(181,92,450,92);line(460,82,450,92);


}

void marcop(void)/*marcos de la pantalla*/
{
  setfillstyle(1,12);
   setcolor(12); circle(20,455,20);  circle(619, 22, 20);
  floodfill(20,455,12);  floodfill(620,30,12);
	setfillstyle(1,5);

    setcolor(5);rectangle(120,35,510,25);	/*yiah te imaginas que es*/
	floodfill(121,34,5);

	line(120,24,110,30); line(120,34,110,40);circle(115,32,2); floodfill(115,32,5);/*izquierda*/
	line(510,24,520,30); line(510,34,520,40);circle(515,32,2); floodfill(515,32,5);/*derecha*/

	/*decoracion metodo naruto(relleno)*/
	rectangle(74,30,109,40);floodfill(75,31,5); /*parte de arribita esquina*/
	arc(68,62,80,170,32);
	arc(68,62,75,170,22);

    bar(37,55,47,412);floodfill(38,53,5);   /*el cateto derecho y el unico creo*/


    rectangle(520,30,560,40);floodfill(521,31,5); /*parte de arribita esquina derecha*/
	arc(565,62,10,100,32);
	arc(565,62,10,100,22);

    bar(586,57,596,100);floodfill(587,56,5);


    /*parte de abajito esquina izquierda*/
     arc(73,413,180,273,26);/*<-- este es el mas cercano a la pantalla*/
	 arc(72,414,175,275,35);
	 /**/rectangle(75,439,82,449); floodfill(74,440,5);/*tocas esto y te jodes*/
	 bar(75,439,109,449);                           line(110,439,130,429); circle(125,440,2);circle(120,448,2);circle(138,438,2);
                                                    line(110,449,130,459); circle(150,441,2);circle(135,450,2);

    /*segundo marco*/
    setfillstyle(1,12);
    setcolor(12);bar(120,5,510,15);	/*retro secundario tope*/

	line(120,4,110,10); line(120,14,110,20);/*izquierda*/
	bar(54,10,109,20);  circle(115,12,2);floodfill(115,12,12);

	arc(48,42,80,170,32);
	arc(49,42,75,170,22);
	bar(16,38,27,420); floodfill(17,37,12);
	line(16,420,6,432);line(26,420,35,432);
	circle(15,430,2); circle(21,425,2); circle(28,430,2);

	line(510,4,520,10); line(510,14,520,20);/*derecha*/bar(520,10,560,20);line(560,10,580,5);line(560,20,580,25);
    circle(515,12,2); floodfill(515,12,12);            circle(565,15,2);circle(572,18,2);circle(572,11,2);
                                                       circle(580,15,2);circle(585,19,2);circle(585,10,2);
    circle(585,109,3);floodfill(586,109,12);
        /*ARCADE*/

    settextstyle(0,0,2);

     setcolor(12);
    outtextxy(199, 436, "A R C A D E");
    outtextxy(198, 437, "A R C A D E");
    outtextxy(197, 438, "A R C A D E");
    outtextxy(196, 439, "A R C A D E");

    setcolor(14);
    outtextxy(200, 433, "A R C A D E");
    outtextxy(200, 435, "A R C A D E");

    /*No se que hare aqui pero, algo hice*/
    setcolor(5);
	rectangle(580,100,630,355);/*mini laberin*/

    line(581,120,590,120);line(590,120,590,110);
    line(629,110,620,110);line(619,105,619,120);

     line(600,125,600,135);line(601,125,610,125);
                           line(601,135,610,135);

    line(581,160,610,160);line(610,150,610,175);

    line(581,180,596,180);

    line(600,199,620,199);line(611,200,611,220);line(612,220,632,220);

    line(581,219,591,219);line(592,219,592,230);

    line(600,240,600,250);                      line(610,240,610,250);
                          line(601,250,610,250);

     line(595,270,595,330); line(596,270,620,270);
                            line(596,320,629,320);

    line(590,340,590,355);
    setfillstyle(1,10);
     setcolor(10); rectangle(609,335,629,354);
     floodfill(610,336,10);


     setfillstyle(1,12);
     /*line(570,415,620,455);*/setcolor(12);
     line(520,455,595,435); line(595,435,620,375);
     line(520,455,620,455); line(620,375,620,455);
     floodfill(591,454,12);

     setfillstyle(1,9);
}

void botones(void)/*botones primera screen*/
{
	setfillstyle(1,9);

                                  setcolor(9);/*U*/
    /*pilar iz*/bar(281,61,291,91);  /*fila bot*/bar(291,83,311,91); /*pilar medio*/bar(311,73,321,91);
                                               /*N y i*/
                /*pilar*/ bar(296,61,306,80);/*hori top*/bar(306,61,336,70); /*pilar de*/bar(326,70,336,91);
                /*hori bot*/bar(336,81,346,91); /*pilar de i*/bar(341,74,351,91); /*tilde*/bar(341,61,351,70);
   setfillstyle(1,7);
  setcolor(7);
  /*line(60,66,60,405);*/
  /*presentacion*/ bar(80,120,200,385); /*Game*/bar(255,120,375,385);/*Off*/bar(430,120,550,385);
   setcolor(0);rectangle(81,121,199,384);rectangle(82,122,198,383);/*presentation*/
   rectangle(256,121,374,384);rectangle(257,122,373,383);/*game*/
   rectangle(431,121,549,384);rectangle(432,122,548,383);/*off*/

  /*------------------letras--------------------------*/

   settextstyle(0,0,6);

                           setcolor(15);rectangle(109,196,168,251);rectangle(110,197,168,251);/*profundidad*/
    setcolor(0); outtextxy(118,201,"P");rectangle(107,194,168,251);rectangle(108,195,167,250);

     settextstyle(0,0,5);
     setcolor(12);
    outtextxy(124, 204, "P");
    settextstyle(0,0,0);setcolor(4);
    outtextxy(90,315,"PRESENTATION");setcolor(15);rectangle(88,310,188,325);setcolor(0);rectangle(87,309,188,325);


	    settextstyle(0,0,6);

	                           setcolor(15);rectangle(284,196,342,251);rectangle(285,197,342,251);/*profundidad*/
	    setcolor(0); outtextxy(294,201,"G");rectangle(282,194,342,251);rectangle(283,195,343,250);

	     settextstyle(0,0,5);
	     setcolor(12);
	    outtextxy(300, 204, "G");
	    settextstyle(0,0,0);setcolor(4);
	    outtextxy(285,315,"G A M E");setcolor(15);rectangle(275,310,350,325);setcolor(0);rectangle(274,309,350,325);


	     settextstyle(0,0,6);

	                           setcolor(15);rectangle(457,196,519,251);rectangle(458,197,519,251);/*profundidad*/
	    setcolor(0); outtextxy(467,201,"O");rectangle(455,194,519,251);rectangle(456,195,520,250);

	     settextstyle(0,0,5);
	     setcolor(12);
	    outtextxy(473, 204, "O");
	    settextstyle(0,0,0);setcolor(4);
	    outtextxy(458,315,"TURN OFF");setcolor(15);rectangle(448,310,532,325);setcolor(0);rectangle(447,309,532,325);
}

void score(void)/*imprime pantalla de puntaje*/
{
  FILE *archivo;
  char caracter, tecla;
  clrscr();
  cleardevice();
  setbkcolor(BLACK);
  fflush(stdin);
	archivo = fopen("C:\\TC20\\FICHEROS\\SCORE.txt","r");
	if (archivo == NULL)
  {
    printf("\nError de apertura del archivo. \n\n");
  }
  else
  {
    rewind(archivo);
    while((caracter = fgetc(archivo)) != EOF)
	  {
		    printf("%c",caracter);
	  }
  }
  fclose(archivo);
  pantalla();
  marcop();

  setcolor(14);
  settextstyle(DEFAULT_FONT, 0, 3);
  outtextxy(250, 60, "SCORE");
  settextstyle(DEFAULT_FONT, 0, 1);
  outtextxy(350, 410, "Presione ENTER para volver.");
  do
  {
    tecla = getch();
    if (tecla == 13)
    {
      break;
    }
  } while(tecla != 13);
}

void presentacion	(void)
{
  FILE *f;
  char caracter;
  clrscr();
  cleardevice();
  setbkcolor(BLACK);
  fflush(stdin);

  f = fopen("C:\\TC20\\FICHEROS\\P.txt","r");

  if (f == NULL)
  {
    printf("\nError de apertura del archivo. \n\n");
  }
  else
  {
    rewind(f);
    while((caracter = fgetc(f)) != EOF)
    {
      printf("%c",caracter);
    }
  }
  fclose(f);
  pantalla();
  marcop();
  setcolor(9);/*U*/
  /*pilar iz*/bar(281,61,291,91);  /*fila bot*/bar(291,83,311,91); /*pilar medio*/bar(311,73,321,91);
               /*N y i*/
  /*pilar*/ bar(296,61,306,80);/*hori top*/bar(306,61,336,70); /*pilar de*/bar(326,70,336,91);
  /*hori bot*/bar(336,81,346,91); /*pilar de i*/bar(341,74,351,91); /*tilde*/bar(341,61,351,70);

getch();
}

/*---------------------------- SCREEN-------------------------------*/

int screen1(void)/*devuelve 0 para presentacion, 1 para jugar, 2 para salir*/
{
  int ciclo = 0, opcion = 0;
  /*time_t hora_actual;*/
  /*struct time tiempo;
  struct date d;*/
  /*int seg,min,w,h;
  float hora;
  char mensaje[20], fecha[50];
  int xseg, yseg, xmin, ymin, xhora, yhora;*/
  cleardevice();
  pantalla();
  marcop();
  botones();
  do
  {
    fflush(stdin);
    mver();
   	 /*gettime(&tiempo);
   	 seg=tiempo.ti_sec;
   	 min=tiempo.ti_min;
   	 hora=tiempo.ti_hour;
   	 if(hora>12)
   	 hora-=12;
   	 hora+=(min/60);

   	 setcolor(WHITE);
   	 sprintf(mensaje,"%2.0f: %2.0d: %2.0d",hora,tiempo.ti_min,tiempo.ti_sec);
   	 outtextxy(72,62,mensaje);

   		sleep(1);
   	setcolor(BLACK);

   	outtextxy(72,62,mensaje);

    getdate(&d);
    sprintf(fecha,"%.d / %.d / %.d", d.da_day,d.da_mon,d.da_year);

    outtextxy(400,62,fecha);*/
     /*do{
       hora_actual = time(NULL);
      setcolor(WHITE);
     outtextxy(72,62,ctime(&hora_actual));
     sleep(1);
      setcolor(BLACK);

     outtextxy(72,62,ctime(&hora_actual));

     if (mclick() == 1)
     {
       break;
     }


   } while(mclick() != 1);*/

    if (((minlimit(1, 81, 121, 199, 384)) == 1) && (mclick() == 1))/*boton continuar*/
    {
      mocultar();
      opcion = 0;
      ciclo = 1;
    }
    if ((minlimit(1, 256, 121, 374, 384)) == 1 && mclick() == 1)/*boton salir*/
    {
      mocultar();
      opcion = 1;
      ciclo = 1;
    }
    if ((minlimit(1, 431, 121, 549, 384)) == 1 && mclick() == 1)/*boton salir*/
    {
      mocultar();
      opcion = 2;
      ciclo = 1;
    }
  } while(ciclo == 0);

  return opcion;
}

int screen2(void)/*devuelve 0 para play, 1 para score, 2 para tutorial, 3 para salir*/
{
  int ciclo = 0, opcion = 0;

  cleardevice();
  setbkcolor(BLACK);
  setcolor(5);
  setlinestyle(0,0, 3);
  /* Lineas verticales */
  line(75 ,0, 75, 75);
  line(150, 100, 150, 225);
  line(225, 75, 225, 125);
  line(450, 0, 450, 125);
  line(375, 125, 375, 200);
  line(570, 0, 570, 200);
  line(510, 70, 510, 150);
  line(75, 410, 75, 480);
  line(140, 290, 140, 410);
  line(75, 220, 75, 290);
  line(210, 370, 210, 480);
  line(380, 290, 380, 480);
  line(440, 290, 440, 415);
  line(510, 290, 510, 335);
  /* lineas horizontales */
  line(0  ,150, 150, 150);
  line(225, 125, 375, 125);
  line(325, 55, 450, 55);
  line(150, 225, 300, 225);
  line(375, 200, 450, 200);
  line(510, 150, 570, 150);
  line(0, 350, 75, 350);
  line(75, 410, 140, 410);
  line(75, 290, 200, 290);
  line(210, 425, 290, 425);
  line(285, 340, 380, 340);
  line(440, 415, 640, 415);
  line(510, 335, 640, 335);
  line(580, 265, 640, 265);
  /*Titulo*/

  settextstyle(0,0,6);
  setcolor(14);outtextxy(300,50,"Kirby's");outtextxy(298,52,"Kirby's");
  outtextxy(405,110,"Maze");outtextxy(403,112,"Maze");

  setcolor(12);outtextxy(302,48,"Kirby's");
  outtextxy(407,108,"Maze");
  /*botones*/
  /*pa las lineas normales*/
  setfillstyle(1,12);/*supuestamente es el kirby*/
  setcolor(12);circle(140,170,120);floodfill(140,170,12);

  settextstyle(0,0,2);/*texto*/

  setfillstyle(1,7);/*color*/
  setcolor(7);bar(204,209,390,239); setcolor(BLACK);outtextxy(242,221,"P L A Y");setcolor(BLACK);outtextxy(243,220,"P L A Y");
  setlinestyle(0,0, 3);     setcolor(14);outtextxy(245,219,"P L A Y");/*primero jugar*/
  setcolor(15);line(205,210,389,210);  line(205,210,205,238); setcolor(0);rectangle(203,208,391,240);

  setcolor(7);bar(204,259,390,289); setcolor(BLACK);outtextxy(242,266,"Score");setcolor(BLACK);outtextxy(243,267,"Score");
  setlinestyle(0,0, 3);     setcolor(14);outtextxy(245,265,"Score");/*segundo score*/
  setcolor(15);line(205,260,389,260);  line(205,260,205,288); setcolor(0);rectangle(203,258,391,290);


  setcolor(7);bar(204,309,390,339); setcolor(BLACK);outtextxy(239,315,"Tutorial");setcolor(BLACK);outtextxy(240,317,"Tutorial");
  setlinestyle(0,0, 3);     setcolor(14);outtextxy(243,315,"Tutorial");/*tercer tuto*/
  setcolor(15);line(205,310,389,310);  line(205,310,205,338); setcolor(0);rectangle(203,308,391,340);

  setcolor(7);bar(204,359,390,389); setcolor(BLACK);outtextxy(249,366,"Exit");setcolor(BLACK);outtextxy(250,367,"Exit");
  setlinestyle(0,0, 3);     setcolor(14);outtextxy(253,366,"Exit");/*tercero*/
  setcolor(15);line(205,360,389,360);  line(205,360,205,388); setcolor(0);rectangle(203,358,391,390);

  fflush(stdin);
  mver();
  /*msituar(1, 320, 240);*/
  do
  {
    if (((minlimit(1, 204, 209, 390, 239)) == 1) && (mclick() == 1))/*boton continuar*/
    {
      mocultar();
      opcion = 0;
      ciclo = 1;
    }
    if ((minlimit(1, 204, 259, 390, 289)) == 1 && mclick() == 1)/*boton salir*/
    {
      mocultar();
      opcion = 1;
      ciclo = 1;
    }
    if ((minlimit(1, 204, 309, 390, 339)) == 1 && mclick() == 1)/*boton salir*/
    {
      mocultar();
      opcion = 2;
      ciclo = 1;
    }
    if ((minlimit(1, 204, 359, 390, 389)) == 1 && mclick() == 1)/*boton salir*/
    {
      mocultar();
      opcion = 3;
      ciclo = 1;
    }
  } while(ciclo == 0);
  return opcion;
}
