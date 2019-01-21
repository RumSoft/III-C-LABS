#pragma once

#include <iostream>
#include "Pracownik.h";
#include "Napis.h";

class Kierownik : public Pracownik {
	Napis m_NazwaDzialu;
	int m_nLiczbaPracownikow;

public:
	Kierownik(const char* nazwadzialu = "", int liczbapracownikow = 0, const char* imie="", const char* nazwisko="", int d=1, int m=1, int r=2000);
	Kierownik(const Kierownik& wzor);
	void Wypiszdane() const override;
	string ToString() const override;

	friend ostream & operator<<(ostream & wy, const Kierownik & n);
	friend istream & operator>>(istream & we, Kierownik & n);

};