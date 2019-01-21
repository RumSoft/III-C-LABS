#pragma once

#include "Pracownik.h"

class ListaPracownikow {
public:
	ListaPracownikow();
	~ListaPracownikow();
	void Dodaj(Pracownik& p);
	void Usun(const Pracownik& wzorzec);
	void WypiszPracownikow() const;
	const Pracownik* Szukaj(const char* nazwisko, const char* imie)const;

	int LiczbaPracownikow() { return m_nLiczbaPracownikow; }
	Pracownik* PobierzPracownika() const { return m_pPoczatek; }
private:
	Pracownik* m_pPoczatek;
	int m_nLiczbaPracownikow;

};