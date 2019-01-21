#include "stdafx.h"
#include "Data.h"
#include <string>
#include <iostream>

using namespace std;


Data::Data(int d, int m, int r) : m_nDzien(d), m_nMiesiac(m), m_nRok(r)
{
}

Data::~Data()
{
}

int Data::Dzien() const
{
	return m_nDzien;
}

int Data::Miesiac() const
{
	return m_nMiesiac;
}

int Data::Rok() const
{
	return m_nRok;
}

void Data::Koryguj()
{
	if (m_nMiesiac > 12) m_nMiesiac = 12;
	else if (m_nMiesiac < 1) m_nMiesiac = 1;
	
	if (m_nDzien < 1)
		m_nDzien = 1;

	int dniNaMiesiac[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (m_nDzien > dniNaMiesiac[m_nMiesiac - 1])
		m_nDzien = dniNaMiesiac[m_nMiesiac - 1];
	
	if (m_nMiesiac == 2 && m_nDzien == 29 && !Przestepny())
		m_nDzien = 28;

}

int Data::Porownaj(const Data & wzor) const
{
	int d1 = this->Rok() * 10000 + Miesiac() * 100 + this->Dzien();
	int d2 = wzor.Rok() * 10000 + wzor.Miesiac() * 100 + wzor.Dzien();
	if (d1 > d2)
		return 1;
	if (d1 < d2)
		return -1;
	return 0;
}

void Data::Ustaw(int d, int m, int r)
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
	Data::Koryguj();
}

string Data::ToString()
{
	string str;
	str.append(to_string(Dzien()));
	str.append("-");
	str.append(to_string(Miesiac()));
	str.append("-");
	str.append(to_string(Rok()));
	return str;
}


bool Data::Przestepny()
{
	return (Rok() % 4 == 0 && Rok() % 100 != 0) || (Rok() % 400 == 0);
}

ostream & operator<<(ostream & wy, const Data & d)
{
	wy << d.Dzien() << " " << d.Miesiac() << " " << d.Rok();
	return wy;
}

istream & operator>>(istream & we, Data & d)
{
	int dz, m, r;
	we >> dz >> m >> r;
	d.Ustaw(dz,m,r);
	return we;
}
