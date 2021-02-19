#include<stdio.h>
#include<conio.h>
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
}

void logo()
	{
		int i,x,y;
		char cuadro=219;
		x=2;
		y=2;
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
		/*getch();*/
	}
	/*Proyecto #1 Loteria*/
	void menu()
{
	int i=0;
	textbackground(BLUE);
	clrscr();
	textcolor(WHITE);
	for (i = 4; i <= 77; i++)/*Parte superior*/
	{
	gotoxy(i, 5); cprintf("%c", 219);
	}
	gotoxy(3, 4); cprintf("%c", 219);gotoxy(78, 4); cprintf("%c", 219);
	gotoxy(2, 3); cprintf("%c", 219);gotoxy(79, 3); cprintf("%c", 219);
	gotoxy(1, 2); cprintf("%c", 219);gotoxy(80, 2); cprintf("%c", 219);
	gotoxy(1, 1); cprintf("%c", 219);gotoxy(80, 1); cprintf("%c", 219);

	gotoxy(17, 1);cprintf("  (  )  (  _  )(_  _)( ___)(  _ \\(_  _)  /__\\");
	gotoxy(17, 2);cprintf("   )(__  )(_)(   )(   )__)  )   / _)(_  /(__)\\");
	gotoxy(17, 3);cprintf("  (____)(_____) (__) (____)(_)\\_)(____)(__)(__)");

	for (i = 4; i <= 77; i++)/*Parte inferior*/
	{
	gotoxy(i, 21); cprintf("%c", 219);
	}
	gotoxy(3, 21); cprintf("%c", 219);gotoxy(78, 21); cprintf("%c", 219);
	gotoxy(2, 22); cprintf("%c", 219);gotoxy(79, 22); cprintf("%c", 219);
	gotoxy(1, 23); cprintf("%c", 219);gotoxy(80, 23); cprintf("%c", 219);

	for (i = 0; i <=15; i++)/*Lateral derecho*/
	{
		gotoxy(65+i, 8); cprintf("%c", 219);
	}
	for (i = 0; i <=15; i++)
	{
		gotoxy(65+i, 19); cprintf("%c", 219);
	}
	for (i = 0; i < 11; i++)
	{
		gotoxy(65, 8+i); cprintf("%c", 219);
	}
	gotoxy(67, 11); cprintf("N%cmero", 163);
	gotoxy(67, 12); cprintf("comprado", 163);

	gotoxy(67, 15); cprintf("Cantidad", 163);
	gotoxy(67, 16); cprintf("apostada", 163);

	for (i = 0; i < 10; i++) /*Medioa abajo*/
	{
		gotoxy(35+i,15);cprintf("%c", 219);/*Linea grande*/
	}
	for (i = 0; i < 8; i++)
	{
		gotoxy(36+i,16);cprintf("%c", 219);/*Linea pequeña*/
	}
	for (i = 0; i < 10; i++) /*Medio arriba*/
	{
		gotoxy(35+i,11);cprintf("%c", 219);/*Linea grande*/
	}
	for (i = 0; i < 8; i++)
	{
		gotoxy(36+i,10);cprintf("%c", 219);/*Linea pequena*/
	}
	textcolor(BLACK);/*Color negro*/
	gotoxy(5,23);cprintf("resentaci%cn", 162);
	gotoxy(22,23);cprintf("dquirir");
	gotoxy(21,24);cprintf("n%cmero",163);
	gotoxy(35,23);cprintf("omenzar");
	gotoxy(34,24);cprintf("a jugar");
	gotoxy(48,23);cprintf("olver");
	gotoxy(47,24);cprintf("a jugar");
	gotoxy(62,23);cprintf("alir");

	textcolor(LIGHTGREEN);/*Color verde claro*/
	gotoxy(04,23);cprintf("P");
	gotoxy(21,23);cprintf("A");
	gotoxy(34,23);cprintf("C");
	gotoxy(47,23);cprintf("V");
	gotoxy(61,23);cprintf("S");
	/*textcolor(BLACK);
	gotoxy(73,24);cprintf("%c%c%c", 196, 196, 196);*/
}

void ganaste()
{
	clrscr();
  textbackground(GREEN);
  clrscr();
  textcolor(WHITE);
  gotoxy(35,12);cprintf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201,205,205,205,205,205,205,205,205,205,205,205,205,187);
  gotoxy(35,13);cprintf("%c GANASTE!!! %c", 186,186);
  gotoxy(35,14);cprintf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void perdiste()
{
	clrscr();
  textbackground(RED);
  clrscr();
  textcolor(WHITE);
  gotoxy(34,12);cprintf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
  gotoxy(34,13);cprintf("%c PERDISTE!!! %c", 186,186);
  gotoxy(34,14);cprintf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void presentacion()
{

  clrscr();
	textbackground(BLUE);
	clrscr();
	textcolor(WHITE);
  do
	{
    clrscr();
		gotoxy(20,2);cprintf("Universidad Nacional de Ingener%ca UNI\n", 161);
		gotoxy(8,3);cprintf("Facultad de Elctr%cnica y Computaci%cn\n", 162, 162);
		gotoxy(8,6);cprintf("Docente: Ing Nelson Barrios\n");
		gotoxy(8,7);cprintf("Proyecto: Loter%ca \n", 161);
		gotoxy(8,8);cprintf("Grupo: 1M2-CO\n");
		gotoxy(8,11);cprintf("Integrantes, carn%c\n", 130);
		gotoxy(8,12);cprintf("Margarita Concepci%cn Valladares Membre%co, 2020-0455U", 162, 164);
		gotoxy(8,13);cprintf("Nestor Alexander Membre%co Cuadra, 2020-0504U", 164);
		gotoxy(8,14);cprintf("Weychen Eng Cuadrado, 2020-0316U");
		gotoxy(8,16);cprintf("Defensa: 02/08/2020 \n");
    sleep(1);
		gotoxy(35, 24);cprintf("Precione ENTER para volver al men%c", 163);
	}
	while(!kbhit());
}
