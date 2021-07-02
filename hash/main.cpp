#include <iostream>
#include "hashtable.h"
using namespace std;

int main()
{
    Hash h;
    int opc;
    int x;
    do{cout << "*** Hashing ***" << endl;
    cout<<"1- Inserir"<<endl;
    cout<<"2- Remover"<<endl;
    cout<<"3- Exibir Hash"<<endl;
    cout<<"9- Sair"<<endl;
    cout<<"Selecione:";
    cin>>opc;
    switch(opc)
    {
    case 1:
        cout<<"Digite o numero:";
        cin>>x;
        h.insere(x);
        cout<<"Sucesso!"<<endl;
        break;
    case 2:
            cout<<"Insira o valor para remover: "<<endl;
            cin>>x;
            if(h.remover(x))
            {
                cout<<"Sucesso!"<<endl;
            }
            else
                cout<<"Valor nao encontrado!"<<endl;

        break;
    case 3:
            cout<<"Elementos da Lista"<<endl;
            h.mostralista();
            cout<<"\n-------------"<<endl;
        break;
    case 9:
        cout<<"fim"<<endl;
        break;
    default:
        cout<<"Opcao invalida!"<<endl;
        break;
    }
}
while (opc!=9);
return 0;
};
