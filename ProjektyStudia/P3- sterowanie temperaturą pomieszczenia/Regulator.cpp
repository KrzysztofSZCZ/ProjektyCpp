#include"Regulator.h"

void Regulator::wpisz_instancje_klas_posiadanych(Grzejnik* g_wpisywany, Pomieszczenie* p_wpisywane)
{
		Regulowany_ = g_wpisywany;
		Obslugiwane_ = p_wpisywane;
}

Regulator::Regulator() : Regulowany_(nullptr), Obslugiwane_(nullptr), zadana_temperatura_(0)
{

}
