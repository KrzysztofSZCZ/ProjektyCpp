#include "RegulatorBB.h"

void Regulator_BB::steruj(float wartosc_zadana_temperatury, float dt)
{
	if (Obslugiwane_ == nullptr || Regulowany_ == nullptr)
		throw "Nie wykryto adresu pomieszczenia lub grzejnika.";

	else 
	{
		if (Obslugiwane_->getTemperatura() < wartosc_zadana_temperatury)
			Regulowany_->ustaw_poziom_mocy(1);
		else
			Regulowany_->ustaw_poziom_mocy(0);
	}
}
