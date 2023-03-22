#pragma once
#include "Grzejnik.h"
#include "Pomieszczenie.h"

class Regulator
{
protected:

	Grzejnik* Regulowany_;
	Pomieszczenie* Obslugiwane_;

	float zadana_temperatura_;

public:
	virtual void steruj(float zadana_wartosc_temperatury, float dt) = 0;

	void wpisz_instancje_klas_posiadanych(Grzejnik* g_wpisywany, Pomieszczenie* p_wpisywane);

	Regulator();
};