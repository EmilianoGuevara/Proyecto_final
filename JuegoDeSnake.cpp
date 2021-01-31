//------------------------INICIO DEL JUEGO--------------------------------------------
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
//Incorporar Menu_end
int serpiente [100000000][2];
char tecla, opci, tcl;
int salir = 0, salid = 1;
int a = 1, tam = 4, xx = 10, yy = 10, manzanax = 12, manzanay = 10;
int velocidad = 100, puntos = 0 , h = 1;
int dir = 2;
void pantalla();
void pantalla_final();
void imprimir_serpiente();
void borrar_serpiente();
void guardar_serpiente();
void manzana();
bool fin_del_juego();
void moverse();
void score();
void aumento_de_velocidad();
void g();
void alfa();
void m();
void e();
void o();
void v();
void ef();
void r();
void menu_end();
void serpiente_complemento();
void dollar_complemento();
void etec();
void generacion_etec();
void serpiente_menuend();
void logo();
void letras_tutorial();
void iniciar_tutorial();
void tutorial();
void mecanica();
void advertencias();
void objetivo_del_juego();
void menuini();

void gotoxy(int x, int y)
{
     HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);     
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y = y;
     SetConsoleCursorPosition(hcon, dwPos);
}
int main()
{
     char op;
     while(op!='3')
     {
        menuini();
        op=getchar();
        switch(op)
        {
           case '1':
           	
		   		system("cls");
                pantalla(); 
		        gotoxy(manzanax, manzanay);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                printf("%c",36);
                while((fin_del_juego() && puntos < 201) && salir != 20)
	            { 
                    manzana();
	               	borrar_serpiente();
		            guardar_serpiente();
           		    imprimir_serpiente();
	                score();
	                aumento_de_velocidad();
	                moverse();	
                }
                Sleep(50);
	            if(salir == 0)
                {
		            system("cls");
		            pantalla_final();
		            Sleep(100);
            	    system("cls");
                } 	  
	            //system("pause>NULL");
	            
			return 0;
	            break;
          case '2':
		  		system("cls");
                tutorial();
                break;
            case '3':
            	return 0 ;
            	break;
          
        }
     }
    fflush(stdin);   
	return 0;
}

void dollar_complemento()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);	
	//Dolar 1.
	gotoxy(98,14);
	printf("*");
	gotoxy(97,15);
	printf("****");
	gotoxy(96,16);
	printf("* *");
	gotoxy(97,17);
	printf("***");
	gotoxy(98,18);
	printf("* *");
	gotoxy(96,19);
	printf("****");
	gotoxy(98,20);
	printf("*");
	//Dolar 2.
	gotoxy(106,8);
	printf("*");
	gotoxy(105,9);
	printf("****");
	gotoxy(104,10);
	printf("* *");
	gotoxy(105,11);
	printf("***");
	gotoxy(106,12);
	printf("* *");
	gotoxy(104,13);
	printf("****");
	gotoxy(106,14);
	printf("*");
	//Dolar 3.
	gotoxy(106,19);
	printf("*");
	gotoxy(105,20);
	printf("****");
	gotoxy(104,21);
	printf("* *");
	gotoxy(105,22);
	printf("***");
	gotoxy(106,23);
	printf("* *");
	gotoxy(104,24);
	printf("****");
	gotoxy(106,25);
	printf("*");
}

void serpiente_complemento()
{
	gotoxy(85,3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	printf("* *");
	gotoxy(85,4);
	printf("* *");
	gotoxy(86,5);
	printf("*");
	gotoxy(84,6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	printf("*****");
	gotoxy(83,7);
	printf("*******");
	gotoxy(82,8);
	printf("*********");
	gotoxy(82,9);
	printf("*  ***  *");
	gotoxy(82,10);
	printf("*********");
	gotoxy(83,11);
	printf("*******");
	gotoxy(83,12);
	printf("*******");
	gotoxy(83,13);
	printf("*******");
	gotoxy(82,14);
	printf("*******");
	gotoxy(82,15);
	printf("*******");
	gotoxy(81,16);
	printf("*******");
	gotoxy(80,17);
	printf("*******");
	gotoxy(80,18);
	printf("*******");
	gotoxy(80,19);
	printf("*******");
	gotoxy(81,20);
	printf("*******");
	gotoxy(81,21);
	printf("*******");
	gotoxy(81,22);
	printf("*******");
	gotoxy(83,23);
	printf("*******");
	gotoxy(83,24);
	printf("*******");
	gotoxy(84,25);
	printf("*******");
	gotoxy(85,26);
	printf("*******");
	gotoxy(85,27);
	printf("*******");
	gotoxy(85,28);
	printf("*******");
	gotoxy(84,29);
	printf("*******");
	gotoxy(83,30);
	printf("*******");
	//Corte.
	gotoxy(98,0);
	printf("******");
	gotoxy(97,1);
	printf("******");
	gotoxy(97,2);
	printf("*****");
	gotoxy(96,3);
	printf("*****");
	gotoxy(96,4);
	printf("****");
	gotoxy(95,5);
	printf("****");
	gotoxy(95,6);
	printf("***");
	gotoxy(95,7);
	printf("***");
	gotoxy(96,8);
	printf("**");
	gotoxy(96,9);
	printf("**");
	gotoxy(97,10);
	printf("*");
}
void g()
{
	gotoxy(8,10);
	printf("%c",201);
	gotoxy(8,20);
	printf("%c",200);
	gotoxy(16,20);
	printf("%c",188);
	gotoxy(16,15);
	printf("%c",187);
	for(int i = 9; i < 17; i++)
	{
		gotoxy(i,10);
		printf("%c",205);
    }
	for(int aa = 11; aa < 20; aa++)
	{
		gotoxy(8,aa);
		printf("%c",186);
	}
	for(int bb = 9; bb < 16; bb++)
	{
		gotoxy(bb,20);
		printf("%c", 205);
	}
	for(int cc = 19; cc > 15; cc--)
	{
		gotoxy(16,cc);
		printf("%c",186);
	}
	for(int dd = 13; dd < 16; dd++)
	{
		gotoxy(dd,15);
		printf("%c",205);
	}
	
}
void alfa()
{
	gotoxy(17,10);
	printf("%c",201);
	gotoxy(25,10);
	printf("%c",187);
	for(int i = 18; i < 25; i++)
	{
		gotoxy(i,10);
		printf("%c",205);
	}
	for(int aa = 11; aa < 21; aa++)
	{
		gotoxy(17,aa);
		printf("%c",186);
	}
	for(int bb = 11; bb < 21; bb++)
	{
            gotoxy(25,bb);        
            printf("%c",186);
    }
    for(int cc = 18; cc < 25; cc++)
    {
            gotoxy(cc,15);
            printf("%c",205);
    }
    gotoxy(17,15);
    printf("%c",204);
    gotoxy(25,15);
    printf("%c",185);
}
void m()
{
    gotoxy(27,10);
    printf("%c",201);
    gotoxy(39,10);
    printf("%c",187);
	for(int i = 28; i < 39; i++)
	{
         gotoxy(i,10);
         printf("%c",205);
    }
    for(int aa = 11; aa < 21; aa++)
    {
         gotoxy(27,aa);
         printf("%c",186);
    }
    for(int bb = 11; bb < 21; bb++)
    {
         gotoxy(39,bb);
         printf("%c",186);
    }
    for(int cc = 11; cc < 21; cc++)
    {
         gotoxy(33,cc);
         printf("%c",186);
    }
    gotoxy(33,10);
    printf("%c",203);
}
void e()
{
    gotoxy(41,10); 
	printf("%c",201);
	gotoxy(41,20);
	printf("%c",200);
	for(int i = 42; i < 50; i++)
	{
         gotoxy(i,10);
         printf("%c",205);
    }
    for(int aa = 42; aa < 50; aa++)
    {
         gotoxy(aa,15);
         printf("%c",205);
    }
    for(int bb = 42; bb < 50; bb++)
    {
         gotoxy(bb,20);
         printf("%c",205);
    }
    for(int cc = 11; cc < 20; cc++)
    {
         gotoxy(41,cc);
         printf("%c",186);
    }
    gotoxy(41,15);
    printf("%c",204);
}
void o()
{
	gotoxy(59,10);
	printf("%c",201);
	gotoxy(67,10);
	printf("%c",187);
	gotoxy(59,20);
	printf("%c",200);
	gotoxy(67,20);
	printf("%c",188);
	for(int i = 60; i < 67; i++)
	{
         gotoxy(i,10);
         printf("%c",205);
    }
    for(int aa = 60; aa < 67; aa++)
    {
         gotoxy(aa,20);
         printf("%c",205);
    }
    for(int bb = 11; bb < 20; bb++)
    {
         gotoxy(59,bb);
         printf("%c",186);
    }
    for(int cc = 11; cc < 20; cc++)
    {
         gotoxy(67,cc);
         printf("%c",186);
    }
}
void v()
{
    gotoxy(69,20); 
	printf("%c",200);
	gotoxy(77,20);
	printf("%c",188);
	for(int i = 70; i < 77; i++)
	{
         gotoxy(i,20);
         printf("%c",205);
    }
    for(int aa = 11; aa < 20; aa++)
    {
         gotoxy(69,aa);
         printf("%c",186);
    }
    for(int bb = 11; bb < 20; bb++)
    {
         gotoxy(77,bb);
         printf("%c",186);
    }
}
void ef()
{
    gotoxy(79,10); 
	printf("%c",201);
	gotoxy(79,20);
	printf("%c",200);
	for(int i = 80; i < 87; i++)
	{
         gotoxy(i,10);
         printf("%c",205);
    }
    for(int aa = 80; aa < 87; aa++)
    {
         gotoxy(aa,15);
         printf("%c",205);
    }
    for(int bb = 80; bb < 87; bb++)
    {
         gotoxy(bb,20);
         printf("%c",205);
    }
    for(int cc = 11; cc < 20; cc++)
    {
         gotoxy(79,cc);
         printf("%c",186);
    }
    gotoxy(79,15);
    printf("%c",204);
}
void r()
{
	gotoxy(89,10);
	printf("%c",201);
	gotoxy(97,10);
	printf("%c",187);
	gotoxy(97,15);
	printf("%c",188);
	for(int i = 90; i < 97; i++)
	{
         gotoxy(i,10);
         printf("%c",205);
    }
    for(int aa = 11; aa < 20; aa++)
    {
         gotoxy(89,aa);
         printf("%c",186);
    }
    for(int bb = 11; bb < 15; bb++)
    {
    	gotoxy(97,bb);
    	printf("%c",186);
	}
	for(int cc = 90; cc < 97; cc++)
	{
		gotoxy(cc,15);
		printf("%c",205);
	}
	gotoxy(89,15);
	printf("%c",204);
	gotoxy(90,15);
	printf("%c", 203);
	gotoxy(90,16);
	printf("%c",200);
	gotoxy(91,16);
	printf("%c",205);
	gotoxy(92,16);
	printf("%c",205);
	gotoxy(93,16);
	printf("%c",187);
	gotoxy(93,17);
	printf("%c",186);
	gotoxy(93,18);
	printf("%c",200);
	gotoxy(94,18);
	printf("%c",205);
	gotoxy(95,18);
	printf("%c",205);
	gotoxy(96,18);
	printf("%c",187);
	gotoxy(96,19);
	printf("%c",186);
	gotoxy(96,20);
	printf("%c",200);
	gotoxy(89,20);
	printf("%c",200);
}
void pantalla_final()
{
	system("color 4B");
	g();
	alfa();
	m();
	e();
	o();
	v();
	ef();
	r();
}

void aumento_de_velocidad()
{	
		if(puntos == h*20)
		{
			velocidad -= 10 ;
			h++;
		}
}
void score()
{
	gotoxy(3,1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	printf("SCORE: %i. %c", puntos,36);
}
void moverse()
{
	if(kbhit())
		{
			tecla = getch();
			switch(tecla)
            {
	                     case 'a':
		                      if(tecla != 'd')	
		                               	dir = 1;
  	                          break;
                        case 'd':
		                     if(tecla != 'a')
		                              	dir = 2;
                    	     break;
                        case 'w':
		                     if(tecla != 's')
		                            	dir = 3;
	                       	 break;
	                    case 's':
		                      if(tecla != 'w')
                                         dir = 4;
	      	                  break;
	      	            case 'p':
                              system("cls");
	      	            	  salir = 20;
	      	            	  break;
	      	            default:
	      	            	moverse();
	      	            	break;
            }
		}
		if(dir == 1)
				xx--;
		if(dir == 2)
				xx++;
		if(dir == 3)
				yy--;
		if(dir == 4)
				yy++;
        Sleep(velocidad);
}
bool fin_del_juego()
{
	if(xx == 2 || xx == 77 || yy == 3 || yy == 23)
		return false;
	for(int i = tam-1; i > 0; i--)
	{
		if(serpiente[i][0] == xx && serpiente[i][1] == yy)
			return false;
	}		
}
void manzana()
{
	if(xx == manzanax && yy == manzanay)
	{
		manzanax = (rand()%73)+4;
		manzanay = (rand()%19)+4;
		tam++;
		puntos++;
		gotoxy(manzanax,manzanay);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		printf("%c",36);
	}
}
void guardar_serpiente()
{
	serpiente[a][0] = xx;
	serpiente[a][1] = yy;
	a++;
	if(a == tam)
		a = 1;
}
void imprimir_serpiente()
{
	for(int i = 1; i < tam; i++)
	{
		gotoxy(serpiente[i][0],serpiente[i][1]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
		printf("*");
    }
}
void borrar_serpiente()
{
	gotoxy(	serpiente[a][0],serpiente[a][1]);
	printf(" ");
}
void pantalla()
{
	//adornos.
	dollar_complemento();
	serpiente_complemento();
	//marcos.
	for(int i = 2; i < 78; i++)
	{
		gotoxy(i,3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_RED);
		printf("%c",205);
		gotoxy(i,23);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_RED);
		printf("%c",205);
	}
	for(int i = 4; i < 23; i++)
	{
		gotoxy(2,i);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_RED);
        printf("%c",186);
        gotoxy(77,i);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_RED);
        printf("%c",186);
	}
	gotoxy(2,3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_RED);
	printf("%c", 201);
	gotoxy(2,23);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_RED);
	printf("%c", 200);
	gotoxy(77,3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_RED);
	printf("%c",187);
	gotoxy(77,23);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_RED);
	printf("%c",188);
}

//-------------------FIN DEL JUEGO------------------------------

//----------------------------------TUTORIAL----------------------------

void tutorial()
{
    letras_tutorial();    
    logo();
    iniciar_tutorial();
    system("pause > NULL");
    menuini();
    return;
}
void objetivo_del_juego()
{
     system("cls");
     gotoxy(10,10);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
     printf("El objetivo del juego es atrapar la mayor canridad de dinero posible.");
     gotoxy(10,14);
     printf("Mientras m%cs dinero consigas, m%cs crecer%c tu cola.",160,160,160);
     gotoxy(10,22);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
     printf("Presione una tecla para continuar...");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
     gotoxy(35,10);
     printf("atrapar");
     gotoxy(64,10);
     printf("dinero");
     gotoxy(19,14);
     printf("m%cs dinero",160);
     gotoxy(40,14);
     printf("m%cs crecer%c",160,160);
     getch();
     system("cls");
}
void advertencias()
{
     system("cls");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
     gotoxy(10,10);
     printf("Para salir presione la tecla 'P'.");
     gotoxy(10,12);
     printf("EVITA ir cambiar la direcci%cn en sentido opuesto ya que es como si chocaras con tu cola.",162);
     gotoxy(10,14);
     printf("Ejemplo: ");
     gotoxy(10,16);
     printf("\tSi vas hacia delante NO vayas hacia atr%cs, porque CHOCAS.",160);
     gotoxy(10,19);
     printf("Por lo que si cambias a direcci%cn opuesta, PIERDES.",162);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
     gotoxy(15,10);
     printf("salir");
     gotoxy(40,10);
     printf("P");
     gotoxy(53,19);
     printf("PIERDES.");
     gotoxy(34,19);
     printf("direcci%cn opuesta",162);
     gotoxy(10,12);
     printf("EVITA");
     gotoxy(43,12);
     printf("sentido opuesto");
     gotoxy(37,16);
     printf("NO");
     gotoxy(10,23);
     printf("Presiona una tecla para continuar...");
     getch();
     system("cls");
     gotoxy(10,22);
     printf("Presione una tecla para continuar...");
     gotoxy(10,10);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
     printf("ANTES DE INICIAR EL JUEGO REVISE QUE 'BLOCK MAYUS' NO EST%C ACTIVADA.",144);
     getch();
}
void mecanica()
{
	gotoxy(10,10);
	printf("La tecla 'd' mueve a la serpiente hacia la derecha.");
	gotoxy(10,12);
	printf("La tecla 'a' mueve a la serpiente hacia la izquierda.");
	gotoxy(10,14);
	printf("La tecla 'w' mueve a la serpiente hacia arriba.");
	gotoxy(10,16);
	printf("La tecla 's' mueve a la serpiente hacia abajo.");
	gotoxy(10,18);
	printf("La tecla 'SPACE' crea un portal de un espacio para no chocar con la cola.");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	gotoxy(20,10);
	printf("d");
	gotoxy(53,10);
	printf("derecha.");
	gotoxy(20,12);
	printf("a");
	gotoxy(53,12);
	printf("izquierda.");
	gotoxy(20,14);
	printf("w");
	gotoxy(50,14);
	printf("arriba.");
	gotoxy(20,16);
	printf("s");
	gotoxy(50,16);
	printf("abajo.");
	gotoxy(20,18);
	printf("SPACE");
	gotoxy(35,18);
	printf("portal");
	gotoxy(10,22);
	printf("Presione una tecla para continuar...");
	getch();
}

void logo()
{
     //Dinero.
     gotoxy(11,16);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | BACKGROUND_GREEN);
     printf("*");
     gotoxy(10,17);
     printf("****");
     gotoxy(9,18);
     printf("*");
     gotoxy(11,18);
     printf("*");
     gotoxy(10,19);
     printf("***");
     gotoxy(11,20);
     printf("*");
     gotoxy(13,20);
     printf("*");
     gotoxy(9,21);
     printf("****");
     gotoxy(11,22);
     printf("*");
     //Serpiente.
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_RED);
     for(int i = 18; i < 30; i++)
     {
             gotoxy(i,14);
             printf("*");
     }
     for(int az = 16; az < 34; az++)
     {
             gotoxy(az,15);
             printf("*");
     }
     //
     for(int bz = 15; bz < 20; bz++)
     {
             gotoxy(bz,16);
             printf("*");
     }
     for(int bzp = 26; bzp < 36; bzp ++)
     {
     		 gotoxy(bzp,16);
     		 printf("*");
	 }
     //
     for(int cz = 15; cz < 38; cz++)
     {
             gotoxy(cz,17);
             printf("*");
     }
     for(int dz = 25; dz < 119; dz++)
     {
     		 gotoxy(dz,18);
     		 printf("*");
	 }
	 for(int ez = 29; ez < 119; ez++)
	 {
	 		 gotoxy(ez,19);
	 		 printf("*");
	 }
	 for(int fz = 29; fz < 119; fz++)
	 {
	 		 gotoxy(fz,20);
	 		 printf("*");
	 }
	 for(int gz = 29; gz < 119; gz++)
	 {
	 		 gotoxy(gz,21);
	 		 printf("*");
	 }
	 for(int hz = 26; hz < 119; hz++)
	 {
	 		 gotoxy(hz,22);
	 		 printf("*");
	 }
	 for(int iz = 16; iz < 119; iz++)
	 {
	 		 gotoxy(iz,23);
	 		 printf("*");
	 }
	 for(int jz = 17; jz < 119; jz++)
	 {
	 		 gotoxy(jz,24);
	 		 printf("*");
	 }
}
//FUNCION PARA EL TUTORIAL.--------------------------------------------------------------------
void iniciar_tutorial()
{
     gotoxy(8,10);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
     printf("Presione '1' para inicial el tutorial: ");
     scanf("%c",&tcl);
     if(tcl == '1')
     {
           system("cls");
           mecanica();
           advertencias();
           objetivo_del_juego();
     }
     else
     {          
           system("cls");
           gotoxy(12,12);
           printf("Opci%cn inv%clida...",162,160);
           Sleep(700);
           system("cls");
           tutorial();
     }
}
void letras_tutorial()
{
	// Letra T
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
	gotoxy(8,2);
	printf("******");
	gotoxy(8,3);
	printf("******");
	gotoxy(10,4);
	printf("**");
	gotoxy(10,5);
	printf("**");
	gotoxy(10,6);
	printf("**");
	gotoxy(10,7);
	printf("**");
	//Letra U
	gotoxy(16,2);
	printf("**");
	gotoxy(16,3);
	printf("**");
	gotoxy(16,4);
	printf("**");
	gotoxy(16,5);
	printf("**");
	gotoxy(16,6);
	printf("******");
	gotoxy(17,7);
	printf("****");
	gotoxy(20,2);
	printf("**");
	gotoxy(20,3);
	printf("**");
	gotoxy(20,4);
	printf("**");
	gotoxy(20,5);
	printf("**");
	//Segunda Letra T
	gotoxy(24,2);
	printf("******");
	gotoxy(24,3);
	printf("******");
	gotoxy(26,4);
	printf("******");
    gotoxy(31,5);
	printf("**");
	gotoxy(31,6);
	printf("******");
	gotoxy(32,7);
	printf("****");
	gotoxy(35,4);
	printf("**");
	gotoxy(35,5);
	printf("**");
	gotoxy(26,5);
	printf("**");
	gotoxy(26,6);
	printf("**");
	gotoxy(26,7);
	printf("**");
	//Letra O
	gotoxy(32,2);
	printf("****");
	gotoxy(31,3);
	printf("******");
	gotoxy(31,4);
	printf("**");
	//Letra R
	gotoxy(39,2);
	printf("****");
	gotoxy(39,3);
	printf("**");
	gotoxy(39,4);
	printf("**");
	gotoxy(39,5);
	printf("****");
	gotoxy(39,6);
	printf("**");
	gotoxy(39,7);
	printf("**");
	gotoxy(43,3);
	printf("*");
	gotoxy(43,4);
	printf("*");
	gotoxy(42,6);
	printf("**");
	gotoxy(43,7);
	printf("**");
	//letra I
	gotoxy(47,2);
	printf("******");
	gotoxy(47,3);
	printf("******");
	gotoxy(49,4);
	printf("**");
	gotoxy(49,5);
	printf("**");
	gotoxy(47,6);
	printf("******");
	gotoxy(47,7);
    printf("******");
	//Letra A
	gotoxy(56,2);
	printf("****");
	gotoxy(55,3);
	printf("******");
	gotoxy(55,4);
	printf("**");
	gotoxy(55,5);
	printf("******");
	gotoxy(55,6);
	printf("**");
	gotoxy(55,7);
	printf("**");
	gotoxy(59,4);
	printf("**");
	gotoxy(59,6);
	printf("**");
	gotoxy(59,7);
	printf("**");
	//Letra L
	gotoxy(63,2);
	printf("**");
	gotoxy(63,3);
	printf("**");
  	gotoxy(63,4); 
	printf("**");
	gotoxy(63,5);
	printf("**");
	gotoxy(63,6);
	printf("*****");
	gotoxy(63,7);
	printf("*****");
}

//-----------------------------------FIN DEL TUTORIAL------------------------------------


//------------------MENÚ FINAL (MENUEND)------------------------------------------

void serpiente_menuend()
{
	gotoxy(72,3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	printf("* *");
	gotoxy(72,4);
	printf("* *");
	gotoxy(73,5);
	printf("*");
	gotoxy(71,6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	printf("*****");
	gotoxy(70,7);
	printf("*******");
	gotoxy(69,8);
	printf("*********");
	gotoxy(69,9);
	printf("*  ***  *");
	gotoxy(69,10);
	printf("*********");
	gotoxy(70,11);
	printf("*******");
	gotoxy(70,12);
	printf("*******");
	gotoxy(70,13);
	printf("*******");
	gotoxy(69,14);
	printf("*******");
	gotoxy(69,15);
	printf("*******");
	gotoxy(68,16);
	printf("*******");
	gotoxy(67,17);
	printf("*******");
	gotoxy(67,18);
	printf("*******");
	gotoxy(67,19);
	printf("*******");
	gotoxy(68,20);
	printf("*******");
	gotoxy(69,21);
	printf("*******");
	gotoxy(69,22);
	printf("*******");
	gotoxy(70,23);
	printf("*******");
	gotoxy(70,24);
	printf("*******");
	gotoxy(71,25);
	printf("*******");
	gotoxy(72,26);
	printf("*******");
	gotoxy(72,27);
	printf("*******");
	gotoxy(72,28);
	printf("*******");
	gotoxy(71,29);
	printf("*******");
	gotoxy(70,30);
	printf("*******");
	//corte
	gotoxy(85,0);
	printf("******");
	gotoxy(84,1);
	printf("******");
	gotoxy(84,2);
	printf("*****");
	gotoxy(83,3);
	printf("*****");
	gotoxy(83,4);
	printf("****");
	gotoxy(82,5);
	printf("****");
	gotoxy(82,6);
	printf("***");
	gotoxy(82,7);
	printf("***");
	gotoxy(83,8);
	printf("**");
	gotoxy(83,9);
	printf("**");
	gotoxy(84,10);
	printf("*");
}

void menuini()
{
	//Esto es para los marcos horizontales
     for (int i = 2 ; i<110 ; i++)
	{
		gotoxy (i,3);
		printf ("%c",205);
		gotoxy (i,25);
		printf ("%c",205);
	}
	//Esto es para los marcos verticales
	for (int i = 4 ; i < 25 ; i++)
	{
		gotoxy(2,i);
		printf("%c",186);
		gotoxy(109,i);
		printf("%C",186);
	}
	//Esquinas del marco
	gotoxy(2,3);
	printf("%c",201);
	gotoxy(2,25);
	printf("%c",200);
	gotoxy (109,3);
	printf("%c",187);
	gotoxy(109,25);
	printf("%c",188);
	
	//Dibujo del menú
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
     gotoxy(40,4);
     printf("      ++++++++++++   ++++      ++  +++++++++  ++   ++   +++++++++   ");
     gotoxy(40,5);
     printf("     ++++++++++++++  +++++     ++  ++     ++  ++  ++    +++++++++   ");
     gotoxy(40,6);
     printf("      +++++++        +++ ++    ++  ++     ++  ++ ++     ++          ");
     gotoxy(40,7);
     printf("        ++++++++     +++  ++   ++  +++++++++  +++       +++++++     ");
     gotoxy(40,8);
     printf("        ++++++++++   +++   ++  ++  ++     ++  ++ ++     ++          ");
     gotoxy(40,9);
     printf("    +++++++++++++++  +++    +++++  + +    ++  ++  ++    +++++++++   ");
     gotoxy(40,10);
     printf("    ++++++++++++++   +++     ++++  + +    ++  ++   ++   +++++++++   ");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);   
     gotoxy(15,5);
     printf("1.Partida Rapida\n",163);
     gotoxy(15,10);
     printf("2.Tutorial\n", 163);
     gotoxy(15,15);
     printf("3.Salir\n", 163);
     gotoxy(15,20);
     printf("Apriete espacio y la opcion que usted desea");
     gotoxy(15,21);
     printf("Opcion:\t",163);
     fflush(stdin);
     getchar();
     return ;
//En esta función se supone que debe ir la función del menu principal.
}
//------------------------FIN DEL MENU FINAL (MENUEND)---------------------------f("**");
