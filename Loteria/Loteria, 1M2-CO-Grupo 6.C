#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "almacen.h"


void main (void)
{

    int random=0, variable=0, contador=0, opc=0, i=0, numero_comprado=0;
    int cantidad_apostar=0, juega=0;
    char caracter, validacion[3];
    clrscr();
    logo();
    sleep(3);
    barra_de_carga();
    sleep(3);
    while(opc!=5)
    {
      i=0; opc=0;
      clrscr();
      menu();
    	gotoxy(76,12);cprintf("%02d", numero_comprado);
    	gotoxy(76,16);cprintf("C$%d", cantidad_apostar);
    	gotoxy(39,13);cprintf("%02d", random);
    	gotoxy(80,23);cprintf("");

      for (i = 0; i < 2; i++)
      {
        validacion[i]=' ';
      }
        i=0;
        fflush(stdin);
          while(caracter=getch()) /*Ciclo infinito para validar que solo se pueda*/
          {                       /*escribir las letras correspondiente a cada inciso*/

            if (caracter==80||caracter==112||caracter==65||caracter==97||
                caracter==67||caracter==99||caracter==86||caracter==118||
                caracter==83||caracter==115)
            {
              if (i==0)
              {
                validacion[i]=caracter;
               break;
              }
            }
          }

if (validacion[0]==80||validacion[0]==112)
{
  opc=1;
}

else if (validacion[0]==65||validacion[0]==97)
{
  opc=2;
}
else if (validacion[0]==67||validacion[0]==99)
{
  opc=3;
}
else if (validacion[0]==86||validacion[0]==118)
{
  opc=4;
}
else
{
  opc=5;
}

switch(opc)
{
  clrscr();
    case 1:
            presentacion();
    break;
    case 2:
			if(juega==0)
			{
            volver_jugar:
            numero_comprado=0;
            cantidad_apostar=0;
            clrscr();
            textcolor(WHITE);
            gotoxy(15, 12);cprintf("Escriba el n%cmero que desea comprar. (0-99)", 163);
						gotoxy(25, 13);cprintf("--> ");
					    fflush(stdin);

    						numero_comprado=0;
    						for (i = 0; i < 2; i++)
    						{
    							validacion[i]=' ';
    						}
    						i=0;
    						while(caracter=getch()) /*Ciclo infinito para validar que solo se pueda*/
    						{                       /*escribir las letras correspondiente a cada inciso*/
    							if (caracter==13)
    							{
    								if (i>=1)
    								{
    									validacion[i]='\0';
    									break;
    								}
    							}
    							if (caracter>=48&&caracter<=57)
    							{
    								if (i>=0&&i<=1)
    								{
    									printf("%c", caracter);
    									validacion[i]=caracter;
    									i++;
    								}
    							}
    							if (caracter==8)
    							{
    								if (i>0)
    								{
    									i--;
    									printf("\b \b");
    								}
    							}
    						}

    					numero_comprado=atoi(validacion);
					clrscr();
					gotoxy(15,12);cprintf("Escriba la cantidad de dinero que desea apostar\n");
					gotoxy(25,13);cprintf("--> C$");
                    fflush(stdin);
					for (i = 0; i < 3; i++)
					{
						validacion[i]=' ';
					}
          validacion_dinero:
          i=0;
					while(caracter=getch()) /*Ciclo infinito para validar que solo se pueda*/
					{                       /*escribir las letras correspondiente a cada inciso*/
						if (caracter==13)
						{
							if (i>=1)
							{
								validacion[i]='\0';
								break;
							}
						}

						if (caracter>=48&&caracter<=57)
						{
							if (i==0)
							{
								if (caracter==48)
								{
                    goto validacion_dinero;
								}
							}
							if (i>=0&&i<=2)
							{

								printf("%c", caracter);
								validacion[i]=caracter;
								i++;
							}
						}
						if (caracter==8)
						{
							if (i>0)
							{
								i--;
								printf("\b \b");
							}
						}
					}

					cantidad_apostar = atoi (validacion);
					gotoxy(35, 24);cprintf("Presione ENTER para continuar");
					getch();
					juega=1;
			}
    break;
    case 3:
		    if(juega==1)
		    {
		        /*Da un numero aleatorio, si este coincide con el valor de "numero_comprado"
		 mostrara un mensaje diciendo "ganaste", sino mostrara un mensaje diciendo "perdiste"*/
				contador=0;
				srand (time(NULL));
					while(variable==0)/*Bucle infinito*/
					{
						contador++;
						if (contador==100)/*Determina el fin del bucle*/
						{
							break; /*Rompe el bucle*/
						}
						else
						{
						random=0; /*Limpua la variable*/
						fflush(stdin);/*Limpia el buffer*/
						random=rand() % 100 ; /*Saca un numero random entre 0 y 99*/
            gotoxy(39,13);cprintf("%02d", random);/*Imprime el numero random obtenido*/
						delay(100); /*Demora de 100 milisegundos*/
            gotoxy(39,13);printf("  "); /*Limpia la pantalla para crear la ilusion de animacion*/
						}
					}
            /*Inicio de animacion de salida del numero random*/
	          textcolor(LIGHTGREEN+BLINK);
            gotoxy(39,13);cprintf("%02d", random);
            sleep(3);/*fin de animacion*/

				if (random==numero_comprado)/*Condicional, de ser cierta imprime "Ganaste"*/
				{							/*de otra forma imprime "Perdiste"*/
					ganaste();
					gotoxy(35,20);cprintf("Premio $%d", cantidad_apostar*3);
				}
				else
				{
					perdiste();
				}
				gotoxy(40, 24);cprintf("Presione ENTER para continuar");getch();
                juega=2;
		    }
    break;
    case 4:
            if(juega==2)
            {
                goto volver_jugar;
            }

    break;
    default:

    break;

}
}
clrscr();
gotoxy(40, 23);printf("Cerrando programa...");
sleep(2);
}
