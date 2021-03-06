//Incluindo biblioteca.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//Definindo o tamanho dos vetores x e y.
#define VETORX 14
#define VETORY 14


//=========================================================================================================================================================================================================================





//FUN��ES DE ESTRUTURA GERAL





//=========================================================================================================================================================================================================================


//Estrutura "geral".
typedef struct{
	int tipo;
	int vida; 
	int direcao;
	int contPonto;
	int contTanque; 
	char sprite;
	
	//DIRE��O
	//Norte == 1
	//Sul   == 2
	//Leste == 3
	//Oeste == 4
	
	//TIPO
	//Espa�o vazio = 0.
	//Fronteira do tabuleiro = 1.
	//Rel�quia = 2.
	//Bloco de a�o = 3.
	//Tijolos = 4.
	//Tanque jogador Os�rio = 5.
	//Tanque inimigo M1 Ambrans = 6.
	//Tanque inimigo Centurion = 7.
	//Tanque inimigo Os�rio = 8.
	
}geral;


//=========================================================================================================================================================================================================================





//FUN��ES GERAIS





//=========================================================================================================================================================================================================================


//Zera a Matriz (tipo==0) .
void zeraMatriz ();


//Gera a Fronteira do Tabuleiro (tipo==1).
void geraLimite();


//Gera Rel�quia(tipo==2).
void geraReliquia ();


//Gera Blocos de A�o (tipo=3).
void geraBloco();


//Gera Tijolos Normais (tipo==4).
void geraTijolos ();


//Gera Tanque do Jogador Principal (Os�rio) (tipo==5).
void tanqueOsorio ();


//Gera Tanque do Jogador Inimigo (M1 Abrams) (tipo==6).
void tanqueAbrams ();


//Gera Tanque do Jogador Inimigo Centurion (tipo==7).
void tanqueCenturion ();


//Gera Tanque do Jogador Inimigo Osorio (tipo==8).
void tanqueInimigoOsorio ();


//Imprime o Tabuleiro.
void imprimeTabuleiro ();


//Estrutura de controle do espa�amento.
void espaco ();


//Copia o tabuleiro.
void copiaTabuleiro();


//Copia o tabuleiro auxiliar para o principal.
void colaTabuleiro();


//Mostra as informa��es do jogador na tela.
void printaInfo();


//Zera a c�lula da matriz.
void zeraCelula();


//=========================================================================================================================================================================================================================





//FUN��ES DE JOGADA





//=========================================================================================================================================================================================================================


//Transporta todas as informa��es do tanque principal (Os�rio) para outra c�lula.
void movimentoOsorio ();


//Muda a dire��o do tanque principal (Os�rio).
void giraOsorio ();


//Sistema de tiro do tanque principal (Os�rio).
void atiraOsorio();


//Jogada do tanque inimigo M1Abrams
void jogadaInimigoAbrams();


//Jogada do tanque inimigo M1Abrams
void jogadaInimigoCenturion();


//Jogada do tanque inimigo M1Abrams
void jogadaInimigoOsorio();


//=========================================================================================================================================================================================================================





//C�DIGO PRINCIPAL





//=========================================================================================================================================================================================================================


//Fun��o c�digo fonte.
int main() {
	
	geral matriz[VETORX][VETORY];
	geral matrizAux[14][14];
	int menuprincipal,menujogada,menusair,vardirecao,posx,posy,i,j;
	
	do{
		system("cls");
		printf("Bem vindo ao Battle City CEFET!!!\n\n[1] Jogar.\n[2] Debug.\n[3] Lista de jogadores.\n[4] Sair.\n\nEscolha uma opcao: ");
		scanf("%d",&menuprincipal);
		
		switch(menuprincipal){
			case 1:

				zeraMatriz(matriz);
				geraLimite(matriz);
				geraReliquia(matriz);
				geraBloco(matriz);
				geraTijolos(matriz);
				tanqueOsorio(matriz);
				tanqueAbrams(matriz);
				tanqueCenturion(matriz);
				tanqueInimigoOsorio(matriz);
				
				copiaTabuleiro(matriz,matrizAux);
				
				
				//Estrutura da jogada.
				do{
					
					espaco();
					imprimeTabuleiro(matriz);
					
					printf("[1] Movimentar o tanque.\n[2] Disparar.\n[3] Girar o tanque.\n[4] Sair.\n\nEscolha uma opcao: ");
					scanf("%d",&menujogada);
					
					//menu jogada.
					switch(menujogada){
						
						//Movimentar tanque principal.
						case 1:
							
							espaco();
							movimentoOsorio(matriz);
							break;
							
						//Dsparo do tanque.		
						case 2:
							atiraOsorio(matriz);
							break;
							
						//Girar o tanque.	
						case 3:
							
							espaco();
							giraOsorio(matriz);
							break;
							
						//Sair.	
						case 4:
							
							espaco();
							imprimeTabuleiro(matriz);
							
							printf("[1] Reiniciar Fase.\n[2] Novo Jogo.\nEscolha uma opcao: ");
							scanf("%d",&menusair);
							
							if(menusair==1){
								colaTabuleiro(matriz,matrizAux);
							}
							if(menusair==2){
								menujogada = 5;
								
							}
							espaco();
							
							break;
					}
				}
				while(menujogada != 5);
				break;
				
				case 2 :
					break;		
		}
	}
	while(menuprincipal != 4);
	return 0;
}


//=========================================================================================================================================================================================================================





//C�DIGO DAS FUN��ES GERAIS





//=========================================================================================================================================================================================================================


//Zera a Matriz (tipo==0).
void zeraMatriz (geral matriz[VETORX][VETORY]){
	int i, j;
		
	//Transforma toda a matriz em c�lulas vazias.
	for(i=0;i<=VETORY;i++){
		for(j=0;j<=VETORY;j++){
			matriz[i][j].tipo = 0;
			matriz[i][j].vida = 0;
			matriz[i][j].direcao = 0;
			matriz[i][j].contPonto = 0;
			matriz[i][j].contTanque = 0;
			matriz[i][j].sprite = ' ';
			} 	
	}
	
}


//Gera a Fronteira do Tabuleiro (tipo==1).
void geraLimite(geral matriz[VETORX][VETORY]){
	int i,j;
	
	//Cria a fronteira de zeros do tabuleiro.
	for(i=0;i<=VETORX;i++){
		matriz[0][i].tipo = 1;
		matriz[0][i].sprite = '0';
		matriz[VETORX][i].tipo = 1;
		matriz[VETORX][i].sprite = '0';
	}
	for(i=1;i<=VETORY-1;i++){
		matriz[i][0].tipo = 1;
		matriz[i][0].sprite = '0';
		matriz[i][VETORY].tipo = 1;	
		matriz[i][VETORY].sprite = '0';
	}
	
}


//Gera Rel�quia(tipo==2).
void geraReliquia (geral matriz[VETORX][VETORY]){
	
	//Gera a rel�quia em c�lula fixa do tabuleiro.
	matriz[13][7].tipo = 2;
	matriz[13][7].vida = 1;
	matriz[13][7].sprite = 197;
	
}


//Gera Blocos de A�o (tipo=3).
void geraBloco(geral matriz[VETORX][VETORY]){
	
	//Gera os blocos de a�o em c�lulas fixas do tabuleiro.
	matriz[2][2].tipo = 3 ;
	matriz[2][2].sprite = 219 ;
	matriz[12][2].tipo = 3 ;
	matriz[12][2].sprite = 219 ;
	matriz[2][12].tipo = 3 ;
	matriz[2][12].sprite = 219 ;
	matriz[12][12].tipo = 3 ;
	matriz[12][12].sprite = 219 ;
	matriz[7][7].tipo = 3 ;
	matriz[7][7].sprite = 219 ;
	
}


//Gera Tijolos Normais (tipo==4).
void geraTijolos (geral matriz[VETORX][VETORY]){
	int i, j, var;
	
	srand(time(0));
	
	//Gera a prote��o fixa de tijolos da rel�quia.
	matriz[12][7].tipo = 4;
	matriz[12][7].vida = 1;
	matriz[12][7].sprite = 177;
	
	for(i=1;i<=VETORX-1;i++){
		if(i==12 || i==13){
			matriz[i][6].tipo = 4;
			matriz[i][6].vida = 1;
			matriz[i][6].sprite = 177;
			matriz[i][8].tipo = 4;
			matriz[i][8].vida = 1;
			matriz[i][8].sprite = 177;
		}
		
	}
	
	
	//Gera tijolos normais em c�lulas aleat�rias do tabuleiro.
	for(i=1;i<=VETORY-1;i++){
		for(j=1;j<=VETORY-1;j++){
				if(matriz[i][j].tipo==0){
					var = rand() % 3;
					if(var==0){
					matriz[i][j].tipo = 4;
					matriz[i][j].vida = 1;
					matriz[i][j].sprite = 177;
					}
				}
				
		} 	
	}
	
}


//Gera Tanque do Jogador Principal (Os�rio) (tipo==5).
void tanqueOsorio (geral matriz[VETORX][VETORY]){
	int i, j;
	
	srand(time(0));

	//Gera tanque do jogador (Os�rio) em uma c�lula aleat�ria do tabuleiro.
	do{
		i = 1 + (rand() % 13);
		j = 1 + (rand() % 13);
		if(matriz[i][j].tipo == 0){
			matriz[i][j].tipo = 5;
			matriz[i][j].vida = 4;
			matriz[i][j].direcao = 1;
			matriz[i][j].sprite = 'O';
		}
	}
	while(matriz[i][j].tipo != 5);
	
}


//Gera Tanque do Jogador Inimigo (M1 Abrams) (tipo==6).
void tanqueAbrams (geral matriz[VETORX][VETORY]){
	int i, j;
	
	srand(time(0));
	
	//Cria tanque do inimigo(M1 Abrans) em c�lula aleat�ria do tabuleiro.
	do{
		i = 1 + (rand() % 13);
		j = 1 + (rand() % 13);
		if(matriz[i][j].tipo == 0){
			matriz[i][j].tipo = 6;
			matriz[i][j].vida = 1;
			matriz[i][j].direcao = 1;
			matriz[i][j].sprite = 'A';
		}
	}
	while(matriz[i][j].tipo != 6);
	
}


//Gera Tanque do Jogador Inimigo Centurion (tipo==7).
void tanqueCenturion (geral matriz[VETORX][VETORY]){
	int i, j;
	
	srand(time(0));
	
	//Cria tanque do inimigo(Centurion) em c�lula aleat�ria do tabuleiro.
	do{
		i = 1 + (rand() % 13);
		j = 1 + (rand() % 13);
		if(matriz[i][j].tipo == 0){
			matriz[i][j].tipo = 7;
			matriz[i][j].vida = 1;
			matriz[i][j].direcao = 1;
			matriz[i][j].sprite = 'C';
		}
	}
	while(matriz[i][j].tipo != 7);
	
}


//Gera Tanque inimigo (Os�rio) (tipo==8).
void tanqueInimigoOsorio (geral matriz[VETORX][VETORY]){
	int i, j;
	
	srand(time(0));

	//Gera tanque inimigo (Os�rio) em uma c�lula aleat�ria do tabuleiro.
	do{
		i = 1 + (rand() % 13);
		j = 1 + (rand() % 13);
		if(matriz[i][j].tipo == 0){
			matriz[i][j].tipo = 8;
			matriz[i][j].vida = 1;
			matriz[i][j].direcao = 1;
			matriz[i][j].sprite = 'T';
		}
	}
	while(matriz[i][j].tipo != 8);
	
}


//Imprime o Tabuleiro.
void imprimeTabuleiro (geral matriz[VETORX][VETORY]){
	int i, j;
	
	printaInfo();
	
	//Imprime o tabuleiro atrav�s do sprite.
	for(i=0;i<=VETORX;i++){
		for(j=0;j<=VETORY;j++){
			printf("  %c  ", matriz[i][j].sprite);
		}
		printf("\n\n\n");
	}
	
}


//Estrutura de controle do espa�amento.
void espaco (){
	
	system("cls");
	printf("\n\n");

}


//Copia o tabuleiro.
void copiaTabuleiro(geral matriz[VETORX][VETORY],geral matrizAux[VETORX][VETORY]){
	int i;
	int j;
	
	for(i=0;i<=VETORX;i++){
		for(j=0;j<=VETORY;j++){
			matrizAux[i][j].tipo = matriz[i][j].tipo;
			matrizAux[i][j].vida = matriz[i][j].vida;
			matrizAux[i][j].direcao = matriz[i][j].direcao;
			matrizAux[i][j].sprite = matriz[i][j].sprite;
			
		}
	}
		
}


//Copia o tabuleiro auxiliar para o principal.
void colaTabuleiro(geral matriz[VETORX][VETORY],geral matrizAux[VETORX][VETORY]){
	int i;
	int j;
	
	for(i=0;i<=VETORX;i++){
		for(j=0;j<=VETORY;j++){
			matriz[i][j].tipo = matrizAux[i][j].tipo;
			matriz[i][j].vida = matrizAux[i][j].vida;
			matriz[i][j].direcao = matrizAux[i][j].direcao;
			matriz[i][j].sprite = matrizAux[i][j].sprite;
		}
	}
	
}


//Mosta as informa��es do tanque do jogador.
void printaInfo(geral matriz[VETORX][VETORY]){
	int i, j, posx, posy;
	//Encontrar tanque Os�rio.
	for(i=0;i<=VETORY;i++){
		for(j=0;j<=VETORY;j++){
			if(matriz[i][j].tipo==5){
				posx = i;
				posy = j;
			}
		}
	}
	
	printf("  VIDAS: %d \t\tTANQUES DESTRUIDOS: %d \t\tPONTOS: %d \n\n",matriz[posx][posy].vida, matriz[posx][posy].contTanque, matriz[posx][posy].contPonto);
}


//Zera a c�lula da matriz.
void zeraCelula(geral matriz[VETORX][VETORY], int x, int y){
	
	matriz[x][y].tipo = 0;
	matriz[x][y].vida = 0;
	matriz[x][y].direcao = 0;
	matriz[x][y].sprite = ' ';
	
}


//=========================================================================================================================================================================================================================





//C�DIGO DAS FUN��ES DE JOGADA





//=========================================================================================================================================================================================================================


//Transporta todas as informa��es do tanque principal (Os�rio) para outra c�lula.
void movimentoOsorio (geral matriz[VETORX][VETORY]){
	int i,j,vardirecao,posx,posy;
	
	//Encontrar tanque Os�rio.
	for(i=0;i<=VETORY;i++){
		for(j=0;j<=VETORY;j++){
			if(matriz[i][j].tipo==5){
				posx = i;
				posy = j;
			}
		}
	}

	
	//Estrutura de controle do espa�amento.
	printf("\n\n");
	espaco();
	
	imprimeTabuleiro(matriz);
	
	//Estrutura do menu de movimento.
	printf("[1] Movimentar Norte.\n[2] Movimentar Sul.\n[3] Movimentar Leste.\n[4] Movimentar Oeste.\n\nEscolha uma opcao: ");
	scanf("%d",&vardirecao);
	
	if(vardirecao==matriz[posx][posy].direcao){	
	
		//Movimenta o tanque para o norte.
		if(vardirecao==1){
								
			if(matriz[posx-1][posy].tipo==0){
				matriz[posx-1][posy].tipo = matriz[posx][posy].tipo;
				matriz[posx-1][posy].vida = matriz[posx][posy].vida;
				matriz[posx-1][posy].direcao = matriz[posx][posy].direcao;
				matriz[posx-1][posy].contPonto = matriz[posx][posy].contPonto;
				matriz[posx-1][posy].contTanque = matriz[posx][posy].contTanque;
				matriz[posx-1][posy].sprite = matriz[posx][posy].sprite;
				matriz[posx][posy].tipo = 0;
				matriz[posx][posy].vida = 0;
				matriz[posx][posy].direcao = 0;
				matriz[posx][posy].contPonto = 0;
				matriz[posx][posy].contTanque = 0;
				matriz[posx][posy].sprite = ' ';
				
			//	jogadaInimigoAbrams(matriz);
			//	jogadaInimigoCenturion(matriz);
			//	jogadaInimigoOsorio(matriz);
			}
			
		}
							
		//Movimenta o tanque para o sul. 
		if(vardirecao==2){
									
			if(matriz[posx+1][posy].tipo==0){
				matriz[posx+1][posy].tipo = matriz[posx][posy].tipo;
				matriz[posx+1][posy].vida = matriz[posx][posy].vida;
				matriz[posx+1][posy].direcao = matriz[posx][posy].direcao;
				matriz[posx+1][posy].contPonto = matriz[posx][posy].contPonto;
				matriz[posx+1][posy].contTanque = matriz[posx][posy].contTanque;
				matriz[posx+1][posy].sprite = matriz[posx][posy].sprite;
				matriz[posx][posy].tipo = 0;
				matriz[posx][posy].vida = 0;
				matriz[posx][posy].direcao = 0;
				matriz[posx][posy].contPonto = 0;
				matriz[posx][posy].contTanque = 0;
				matriz[posx][posy].sprite = ' ';
				
			//	jogadaInimigoAbrams(matriz);
			//	jogadaInimigoCenturion(matriz);
			//	jogadaInimigoOsorio(matriz);
			}
			
		}
								
		//Movimenta o tanque para o leste.
		if(vardirecao==3){
								
			if(matriz[posx][posy+1].tipo==0){
				matriz[posx][posy+1].tipo = matriz[posx][posy].tipo;
				matriz[posx][posy+1].vida = matriz[posx][posy].vida;
				matriz[posx][posy+1].direcao = matriz[posx][posy].direcao;
				matriz[posx][posy+1].contPonto = matriz[posx][posy].contPonto;
				matriz[posx][posy+1].contTanque = matriz[posx][posy].contTanque;
				matriz[posx][posy+1].sprite = matriz[posx][posy].sprite;
				matriz[posx][posy].tipo = 0;
				matriz[posx][posy].vida = 0;
				matriz[posx][posy].direcao = 0;
				matriz[posx][posy].contPonto = 0;
				matriz[posx][posy].contTanque = 0;
				matriz[posx][posy].sprite = ' ';
				
			//	jogadaInimigoAbrams(matriz);
			//	jogadaInimigoCenturion(matriz);
			//	jogadaInimigoOsorio(matriz);
			}
			
		}
								
		//Movimenta o tanque para o oeste.
		if(vardirecao==4){
									
			if(matriz[posx][posy-1].tipo==0){	
				matriz[posx][posy-1].tipo = matriz[posx][posy].tipo;
				matriz[posx][posy-1].vida = matriz[posx][posy].vida;
				matriz[posx][posy-1].direcao = matriz[posx][posy].direcao;
				matriz[posx][posy-1].contPonto = matriz[posx][posy].contPonto;
				matriz[posx][posy-1].contTanque = matriz[posx][posy].contTanque;
				matriz[posx][posy-1].sprite = matriz[posx][posy].sprite;
				matriz[posx][posy].tipo = 0;
				matriz[posx][posy].vida = 0;
				matriz[posx][posy].direcao = 0;
				matriz[posx][posy].contPonto = 0;
				matriz[posx][posy].contTanque = 0;
				matriz[posx][posy].sprite = ' ';
				
			//	jogadaInimigoAbrams(matriz);
			//	jogadaInimigoCenturion(matriz);
			//	jogadaInimigoOsorio(matriz);
			}
			
		}
			
	}
	
}


//Muda a dire��o do tanque principal (Os�rio).
void giraOsorio (geral matriz[VETORX][VETORY]){
	int i,j,vargira,posx,posy;
	
	imprimeTabuleiro(matriz);
	
	printf("[1] Girar Norte.\n[2] Girar Sul.\n[3] Girar Leste.\n[4] Girar Oeste.\nEscolha uma opcao: ");
	scanf("%d",&vargira);
	
	//Encontrar tanque Os�rio e muda a direcao
	for(i=0;i<=VETORY;i++){
		for(j=0;j<=VETORY;j++){
			if(matriz[i][j].tipo==5){
				posx = i;
				posy = j;
			}
		}
	}
	
	if(vargira==1){
		
		matriz[posx][posy].direcao = 1;
				
	}
	
	if(vargira==2){
		
		matriz[posx][posy].direcao = 2;
				
	}
	
	if(vargira==3){
		
		matriz[posx][posy].direcao = 3;
				
	}
	
	if(vargira==4){
		
		matriz[posx][posy].direcao = 4;
				
	}
	
}


//Sistema de tiro do tanque principal (Os�rio).
void atiraOsorio(geral matriz[VETORX][VETORY]){
	int i,j,atira,posx,posy,cont=0;


	for(i=0;i<=VETORY;i++){
		for(j=0;j<=VETORX;j++){
			if(matriz[i][j].tipo==5){
				posx = i;
				posy = j;
			}
		}
	}
	
	
	//Atira para o Norte
	if(matriz[posx][posy].direcao==1){
	    for(i=(posx-1);i>0;i--){
			if(matriz[i][posy].tipo == 4){
		    	zeraCelula(matriz,i,posy);
		    	break;
		    }
		    
		    if(matriz[i][posy].tipo == 6){
		    	zeraCelula(matriz,i,posy);
		    	matriz[posx][posy].contPonto += 10;
		    	matriz[posx][posy].contTanque += 1;
		    	break;
			}
			
			if(matriz[i][posy].tipo == 7){
		    	zeraCelula(matriz,i,posy);
		    	matriz[posx][posy].contPonto += 10;
		    	matriz[posx][posy].contTanque += 1;
		    	break;
		    }
		    
		    if(matriz[i][posy].tipo == 8){
		    	zeraCelula(matriz,i,posy);
		    	matriz[posx][posy].contPonto += 10;
		    	matriz[posx][posy].contTanque += 1;
		    	break;
			}
        }
	}
	//Atira para o Sul
	if(matriz[posx][posy].direcao==2){
		for(i=(posx+1);i<VETORX;i++){
			if(matriz[i][posy].tipo == 4){
			    zeraCelula(matriz,i,posy);
			    break;	
			}
			
			 if(matriz[i][posy].tipo == 6){
		    	zeraCelula(matriz,i,posy);
		    	matriz[posx][posy].contPonto += 10;
		    	matriz[posx][posy].contTanque += 1;
		    	break;
			}
			
			if(matriz[i][posy].tipo == 7){
		    	zeraCelula(matriz,i,posy);
		    	matriz[posx][posy].contPonto += 10;
		    	matriz[posx][posy].contTanque += 1;
		    	break;
		    }
		    
		    if(matriz[i][posy].tipo == 8){
		    	zeraCelula(matriz,i,posy);
		    	matriz[posx][posy].contPonto += 10;
		    	matriz[posx][posy].contTanque += 1;
		    	break;
			}
	    }
	}
	//Atira para o Leste
	if(matriz[posx][posy].direcao==3){
		for(i=(posy+1);i<VETORY;i++){
			if(matriz[posx][i].tipo == 4){
				zeraCelula(matriz,posx,i);
				break;	
			}
			
			 if(matriz[posx][i].tipo == 6){
		    	zeraCelula(matriz,posx,i);
		    	matriz[posx][posy].contPonto += 10;
		    	matriz[posx][posy].contTanque += 1;
		    	break;
			}
			
			if(matriz[posx][i].tipo == 7){
		    	zeraCelula(matriz,posx,i);
		    	matriz[posx][posy].contPonto += 10;
		    	matriz[posx][posy].contTanque += 1;
		    	break;
		    }
		    
		    if(matriz[posx][i].tipo == 8){
		    	zeraCelula(matriz,posx,i);
		    	matriz[posx][posy].contPonto += 10;
		    	matriz[posx][posy].contTanque += 1;
		    	break;
			}
	    }
	}
	//Atira para o Oeste
	if(matriz[posx][posy].direcao==4){
		for(i=(posy-1);i>0;i--){
			if(matriz[posx][i].tipo == 4){
				zeraCelula(matriz,posx,i);
				break;
			}
			
			 if(matriz[posx][i].tipo == 6){
		    	zeraCelula(matriz,posx,i);
		    	matriz[posx][posy].contPonto += 10;
		    	matriz[posx][posy].contTanque += 1;
		    	break;
			}
			
			if(matriz[posx][i].tipo == 7){
		    	zeraCelula(matriz,posx,i);
		    	matriz[posx][posy].contPonto += 10;
		    	matriz[posx][posy].contTanque += 1;
		    	break;
		    }
		    
		    if(matriz[posx][i].tipo == 8){
		    	zeraCelula(matriz,posx,i);
		    	matriz[posx][posy].contPonto += 10;
		    	matriz[posx][posy].contTanque += 1;
		    	break;
			}
	    }
	}
}


//Movimenta aleat�riamente o tanque inimigo M1 Abrams.
void jogadaInimigoAbrams(geral matriz[VETORX][VETORY]){
	int i, j, posx, posy, alemov, var=0;
	
	
	//Encontrar tanque M1 Abrams.
	for(i=0;i<=VETORY;i++){
		for(j=0;j<=VETORY;j++){
			if(matriz[i][j].tipo==6){
				posx = i;
				posy = j;
			}
		}
	}
	
	do{
		
		alemov = rand() %4;
	
		switch(alemov){
		
			//movimenta para o norte.
			case 0:
							
				if(matriz[posx-1][posy].tipo==0){
					matriz[posx-1][posy].tipo = matriz[posx][posy].tipo;
					matriz[posx-1][posy].vida = matriz[posx][posy].vida;
					matriz[posx-1][posy].direcao = 1;
					matriz[posx-1][posy].sprite = matriz[posx][posy].sprite;
					matriz[posx][posy].tipo = 0;
					matriz[posx][posy].vida = 0;
					matriz[posx][posy].direcao = 0;
					matriz[posx][posy].sprite = ' ';
					
					var=1;
				}
				
				break;
			
			//Movimenta para Sul.	
			case 1:
										
				if(matriz[posx+1][posy].tipo==0){
					matriz[posx+1][posy].tipo = matriz[posx][posy].tipo;
					matriz[posx+1][posy].vida = matriz[posx][posy].vida;
					matriz[posx+1][posy].direcao = 2;
					matriz[posx+1][posy].sprite = matriz[posx][posy].sprite;
					matriz[posx][posy].tipo = 0;
					matriz[posx][posy].vida = 0;
					matriz[posx][posy].direcao = 0;
					matriz[posx][posy].sprite = ' ';
					
					var=1;
				}
		
				break;
			
			//Movimenta para o Leste.
			case 2:
									
				if(matriz[posx][posy+1].tipo==0){
					matriz[posx][posy+1].tipo = matriz[posx][posy].tipo;
					matriz[posx][posy+1].vida = matriz[posx][posy].vida;
					matriz[posx][posy+1].direcao = 3;
					matriz[posx][posy+1].sprite = matriz[posx][posy].sprite;
					matriz[posx][posy].tipo = 0;
					matriz[posx][posy].vida = 0;
					matriz[posx][posy].direcao = 0;
					matriz[posx][posy].sprite = ' ';
					
					var=1;
				}
				
				break;
			
			//Movimenta para o Oeste.
			case 3:
										
				if(matriz[posx][posy-1].tipo==0){	
					matriz[posx][posy-1].tipo = matriz[posx][posy].tipo;
					matriz[posx][posy-1].vida = matriz[posx][posy].vida;
					matriz[posx][posy-1].direcao = 4;
					matriz[posx][posy-1].sprite = matriz[posx][posy].sprite;
					matriz[posx][posy].tipo = 0;
					matriz[posx][posy].vida = 0;
					matriz[posx][posy].direcao = 0;
					matriz[posx][posy].sprite = ' ';
					
					var=1;
				}
			
				break;
		}
				
	}
	while(var!=1);
	
}


//Movimenta aleat�riamente o tanque inimigo Centurion.
void jogadaInimigoCenturion(geral matriz[VETORX][VETORY]){
	int i, j, posx, posy, alemov, var=0;
	
	
	//Encontrar tanque Centurion.
	for(i=0;i<=VETORY;i++){
		for(j=0;j<=VETORY;j++){
			if(matriz[i][j].tipo==7){
				posx = i;
				posy = j;
			}
		}
	}
	
	do{
		
		alemov = rand() %4;
	
		switch(alemov){
		
			//movimenta para o norte.
			case 0:
							
				if(matriz[posx-1][posy].tipo==0){
					matriz[posx-1][posy].tipo = matriz[posx][posy].tipo;
					matriz[posx-1][posy].vida = matriz[posx][posy].vida;
					matriz[posx-1][posy].direcao = 1;
					matriz[posx-1][posy].sprite = matriz[posx][posy].sprite;
					matriz[posx][posy].tipo = 0;
					matriz[posx][posy].vida = 0;
					matriz[posx][posy].direcao = 0;
					matriz[posx][posy].sprite = ' ';
					
					var=1;
				}
				
				break;
			
			//Movimenta para Sul.	
			case 1:
										
				if(matriz[posx+1][posy].tipo==0){
					matriz[posx+1][posy].tipo = matriz[posx][posy].tipo;
					matriz[posx+1][posy].vida = matriz[posx][posy].vida;
					matriz[posx+1][posy].direcao = 2;
					matriz[posx+1][posy].sprite = matriz[posx][posy].sprite;
					matriz[posx][posy].tipo = 0;
					matriz[posx][posy].vida = 0;
					matriz[posx][posy].direcao = 0;
					matriz[posx][posy].sprite = ' ';
					
					var=1;
				}
		
				break;
			
			//Movimenta para o Leste.
			case 2:
									
				if(matriz[posx][posy+1].tipo==0){
					matriz[posx][posy+1].tipo = matriz[posx][posy].tipo;
					matriz[posx][posy+1].vida = matriz[posx][posy].vida;
					matriz[posx][posy+1].direcao = 3;
					matriz[posx][posy+1].sprite = matriz[posx][posy].sprite;
					matriz[posx][posy].tipo = 0;
					matriz[posx][posy].vida = 0;
					matriz[posx][posy].direcao = 0;
					matriz[posx][posy].sprite = ' ';
					
					var=1;
				}
				
				break;
			
			//Movimenta para o Oeste.
			case 3:
										
				if(matriz[posx][posy-1].tipo==0){	
					matriz[posx][posy-1].tipo = matriz[posx][posy].tipo;
					matriz[posx][posy-1].vida = matriz[posx][posy].vida;
					matriz[posx][posy-1].direcao = 4;
					matriz[posx][posy-1].sprite = matriz[posx][posy].sprite;
					matriz[posx][posy].tipo = 0;
					matriz[posx][posy].vida = 0;
					matriz[posx][posy].direcao = 0;
					matriz[posx][posy].sprite = ' ';
					
					var=1;
				}
			
				break;
		}
				
	}
	while(var!=1);
	
}


//Movimenta aleat�riamente o tanque inimigo Os�rio.
void jogadaInimigoOsorio(geral matriz[VETORX][VETORY]){
	int i, j, posx, posy, alemov, var=0;
	
	
	//Encontrar tanque Os�rio.
	for(i=0;i<=VETORY;i++){
		for(j=0;j<=VETORY;j++){
			if(matriz[i][j].tipo==8){
				posx = i;
				posy = j;
			}
		}
	}
	
	do{
		
		alemov = rand() %4;
	
		switch(alemov){
		
			//movimenta para o norte.
			case 0:
							
				if(matriz[posx-1][posy].tipo==0){
					matriz[posx-1][posy].tipo = matriz[posx][posy].tipo;
					matriz[posx-1][posy].vida = matriz[posx][posy].vida;
					matriz[posx-1][posy].direcao = 1;
					matriz[posx-1][posy].sprite = matriz[posx][posy].sprite;
					matriz[posx][posy].tipo = 0;
					matriz[posx][posy].vida = 0;
					matriz[posx][posy].direcao = 0;
					matriz[posx][posy].sprite = ' ';
					
					var=1;
				}
				
				break;
			
			//Movimenta para Sul.	
			case 1:
										
				if(matriz[posx+1][posy].tipo==0){
					matriz[posx+1][posy].tipo = matriz[posx][posy].tipo;
					matriz[posx+1][posy].vida = matriz[posx][posy].vida;
					matriz[posx+1][posy].direcao = 2;
					matriz[posx+1][posy].sprite = matriz[posx][posy].sprite;
					matriz[posx][posy].tipo = 0;
					matriz[posx][posy].vida = 0;
					matriz[posx][posy].direcao = 0;
					matriz[posx][posy].sprite = ' ';
					
					var=1;
				}
		
				break;
			
			//Movimenta para o Leste.
			case 2:
									
				if(matriz[posx][posy+1].tipo==0){
					matriz[posx][posy+1].tipo = matriz[posx][posy].tipo;
					matriz[posx][posy+1].vida = matriz[posx][posy].vida;
					matriz[posx][posy+1].direcao = 3;
					matriz[posx][posy+1].sprite = matriz[posx][posy].sprite;
					matriz[posx][posy].tipo = 0;
					matriz[posx][posy].vida = 0;
					matriz[posx][posy].direcao = 0;
					matriz[posx][posy].sprite = ' ';
					
					var=1;
				}
				
				break;
			
			//Movimenta para o Oeste.
			case 3:
										
				if(matriz[posx][posy-1].tipo==0){	
					matriz[posx][posy-1].tipo = matriz[posx][posy].tipo;
					matriz[posx][posy-1].vida = matriz[posx][posy].vida;
					matriz[posx][posy-1].direcao = 4;
					matriz[posx][posy-1].sprite = matriz[posx][posy].sprite;
					matriz[posx][posy].tipo = 0;
					matriz[posx][posy].vida = 0;
					matriz[posx][posy].direcao = 0;
					matriz[posx][posy].sprite = ' ';
					
					var=1;
				}
			
				break;
		}
				
	}
	while(var!=1);
	
}
							 







		
