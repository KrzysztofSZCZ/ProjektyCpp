#include "Gracz.h"
#include "Karta.h"
#include "Gracz_komputerowy.h"
#include <time.h>
#include <string.h>
#include <windows.h>
#include <algorithm>
#include <fstream>

class Kasyno {

	Karta talia_kart_[52];
	int dawana_karta_;

	Gracz* lista_graczy_;
	Gracz_kompuetrowy* lista_graczy_komputerowych_;
	int liczba_graczy_komputerowych_w_grze_;
	int liczba_graczy_w_grze_;

	int czy_jest_zwyciesca_;
	int czy_wszyscy_przegrali_;

	bool czy_pierwsza_gra_;



public:
	Kasyno();

	void tasuj_talie();
	Karta* daj_karte();

	void ilu_graczy_gra();
	void ilu_graczy_komputerowych_gra();

	void graj();
	void spasuj_za_gracza(Gracz za_ktorego_pasuje);
	void zacznij_nowa_gre();
	int czy_zaczac_nowa_gre();
	
	void koniec_gry();

	void wpisz_do_pliku_tekstowego();

	bool czy_wszyscy_przegrali();

	void ktory_gracz_wygral(int indeks_gracza);
	void ktory_gracz_komputerowy_wygral(int indeks_gracza);


};
