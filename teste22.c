// Leonardo Costa 
// Vilmar Rangel
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void *ThreadSoma(int *arg) {
    int soma = arg[0] + arg[1];
    printf("Eu sou a thread SOMA (%d) e irei dormir por %d segundos\n",soma, 10);
    sleep(10);
    printf("Eu sou a Thread SOMA (%d). Já se passaram %d segundos, então terminei!\n",soma, 10);
    printf("\n");
    return NULL;
}
void *ThreadMultiplica(int *arg) {
    int multiplicacao = arg[0] * arg[1];
    printf("Eu sou a thread MULTIPLICA (%d) e irei dormir por %d segundos\n",multiplicacao, 4);
    sleep(4);
    printf("Eu sou a Thread MULTIPLICA (%d). Já se passaram %d segundos, então terminei!\n",multiplicacao, 4);
    printf("\n");
    return NULL;
}
void *ThreadDivide(int *arg) {
    int divisao = arg[0] / arg[1];
    printf("Eu sou a thread DIVISAO (%d) e irei dormir por %d segundos\n",divisao, 7);
    sleep(7);
    printf("Eu sou a Thread DIVISAO (%d). Já se passaram %d segundos, então terminei!\n",divisao, 7);
    printf("\n");
    return NULL;
}
void *ThreadSubtrai(int *arg1) {
    int subtracao = arg[0] - arg[1];
    printf("Eu sou a thread SUBTRACAO (%d) e irei dormir por %d segundos\n",subtracao, 13);
    sleep(13);
    printf("\n");
    printf("Eu sou a Thread SUBTRACAO (%d). Já se passaram %d segundos, então terminei!\n",subtracao, 13);
    return NULL;
}
int main() {
    int numeros[2];
    printf("Digite um numero inteiro !=0:");
    scanf("%d",&numeros[0]);
    printf("Digite um numero inteiro !=0:");    
    scanf("%d",&numeros[1]);
    pthread_t tDivisao, tSoma,tMultiplicacao,tSubtracao;
    pthread_create(&(tSoma), NULL, ThreadSoma, numeros);
    pthread_create(&(tMultiplicacao), NULL, ThreadMultiplica, numeros);
    pthread_create(&(tDivisao), NULL, ThreadDivide, numeros);
    pthread_create(&(tSubtracao), NULL, ThreadSubtrai, numeros);

    pthread_join(tSoma, NULL);
    pthread_join(tMultiplicacao, NULL);
    pthread_join(tDivisao, NULL);
    pthread_join(tSubtracao, NULL);
    return 0;
}
