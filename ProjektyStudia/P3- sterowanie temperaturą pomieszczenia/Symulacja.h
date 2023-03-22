#pragma once
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"
#include <fstream>

class Symulacja 
{
	Grzejnik Uzywany_w_pomieszczeniu_;
	Pomieszczenie Symulowane_;
	Regulator* Sterujacy_grzejnikiem_;

	float czas_symulacji_;
	int liczba_iteracji_;
	
	std::vector <float> przebieg_temperatury;
	std::vector <float> przebieg_czasu;
	std::vector <float> przebieg_mocy;

	

public:
	
	Symulacja();
	~Symulacja();

	void iteracja(float dt);
	void przebieg(int liczba_wykonywanych_iteracja, float czas_probkowania);
	void zapis(char* zapisywany_przebieg);

	char* wpisz_nazwe_przebiegu();

	int wybierz_regulator();
	void ustaw_regulator(Regulator* ustawiany);
};