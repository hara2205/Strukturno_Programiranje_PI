#include<iostream>
#include<cmath>
using namespace std;
const int vel = 8;
int brojCifara(int broj) {
	return log10(broj) + 1;
}
void Unos(int matrica[][vel]) {
	for (int i = 0; i <vel ; i++)
		for (int j = 0; j < vel; j++)
			if((i+j)%2==0)
				do
				{
					matrica[i][j] = rand() % 10000;
				} while (matrica[i][j]%2!=0 || brojCifara(matrica[i][j]) % 2 == 0);
			else 
				do
				{
					matrica[i][j] = rand() % 10000;
				} while (matrica[i][j] % 2 == 0 || brojCifara(matrica[i][j]) % 2 != 0);
			
}
void Ispis(int matrica[][vel]) {
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			cout << matrica[i][j]<<"  ";
		}
		cout << endl;
		cout << endl;
	}
}
float ProsjekCrnihIznadSporedneDijagonale(int matrica[][vel]) {
	float suma = 0;
	int brojac = 0;
	for (int i = 0; i < vel; i++)
		for (int j = 0; j < vel; j++)
			if ((i + j) % 2 == 0 && (i + j) <= 6) {
				suma += matrica[i][j];
				brojac++;
			}
	return suma /= brojac;
}
float ProsjekParnihBijelohIznadGlavne(int matrica[][vel]) {
	float suma = 0;
	int brojac = 0;
	for (int i = 0; i < vel; i++)
		for (int j = 0; j < vel; j++)
			if (matrica[i][j] % 2 == 0 && ((i + j) % 2 != 0) && j > i) {
				suma += matrica[i][j];
				brojac++;
			}
	if (suma == 0)
		return 0;
	return suma /= brojac;
}
float ProsjekNeparnihCrnihIspodSporedne(int matrica[][vel]) {
	float suma = 0;
	int brojac = 0;
	for (int i = 0; i <vel; i++)
		for (int j = 0; j < vel; j++)
			if ((i + j) >= 8 && matrica[i][j] % 2 != 0 && (i + j) % 2 == 0) {
				suma += matrica[i][j];
				brojac++;
		}
	if (suma ==0)
		return 0;
	return suma /= brojac;
}
float ProsjekParnihCrnih(int matrica[][vel]) {
	float suma = 0;
	int brojac = 0;
	for (int i = 0; i < vel; i++)
		for (int j = 0; j < vel; j++)
			if ((i + j) % 2 == 0) {
				suma += matrica[i][j];
				brojac++;
		}
	return suma /= brojac;
}
int main() {
	int matrica[vel][vel];
	Unos(matrica);
	Ispis(matrica);
	cout << "Prosjek crnih elemenata iznad sporedne dijalonale je: " << ProsjekCrnihIznadSporedneDijagonale(matrica) << endl;
	cout << "Prosjek parnih elemenata na bijelim poljima iznad glavne dijagonale je: " << ProsjekParnihBijelohIznadGlavne(matrica) << endl;
	//na svakom bijelom polju se nalazi neparni element, tako da ova funkcija nema smisla.
	cout << "Prosjek svih neparnih crnih ispod sporedne je: " << ProsjekNeparnihCrnihIspodSporedne(matrica)<<endl;
	//na svakom crnom polju se nalazi parni element, tako da ova funkcija nema smisla.
	cout << "Prosjek crnih elemenata matrice na parnim pozicijama: " << ProsjekParnihCrnih(matrica);
	//svako crno polje je na parnoj poziciji
	system("Pause>0");
	return 0;
}