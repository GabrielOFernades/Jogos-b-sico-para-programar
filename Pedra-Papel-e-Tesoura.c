#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void imprimir_pedraXPedra(void);
void imprimir_pedraXPapel(void);
void imprimir_pedraXTesoura(void);

void imprimir_papelXPedra(void);
void imprimir_papelXPapel(void);
void imprimir_papelXTesoura(void);

void imprimir_tesouraXPedra(void);
void imprimir_tesouraXPapel(void);
void imprimir_tesouraXTesoura(void);

void imprimir_vitoria(void);
void imprimir_derrota(void);
void imprimir_empate(void);

int imprimir_partida(int jogada_jogador, int pontos);
int imprimir_menu_inicio(void);
int imprimir_opcao_de_jogada(void);
void opcoes_de_jogada(int opcao);

int main(void)
{
	int vitoria = 0, opcao, pontos = 0, jogada_jogador, finalizar_jogo = 1;
	
	opcao = imprimir_menu_inicio();
	
	switch(opcao)
	{
		case 0:
			printf("Finalizando Programa!\n");
			return 0;
		break;
		
		case 1:
			rejogar:
			jogada_jogador = imprimir_opcao_de_jogada();
			pontos += imprimir_partida(jogada_jogador, pontos);
				
			check:
			printf("\n\nDeseja continuar?\n[0] - Sair\t[1] - continuar\nResposta:");
			scanf("%d", &finalizar_jogo);
			
			if(finalizar_jogo == 1)
				goto rejogar;
			else if(finalizar_jogo == 0)
				return 0;
			else
			{
				system("cls");
				printf("Opcao Invalida!\n");
				goto check;
			}	
		break;
	}
}

int imprimir_menu_inicio(void)
{
	int opcao = -1;
	while(opcao < 0 || opcao > 1)
	{
		system("cls");
		printf("--------------------------\n");
		printf(" Digite a opcao desejada\n\n");
		printf("0 - sair   1 - Comecar jogo\n");
		printf("-------------------------\n\n");
		printf("Resposta: ");
		scanf("%d", &opcao);
	}	
	return opcao;
}

int imprimir_opcao_de_jogada(void)
{
	int opcao = -1;
	while(opcao < 1 || opcao > 3)
	{
		system("cls");
		printf("-------------------------\n");
		printf(" Digite a opcao desejada\n\n");
		printf("   1 - Pedra  2 - Papel   \n");
		printf("      3 - Tesoura         \n");
		printf("-------------------------\n\n");
		printf("Resposta: ");
		scanf("%d", &opcao);
	}	
	return opcao;
}

int imprimir_partida(int jogada_jogador, int pontos)
{
	system("cls");
	int jogada_maquina;
	srand(time(NULL));
	jogada_maquina = rand() % 3;
	jogada_maquina++;
	
	printf("Pontos: %d\n", pontos);
	switch(jogada_jogador)
	{
		//imprimir jogadas com o jogador tendo escolhido PEDRA
		case 1:
			switch(jogada_maquina)
			{
				case 1:
					imprimir_pedraXPedra();
					imprimir_empate();
				break;
				
				case 2:
					imprimir_pedraXPapel();
					imprimir_derrota();
				break;
				
				case 3:
					imprimir_pedraXTesoura();
					imprimir_vitoria();
					system("pause");
					return 1;
				break;
			}
		break;
		
		//imprimir jogadas com o jogador tendo escolhido PAPEL
		case 2:
			switch(jogada_maquina)
			{
				case 1:
					imprimir_papelXPedra();
					imprimir_vitoria();
				break;
				
				case 2:
					imprimir_papelXPapel();
					imprimir_empate();
				break;
				
				case 3:
					imprimir_papelXTesoura();
					imprimir_derrota();
					system("pause");
					return 1;
				break;
			}
		break;
			
		//imprimir jogadas com o jogador tendo escolhido TESOURA
		case 3:
			switch(jogada_maquina)
			{
				case 1:
					imprimir_tesouraXPedra();
					imprimir_derrota();
				break;
				
				case 2:
					imprimir_tesouraXPapel();
					imprimir_vitoria();
					system("pause");
					return 1;
										
					
				break;
				
				case 3:
					imprimir_tesouraXTesoura();
					imprimir_empate();
				break;
			}
		break;
	}
	system("pause");
	return 0;
}

void imprimir_vitoria(void)
{
	printf("\n");
printf(" _____                _____                     \n");
printf("|  |  |___ ___ ___   |  |  |___ ___ ___ ___ _ _ \n");
printf("|  |  | . |  _| -_|  |  |  | -_|   |  _| -_| | |\n");
printf(" \\___/|___|___|___|   \\___/|___|_|_|___|___|___|\n");
                                                
}

void imprimir_derrota(void)
{
	printf("\n");
	printf(" _____                _____           _         \n");
	printf("|  |  |___ ___ ___   |  _  |___ ___ _| |___ _ _ \n");
	printf("|  |  | . |  _| -_|  |   __| -_|  _| . | -_| | |\n");
	printf(" \\___/|___|___|___|  |__|  |___|_| |___|___|___|\n");
}

void imprimir_empate(void)
{
	printf("\n");
	printf(" _____ _____ _____ _____ _____ _____ \n");
	printf("|   __|     |  _  |  _  |_   _|   __|\n");
	printf("|   __| | | |   __|     | | | |   __|\n");
	printf("|_____|_|_|_|__|  |__|__| |_| |_____|\n");
}

void imprimir_pedraXPedra(void)
{
	printf("    _______          _______    \n");
	printf("---'   ____)        (____   '---\n");
	printf("      (_____)      (_____)      \n");
	printf("      (____)        (____)      \n");
	printf("      (____)        (____)      \n");
	printf("---.__(___)          (___)__.---\n");
}

void imprimir_pedraXPapel(void)
{	
	printf("    _______              _______    \n");
	printf("---'   ____)        ____(____   '---\n");
	printf("      (_____)      (______          \n");
	printf("      (_____)      (_______         \n");
	printf("      (____)        (_______        \n");
	printf("---.__(___)          (__________.---\n");
}

void imprimir_pedraXTesoura(void)
{
printf("    _______             _______    \n");
printf("---'   ____)       ____(____   '---\n");
printf("      (_____)     (______          \n");
printf("      (_____)    (__________       \n");
printf("      (____)          (____)       \n");
printf("---.__(___)             (___)__.---\n");
	
}

void imprimir_tesouraXPedra(void)
{
	printf("    _______              _______    \n");
	printf("---'   ____)____        (____   '---\n");
	printf("          ______)      (_____)      \n");
	printf("       __________)     (_____)      \n");
	printf("      (____)            (____)      \n");
	printf("---.__(___)              (___)__.---\n");
	printf("\n");
}

void imprimir_tesouraXPapel(void)
{
	printf("    _______                  _______    \n");
	printf("---'   ____)____        ____(____   '---\n");
	printf("          ______)      (______          \n");
	printf("       __________)     (______          \n");
	printf("      (____)            (_______        \n");
	printf("---.__(___)              (__________.---\n");
	printf("\n");
}

void imprimir_tesouraXTesoura(void)
{
	printf("    _______                  _______    \n");
	printf("---'   ____)____        ____(____   '---\n");
	printf("          ______)      (______          \n");
	printf("       __________)    (__________       \n");
	printf("       (____)              (____)       \n");
	printf("---.__(___)                  (___)__.---\n");
	printf("\n");
}

void imprimir_papelXPedra(void)
{
	printf("    _______               _______    \n");
	printf("---'    ____)____        (____   '---\n");
	printf("           ______)      (_____)      \n");
	printf("          _______)      (_____)      \n");
	printf("         _______)        (____)      \n");
	printf("---.__________)           (___)__.---\n");
}

void imprimir_papelXPapel(void)
{
	printf("    _______                  _______    \n");
	printf("---'   ____)____        ____(____   '---\n");
	printf("          ______)      (______          \n");
	printf("         _______)      (_______         \n");
	printf("        _______)        (_______        \n");
	printf("---.__________)          (__________.---\n");
}

void imprimir_papelXTesoura(void)
{
	printf("    ______                   _______    \n");
	printf("---'  ____)____         ____(____   '---\n");
	printf("           ______)     (______          \n");
	printf("          _______)     (__________      \n");
	printf("         _______)           (____)      \n");
	printf("---.__________)              (___)__.---\n");
}

