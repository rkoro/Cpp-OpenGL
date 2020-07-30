#ifndef FIZYKA_H
#define FIZYKA_H

typedef struct sGranica
{
	float xa; //minimalna wartosc x
	float ya; //minimalna wartosc y
	float xb; //maskymalna wartosc x
	float yb;//maskymalna wartosc y
	float za;//minimalna wartosc z
	float zb;//maskymalna wartosc z
} sGranica;

class CFizyka
{
	protected:
		int czas; //czas ostatniej aktualizacji
		sGranica granica; //granice obiektu
		float x,y,z; //polozenie srodka masy
		float v;//predkosc
		float alfa_v_x,alfa_v_y;//kierunek wektora predkosci w [stopniach]
		float g; //grawitacja
		float alfa_g_x,alfa_g_y;//kierunek wektora grawitacji	
	public:
		CFizyka();
		float ZwracajX() {return float(x);}
		float ZwracajY() {return float(y);}
		float ZwracajZ() {return float(z);}
		void UstawX(float _x) {x = _x;}
		void UstawY(float _y) {y = _y;}
		void UstawZ(float _z) {z = _z;}

		void setGeometria(float _x,float _y,float _z, float _xa,float _ya,float _za,float _xb,float _yb,float _zb);

		void Odbicie(float alfa_n) ; //odbicie od sciany charakteryzowanej za pomoca normalnej alfa_n
		void Aktualizuj(int czas_aktualny);//zmienia polozenie obiektu na podstawie aktualnego czasu
		void setPredkosc(float _v, float _alfa_v_x,float _alfa_v_y); //ustawia poczatkowa predkosc
		void setFizyka(float _g, float _alfa_g_x,float _alfa_g_y); //ustawia poczatkowe przyspieszenie
		virtual int Kolizja(CFizyka& X); //wykrywanie kolizji z innym obiektem (funkcja przekazuje 1 gdy jest kolizja 0 gdy brak)
		int IsInRect(float _x, float _y,float _z, const CFizyka& X);//wykrywa czy dany punkt (_x,_y) znajduje sie wewnatrz pewnego kwadratu
		float odleglosc(float _x, float _y, float _z, float _xa,float _ya,float _za,float _xb,float _yb,float _zb);//wyznacza odleglosc od pewnej prostej przechodzacej przez 2 punkty
		virtual float ZnajdzNormalna(const CFizyka& X);//znajduje normalna boku ktory jest najblizej srodka obiektu (wynikiem funkcji jest orientacja normalnej);
		void Reset(); //resetuje czas

};
#endif