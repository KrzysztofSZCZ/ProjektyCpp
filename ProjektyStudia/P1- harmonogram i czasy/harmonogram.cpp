#include "harmonogram.h"

void Harmonogram::dodaj_czas_do_harmonogramu(Czas alokowany)
{

	Czas* chwilowy = new Czas[liczba_czasow_w_harmonogramie_ + 1];

	if (liczba_czasow_w_harmonogramie_ != 0)
	{


		for (int i = 0; i < liczba_czasow_w_harmonogramie_; i++)
			chwilowy[i] = element_harmonogramu_[i];

		chwilowy[liczba_czasow_w_harmonogramie_] = alokowany;

		delete[] element_harmonogramu_;

		element_harmonogramu_ = chwilowy;

		for (int j = 0; j < (liczba_czasow_w_harmonogramie_ + 1); j++)
			element_harmonogramu_[j] = chwilowy[j];

	}

	else
	{
		element_harmonogramu_ = chwilowy;

		chwilowy[0] = alokowany;

		element_harmonogramu_[0] = chwilowy[0];
	}
	
	liczba_czasow_w_harmonogramie_++;
}


int Harmonogram::zwroc_liczbe_czasow()
{
	return liczba_czasow_w_harmonogramie_;
}

Czas Harmonogram::zwroc_podany_czas(int indeks_czasu_zwracanego)
{
	return element_harmonogramu_[indeks_czasu_zwracanego];
}

Czas Harmonogram::sumuj_wszystkie_czasy()
{
	Czas suma_czasow;

	for (int i = 0; i < liczba_czasow_w_harmonogramie_; i++)
	{
		suma_czasow.sumuj_czas(element_harmonogramu_[i]);
	}

	return suma_czasow;

}

void Harmonogram::zwroc_wszystkie_czasy()
{

	for (int i = 0; i < liczba_czasow_w_harmonogramie_; i++)
	{

		std::cout << "Czas" << i + 1 << "- ";
		element_harmonogramu_[i].pokaz_czas();
		std::cout << std::endl;

	}
}

Harmonogram::Harmonogram(const Harmonogram& inny, int liczba_kopiowanych_czasow)
{
	liczba_czasow_w_harmonogramie_ = liczba_kopiowanych_czasow;
	element_harmonogramu_ = new Czas[liczba_czasow_w_harmonogramie_];

	for (int i = 0; i < liczba_kopiowanych_czasow; i++)
	{
		 element_harmonogramu_[i] = inny.element_harmonogramu_[i];
	}

}

void Harmonogram::operator=(const Harmonogram& inny)
{
	liczba_czasow_w_harmonogramie_ = inny.liczba_czasow_w_harmonogramie_;
	
	delete[] element_harmonogramu_;

	element_harmonogramu_ = new Czas[liczba_czasow_w_harmonogramie_];

	for (int i = 0; i < liczba_czasow_w_harmonogramie_; i++)
		element_harmonogramu_[i] = inny.element_harmonogramu_[i];
}

Harmonogram::Harmonogram() : liczba_czasow_w_harmonogramie_(0)
{

}

void Harmonogram::dodaj_sekundy_do_czasu(int dodane_sekundy, int numer_czasu)
{
	element_harmonogramu_[numer_czasu - 1] += dodane_sekundy;

	element_harmonogramu_[numer_czasu - 1].sprawdz_poprawnosc_wpisania_czasu();
}

