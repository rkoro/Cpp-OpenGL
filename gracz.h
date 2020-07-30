#ifndef GRACZ_H
#define GRACZ_H

#include "Element.h"

class Cgracz
{
	public:
		float x,y,z;
		bool bonus[5]; //flagi bonusow
		int hp;

		Cgracz(){x=0,y=0,z=0;}
		Cgracz(float n_x, float n_y, float n_z){x = n_x, y = n_y, z = n_z;}
		virtual void Rysuj();
};

#endif