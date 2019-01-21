#include "stdafx.h"
#include "Kierownik.h"
#include <stdlib.h>
#include <fstream>
#include <string>
#include "ListaPracownikow.h"

using namespace std;

#pragma region menu
void ShowMenu()
{
	cout << "\nWitaj przybyszu w systemie zarzadzania pracownikami 3000" << endl;
	cout << "1. Dodaj pracownika." << endl;
	cout << "2. Usun pracownika." << endl;
	cout << "3. Pokaz liste pracownikow." << endl;
	cout << "4. Wyszukaj pracownika na liscie." << endl;
	cout << "5. Wczytaj liste z pliku." << endl;
	cout << "6. Zapisz liste do pliku." << endl;
	cout << "7. Dodaj kierownika" << endl;
	cout << "9. Wyczysc liste." << endl;
	cout << "0. Zakoncz program." << endl;
}


void DodajPracownika(ListaPracownikow* l)
{
	cout << "Podaj dane pracownika w formacie:\nIMIE NAZWISKO DD MM RRRR\n";
	const auto p = new Pracownik();
	cin >> *p;
	l->Dodaj(*p);
	cout << "Pomyślnie dodano pracownika";
}

void UsunPracownika(ListaPracownikow* l)
{
	cout << "Podaj imie i nazwisko pracownika do usunięcia" << endl;
	Napis im, nazw;
	cin >> im >> nazw;
	const auto p = l->Szukaj(nazw.Zwroc(), im.Zwroc());
	if (p) {
		l->Usun(*p);
		cout << "usunieto pracownika" << endl;
	}
	else
		cout << "nie znaleziono pracownika" << endl;
}

void PokazListe(ListaPracownikow* l)
{
	cout << "Lista pracownikow, aktualny stan:" << endl;
	l->WypiszPracownikow();
}

void DodajKierownika(ListaPracownikow* l)
{
	cout << "Podaj dane kierownika w formacie:\nIMIE NAZWISKO DD MM RRRR ILOSC_PRACOW NAZWA_DZIALU\n";
	const auto p = new Kierownik();
	cin >> *p;
	l->Dodaj(*p);
	cout << "Pomyślnie dodano pracownika";
}

#pragma endregion

void WyszukajPracownika(ListaPracownikow* l)
{
	cout << "podaj imie i nazwisko pracownika";
	Napis im, nazw;
	cin >> im >> nazw;
	const Pracownik* p = l->Szukaj(nazw.Zwroc(), im.Zwroc());
	if (p)
		cout << p->ToString() << endl;
	else
		cout << "nie znaleziono pracownika" << endl;
}

void ZapiszListe(ListaPracownikow* l)
{
	ofstream  file;
	file.open("pracowniki.txt", ios::out);
	Pracownik* p = l->PobierzPracownika();
	while (p != nullptr) {
		if (const auto k = dynamic_cast<Kierownik*>(p))
			file << "K " << *k << endl;
		else
			file << "P " << *p << endl;
		p = p->m_pNastepny;
	}
	file.close();
	cout << "pomyslnie zapisano pracownikow do pliku";
}

void WczytajListe(ListaPracownikow* l)
{
	ifstream file;
	file.open("pracowniki.txt", ios::in);
	while(!file.eof())
	{
		string n;
		file >> n;
		if (n.empty()) return;

		if (n == "K")
		{
			const auto k = new Kierownik();
			file >> *k;
			l->Dodaj(*k);
		}
		else
		{
			const auto p = new Pracownik();
			file >> *p;
			l->Dodaj(*p);
		}
	}
}

void WyczyscListe(ListaPracownikow* l)
{
	while(l->LiczbaPracownikow() > 0)
		l->Usun(*l->PobierzPracownika());
	cout << "Usunieto pracownikow";
}

int main() {
	auto l = new ListaPracownikow();
	while(true)
	{
		ShowMenu();
		int a = 0;
		cin >> a;

		switch(a)
		{
		case 1:
			DodajPracownika(l);
			break;
		case 2:
			UsunPracownika(l);
			break;
		case 3:
			PokazListe(l);
			break;
		case 4:
			WyszukajPracownika(l);
			break;
		case 5:
			WczytajListe(l);
			break;
		case 6:
			 ZapiszListe(l);
			break;
		case 7:
			DodajKierownika(l);
			break;
		case 9:
			WyczyscListe(l);
			break;
		}
		if (a == 0)
			break;
	}
	system("PAUSE");
}
