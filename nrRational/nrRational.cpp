#include "pch.h"
#include <iostream>
#include <string>


class nrRational
{
public:
	nrRational(int, int);
	nrRational(const nrRational &);
	~nrRational();

	void setFractie(int numarator, int numitor);
	void setNumarator(int numarator);
	int getNumarator();
	void setNumitor(int numitor);
	int getNumitor();

	nrRational operator+=(int);
	nrRational operator+=(nrRational);
	nrRational operator-=(int);
	nrRational operator-=(nrRational);
	nrRational operator*=(int);
	nrRational operator*=(nrRational);
	nrRational operator/=(int);
	nrRational operator/=(nrRational);

	friend nrRational operator+(const nrRational&);
	friend nrRational operator-(const nrRational&);

	friend nrRational operator+(const nrRational&, const nrRational&);
	friend nrRational operator+(const nrRational&, int);
	friend nrRational operator+(int, const nrRational&);
	friend nrRational operator-(const nrRational&, const nrRational&);
	friend nrRational operator-(const nrRational&, int);
	friend nrRational operator-(int, const nrRational&);
	friend nrRational operator*(const nrRational&, const nrRational&);
	friend nrRational operator*(const nrRational&, int);
	friend nrRational operator*(int, const nrRational&);
	friend nrRational operator/(const nrRational&, const nrRational&);
	friend nrRational operator/(const nrRational&, int);
	friend nrRational operator/(int, const nrRational&);
	friend nrRational operator^(const nrRational&, int);

	std::string toString();

	friend bool operator==(const nrRational&, const nrRational&);
	friend bool operator==(int, const nrRational&);
	friend bool operator==(const nrRational&, int);
	friend bool operator!=(const nrRational&, const nrRational&);
	friend bool operator!=(int, const nrRational&);
	friend bool operator!=(const nrRational&, int);
	friend bool operator<(const nrRational&, const nrRational&);
	friend bool operator<(int, const nrRational&);
	friend bool operator<(const nrRational&, int);
	friend bool operator<=(const nrRational&, const nrRational&);
	friend bool operator<=(int, const nrRational&);
	friend bool operator<=(const nrRational&, int);
	friend bool operator>(const nrRational&, const nrRational&);
	friend bool operator>(int, const nrRational&);
	friend bool operator>(const nrRational&, int);
	friend bool operator>=(const nrRational&, const nrRational&);
	friend bool operator>=(int, const nrRational&);
	friend bool operator>=(const nrRational&, int);

	operator double();
	operator int();
	operator std::string();

	friend std::istream& operator>>(std::istream& in, nrRational &fractie);
	friend std::ostream& operator<<(std::ostream& out, nrRational &fractie);

private:
	int mNumarator, mNumitor;
	void formaCanonica();

};

nrRational::nrRational(int numarator = 0, int numitor = 1)
{
	mNumarator = numarator;
	mNumitor = numitor;
	formaCanonica();
}
nrRational::nrRational(const nrRational &fractie)
{
	mNumarator = fractie.mNumarator;
	mNumitor = fractie.mNumitor;
}

nrRational::~nrRational() {}

void nrRational::setFractie(int numarator, int numitor)
{
	mNumarator = numarator;
	mNumitor = numitor;
	formaCanonica();
}

void nrRational::setNumarator(int numarator)
{
	mNumarator = numarator;
	formaCanonica();
}

int nrRational::getNumarator()
{
	return mNumarator;
}

void nrRational::setNumitor(int numitor)
{
	mNumitor = numitor;
	formaCanonica();
}

int nrRational::getNumitor()
{
	return mNumitor;
}

void nrRational::formaCanonica()
{
	int numi, numa;
	numi = mNumitor;
	numa = mNumarator;
	while (numi != 0)
	{
		int temp = numa % numi;
		numa = numi;
		numi = temp;
	}
	mNumitor = mNumitor / numa;
	mNumarator = mNumarator / numa;
}

nrRational nrRational::operator+=(int x)
{
	mNumarator += x * mNumitor;
	formaCanonica();
	return *this;
}

nrRational nrRational::operator+=(nrRational fractie)
{
	mNumarator = mNumarator * fractie.mNumitor + mNumitor * fractie.mNumarator;
	mNumitor = mNumitor * fractie.mNumitor;
	formaCanonica();;
	return *this;
}

nrRational nrRational::operator-=(int x)
{
	mNumarator -= x * mNumitor;
	formaCanonica();
	return *this;
}

nrRational nrRational::operator-=(nrRational fractie)
{
	mNumarator = mNumarator * fractie.mNumitor - fractie.mNumarator * mNumitor;
	mNumitor = mNumitor * fractie.mNumitor;
	formaCanonica();
	return *this;
}

nrRational nrRational::operator*=(int x)
{
	mNumarator *= x;
	formaCanonica();
	return *this;
}

nrRational nrRational::operator*=(nrRational fractie)
{
	mNumarator = mNumarator * fractie.mNumarator;
	mNumitor = mNumitor * fractie.mNumitor;
	formaCanonica();
	return *this;
}

nrRational nrRational::operator/=(int x)
{
	mNumitor *= x;
	formaCanonica();
	return *this;
}

nrRational nrRational::operator/=(nrRational fractie)
{
	mNumarator = mNumarator * fractie.mNumitor;
	mNumitor = mNumitor * fractie.mNumarator;
	formaCanonica();
	return *this;
}

nrRational operator+(const nrRational& fractie)
{
	return nrRational(fractie.mNumarator, fractie.mNumitor);
}

nrRational operator-(const nrRational& fractie)
{
	return nrRational(0-fractie.mNumarator, fractie.mNumitor);
}

nrRational operator+(const nrRational& fractie1, const nrRational& fractie2)
{
	nrRational suma;
	suma.mNumarator = fractie1.mNumarator * fractie2.mNumitor + fractie1.mNumitor * fractie2.mNumarator;
	suma.mNumitor = fractie1.mNumitor * fractie2.mNumitor;
	suma.formaCanonica();
	return suma;
}

nrRational operator+(const nrRational& fractie1, int nr)
{
	nrRational suma;
	suma.mNumarator = fractie1.mNumarator  + fractie1.mNumitor * nr;
	suma.formaCanonica();
	return suma;
}

nrRational operator+(int nr, const nrRational& fractie1)
{
	nrRational suma;
	suma.mNumarator = fractie1.mNumarator + fractie1.mNumitor * nr;
	suma.formaCanonica();
	return suma;
}

nrRational operator-(const nrRational& fractie1, const nrRational& fractie2)
{
	nrRational diferenta;
	diferenta.mNumarator = fractie1.mNumarator * fractie2.mNumitor - fractie2.mNumarator * fractie1.mNumitor;
	diferenta.mNumitor = fractie1.mNumitor * fractie2.mNumitor;
	diferenta.formaCanonica();
	return diferenta;
}

nrRational operator-(const nrRational& fractie1, int nr)
{
	nrRational diferenta;
	diferenta.mNumarator = fractie1.mNumarator - nr * fractie1.mNumitor;
	diferenta.formaCanonica();
	return diferenta;
}

nrRational operator-(int nr, const nrRational& fractie1)
{
	nrRational diferenta;
	diferenta.mNumarator = fractie1.mNumarator - nr * fractie1.mNumitor;
	diferenta.formaCanonica();
	return diferenta;
}

nrRational operator*(const nrRational& fractie1, const nrRational& fractie2)
{
	nrRational produs;
	produs.mNumarator =fractie1. mNumarator * fractie2.mNumarator;
	produs.mNumitor =fractie1.mNumitor * fractie2.mNumitor;
	produs.formaCanonica();
	return produs;
}

nrRational operator*(const nrRational& fractie1, int nr)
{
	nrRational produs;
	produs.mNumarator = fractie1.mNumarator * nr;
	produs.formaCanonica();
	return produs;
}

nrRational operator*(int nr, const nrRational& fractie1)
{
	nrRational produs;
	produs.mNumarator = fractie1.mNumarator * nr;
	produs.formaCanonica();
	return produs;
}

nrRational operator/(const nrRational& fractie1, const nrRational& fractie2)
{
	nrRational rezultat;
	rezultat.mNumarator = fractie1.mNumarator * fractie2.mNumitor;
	rezultat.mNumitor = fractie1.mNumitor * fractie2.mNumarator;
	rezultat.formaCanonica();
	return rezultat;
}

nrRational operator/(const nrRational& fractie1, int nr)
{
	nrRational rezultat;
	rezultat.mNumitor = fractie1.mNumitor * nr;
	rezultat.formaCanonica();
	return rezultat;
}

nrRational operator/(int nr, const nrRational& fractie1)
{
	nrRational rezultat;
	rezultat.mNumitor = fractie1.mNumitor * nr;
	rezultat.formaCanonica();
	return rezultat;
}

nrRational operator^(const nrRational& fractie, int putere)
{
	nrRational rezultat;
	rezultat.mNumarator = pow(fractie.mNumarator, putere);
	rezultat.mNumitor = pow(fractie.mNumitor, putere);
	rezultat.formaCanonica();
	return rezultat;
}

std::string nrRational::toString()
{
	std::string s;
	if (mNumarator == 0 || mNumitor == 1)    s = std::to_string(mNumarator);
	else s = std::to_string(mNumarator) + "/" + std::to_string(mNumitor);
	return s;
}

bool operator==(const nrRational& fractie1, const nrRational& fractie2)
{
	return fractie1.mNumarator == fractie2.mNumarator && fractie1.mNumitor == fractie2.mNumitor;
}

bool operator==(int nr, const nrRational& fractie)
{
	return nr * fractie.mNumitor == fractie.mNumarator;
}

bool operator==(const nrRational& fractie, int nr)
{
	return nr * fractie.mNumitor == fractie.mNumarator;
}

bool operator!=(const nrRational& fractie1, const nrRational& fractie2)
{
	return !(fractie1.mNumarator == fractie2.mNumarator && fractie1.mNumitor == fractie2.mNumitor);
}

bool operator!=(int nr, const nrRational& fractie)
{
	return !(nr * fractie.mNumitor == fractie.mNumarator);
}

bool operator!=(const nrRational& fractie, int nr)
{
	return !(nr * fractie.mNumitor == fractie.mNumarator);
}

bool operator<(const nrRational& fractie1, const nrRational& fractie2)
{
	return fractie1.mNumarator*fractie2.mNumitor < fractie1.mNumitor*fractie2.mNumarator;
}

bool operator<(int nr, const nrRational& fractie)
{
	return nr * fractie.mNumitor < fractie.mNumarator;
}

bool operator<(const nrRational& fractie, int nr)
{
	return fractie.mNumarator < nr*fractie.mNumitor;
}

bool operator<=(const nrRational& fractie1, const nrRational& fractie2)
{
	return fractie1.mNumarator*fractie2.mNumitor <= fractie1.mNumitor*fractie2.mNumarator;
}

bool operator<=(int nr, const nrRational& fractie)
{
	return nr * fractie.mNumitor <= fractie.mNumarator;
}

bool operator<=(const nrRational& fractie, int nr)
{
	return fractie.mNumarator <= nr*fractie.mNumitor;
}

bool operator>(const nrRational& fractie1, const nrRational& fractie2)
{
	return fractie1.mNumarator*fractie2.mNumitor > fractie1.mNumitor*fractie2.mNumarator;
}

bool operator>(int nr, const nrRational& fractie)
{
	return nr * fractie.mNumitor > fractie.mNumarator;
}

bool operator>(const nrRational& fractie, int nr)
{
	return fractie.mNumarator > nr*fractie.mNumitor;
}

bool operator>=(const nrRational& fractie1, const nrRational& fractie2)
{
	return fractie1.mNumarator*fractie2.mNumitor >= fractie1.mNumitor*fractie2.mNumarator;
}

bool operator>=(int nr, const nrRational& fractie)
{
	return nr * fractie.mNumitor >= fractie.mNumarator;
}

bool operator>=(const nrRational& fractie, int nr)
{
	return fractie.mNumarator > nr*fractie.mNumitor;
}

nrRational::operator int()
{
	return mNumarator / mNumitor;
}

nrRational::operator double()
{
	return (double)mNumarator / mNumitor;
}

nrRational::operator std::string()
{
	return toString();
}

std::istream& operator>>(std::istream& in, nrRational &fractie)
{
	in >> fractie.mNumarator >> fractie.mNumitor;
	return in;
}

std::ostream& operator<<(std::ostream& out, nrRational &fractie)
{
	fractie.formaCanonica();
	if (fractie.mNumarator == 0 || fractie.mNumitor == 1) std::cout << fractie.mNumarator << '\n';
	else std::cout << fractie.mNumarator << "/" << fractie.mNumitor << '\n';
	return out;
}

int main()
{
	nrRational f1, f2, s, p, exp;
	std::cin >> f1 >> f2;
	std::cout << f1 << f2 << '\n';

	/*
		std::cout<<f1.toString()<<'\n';
		s = f1 + f2;
		std::cout << "Suma="<<s;

		p = f1 * f2;
		std::cout<<"Produs = "<<p;

		if (f1 == f2) std::cout<<"egale"<<'\n';
			else std::cout<<"nu"<<'\n';
*/



	system("pause");
	return 0;
}
