#include "stdafx.h"
#include <iostream>
#include <string>
#include "Data.h"
#include "Kierownik.h"

using namespace std;



Kierownik::Kierownik(const char* nazwadzialu, int liczbapracownikow,
	const char* imie, const char* nazwisko, int d, int m, int r) :
	Pracownik(imie, nazwisko, d, m, r),
	m_NazwaDzialu(nazwadzialu),
	m_nLiczbaPracownikow(liczbapracownikow)
{
}

Kierownik::Kierownik(const Kierownik& wzor) :
	Pracownik(wzor),
	m_NazwaDzialu(wzor.m_NazwaDzialu),
	m_nLiczbaPracownikow(wzor.m_nLiczbaPracownikow)
{
}

void Kierownik::Wypiszdane() const
{
	cout << ToString() << endl;
}

string Kierownik::ToString() const
{
	string str;
	str.append("Kierownik dzialu: ")
		.append(this->m_NazwaDzialu.Zwroc())
		.append(", ")
		.append(Pracownik::ToString());
	return str;
}


ostream & operator<<(ostream & wy, const Kierownik & n)
{
	wy << *(new Pracownik(n)) << " " << n.m_nLiczbaPracownikow << " " << n.m_NazwaDzialu;
	return wy;
}

istream & operator >> (istream & we, Kierownik & n)
{
	string imie, nazwisko;
	Data data;
	string nazwaDzialu;
	int ilosc;
	we >> imie >> nazwisko >> data >> ilosc >> nazwaDzialu;
	n.Imie(imie.c_str());
	n.Nazwisko(nazwisko.c_str());
	n.DataUrodzenia(data.Dzien(), data.Miesiac(), data.Rok());
	n.m_NazwaDzialu.Ustaw(nazwaDzialu.c_str());
	n.m_nLiczbaPracownikow = ilosc;
	return we;
}

