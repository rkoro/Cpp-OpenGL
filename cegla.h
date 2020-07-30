#ifndef CEGLA_H
#define CEGLA_H

#include "Element.h"
#include <stdlib.h>
#include <glut.h>
#include <math.h>

// x to jest przod/tyl
// y to jest gora/dol
// z to jest prawo/lewo przy czym +1 przesuwa w lewo
#define M_PI 3.141592654

class Ccegla
{
public:
	float x,y,z;
	int R,G,B;
	Ccegla(){x=0,y=0,z=0,R=0,G=0,B=0;}
	Ccegla(float xs,float ys,float zs){x=xs,y=ys,z=zs,R=0,G=0,B=0;}
	virtual void Rysuj();

};


#endif