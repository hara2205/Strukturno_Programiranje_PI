#include<iostream>
#include<cmath>
using namespace std;
const int vel = 7;
void Unos(double niz[]) {
	for (int i = 0; i < vel; i++)
	{
		do
		{
			cout << "Unesite " << i+1 << ". element niza: ";
			cin >> niz[i];
		} while (niz[i]<-100 || niz[i]>100);
	}
}
double AritmetickaSredina(double niz[]) {
	double suma = 0;
	for (int i = 0; i < vel; i++)
	{
		suma += niz[i];
	}
	return suma/ vel;
}
void Ukloni(double niz[], double prosjek, int& nova_velicina) {
	for (int i = 0; i < vel; i++)
	{
		if (abs(niz[i] - prosjek) < 10) {
			niz[nova_velicina] = niz[i];
			nova_velicina++;
		}
	}
}
int main() {
	double niz[vel];
	double prosjek = 0;
	int nova_velicina = 0;
	Unos(niz);
	prosjek = AritmetickaSredina(niz);
	cout << "Aritmeticka sredina unesenog niza je: " << prosjek << endl;
	Ukloni(niz, prosjek, nova_velicina);
	cout << "Niz nakon uklanjanja elemenata cija je udaljenost od aritmeticke sredine veca od 10: ";
	for (int i = 0; i < nova_velicina; i++)
	{
		cout << niz[i] << " ";
	}
	system("Pause>0");
	return 0;
}