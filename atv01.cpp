#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int total;
    vector<float> notas;
    vector<string> nomes;

    cout << "Digite o total de alunos ";
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

    cout << "\nDados dos alunos:\n";
    for (int i = 0; i < total; i++) {
        cout << "Aluno " << nomes[i] << endl;
        cout << "Nota 1 " << notas[i] << endl;
        cout << "Nota 2 " << notas[i + 1] << endl;
        cout << "Media " << (notas[i] + notas[i + 1]) / 2 << endl;
        cout << "-----------------------\n";
    }

    return 0;
}