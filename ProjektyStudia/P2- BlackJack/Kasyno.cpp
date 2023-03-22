#include "Kasyno.h"

Kasyno::Kasyno() : dawana_karta_(0), liczba_graczy_w_grze_(0), czy_jest_zwyciesca_(0), czy_pierwsza_gra_(true), liczba_graczy_komputerowych_w_grze_(0)
{
	ilu_graczy_gra();
	ilu_graczy_komputerowych_gra();
}

void Kasyno::tasuj_talie()
{
	srand(time(NULL));
	Karta chwilowa;

	int karta1, karta2;
	int liczba_tasowan = 0;

	while (liczba_tasowan != 100)
	{

		karta1 = rand() % 52;
		karta2 = rand() % 52;

		if (karta1 == karta2)
			liczba_tasowan++;

		else
		{
			chwilowa = talia_kart_[karta1];
			talia_kart_[karta1] = talia_kart_[karta2];
			talia_kart_[karta2] = chwilowa;

			liczba_tasowan++;
		}
	}

}

Karta* Kasyno::daj_karte()
{
	return &talia_kart_[dawana_karta_++];
}

void Kasyno::graj()
{

	while (1)
	{
		int k = 0;

		if (czy_pierwsza_gra_ == false)
		{
			zacznij_nowa_gre();
		}

		if (czy_pierwsza_gra_ == true)
		{
			for (int o = 0; o < 4; o++)
			{
				for (int p = 0; p < 13; p++)
				{
					talia_kart_[k] = Karta(o, p);
					k++;
				}
			}
			czy_pierwsza_gra_ = false;
		}

		else
		{
			ilu_graczy_gra();
			ilu_graczy_komputerowych_gra();
		}

		Karta dawana_graczowi;

		tasuj_talie();

		for (int i = 0; i < liczba_graczy_w_grze_; i++)
		{
			dawana_graczowi = *daj_karte();

			lista_graczy_[i].wez_karte(&dawana_graczowi);

			dawana_graczowi = *daj_karte();

			lista_graczy_[i].wez_karte(&dawana_graczowi);
		}

		for (int i = 0; i < liczba_graczy_komputerowych_w_grze_; i++)
		{
			dawana_graczowi = *daj_karte();

			lista_graczy_komputerowych_[i].wez_karte(&dawana_graczowi);

			dawana_graczowi = *daj_karte();

			lista_graczy_komputerowych_[i].wez_karte(&dawana_graczowi);
		}

		while (czy_jest_zwyciesca_ != 1)
		{

			for (int j = 0; j < liczba_graczy_w_grze_; j++)
			{
				system("cls");

				if (lista_graczy_[j].zwroc_czy_gracz_spasowal() != 1)
				{
					std::cout << "Ruch gracza ";
					lista_graczy_[j].pokaz_nazwe_gracza();
					std::cout << std::endl;

					lista_graczy_[j].pokaz_karty_z_reki();

					lista_graczy_[j].sumuj_punkty();

					int liczba_punktow_gracza = lista_graczy_[j].zwroc_liczbe_punktow();

					lista_graczy_[j].wyswietl_liczbe_punktow();

					if (liczba_punktow_gracza >= 20)
					{
						lista_graczy_[j].spasuj_automatycznie();

						if (liczba_punktow_gracza > 21)
						{

							std::cout << "Twoja liczba punktow przekracza 21- przegrales!" << std::endl;
							lista_graczy_[j].przegraj_automatycznie();

							Sleep(1500);
						}
						else if (liczba_punktow_gracza == 21)
						{
							lista_graczy_[j].ustaw_czy_gracz_wygral();
							czy_jest_zwyciesca_ = 1;

						}
					}

					else
					{
						lista_graczy_[j].spasuj_lub_graj();
						if (lista_graczy_[j].zwroc_czy_gracz_spasowal() == 0)
						{
							dawana_graczowi = *daj_karte();
							lista_graczy_[j].wez_karte(&dawana_graczowi);
						}
					}

					Sleep(700);
				}

			}

			for (int j = 0; j < liczba_graczy_komputerowych_w_grze_; j++)
			{
				system("cls");

				if (lista_graczy_komputerowych_[j].zwroc_czy_gracz_spasowal() != 1)
				{
					std::cout << "Ruch gracza ";
					lista_graczy_komputerowych_[j].pokaz_identyfikator();
					std::cout << std::endl;

					lista_graczy_komputerowych_[j].pokaz_karty_z_reki();

					lista_graczy_komputerowych_[j].sumuj_punkty();

					std::cout << "Suma punktow gracza komputerowego wynosi: " << lista_graczy_komputerowych_[j].zwroc_liczbe_punktow() << std::endl;

					Sleep(1500);

					if (lista_graczy_komputerowych_[j].czy_gra_dalej() == true)
					{
						dawana_graczowi = *daj_karte();
						lista_graczy_komputerowych_[j].wez_karte(&dawana_graczowi);
					}

					else
					{
						std::cout << lista_graczy_komputerowych_[j].zwroc_identyfikator() << " Spaowal" << std::endl;
						lista_graczy_komputerowych_[j].spasuj_automatycznie();
						Sleep(1000);
					}

					if (lista_graczy_komputerowych_[j].zwroc_liczbe_punktow() >= 20)
					{
						lista_graczy_[j].spasuj_automatycznie();

						if (lista_graczy_komputerowych_[j].zwroc_liczbe_punktow() > 21)
						{

							std::cout << "Licbza punktow gracza komputerowego przekracza 21- przegral!" << std::endl;
							lista_graczy_komputerowych_[j].przegraj_automatycznie();

							Sleep(1500);
						}
						else if (lista_graczy_komputerowych_[j].zwroc_liczbe_punktow() == 21)
						{
							lista_graczy_komputerowych_[j].ustaw_czy_gracz_wygral();
							czy_jest_zwyciesca_ = 1;

						}
					}
				}
			}

				if (czy_jest_zwyciesca_ == 1)
				{
					system("cls");

					for (int i = 0; i < liczba_graczy_w_grze_; i++)
					{
						ktory_gracz_wygral(i);
					}

					for (int i = 0; i < liczba_graczy_komputerowych_w_grze_; i++)
					{
						ktory_gracz_komputerowy_wygral(i);
					}

					wpisz_do_pliku_tekstowego();

					Sleep(1500);

					if (czy_zaczac_nowa_gre() == 0)
					{
						koniec_gry();
						return;
					}
				}


				int sprawdzenie_czy_gra_sie_skonczyla = 0;

				for (int l = 0; l < liczba_graczy_w_grze_; l++)
					sprawdzenie_czy_gra_sie_skonczyla += lista_graczy_[l].zwroc_czy_gracz_spasowal();

				for (int l = 0; l < liczba_graczy_komputerowych_w_grze_; l++)
					sprawdzenie_czy_gra_sie_skonczyla += lista_graczy_komputerowych_[l].zwroc_czy_gracz_spasowal();

				if (sprawdzenie_czy_gra_sie_skonczyla == (liczba_graczy_w_grze_ + liczba_graczy_komputerowych_w_grze_))
				{
					system("cls");
					int tablica_punktow[6] = { 0, 0, 0, 0, 0, 0 };


					if (czy_wszyscy_przegrali() == true)
					{
						std::cout << "Wszyscy przegrali. HAHA" << std::endl;

						wpisz_do_pliku_tekstowego();

						if (czy_zaczac_nowa_gre() == 0)
						{
							koniec_gry();
							return;
						}

						czy_jest_zwyciesca_ = 1;
					}

					while (czy_jest_zwyciesca_ != 1)
					{
						for (int m = 0; m < liczba_graczy_w_grze_; m++)
						{
							if (lista_graczy_[m].zwroc_liczbe_punktow() > 21)
								lista_graczy_[m].zeruj_punkty();

							tablica_punktow[m] = lista_graczy_[m].zwroc_liczbe_punktow();

						}

						for (int m = 0; m < liczba_graczy_komputerowych_w_grze_; m++)
						{
							if (lista_graczy_komputerowych_[m].zwroc_liczbe_punktow() > 21)
								lista_graczy_komputerowych_[m].zeruj_punkty();

							tablica_punktow[liczba_graczy_w_grze_ + m] = lista_graczy_komputerowych_[m].zwroc_liczbe_punktow();

						}

						std::sort(tablica_punktow, tablica_punktow + 6);

						int najwieksza_liczba_punktow = tablica_punktow[5];

						for (int n = 0; n < liczba_graczy_w_grze_; n++)
						{
							if (lista_graczy_[n].zwroc_liczbe_punktow() == najwieksza_liczba_punktow)
							{
								lista_graczy_[n].ustaw_czy_gracz_wygral();

								ktory_gracz_wygral(n);
							}
						}

						for (int n = 0; n < liczba_graczy_komputerowych_w_grze_; n++)
						{
							if (lista_graczy_komputerowych_[n].zwroc_liczbe_punktow() == najwieksza_liczba_punktow)
							{
								lista_graczy_komputerowych_[n].ustaw_czy_gracz_wygral();
								ktory_gracz_komputerowy_wygral(n);
							}
						}

						wpisz_do_pliku_tekstowego();

						czy_jest_zwyciesca_ = 1;

						for (int r = 0; r < 6; r++)
						{
							tablica_punktow[r] = 0;
						}

						if (czy_zaczac_nowa_gre() == 0)
						{
							koniec_gry();
							return;
						}

						else
						{
							sprawdzenie_czy_gra_sie_skonczyla = 0;
						}
						break;
					}

				}
			
			if (czy_jest_zwyciesca_ == 1)
				break;
		}

	}

}

void Kasyno::ilu_graczy_gra()
{

	while (1) {
		std::cout << " Wpisz ilu graczy ludzkich ma grac. (1-3)" << std::endl;

		std::cin >> liczba_graczy_w_grze_;

		if (std::cin.fail() == true) {
			std::cout << "Wpisano znak o niepoprawnym typie! Prosze wpisac ponownie" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}

		else if (liczba_graczy_w_grze_ < 1 || liczba_graczy_w_grze_> 3)
			std::cout << "Wpisano cyfrê z niepoprawnego zakresu! Proszê wpisaæ ponownie!" << std::endl;

		else break;
	}

	std::cin.ignore(256, '\n');

	lista_graczy_ = new Gracz[liczba_graczy_w_grze_];

	for (int s = 0; s < liczba_graczy_w_grze_; s++)
	{

		lista_graczy_[s].ustaw_adres(this);
		lista_graczy_[s].wpisz_nazwe_gracza();
	}


}

void Kasyno::spasuj_za_gracza(Gracz za_ktorego_pasuje)
{
	za_ktorego_pasuje.spasuj_automatycznie();
}


void Kasyno::zacznij_nowa_gre()
{
	delete[] lista_graczy_;
	delete[] lista_graczy_komputerowych_;

	dawana_karta_ = 0;
	liczba_graczy_w_grze_ = 0;
	liczba_graczy_komputerowych_w_grze_ = 0;
	czy_jest_zwyciesca_ = 0;

}


int Kasyno::czy_zaczac_nowa_gre()
{
	int czy_grac_dalej;

	while (1) {
		std::cout << " Czy chcesz rozpoczac nowa gre? TAK (wpisz 1) NIE (wpisz 0) " << std::endl;

		std::cin >> czy_grac_dalej;

		if (std::cin.fail() == true) {
			std::cout << "Wpisano znak o niepoprawnym typie! Prosze wpisac ponownie" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}

		else if (czy_grac_dalej != 0 && czy_grac_dalej != 1)
			std::cout << "Wpisano cyfrê z niepoprawnego zakresu! Proszê wpisaæ ponownie!" << std::endl;

		else break;
	}

	return czy_grac_dalej;
}

void Kasyno::wpisz_do_pliku_tekstowego()
{
	int czy_zapisac = 0;

	while (1) {
		std::cout << " Czy chcesz zapisac wyniki do pliku tekstowego? TAK (wpisz 1) NIE (wpisz 0) " << std::endl;

		std::cin >> czy_zapisac;

		if (std::cin.fail() == true) {
			std::cout << "Wpisano znak o niepoprawnym typie! Prosze wpisac ponownie" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}

		else if (czy_zapisac != 0 && czy_zapisac != 1)
			std::cout << "Wpisano cyfrê z niepoprawnego zakresu! Proszê wpisaæ ponownie!" << std::endl;

		else break;
	}

	if (czy_zapisac == 1)
	{
		std::ofstream plik;

		char nazwa_pliku[256];

		std::cout << "Podaj nazwe pliku, do ktorego maja zapisac sie wyniki. (Muszisz wpisac rozszerzenie .txt)" << std::endl;
		std::cin >> nazwa_pliku;

		plik.open(nazwa_pliku, std::ofstream::out);

		if (plik.is_open())
		{
			for (int i = 0; i < liczba_graczy_w_grze_; i++)
			{
				lista_graczy_[i].sumuj_punkty();
				plik << lista_graczy_[i].zwroc_nazwe_gracza();

				plik.width(15);
				std::cout.width(15);
				for (int j = 0; j < lista_graczy_[i].zwroc_liczbe_kart(); j++)
				{
					plik << lista_graczy_[i].zwroc_karty_figura(j);

					plik << " ";

					if (lista_graczy_[i].zwroc_karty_kolor(j) == 3)
					{
						plik << "Kier";
					}

					else if (lista_graczy_[i].zwroc_karty_kolor(j) == 4)
					{
						plik << "Karo";
					}

					else if (lista_graczy_[i].zwroc_karty_kolor(j) == 5)
					{
						plik << "Trefl";
					}

					else if (lista_graczy_[i].zwroc_karty_kolor(j) == 6)
					{
						plik << "Pik";
					}

					plik << "  ";

				}


				plik.width(15);
				std::cout.width(15);
				plik << lista_graczy_[i].zwroc_liczbe_punktow();

				plik << std::endl;


			}

			for (int i = 0; i < liczba_graczy_komputerowych_w_grze_; i++)
			{
				lista_graczy_komputerowych_[i].sumuj_punkty();
				plik << lista_graczy_komputerowych_[i].zwroc_identyfikator();

				plik.width(15);
				std::cout.width(15);
				for (int j = 0; j < lista_graczy_komputerowych_[i].zwroc_liczbe_kart(); j++)
				{
					plik << lista_graczy_komputerowych_[i].zwroc_karty_figura(j);

					plik << " ";

					if (lista_graczy_komputerowych_[i].zwroc_karty_kolor(j) == 3)
					{
						plik << "Kier";
					}

					else if (lista_graczy_komputerowych_[i].zwroc_karty_kolor(j) == 4)
					{
						plik << "Karo";
					}

					else if (lista_graczy_komputerowych_[i].zwroc_karty_kolor(j) == 5)
					{
						plik << "Trefl";
					}

					else if (lista_graczy_komputerowych_[i].zwroc_karty_kolor(j) == 6)
					{
						plik << "Pik";
					}

					plik << "  ";

				}


				plik.width(15);
				std::cout.width(15);
				plik << lista_graczy_komputerowych_[i].zwroc_liczbe_punktow();

				plik << std::endl;

			}


		}

		else
		{
			std::cout << "Nie uda³o siê zapisaæ pliku!" << std::endl;
		}

		plik.close();

	}

}

void Kasyno::ilu_graczy_komputerowych_gra()
{
	while (1) {
		std::cout << " Wpisz ilu graczy komputerowych ma grac. (1-3)" << std::endl;

		std::cin >> liczba_graczy_komputerowych_w_grze_;

		if (std::cin.fail() == true) {
			std::cout << "Wpisano znak o niepoprawnym typie! Prosze wpisac ponownie" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}

		else if (liczba_graczy_komputerowych_w_grze_ < 1 || liczba_graczy_komputerowych_w_grze_> 3)
			std::cout << "Wpisano cyfrê z niepoprawnego zakresu! Proszê wpisaæ ponownie!" << std::endl;

		else break;
	}

	std::cin.ignore(256, '\n');

	lista_graczy_komputerowych_ = new Gracz_kompuetrowy[liczba_graczy_komputerowych_w_grze_];

	for (int s = 0; s < liczba_graczy_komputerowych_w_grze_; s++)
	{

		lista_graczy_komputerowych_[s].ustaw_adres(this);
		lista_graczy_komputerowych_[s].nadaj_identyfikator(s);
		lista_graczy_komputerowych_[s].wpisz_odwage(s);
	}


}

bool Kasyno::czy_wszyscy_przegrali()
{
	int zlicz_przegranych = 0;

	for (int i = 0; i < liczba_graczy_w_grze_; i++)
	{
		zlicz_przegranych += lista_graczy_[i].zwroc_czy_przekroczyl_liczbe_punktow();
	}

	for (int i = 0; i < liczba_graczy_komputerowych_w_grze_; i++)
	{
		zlicz_przegranych += lista_graczy_komputerowych_[i].zwroc_czy_przekroczyl_liczbe_punktow();
	}

	if (zlicz_przegranych == (liczba_graczy_komputerowych_w_grze_ + liczba_graczy_w_grze_))
		return true;

	else
		return false;
}
void Kasyno::ktory_gracz_wygral(int i)
{
	if (lista_graczy_[i].czy_wygral() == true)
	{
		lista_graczy_[i].wyswietl_liczbe_punktow();
		std::cout << "Gra zakonczona. Wygral gracz ";
		lista_graczy_[i].pokaz_nazwe_gracza();
		std::cout << std::endl;
	}
}

void Kasyno::ktory_gracz_komputerowy_wygral(int i)
{
	if (lista_graczy_komputerowych_[i].czy_wygral() == true)
	{
		lista_graczy_komputerowych_[i].wyswietl_liczbe_punktow();
		std::cout << "Gra zakonczona. Wygral gracz komputerowy ";
		lista_graczy_komputerowych_[i].pokaz_identyfikator();
		std::cout << std::endl;
	}
}

void Kasyno::koniec_gry()
{
	delete[] lista_graczy_;
	delete lista_graczy_komputerowych_;
}