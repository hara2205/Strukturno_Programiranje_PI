#include<iostream>
#include<cctype>
using namespace std;
const int vel = 8;
int PrebrojiCifre(int broj) {
	return log10(broj) + 1;
}
void Inicijalizuj(int matrica[][vel]) {
	for (int i = 0; i < vel; i++)
		for (int j = 0; j < vel; j++)
			if((i+j)%2==0)
				do
				{
					matrica[i][j] = rand() % 10000;
				} while (matrica[i][j]%2!=0 || PrebrojiCifre(matrica[i][j])%2==0);
			else
				do
				{
					matrica[i][j] = rand() % 10000;
				} while (matrica[i][j]%2==0 || PrebrojiCifre(matrica[i][j])%2!=0);
}
void Ispis(int matrica[][vel]) {
	for (int i = 0; i < vel; i++) {
		for (int j = 0; j < vel; j++)
			cout << matrica[i][j] << "  ";
		cout << endl;
	}
}
int srednjaCifra(int broj) {
	int cifra = 0;
	for (int i = 0; i <=PrebrojiCifre(broj)/2; i++)
	{
		cifra = broj % 10;
		broj /= 10;
	}
	return cifra;
}
void IspisVrijednosti(int matrica[][vel]) {
	cout << "Srednje cifre crnih polja iznad glavne dijagonale: " << endl;
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			if ((i + j) % 2 == 0 && j > i)
				cout << matrica[i][j] << " - " << srednjaCifra(matrica[i][j])<<endl;
		}
	}
	/* drugi dio funkcije gdje pise da treba srednju cifru broja koji ima paran broj cifara uraditi kao prosjek
	dvije srednje cifre ne treba implementirati jer na svakom crnom polju se nalazi broj sa neparnim brojem cifara*/
}
int main() {
	int matrica[vel][vel];
	Inicijalizuj(matrica);
	Ispis(matrica);
	cout << endl;
	IspisVrijednosti(matrica);
	system("Pause>0");
	return 0;
}