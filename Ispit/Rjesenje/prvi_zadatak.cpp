#include<iostream>
#include<cmath>
using namespace std;
double Formula(int broj) {
	double suma = 0;
	for (int i = 1; i <=broj; i++)
	{
		suma += (1 / sqrt(i) - 1 / sqrt(i + 1));
	}
	return suma;
}
void Unos(int& broj) {

	do
	{
		cout << "Unesite broj u intervalu od 10 do 100: ";
		cin >> broj;
	} while (!(broj>10 && broj<100) );
}
int main() {

	int broj = 0;
	Unos(broj);
	cout << "Rezultat formule je: " << Formula(broj);
	
	system("Pause>0");
	return 0;
}