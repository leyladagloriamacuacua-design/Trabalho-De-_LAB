#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encriptar(string texto) {
    for(int i = 0; i < texto.length(); i++) {
        texto[i] = texto[i] + 3;
    }
    return texto;
}

string desencriptar(string texto) {
    for(int i = 0; i < texto.length(); i++) {
        texto[i] = texto[i] - 3;
    }
    return texto;
}

int main() {

    int opcao;
    string mensagem;
    string chave;

    do {

        cout << "\n===== DIARIO SECRETO =====\n";
        cout << "1 - Escrever mensagem\n";
        cout << "2 - Ler mensagem\n";
        cout << "3 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;
        cin.ignore();

        if(opcao == 1) {

            cout << "Digite sua mensagem: ";
            getline(cin, mensagem);

            mensagem = encriptar(mensagem);

            ofstream ficheiro("diario.txt");
            ficheiro << mensagem;
            ficheiro.close();

            cout << "Mensagem guardada com sucesso!\n";
        }

        else if(opcao == 2) {

            cout << "Digite a chave: ";
            getline(cin, chave);

            if(chave == "1234") {

                ifstream ficheiro("diario.txt");
                getline(ficheiro, mensagem);
        ficheiro.close();

                mensagem = desencriptar(mensagem);

                cout << "Mensagem secreta: " << mensagem << endl;
            }

            else {
                cout << "Chave incorreta!\n";
            }
        }

    } while(opcao != 3);

    cout << "Programa encerrado.\n";

    return 0;
}
