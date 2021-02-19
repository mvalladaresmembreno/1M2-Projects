#include<stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <dos.h>
#include <stdlib.h>

void barra_de_carga()
	{
		int i,puntitos = 44,x,y,fin = 50,num = 0,cargando = 15,color;
		int esquina_1 = 201,esquina_2 = 200,esquina_3 = 188,esquina_4 = 187,filas = 205,columnas = 186;
		int barra_carga;
		x = 14;
		y = 19;
		clrscr();
		textbackground(BLACK);
		clrscr();
		textcolor(WHITE);gotoxy(36,16);cprintf("Cargando");
		for (i = 0; i < 1;)
		{
			if(x == 14 && y == 19)
			{
				gotoxy(x,y);
				printf("%c",esquina_1);
				y++;
			}
			else if(x == 14 && y == 20)
			{
				gotoxy(x,y);
				printf("%c",columnas);
				y++;
			}
			else if(x == 14 && y == 21)
			{
				gotoxy(x,y);
				printf("%c",esquina_2);
				x++;
			}
			else if((x > 14 && x != 65) && y == 21)
			{
				gotoxy(x,y);
				printf("%c",filas);
				x++;
			}
			else if(x == 65 && y == 21)
			{
				gotoxy(x,y);
				printf("%c",esquina_3);
				y--;
			}
			else if(x == 65 && y == 20)
			{
				gotoxy(x,y);
				printf("%c",columnas);
				y--;
			}
			else if(x == 65 && y == 19)
			{
				gotoxy(x,y);
				printf("%c",esquina_4);
				x--;
			}
			else if((x > 14 && x != 65) && y == 19)
			{
				gotoxy(x,y);
				printf("%c",filas);
				x--;
			}
			if(x == 15 && y == 19)
			{
				gotoxy(x,y);
				printf("%c",filas);
				break;
			}
		}
		for (barra_carga = 0; barra_carga <= fin; barra_carga ++)
		{
			if(num==100)
				textcolor(GREEN);gotoxy(39,18);cprintf("%d%",num);num+=2;
			if(barra_carga<49)
			{
				if(puntitos==44)
				{
					gotoxy(puntitos,16);printf("   ");delay(99);
				}
				else if(puntitos==45)
				{
					gotoxy(puntitos,16);printf("  ");delay(99);
				}
					else if(puntitos==46)
				{
					gotoxy(puntitos,16);printf(" ");delay(99);
				}
					else if(puntitos==47)
				{
					gotoxy(puntitos,16);printf("");delay(99);x=43;
				}
			}
			else
			{
				gotoxy(36,16);printf("           ");
				textcolor(GREEN+BLINK);gotoxy(36,16);cprintf("Completado");
			}
			if(barra_carga>0)
			{
				if(num>0 && num<=14)
					color=15;	/* color blanco */
				else if(num>15 && num<=28)
					color=14;	/* color amarrillo */
				else if(num>29 && num<=42)
					color=3;	/* color cyan */
				else if(num>43 && num<=56)
					color=2;	/* color verde */
				else if(num>57 && num<=70)
					color=5;	/* color magenta */
				else if(num>71 && num<=84)
					color=4;   /* color rojo */
				else if(num>85 && num<=100)
					color=15;   /* color azul */
				textcolor(color);gotoxy(cargando,20);cprintf("%c",219);delay(60);
				cargando++;
			}
			puntitos++;
	printf("\n");
	}
 sleep(2);
}

void logo()
	{
		int i,x,y;
		char cuadro=219;
		x=2;
		y=2;
		clrscr();
		textbackground(BLACK);
		clrscr();
		for (i = 0; i < 78; i++) /*	ciclo for para llenar toda la pantalla*/
		{
			if (y>0 && y<=6)
			{
				if(x>1 && x<=14)
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				 else if(x>14 && x<=17)
				{
					textcolor(WHITE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else if(x>17 && x<=62)
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else if(x>62 && x<=65)
				{
					textcolor(WHITE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
			}
			else if (y>6 && y<=8)
			{
				if(x>1 && x<=14)
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				 else if(x>14 && x<=17)
				{
					textcolor(WHITE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else if(x>17 && x<=30)
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else if(x>30 && x<=49)
				{
					textcolor(WHITE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else if(x>49 && x<=62)
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else
				{
					textcolor(WHITE);gotoxy(x,y);cprintf("%c",cuadro);
				}
			}
			else if (y>8 && y<=17)
			{
				if(x>1 && x<=14)
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				 else if(x>14 && x<=17)
				{
					textcolor(WHITE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else if(x>17 && x<=30)
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else if(x>30 && x<=33)
				{
					textcolor(WHITE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else if(x>33 && x<=46)
				{
					textcolor(BLUE);(x,y);cprintf("%c",cuadro);
				}
				else if(x>46 && x<=49)
				{
					textcolor(WHITE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else if(x>49 && x<=62)
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else if(x>62 && x<=65)
				{
					textcolor(WHITE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
			}
			else if (y>17 && y<=19)
			{
				if(x>1 && x<=14)
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				 else if(x>14 && x<=33)
				{
					textcolor(WHITE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else if(x>33 && x<=46)
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else if(x>46 && x<=49)
				{
					textcolor(WHITE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else if(x>49 && x<=62)
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else if(x>62 && x<=65)
				{
					textcolor(WHITE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
			}
			else
			{
				if(x>1 && x<=46)
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				 else if(x>46 && x<=49)
				{
					textcolor(WHITE);gotoxy(x,y);cprintf("%c",cuadro);
				}
				else
				{
					textcolor(BLUE);gotoxy(x,y);cprintf("%c",cuadro);
				}
			}
			x++;
			if(y>0 && y<24)
			{
				if (x==79)
				{
					y++;
					x=2;
					i=0;
					delay(99);
				}
			}
		}
		textcolor(WHITE);
	 sleep(2);
	 	/*getch();*/
	}
