#include "Gracz_komputerowy.h"

Gracz_kompuetrowy::Gracz_kompuetrowy() : odwaga_(0), identyfikator_("Botx")
{
	liczba_kart_na_rece_ = 0;
	czy_spasowal_ = 0;
	czy_przekroczyl_liczbe_punktow_ = 0;
	suma_punktow_ = 0;
}

Gracz_kompuetrowy::Gracz_kompuetrowy(Kasyno* adres) : odwaga_(0), identyfikator_("Botx")
{
	liczba_kart_na_rece_ = 0;
	czy_spasowal_ = 0;
	czy_przekroczyl_liczbe_punktow_ = 0;
	suma_punktow_ = 0;

	adres_kasyna_ = adres;
}

void Gracz_kompuetrowy::nadaj_identyfikator(int indeks_gracza_komputerowego)
{
	if (indeks_gracza_komputerowego == 0)
	{
		strcpy_s(identyfikator_, "Bot1");
	}

	else if(indeks_gracza_komputerowego == 1)
	{
		strcpy_s(identyfikator_, "Bot2");
	}

	else
	{
		strcpy_s(identyfikator_, "Bot3");
	}
}

void Gracz_kompuetrowy::pokaz_identyfikator()
{
	std::cout << identyfikator_ << std::endl;
}

void Gracz_kompuetrowy::wpisz_odwage(int i)
{

	std::cout << "Wpisz odwage gracza " << (i + 1) << std::endl;
	while (1) {
		std::cout << "Jak odwazny ma byc gracz komputerowy? Wpisz: 1 (rozwazny), 2 (normalny), 3 (ryzykujacy)." << std::endl;

		std::cin >> odwaga_;
		if (std::cin.fail() == true) {
			std::cout << "Wpisano znak o niepoprawnym typie! Prosze wpisac ponownie" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}

		else if (odwaga_ < 1 || odwaga_ > 3)
			std::cout << "Wpisano cyfrê z niepoprawnego zakresu! Proszê wpisaæ ponownie!" << std::endl;

		else break;
	}

}

char* Gracz_kompuetrowy::zwroc_identyfikator()
{
	return identyfikator_;
}

int Gracz_kompuetrowy::zwroc_odwage()
{
	return odwaga_;
}

bool Gracz_kompuetrowy::czy_gra_dalej()
{
	if (odwaga_ == 1)
	{
		if (suma_punktow_ > 15)
			return false;
		else
			return true;
	}

	else if (odwaga_ == 2)
	{
		if (suma_punktow_ > 16)
			return false;
		else
			return true;
	}

	else
	{
		if (suma_punktow_ > 18)
			return false;
		else
			return true;
	}
}