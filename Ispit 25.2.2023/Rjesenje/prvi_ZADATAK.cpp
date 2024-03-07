#include<iostream>
using namespace std;
void Unos(int& a, int& b) {
	do
	{
		cout << "Unesite broj veci od 200: ";
		cin >> a;
	} while (a<=200);
	do
	{
		cout << "Unesite broj barem za 100 veci od prvog: ";
		cin >> b;
	} while (b<=a+100);
}
int ObrniBroj(int broj) {
	int obrnuti = 0;
	while (broj != 0) {
		obrnuti *= 10;
		obrnuti += broj % 10;
		broj /= 10;
	}
	return obrnuti;
}
bool Provjera(int broj, int& a, int& b) {
	for (int i = 10; i < broj; i++)
	{
		for (int j = broj; j >10; j--)
		{
			if (ObrniBroj(i) == i && ObrniBroj(j) == j && i+j==broj) {
				a = i;
				b = j;
				return true;
			}
		}
	}
	return false;
}
void Ispis(int a, int b) {
	for (int i = a; i <=b; i++)
	{
		if (i % 2 == 0) {
			int prvi = 0, drugi = 0;
			if (Provjera(i, prvi, drugi))
				cout << i << " = " << prvi << " + " << drugi << endl;
			else
				cout << i << " se ne moze izraziti kao zbir dva palindroma." << endl;
		}
	}
}
int main() {
	int a = 0,b=0;
	Unos(a, b);
	Ispis(a, b);
	system("Pause>0");
	return 0;
}