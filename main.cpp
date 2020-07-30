#include "kamera.h"
#include "cegla.h"

CKamera kamera(0,5,20,0,0);

//tablica cegiel
Ccegla cegla[40];
float klr=0.0f;

void Rysuj_siatke()
{															

	for(float i = -300; i <= 300; i += 5)
	{
		glBegin(GL_LINES);
			glColor3ub(150, 190, 150);						
			glVertex3f(-300, 0, i);					
			glVertex3f(300, 0, i);
			glVertex3f(i, 0,-300);							
			glVertex3f(i, 0, 300);
		glEnd();
	}
}

void Rysuj_sciane(float dlugosc,float wysokosc, float obroty,float obrotz,float przesuniecieX,float przesuniecieY,float przesuniecieZ)
{
	glRotatef(obroty,0,1,0);
	glRotatef(obrotz,1,0,0);
	glColor3f(0.2, 0.5, 1);
	glTranslatef(przesuniecieX,przesuniecieY,przesuniecieZ);
	glPushMatrix();
	glBegin(GL_QUADS);			
		glVertex3f(0,wysokosc,0);
		glVertex3f(-(dlugosc), wysokosc, 0);         
		glVertex3f(-(dlugosc), 0.0f,0);         
		glVertex3f(0.0f,0.0f, 0);         
	glEnd();
	glPopMatrix();
}

//inicjacja cegiel
void inicjacjaCegiel (void) 
{
	float R,G,B;

	R=rand()%20/10-1;
	G=rand()%20/10-1;
	B=rand()%20/10-1;
	for (int i=0;i<10;i++)
		 {
		cegla[i].R=R;
		cegla[i].G=G;
		cegla[i].B=B;
		cegla[i].x=(i-5)*5;
		cegla[i].y=2.5;
		cegla[i].z=80;
		 }
	R=rand()%20/10-1;
	G=rand()%20/10-1;
	B=rand()%20/10-1;
	for (int i=10;i<20;i++)
		{
		cegla[i].R=R;
		cegla[i].G=G;
		cegla[i].B=B;
		cegla[i].x=(i-15)*5;
		cegla[i].y=7.5;
		cegla[i].z=80;

		}
	R=rand()%20/10-1;
	G=rand()%20/10-1;
	B=rand()%20/10-1;
	for (int i=20;i<30;i++)
		{		
		cegla[i].R=R;
		cegla[i].G=G;
		cegla[i].B=B;
		cegla[i].x=(i-25)*5;
		cegla[i].y=12.5;
		cegla[i].z=80;
		}
	R=rand()%20/10-1;
	G=rand()%20/10-1;
	B=rand()%20/10-1;
	for (int i=30;i<40;i++)
		{
		cegla[i].R=R;
		cegla[i].G=G;
		cegla[i].B=B;
		cegla[i].x=(i-35)*5;
		cegla[i].y=17.5;
		cegla[i].z=80;
		}
}

void init (void) {
 inicjacjaCegiel();
}


GLfloat ambientLight[] = {1.0f, 0.0f, 0.3f, 1.0f };//swiatło otaczajace
GLfloat ambientLight2[] = {1.0f, 0.0f, 0.0f, 1.0f };
GLfloat diffuseLight[] = { 0.5f, 2.0f, 0.2f, 1.0f };//wiatło rozproszone
GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f}; //wiatło odbite
GLfloat lightPos0[] = { 20.0f, 12.0f, 15.0f,1.0f };//pozycja wiatła
GLfloat lightPos1[] = { -22.0f, -10.0f,20.0f,1.0f };
GLfloat lightPos2[] = { 0.0f, 0.0f,0.0f,1.0f };


void enable (void) {
     	glEnable(GL_LIGHTING);
	//glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	glLightfv(GL_LIGHT0,GL_SPECULAR,specular); //wiatło odbite
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos0); //pozycja wiatła
	glEnable(GL_LIGHT0);
	
	glLightfv(GL_LIGHT1,GL_DIFFUSE,ambientLight);
	glLightfv(GL_LIGHT1,GL_SPECULAR,specular); 
	glLightfv(GL_LIGHT1,GL_POSITION,lightPos1); 
	glEnable(GL_LIGHT1);

		
	glLightfv(GL_LIGHT2,GL_DIFFUSE,ambientLight2);
	glLightfv(GL_LIGHT2,GL_SPECULAR,specular); 
	glLightfv(GL_LIGHT2,GL_POSITION,lightPos2); 
	//glEnable(GL_LIGHT2);


	glEnable( GL_COLOR_MATERIAL);
    
   
    glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	

	glEnable (GL_DEPTH_TEST);//enable the depth testing
	glShadeModel (GL_SMOOTH); //set the shader to smooth shader

}

//Wiadomo, tutaj się wszytsko rysuje
void display (void) 
{
    glClearColor (0.0,0.0,0.0,1.0); //czarne tło
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
    glLoadIdentity();  
	kamera.camera();
	Rysuj_siatke();

	for(int i=0;i<40;i++)
		cegla[i].Rysuj();
	Rysuj_sciane(160,20,90,0,0,0,22.5);//lewa sciana
	Rysuj_sciane(160,20,0,0,0,0,-50);//prawa sciana
	Rysuj_sciane(160,50,0,90,0,0,0);//podloga
	Rysuj_sciane(160,50,0,0,0,0,-20);//sufit
	Rysuj_sciane(20,50,90,0,0,0,0);//sciana gracza
	Rysuj_sciane(20,50,0,0,0,0,-160);//przeciwlegla sciana
    
	enable();
    glutSwapBuffers(); //
}

//Ustawienia startowe okna
void reshape (int w, int h) {
     glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
     glMatrixMode (GL_PROJECTION); //set the matrix to projection

     glLoadIdentity ();
     gluPerspective (90, (GLfloat)w / (GLfloat)h, 1.0, 1000.0); //set the perspective (angle of sight, width, height, , depth)
     glMatrixMode (GL_MODELVIEW); //set the matrix back to model

}

void keyboard (unsigned char key, int x, int y) {
    if (key=='q')
     {
		 kamera.xobr += 1;
		 if (kamera.xobr >360) kamera.xobr -= 360;
		 glutPostRedisplay();
     }

    if (key=='z')
     {
		 kamera.xobr -= 1;
		 if (kamera.xobr < -360) kamera.xobr += 360;
		 glutPostRedisplay();
     }

    if (key=='w')
     {
		float xobrrad, yobrrad;
		yobrrad = (kamera.yobr / 180 * M_PI);
		xobrrad = (kamera.xobr / 180 * M_PI); 
		kamera.xpoz += float(sin(yobrrad)) ;
		kamera.zpoz -= float(cos(yobrrad)) ;
		kamera.ypoz -= float(sin(xobrrad)) ;
		glutPostRedisplay();
     }

    if (key=='s') //idziemy do tylu
     {
		 float xobrrad, yobrrad;
		 yobrrad = (kamera.yobr / 180 * M_PI);
		 xobrrad = (kamera.xobr / 180 * M_PI); 
		 kamera.xpoz -= float(sin(yobrrad));
		 kamera.zpoz += float(cos(yobrrad)) ;
		 kamera.ypoz += float(sin(xobrrad));
		 glutPostRedisplay();
     }

    if (key=='d') //obracamy sie w prawo
     {
		 kamera.yobr += 1;
		 if (kamera.yobr >360) kamera.yobr -= 360;
		 glutPostRedisplay();
     }

    if (key=='a')//obracamy sie w lewo
     {
		 kamera.yobr -= 1;
		 if (kamera.yobr < -360)kamera.yobr += 360;
		 glutPostRedisplay();
     }
	
	if(key=='p')
	{
		
		/*float yrotrad;
		yrotrad = (kamera.yobr / 180 * M_PI);
		kamera.xpoz += float(cos(yrotrad)) * 0.2;
		kamera.zpoz += float(sin(yrotrad)) * 0.2;*/
		if(kamera.xpoz > -20)		
			kamera.xpoz -= 1;
		else
			kamera.xpoz += 1; //ruch po osi
		glutPostRedisplay();
	}
	if(key=='o')
	{
		
		/*float yobrrad;
		yobrrad = (kamera.yobr / 180 * M_PI);
		kamera.xpoz -= float(cos(yobrrad)) * 0.2;
		kamera.zpoz -= float(sin(yobrrad)) * 0.2;*/
		if(kamera.xpoz < 20)	
			kamera.xpoz += 1;
		else
			kamera.xpoz -= 1; //ruch po osi
		glutPostRedisplay();
	}
 
}

void MouseMove(int x, int y)
{
	float diffx=x-kamera.lastx; // sprawdz roznice miedzy aktualnym x i ostatnia pozycja x
	float diffy=y-kamera.lasty; // sprawdz roznice miedzy aktualnym y i ostatnia pozycja y
	kamera.lastx=x; //przypisz ostatniej x aktualny x
	kamera.lasty=y; //przypisz ostatniej x aktualny x
	kamera.xobr += (float)diffy; // zwieksz xobr o nowa roznice
	kamera.yobr += (float)diffx;// 
	glutPostRedisplay();
}

int main (int argc, char **argv) {
     glutInit (&argc, argv);
     glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH); //set the display to Double buffer, with depth
     glutInitWindowSize (800, 800); //rozmiar okna
     glutInitWindowPosition (100, 100); //pozycja okna
     glutCreateWindow ("Okno"); //tytul okna
     init (); //init. bk.
     glutDisplayFunc (display); //display. rysuje wszystko
    // glutIdleFunc (display); 
     glutReshapeFunc (reshape); //reshape the window accordingly
	 glutPassiveMotionFunc(MouseMove);	//ruch myszka
     glutKeyboardFunc (keyboard); //check the keyboard
     glutMainLoop (); //call the main loop
     return 0;
}