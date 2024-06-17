#include <iostream>
using namespace std;

class Conta {
public:
    string nome;
    string senha;
    string senhas[100];
    int totalSenhas;

    Conta() {
        totalSenhas = 0;
    }

    void registrarConta(const string& n, const string& s) {
        nome = n;
        senha = s;
    }

    bool verificarLogin(const string& n, const string& s) {
        return nome == n && senha == s;
    }

    void adicionarSenha(const string& novaSenha) {
        if (totalSenhas < 100) {
            senhas[totalSenhas++] = novaSenha;
            cout << "Senha adicionada com sucesso\n";
        } else {
            cout << "Limite de senhas atingido\n";
        }
    }

    void mostrarSenhas() const {
        if (totalSenhas == 0) {
            cout << "Nenhuma senha armazenada\n";
        } else {
            cout << "Suas senhas:\n";
            for (int i = 0; i < totalSenhas; i++) {
                cout << senhas[i] << endl;
            }
        }
    }
};

int main() {
    Conta conta;
    while (true) {
        cout << "Bem vindo ao entre com sua conta!\ncaso não tenha registre-se\nDigite 1 para entrar com sua conta\nDigite 2 para registrar-se\nDigite 0 para sair\n";
        int opcao;
        cin >> opcao;
        if (opcao == 0) {
            break;
        }
        if (opcao == 1) {
            cout << "Digite seu nome de usuario\n";
            string nometentativa;
            cin >> nometentativa;
            cout << "Digite sua senha\n";
            string senhaTentativa;
            cin >> senhaTentativa;
            if (conta.verificarLogin(nometentativa, senhaTentativa)) {
                cout << "Login bem sucedido\n";
                while (true) {
                    cout << "Bem-vindo ao gerenciador de senhas\nDigite 1 para adicionar uma senha\nDigite 2 para ver suas senhas\nDigite 0 para sair\n";
                    int opcaoGerenciador;
                    cin >> opcaoGerenciador;
                    if (opcaoGerenciador == 0) {
                        break;
                    } else if (opcaoGerenciador == 1) {
                        cout << "Digite daonde e a senha que deseja adicionar (ex. insta-123)\n";
                        string novaSenha;
                        cin >> novaSenha;
                        conta.adicionarSenha(novaSenha);
                    } else if (opcaoGerenciador == 2) {
                        conta.mostrarSenhas();
                    } else {
                        cout << "Opção inválida, por favor tente novamente\n";
                    }
                }
            } else {
                cout << "Senha incorreta ou conta não registrada\n";
            }
        } else if (opcao == 2) {
            cout << "Digite seu nome de usuario\n";
            string nome;
            cin >> nome;
            cout << "Registre uma senha para a conta\n";
            string senha;
            cin >> senha;
            conta.registrarConta(nome, senha);
            cout << "Conta registrada com sucesso\n";
        } else {
            cout << "Opção inválida, por favor tente novamente\n";
        }
        cout << "Digite 0 para voltar ao menu caso queira sair digite qualquer coisa\n";
        int opcao2;
        cin >> opcao2;
        if (opcao2 != 0) {
            break;
        }
    }
    return 0;
}
