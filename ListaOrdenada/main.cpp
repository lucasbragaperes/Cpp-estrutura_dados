#include <iostream>
#include <stdio.h>

#include "filaligada.h"
#include "node.h"
using namespace std;

main()
{
    setlocale(LC_ALL, "Portuguese");

    cout << "*** Lista Ordenada ***" << endl;
    Lista<int> f;
    int opc, x;
    do
    {
        cout<<"1- Inserir um novo número"<<endl;
        cout<<"2- Remover um número"<<endl;
        cout<<"3- Exibir a lista"<<endl;
        cout<<"4- Buscar um número"<<endl;
        cout<<"9- Fim"<<endl;
        cout<<"Selecione: ";
        cin>>opc;
        cout<<endl;
        switch(opc)
        {
        case 1:
            cout<<"Digite o numero: ";
            cin>>x;
            if(f.insere(x))
            {
                cout<<"Sucesso!!!"<<endl;
                cout<<endl;
            }
            else
            {
                cout<<"Fila cheia!!!"<<endl;
                cout<<endl;
            }

            break;
        case 2:
            if(f.listavazia())
            {
                cout<<"Fila vazia!!!"<<endl;
                cout<<endl;
            }
            else
            {
                cout<<"Insira o valor para remover: "<<endl;
                cin>>x;
                if(f.remover(x))
                {
                    cout<<"Sucesso!"<<endl;
                    cout<<endl;
                }
                else
                    cout<<"Valor não encontrado!"<<endl;
                cout<<endl;

            }
            break;
        case 4:
            if(f.listavazia())
            {
                cout<<"Lista vazia!!!"<<endl;
                cout<<endl;

            }
            else
            {
                cout<<"Insira o valor para buscar: "<<endl;
                cin>>x;
                if(f.busca(x)==0)
                {
                    cout<<"Valor "<<x<<" não encontrado!"<<endl;
                    cout<<endl;

                }
                else
                    cout<<"Sucesso!!! "<<x<<" Encontrado "<<"aparece "<<f.busca(x)+1<<" vezes"<<endl;
                cout<<endl;

            }
            break;
        case 3:
            if(f.listavazia())
            {
                cout<<"Lista vazia!!!"<<endl;
                cout<<endl;

            }
            else
            {
                cout<<"Elementos da Lista"<<endl;
                Node<int> *aux = f.h;
                while(aux != NULL)
                {
                    cout<<aux->info<<" ";
                    aux = aux->prox;
                }
                cout<<"\n-------------"<<endl;
            }
            break;
        case 9:
            cout<<"Fim!"<<endl;
            break;
        default:
            cout<<"Opção Inválida!"<<endl;
            cout<<endl;

            break;
        }
    }
    while (opc!=9);

}
