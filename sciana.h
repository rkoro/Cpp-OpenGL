#ifndef SCIANA_H
#define SCIANA_H

#include "Element.h"

class CSciana
{
	float x,y,z;

public:
	CSciana(){x=0,y=0,z=0,R=0,G=0,B=0;}
	CSciana(float xs,float ys,float zs){x=xs,y=ys,z=zs,R=0,G=0,B=0;}
	virtual void Rysuj();
#endif