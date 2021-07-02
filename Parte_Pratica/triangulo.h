/*
P1 Estrutura de dados - Ex. 06
Nome: Lucas Braga Peres
*/

#ifndef TRIANGULO_H_INCLUDED
#define TRIANGULO_H_INCLUDED
#include <math.h>

using namespace std;

struct Triangulo
{
	float a, b, c;

	float perimetro()
	{
		return a + b + c;
	}

	float area()
	{
		float s = (a + b + c) / 2;
		return sqrt(s*(s - a)*(s - b)*(s - c));
	}
    // verifica se é triangulo, retorna erro no menu caso FALSE
	bool isTriangulo()
	{
		return (a < b + c && b < a + c && c < a + b);
	}

	string tipo()
	{
		if (a == b && b == c)
		{
			cout<< "EQUILATERO";
            cout<<endl<<"---"<<endl;
		}
		else
		{
			if (a == b || b == c || a == c)
			{
				cout<< "ISOSCELES";
				cout<<endl<<"---"<<endl;
			}
			else
			{
				cout<< "ESCALENO";
				cout<<endl<<"---"<<endl;
			}
		}
	}

};

#endif // TRIANGULO_H_INCLUDED
