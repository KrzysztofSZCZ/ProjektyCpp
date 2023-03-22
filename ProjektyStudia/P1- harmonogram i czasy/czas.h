#include<iostream>

class Czas
{
private:

	int godziny_;
	int minuty_;
	int sekundy_;


	int zwroc_godziny();
	int zwroc_minuty();
	int zwroc_sekundy();

public:
	
	void wpisz_godziny();
	void wpisz_minuty();
	void wpisz_sekudny();

	Czas(int podane_godziny, int podane_minuty, int podane_sekundy);
	Czas(int podane_sekundy, int podane_minuty);
	Czas(int podane_sekundy);
	Czas();

	~Czas();

	void sprawdz_poprawnosc_wpisania_czasu();

	void pokaz_czas();

	void sumuj_czas(Czas dodwany);

	Czas operator+(Czas &dodawany);
	Czas operator+=(int dodawane_sekundy);

	Czas operator=(Czas &zrownywany);

	bool operator==(Czas porownywany);
	bool operator<(Czas porownywany);
};