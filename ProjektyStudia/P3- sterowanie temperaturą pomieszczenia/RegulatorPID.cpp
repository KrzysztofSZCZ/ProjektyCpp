#include "RegulatorPID.h"

Regulator_PID::Regulator_PID() : Kp_(4), Ki_(0.02), Kd_(0.1), suma_uchybu_(0), uchyb_w_poprzedniej_chwili_(0)
{

}

void Regulator_PID::steruj(float zadana_wartosc_temperatury, float dt)
{
	if (Obslugiwane_ == nullptr)
		throw "Nie mozna zalezc pomieszczenia, w ktorym znajduje sie regulator";

	else
	{
		float uchyb = zadana_wartosc_temperatury - Obslugiwane_->getTemperatura();

		//Cz�� proporcjonalna
		float Up = Kp_ * uchyb;

		//Cz�� ca�kuj�ca
		suma_uchybu_ += (uchyb * dt);

		float Ui = Ki_ * suma_uchybu_;

		//Cz�� r�niczkuj�ca
		float roznica_uchybu = ((uchyb - uchyb_w_poprzedniej_chwili_) / dt);

		float Ud = Kd_ * roznica_uchybu;

		//Ca�owity sugna� steruj�cy
		float U = Up + Ui + Ud;

		uchyb_w_poprzedniej_chwili_ = uchyb;

		if (Regulowany_ == nullptr)
			throw "Do regulatora nie przypisano zadnego grzejnika";

		else
			Regulowany_->ustaw_poziom_mocy(U);
	}
}
