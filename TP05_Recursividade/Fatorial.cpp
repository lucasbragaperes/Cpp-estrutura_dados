#include <iostream>

using namespace std;

int main()
{
    double fatorial(int n);
    double n;
    cout <<"Digite um numero:"<< endl;
    cin >> n;


	cout << "Fatorial de " << n << " = " << fatorial(n) << endl;
    return 0;
}

double fatorial(int n) {
	double p = 1;
	if (n != 0) {
		for (int i = 1; i <= n; i++) {
			p = p * i;
		}
	}
	return p;
}
