/*
P1 Estrutura de dados
Nome: Lucas Braga Peres
*/

#ifndef listalinear_H_INCLUDED
#define listalinear_H_INCLUDED

template<typename Tipo>
struct Lista
{
	Tipo *elementos;
	unsigned int tamanho;
	unsigned int qtde;
	int p;

	Lista(unsigned int tam)
	{
		tamanho = tam;
		elementos = new Tipo[tamanho];
		p = -1;
		qtde = 0;
	}

	void inserir(Tipo x)
	{
		p = p + 1;
		elementos[p] = x;
		qtde++;
	}
	Tipo remover()
	{
		Tipo temp = elementos[p];
		p = p - 1;
		qtde--;
		return temp;
	}
	Tipo ultimo()
	{
		return elementos[p];
	}
	bool listacheia()
	{
		return qtde == tamanho;
	}
	bool listavazia()
	{
		return qtde == 0;
	}
};
#endif // listalinear_H_INCLUDED
