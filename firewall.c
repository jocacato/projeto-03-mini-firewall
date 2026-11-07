#include <stdio.h>

int main(void) {
    int liberadas[4] = {22, 53, 80, 443};
    int solicitacoes[8];
    int n;
    int permitidas = 0;
    int bloqueadas = 0;
    int i, j;

    do {
        printf("Quantas solicitacoes (1 a 8)? ");
        if (scanf("%d", &n) != 1) {
            printf("Entrada invalida. Tente novamente.\n");
            while (getchar() != '\n');
            n = 0;
        }
    } while (n < 1 || n > 8);

    for (i = 0; i < n; i++) {
        do {
            printf("Porta da solicitacao %d (1 a 65535): ", i + 1);
            if (scanf("%d", &solicitacoes[i]) != 1) {
                printf("Porta invalida. Tente novamente.\n");
                while (getchar() != '\n');
                solicitacoes[i] = 0;
            }
        } while (solicitacoes[i] < 1 || solicitacoes[i] > 65535);
    }

    printf("\n--- RESULTADO ---\n");
    for (i = 0; i < n; i++) {
        int encontrada = 0;

        for (j = 0; j < 4; j++) {
            if (solicitacoes[i] == liberadas[j]) {
                encontrada = 1;
                break;
            }
        }

        if (encontrada) {
            printf("Porta %d: PERMITIDA\n", solicitacoes[i]);
            permitidas++;
        } else {
            printf("Porta %d: BLOQUEADA\n", solicitacoes[i]);
            bloqueadas++;
        }
    }

    printf("\nPermitidas: %d | Bloqueadas: %d\n", permitidas, bloqueadas);
    return 0;
}
