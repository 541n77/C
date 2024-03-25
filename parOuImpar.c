#include <stdio.h>
#include <stdlib.h>

void welcome();
void menu();
void game(char opPlayer);
void continuar();
void resultado();

char option;
char opPlayer;
int numPlayer;
int numPcPlayer;
int result;
int sair = 1;
char continuarOp;
int playerCount;
int pcCount;


int main(){
    welcome();
    do{
        menu();
        game(opPlayer);
        continuar();
    } while(sair != 0);
    resultado();

    return 0;
}

void welcome(){
    printf("-----------------------------\n");
    printf("--- Programa Par ou Impar ---\n");
    printf("-----------------------------\n");
}
void menu(){
    printf("Você quer ser (p)par ou (i)impar?\n");
    scanf(" %c", &option);
    if (option == 'p' || option == 'i'){
        opPlayer = option;
    } else {
        printf("Insira uma opção válida!\n");
        menu();
    }
}
void game(char opPlayer){
    printf("Insira um número: ");
    scanf("%d", &numPlayer);
    numPcPlayer = rand() % 100;

    result = numPlayer + numPcPlayer;

    if (((result % 2) == 0 && opPlayer == 'p') || ((result % 2) != 0 && opPlayer == 'i')){
        printf("Resultado: %d \n", result);
        printf("Você Ganhou!\n");
        playerCount++;
    }else {
        printf("Resultado: %d \n", result);
        printf("Computador Ganhou!\n");
        pcCount++;
    }
}
void continuar(){
    printf("\nDeseja continuar a jogar? (s)Sim || (n)Não\n");
    scanf(" %c", &continuarOp);
    if (continuarOp == 'n'){
        sair = 0;
    } else if (continuarOp != 's'){
        printf("Insira uma opção válida!");
        continuar();
    }
}
void resultado(){
    printf("\nResultado: Jogador %d vitórias || Computador %d vitórias\n", playerCount, pcCount);
    if (playerCount > pcCount){
        printf("Parabéns, você ganhou o jogo!");
    } else if(playerCount < pcCount){
        printf("Infelizmente não foi dessa vez! o Computador ganhou!");
    } else{
        printf("Jogo acirrado! Empate!");
    }
}
