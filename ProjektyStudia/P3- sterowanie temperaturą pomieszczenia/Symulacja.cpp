#include "Symulacja.h"

void Symulacja::iteracja(float dt)
{
	Symulowane_.dodajCieplo(Uzywany_w_pomieszczeniu_.zwroc_moc_emitowana());
	Symulowane_.aktualizuj(dt);


}

void Symulacja::przebieg(int liczba_krokow, float czas_probkowania)
{

	Sterujacy_grzejnikiem_->wpisz_instancje_klas_posiadanych(&Uzywany_w_pomieszczeniu_, &Symulowane_);

	for (int i = 0; i < liczba_krokow; i++)
	{
		try 
		{
			Sterujacy_grzejnikiem_->steruj(22.73, czas_probkowania);
		}
		catch (...)
		{
			std::cout << "Brak przypisanego pomieszcznia lub grzejnika do regulatora. Symulacja zakonczona niepowodzeniem!" << std::endl;

			return;
		}

		przebieg_temperatury.push_back(Symulowane_.getTemperatura());
		przebieg_czasu.push_back(czas_symulacji_);
		przebieg_mocy.push_back(Uzywany_w_pomieszczeniu_.zwroc_moc_emitowana());

		iteracja(czas_probkowania);

		czas_symulacji_ += czas_probkowania;


		liczba_iteracji_++;
	}

	std::cout << "Symulacja zakonczona powodzeniem" << std::endl;

	zapis(wpisz_nazwe_przebiegu());

}

void Symulacja::zapis(char* nazwa_pliku)
{
	std::ofstream plik;

	plik.open(nazwa_pliku, std::ofstream::out);

	if (plik.is_open())
	{
		plik << "Temperatura w pomieszczeniu [K]:";
		plik << std::endl;

		for (int i = 0; i < liczba_iteracji_; i++)
			plik << przebieg_temperatury[i] << ";";

		plik << std::endl;

		plik << "Przebieg czasu probkowania [j.u.]:";
		plik << std::endl;

		for (int i = 0; i < liczba_iteracji_; i++)
			plik << przebieg_czasu[i] << ";";

		plik << std::endl;

		plik << "Przebieg mocy[W]:";
		plik << std::endl;

		for (int i = 0; i < liczba_iteracji_; i++)
			plik << przebieg_mocy[i] << ";";

		plik << std::endl;

		std::cout << "Poprawnie zapisano przebieg symulacji." << std::endl;
	}

	else
		std::cout << "NIe udalo sie otworzyc pliku!" << std::endl;

	plik.close();
}

Symulacja::Symulacja() : Symulowane_(2,2,2), czas_symulacji_(0), liczba_iteracji_(0), Sterujacy_grzejnikiem_(nullptr)
{
	try
	{
		if (wybierz_regulator() == 0)
		{
			Regulator_PID* PID = new Regulator_PID;
			ustaw_regulator(PID);
		}
		else
		{
			Regulator_BB* BB = new Regulator_BB;
			ustaw_regulator(BB);
		}
	}
	catch (...)
	{
		std::cout << "Bez ustawienia regulatora nie mozna uruchomic symulacji! Program zakonczy dzialanie" << std::endl;
		return;
	}

}

Symulacja::~Symulacja()
{
	if(Sterujacy_grzejnikiem_ != nullptr)
		delete Sterujacy_grzejnikiem_;
}

char* Symulacja::wpisz_nazwe_przebiegu()
{
	char nazwa_pliku[256];

	std::cout << "Podaj nazwe pliku, do ktorego maja zapisac sie przebiegi symulacji. (Muszisz wpisac rozszerzenie .csv)" << std::endl;
	std::cin >> nazwa_pliku;

	return nazwa_pliku;
}

int Symulacja::wybierz_regulator()
{
	int wybor_uzytkownika;

	while (1)
	{
		std::cout << "Ktory regulator ma sterowac grzenikiem? Wpizz 0 (PID) lub 1 (BB)" << std::endl;

		std::cin >> wybor_uzytkownika;

		if (std::cin.fail() == true) {
			std::cout << "Wpisano znak o niepoprawnym typie! Prosze wpisac ponownie" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}

		else if (wybor_uzytkownika != 0 && wybor_uzytkownika != 1)
			std::cout << "Wpisano cyfrê z niepoprawnego zakresu! Proszê wpisaæ ponownie!" << std::endl;

		else break;
	}

	return wybor_uzytkownika;
}

void Symulacja::ustaw_regulator(Regulator* ustawiany)
{
	if (ustawiany == nullptr)
		throw "Nie podano adresu regulatora!";
	else
		Sterujacy_grzejnikiem_ = ustawiany;
}
