#include "czas.h"

class Harmonogram
{
private:

	Czas* element_harmonogramu_;
	int liczba_czasow_w_harmonogramie_;

public:

	void dodaj_czas_do_harmonogramu(Czas alokowany);

	Harmonogram();
	//~Harmonogram();

	int zwroc_liczbe_czasow();
	Czas zwroc_podany_czas(int indeks_zwracanego_czasu);

	Czas sumuj_wszystkie_czasy();
	void zwroc_wszystkie_czasy();

	Harmonogram(const Harmonogram &inny, int liczba_kopiowanych_czasow);

	void operator=(const Harmonogram &inny);

	void dodaj_sekundy_do_czasu(int dodane_sekundy, int numer_czasu);


};
