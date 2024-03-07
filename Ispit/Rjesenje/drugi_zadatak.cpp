#include<iostream>
using namespace std;
int PronadjiBrojCifara(int broj) {
	return log10(broj) + 1;
}
int PronadjiSrednjuCifru(int broj) {
	int brojCifara = PronadjiBrojCifara(broj);
	int srednjaCifra = 0;
	for (int i = 0; i <=brojCifara/2 ; i++)
	{
		srednjaCifra = broj % 10;
		broj /= 10;
	}
	return srednjaCifra;
}
int PronadjiBroj(int broj, int srednjaCifra) {
	if (srednjaCifra == 1)
		return broj + 1;
	for (int i = 1; i <=broj; i++)
	{
		if (i * srednjaCifra > broj)
			return i;
	}
}
int main() {

	int N = 0;
	do
	{
		cout << "Unesite broj sa neparnim brojem cifara: ";
		cin >> N;
	} while (PronadjiBrojCifara(N)%2==0);
	int srednjaCifra = PronadjiSrednjuCifru(N);
	cout << "Srednja cifra broja " << N << " je: " << srednjaCifra<<endl;
	if (srednjaCifra == 0)
		cout << "Svaki broj pomnozen s nulom je nula!";
	else {
		cout << "Najmanji broj koji pomnozen srednjom cifrom daje rezultat veci od unesenog broja je: " << PronadjiBroj(N, srednjaCifra);
	}
	system("Pause>0");
	return 0;
}