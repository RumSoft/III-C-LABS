#pragma once
#include <iostream>
#include "Napis.h"
#include "Data.h"
using namespace std;

static int id_index = 0;

class Pracownik
{
public:
	Pracownik(const char* im = "", const char * naz = "", int dzien = 1, int miesiac = 1, int rok = 2000);
	Pracownik(const Pracownik & wzor);

	virtual ~Pracownik();

	const char* Imie() const;
	void Imie(const char* nowe_imie);

	void Nazwisko(const char* nowe_nazwisko);
	const char* Nazwisko() const;

	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	Data DataUrodzenia() const;

	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const  char* por_nazwisko) const;
	Pracownik* m_pNastepny = nullptr;
	int Porownaj(const Pracownik& wzorzec) const;

	friend ostream & operator << (ostream & wy, const Pracownik & n);
	friend istream & operator >> (istream & we, Pracownik & n);

	Pracownik & operator=(const Pracownik & wzor);
	bool operator== (const Pracownik& wzor) const;

	virtual string ToString() const;
	virtual void Wypiszdane() const;
	virtual Pracownik* KopiaObiektu();

private:
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
	const int m_nIDZatrudnienia;
};

