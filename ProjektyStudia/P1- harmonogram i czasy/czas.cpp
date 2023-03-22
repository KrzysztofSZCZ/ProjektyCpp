#include "czas.h"

void Czas::wpisz_godziny()
{
	int poprawnosc_wpisania_danych = 0;

	while (poprawnosc_wpisania_danych != 1)
	{
		std::cout << "Wpisz godziny" << std::endl;
		std::cin >> godziny_;

		if (godziny_ < 0)
			std::cout << "Wpisano niepoprawna wartosc!" << std::endl;

		else
			poprawnosc_wpisania_danych = 1;
	}
}

void Czas::wpisz_minuty()
{
	int poprawnosc_wpisania_danych = 0;

	while (poprawnosc_wpisania_danych != 1)
	{
		std::cout << "Wpisz minuty" << std::endl;
		std::cin >> minuty_;

		if (minuty_ < 0)
			std::cout << "Wpisano niepoprawna wartosc!" << std::endl;

		else
			poprawnosc_wpisania_danych = 1;
	}
}

void Czas::wpisz_sekudny()
{
	int poprawnosc_wpisania_danych = 0;

	while (poprawnosc_wpisania_danych != 1)
	{
		std::cout << "Wpisz sekundy" << std::endl;
		std::cin >> sekundy_;

		if (sekundy_ < 0)
			std::cout << "Wpisano niepoprawna wartosc!" << std::endl;

		else
			poprawnosc_wpisania_danych = 1;
	}

}

int Czas::zwroc_godziny()
{
	return godziny_;
}

int Czas::zwroc_minuty()
{
	return minuty_;
}

int Czas::zwroc_sekundy()
{
	return sekundy_;
}

void Czas::sprawdz_poprawnosc_wpisania_czasu()
{

	if (sekundy_ >= 60)
	{
		int modulo_sekund = sekundy_ % 60;

		minuty_ += (sekundy_ - modulo_sekund) / 60;
		sekundy_ = modulo_sekund;
	}

	if (minuty_ >= 60)
	{
		int modulo_minut = minuty_ % 60;

		godziny_ += (minuty_ - modulo_minut) / 60;
		minuty_ = modulo_minut;
	}
}

Czas Czas::operator+(Czas &dodawany)
{
	sekundy_ + dodawany.sekundy_;
	minuty_ + dodawany.minuty_;
	godziny_ + dodawany.godziny_;

	return *this;
}

Czas Czas::operator+=(int dodawane_sekundy)
{
	sekundy_ += dodawane_sekundy;

	return *this;
}

void Czas::pokaz_czas()
{
	std::cout << godziny_ << ":" << minuty_ << ":" << sekundy_ << std::endl;
}

bool Czas::operator==(Czas porownywany)
{
	if (sekundy_ != porownywany.sekundy_)
		return false;
	
	else
	{
		if (minuty_ != porownywany.minuty_)
			return false;

		else
		{
			if (godziny_ != porownywany.godziny_)
				return false;
			
			else
				return true;
		}
	}
}

bool Czas::operator<(Czas porownywany)
{
	if (godziny_ < porownywany.godziny_)
		return true;

	else
	{
		if (minuty_ < porownywany.minuty_)
			return true;

		else
		{
			if (sekundy_ < porownywany.sekundy_)
				return true;

			else
				return false;
		}
	}
}

Czas::Czas(int podane_godziny, int podane_minuty, int podane_sekundy)
{
	
	if (podane_godziny < 0 || podane_minuty < 0 || podane_sekundy < 0)
	{
		std::cout << "Podano niedozwolone wartosci czasu. Czas zostanie utworzony i wyzerowany!" << std::endl;

		godziny_ = 0;
		minuty_ = 0;
		sekundy_ = 0;

	}

	else 
	{
		godziny_ = podane_godziny;
		minuty_ = podane_minuty;
		sekundy_ = podane_sekundy;
	}
}

Czas::Czas(int podane_minuty, int podane_sekundy)
{
	if (podane_minuty < 0 || podane_sekundy < 0)
	{
		std::cout << "Podano niedozwolone wartosci czasu. Czas zostanie utworzony i wyzerowany!" << std::endl;

		godziny_ = 0;
		minuty_ = 0;
		sekundy_ = 0;

	}

	else
	{
		godziny_ = 0;
		minuty_ = podane_minuty;
		sekundy_ = podane_sekundy;
	}
}

Czas::Czas(int podane_sekundy)
{
	if (podane_sekundy < 0)
	{
		std::cout << "Podano niedozwolone wartosci czasu. Czas zostanie utworzony i wyzerowany!" << std::endl;

		godziny_ = 0;
		minuty_ = 0;
		sekundy_ = 0;

	}

	else
	{
		godziny_ = 0;
		minuty_ = 0;
		sekundy_ = podane_sekundy;
	}
}

Czas::Czas()
{
	godziny_ = 0;
	minuty_ = 0;
	sekundy_ = 0;
}


Czas Czas::operator=(Czas &zrownywany)
{
	godziny_ = zrownywany.godziny_;
	minuty_ = zrownywany.minuty_;
	sekundy_ = zrownywany.sekundy_;

	return *this;
}

void Czas::sumuj_czas(Czas dodawany)
{
	sekundy_ += dodawany.sekundy_;
	minuty_ += dodawany.minuty_;
	godziny_ += dodawany.godziny_;
}

Czas::~Czas()
{

}