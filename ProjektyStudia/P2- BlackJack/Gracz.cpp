#include "Gracz.h"

void Gracz::wez_karte(Karta* karta_dobierana)
{
	karty_w_rece_[liczba_kart_na_rece_] = *karta_dobierana;

	liczba_kart_na_rece_++;
}

void Gracz::pokaz_karty_z_reki()
{
	std::cout << "Twoje karty na rece to: " << std::endl;

	for (int i = 0; i < liczba_kart_na_rece_; i++)
	{
		karty_w_rece_[i].wypisz();
		std::cout << std::endl;
	}
}

Gracz::Gracz() : liczba_kart_na_rece_(0), czy_spasowal_(0), suma_punktow_(0), czy_przekroczyl_liczbe_punktow_(0), czy_wygral_(false)
{

}

int Gracz::zwroc_czy_gracz_spasowal()
{
	if (czy_spasowal_ == 1)
		return 1;

	else
		return 0;
}

void Gracz::spasuj_lub_graj()
{

	int decyzja_gracza;

	while (1) {
		std::cout << "Czy chcesz spasowac? TAK (wpisz 1), NIE (wpisz 0)" << std::endl;

		std::cin >> decyzja_gracza;
		if (std::cin.fail() == true) {
			std::cout << "Wpisano znak o niepoprawnym typie! Prosze wpisac ponownie" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}

		else if (decyzja_gracza != 0 && decyzja_gracza != 1)
			std::cout << "Wpisano cyfrê z niepoprawnego zakresu! Proszê wpisaæ ponownie!" << std::endl;

		else break;
	}

	if (decyzja_gracza == 1)
		czy_spasowal_ = 1;

}

void Gracz::spasuj_automatycznie()
{
	czy_spasowal_ = 1;
}

int Gracz::zwroc_liczbe_punktow()
{
	return suma_punktow_;
}

void Gracz::sumuj_punkty()
{
	suma_punktow_ = 0;
	for (int i = 0; i < liczba_kart_na_rece_; i++)
		suma_punktow_ += karty_w_rece_[i].getWartosc();
}

void Gracz::wyswietl_liczbe_punktow()
{
	std::cout << "Suma punktow wynosi: " << suma_punktow_ << std::endl;
}

int Gracz::zwroc_czy_przekroczyl_liczbe_punktow()
{
	return czy_przekroczyl_liczbe_punktow_;
}

void Gracz::przegraj_automatycznie()
{
	czy_przekroczyl_liczbe_punktow_ = 1;
	suma_punktow_ = 0;
}

void Gracz::zeruj_punkty()
{
	suma_punktow_ = 0;
}

void Gracz::wpisz_nazwe_gracza()
{
	std::cout << "Wpisz nazwe gracza" << std::endl;
	std::cin.getline(nazwa_gracza_, 20);

}

void Gracz::pokaz_nazwe_gracza()
{
	std::cout << nazwa_gracza_ << std::endl;
}

void Gracz::ustaw_adres(Kasyno* adres)
{
	adres_kasyna_ = adres;
}

char* Gracz::zwroc_nazwe_gracza()
{
	return nazwa_gracza_;
}

int Gracz::zwroc_liczbe_kart()
{
	return liczba_kart_na_rece_;
}

char Gracz::zwroc_karty_kolor(int i)
{

	return karty_w_rece_[i].getKolor();
}

char Gracz::zwroc_karty_figura(int i)
{
	return karty_w_rece_[i].getFigura();
}

bool Gracz::czy_wygral()
{
	if (czy_wygral_ == true)
		return true;
	else
		return false;
}

bool Gracz::zwroc_czy_wygral()
{
	return czy_wygral_;
}

void Gracz::ustaw_czy_gracz_wygral()
{
	czy_wygral_ = true;
}