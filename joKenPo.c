#include <stdio.h>
#include <windows.h>
#include <math.h>

void welcome();
void options();
void game();
void continuar();

int opPlayer;
int opComputer;
char opPlayerString[10];
char opComputerString[10];
int playerCount = 0;
int computerCount = 0;
int finish = 1;

int main(){
    welcome();
    do{
      options();
      game();
      continuar();
    } while (finish != 2);
    result();
}
void welcome(){
    printf("--------------------------------------\n");
    printf("--- Jogo do Pedra,Papel ou Tesoura ---\n");
    printf("--------------------------------------\n");
    printf("");
}
void options(){
    printf("Selecione uma opção: \n");
    printf("1-Pedra 2-Papel 3-Tesoura\n");
    scanf("%d", &opPlayer);

    switch (opPlayer){
        case 1:
            strcpy(opPlayerString, "Pedra");
            break;
        case 2:
            strcpy(opPlayerString, "Papel");
            break;
        case 3:
            strcpy(opPlayerString, "Tesoura");
            break;
        default:
            printf("Digite uma opção válida!");
            options();
    }

    opComputer = rand()%2;

    switch (opComputer){
        case 0:
            strcpy(opComputerString, "Pedra");
            break;
        case 1:
            strcpy(opComputerString, "Papel");;
            break;
        case 2:
            strcpy(opComputerString, "Tesoura");
            break;
    }
}
void game(){
    printf("Jo... ");
    sleep(1);
    printf("Ken...");
    sleep(1);
    printf("Po!\n");

    printf("Você: %s || Computador: %s\n", opPlayerString, opComputerString);

    opPlayer--;
    if ((opPlayer == 0 && opComputer == 2) || (opPlayer == 1 && opComputer == 0) || (opPlayer == 2 && opComputer == 1)){
        printf("Você Ganhou!");
        playerCount++;
    } else if (opPlayer == opComputer){
        printf("Empatou!");
    } else{
        printf("Computador ganhou!");
        computerCount++;
    }
}
void continuar(){
    printf("\nDeseja continuar a jogar? 1-Continuar 2-Sair\n");
    scanf(" %d", &finish);
    if (finish != 1 && finish != 2){
        printf("Por Favor, Digite uma opção válida");
        continuar();
    }
}
void result(){
    printf("\nVocê ganhou %d vezes | Computador ganhou %d vezes\n", playerCount, computerCount);
    (playerCount > computerCount) ? printf("Parabéns, vocêe ganhou o jogo!") : (playerCount == computerCount) ? printf("O jogo empatou!") : printf("Você perdeu! O computador ganhou!");
}
