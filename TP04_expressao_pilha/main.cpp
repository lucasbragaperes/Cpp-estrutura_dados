#include <iostream>
#include "pilha.h"
#include <string>

using namespace std;

Pilha<char> p(50);
string expressao;
void exp();
void menu();
int opcao = 0;


main()
{
    cout << "TP 04 - Analisando uma Expressao" << endl;
    cout << "Desenvolvido por Lucas Braga Peres" << endl;
    do
    {
        menu();
    }
    while (opcao != 9);
}

void menu()
{
    cout<<endl<<"*** MENU ***"<<endl;
    cout<<"1 - Verificar Expressao"<<endl;
    cout<<"9 - Sair"<<endl;
    cout<<endl<<"Selecione a opcao desejada: ";
    cin>>opcao;

    switch (opcao)
    {
    case 1:
        exp();
        break;
    case 9:
        cout<<"FIM!"<<endl;
        break;
    default :
        printf ("Valor invalido!\n");
    }
}

void exp()
{
    getchar(); // necessario por causa do switch case

    cout << "Digite a expressao:"<<endl;
    getline(cin, expressao);
    cout << endl << expressao << endl;
    cout << "Tamanho:" << expressao.size() << endl;

    for (int i = 0; i < expressao.size(); i++)
    {
        cout << expressao.at(i) << endl;
    }

    unsigned i = 0;
    char s;  //simbolo na expressao

    while (i < expressao.size())
    {
        s = expressao.at(i);
        if (s == '(' || s == '[' || s == '{')
        {
            cout << s <<endl;
            p.empilha(s);
        }
        else
        {
            if (s == ')' || s == ']' || s == '}')
            {
                if (p.pilhavazia())
                {
                    p.empilha(s);
                    break;
                }
                else
                {
                    if (s == ')' && p.elementodotopo() == '(')
                    {
                        p.desempilha();
                    }
                    else
                    {
                        if (s == ']' && p.elementodotopo() == '[')
                        {
                            p.desempilha();
                        }
                        else
                        {
                            if (s == '}' && p.elementodotopo() == '{')
                            {
                                p.desempilha();
                            }
                        }
                    }
                }
            }
        }
        i++;
    }//while

    cout<<endl<<"****** RESULTADO ******"<<endl;
    if (p.pilhavazia())
    {
        cout << "Expressao correta!" << endl;
        cout<<"********************"<<endl;
    }
    else
    {
        cout << "ERRO - Expressao nao fecha!" << endl;
        cout<<"********************"<<endl;
    }
}
