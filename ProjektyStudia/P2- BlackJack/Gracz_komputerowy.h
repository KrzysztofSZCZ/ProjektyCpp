#include "Gracz.h"

class Kasyno;

class Gracz_kompuetrowy : public Gracz 
{
	int odwaga_;
	char identyfikator_[5];

public:

	Gracz_kompuetrowy();
	Gracz_kompuetrowy(Kasyno* adres);

	void nadaj_identyfikator(int indeks_gracza_komputerowego);
	void pokaz_identyfikator();
	char* zwroc_identyfikator();

	void wpisz_odwage(int i);
	int zwroc_odwage();

	bool czy_gra_dalej();


};