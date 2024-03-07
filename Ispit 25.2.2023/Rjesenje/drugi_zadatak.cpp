#include<iostream>
using namespace std;
void Unos(int &broj) {
	do
	{
		cout << "Unesite broj koji nije manji od 10: ";
		cin >> broj;
	} while (broj<10);
}
bool isProst(int broj) {
	for (int i = 2; i <=broj/2 ; i++)
	{
		if (broj % i == 0)
			return false;
	}
	return true;
}
bool NemaParnuCifru(int broj) {
	while (broj != 0) {
		if ((broj % 10) % 2 == 0)
			return false;
		broj /= 10;
	}
	return true;
}
void Ispis(int broj) {
	cout << "Brojevi u rangu od 1 do " << broj << " koji su prosti i nemaju ni jednu parnu cifru:"<<endl;
	for (int i = 1; i <=broj; i++)
		if (isProst(i) && NemaParnuCifru(i))
			cout << i << "  ";
	
}
int main() {
	int m_1 = 0;
	Unos(m_1);
	Ispis(m_1);
	system("Pause>0");
	return 0;
}