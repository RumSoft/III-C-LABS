#include "stdafx.h"
#include "Pracownik.h"
#include <iostream>
#include <string>

Pracownik::Pracownik(const char * im, const char * naz, int dzien, int miesiac, int rok) 
	: m_Imie(im), m_Nazwisko(naz), m_DataUrodzenia(dzien, miesiac, rok), m_nIDZatrudnienia(++id_index)
{

	m_pNastepny = nullptr;
}

Pracownik::Pracownik(const Pracownik& wzor) : m_nIDZatrudnienia(++id_index)
{
	Imie(wzor.Imie());
	Nazwisko(wzor.Nazwisko());
	DataUrodzenia(wzor.DataUrodzenia().Dzien(),
		wzor.DataUrodzenia().Miesiac(),
		wzor.DataUrodzenia().Rok());
	m_pNastepny = nullptr;
}


Pracownik& Pracownik::operator=(const Pracownik& wzor)
{
	Imie(wzor.Imie());
	Nazwisko(wzor.Nazwisko());
	DataUrodzenia(wzor.DataUrodzenia().Dzien(),
		wzor.DataUrodzenia().Miesiac(),
		wzor.DataUrodzenia().Rok());
	m_pNastepny = wzor.m_pNastepny;
	return *this;
}

bool Pracownik::operator==(const Pracownik & wzor) const
{
	return Porownaj(wzor) == 0;
}

string Pracownik::ToString() const 
{
	string str;
	str.append(Imie())
		.append(" ")
		.append(Nazwisko())
		.append(", ")
		.append(DataUrodzenia().ToString());
	return str;
}

void Pracownik::Wypiszdane() const
{
	cout << ToString() << endl;
}

Pracownik * Pracownik::KopiaObiektu()
{
	return new Pracownik(*this);
}

Pracownik::~Pracownik()
{
	//delete m_pNastepny;
}

const char * Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}

const char * Pracownik::Nazwisko() const
{
	return m_Nazwisko.Zwroc();
}

void Pracownik::Imie(const char * nowe_imie)
{
	this->m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char * nowe_nazwisko)
{
	this->m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	this->m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

Data Pracownik::DataUrodzenia() const
{
	return m_DataUrodzenia;
}

int Pracownik::SprawdzImie(const char * por_imie) const
{
	return strcmp(Imie(), por_imie);
}

int Pracownik::SprawdzNazwisko(const char * por_nazwisko) const
{
	return strcmp(Nazwisko(), por_nazwisko);
}

int Pracownik::Porownaj(const Pracownik& wzorzec) const
{
	int sprawdz = SprawdzNazwisko(wzorzec.Nazwisko());
	if (sprawdz != 0)
		return sprawdz;

	sprawdz = SprawdzImie(wzorzec.Imie());
	if (sprawdz != 0)
		return sprawdz;

	sprawdz = this->DataUrodzenia().Porownaj(wzorzec.DataUrodzenia());
	if (sprawdz != 0)
		return sprawdz;
	return 0;
}

ostream & operator<<(ostream & wy, const Pracownik & n)
{
	wy << n.Imie() << " " << n.Nazwisko() << " " << n.DataUrodzenia();
	return wy;
}

istream & operator >> (istream & we, Pracownik & n)
{

	we >> n.m_Imie >> n.m_Nazwisko >> n.m_DataUrodzenia;
	return we;
}

