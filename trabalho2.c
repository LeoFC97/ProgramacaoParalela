// Leonardo Costa
// Vilmar Rangel
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

void* ThreadSoma(int* args) {
    int soma = args[0] + args[1];
    int tempoSleep = args[2];
    printf("Eu sou a thread SOMA (%d) e irei dormir por %d segundos\n", soma, tempoSleep);
    sleep(tempoSleep);
    printf("Eu sou a Thread SOMA (%d). Ja se passaram %d segundos, entao terminei!\n", soma, tempoSleep);
    return NULL;
}
void* ThreadMultiplica(int* args) {
    int multiplicacao = args[0] * args[1];
    int tempoSleep = args[2];
    printf("Eu sou a thread MULTIPLICA (%d) e irei dormir por %d segundos\n", multiplicacao, tempoSleep);
    sleep(tempoSleep);
    printf("Eu sou a Thread MULTIPLICA (%d). Ja se passaram %d segundos, entao terminei!\n", multiplicacao, tempoSleep);
    return NULL;
}
void* ThreadDivide(int* args) {
    int divisao = args[0] / args[1];
    int tempoSleep = args[2];
    printf("Eu sou a thread DIVISAO (%d) e irei dormir por %d segundos\n", divisao, tempoSleep);
    sleep(tempoSleep);
    printf("Eu sou a Thread DIVISAO (%d). Ja se passaram %d segundos, entao terminei!\n", divisao, tempoSleep);
    return NULL;
}

void* ThreadSubtrai(int* args) {
    int subtracao = args[0] - args[1];
    int tempoSleep = args[2];
    printf("Eu sou a thread SUBTRACAO (%d) e irei dormir por %d segundos\n", subtracao, tempoSleep);
    sleep(tempoSleep);
    printf("Eu sou a Thread SUBTRACAO (%d). Ja se passaram %d segundos, entao terminei!\n", subtracao, tempoSleep);
    return NULL;
}
int main() {
    srand(time(0));
    int numeros[3];
    printf("Digite um numero inteiro > 0:");
    scanf("%d", &numeros[0]);
    printf("Digite um numero inteiro > 0:");
    scanf("%d", &numeros[1]);
    pthread_t tDivisao, tSoma, tMultiplicacao, tSubtracao;
    numeros[2] = rand() % 20 + 1;
    printf("\n rand atual: \t %d",numeros[2] );
    pthread_create(&(tSoma), NULL, ThreadSoma, numeros);
    numeros[2] = rand() % 20 + 1;
    pthread_create(&(tMultiplicacao), NULL, ThreadMultiplica, numeros);
    numeros[2] = rand() % 20 + 1;
    pthread_create(&(tDivisao), NULL, ThreadDivide, numeros);
    numeros[2] = rand() % 20 + 1;
    pthread_create(&(tSubtracao), NULL, ThreadSubtrai, numeros);

    pthread_join(tSoma, NULL);
    pthread_join(tMultiplicacao, NULL);
    pthread_join(tDivisao, NULL);
    pthread_join(tSubtracao, NULL);
    return 0;
}