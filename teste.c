#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int segundos = time(0);
    srand(segundos);
    int numgrande = rand();
    int secreto = numgrande % 100;
    
    int chute = 0;
    int tentativa = 1;
    double pontos = 100;
    int acertou;

    int nivel;
    int numtentativas;
    printf("Qual o nível de dificuldade você quer jogar?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\nEscolha: ");
    scanf("%d",&nivel);

    switch (nivel) {
    case 1:
        numtentativas = 20;
        break;
    case 2:
        numtentativas = 10;
    default:
        numtentativas = 5;
        break;
    }

    for (int i = 0; i < numtentativas; i++){
        printf("Tentativa: %d\n",tentativa);
        printf("Adivinhe o número: ");
        scanf("%d",&chute);

        acertou = (chute == secreto);
        if (chute < 0) {
            printf("Você não pode chutar números negativos!");
            continue;
        }
        
        if (acertou) {
            break;
        } else{
            if (i == (numtentativas -1)) {
                break;
            }
            
            printf("Tente novamente!\n");
            if(chute > secreto) {
                printf("Chute mais baixo!\n\n");
            } else {
                printf("Chute mais alto!\n\n");
            }
        }
        tentativa++;

        double pontosperdidos = abs(chute - secreto) / (double) 2;
        pontos -= pontosperdidos;
    }
    

    if (acertou) {
        printf("Parabéns, você ganhou em %d tentativa(s)!\n",tentativa);
        printf("Total de Pontos: %.2f\n",pontos);
    } else {
        printf("Você perdeu! Tente novamente\n");
    } 
}