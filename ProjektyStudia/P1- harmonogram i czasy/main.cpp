#include "harmonogram.h"

Harmonogram kopiuj_harmonogram(Harmonogram kopiowany)
{
	int parametr_ile_czasow_skopiowac = 0;
	int liczba_czasow_do_skopiowania;

	while (parametr_ile_czasow_skopiowac != 1)
	{
		std::cout << "Podaj, ile czasow chcesz skopiowac" << std::endl;
		std::cin >> liczba_czasow_do_skopiowania;

		if (liczba_czasow_do_skopiowania < 0 || liczba_czasow_do_skopiowania > kopiowany.zwroc_liczbe_czasow())
		{
			std::cout << "Nie mozna skopiowac takiej liczby czasow! Podano niepoprawna wartosc!" << std::endl;
		}

		else
		{
			Harmonogram Harmonogram_skopiowany(kopiowany, liczba_czasow_do_skopiowania);
			return Harmonogram_skopiowany;
		}
	}
}
 

Harmonogram kopiuj_czasy_o_zadanej_sumie(Harmonogram kopiowany, Czas podana_suma)
{
	Czas suma_czasow;
	int indeks_czasu = 0;
	int czy_dodawac_czas = 0;

	while (czy_dodawac_czas != 1 && indeks_czasu < kopiowany.zwroc_liczbe_czasow())
	{
		if (suma_czasow < podana_suma )
		{
			suma_czasow.sumuj_czas(kopiowany.zwroc_podany_czas(indeks_czasu));
			suma_czasow.sprawdz_poprawnosc_wpisania_czasu();

			if (suma_czasow < podana_suma || suma_czasow == podana_suma)
			{
				indeks_czasu++;
			}

			else 
			{
				czy_dodawac_czas = 1;
			}
		}

		else
		{
			czy_dodawac_czas = 1;
		}

	}

	Harmonogram Harmongram_skopiowany(kopiowany, indeks_czasu);
	return Harmongram_skopiowany;
}


int main()
{

	Czas Czas1(1, 2, 55);
	Czas Czas2(5, 76, 68);
	Czas Czas3(12, 4, 22);
	Czas Czas4(9);
	Czas Czas5(55, 13);
	
	Czas zsumowane_czasy;
	Czas podana_suma_graniczna;


	Czas1.sprawdz_poprawnosc_wpisania_czasu();
	Czas2.sprawdz_poprawnosc_wpisania_czasu();
	Czas3.sprawdz_poprawnosc_wpisania_czasu();
	Czas4.sprawdz_poprawnosc_wpisania_czasu();
	Czas5.sprawdz_poprawnosc_wpisania_czasu();

	Harmonogram Harmonogram1;
	Harmonogram Harmonogram_skopiowany;
	Harmonogram Harmonogram_skopiowany_o_zadanej_sumie;

	Harmonogram1.dodaj_czas_do_harmonogramu(Czas1);
	Harmonogram1.dodaj_czas_do_harmonogramu(Czas2);
	Harmonogram1.dodaj_czas_do_harmonogramu(Czas3);
	Harmonogram1.dodaj_czas_do_harmonogramu(Czas4);
	Harmonogram1.dodaj_czas_do_harmonogramu(Czas5);

	Harmonogram1.zwroc_wszystkie_czasy();

	int opcja_menu = 55;
	int parametr_menu = 100;

	int parametr_poprawngo_dodawnaia_sekund = 0;
	int dodawane_sekundy;
	int do_ktorego_czasu_dodac_sekundy;
	int poprawnosc_czasu_do_ktorego_dodawane_sa_sekundy = 0;

	while (parametr_menu != 0)
	{
		std::cout << "Co chcesz teraz zrobic? (Wpisz cyfre)" << std::endl;
		std::cout << "1: Skopiuj wybrana liczbe czasu do nowego harmonogramu" << std::endl;
		std::cout << "2: Dodaj sekundy do czasu" << std::endl;
		std::cout << "3: Kopiuj czasy o zadaniej sumie" << std::endl;

		std::cin >> opcja_menu;

		switch (opcja_menu)
		{

		case 1:
			
			Harmonogram_skopiowany = kopiuj_harmonogram(Harmonogram1);
			Harmonogram_skopiowany.zwroc_wszystkie_czasy();

			break;

		case 2:

			while (parametr_poprawngo_dodawnaia_sekund != 1)
			{
				std::cout << "Podaj, ile sekund chcesz dodac do czasu" << std::endl;
				std::cin >> dodawane_sekundy;

				if (dodawane_sekundy < 0)
					std::cout << "Nie mozna dodac ujemnej liczby sekund!" << std::endl;

				else
				{
					parametr_poprawngo_dodawnaia_sekund = 1;
				}
			}

			while (poprawnosc_czasu_do_ktorego_dodawane_sa_sekundy != 1)
			{
				std::cout << "Podaj, do ktorego czasu chcesz dodac sekundy" << std::endl;
				std::cin >> do_ktorego_czasu_dodac_sekundy;

				if (do_ktorego_czasu_dodac_sekundy < 0 || do_ktorego_czasu_dodac_sekundy > Harmonogram1.zwroc_liczbe_czasow())
				{
					std::cout << "Nie ma takiego czasu! Wpisz ponownie." << std::endl;
				}

				else
				{
					Harmonogram1.dodaj_sekundy_do_czasu(dodawane_sekundy, do_ktorego_czasu_dodac_sekundy);
					poprawnosc_czasu_do_ktorego_dodawane_sa_sekundy = 1;
				}
			}

			Harmonogram1.zwroc_wszystkie_czasy();
			

			break;

		case 3:

			podana_suma_graniczna.wpisz_godziny();
			podana_suma_graniczna.wpisz_minuty();
			podana_suma_graniczna.wpisz_sekudny();

			podana_suma_graniczna.sprawdz_poprawnosc_wpisania_czasu();

			Harmonogram_skopiowany_o_zadanej_sumie = kopiuj_czasy_o_zadanej_sumie(Harmonogram1, podana_suma_graniczna);

			Harmonogram_skopiowany_o_zadanej_sumie.zwroc_wszystkie_czasy();

			break;

		default:

			std::cout << "Podano niepoprawna opcje wyboru! Prosze wpisac ponownie." << std::endl;

			break;
		}
	}

	}
