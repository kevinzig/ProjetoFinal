//Incluindo biblioteca.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//Definindo o tamanho dos vetores x e y.
#define VETORX 14
#define VETORY 14





//FUNÇÕES DE ESTRUTURA GERAL===================================================================================================================================================================================================





//Estrutura "geral".
typedef struct{
	int tipo;
	int vida; 
	int direcao;     
	char sprite;
	
	//DIREÇÃO
	//Norte == 1
	//Sul   == 2
	//Leste == 3
	//Oeste == 4
	
	//TIPO
	//Espaço vazio = 0.
	//Fronteira do tabuleiro = 1.
	//Relíquia = 2.
	//Bloco de aço = 3.
	//Tijolos = 4.
	//Tanque jogador Osório = 5.
	//Tanque inimigo M1 Ambrans = 6.
	//Tanque inimigo Centurion = 7.
	
}geral;





//FUNÇÕES GERAIS============================================================================================================================================================================================================





//Zera a Matriz (tipo==0) .
int zeraMatriz ();


//Gera a Fronteira do Tabuleiro (tipo==1).
int geraLimite();


//Gera Relíquia(tipo==2).
int geraReliquia ();


//Gera Blocos de Aço (tipo=3).
int geraBloco();


//Gera Tijolos Normais (tipo==4).
int geraTijolos ();


//Gera Tanque do Jogador Principal (Osório) (tipo==5).
int tanqueOsorio ();


//Gera Tanque do Jogador Inimigo (M1 Abrams) (tipo==6).
int tanqueAbrams ();


//Gera Tanque do Jogador Inimigo Centurion (tipo==7).
int tanqueCenturion ();


//Imprime o Tabuleiro.
int imprimeTabuleiro ();


//Estrutura de controle do espaçamento.
int espaco ();


//Elimina as estruturas do mapa.
int destroi();



//FUNÇÕES DE JOGADA=========================================================================================================================================================================================================





//Transporta todas as informações do tanque principal (Osório) para outra célula.
int movimentoOsorio ();


//Muda a direção do tanque principal (Osório).
int giraOsorio ();


//Verifica se na direção selecionada para atirar há algum obstaculo(blocos, Inimigos, limites), no caso da existência de um bloco comum ou inimigo, o mesmo será atinjido e destruido.
int atiraOsorio ();


//CÓDIGO PRINCIPAL==========================================================================================================================================================================================================





//Função código fonte.
int main() {
	
	geral matriz[VETORX][VETORY];
	int menu,jogada,vardirecao,posx,posy,i,j;
	
	do{
		
		printf("Bem vindo ao Battle City CEFET!!!\n\n[1] Jogar.\n[2] Debug.\n[3] Lista de jogadores.\n[4] Sair.\n\nEscolha uma opcao: ");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:
				//Estrutura de controle do espaçamento.
				espaco(matriz,VETORX,VETORY);
					
				zeraMatriz(matriz,VETORX,VETORY);
				geraLimite(matriz,VETORX,VETORY);
				geraReliquia(matriz,VETORX,VETORY);
				geraBloco(matriz,VETORX,VETORY);
				geraTijolos(matriz,VETORX,VETORY);
				tanqueOsorio(matriz,VETORX,VETORY);
				tanqueAbrams(matriz,VETORX,VETORY);
				tanqueCenturion(matriz,VETORX,VETORY);
				
				
				//Estrutura da jogada.
				do{
					
					imprimeTabuleiro(matriz,VETORX,VETORY);
					
					printf("[1] Movimentar o tanque.\n[2] Disparar.\n[3] Girar o tanque.\n[4] Sair.\n\nEscolha uma opcao: ");
					scanf("%d",&jogada);
					
					//menu jogada.
					switch(jogada){
						
						//Movimentar tanque principal.
						case 1:
							movimentoOsorio(matriz,VETORX,VETORY);
							break;
							
						//Dsparo do tanque.		
						case 2:
							atiraOsorio(matriz,VETORX,VETORY);
							destroi(matriz,VETORX,VETORY); 
							break;
							
						//Girar o tanque.	
						case 3:
							giraOsorio(matriz,VETORX,VETORY);
							break;
							
						//Sair.	
						case 4:
							break;
					}
				}
				while(jogada != 4);
				return 0;
				
				case 2 :
					break;		
		}
	}
	while(menu != 4);
	return 0;
}





//CÓDIGO DAS FUNÇÔES GERAIS==========================================================================================================================================================================================================





//Zera a Matriz (tipo==0).
int zeraMatriz (geral matriz[VETORX][VETORY], int x, int y){
	int i, j;
		
	//Transforma toda a matriz em células vazias.
	for(i=0;i<=VETORY;i++){
		for(j=0;j<=VETORY;j++){
			matriz[i][j].tipo = 0;
			matriz[i][j].vida = 0;
			matriz[i][j].direcao = 0;
			matriz[i][j].sprite = ' ';
			} 	
	}
	return 0;
}


//Gera a Fronteira do Tabuleiro (tipo==1).
int geraLimite(geral matriz[VETORX][VETORY], int x, int y){
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
	return 0;
}


//Gera Relíquia(tipo==2).
int geraReliquia (geral matriz[VETORX][VETORY], int x, int y){
	
	//Gera a relíquia em célula fixa do tabuleiro.
	matriz[13][7].tipo = 2;
	matriz[13][7].vida = 1;
	matriz[13][7].sprite = 197;
	
	return 0;
}


//Gera Blocos de Aço (tipo=3).
int geraBloco(geral matriz[VETORX][VETORY], int x, int y){
	
	//Gera os blocos de aço em células fixas do tabuleiro.
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
	
	return 0;
}


//Gera Tijolos Normais (tipo==4).
int geraTijolos (geral matriz[VETORX][VETORY], int x, int y){
	int i, j, var;
	
	srand(time(0));
	
	//Gera a proteção fixa de tijolos da relíquia.
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
	
	
	//Gera tijolos normais em células aleatórias do tabuleiro.
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
	return 0;
}


//Gera Tanque do Jogador Principal (Osório) (tipo==5).
int tanqueOsorio (geral matriz[VETORX][VETORY], int x, int y){
	int i, j;
	
	srand(time(0));

	//Gera tanque do jogador (Osório) em uma célula aleatória do tabuleiro.
	do{
		i = 1 + (rand() % 13);
		j = 1 + (rand() % 13);
		if(matriz[i][j].tipo == 0){
			matriz[i][j].tipo = 5;
			matriz[i][j].vida = 1;
			matriz[i][j].direcao = 1;
			matriz[i][j].sprite = 'O';
		}
	}
	while(matriz[i][j].tipo != 5);
	return 0;
}


//Gera Tanque do Jogador Inimigo (M1 Abrams) (tipo==6).
int tanqueAbrams (geral matriz[VETORX][VETORY], int x, int y){
	int i, j;
	
	srand(time(0));
	
	//Cria tanque do inimigo(M1 Abrans) em célula aleatória do tabuleiro.
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
	return 0;
}


//Gera Tanque do Jogador Inimigo Centurion (tipo==7).
int tanqueCenturion (geral matriz[VETORX][VETORY], int x, int y){
	int i, j;
	
	srand(time(0));
	
	//Cria tanque do inimigo(Centurion) em célula aleatória do tabuleiro.
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
	return 0;
}


//Imprime o Tabuleiro.
int imprimeTabuleiro (geral matriz[VETORX][VETORY], int x, int y){
	int i, j;
	
	//Imprime o tabuleiro através do sprite.
	for(i=0;i<=VETORX;i++){
		for(j=0;j<=VETORY;j++){
			printf("  %c  ", matriz[i][j].sprite);
		}
		printf("\n\n\n");
	}
	return 0;
}


//Estrutura de controle do espaçamento.
int espaco (geral matriz[VETORX][VETORY], int x, int y){
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}





//CÓDIGO DAS FUNÇÕES DE JOGADA=========================================================================================================================================================================================================





//Transporta todas as informações do tanque principal (Osório) para outra célula.
int movimentoOsorio (geral matriz[VETORX][VETORY], int x, int y){
	int i,j,vardirecao,posx,posy;
	
	//Encontrar tanque Osório.
	for(i=0;i<=VETORY;i++){
		for(j=0;j<=VETORY;j++){
			if(matriz[i][j].tipo==5){
				posx = i;
				posy = j;
			}
		}
	}

	
	//Estrutura de controle do espaçamento.
	espaco(matriz,VETORX,VETORY);
	imprimeTabuleiro(matriz,VETORX,VETORY);
	
	//Estrutura do menu de movimento.
	printf("[1] Movimentar Norte.\n[2] Movimentar Sul.\n[3] Movimentar Leste.\n[4] Movimentar Oeste.\n Escolha uma ação: ");
	scanf("%d",&vardirecao);
	
	if(vardirecao==matriz[posx][posy].direcao){	
	
		//Movimenta o tanque para o norte.
		if(vardirecao==1){
								
			if(matriz[posx-1][posy].tipo==0){
				matriz[posx-1][posy].tipo = matriz[posx][posy].tipo;
				matriz[posx-1][posy].vida = matriz[posx][posy].vida;
				matriz[posx-1][posy].direcao = matriz[posx][posy].direcao;
				matriz[posx-1][posy].sprite = matriz[posx][posy].sprite;
				matriz[posx][posy].tipo = 0;
				matriz[posx][posy].vida = 0;
				matriz[posx][posy].direcao = 0;
				matriz[posx][posy].sprite = ' ';
				
				//Estrutura de controle do espaçamento.
				espaco(matriz,VETORX,VETORY);
				
				return 0;  
			}		
			else{
				
				//Estrutura de controle do espaçamento.
				espaco(matriz,VETORX,VETORY);
				
				printf("Obstaculo a frente.\n\n");
				return 0;
			}
		}
							
		//Movimenta o tanque para o sul. 
		if(vardirecao==2){
									
			if(matriz[posx+1][posy].tipo==0){
				matriz[posx+1][posy].tipo = matriz[posx][posy].tipo;
				matriz[posx+1][posy].vida = matriz[posx][posy].vida;
				matriz[posx+1][posy].direcao = matriz[posx][posy].direcao;
				matriz[posx+1][posy].sprite = matriz[posx][posy].sprite;
				matriz[posx][posy].tipo = 0;
				matriz[posx][posy].vida = 0;
				matriz[posx][posy].direcao = 0;
				matriz[posx][posy].sprite = ' ';
				
				//Estrutura de controle do espaçamento.
				espaco(matriz,VETORX,VETORY);
				
				return 0; 
			}
			else{
				
				//Estrutura de controle do espaçamento.
				espaco(matriz,VETORX,VETORY);
				
				printf("Obstaculo a frente.\n\n");
				return 0;
			}
		}
								
		//Movimenta o tanque para o leste.
		if(vardirecao==3){
								
			if(matriz[posx][posy+1].tipo==0){
				matriz[posx][posy+1].tipo = matriz[posx][posy].tipo;
				matriz[posx][posy+1].vida = matriz[posx][posy].vida;
				matriz[posx][posy+1].direcao = matriz[posx][posy].direcao;
				matriz[posx][posy+1].sprite = matriz[posx][posy].sprite;
				matriz[posx][posy].tipo = 0;
				matriz[posx][posy].vida = 0;
				matriz[posx][posy].direcao = 0;
				matriz[posx][posy].sprite = ' ';
				
				//Estrutura de controle do espaçamento.
				espaco(matriz,VETORX,VETORY);
				
				return 0;  
			}
			else{
				
				//Estrutura de controle do espaçamento.
				espaco(matriz,VETORX,VETORY);
				
				printf("Obstaculo a frente.\n\n");
				return 0;
			}
		}
								
		//Movimenta o tanque para o oeste.
		if(vardirecao==4){
									
			if(matriz[posx][posy-1].tipo==0){	
				matriz[posx][posy-1].tipo = matriz[posx][posy].tipo;
				matriz[posx][posy-1].vida = matriz[posx][posy].vida;
				matriz[posx][posy-1].direcao = matriz[posx][posy].direcao;
				matriz[posx][posy-1].sprite = matriz[posx][posy].sprite;
				matriz[posx][posy].tipo = 0;
				matriz[posx][posy].vida = 0;
				matriz[posx][posy].direcao = 0;
				matriz[posx][posy].sprite = ' ';
				
				//Estrutura de controle do espaçamento.
				espaco(matriz,VETORX,VETORY);
				
				return 0;
			}
			else{
				
				//Estrutura de controle do espaçamento.
				espaco(matriz,VETORX,VETORY);
				
				printf("Obstaculo a frente.\n\n");
				return 0;
			}
		}
			
	}
	else{
		
		//Estrutura de controle do espaçamento.
		espaco(matriz,VETORX,VETORY);
		
		if(matriz[posx][posy].direcao==1){
			printf("Direcao incorreta!!! (Norte) \n\n");
		}
		
		if(matriz[posx][posy].direcao==2){
			printf("Direcao incorreta!!! (Sul) \n\n");
		}
		
		if(matriz[posx][posy].direcao==3){
			printf("Direcao incorreta!!! (Leste) \n\n");
		}
		
		if(matriz[posx][posy].direcao==4){
			printf("Direcao incorreta!!! (Oeste) \n\n");
		}
	}
		return 0;
}


//Muda a direção do tanque principal (Osório).
int giraOsorio (geral matriz[VETORX][VETORY], int x, int y){
	int i,j,vargira,posx,posy;
	
	//Estrutura de controle do espaçamento.
	espaco(matriz,VETORX,VETORY);
	imprimeTabuleiro(matriz,VETORX,VETORY);
	
	printf("[1] Girar Norte.\n[2] Girar Sul.\n[3] Girar Leste.\n[4] Girar Oeste.\n Escolha uma acao: ");
	scanf("%d",&vargira);
	
	//Encontrar tanque Osório e muda a direcao
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
		
		//Estrutura de controle do espaçamento.
		espaco(matriz,VETORX,VETORY);
				
	}
	
	if(vargira==2){
		
		matriz[posx][posy].direcao = 2;
		
		//Estrutura de controle do espaçamento.
		espaco(matriz,VETORX,VETORY);
				
	}
	
	if(vargira==3){
		
		matriz[posx][posy].direcao = 3;
		
		//Estrutura de controle do espaçamento.
		espaco(matriz,VETORX,VETORY);
				
	}
	
	if(vargira==4){
		
		matriz[posx][posy].direcao = 4;
		//Estrutura de controle do espaçamento.
		espaco(matriz,VETORX,VETORY);
				
	}
	
	return 0;
}

int atiraOsorio(geral matriz[VETORX][VETORY], int x, int y){
	int i,j,atira,posx,posy,posxi,posyi;
	
	//Estrutura do menu de tiro.
	printf("[1] Atira Norte.\n[2] Atira Sul.\n[3] Atira Leste.\n[4] Atira Oeste.\n Escolha uma acao: ");
	scanf("%d",&atira);
	
	for(i=0;i<=VETORY;i++){
		for(j=0;j<=VETORY;j++){
			if(matriz[i][j].tipo==5){
				posx = i;
				posy = j;
			}
		}
	}
	
	if(atira==matriz[posx][posy].direcao){
		//Atira para o Norte
		if(matriz[posx][posy].direcao==1){
		posyi=posy;
		while(matriz[posx][posyi].tipo=0){
			posyi+=1;
		}
		posyi+=1;
		if(matriz[posx][posyi].tipo==7){
			matriz[posx][posyi].vida=0;
		}
		if(matriz[posx][posyi].tipo==6){
			matriz[posx][posyi].vida=0;
		}
	    if(matriz[posx][posyi].tipo==4){
			matriz[posx][posyi].vida=0;
		}
		if(matriz[posx][posyi].tipo==2){
			matriz[posx][posyi].vida=0;
		}
		espaco(matriz,VETORX,VETORY);
		return 0;
	}
	//Atira para o Sul
		if(matriz[posx][posy].direcao==2){
		posyi=posy;
		while(matriz[posx][posyi].tipo=0){
			posyi+=1;
		}
		posyi+=1;
		if(matriz[posx][posyi].tipo==7){
			matriz[posx][posyi].vida=0;
		}
		if(matriz[posx][posyi].tipo==6){
			matriz[posx][posyi].vida=0;
		}
	    if(matriz[posx][posyi].tipo==4){
			matriz[posx][posyi].vida=0;
		}
		if(matriz[posx][posyi].tipo==2){
			matriz[posx][posyi].vida=0;
		}
		espaco(matriz,VETORX,VETORY);
	    return 0;
	}
	//Atira para o Leste
		if(matriz[posx][posy].direcao==3){
		posxi=posx;
		while(matriz[posxi][posy].tipo=0){
			posxi+=1;
		}
		posxi+=1;
		if(matriz[posx][posyi].tipo==7){
			matriz[posx][posyi].vida=0;
		}
		if(matriz[posx][posyi].tipo==6){
			matriz[posx][posyi].vida=0;
		}
	    if(matriz[posx][posyi].tipo==4){
			matriz[posx][posyi].vida=0;
		}
		if(matriz[posx][posyi].tipo==2){
			matriz[posx][posyi].vida=0;
		}
		espaco(matriz,VETORX,VETORY);
		return 0;
	}
	//Atira para o Oeste
		if(matriz[posx][posy].direcao==4){
		posxi=posx;
		while(matriz[posxi][posy].tipo=0){
			posxi-=1;
		}
		posxi-=1;
		if(matriz[posx][posyi].tipo==7){
			matriz[posx][posyi].vida=0;
		}
		if(matriz[posx][posyi].tipo==6){
			matriz[posx][posyi].vida=0;
		}
	    if(matriz[posx][posyi].tipo==4){
			matriz[posx][posyi].vida=0;
		}
		if(matriz[posx][posyi].tipo==2){
			matriz[posx][posyi].vida=0;
		}
		espaco(matriz,VETORX,VETORY);
		return 0;
	}
	
}
	else{
	//Estrutura de controle do espaçamento.
		espaco(matriz,VETORX,VETORY);
		
		if(matriz[posx][posy].direcao==1){
			printf("Direcao incorreta!!! (Norte) \n\n");
		}
		
		if(matriz[posx][posy].direcao==2){
			printf("Direcao incorreta!!! (Sul) \n\n");
		}
		
		if(matriz[posx][posy].direcao==3){
			printf("Direcao incorreta!!! (Leste) \n\n");
		}
		
		if(matriz[posx][posy].direcao==4){
			printf("Direcao incorreta!!! (Oeste) \n\n");
		}
		espaco(matriz,VETORX,VETORY);
		return 0;
	}
	return 0;
}

int destroi(geral matriz[VETORX][VETORY], int x, int y){
	int posx,posy;
	
	if(matriz[posx][posy].vida==0){
		matriz[posx][posy].tipo=0;
		matriz[posx][posy].sprite=' ';
		return 0;
	}
	return 0;
}


