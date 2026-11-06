#include <iostream>
using namespace std;

int main() {
    int liberadas[4] = {22, 53, 80, 443};
    int solicitacoes[8];
    int n;
    int permitidas = 0;
    int bloqueadas = 0;

    // Validar quantidade de solicitacoes
    do {
        cout << "Quantas solicitacoes (1 a 8)? ";
        cin >> n;
        if (n < 1 || n > 8) {
            cout << "Entrada invalida. Tente novamente." << endl;
        }
    } while (n < 1 || n > 8);

    // Ler e validar cada porta
    for (int i = 0; i < n; i++) {
        do {
            cout << "Porta da solicitacao " << i + 1 << " (1 a 65535): ";
            cin >> solicitacoes[i];
            if (solicitacoes[i] < 1 || solicitacoes[i] > 65535) {
                cout << "Porta invalida. Tente novamente." << endl;
            }
        } while (solicitacoes[i] < 1 || solicitacoes[i] > 65535);
    }

    // Decidir: pesquisar cada porta no vetor de liberadas
    cout << endl << "--- RESULTADO ---" << endl;
    for (int i = 0; i < n; i++) {
        bool encontrada = false;
        for (int j = 0; j < 4; j++) {
            if (solicitacoes[i] == liberadas[j]) {
                encontrada = true;
            }
        }
        if (encontrada) {
            cout << "Porta " << solicitacoes[i] << ": PERMITIDA" << endl;
            permitidas = permitidas + 1;
        } else {
            cout << "Porta " << solicitacoes[i] << ": BLOQUEADA" << endl;
            bloqueadas = bloqueadas + 1;
        }
    }

    cout << endl << "Permitidas: " << permitidas << " | Bloqueadas: " << bloqueadas << endl;
    return 0;
}
