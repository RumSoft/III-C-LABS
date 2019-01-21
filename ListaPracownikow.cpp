#include "stdafx.h"
#include "ListaPracownikow.h"
#include <iostream>

ListaPracownikow::ListaPracownikow(): m_pPoczatek(nullptr), m_nLiczbaPracownikow(0)
{
}

ListaPracownikow::~ListaPracownikow()
{
	auto n1 = this->m_pPoczatek;
	while (n1)
	{
		auto next = n1->m_pNastepny;
		delete n1;                         
		n1 = next;                    
	}
	delete this;
}

void ListaPracownikow::Dodaj(Pracownik &p)
{
	m_nLiczbaPracownikow++;
	auto pp = m_pPoczatek;
	if (pp == nullptr) { 
		m_pPoczatek = &p;
		return;
	}
	while (pp->m_pNastepny != nullptr)
		pp = pp->m_pNastepny;
	pp->m_pNastepny = &p;
}
 
void ListaPracownikow::Usun(const Pracownik & wzorzec)
{
	//brak
	if (m_nLiczbaPracownikow == 0)
		return;

	m_nLiczbaPracownikow--;
	//pierwszy
	if (m_pPoczatek->Porownaj(wzorzec) == 0) {
		auto nastepny = m_pPoczatek->m_pNastepny;
		m_pPoczatek = nastepny;
		
		return;
	}

	//inny niz pierwszy
	Pracownik* p = m_pPoczatek, *pp = m_pPoczatek->m_pNastepny;
	while (pp != nullptr) {
		if (pp->Porownaj(wzorzec) == 0) {
			p->m_pNastepny = pp->m_pNastepny;
			return;
		}
		p = pp;
		pp = pp->m_pNastepny;
	}
}

void ListaPracownikow::WypiszPracownikow() const
{
	if (m_nLiczbaPracownikow == 0)
		std::cout<< "\t brak ludzi, bieda w zakladzie produkcjnym..." << std::endl;
	auto p = m_pPoczatek;
	while(p != nullptr) {
		//std::cout << "PRACOWNIK, dane osobowe: " << *p << std::endl;
		p->Wypiszdane();
		p = p->m_pNastepny;
	}
}

const Pracownik * ListaPracownikow::Szukaj(const char * nazwisko, const char * imie) const
{
	auto p = m_pPoczatek;
	while (p != nullptr) {
		if (p->SprawdzNazwisko(nazwisko) == 0 && p->SprawdzImie(imie) == 0)
			return p;
		p = p->m_pNastepny;
	}
	return nullptr;
}

