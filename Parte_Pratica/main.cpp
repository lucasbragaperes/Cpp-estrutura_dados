/*
P1 - Estrutura de dados

*/

#include <iostream>
#include <stdlib.h>
#include "triangulo.h"
#include "listalinear.h"

using namespace std;

main()
{

	unsigned t;
	cout << "P1 - Estrutura de Dados - Parte Pratica"<< endl;
	cout << "Nome: Lucas Braga Peres"<< endl<< endl;

	do
    {
        cout << "Digite a quantidade de triangulos (tamanho da lista): ";
        cin >> t;
        if(t<=0)
            cout <<"Digite um numero maior que zero!"<<endl<<endl;
    }while(t <=0);

	Lista<Triangulo> mlista(t);
	Triangulo w;
    unsigned int opc;
	do
	{
		cout << "************" <<endl<< endl;
		cout << "MENU" <<endl<< endl;
		cout << "1 - Inserir Triangulo" << endl;
		cout << "2 - Remover Triangulo" << endl;
		cout << "3 - Exibir ultimo" << endl;
		cout << "4 - Exibir todos" << endl;
		cout << "0 - Sair" << endl<< endl;
		cout << "Selecione a opcao: " << endl;
		cin >> opc;
        cout << "************" <<endl<< endl;

		switch (opc)
		{
		case 1:
			if (mlista.listacheia())
			{
				cout << "Lista Cheia! Remova um triangulo!" << endl << endl;
			}
			else
			{
				cout << "Digite o lado A:";
				cin >> w.a;

				cout << "Digite o lado B:";
				cin >> w.b;

				cout << "Digite o lado C:";
				cin >> w.c;

				if (w.isTriangulo())
				{
					mlista.inserir(w);
					cout << endl<< "Concluido!" << endl << endl;
				}
				else
				{
					cout << endl << "Nao é um triangulo" << endl << endl;
				}
			}
			break;

		case 2:
			if (mlista.listavazia())
			{
				cout << "Lista Vazia! Insira um triangulo!" << endl << endl;
			}
			else
			{
				w = mlista.remover();
				cout << endl<< "\nRemovido\n" <<  w.a << w.b << w.b << endl;
			}
			break;
		case 3:
			if (mlista.listavazia())
			{
				cout << "Lista Vazia! Insira um triangulo!" << endl << endl;
			}
			else
			{
				w = mlista.ultimo();
				cout <<"*** Ultimo Triangulo ***"<<endl;
                    cout << "Lado A: " << w.a << endl;
					cout << "Lado B: " << w.b << endl;
					cout << "Lado C: " << w.c << endl;
                    cout << "Perimetro: " << w.perimetro()<< endl;
                    cout << "Obs: Mais detalhes, selecione opcao 4"<< endl<< endl;
			}
			break;
		case 4:
			cout << "*** Todos os triangulos da lista ***" << endl << endl;
			if (mlista.listavazia())
			{
				cout << "Lista Vazia! Insira um triangulo!" << endl << endl;
			}
			else
			{
				for (int i = 0; i <= mlista.p; i++)
				{
					w = mlista.elementos[i];
					cout << "Lado A: " << w.a << endl;
					cout << "Lado B: " << w.b << endl;
					cout << "Lado C: " << w.c << endl;
					cout << "Perimetro: " << w.perimetro()<< endl;
					cout << "Area: " << w.area() << endl;
					cout << "Tipo: " <<  w.tipo() << endl;
				}
			}
			break;

		case 0:
			cout << endl<< "Fim!" << endl;
			break;
		default:
			cout << endl<< "Opçao invalida!" << endl;
			break;

		}

	} while (opc != 0);

}
