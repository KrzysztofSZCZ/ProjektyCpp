#include "Grzejnik.h"

Grzejnik::Grzejnik() : moc_nominalna_(2000), aktualny_poziom_mocy_(0)
{

}

float Grzejnik::zwroc_aktualny_poziom_mocy()
{
	return aktualny_poziom_mocy_;
}

float Grzejnik::zwroc_moc_nominalna()
{
	return moc_nominalna_;
}

void Grzejnik::ustaw_poziom_mocy(float wpisywany_poziom_mocy)
{
	if (wpisywany_poziom_mocy < 0)
		aktualny_poziom_mocy_ = 0;

	else if (wpisywany_poziom_mocy > 1)
		aktualny_poziom_mocy_ = 1;

	else
		aktualny_poziom_mocy_ = wpisywany_poziom_mocy;
}

float Grzejnik::zwroc_moc_emitowana()
{
	return (aktualny_poziom_mocy_ * moc_nominalna_);
}

float Grzejnik::wpisz_poziom_mocy()
{
	float wpisywany_poziom_mocy;

	while (1)
	{
		std::cout << "Wpisz aktualny poziom mocy w grzejnku. (0-1)" << std::endl;

		std::cin >> wpisywany_poziom_mocy;

		if (std::cin.fail() == true) {
			std::cout << "Wpisano znak o niepoprawnym typie! Prosze wpisac ponownie" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}

		else if (wpisywany_poziom_mocy < 0 || wpisywany_poziom_mocy > 1)
			std::cout << "Wpisano cyfrê z niepoprawnego zakresu! Proszê wpisaæ ponownie!" << std::endl;

		else break;
	}

	return wpisywany_poziom_mocy;
}