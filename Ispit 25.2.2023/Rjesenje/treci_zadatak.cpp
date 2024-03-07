#include<iostream>
#include<cctype>
using namespace std;
const int vel = 50;
void Inicijalizuj(char niz[]) {
	for (int i = 0; i < vel; i++)
		niz[i] = 'a' + rand() % 25;
}
void Ispis(char niz[], int velicina) {
	for (int i = 0; i < velicina; i++)
		cout << niz[i] << " ";
	cout << endl;
}
void PrebrojiSamoglasnike(char niz[]) {
	float brojac = 0;
	for (int i = 0; i < vel; i++)
		if (tolower(niz[i]) == 'a' || tolower(niz[i]) == 'e' || tolower(niz[i]) == 'i' || tolower(niz[i]) == 'o' || tolower(niz[i]) == 'u')
			brojac++;
	cout << "Ukupan broj samoglasnika u nizu je: " << brojac<<endl;
	cout << "Procenat koji cine samoglasnici je: " << (brojac / vel) * 100 << "%" << endl;
}
void UkloniSuglasnike(char niz[], int& nova_velicina) {
	for (int i = 0; i < vel; i++)
		if (tolower(niz[i]) == 'a' || tolower(niz[i]) == 'e' || tolower(niz[i]) == 'i' || tolower(niz[i]) == 'o' || tolower(niz[i]) == 'u') {
			niz[nova_velicina] = niz[i];
			nova_velicina++;
		}
}
int main() {
	char niz[vel];
	int nova_velicina = 0;
	Inicijalizuj(niz);
	Ispis(niz,vel);
	PrebrojiSamoglasnike(niz);
	cout << "Niz nakon uklanjanja suglasnika: " << endl;
	UkloniSuglasnike(niz, nova_velicina);
	Ispis(niz, nova_velicina);
	system("Pause>0");
	return 0;
}