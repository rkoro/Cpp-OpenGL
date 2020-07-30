#include "kamera.h"


#define M_PI 3.141592654f;

//////////////////////////////////////////////////////////
// x to jest przod/tyl
// y to jest gora/dol
// z to jest prawo/lewo przy czym +1 przesuwa w lewo
/////////////////////////////////////////////////////////

void CKamera::camera(void){
	glRotatef(xobr,1.0,0.0,0.0);  //rotate our camera on teh x-axis (left and right)
	glRotatef(yobr,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
	glTranslated(-xpoz,-ypoz,-zpoz); //translate the screen to the position of our camera
}