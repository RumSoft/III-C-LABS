#include "stdafx.h"
#include "Napis.h"
#include <string>

//disable strcpy warning
#pragma warning(disable:4996)

using namespace std;

Napis::Napis(const char * nap)
{
	this->Ustaw(nap);
}

Napis::Napis(const Napis & wzor)
{
	this->Ustaw(wzor.Zwroc());
}

Napis::~Napis()
{
	delete m_pszNapis;
}

const char * Napis::Zwroc() const
{
	return this->m_pszNapis;
}

void Napis::Ustaw(const char * nowy_napis)
{
	const int dl = strlen(nowy_napis);
	m_pszNapis = new char[dl];
	strcpy(m_pszNapis, nowy_napis);
	m_nDl = dl;
}


int Napis::SprawdzNapis(const char * por_napis) const
{
	return strcmp(this->Zwroc(), por_napis);
}

Napis & Napis::operator=(const Napis & wzor)
{
	Ustaw(wzor.Zwroc());
	return *this;
}

bool Napis::operator==(const Napis & wzor) const
{
	return SprawdzNapis(wzor.Zwroc()) == 0;
}

ostream & operator<<(ostream & wy, const Napis & n)
{
	wy << n.Zwroc();
	return wy;
}

istream & operator >> (istream & we, Napis & n)
{
	string str;
	we >> str;
	n.Ustaw(str.c_str());
	return we;
}
