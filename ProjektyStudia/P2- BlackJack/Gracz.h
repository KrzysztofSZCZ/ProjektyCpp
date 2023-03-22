#pragma once
#include <iostream>
#include"Karta.h"
#include<string>


class Kasyno;

class Gracz 
{

protected:

	Karta karty_w_rece_[10];
	int liczba_kart_na_rece_;

	char nazwa_gracza_[20];

	int suma_punktow_;

	int czy_spasowal_;
	int czy_przekroczyl_liczbe_punktow_;
	bool czy_wygral_;

	Kasyno* adres_kasyna_;

public:

	void wez_karte(Karta* karta_brana);
	void pokaz_karty_z_reki();
	int zwroc_liczbe_kart();
	char zwroc_karty_kolor(int i);
	char zwroc_karty_figura(int i);


	Gracz();
	void ustaw_adres(Kasyno* adres);

	void wpisz_nazwe_gracza();
	void pokaz_nazwe_gracza();
	char* zwroc_nazwe_gracza();

	void spasuj_lub_graj();
	void spasuj_automatycznie();
	int zwroc_czy_gracz_spasowal();
	bool czy_wygral();

	void przegraj_automatycznie();
	int zwroc_czy_przekroczyl_liczbe_punktow();

	int zwroc_liczbe_punktow();
	void sumuj_punkty();
	void wyswietl_liczbe_punktow();
	void zeruj_punkty();

	bool zwroc_czy_wygral();
	void ustaw_czy_gracz_wygral();


};