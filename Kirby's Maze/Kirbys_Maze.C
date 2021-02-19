#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include "KIRBY.H"

void main(void)
{
  int gd = DETECT, gm;
  int opc1 = 0, opc2 = 0;
  initgraph(&gd, &gm, "C:\\TC\\BGI");

  do
  {
    opc1 = screen1();
    switch (opc1)
    {
      case 0:
              presentacion();
      break;

      case 1:
              do
              {
                fflush(stdin);
                opc2 = screen2();
                switch (opc2)
                {
                  case 0:
                          niveles();
                  break;

                  case 1:
                          score();
                  break;

                  case 2:
                          tutorial();
                  break;

                  case 3:
                        
                  break;
                }
              } while(opc2 != 3);
      break;

      case 2:
      break;
    }
  } while(opc1 != 2);


  closegraph();
}

