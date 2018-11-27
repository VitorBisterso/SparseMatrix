#include <iostream>

#include "Node.hpp"
#include "AvlTree.hpp"
#include "Line.hpp"
#include "SparseMatrix.hpp"

using namespace std;

int main()
{
    SparseMatrix<int>* matrix = new SparseMatrix<int>(0);

    for (;;)
    {
        system("cls");
        cout << "Matriz Esparsa" << endl;
        cout << "Comandos disponiveis: " << endl << endl;
        cout << "1 - Inserir" << endl;
        cout << "2 - Selecionar" << endl;
        cout << "3 - Printar" << endl;
        cout << "4 - Sair" << endl << endl;
        cout << "Digite uma opcao: ";

        int option;
        cin >> option;

        int value;
        int line;
        int column;

        switch (option)
        {
            case 1:
                system("cls");
                cout << "Digite a linha aonde o valor sera inserido: ";
                cin >> line;
                cout << "Digite a coluna aonde o valor sera inserido: ";
                cin >> column;

                cout << "Digite o valor que deseja inserir: ";
                cin >> value;
                try
                {
                    matrix->put(line, column, value);
                    cout << "Operacao efetuada com sucesso";
                }
                catch(exception &err)
                {
                    cout << "Erro";
                }
                break;
            case 2:
                system("cls");
                cout << "Digite a linha do valor que deseja selecionar: ";
                cin >> line;
                cout << "Digite a coluna do valor que deseja selecionar: ";
                cin >> column;
                try
                {
                    cout << matrix->get(line, column);
                }
                catch(exception &err)
                {
                    cout << "Valor nao existe na matriz";
                }
                break;
            case 3:
                cout << *matrix;
                break;
            case 4:
                exit(0);
        }
        cout << endl << endl;
        cout << "Pressione qualquer tecla para continuar...";
        cin.sync();
        cin.ignore();
    }
    return 0;
}
