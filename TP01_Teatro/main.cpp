#include <iostream>
#include "Teatro.h"

using namespace std;

void displayMenu() {
    cout << "\n    ************* MENU *************" << endl;
    cout << "    ** 01 - Visualizar poltronas  **" << endl;
    cout << "    ** 02 - Reservar poltrona     **" << endl;
    cout << "    ** 03 - Reembolsar ticket     **" << endl;
    cout << "    ** 04 - Trocar poltrona       **" << endl;
    cout << "    ** 00 - Sair                  **" << endl;
    cout << "    ********************************" << endl;
    cout << "\nSelecione uma opcao: ";
}

void selecionarOpcao(Teatro &theater, int &reservedSeat, int &option) {
    int seat;
    cin >> option;
    switch (option) {
        case 1:
            theater.displayTheater();
            break;
        case 2:
            theater.displayTheater();
            cout << "Por favor, selecione a poltrona desejada: ";
            cin >> seat;
            if (theater.isSeatAvailable(seat)) {
                theater.buySeat(seat);
                reservedSeat = seat;
            }
            else theater.buySeat(seat);
            break;
        case 3:
            if (reservedSeat > 0 && !theater.isSeatAvailable(reservedSeat)) {
                theater.refundSeat(reservedSeat);
                reservedSeat = 0;
            }
            else
                cout << "Voce precisa ter uma poltrona reservada para pedir reembolso" << endl;
            break;
        case 4:
            if (reservedSeat > 0 && !theater.isSeatAvailable(reservedSeat)) {
                theater.displayTheater();
                cout << "Por favor, selecione a nova poltrona desejada: ";
                cin >> seat;
                if (theater.isSeatAvailable(seat)) {
                    theater.refundSeat(reservedSeat);
                    theater.buySeat(seat);
                    reservedSeat = seat;
                }
                else theater.buySeat(seat);
            }
            else cout << "Voce precisa ter uma poltrona reservada para realizar a troca" << endl;
            break;
        case 0:
            cout << "Obrigado por visitar o Teatro " << theater.nome << "! Volte sempre" << endl;
            break;
        default:
            cout << "Por favor, selecione uma opcao valida" << endl;
    }
}

int main() {
    Teatro theater("Guarani", 6, 10);
    int reservedSeat;
    int exitOption = 0;
    int option;

    while (true) {
        displayMenu();
        selecionarOpcao(theater, reservedSeat, option);
        if (option == exitOption)
            return 0;
    }
}
