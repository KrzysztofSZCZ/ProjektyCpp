#pragma once

#include "Regulator.h"

class Regulator_BB : public Regulator 
{

public:
	void steruj(float wartosc_zadana_temperatury, float dt);
	
};