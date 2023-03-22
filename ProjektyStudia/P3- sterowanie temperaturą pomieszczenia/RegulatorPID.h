#pragma once

#include "Regulator.h"

class Regulator_PID : public Regulator
{
	float Kp_;
	float Ki_;
	float Kd_;

	float suma_uchybu_;
	float uchyb_w_poprzedniej_chwili_;

public:

	Regulator_PID();

	void steruj(float zadana_wartosc_temperatury, float dt);

};

