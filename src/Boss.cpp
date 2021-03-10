#include "Boss.h"
#include "ETSIDI.h"

Boss::Boss():prof("imagenes/prof.png",4)
{
	prof.setCenter(4, 8);
	prof.setSize(4, 7);
}

Boss::~Boss()
{
	destruirEx();
	Ex = 0; //Cuidado
}

void Boss::inicializa(int v) {
	
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;

	profesor.setPos(6, 12);
	Ex = new Examen(v);            //buscar delete, creo qu eo esta, causa que no se cierre 
	                               // bien el programa
}

void Boss::dibuja() {

	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	glEnable(GL_TEXTURE_2D);
	loadTextura("imagenes/aula.png", -12, 0, 10, 12, 0, 10, 12, 15, 10, -12, 15, 10);
	loadTextura("imagenes/hoja_examen.png", -8, 0, 12, 6, 0, 12, 6, 7,12, -8, 7,12);
	//loadTextura("imagenes/prof.png", 3, 5, 13, 5, 5, 13, 5, 13, 13, 3, 13, 13);
	glEnable(GL_LIGHTING);	//NO BORRAR 
	glDisable(GL_TEXTURE_2D); // NO BORRAR 

	glPushMatrix();
	glTranslatef(6, 12, 10.5);
	glColor3f(1.0f, 1.0f, 1.0f);

	prof.setState(3, false);
	prof.draw();

	glPopMatrix();

	Ex->dibuja(indiceImpresionPreguntas);
	if (indiceImpresionPreguntas > 0)
	{
		Ex->Correccion(Ex->respuesta, indiceImpresionPreguntas - 1);
		Ex->respuesta = '0';
	}

}

void Boss::mueve(float t, float Amp){
	profesor.mueve_armonico(t, Amp);
	prof.loop();
}

void Boss::loadTextura(const char *ruta, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4) {
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(ruta).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1);		glVertex3f(x1, y1, z1);
	glTexCoord2d(1, 1);		glVertex3f(x2, y2, z2);
	glTexCoord2d(1, 0);		glVertex3f(x3, y3, z3);
	glTexCoord2d(0, 0);		glVertex3f(x4, y4, z4);
	glEnd();
}

void Boss::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case 'a':
	{
		Ex->respuesta = key;
		if (indiceImpresionPreguntas < 4) indiceImpresionPreguntas++;

		break;
	}
	case 'b':
	{
		Ex->respuesta = key;
		if (indiceImpresionPreguntas < 4) indiceImpresionPreguntas++;

		break;
	}
	case 'c':
	{
		Ex->respuesta = key;
		if (indiceImpresionPreguntas < 4) indiceImpresionPreguntas++;

		break;
	}
	case 'd':
	{
		Ex->respuesta = key;
		if (indiceImpresionPreguntas < 4) indiceImpresionPreguntas++;

		break;
	}
	default:
		break;

	}
}
