#pragma once
#include <iostream>

class Grzejnik 
{
	const float moc_nominalna_;
	float aktualny_poziom_mocy_;

public:

	Grzejnik();
	
	float zwroc_moc_nominalna();
	float zwroc_aktualny_poziom_mocy();
	float zwroc_moc_emitowana();

	void ustaw_poziom_mocy(float wpisywany_poziom_mocy);
	float wpisz_poziom_mocy();
};