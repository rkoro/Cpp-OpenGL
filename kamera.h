#ifndef KAMERA_H
#define KAMERA_H

#include <stdlib.h>
#include <glut.h>
#include <math.h>

#define M_PI 3.141592654

class CKamera{

	public:
		float xpoz, ypoz, zpoz, xobr, yobr;
		float lastx, lasty;

		CKamera(){xpoz = 0, ypoz = 0, zpoz = 0, xobr = 0, yobr = 0;}
		CKamera(float nx, float ny, float nz, float nxobr, float nyobr){xpoz = nx, ypoz = ny, zpoz = nz, xobr = nxobr, yobr = nyobr;}
		void camera(void);
};

#endif