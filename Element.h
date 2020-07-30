#ifndef ELEMENT_H
#define ELEMENT_H

#include "fizyka.h"

class CElement
{
public:
	float m_katx,m_katy;
	float R,G,B;

public:
	CElement();

	virtual void Przesun(float _x, float _y, float _z);
	virtual void Obroc(float katx, float katy);
	virtual void UstawKolor(float Re, float Be, float Ge);
	virtual void Rysuj()=0;

};
#endif