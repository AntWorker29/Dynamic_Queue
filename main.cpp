#include <iostream>
#include <conio.h>
using namespace std;
#define MEM_INSUFFICIENT -1
///// COADA_dinamica
// Definire NOD
typedef struct Nod_ {
	int info;
	struct Nod_* suc;//succesor, urmator, legatura
}Nod;
typedef struct Coada_ {
	Nod_* front;
	Nod_* rear;
}Coada;
///////////////////////////////////////////////////////////////////////////////////
Nod* init(const int info) {

	Nod* nodNou = new Nod;
	nodNou->info = info;
	nodNou->suc = NULL;
	return nodNou;
}
///////////////////////////////////////////////////////////////////////////////////
void parcurgere(Coada_* lista) {
	Nod* temp =lista-> front;
	if (lista->front == NULL) cout << "Coada e goala\n";
	else
	{
		cout << "Coada este: ";
		while (temp != NULL)
		{
			cout << temp->info << " ";
			temp = temp->suc;
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////
Coada_* Enqueue(Coada_* lista, const int info)
{
	Nod* nodNou = init(info);
	if (lista->front == NULL)
	{
		lista->front= lista->rear = nodNou;
	}
	else
	{
		lista->rear->suc = nodNou;
		lista->rear = nodNou;
	}
	return lista;
}
///////////////////////////////////////////////////////////////////////////////////
Coada_* Dequeue(Coada_* lista)
{
	if (lista->front == NULL)
	{
		return NULL;
		cout << "Coada e goala!\n";
	}
	Nod* temp = lista->front;
	lista->front = lista->front->suc;
	cout << "A fost sters elementul " << temp->info <<" din coada\n";
	delete[] temp;
	if (lista->front == NULL)	lista->rear = NULL;
	return lista;
}
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
int main() {
	Coada_* lista = new Coada_;
	lista->front = NULL;
	lista->rear = NULL;
	char meniu;

	do {
		system("cls");
		cout << "COADA_implementata_DINAMIC: " << endl;
		cout << "(p) Parcurgere \n";
		//cout << "(c) Cautare \n";
		cout << "(i) ENQUEUE/ Inserare \n";
		cout << "(s) DEQUEUE/ Stergere \n";
		cout << "(x) Iesire \n";
		meniu = _getch();
		switch (meniu) {
		case 'p':
		{
			//Parcurgere
			//cout << "Coada este: " << endl;
			parcurgere(lista);
			_getch();
			break;
		}
		case 'i':
		{
			///ENQUEUE
			int valoarea;
			cout << "Inserati la sfarsit elementul: ";
			cin >> valoarea;
			lista = Enqueue(lista, valoarea);
			parcurgere(lista);
			_getch();
			break;
		}
		case 's':
		{	/// DEQUEUE
			lista = Dequeue(lista);
			parcurgere(lista);
			_getch();
			break;
		}
		}
	} while (meniu != 'x');
	return 0;
}
