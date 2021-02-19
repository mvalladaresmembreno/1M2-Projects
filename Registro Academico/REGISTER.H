#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


int GetIntR(void)/*Funcion que valida un numero entero de hasta 3 cifras*/
{
  int numer_salida=0, a=0, numero_val=0;
  char tecla, numero[4];
  while (numero_val==0)
  {
    for (a = 0; a < 4; a++)
    {
      numero[a]=' ';
    }
    a=0;
    while (tecla=getch())
    {
      if (tecla==13)/*tecla presionada ENTER*/
      {
        if (a>0)/*solo si presiono un numero anteriormente*/
        {
          numero[a]='\0';
          break;
        }
      }
      if (tecla>=48&&tecla<=57)/*tecla presionada 0-9*/
      {
        if (a<3)/*solo 3 numeros se pueden presionar*/
        {
          printf("%c", tecla);
          numero[a]=tecla;
          a++;
        }
      }
      if (tecla==8)/*tecla preciona, backpace, borrar*/
      {
        if (a>0)/*solo se puede borrar lo que el usuaio digito*/
        {
          printf("\b \b");
          a--;
        }
      }
    }
    numer_salida=atoi(numero);/*convierte la cadena de caracteres en numeros Int*/
    if (numer_salida<=100&&numer_salida>=0)/*si el numero no se encuentra entre 0 y 100*/
    {
      numero_val=1;/*cierra el ciclo*/
    }
    else
    {
      printf("\b \b\b \b\b \b");/*borra 3 espacios, los escritos por el usuario*/
    }
  }
  return numer_salida;/*retorna el numero escrito por el usuario*/
}

int GetIntC(void)/*funcion que valida un numero entero de hasta 4 cifras para el carnet*/
{
  int numer_salida=0, a=0;
  char tecla, numero[4];
  for (a = 0; a < 4; a++)
  {
    numero[a]=' ';
  }
  a=0;
  while (tecla=getch())
  {
    if (tecla==13)
    {
      if (a==3)
      {
        numero[a]='\0';
        break;
      }
    }
    if (tecla>=48&&tecla<=57)
    {
      if (a<3)
      {
        printf("%c", tecla);
        numero[a]=tecla;
        a++;
      }
    }
    if (tecla==8)
    {
      if (a>0)
      {
        printf("\b \b");
        a--;
      }
    }
  }
  numer_salida=atoi(numero);
  return numer_salida;
}

int Menu(int grupo)/*Funcion menu, imprime el menu, se mueve con W, S, retorna el valor de la opcion seleccionada*/
{
  int i=0, y_menu=0, opc_menu=0;
  char tecla;
  clrscr();
  textbackground(WHITE);
  clrscr();
  textcolor(BLUE);
  /*------------------------------Desing---------------------------------*/
  for (i = 4; i <= 77; i++)/*Parte superior*/
  {
    gotoxy(i, 5);
    cprintf("%c", 219);
  }
  gotoxy(3, 4); cprintf("%c", 219);gotoxy(78, 4); cprintf("%c", 219);
  gotoxy(2, 3); cprintf("%c", 219);gotoxy(79, 3); cprintf("%c", 219);
  gotoxy(1, 2); cprintf("%c", 219);gotoxy(80, 2); cprintf("%c", 219);
  gotoxy(1, 1); cprintf("%c", 219);gotoxy(80, 1); cprintf("%c", 219);
  gotoxy(30, 2);cprintf("Grupo      :      1M%d-CO",  grupo);
  /*--------------------------------------------------------------------*/
  gotoxy(37, 10);cprintf("[  Agregar ]");
  gotoxy(37, 12);cprintf("[  Buscar  ]");
  gotoxy(37, 14);cprintf("[Actualizar]");
  gotoxy(37, 16);cprintf("[ Eliminar ]");
  gotoxy(37, 18);cprintf("[  Mostrar ]");
  gotoxy(37, 20);cprintf("[ Regresar ]");
  gotoxy(37, 22);cprintf("[  Salir   ]");
  /*--------------------------------Desing-------------------------------*/
  y_menu=10;/*Determina donde se posiciona los cursores >> <<*/
  opc_menu=1;/*Determina el valor de la opccion seleccionada*/
  gotoxy(34, y_menu);cprintf(">>");/*imprime en la primera opcion*/
  gotoxy(50, y_menu);cprintf("<<");
  gotoxy(80, 25);/*posicion para que no se aprecie el cursor*/
  do
  {
    tecla = getch();
    if (tecla==87||tecla==119)/*w arriba*/
    {
      if (y_menu!=10)
      {
        gotoxy(34,y_menu);cprintf("  ");
        gotoxy(50, y_menu);cprintf("  ");
        y_menu-=2;
        gotoxy(80, 25);
        gotoxy(34,y_menu);cprintf(">>");
        gotoxy(50, y_menu);cprintf("<<");
        opc_menu-=1;
        gotoxy(80, 25);
      }
    }
    if (tecla==83||tecla==115)/*s abajo*/
    {
      if (y_menu!=22)
      {
        gotoxy(34,y_menu);cprintf("  ");
        gotoxy(50, y_menu);cprintf("  ");
        y_menu+=2;
        gotoxy(80, 25);
        gotoxy(34,y_menu);cprintf(">>");
        gotoxy(50, y_menu);cprintf("<<");
        opc_menu+=1;
        gotoxy(80, 25);
      }
    }
    if (tecla==13)
    {
      break;
    }
  } while(tecla!=87||tecla!=119||tecla!=83||tecla!=115||tecla!=13);
  return opc_menu;/*devuelve la opcion seleccionada*/
}

int Buscar(void)/*Funcion buscar, imprime el menu de busqueda y determina la forma de la busqueda*/
{
  int i=0, y_buscar=0, opc_buscar=0;
  char tecla;
  clrscr();
  textbackground(WHITE);
  clrscr();
  textcolor(BLUE);
  clrscr();
  y_buscar=14;
  opc_buscar=1;
  /*----------------------------Design-------------------------------*/
  gotoxy(25,5);cprintf("    ____                                ");
  gotoxy(25,6);cprintf("   / __ )__  ________________ ______    ");
  gotoxy(25,7);cprintf("  / __  / / / / ___/ ___/ __ `/ ___/    ");
  gotoxy(25,8);cprintf(" / /_/ / /_/ (__  ) /__/ /_/ / /        ");
  gotoxy(25,9);cprintf("/_____/\\__,_/____/\\___/\\__,_/_/      ");
  /*----------------------------------------------------------------*/
  for (i = 0; i < 4 ; i++)/*Laterales*/
  {
    gotoxy(29, i+13);printf("%c", 186);
    gotoxy(50, i+13);printf("%c", 186);
  }
  for (i = 0; i < 21 ; i++)/*Lados superiores*/
  {
    gotoxy(29+i, 13);printf("%c", 205);
    gotoxy(29+i, 17);printf("%c", 205);
  }
  gotoxy(29, 13);printf("%c", 201);/*esquina superiorizquierda*/
  gotoxy(29, 17);printf("%c", 200);/*esquina inferior izquierda*/
  gotoxy(50, 13);printf("%c", 187);/*esquina superior derecha*/
  gotoxy(50, 17);printf("%c", 188);/*esquina inferior derecha*/
  /*----------------------------------------------------------*/
  gotoxy(37, 14);printf("Nombre");
  gotoxy(37, 16);printf("Carnet");
  /*----------------------------Design-------------------------*/
  gotoxy(35,y_buscar);printf(">");
  gotoxy(44, y_buscar);printf("<");
  gotoxy(80, 25);

  do
  {
    tecla=getch();
    if (tecla==87||tecla==119)/*w arriba*/
    {
      if (y_buscar!=14)
      {
        gotoxy(35,y_buscar);printf(" ");
        gotoxy(44, y_buscar);printf(" ");
        y_buscar-=2;
        gotoxy(80, 25);
        gotoxy(35,y_buscar);printf(">");
        gotoxy(44, y_buscar);printf("<");
        opc_buscar-=1;
        gotoxy(80, 25);
      }
    }
    if (tecla==83||tecla==115)/*s abajo*/
    {
      if (y_buscar!=16)
      {
        gotoxy(35,y_buscar);printf(" ");
        gotoxy(44, y_buscar);printf(" ");
        y_buscar+=2;
        gotoxy(80, 25);
        gotoxy(35,y_buscar);printf(">");
        gotoxy(44, y_buscar);printf("<");
        opc_buscar+=1;
        gotoxy(80, 25);
      }
    }
    if (tecla==13)
    {
      break;
    }
  } while (tecla!=87||tecla!=119||tecla!=83||tecla!=115||tecla!=13);
  return opc_buscar;
}

void credenciales_inco()/*imprime por pantalla credenciales incor*/
{
  textbackground(RED);
  clrscr();
  textcolor(WHITE);
  clrscr();
  gotoxy(30,13);
  printf("Credenciales incorrectas");
  delay(1500);
}

void parpadeo()/*funcion que simula la cerrada de seguridad del sistema*/
{
  int i=0;
  clrscr();
  textbackground(RED);
  clrscr();
  textcolor(WHITE);
  for (i = 10; i > 0; i--)
  {
    gotoxy(27,13);
    printf("El sistema se cerrar%c en %02i s\n", 160, i);
    sleep(1);
    gotoxy(80,25);
  }
}

void presentacion()/*funcion que muestra la presentacion*/
{	int i;
	clrscr();
	textbackground(WHITE);
	clrscr();
	textcolor(BLUE);
	clrscr();
	/* Pilares Rectos */
	for(i=3;i<=11;i++)
	{
	gotoxy(26,i); delay(30); cprintf("%c%c%c%c",219,219,219,219);
	gotoxy(44,i); delay(30); cprintf("%c%c%c%c",219,219,219,219);
	}
  /* Bloque Horizontal Inferior */
   for(i=30;i<=37;i++)
   {
	gotoxy(i,10);  delay(30); cprintf("%c%c",219,219);
	gotoxy(i,11);  delay(30); cprintf("%c%c",219,219);
   }
    /* Pilar Vertical Superior */
   for(i=3;i<=8;i++)
   {
	gotoxy(32,i);  delay(30); cprintf("%c%c%c%c",219,219,219,219);
   }
    /* Bloque Horizontal Superior */
   for(i=36;i<=42;i++)
   {
	gotoxy(i,3);  delay(30); cprintf("%c%c",219,219);
	gotoxy(i,4);  delay(30); cprintf("%c%c",219,219);
   }
 /* Pilares Peque¤os */
  for(i=6;i<=11;i++)
  {
   gotoxy(38,i);  delay (30); cprintf("%c%c%c%c",219,219,219,219);
   gotoxy(50,i);  delay(30); cprintf("%c%c%c%c",219,219,219,219);
  }
  for(i=47;i<=48;i++)
   {
   gotoxy(i,10);  delay(20); cprintf("%c%c",219,219);
   gotoxy(i,11);  delay(20); cprintf("%c%c",219,219);
   }
   /* Tilde i */
   for(i=3;i<=4;i++)
   {
   gotoxy(50,i);  delay(30); cprintf("%c%c%c%c",219,219,219,219);
   }

   delay(40);
   gotoxy(23,13);textcolor(1);cprintf("UNIVERSIDAD NACIONAL DE INGENIERIA");
   gotoxy(22,14);textcolor(1);cprintf("Facultad de electronica y computacion");
   gotoxy(34,16);textcolor(1);cprintf("Grupo: 1M2-CO");
   gotoxy(12,17);textcolor(1);cprintf("integrantes:");
   gotoxy(25,17);textcolor(1);cprintf("Eng Cuadrado Weychen "); cprintf("2020-0316U");
   gotoxy(25,18);textcolor(1);cprintf("Membre%co Cuadra Nestor Alexander ",164); cprintf("2020-0504U");
   gotoxy(25,19);textcolor(1);cprintf("Valladares Membre%co Margarita Concepcion "); cprintf("2020-0455U");
   /*gotoxy(35,19);textcolor(1);cprintf("2020-0504U");*/
   gotoxy(14,21);textcolor(1);cprintf("Docente: Nelson Alejandro Barrios Gonzales");
   gotoxy(15,22);textcolor(1);cprintf("proyecto: Registro academico");/*Proyecto*/
   gotoxy(16,23);textcolor(1);cprintf("Carrera: Ingenieria en Computacion");
   gotoxy(58,1);textcolor(1);cprintf("fecha: 7/10/20");/*fecha de entrega*/
   gotoxy(58,25);textcolor(1);cprintf("Presione ENTER");
  getch();
}

int login_registro(void)
{
  int i=0, intentos=3;
  char user[40], pass[20], tecla;
  while (intentos>0)
  {
    textbackground(WHITE);
    clrscr();
    textcolor(BLUE);
    clrscr();
    /*------------------------------------Design---------------------------------------------*/
    /*Letras grandes*/
    gotoxy(13,2);printf("    ____             _      __                       ");
    gotoxy(13,3);printf("   / __ \\___  ____ _(_)____/ /__________             ");
    gotoxy(13,4);printf("  / /_/ / _ \\/ __ `/ / ___/ __/ ___/ __ \\            ");
    gotoxy(13,5);printf(" / _, _/  __/ /_/ / (__  ) /_/ /  / /_/ /            ");
    gotoxy(13,6);printf("/_/ |_|\\___/\\__, /_/____/\\__/_/   \\____/  _          ");
    gotoxy(13,7);printf("   /   | __/____/_ _____/ /__  ____ ___  (_)________ ");
    gotoxy(13,8);printf("  / /| |/ ___/ __ `/ __  / _ \\/ __ `__ \\/ / ___/ __ \\");
    gotoxy(13,9);printf(" / ___ / /__/ /_/ / /_/ /  __/ / / / / / / /__/ /_/ /");
    gotoxy(13,10);printf("/_/  |_\\___/\\__,_/\\__,_/\\___/_/ /_/ /_/_/\\___/\\____/ ");
    /*--------------------------------------------------------------------------------------*/
    /*Cuadro*/
    for (i = 0; i < 39; i++)
    {
      gotoxy(22+i, 15);/*Parte superior*/
      cprintf("%c", 205);
      gotoxy(22+i, 21);/*Parte inferior*/
      cprintf("%c", 205);
    }
    for (i = 0; i < 6; i++)
    {
      gotoxy(22, 15+i);
      printf("%c", 186);/*Parte izquierda*/
      gotoxy(60,15+i);
      printf("%c", 186);/*Parte derecha*/
    }
    gotoxy(22,15);
    printf("%c", 201);/*esquina superior izquierda*/
    gotoxy(60,15);
    printf("%c", 187);/*esquina superior derecha*/
    gotoxy(60,21);
    printf("%c", 188);/*esquina inferior derecha*/
    gotoxy(22,21);
    printf("%c", 200);/*esquina inferior izquierda*/
    /*-------------------------------------------------*/
    gotoxy(30, 17);
    printf("Usuario:       ");
    gotoxy(30,19);
    printf("Contrase%ca:   ", 164);
    /*-------------------------Design--------------------------*/

    strcpy(user, " ");
    strcpy(pass, " ");
    gotoxy(30, 23);
    printf("Intentos restantes: %d", intentos);
    gotoxy(45,17);
    i=0;
    /*validacion de usuario*/
    while (tecla=getch())
    {
      if (tecla==13)
      {
        if (i>0)
        {
          user[i]='\0';
          break;
        }
      }
      if (tecla==8)
      {
        if (i>0)
        {
          printf("\b \b");
          i--;
        }
      }
      if (tecla>=65&&tecla<=90||tecla>=97&&tecla<=122)/*tecla, letras mayusculas, letras minusculas*/
      {
        if (i<10)
        {
          printf("%c", tecla);
          user[i]=tecla;
          i++;
        }
      }
    }
    gotoxy(45,19);
    i=0;
    /*validacion de password*/
    while (tecla=getch())
    {
      if (tecla==13)
      {
        if (i>0)
        {
          pass[i]='\0';
          break;
        }
      }
      if (tecla==8)
      {
        if (i>0)
        {
          printf("\b \b");
          i--;
        }
      }
      if (tecla>=65&&tecla<=90||tecla>=97&&tecla<=122)
      {
        if (i<10)
        {
          printf("*");
          pass[i]=tecla;
          i++;
        }
      }
    }
    /*comprobando credenciales*/
    if (strcmp(user, "Nelson")==0)
    {
       if (strcmp(pass, "admin")==0)
       {
         break;
         /*Si el usuario y el password son correctos se sale del bucle*/
       }
       else
       {
         intentos--;
         /*Disminuye la cantidad de intentos en 1 y vuelve al bucle*/
       }
    }
    else
    {
      credenciales_inco();
      intentos--;
    }
  }
  return intentos;
}

int Grupo(void)/*imprime el menu de seleccon de grupo, retorna un valor correspondiente a cada grupo*/
{
	int i=0, y_grupo=0, opc_grupo=0;
	char tecla;
	clrscr();
	textbackground(WHITE);
	clrscr();
	textcolor(BLUE);
	clrscr();
	y_grupo=14;
	opc_grupo=1;
	/*----------------------------Design--------------------------*/
	gotoxy(25,5);printf("   ______                     ");
	gotoxy(25,6);printf("  / ____/______  ______  ____");
	gotoxy(25,7);printf(" / / __/ ___/ / / / __ \\/ __ \\");
	gotoxy(25,8);printf("/ /_/ / /  / /_/ / /_/ / /_/ /");
	gotoxy(25,9);printf("\\____/_/   \\__,_/ .___/\\____/");
	gotoxy(25,10);printf("               /_/            ");
	/*--------------------------------------------------------*/
	for (i = 0; i < 4 ; i++)/*Laterales*/
	{
		gotoxy(29, i+13);printf("%c", 186);
		gotoxy(50, i+13);printf("%c", 186);
	}
	for (i = 0; i < 21 ; i++)/*Lados superiores*/
	{
		gotoxy(29+i, 13);printf("%c", 205);
		gotoxy(29+i, 17);printf("%c", 205);
	}
	gotoxy(29, 13);printf("%c", 201);/*esquina superiorizquierda*/
	gotoxy(29, 17);printf("%c", 200);/*esquina inferior izquierda*/
	gotoxy(50, 13);printf("%c", 187);/*esquina superior derecha*/
	gotoxy(50, 17);printf("%c", 188);/*esquina inferior derecha*/
	/*--------------------------Design----------------------------*/
	gotoxy(37, 14);printf("1M1-CO");
	gotoxy(37, 16);printf("1M2-CO");
	gotoxy(35,y_grupo);printf(">");
	gotoxy(44, y_grupo);printf("<");
	gotoxy(80, 25);
	do
  {
    tecla=getch();
		if (tecla==87||tecla==119)/*w arriba*/
		{
			if (y_grupo!=14)
			{
				gotoxy(35,y_grupo);printf(" ");
				gotoxy(44, y_grupo);printf(" ");
				y_grupo-=2;
				gotoxy(80, 25);
				gotoxy(35,y_grupo);printf(">");
				gotoxy(44, y_grupo);printf("<");
				opc_grupo-=1;
				gotoxy(80, 25);
			}
		}
		if (tecla==83||tecla==115)/*s abajo*/
		{
			if (y_grupo!=16)
			{
				gotoxy(35,y_grupo);printf(" ");
				gotoxy(44, y_grupo);printf(" ");
				y_grupo+=2;
				gotoxy(80, 25);
				gotoxy(35,y_grupo);printf(">");
				gotoxy(44, y_grupo);printf("<");
				opc_grupo+=1;
				gotoxy(80, 25);
			 }
		}
		if (tecla==13)
		{
			break;
		}
	} while(tecla!=87||tecla!=119||tecla!=83||tecla!=115||tecla!=13);
  return opc_grupo;
	}

int Semestre(void)/*Imprime el menu de seleccion de semestre para la opcion agregar*/
{
  int i = 0, y_buscar = 0, opc_semestre = 0;
  char tecla;
  clrscr();
  textbackground(WHITE);
  clrscr();
  textcolor(BLUE);
  clrscr();
  y_buscar=14;
  opc_semestre=1;
  /*---------------------------------Design------------------------------*/
  gotoxy(20,5);cprintf("   _____                          __          ");
  gotoxy(20,6);cprintf("  / ___/___  ____ ___  ___  _____/ /_________ ");
  gotoxy(20,7);cprintf("  \\__ \\/ _ \\/ __ `__ \\/ _ \\/ ___/ __/ ___/ _ \\");
  gotoxy(20,8);cprintf(" ___/ /  __/ / / / / /  __(__  ) /_/ /  /  __/");
  gotoxy(20,9);cprintf("/____/\\___/_/ /_/ /_/\\___/____/\\__/_/   \\___/ ");
  /*----------------------------------------------------------------*/
  for (i = 0; i < 4 ; i++)/*Laterales*/
  {
    gotoxy(29, i+13);printf("%c", 186);
    gotoxy(50, i+13);printf("%c", 186);
  }
  for (i = 0; i < 21 ; i++)/*Lados superiores*/
  {
     gotoxy(29+i, 13);printf("%c", 205);
     gotoxy(29+i, 17);printf("%c", 205);
  }
  gotoxy(29, 13);printf("%c", 201);/*esquina superiorizquierda*/
  gotoxy(29, 17);printf("%c", 200);/*esquina inferior izquierda*/
  gotoxy(50, 13);printf("%c", 187);/*esquina superior derecha*/
  gotoxy(50, 17);printf("%c", 188);/*esquina inferior derecha*/
  /*----------------------------Design------------------------------*/
  gotoxy(37, 14);printf("   I  ");
  gotoxy(37, 16);printf("   II ");
  gotoxy(35,y_buscar);printf(">");
  gotoxy(44, y_buscar);printf("<");
  gotoxy(80, 25);

  do
  {
    tecla=getch();
    if (tecla==87||tecla==119)/*w arriba*/
    {
      if (y_buscar!=14)
      {
        gotoxy(35,y_buscar);printf(" ");
        gotoxy(44, y_buscar);printf(" ");
        y_buscar-=2;
        gotoxy(80, 25);
        gotoxy(35,y_buscar);printf(">");
        gotoxy(44, y_buscar);printf("<");
        opc_semestre-=1;
        gotoxy(80, 25);
      }
    }
    if (tecla==83||tecla==115)/*s abajo*/
    {
      if (y_buscar!=16)
      {
        gotoxy(35,y_buscar);printf(" ");
        gotoxy(44, y_buscar);printf(" ");
        y_buscar+=2;
        gotoxy(80, 25);
        gotoxy(35,y_buscar);printf(">");
        gotoxy(44, y_buscar);printf("<");
        opc_semestre+=1;
        gotoxy(80, 25);
       }
    }
    if (tecla==13)
    {
      break;
    }
  } while (tecla!=87||tecla!=119||tecla!=83||tecla!=115||tecla!=13);
  return opc_semestre;
}

void agraegarNombre()/*Design para la parte de agregar nombre en la opcion agregar*/
{
 int i = 0;
 clrscr();
 textbackground(WHITE);
 clrscr();
 textcolor(BLUE);
 for (i = 4; i <= 77; i++)/*Parte inferior*/
 {
   gotoxy(i, 21); cprintf("%c", 219);
 }
 gotoxy(3, 21); cprintf("%c", 219);gotoxy(78, 21); cprintf("%c", 219);
 gotoxy(2, 22); cprintf("%c", 219);gotoxy(79, 22); cprintf("%c", 219);
 gotoxy(1, 23); cprintf("%c", 219);gotoxy(80, 23); cprintf("%c", 219);
}

void cuadro()/*imprime un cuadro*/
{
  int i = 0;
  clrscr();
  textbackground(WHITE);
  clrscr();
  textcolor(BLUE);
  for (i = 0; i < 50; i++)
  {
    gotoxy(15+i, 8);cprintf("%c",205);
    gotoxy(15+i, 20);cprintf("%c",205);
  }
  for (i = 0; i < 12; i++)
  {
    gotoxy(15, 8+i);cprintf("%c",186);
    gotoxy(65, 8+i);cprintf("%c",186);
  }
  gotoxy(15, 8);cprintf("%c", 201);/*esquina superior izquierda*/
  gotoxy(65, 8);cprintf("%c", 187);/*esquina superior derecha*/
  gotoxy(15, 20);cprintf("%c", 200);/*esquina inferior izquierda*/
  gotoxy(65, 20);cprintf("%c", 188);/*esquina inferiror derecha*/
}

void estudiantes()/*muestra una pantalla en rojo con el mensaje "no se pueden anadir mas estudiantes"*/
{
  clrscr();
  textbackground(RED);
  clrscr();
  textcolor(WHITE);
  gotoxy(25,13);cprintf("No puede a%cadir a m%cs estudiantes.\n", 164, 160);
  gotoxy(80,25);
  sleep(2);
}

void MostrarISemestre()/*cuadricula para mostrar el primer semestre*/
{
	int i = 0;
	clrscr();
	textbackground(WHITE);
	clrscr();
	textcolor(BLACK);
	clrscr();

	for (i = 0; i <=78 ; i++)/*fila horizonatal*/
	{
    gotoxy(4,4);cprintf("%c%c",196,196);
    gotoxy(i,4); cprintf("%c%c%c",196,196,196);/* code */
	}
	for(i=49;i<73;i++)/*extra*/
	{
	   gotoxy(i,2); cprintf("%c%c%c",196,196,196);
	}
	for(i=1;i<26;i++)/*Columnas principales*/
	{
	   gotoxy(37,i);cprintf("%c",179);
		 gotoxy(48,i);cprintf("%c",179);
			/*gotoxy(66,i);cprintf("%c",179);*/
	    gotoxy(74,i);cprintf("%c",179);
	 }
	 for(i=2;i<26;i++)/*columnas secundarias */
	 {
	    gotoxy(54,2);cprintf("%c",194);/*No tocar o la cagas*/
		  gotoxy(54,i);cprintf("%c",179);
		  gotoxy(61,2);cprintf("%c",194);
		  gotoxy(61,i);cprintf("%c",179);
		  gotoxy(68,2);cprintf("%c",194);
		  gotoxy(68,i);cprintf("%c",179);
	 }
	 gotoxy(8,2); cprintf("Nombre y Apellido");
	 gotoxy(40,2); cprintf("Carnet");
	 /*gotoxy(38,3);cprintf("2020_0405U");*/
	 gotoxy(56,1);cprintf("semestre I");
	 gotoxy(50,3);cprintf("IIC");
   gotoxy(56,3);cprintf("GA/D");
   gotoxy(63,3);cprintf("FILO");
   gotoxy(70,3);cprintf("ING");
   /*gotoxy(76,2); cprintf("PROM");*/
	 /*gotoxy(68,3);cprintf("100");
	 gotoxy(68,8);cprintf("100");
	 gotoxy(68,1);cprintf("Notas");
	/*gotoxy(73,4);cprintf("100");*/
}

void ebuscar()/*pantalla de error en buscar*/
{
  clrscr();
  textbackground(RED);
  clrscr();
  textcolor(WHITE);
  gotoxy(30,13);cprintf("Estudiante no encontrado.\n");
  gotoxy(80, 15);
  sleep(2);
}

int Actualizar_estudiante(void)/*Funcion actualizar, imprime las opciones de acutualizacion y determina la forma de la busqueda*/
{
  int i = 0, y_actualizar = 0, opc_actualizar = 0;
  char tecla;
  clrscr();
  textbackground(WHITE);
  clrscr();
  textcolor(BLUE);
  clrscr();
  y_actualizar=14;
  opc_actualizar=1;
  /*--------------------------Design-------------------------------*/
  gotoxy(20,5);cprintf("    ___        __              ___                 ");
  gotoxy(20,6);cprintf("   /   | _____/ /___  ______ _/ (_)___  ____ ______");
  gotoxy(20,7);cprintf("  / /| |/ ___/ __/ / / / __ `/ / /_  / / __ `/ ___/");
  gotoxy(20,8);cprintf(" / ___ / /__/ /_/ /_/ / /_/ / / / / /_/ /_/ / /    ");
  gotoxy(20,9);cprintf("/_/  |_\\___/\\__/\\__,_/\\__,_/_/_/ /___/\\__,_/_/     ");
  /*----------------------------------------------------------------*/
  for (i = 0; i < 4 ; i++)/*Laterales*/
  {
    gotoxy(29, i+13);printf("%c", 186);
    gotoxy(50, i+13);printf("%c", 186);
  }
  for (i = 0; i < 21 ; i++)/*Lados superiores*/
  {
     gotoxy(29+i, 13);printf("%c", 205);
     gotoxy(29+i, 17);printf("%c", 205);
  }
  gotoxy(29, 13);printf("%c", 201);/*esquina superiorizquierda*/
  gotoxy(29, 17);printf("%c", 200);/*esquina inferior izquierda*/
  gotoxy(50, 13);printf("%c", 187);/*esquina superior derecha*/
  gotoxy(50, 17);printf("%c", 188);/*esquina inferior derecha*/
  /*--------------------------Design--------------------------*/
  gotoxy(37, 14);printf("Nombre");
  gotoxy(37, 15);printf("Sem I");
  gotoxy(37, 16);printf("Sem II");
  gotoxy(35,y_actualizar);printf(">");
  gotoxy(44, y_actualizar);printf("<");
  gotoxy(80, 25);

  do
  {
    tecla=getch();
    if (tecla==87||tecla==119)/*w arriba*/
    {
      if (y_actualizar!=14)
      {
        gotoxy(35,y_actualizar);printf(" ");
        gotoxy(44, y_actualizar);printf(" ");
        y_actualizar-=1;
        gotoxy(80, 25);
        gotoxy(35,y_actualizar);printf(">");
        gotoxy(44, y_actualizar);printf("<");
        opc_actualizar-=1;
        gotoxy(80, 25);
      }
    }
    if (tecla==83||tecla==115)/*s abajo*/
    {
      if (y_actualizar!=16)
      {
        gotoxy(35,y_actualizar);printf(" ");
        gotoxy(44, y_actualizar);printf(" ");
        y_actualizar+=1;
        gotoxy(80, 25);
        gotoxy(35,y_actualizar);printf(">");
        gotoxy(44, y_actualizar);printf("<");
        opc_actualizar+=1;
        gotoxy(80, 25);
       }
    }
    if (tecla==13)
    {
      break;
    }
  } while (tecla!=87||tecla!=119||tecla!=83||tecla!=115||tecla!=13);

  return opc_actualizar;
}

int actualizar_semestreI(void)/*Design para actualizar el primer semestre*/
{
  int i=0, y_actualizar=0, opc_actualizar=0;
  char tecla;
  y_actualizar=12;
  opc_actualizar=1;
  clrscr();
  textbackground(WHITE);
  clrscr();
  textcolor(BLUE);
  gotoxy(22, 3);cprintf("Seleccione la clase que desea actulizar\n");
  for (i = 0; i < 50; i++)
  {
    gotoxy(15+i, 8);cprintf("%c",205);
    gotoxy(15+i, 20);cprintf("%c",205);
  }
  for (i = 0; i < 12; i++)
  {
    gotoxy(15, 8+i);cprintf("%c",186);
    gotoxy(65, 8+i);cprintf("%c",186);
  }
  gotoxy(15, 8);cprintf("%c", 201);/*esquina superior izquierda*/
  gotoxy(65, 8);cprintf("%c", 187);/*esquina superior derecha*/
  gotoxy(15, 20);cprintf("%c", 200);/*esquina inferior izquierda*/
  gotoxy(65, 20);cprintf("%c", 188);/*esquina inferiror derecha*/
  /*-------------------------------------------------------------*/
  gotoxy(19,12);printf("Introduccion a la ing en computacion\n");
  gotoxy(19,14);printf("Geometria analitica\n");
  gotoxy(19,16);printf("Filosofia\n");
  gotoxy(19,18);printf("Ingles I\n");
  gotoxy(17, y_actualizar);printf(">");
  gotoxy(80, 25);

  do
  {
    tecla=getch();
    if (tecla==87||tecla==119)/*w arriba*/
    {
      if (y_actualizar!=12)
      {
        gotoxy(17,y_actualizar);printf(" ");
        y_actualizar-=2;
        gotoxy(80, 25);
        gotoxy(17,y_actualizar);printf(">");
        opc_actualizar-=1;
        gotoxy(80, 25);
      }
    }
    if (tecla==83||tecla==115)/*s abajo*/
    {
      if (y_actualizar!=18)
      {
        gotoxy(17,y_actualizar);printf(" ");
        y_actualizar+=2;
        gotoxy(80, 25);
        gotoxy(17,y_actualizar);printf(">");
        opc_actualizar+=1;
        gotoxy(80, 25);
      }
    }
    if (tecla==13)
    {
      break;
    }
  } while (tecla!=87||tecla!=119||tecla!=83||tecla!=115||tecla!=13);
  return opc_actualizar;
}

void notaActualizada()
{
  clrscr();
  textbackground(GREEN);
  clrscr();
  textcolor(WHITE);
  gotoxy(35, 12);cprintf("Nota actualizada");
  gotoxy(80, 15);
  sleep(1);
}

int posicionActualizarSemestreI(int a)/*Devuelve la posicion en y para agragar las notas en el semestre I*/
{
  int b = 0;
  if (a==1)
  {
    b = 12;
  }
  else if (a==2)
  {
    b = 14;
  }
  else if (a==3)
  {
    b = 16;
  }
  else
  {
    b = 18;
  }
  return b;
}

int actualizar_semestreII(void)
{
  int i=0, y_actualizar=0, opc_actualizar=0;
  char tecla;
  y_actualizar=10;
  opc_actualizar=1;
  clrscr();
  textbackground(WHITE);
  clrscr();
  textcolor(BLUE);
  gotoxy(22, 3);cprintf("Seleccione la clase que desea actulizar\n");
  for (i = 0; i < 50; i++)
  {
    gotoxy(15+i, 8);cprintf("%c",205);
    gotoxy(15+i, 20);cprintf("%c",205);
  }
  for (i = 0; i < 12; i++)
  {
    gotoxy(15, 8+i);cprintf("%c",186);
    gotoxy(65, 8+i);cprintf("%c",186);
  }
  gotoxy(15, 8);cprintf("%c", 201);/*esquina superior izquierda*/
  gotoxy(65, 8);cprintf("%c", 187);/*esquina superior derecha*/
  gotoxy(15, 20);cprintf("%c", 200);/*esquina inferior izquierda*/
  gotoxy(65, 20);cprintf("%c", 188);/*esquina inferiror derecha*/
  /*-------------------------------------------------------------*/
  gotoxy(19,10);printf("Lenguaje de programacion\n");
  gotoxy(19,12);printf("Conceptos de Lenguaje\n");
  gotoxy(19,14);printf("Matematica I\n");
  gotoxy(19,16);printf("Ingles II\n");
  gotoxy(19,18);printf("Redaccion tecnica\n");
  gotoxy(17, y_actualizar);printf(">");
  gotoxy(80, 25);

  do
  {
    tecla=getch();
    if (tecla==87||tecla==119)/*w arriba*/
    {
      if (y_actualizar!=10)
      {
        gotoxy(17,y_actualizar);printf(" ");
        y_actualizar-=2;
        gotoxy(80, 25);
        gotoxy(17,y_actualizar);printf(">");
        opc_actualizar-=1;
        gotoxy(80, 25);
      }
    }
    if (tecla==83||tecla==115)/*s abajo*/
    {
      if (y_actualizar!=18)
      {
        gotoxy(17,y_actualizar);printf(" ");
        y_actualizar+=2;
        gotoxy(80, 25);
        gotoxy(17,y_actualizar);printf(">");
        opc_actualizar+=1;
        gotoxy(80, 25);
      }
    }
    if (tecla==13)
    {
      break;
    }
  } while (tecla!=87||tecla!=119||tecla!=83||tecla!=115||tecla!=13);

  return opc_actualizar;
}

void MostrarIISemestre()
{
  int i;
  clrscr();
  textbackground(WHITE);
  clrscr();
  textcolor(BLACK);
  clrscr();

  for (i = 0; i < 78; i++)/*fila horizonatal*/
  {
    gotoxy(4,4);cprintf("%c%c",196,196);
    gotoxy(i,4); cprintf("%c%c%c",196,196,196);/* code */
  }
  for(i = 44;i < 73; i++)/*extra*/
  {
  	gotoxy(i,2); cprintf("%c%c%c",196,196,196);
  }
  for(i=1;i<26;i++)/*Columnas principales*/
  {
    gotoxy(33,i);cprintf("%c",179);
    gotoxy(44,i);cprintf("%c",179);
  	 /*gotoxy(66,i);cprintf("%c",179);*/
  	gotoxy(74,i);cprintf("%c",179);
  }
  for(i=2;i<26;i++)/*columnas secundarias */
  {
    gotoxy(56,2);cprintf("%c",194); /*pr*/
  	gotoxy(56,i);cprintf("%c",179);
  	gotoxy(62,2);cprintf("%c",194);  /*Sg*/
  	gotoxy(62,i);cprintf("%c",179);
  	gotoxy(68,2);cprintf("%c",194);
  	gotoxy(68,i);cprintf("%c",179);/*4ta*/
  	gotoxy(50,2);cprintf("%c",194);
    gotoxy(50,i);cprintf("%c",179);/*tercera columna */
  }
  gotoxy(9,2); cprintf("Nombre y Apellido");
  gotoxy(36,2); cprintf("Carnet");
  /*gotoxy(34,3);cprintf("2020_0405U");*/
  gotoxy(55,1);cprintf("semestre II");
  gotoxy(46,3);cprintf("LDP");
  gotoxy(52,3);cprintf("CDL");
  gotoxy(58,3);cprintf("MAT");
  gotoxy(64,3);cprintf("ING");
  gotoxy(70,3);cprintf("RED");
  /*gotoxy(76,2); cprintf("PROM");*/
}

int posicionActualizarSemestreII(int a)/*Devuelve la posicion en y para agragar las notas en el semestre I*/
{
  int b = 0;
  if (a==1)
  {
    b = 10;
  }
  else if (a==2)
  {
    b = 12;
  }
  else if (a==3)
  {
    b = 14;
  }
  else if (a==4)
  {
    b = 16;
  }
  else
  {
    b = 18;
  }
  return b;
}

void nota_insuficiente(void)
{
  clrscr();
  textbackground(RED);
  clrscr();
  textcolor(WHITE);
  clrscr();
  gotoxy(25, 13);cprintf("Usted no puede llevar esta clase");
  gotoxy(80, 15);
  sleep(1);
}

void estudianteEliminado()
{
  clrscr();
  textbackground(GREEN);
  clrscr();
  textcolor(WHITE);
  gotoxy(29, 12);cprintf("Estudiante eliminado");
  gotoxy(80, 15);
  sleep(1);
}

int seleccionEstudiante(int nu)
{
  char tecla;
  int y_seleccion = 0, opc_seleccion = 0, contador = 0;
  y_seleccion = 5;
  opc_seleccion = 0;
  gotoxy(3, 5); cprintf(">");
  gotoxy(80,25);
  do
  {
    tecla=getch();
    if (tecla==87||tecla==119)/*w arriba*/
    {
      if (y_seleccion != 5)
      {
        gotoxy(3, y_seleccion); cprintf(" ");
        y_seleccion-=2;
        gotoxy(3, y_seleccion); cprintf(">");
        opc_seleccion-=1;
        contador--;
        gotoxy(80, 25);
      }
    }
    if (tecla==83||tecla==115)/*w arriba*/
    {
      if (contador < nu - 1)
      {
        gotoxy(3, y_seleccion); cprintf(" ");
        y_seleccion+=2;
        gotoxy(3, y_seleccion); cprintf(">");
        opc_seleccion+=1;
        contador++;
        gotoxy(80, 25);
      }
    }
    if (tecla==13)
    {
      break;
    }
  } while(tecla!=87||tecla!=119||tecla!=83||tecla!=115||tecla!=13);
  return opc_seleccion;
}

void marco(void)
{
  int i;
	clrscr();
	textbackground(WHITE);
	clrscr();
	textcolor(BLUE);
	clrscr();

	 for (i = 0; i <77; i++)/*marco en mallas top*/
	 {
	 	gotoxy(i,1); delay(15); cprintf("%c%c%c%c%c",178,178,178,178,178);
	 }

		 for(i=1; i<25; i++)/*pilar izquierdo*/
		 {

			gotoxy(79,i); delay(15); cprintf("%c%c",178,178);
		 }

	  	     for(i=77; i>0; i--)/*marco bot*/
			 {

				gotoxy(i,25); delay(15); cprintf("%c%c%c",178,178,178);

			 }

			 for(i=25; i>0; i--)/*pilar top*/
			 {
			 	gotoxy(1,i); delay(15); cprintf("%c%c",178,178);
			 }

			 /*lineas marco*/

			   for (i = 4; i <73; i++)/*marco en lineas top*/
				 {
				 	gotoxy(4,2); cprintf("%c",201);
				 	gotoxy(i,2); cprintf("%c%c%c%c%c",205,205,205,205,205);
				 	gotoxy(77,2); cprintf("%c",187);
				 }
				  for (i = 3 ; i <24 ; i++)/*pilar derecho*/
				  {
				  	gotoxy(4,i); cprintf("%c",186);
				  }

					 for(i=3; i<24; i++)/*pilar izquierdo lineal*/
					 {
						gotoxy(77,i); cprintf("%c",186);

						gotoxy(77,24); cprintf("%c",188);
					 }

				  	     for(i=5; i<73; i++)/*lineal marco bot*/
						 {
							gotoxy(i,24); cprintf("%c%c%c%c%c",205,205,205,205,205);
							gotoxy(4,24); cprintf("%c",200);
						 }

    /* Pilares Rectos */
	for(i=5;i<=13;i++)
	{
	gotoxy(26,i); delay(30); cprintf("%c%c%c%c",219,219,219,219);
	gotoxy(44,i); delay(30); cprintf("%c%c%c%c",219,219,219,219);
	}
  /* Bloque Horizontal Inferior */
   for(i=30;i<=37;i++)
   {
	gotoxy(i,12);  delay(30); cprintf("%c%c",219,219);
	gotoxy(i,13);  delay(30); cprintf("%c%c",219,219);
   }
    /* Pilar Vertical Superior */
   for(i=5;i<=10;i++)
   {
	gotoxy(32,i);  delay(30); cprintf("%c%c%c%c",219,219,219,219);
   }
    /* Bloque Horizontal Superior */
   for(i=36;i<=42;i++)
   {
	gotoxy(i,5);  delay(30); cprintf("%c%c",219,219);
	gotoxy(i,6);  delay(30); cprintf("%c%c",219,219);
   }
 /* Pilares Peque¤os */
  for(i=8;i<=13;i++)
  {
   gotoxy(38,i);  delay (30); cprintf("%c%c%c%c",219,219,219,219);
   gotoxy(50,i);  delay(30); cprintf("%c%c%c%c",219,219,219,219);
  }
  for(i=47;i<=48;i++)
   {
   gotoxy(i,12);  delay(20); cprintf("%c%c",219,219);
   gotoxy(i,13);  delay(20); cprintf("%c%c",219,219);
   }


   /* Tilde i */
   for(i=5;i<=6;i++)
   {
   gotoxy(50,i);  delay(30); textcolor(1+BLINK); cprintf("%c%c%c%c",219,219,219,219);

   }

    textcolor(BLACK);
   /* gotoxy(39,18); delay(20);cprintf("%c",201); cprintf("%c",205); cprintf("%c",205); cprintf("%c",187);
    gotoxy(39,19); delay(20);cprintf("%c",200);cprintf("%c",205);cprintf("%c",205);cprintf("%c",188);*/

	gotoxy(37,16); delay(50); cprintf("S"); gotoxy(38,16); delay(50); cprintf("a");gotoxy(39,16); delay(50); cprintf("l");
	gotoxy(40,16); delay(50); cprintf("i");gotoxy(41,16); delay(50); cprintf("e");gotoxy(42,16); delay(50); cprintf("n");
	gotoxy(43,16); delay(50); cprintf("d");gotoxy(44,16); delay(50); cprintf("o");

    gotoxy(45,16); sleep(1); cprintf("."), gotoxy(46,16); sleep(1); cprintf("."); gotoxy(47,16); sleep(1); cprintf(".");
}

void ful_intentos (void)
{
  clrscr();
  textbackground(RED);
  clrscr();
  textcolor(WHITE);
  clrscr();
  gotoxy(31,12);cprintf(" Numero de intentos superado");
  gotoxy(30,13);cprintf("No se puede borrar un usuario");
  gotoxy(80,25);
  sleep(2);
}
