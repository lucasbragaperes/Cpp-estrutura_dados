#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

template <typename Tipo>
struct Pilha {
	unsigned int maxi;  //tamanho da pilha
	int topo;  //indice do vetor
	Tipo *elementos; //ponteiro para nosso vetor
	Pilha(unsigned int tam) {
		topo = -1;
		maxi = tam;
		elementos = new Tipo[maxi];
	}
	~Pilha() {
		delete[] elementos;
	}

	void empilha(Tipo x) {
		topo++;
		elementos[topo] = x;
	}

	Tipo desempilha() {
		Tipo temp = elementos[topo];
		topo--;
		return temp;
	}

	Tipo elementodotopo() {
		return elementos[topo];
	}

	unsigned int getQtde() {
		return topo + 1;
	}

	bool pilhavazia() {
		return topo == -1;
	}

	bool pilhacheia() {
		return topo == (maxi - 1);
	}
};
#endif // PILHA_H_INCLUDED

