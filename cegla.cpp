#include "cegla.h"


void Ccegla::Rysuj()
{
	glPushMatrix();
	glColor3ub(R, G, B);
	glTranslated(x,y,z); //translate the cube
	glutSolidCube(5); //draw the cube
	glPopMatrix();
}

