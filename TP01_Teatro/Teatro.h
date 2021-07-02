#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#ifndef TEATRO_H_INCLUDED
#define TEATRO_H_INCLUDED

class Teatro {
    private:
        int _linha;
        int _coluna;
        int _poltronas;
    public:
        string nome;
        int *seats;

    Teatro(string nome, int rows, int cols) {
        this->nome = nome;
        _linha = rows;
        _coluna = cols;
        _poltronas = rows * cols;
        buildTheater();
        reserveRandomSeats(_poltronas / 4);
        cout << "[ ***** Bem-vindo ao Teatro " << nome << " ***** ]\n" << endl;
    }

    void displayTheater() {
        cout << "-------------------- Teatro " << nome << " --------------------" << endl;
        for (int row = 0; row < _linha; row++) {
            displayRow(row);
            for (int col = 1; col <= _coluna; col++) {
                int seat = getSeat(row, col);
                displaySeat(seat);
            }
            cout << endl;
        }
    }

    void buySeat(int seat) {
        if (isSeatAvailable(seat)) {
            seats[seat] = 0;
            cout << "Poltrona " << seat << " reservada. Obrigado por comprar no Teatro " << nome << "!" << endl;
        }
        else
            cout << "Poltrona " << seat << " ja esta reservada. Favor selecionar outra opcao" << endl;
    }

    void refundSeat(int seat) {
        if (isSeatAvailable(seat))
            cout << "Operacao invalida. Poltrona livre" << endl;
        else {
            seats[seat] = seat;
            cout << "Ticket reembolsado!" << endl;
        }
    }

    bool isSeatAvailable(int seat) {
        if (seats[seat] == 0) return false;
        return true;
    }

    private:
        void buildTheater() {
            seats = new int[_poltronas];
            for (int row = 0; row < _linha; row++) {
                for (int col = 1; col <= _coluna; col++) {
                    int seat = getSeat(row, col);
                    seats[seat] = seat;
                }
            }
        }

        void displayRow(int row) {
            if (row + 1 < 10)
                cout << "Fileira 0" << row + 1 << ": ";
            else
                cout << "Fileira " << row + 1 << ": ";
        }

        void displaySeat(int seat) {
            if (!isSeatAvailable(seat))
                cout << "[XX] ";
            else if (seats[seat] < 10)
                cout << "[0" << seats[seat] << "] ";
            else
                cout << "[" << seats[seat] << "] ";
        }

        int getSeat(int row, int col) {
            return row * _coluna + col;
        }

        void reserveRandomSeats(int amount) {
            for (int seat = 0; seat < amount; seat++) {
                int randomSeat = rand() % _poltronas + 1;
                seats[randomSeat] = 0;
            }
        }
};

#endif // TEATRO_H_INCLUDED
