#include <iostream>
#include "arvore_binaria.h"

using namespace std;

int main()
{
    cout << "***** Arvore Binaria *****" << endl;
    ArvoreBinaria<int> tree;

    tree.push(tree.root, 7);
    tree.push(tree.root, 5);
    tree.push(tree.root, 2);
    tree.push(tree.root, 9);
    tree.push(tree.root, 8);
    tree.push(tree.root, 6);
    tree.push(tree.root, 10);
    tree.push(tree.root, 15);

    cout << "\nPre ordem" << endl;
    tree.RED(tree.root);

    cout << "\nEm ordem" << endl;
    tree.ERD(tree.root);

    cout << "\nPos ordem" << endl;
    tree.EDR(tree.root);

    cout << "\n\nFIM" << endl;

    return 0;
}
