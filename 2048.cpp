# include "stdafx.h"
# include <iostream>
# include <time.h>
# include <string>
# include <stdlib.h> 

using namespace std;

#define BOARD_SIZE 4

//Devuelve una casilla random.
int casillaRandom(){
	return rand() % BOARD_SIZE;
}
//Pila receptora
struct pila
{
		int v[BOARD_SIZE];
}

//Devuelve un tile random, entre 2 o 4.
int valorRandom(){
	if(rand()%10 < 8 ){
		return 2;
	}else{
		return 4;
	}

}

int main()
{
srand(time(NULL));
   cout << "Bienvenido al 2048! Para jugar use las flechas. Para salir ponga 'q'\n";

   //1 Crear el tablero y lo inicializamos la primera vez
   int tablero[BOARD_SIZE][BOARD_SIZE] = {0};

   tablero[casillaRandom()][casillaRandom()] = valorRandom();
   tablero[casillaRandom()][casillaRandom()] = valorRandom();
   
   bool gameEnded = false;

   while(!gameEnded)
		{ int j = 0;
			
   		//2 Mostramos el trablero
		   for(int i=0; i < BOARD_SIZE; i++)
		   {
		   	for( int j = 0; j < BOARD_SIZE; j++)
				{
		   			cout << tablero[i][j];
		   			cout << " ";
		   		}
		   	cout << "\n";
		   }
		   //3 Esperamos a que el usuario ingrese una flecha, si no es eso, no pasa nada. Si pone la q, sale del juego.
		   char userInput;
		   cin >> userInput;
		   if(userInput == 'q')
				{
		   		gameEnded = true;
				}
		   else
				{
			   cout << "Usted jugo " << userInput << "\n\n";

			//4 Actualizamos el tablero
		   	switch(userInput)
				{
		   		case 'w': pila up[BOARD_SIZE];
							for(int i=0; i<BOARD_SIZE; i++)
							{   
								up[i].v[i]=tablero[i][j];
								for(int k=i+1; k<BOARD_SIZE;k++)
								{
									while(up[i].v[i]!=0 && up[i].v[k]!=0)
									{
										if(up[i].v[i]!=up[i].v[k])
											{
												continue;
											}
										else if(up[i].v[i]=up[i].v[k])
											{
												up[i].v[i]+=up[i].v[k];
												up[i].v[k]=0;
											}
									}
									if(up[i].v[i]=0 && up[i].v[k]!=0)
									{
										up[i].v[i]=up[i].v[k];
										up[i].v[k]=0;
									}
								}
							}
							for(int i=0; i < BOARD_SIZE; i++)
		   						{
		   							tablero[i][j]=up[i].v[i];
		   							for( int j = 0; j < BOARD_SIZE; j++)
										{
		   									cout << tablero[i][j];
		   									cout << " ";
		   								}
		   								cout << "\n";
		   						}
				case 's': pila down[BOARD_SIZE];
								for(int i=0; i<BOARD_SIZE; i++)
									{   
										down[i].v[i]=tablero[i][j];
										for(int k=i+1; k<BOARD_SIZE;k++)
											{
												while(down[i].v[i]!=0 && down[i].v[k]!=0)
												{
													if(down[i].v[i]!=down[i].v[k])
														{
															continue;
														}
													else if(down[i].v[i]=down[i].v[k])
														{
															down[i].v[i]+=down[i].v[k];
															down[i].v[k]=0;
														}
												}
												if(down[i].v[i]=0 && down[i].v[k]!=0)
													{
														down[i].v[i]=down[i].v[k];
														down[i].v[k]=0;
													}
											}					
		   							}
		   		case 'a': pila left[BOARD_SIZE];
		   					for(int i=0; i<BOARD_SIZE; i++)
									{   
										left[i].v[i]=tablero[i][j];
										for(int k=i+1; k<BOARD_SIZE;k++)
											{
												while(left[i].v[i]!=0 && left[i].v[k]!=0)
												{
													if(left[i].v[i]!=left[i].v[k])
														{
															continue;
														}
													else if(left[i].v[i]=left[i].v[k])
														{
															left[i].v[i]+=left[i].v[k];
															left[i].v[k]=0;
														}
												}
												if(left[i].v[i]=0 && left[i].v[k]!=0)
													{
														left[i].v[i]=left[i].v[k];
														left[i].v[k]=0;
													}
											}					
		   							}
		   		case 'd': pila right[BOARD_SIZE];
		   					for(int i=0; i<BOARD_SIZE; i++)
									{   
										right[i].v[i]=tablero[i][j];
										for(int k=i+1; k<BOARD_SIZE;k++)
											{
												while(right[i].v[i]!=0 && right[i].v[k]!=0)
												{
													if(right[i].v[i]!=right[i].v[k])
														{
															continue;
														}
													else if(right[i].v[i]=right[i].v[k])
														{
															right[i].v[i]+=right[i].v[k];
															right[i].v[k]=0;
														}
												}
												if(right[i].v[i]=0 && right[i].v[k]!=0)
													{
														right[i].v[i]=right[i].v[k];
														right[i].v[k]=0;
													}
											}					
		   							}


   			//5 Se decide si se pierde o se gana, y se muestra el mensaje correcto o si no, se vuelve al paso 2
				}
   }
   
   
}
