#pragma once

#include <iostream>
#include <string>

using namespace std;
class Data
{
public:
	Data(int d=1, int m=1, int r=1950);
	~Data();

	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Koryguj();
	int Porownaj(const Data & wzor) const ;
	void Ustaw(int d, int m, int r);
	string ToString();

	friend ostream & operator<<(ostream & wy, const Data & d);
	friend istream & operator>>(istream & we, Data & d);

private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;

	bool Przestepny();
};

