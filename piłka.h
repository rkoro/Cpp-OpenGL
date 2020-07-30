#ifndef PILKA_H
#define PILKA_H

#include <stdlib.h>
#include <glut.h>
#include <math.h>
#include "Element.h"

class Cpilka
{
	public:
		float x, y, z;
		float promien;

		Cpilka(){x=0.0,y=0.0,z=0.0,promien = 0.0;}
		Cpilka()(float n_x,float n_y,float n_z,float _pr){x=n_x,y=n_y,z=n_z,promien = _pr;}
		virtual void Rysuj();
};
#endif