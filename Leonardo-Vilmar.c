// Leonardo Costa 
// Vilmar Rangel

#include <stdio.h>
#include <pthread.h>

#define QTDE_FRASE 2
#define TAM_FRASE 99

void *ThreadFrase(void *arg) {
    printf("%s\n", arg);
    return NULL;
}

int main() {

    char frases[QTDE_FRASE][TAM_FRASE] = {"Instituto", "Programacao"};
    pthread_t threads[QTDE_FRASE];

    int i;
    for (i = 0; i < QTDE_FRASE; i += 1) {
        pthread_create(&(threads[i]), NULL, ThreadFrase, frases[i]);
    }

    for (i = 0; i < QTDE_FRASE; i += 1) {
        pthread_join(threads[i], NULL);
    }
    printf("Fim\n");
    return 0;
}
