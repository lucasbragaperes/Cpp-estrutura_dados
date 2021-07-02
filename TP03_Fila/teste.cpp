#include <iostream>
#include<string>
#include "fila_tp3.h"

// TP 03 - Lista

using namespace std;

main()
{

    int opcao, capa;
    float valor;
    struct Fila umaFila;

    // cria a fila
    cout << "Digite o tamanho da fila:" << endl;
    cin >> capa;
    criarFila(&umaFila, capa);

    int opc;
    do
    {
        cout << "\n**** Fila ****" << endl;
        cout << "1 - Insere" << endl;
        cout << "2 - Remove" << endl;
        cout << "3 - Primeiro da fila" << endl;
        cout << "4 - Exibir a fila" << endl;
        cout << "9 - fim" << endl;
        cout << "Selecione: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            if (estaCheia(&umaFila))
            {

                printf("\nFila Cheia!!!\n\n");

            }
            else
            {

                printf("\nValor do elemento a ser inserido? ");
                scanf("%f", &valor);
                inserir(&umaFila,valor);

            }
            break;
        case 2:
            if (estaVazia(&umaFila))
            {

                printf("\nFila vazia!!!\n\n");

            }
            else
            {

                valor = remover(&umaFila);
                printf("\n%1f removido com sucesso\n\n", valor) ;

            }
            break;
        case 3:
            if (estaVazia(&umaFila))
            {

                printf("\nFila vazia!!!\n\n");

            }
            else
            {
                valor = primeiro(&umaFila);
                cout << "Primeiro da fila: " << valor << endl;

            }
            break;
        case 4:
            if (estaVazia(&umaFila))
            {

                printf("\nFila vazia!!!\n\n");

            }
            else
            {

                printf("\nConteudo da fila => ");
                mostrarFila(&umaFila);

            }
            break;
        case 9:
            cout << "fim...." << endl;
            break;
        default:
            cout << "opcao invalida...." << endl;
            break;
        }
    }
    while (opc != 9);
}


