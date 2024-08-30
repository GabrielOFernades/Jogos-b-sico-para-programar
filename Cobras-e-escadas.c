#include<stdio.h>
#include<time.h>
	
void criar_tabuleiro(int tabuleiro[10][10]);
void imprimir_tabuleiro(int tabuleiro[10][10], int posicao, int player);
int jogar_dado(void);
int jogada(int posicao, int tabuleiro[10][10]);
	
int main(void)
{
	int tabuleiro[10][10], vitoria[2] = {0}, opc = 0, pos_p1 = 0, pos_p2 = 0;
	
	criar_tabuleiro(tabuleiro);
	
	
	imprimir_tabuleiro(tabuleiro, pos_p1, 0);
	
	while(pos_p1 != 100 && pos_p1 != 100)
	{
		
		printf("1 - Jogador [1]\t2 - Jogador[2]\n");
		printf("Digite o numero do jogador que ira jogar: ");
		scanf("%d", &opc);
		
		switch(opc)
		{
			case 1:
				system("cls");
				pos_p1 = jogada(pos_p1, tabuleiro);
				imprimir_tabuleiro(tabuleiro, pos_p1, 1);			
			break;
			
			case 2:
				system("cls");
				pos_p2 = jogada(pos_p2, tabuleiro);
				imprimir_tabuleiro(tabuleiro, pos_p2, 2);
			break;
		}
	}
	
	if(pos_p1 == 100)
	{
		system("cls");
		printf("JOGADOR 1 VENCEU!!!\n\n");
	}
	else
	{
		system("cls");
		printf("JOGADOR 2 VENCEU!!!\n\n");
	}
	
	system("pause");
	return 0;
}

void criar_tabuleiro(int tabuleiro[10][10])
{
	int i, j, num_holder = 99, placeholder, flag;
	
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			tabuleiro[i][j] = num_holder+1;
			num_holder -= 1;
		}
	}

	for(i = 1; i < 10; i++)
	{
		if(i % 2 != 0)
		{		
			for(j = 0; j < 5; j++)
			{
				placeholder = tabuleiro[i][j];
				tabuleiro[i][j] = tabuleiro[i][9-j];
				tabuleiro[i][9-j] = placeholder;
			}
		}
	}
}

void imprimir_tabuleiro(int tabuleiro[10][10], int posicao, int player)
{
	int i, j;
	
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			if(posicao == tabuleiro[i][j])
			{
				printf(" -P0%d-", player);
			}
			else
			{
				printf("  %.3d  ", tabuleiro[i][j]);	
			}
			
		}
		printf("\n");
	}
	
	printf("\n\n");
}

int jogada(int posicao, int tabuleiro[10][10])
{
	int jogada = 0, i, j, flag = 0;
	jogada = (rand() % 6) + 1;
	
	printf("Voce jogou: %d\n", jogada);
	
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{	
			if(tabuleiro [i][j] == (posicao + jogada))
			{
				posicao += jogada;
			}
			else if((posicao + jogada) > 100)
			{
				printf("\t\tPassou Dos 100\n");
				return posicao;
			}
			else if((posicao+jogada) == 100)
			{
				printf("\t\tVOCE VENCEU!\n\n\n");
				return 100;
			}
		}
	}
	
	switch(posicao)
	{
		case 12:
			posicao = 67;
		break;
		
		case 68:
			posicao = 91;
		break;
		
		case 25:
			posicao = 6;
		break;
		
		case 47:
			posicao = 19;
		break;
		
		case 39:
			posicao = 58;
		break;
		
		case 88:
			posicao = 75;
		break;
		
		case 77:
			posicao = 59;
		break;
		
		case 78:
			posicao = 100;
		break;
	}
	
	return posicao;
}
