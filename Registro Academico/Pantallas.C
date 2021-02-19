#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "INTRO.H"
#include "REGISTER.H"

void main (void)
{
  char nombres_1m2[10][45], primerSemestre[4][40]={"Introduccion a la ing en computacion", "Geometria analitica", "Filosofia", "Ingles I"};
  char segundoSemestre[5][50]={"Lenguajes de programacion", "Conceptos de lenguaje", "Matematica I", "Ingles II", "Redaccion tecnica"};
  char tecla, buscar_nombre[45];
  int opc_menu=0, opc_buscar=0, nu_estudiante=3, carnet_1m2[10], i=0, j=0, notas_1m2[10][9], nuAux_estudiante=0, selec_semestre=0;
  int buscar_carnet=0, auxBuscar=0, intentos=0, actualizar_estudiante=0, opc_actualizar=0;
  int actulizar_Isemestre=0, actualizar_IIsemestre=0, aux_notasborrar=0, paso2Agregar=0, paso3Agregar=0;
  int auxerror = 0, auxBorrar = 0;
  int grupo_seleccion = 0;
  /*-----------------------------------1M1---------------------------*/
  int nu_estudiante1=3,notas_1m1[10][9], carnet_1m1[10];
  char nombres_1m1[10][45];
  /*int promedioSemestreI[10], auxProm1=0;*/
  clrscr();
  /*Limpiando variables*/
  /*---------------------------------------------------------------------------*/
  for (i = 0; i < 10; i++)
  {
   for (j = 0; j < 9; j++)
   {
    notas_1m2[i][j] = -1;/*arreglo donde destaran las 9 notas de los 10 estudiantes del grupo 1m2*/
    notas_1m1[i][j] = -1;
   }
  }
  for (i = 0; i < 9 ; i++)
  {
      carnet_1m2[i] = 0;
      carnet_1m1[i] = 0;
  }
  /*---------------------------------------------------------------------------*/
  /*Declaracion de los primeros ususarios en el grupo 1m2*/
  /*---------------------------------------------------------------*/
  strcpy(nombres_1m2[0],"MARGARITA VALLADARES"); carnet_1m2[0]=455;/*logica de los carnet, solo usar los ultimos 3 numeros*/
  strcpy(nombres_1m2[1],"NESTOR ALEXANDER");carnet_1m2[1]=504;/*para usuarios nuevos estos tes numeros son aleatorios*/
  strcpy(nombres_1m2[2],"WEYCHEN ENG");carnet_1m2[2]=316; /*del 100 al 999*/
  strcpy(nombres_1m1[0],"Kurtcito Racoon"); carnet_1m1[0]=375;
  strcpy(nombres_1m1[1],"Kirsten Allison");carnet_1m1[1]=289;
  strcpy(nombres_1m1[2],"Josue Danilo");carnet_1m1[2]=255;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 9; j++)
    {
      notas_1m2[i][j] = 100;
      notas_1m1[i][j] = 100;
    }
  }
  /*---------------------------------------------------------------*/
  /*---------------------------------------------------------------*/
  logo();
  barra_de_carga();
  presentacion();
  intentos=login_registro();/*Dependiendo de la cantidad de intentos restantes entrara o no al menu principal*/
  if (intentos>0)
  {
    grupo_seleccion=Grupo();
    while (opc_menu!=7)
    {
     clrscr();
     opc_menu=Menu(grupo_seleccion);/*Funcion menu, impreme el menu y determina el switch*/
     clrscr();
     fflush(stdin);
     switch (opc_menu)
     {
      case 1:
             /*Agregar*/
             if (grupo_seleccion==1)
             {
               if (nu_estudiante1 < 10)/*controla la entrada de estudiantes, solo se puede agregar un maximo de 10*/
               {
                 fflush(stdin);
                 agraegarNombre();
                 gotoxy(25,10);printf("Ingrese el nombre del estudiante:");
                 gotoxy(35,12);gets(nombres_1m1[nu_estudiante1]);/*Guarda los nombres de los estudiantes del grupo 1m2, en orden del numero de estudiantes, nu_estudiante*/
                 strupr(nombres_1m1[nu_estudiante1]);
                 srand (time(NULL));/*hace que la funcion random dependa de la hora*/
                 fflush(stdin);/*Limpia el buffer*/
                 carnet_1m1[nu_estudiante1]=(rand() % 899)+100 ; /*Saca un numero random entre 100 y 999, generar el carne*/
                 clrscr();
                 selec_semestre=Semestre();
                 clrscr();
                 if (selec_semestre==1)
                 {
                   cuadro();
                   gotoxy(22, 3);cprintf("Ingrese las notas del primer semestre\n");
                   paso2Agregar=0;
                   fflush(stdin);
                   for (i = 0; i < 4; i++)
                   {
                     gotoxy(16, 10+paso2Agregar);cprintf("%s: ", primerSemestre[i]);
                     gotoxy(60, 10+paso2Agregar);notas_1m1[nu_estudiante1][i]=GetIntR();
                     paso2Agregar+=2;
                   }
                 }
                 else
                 {
                   clrscr();
                   cuadro();/*imprime el cuadro para el ingreso de las notas*/
                   gotoxy(22,3);cprintf("Ingrese las notas del primer semestre\n");
                   paso2Agregar=0;/*determinar salto de linea*/
                   fflush(stdin);
                   for (i = 0; i < 4; i++)
                   {
                     gotoxy(16, 10+paso2Agregar);cprintf("%s: ", primerSemestre[i]);
                     gotoxy(60, 10+paso2Agregar);notas_1m1[nu_estudiante1][i]=GetIntR();
                     paso2Agregar+=2;
                   }
                   clrscr();
                   cuadro();
                   gotoxy(22,3);cprintf("Ingrese las notas del segundo semestre.\n");
                   gotoxy(10, 5);cprintf("Oprima \"s\" si va a llevar la clase y \"n\" si no la va a llevar.");
                   gotoxy(16, 9);cprintf("Lenguajes de programacion: ");
                   gotoxy(16, 11);cprintf("Conceptos de lenguaje: ");
                   gotoxy(16, 13);cprintf("Matematica I: ");
                   gotoxy(16, 15);cprintf("Ingles II: ");
                   gotoxy(16, 17);cprintf("Redaccion tecnica: ");
                   paso2Agregar=0;
                   fflush(stdin);
                   for (i = 0; i < 5; i++)
                   {
                     gotoxy(58, 9 + paso2Agregar);cprintf("[s\\n]");
                     gotoxy(80,25);
                     while (tecla=getch())
                     {
                       if (tecla==83||tecla==115)
                       {
                         gotoxy(58, 9+paso2Agregar);printf("     ");
                         gotoxy(59, 9+paso2Agregar);
                         if (i==0)
                         {
                           if (notas_1m1[nu_estudiante1][i]<60)
                           {
                             printf("n\\a");
                             notas_1m1[nu_estudiante1][i+4] = -1;
                             break;
                           }
                           else
                           {
                             notas_1m1[nu_estudiante1][i+4]=GetIntR();
                             break;
                           }
                         }
                         if (i==3)
                         {
                           if (notas_1m1[nu_estudiante1][i]<60)
                           {
                             printf("n\\a");
                             notas_1m1[nu_estudiante1][i+4] = -1;
                             break;
                           }
                           else
                           {
                             notas_1m1[nu_estudiante1][i+4]=GetIntR();
                             break;
                           }
                         }
                         notas_1m1[nu_estudiante1][i+4]=GetIntR();
                         break;
                       }
                       if (tecla==78||tecla==110)
                       {
                         gotoxy(58, 9+paso2Agregar);printf("     ");
                         gotoxy(59, 9+paso2Agregar);printf("n\\a");
                         notas_1m1[nu_estudiante1][i+4]=-1;
                         break;
                       }
                     }
                     paso2Agregar+=2;
                   }
                 }
                 nu_estudiante1++;
                 fflush(stdin);
               }
               else
               {
                 estudiantes();
               }
             }
             else
             {
               if (nu_estudiante < 10)/*controla la entrada de estudiantes, solo se puede agregar un maximo de 10*/
               {
                 agraegarNombre();
                 gotoxy(25,10);printf("Ingrese el nombre del estudiante:");
                 gotoxy(35,12);gets(nombres_1m2[nu_estudiante]);/*Guarda los nombres de los estudiantes del grupo 1m2, en orden del numero de estudiantes, nu_estudiante*/
                 strupr(nombres_1m2[nu_estudiante]);
                 srand (time(NULL));/*hace que la funcion random dependa de la hora*/
                 fflush(stdin);/*Limpia el buffer*/
                 carnet_1m2[nu_estudiante]=(rand() % 899)+100 ; /*Saca un numero random entre 100 y 999, generar el carne*/
                 clrscr();
                 selec_semestre=Semestre();
                 clrscr();
                 if (selec_semestre==1)
                 {
                   cuadro();
                   gotoxy(22, 3);cprintf("Ingrese las notas del primer semestre\n");
                   paso2Agregar=0;
                   fflush(stdin);
                   for (i = 0; i < 4; i++)
                   {
                     gotoxy(16, 10+paso2Agregar);cprintf("%s: ", primerSemestre[i]);
                     gotoxy(60, 10+paso2Agregar);notas_1m2[nu_estudiante][i]=GetIntR();
                     paso2Agregar+=2;
                   }
                 }
                 else
                 {
                   clrscr();
                   cuadro();/*imprime el cuadro para el ingreso de las notas*/
                   gotoxy(22,3);cprintf("Ingrese las notas del primer semestre\n");
                   paso2Agregar=0;/*determinar salto de linea*/
                   fflush(stdin);
                   for (i = 0; i < 4; i++)
                   {
                     gotoxy(16, 10+paso2Agregar);cprintf("%s: ", primerSemestre[i]);
                     gotoxy(60, 10+paso2Agregar);notas_1m2[nu_estudiante][i]=GetIntR();
                     paso2Agregar+=2;
                   }
                   clrscr();
                   cuadro();
                   gotoxy(22,3);cprintf("Ingrese las notas del segundo semestre.\n");
                   gotoxy(10, 5);cprintf("Oprima \"s\" si va a llevar la clase y \"n\" si no la va a llevar.");
                   gotoxy(16, 9);cprintf("Lenguajes de programacion: ");
                   gotoxy(16, 11);cprintf("Conceptos de lenguaje: ");
                   gotoxy(16, 13);cprintf("Matematica I: ");
                   gotoxy(16, 15);cprintf("Ingles II: ");
                   gotoxy(16, 17);cprintf("Redaccion tecnica: ");
                   paso2Agregar=0;
                   fflush(stdin);
                   for (i = 0; i < 5; i++)
                   {
                     gotoxy(58, 9 + paso2Agregar);cprintf("[s\\n]");
                     gotoxy(80,25);
                     while (tecla=getch())
                     {
                       if (tecla==83||tecla==115)
                       {
                         gotoxy(58, 9+paso2Agregar);printf("     ");
                         gotoxy(59, 9+paso2Agregar);
                         if (i==0)
                         {
                           if (notas_1m2[nu_estudiante][i]<60)
                           {
                             printf("n\\a");
                             notas_1m2[nu_estudiante][i+4] = -1;
                             break;
                           }
                           else
                           {
                             notas_1m2[nu_estudiante][i+4]=GetIntR();
                             break;
                           }
                         }
                         if (i==3)
                         {
                           if (notas_1m2[nu_estudiante][i]<60)
                           {
                             printf("n\\a");
                             notas_1m2[nu_estudiante][i+4] = -1;
                             break;
                           }
                           else
                           {
                             notas_1m2[nu_estudiante][i+4]=GetIntR();
                             break;
                           }
                         }
                         notas_1m2[nu_estudiante][i+4]=GetIntR();
                         break;
                       }
                       if (tecla==78||tecla==110)
                       {
                         gotoxy(58, 9+paso2Agregar);printf("     ");
                         gotoxy(59, 9+paso2Agregar);printf("n\\a");
                         notas_1m2[nu_estudiante][i+4]=-1;
                         break;
                       }
                     }
                     paso2Agregar+=2;
                   }
                 }
                 nu_estudiante++;
                 fflush(stdin);
               }
               else
               {
                 estudiantes();
               }
             }

      break;

      case 2:
             /*Buscar*/
             if (grupo_seleccion==1)
             {
                 clrscr();
                 fflush(stdin);
                 paso2Agregar = 0;
                 auxerror = 0;
                 opc_buscar=Buscar();
                 if (opc_buscar==1)
                 {
                   clrscr();
                   gotoxy(15,10);printf("Ingrese el nombre del estudiante que desea buscar:\n");
                   gotoxy(30, 11);gets(buscar_nombre);
                   strupr(buscar_nombre);
                   MostrarISemestre();
                   for (i = 0; i < 10; i++)
                   {
                     auxBuscar = 0;
                     if (strcmp(buscar_nombre, nombres_1m1[i])==0)
                     {
                       auxBuscar = i;
                       gotoxy(5, 7+paso2Agregar);cprintf("%s", nombres_1m1[auxBuscar]);
                       gotoxy(38, 7+paso2Agregar);cprintf("2020-0%dU", carnet_1m1[auxBuscar]);
                       paso3Agregar=0;
                       for (j = 0; j < 4; j++)
                       {
                         gotoxy(51+paso3Agregar, 7+paso2Agregar);cprintf("%d", notas_1m1[auxBuscar][j]);
                         paso3Agregar+=6;
                       }
                       /*gotoxy(75, 7+paso2Agregar);cprintf("%.2f", (promedioSemestreI[j]/4));*/
                       paso2Agregar+=2;
                       auxerror++;
                     }
                   }
                   if (auxerror==0)
                   {
                     ebuscar();
                   }
                 }
                 else
                 {
                   clrscr();
                   agraegarNombre();
                   gotoxy(20,10);cprintf("Ingrese el carnet del estudiante que desea buscar:");
                   gotoxy(35,11);cprintf("2020-0   U");
                   gotoxy(41,11);buscar_carnet=GetIntC();
                   MostrarISemestre();
                   for (i = 0; i < nu_estudiante1; i++)
                   {
                     auxBuscar = 0;
                     if (buscar_carnet==carnet_1m1[i])
                     {
                       auxBuscar = i;
                       gotoxy(5, 7+paso2Agregar);cprintf("%s", nombres_1m1[auxBuscar]);
                       gotoxy(38, 7+paso2Agregar);cprintf("2020-0%dU", carnet_1m1[auxBuscar]);
                       paso3Agregar=0;
                       for (j = 0; j < 4; j++)
                       {
                         gotoxy(51+paso3Agregar, 7+paso2Agregar);cprintf("%d", notas_1m1[auxBuscar][j]);
                         paso3Agregar+=6;
                       }
                       /*gotoxy(75, 7+paso2Agregar);cprintf("%.2f", (promedioSemestreI[j]/4));*/
                       paso2Agregar+=2;
                       auxerror++;
                     }
                   }
                   if (auxerror==0)
                   {
                     ebuscar();
                   }
                 }
                 getch();
             }
             else
             {
               clrscr();
               fflush(stdin);
               paso2Agregar = 0;
               auxerror = 0;
               opc_buscar=Buscar();
               if (opc_buscar==1)
               {
                 clrscr();
                 gotoxy(15,10);printf("Ingrese el nombre del estudiante que desea buscar:\n");
                 gotoxy(30, 11);gets(buscar_nombre);
                 strupr(buscar_nombre);
                 MostrarISemestre();
                 for (i = 0; i < 10; i++)
                 {
                   auxBuscar = 0;
                   if (strcmp(buscar_nombre, nombres_1m2[i])==0)
                   {
                     auxBuscar = i;
                     gotoxy(5, 7+paso2Agregar);cprintf("%s", nombres_1m2[auxBuscar]);
                     gotoxy(38, 7+paso2Agregar);cprintf("2020-0%dU", carnet_1m2[auxBuscar]);
                     paso3Agregar=0;
                     for (j = 0; j < 4; j++)
                     {
                       gotoxy(51+paso3Agregar, 7+paso2Agregar);cprintf("%d", notas_1m2[auxBuscar][j]);
                       paso3Agregar+=6;
                     }
                     /*gotoxy(75, 7+paso2Agregar);cprintf("%.2f", (promedioSemestreI[j]/4));*/
                     paso2Agregar+=2;
                     auxerror++;
                   }
                 }
                 if (auxerror==0)
                 {
                   ebuscar();
                 }
               }
               else
               {
                 clrscr();
                 agraegarNombre();
                 gotoxy(20,10);cprintf("Ingrese el carnet del estudiante que desea buscar:");
                 gotoxy(35,11);cprintf("2020-0   U");
                 gotoxy(41,11);buscar_carnet=GetIntC();
                 MostrarISemestre();
                 for (i = 0; i < nu_estudiante; i++)
                 {
                   auxBuscar = 0;
                   if (buscar_carnet==carnet_1m2[i])
                   {
                     auxBuscar = i;
                     gotoxy(5, 7+paso2Agregar);cprintf("%s", nombres_1m2[auxBuscar]);
                     gotoxy(38, 7+paso2Agregar);cprintf("2020-0%dU", carnet_1m2[auxBuscar]);
                     paso3Agregar=0;
                     for (j = 0; j < 4; j++)
                     {
                       gotoxy(51+paso3Agregar, 7+paso2Agregar);cprintf("%d", notas_1m2[auxBuscar][j]);
                       paso3Agregar+=6;
                     }
                     /*gotoxy(75, 7+paso2Agregar);cprintf("%.2f", (promedioSemestreI[j]/4));*/
                     paso2Agregar+=2;
                     auxerror++;
                   }
                 }
                 if (auxerror==0)
                 {
                   ebuscar();
                 }
               }
               getch();
             }
      break;

      case 3:
             if (grupo_seleccion==1)
             {
               /*Actualizar*/
               fflush(stdin);
               nuAux_estudiante=0;
               opc_actualizar=0;
               actualizar_estudiante=0;
               MostrarISemestre();
               nuAux_estudiante=0;
               paso2Agregar=0;
               paso3Agregar=0;
               while (nuAux_estudiante!=nu_estudiante1)
               {
                 gotoxy(5, 5+paso2Agregar);cprintf("%s", nombres_1m1[nuAux_estudiante]);
                 gotoxy(38, 5+paso2Agregar);cprintf("2020-0%dU", carnet_1m1[nuAux_estudiante]);
                 paso3Agregar=0;
                 for (i = 0; i < 4; i++)
                 {
                   gotoxy(51+paso3Agregar, 5+paso2Agregar);cprintf("%d", notas_1m1[nuAux_estudiante][i]);
                   paso3Agregar+=6;
                 }
                 /*gotoxy(75, 5+paso2Agregar);cprintf("%.2f", (promedioSemestreI[i]/4));*/
                 nuAux_estudiante++;
                 paso2Agregar+=2;
               }
               actualizar_estudiante=seleccionEstudiante(nuAux_estudiante);
               clrscr();
               opc_actualizar=Actualizar_estudiante();
               switch (opc_actualizar)
               {
                case 1:
                       agraegarNombre();
                       gotoxy(25,10);printf("Ingrese el nombre del estudiante:");
                       gotoxy(35,12);
                       strcpy(nombres_1m1[actualizar_estudiante], " ");
                       gets(nombres_1m1[actualizar_estudiante]);/*Guarda los nombres de los estudiantes del grupo 1m2, en orden del numero de estudiantes, nu_estudiante*/
                       strupr(nombres_1m1[actualizar_estudiante]);
                break;
                case 2:
                       clrscr();
                       actulizar_Isemestre=actualizar_semestreI();
                       gotoxy(57,posicionActualizarSemestreI(actulizar_Isemestre));
                       notas_1m1[actualizar_estudiante][actulizar_Isemestre - 1]=GetIntR();
                       notaActualizada();
                break;
                default:
                       clrscr();
                       actualizar_IIsemestre=actualizar_semestreII();
                       if (actualizar_IIsemestre==1 || actualizar_IIsemestre==4)
                       {
                         if (notas_1m1[actualizar_estudiante][0] < 60 || notas_1m1[actualizar_estudiante][3] < 60)
                         {
                           nota_insuficiente();
                         }
                         else
                         {
                           gotoxy(57, posicionActualizarSemestreII(actualizar_IIsemestre));
                           notas_1m1[actualizar_estudiante][3 + actualizar_IIsemestre] = GetIntR();
                           notaActualizada();
                         }
                       }
                       else
                       {
                         gotoxy(57, posicionActualizarSemestreII(actualizar_IIsemestre));
                         notas_1m1[actualizar_estudiante][3 + actualizar_IIsemestre] = GetIntR();
                         notaActualizada();
                       }
                break;
               }
             }
             else
             {
               /*Actualizar*/
               fflush(stdin);
               nuAux_estudiante=0;
               opc_actualizar=0;
               actualizar_estudiante=0;
               MostrarISemestre();
               nuAux_estudiante=0;
               paso2Agregar=0;
               paso3Agregar=0;
               while (nuAux_estudiante!=nu_estudiante)
               {
                 gotoxy(5, 5+paso2Agregar);cprintf("%s", nombres_1m2[nuAux_estudiante]);
                 gotoxy(38, 5+paso2Agregar);cprintf("2020-0%dU", carnet_1m2[nuAux_estudiante]);
                 paso3Agregar=0;
                 for (i = 0; i < 4; i++)
                 {
                   gotoxy(51+paso3Agregar, 5+paso2Agregar);cprintf("%d", notas_1m2[nuAux_estudiante][i]);
                   paso3Agregar+=6;
                 }
                 /*gotoxy(75, 5+paso2Agregar);cprintf("%.2f", (promedioSemestreI[i]/4));*/
                 nuAux_estudiante++;
                 paso2Agregar+=2;
               }
               actualizar_estudiante=seleccionEstudiante(nuAux_estudiante);
               clrscr();
               opc_actualizar=Actualizar_estudiante();
               switch (opc_actualizar)
               {
                case 1:
                       agraegarNombre();
                       gotoxy(25,10);printf("Ingrese el nombre del estudiante:");
                       gotoxy(35,12);
                       strcpy(nombres_1m2[actualizar_estudiante], " ");
                       gets(nombres_1m2[actualizar_estudiante]);/*Guarda los nombres de los estudiantes del grupo 1m2, en orden del numero de estudiantes, nu_estudiante*/
                       strupr(nombres_1m2[actualizar_estudiante]);
                break;
                case 2:
                       clrscr();
                       actulizar_Isemestre=actualizar_semestreI();
                       gotoxy(57,posicionActualizarSemestreI(actulizar_Isemestre));
                       notas_1m2[actualizar_estudiante][actulizar_Isemestre - 1]=GetIntR();
                       notaActualizada();
                break;
                default:
                       clrscr();
                       actualizar_IIsemestre=actualizar_semestreII();
                       if (actualizar_IIsemestre==1 || actualizar_IIsemestre==4)
                       {
                         if (notas_1m2[actualizar_estudiante][0] < 60 || notas_1m2[actualizar_estudiante][3] < 60)
                         {
                           nota_insuficiente();
                         }
                         else
                         {
                           gotoxy(57, posicionActualizarSemestreII(actualizar_IIsemestre));
                           notas_1m2[actualizar_estudiante][3 + actualizar_IIsemestre] = GetIntR();
                           notaActualizada();
                         }
                       }
                       else
                       {
                         gotoxy(57, posicionActualizarSemestreII(actualizar_IIsemestre));
                         notas_1m2[actualizar_estudiante][3 + actualizar_IIsemestre] = GetIntR();
                         notaActualizada();
                       }
                break;
               }
             }
      break;

      case 4:
              if (grupo_seleccion==1)
              {
                intentos = login_registro();
                if (intentos > 0)
                {
                  fflush(stdin);
                  nuAux_estudiante=0;
                  opc_actualizar=0;
                  actualizar_estudiante=0;
                  MostrarISemestre();
                  nuAux_estudiante=0;
                  paso2Agregar=0;
                  paso3Agregar=0;
                  while (nuAux_estudiante!=nu_estudiante1)
                  {
                    gotoxy(5, 5+paso2Agregar);cprintf("%s", nombres_1m1[nuAux_estudiante]);
                    gotoxy(38, 5+paso2Agregar);cprintf("2020-0%dU", carnet_1m1[nuAux_estudiante]);
                    paso3Agregar=0;
                    for (i = 0; i < 4; i++)
                    {
                      gotoxy(51+paso3Agregar, 5+paso2Agregar);cprintf("%d", notas_1m1[nuAux_estudiante][i]);
                      paso3Agregar+=6;
                    }
                    /*gotoxy(75, 5+paso2Agregar);cprintf("%.2f", promedioSemestreI[i]);*/
                    nuAux_estudiante++;
                    paso2Agregar+=2;
                  }
                  actualizar_estudiante=seleccionEstudiante(nu_estudiante1);
                  clrscr();
                  strcpy(nombres_1m1[actualizar_estudiante], " ");
                /*for (i = 0; i < 10; i++)
                  {
                    notas_1m2[actualizar_estudiante][i] = 0;
                  }*/
                  for (i = actualizar_estudiante; i < 10; i++)
                  {
                    auxBorrar = 0;
                    strcpy(nombres_1m1[i], nombres_1m1[i+1]);
                    strcpy(nombres_1m1[i+1], " ");
                    auxBorrar = carnet_1m1[i];
                    carnet_1m1[i] = carnet_1m1[i+1];
                    carnet_1m1[i+1] = auxBorrar;
                  }
                  for (i = actualizar_estudiante; i < 9; i++)
                  {
                    auxBorrar = 0;
                    for (j = 0; j < 9; j++)
                    {
                      auxBorrar = notas_1m1[i][j];
                      notas_1m1[i][j] = notas_1m1[i+1][j];
                      notas_1m1[i+1][j] = auxBorrar;
                    }
                  }
                  for (i = 0; i < 10; i++)
                  {
                    notas_1m1[10][i] = 0;
                  }
                  carnet_1m1[10] = 0;
                  nu_estudiante1--;
                  estudianteEliminado();
                }
                else
                {
                  ful_intentos();
                  goto salida;
                }
              }
              else
              {
                intentos = login_registro();
                if (intentos > 0)
                {
                  fflush(stdin);
                  nuAux_estudiante=0;
                  opc_actualizar=0;
                  actualizar_estudiante=0;
                  MostrarISemestre();
                  nuAux_estudiante=0;
                  paso2Agregar=0;
                  paso3Agregar=0;
                  while (nuAux_estudiante!=nu_estudiante)
                  {
                    gotoxy(5, 5+paso2Agregar);cprintf("%s", nombres_1m2[nuAux_estudiante]);
                    gotoxy(38, 5+paso2Agregar);cprintf("2020-0%dU", carnet_1m2[nuAux_estudiante]);
                    paso3Agregar=0;
                    for (i = 0; i < 4; i++)
                    {
                      gotoxy(51+paso3Agregar, 5+paso2Agregar);cprintf("%d", notas_1m2[nuAux_estudiante][i]);
                      paso3Agregar+=6;
                    }
                    /*gotoxy(75, 5+paso2Agregar);cprintf("%.2f", promedioSemestreI[i]);*/
                    nuAux_estudiante++;
                    paso2Agregar+=2;
                  }
                  actualizar_estudiante=seleccionEstudiante(nu_estudiante);
                  clrscr();
                  strcpy(nombres_1m2[actualizar_estudiante], " ");
                /*for (i = 0; i < 10; i++)
                  {
                    notas_1m2[actualizar_estudiante][i] = 0;
                  }*/
                  for (i = actualizar_estudiante; i < 10; i++)
                  {
                    auxBorrar = 0;
                    strcpy(nombres_1m2[i], nombres_1m2[i+1]);
                    strcpy(nombres_1m2[i+1], " ");
                    auxBorrar = carnet_1m2[i];
                    carnet_1m2[i] = carnet_1m2[i+1];
                    carnet_1m2[i+1] = auxBorrar;
                  }
                  for (i = actualizar_estudiante; i < 9; i++)
                  {
                    auxBorrar = 0;
                    for (j = 0; j < 9; j++)
                    {
                      auxBorrar = notas_1m2[i][j];
                      notas_1m2[i][j] = notas_1m2[i+1][j];
                      notas_1m2[i+1][j] = auxBorrar;
                    }
                  }
                  for (i = 0; i < 10; i++)
                  {
                    notas_1m2[10][i] = 0;
                  }
                  carnet_1m2[10] = 0;
                  nu_estudiante--;
                  estudianteEliminado();
                }
                else
                {
                  ful_intentos();
                  goto salida;
                }
              }
      break;

      case 5:
              if (grupo_seleccion==1)
              {
                fflush(stdin);
               /*Mostrar*/
               /*for (i = 0; i <= nu_estudiante ; i++)
               {
                 auxProm1 = 0;
                 for (j = 0; j < 4; j++)
                 {
                   auxProm1 += notas_1m2[i][j];
                 }
                 auxProm1 /= 1;
                 promedioSemestreI[i]=auxProm1;
               }*/
               MostrarISemestre();
               nuAux_estudiante=0;
               paso2Agregar=0;
               paso3Agregar=0;
              while (nuAux_estudiante!=nu_estudiante1)
              {
                gotoxy(5, 5+paso2Agregar);cprintf("%s", nombres_1m1[nuAux_estudiante]);
                gotoxy(38, 5+paso2Agregar);cprintf("2020-0%dU", carnet_1m1[nuAux_estudiante]);
                paso3Agregar=0;
                for (i = 0; i < 4; i++)/*impresion de las primeras 4 notas*/
                {
                  gotoxy(51+paso3Agregar, 5+paso2Agregar);cprintf("%d", notas_1m1[nuAux_estudiante][i]);
                  paso3Agregar+=6;
                  /*gotoxy(75, 5 + paso2Agregar);
                  cprintf("%d", promedioSemestreI[i]);*/
                }
                nuAux_estudiante++;
                paso2Agregar+=2;
              }
              gotoxy(80,25);
              getch();
              MostrarIISemestre();
              nuAux_estudiante=0;
              paso2Agregar=0;
              paso3Agregar=0;
              while (nuAux_estudiante!=nu_estudiante1)
              {
                gotoxy(5, 5+paso2Agregar);cprintf("%s", nombres_1m1[nuAux_estudiante]);
                gotoxy(34, 5+paso2Agregar);cprintf("2020-0%dU", carnet_1m1[nuAux_estudiante]);
                paso3Agregar=0;
                for (i = 0; i < 5; i++)
                {
                  if (notas_1m1[nuAux_estudiante][i+4]==-1)
                  {
                    gotoxy(47 + paso3Agregar, 5 + paso2Agregar);
                    cprintf("n\\a");
                    paso3Agregar+=6;
                  }
                  else
                  {
                    gotoxy(47 + paso3Agregar, 5 + paso2Agregar);cprintf("%d", notas_1m1[nuAux_estudiante][i + 4]);
                    paso3Agregar+=6;
                  }
                }
                /*gotoxy(75, 5+paso2Agregar);cprintf("%.2f", (promedioSemestreI[i]/4));*/
                nuAux_estudiante++;
                paso2Agregar+=2;
              }
              getch();
              }
              else
              {
                fflush(stdin);
               /*Mostrar*/
               /*for (i = 0; i <= nu_estudiante ; i++)
               {
                 auxProm1 = 0;
                 for (j = 0; j < 4; j++)
                 {
                   auxProm1 += notas_1m2[i][j];
                 }
                 auxProm1 /= 1;
                 promedioSemestreI[i]=auxProm1;
               }*/
               MostrarISemestre();
               nuAux_estudiante=0;
               paso2Agregar=0;
               paso3Agregar=0;
              while (nuAux_estudiante!=nu_estudiante)
              {
                gotoxy(5, 5+paso2Agregar);cprintf("%s", nombres_1m2[nuAux_estudiante]);
                gotoxy(38, 5+paso2Agregar);cprintf("2020-0%dU", carnet_1m2[nuAux_estudiante]);
                paso3Agregar=0;
                for (i = 0; i < 4; i++)/*impresion de las primeras 4 notas*/
                {
                  gotoxy(51+paso3Agregar, 5+paso2Agregar);cprintf("%d", notas_1m2[nuAux_estudiante][i]);
                  paso3Agregar+=6;
                  /*gotoxy(75, 5 + paso2Agregar);
                  cprintf("%d", promedioSemestreI[i]);*/
                }
                nuAux_estudiante++;
                paso2Agregar+=2;
              }
              gotoxy(80,25);
              getch();
              MostrarIISemestre();
              nuAux_estudiante=0;
              paso2Agregar=0;
              paso3Agregar=0;
              while (nuAux_estudiante!=nu_estudiante)
              {
                gotoxy(5, 5+paso2Agregar);cprintf("%s", nombres_1m2[nuAux_estudiante]);
                gotoxy(34, 5+paso2Agregar);cprintf("2020-0%dU", carnet_1m2[nuAux_estudiante]);
                paso3Agregar=0;
                for (i = 0; i < 5; i++)
                {
                  if (notas_1m2[nuAux_estudiante][i+4]==-1)
                  {
                    gotoxy(47 + paso3Agregar, 5 + paso2Agregar);
                    cprintf("n\\a");
                    paso3Agregar+=6;
                  }
                  else
                  {
                    gotoxy(47 + paso3Agregar, 5 + paso2Agregar);cprintf("%d", notas_1m2[nuAux_estudiante][i + 4]);
                    paso3Agregar+=6;
                  }
                }
                /*gotoxy(75, 5+paso2Agregar);cprintf("%.2f", (promedioSemestreI[i]/4));*/
                nuAux_estudiante++;
                paso2Agregar+=2;
              }
              getch();
              }
      break;

      case 6:
             /*Grupo*/
             fflush(stdin);
             grupo_seleccion=Grupo();
      break;

      default:
              /*Salir*/
              marco();
      break;
     }
    }
  }
  else
  {
    salida:
    parpadeo();
  }
}
