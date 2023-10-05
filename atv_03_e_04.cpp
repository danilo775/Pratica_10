#include <iostream>
#include <vector>
#include <string>

using namespace std;

void continuaAdd(vector<float>& notas, vector<string>& nomes, int& total);
void excluir(vector<float>& notas, vector<string>& nomes, int& total);
void alteracaoNotas(int n,vector<float>& notas, vector<string>& nomes);

int main() {
    int total;
    vector<float> notas;
    vector<string> nomes;

    cout << "Digite o total de alunos: ";
    cin >> total;

    for (int i = 0; i < total; i++) {
        string nome;
        float nota1, nota2;

        cout << "Digite o nome do aluno " << i + 1 << ": ";
        cin >> nome;

        cout << "Digite a primeira nota do aluno " << i + 1 << ": ";
        cin >> nota1;

        cout << "Digite a segunda nota do aluno " << i + 1 << ": ";
        cin >> nota2;

        nomes.push_back(nome);
        notas.push_back(nota1);
        notas.push_back(nota2);
    }

    int n = total;
    bool trocou;

    do {
        trocou = false;
        for (int i = 0; i < n - 1; i++) {
            if (nomes[i] > nomes[i + 1]) {
                swap(nomes[i], nomes[i + 1]);
                swap(notas[i * 2], notas[(i + 1) * 2]);
                swap(notas[i * 2 + 1], notas[(i + 1) * 2 + 1]);
                trocou = true;
            }
        }
        n--;
    } while (trocou);
  
    continuaAdd(notas, nomes, total);
    excluir(notas, nomes, total);
    alteracaoNotas(total,notas, nomes);
    
    return 0;
}

void continuaAdd(vector<float>& notas, vector<string>& nomes, int& total) {
    char incluirAluno;

    do {
        cout << "\nDados dos alunos:\n";
        for (int i = 0; i < total; i++) {
            cout << "Aluno: " << nomes[i] << endl;
            cout << "Nota 1: " << notas[i * 2] << endl;
            cout << "Nota 2: " << notas[i * 2 + 1] << endl;
            float media = (notas[i * 2] + notas[i * 2 + 1]) / 2;
            cout << "Media: " << media << endl;
            if (media >= 7) {
                cout << "Situacao: Aprovado" << endl;
            } else {
                cout << "Situacao: Reprovado" << endl;
            }
            cout << "-----------------------\n";
        }

        cout << "Deseja incluir mais alunos (s/n)? ";
        cin >> incluirAluno;

        if (incluirAluno == 's' || incluirAluno == 'S') {
            string nome;
            float nota1, nota2;

            cout << "Digite o nome do novo aluno: ";
            cin >> nome;

            cout << "Digite a primeira nota do novo aluno: ";
            cin >> nota1;

            cout << "Digite a segunda nota do novo aluno: ";
            cin >> nota2;

            nomes.push_back(nome);
            notas.push_back(nota1);
            notas.push_back(nota2);

            int n = total;
            bool trocou;

            do {
                for (int i = 0; i < n - 1; i++) {
                    if (nomes[i] > nomes[i + 1]) {
                        swap(nomes[i], nomes[i + 1]);
                        swap(notas[i * 2], notas[(i + 1) * 2]);
                        swap(notas[i * 2 + 1], notas[(i + 1) * 2 + 1]);
                        trocou = true;
                    }
                }
                n--;
            } while (trocou);

            total++;
        }
    } while (incluirAluno == 's' || incluirAluno == 'S');
}
void excluir(vector<float>& notas, vector<string>& nomes, int& total) {
    char excluirAluno;

    do {
        cout << "\nDados dos alunos:\n";
        for (int i = 0; i < total; i++) {
            cout << "Aluno: " << nomes[i] << endl;
            cout << "Nota 1: " << notas[i * 2] << endl;
            cout << "Nota 2: " << notas[i * 2 + 1] << endl;
            float media = (notas[i * 2] + notas[i * 2 + 1]) / 2;
            cout << "Media: " << media << endl;
            if (media >= 7) {
                cout << "Situacao: Aprovado" << endl;
            } else {
                cout << "Situacao: Reprovado" << endl;
            }
            cout << "-----------------------\n";
        }

        cout << "Deseja excluir algum aluno (s/n)? ";
        cin >> excluirAluno;

        if (excluirAluno == 's' || excluirAluno == 'S') {
            string nomeExcluir;
            cout << "Digite o nome do aluno a ser excluido: ";
            cin >> nomeExcluir;

            bool encontrado = false;

            vector<float> notasTemp;
            vector<string> nomesTemp;

            for (int i = 0; i < total; i++) {
                if (nomes[i] != nomeExcluir) {
                    notasTemp.push_back(notas[i * 2]);
                    notasTemp.push_back(notas[i * 2 + 1]);
                    nomesTemp.push_back(nomes[i]);
                } else {
                    encontrado = true;
                }
            }

            if (encontrado) {
                notas = notasTemp;
                nomes = nomesTemp;
                total--;
                cout << "Aluno excluido com sucesso." << endl;
            } else {
                cout << "Aluno não encontrado." << endl;
            }
        }
    } while (excluirAluno == 's' || excluirAluno == 'S');
}

void alteracaoNotas(int n, vector<float>& notas, vector<string>& nomes) {
    char alterar;
    cout << "Deseja alterar notas (s/n)?: ";
    cin >> alterar;

    
     while (alterar =='s' || alterar == 'S'){
    
        string nomeAluno;
        cout << "Digite o nome do aluno para  alterar nota: ";
        cin >> nomeAluno;

        bool encontrado = false;
        int indiceAluno;

        for (int i = 0; i < n ; i++) {
            if (nomes[i] == nomeAluno) {
                encontrado = true;
                indiceAluno = i;
                break;
            }
        }

        if (encontrado) {
            cout << "Notas atuais do aluno " << nomeAluno << ":" << endl;
            cout << "Nota 1: " << notas[indiceAluno * 2] << endl;
            cout << "Nota 2: " << notas[indiceAluno * 2 + 1] << endl;

            int opcao;
            do {
                cout << "Deseja alterar a primeira nota (1), a segunda nota (2) ou nenhuma (0)? ";
                cin >> opcao;

                if (opcao == 1) {
                    cout << "Digite a nova primeira nota: ";
                    cin >> notas[indiceAluno * 2];
                } else if (opcao == 2) {
                    cout << "Digite a nova segunda nota: ";
                    cin >> notas[indiceAluno * 2 + 1];
                }

            } while (opcao != 0);

            cout << "Nota do aluno " << nomeAluno << " foram alterada com sucesso." << endl;
        } else {
            cout << "Aluno nao encontrado." << endl;
        }

        cout << "\nDados dos alunos:\n";
        for (int i = 0; i < n; i++) {
            cout << "Aluno: " << nomes[i] << endl;
            cout << "Nota 1: " << notas[i * 2] << endl;
            cout << "Nota 2: " << notas[i * 2 + 1] << endl;
            float media = (notas[i * 2] + notas[i * 2 + 1]) / 2;
            cout << "Media: " << media << endl;
            if (media >= 7) {
                cout << "Situacao: Aprovado" << endl;
            } else {
                cout << "Situacao: Reprovado" << endl;
            }
            cout << "-----------------------\n";
        }
        alterar = 'n';

    }    
}

