#include "HistoriaImagenes.h"
#include "glut.h"
#include "ETSIDI.h"
HistoriaImagenes::HistoriaImagenes() {}
HistoriaImagenes::~HistoriaImagenes() {}
void HistoriaImagenes::Profesor1(void) {
	gluLookAt(0, 7.5, 30, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	glEnable(GL_TEXTURE_2D);
	// Pinta imágen de fondo de la pantalla
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Profesor1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-15.0f, -4.0f, 0);
	glTexCoord2d(1, 1);		glVertex3f(15.0f, -4.0f, 0);
	glTexCoord2d(1, 0);		glVertex3f(15.0f, 18.5f, 0);
	glTexCoord2d(0, 0);		glVertex3f(-15.0f, 18.5f, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
void HistoriaImagenes::Profesor2(void) {
	gluLookAt(0, 7.5, 30, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	glEnable(GL_TEXTURE_2D);
	// Pinta imágen de fondo de la pantalla
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Profesor2.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-15.0f, -4.0f, 0);
	glTexCoord2d(1, 1);		glVertex3f(15.0f, -4.0f, 0);
	glTexCoord2d(1, 0);		glVertex3f(15.0f, 18.5f, 0);
	glTexCoord2d(0, 0);		glVertex3f(-15.0f, 18.5f, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
void HistoriaImagenes::Profesor3(void) {
	gluLookAt(0, 7.5, 30, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	glEnable(GL_TEXTURE_2D);
	// Pinta imágen de fondo de la pantalla
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Profesor2.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-15.0f, -4.0f, 0);
	glTexCoord2d(1, 1);		glVertex3f(15.0f, -4.0f, 0);
	glTexCoord2d(1, 0);		glVertex3f(15.0f, 18.5f, 0);
	glTexCoord2d(0, 0);		glVertex3f(-15.0f, 18.5f, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
void HistoriaImagenes::Presentacion1(void) {
	gluLookAt(0, 7.5, 30, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	glEnable(GL_TEXTURE_2D);
	// Pinta imágen de fondo de la pantalla
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Presentacion1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-15.0f, -4.0f, 0);
	glTexCoord2d(1, 1);		glVertex3f(15.0f, -4.0f, 0);
	glTexCoord2d(1, 0);		glVertex3f(15.0f, 18.5f, 0);
	glTexCoord2d(0, 0);		glVertex3f(-15.0f, 18.5f, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
void HistoriaImagenes::Presentacion2(void) {
	gluLookAt(0, 7.5, 30, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	glEnable(GL_TEXTURE_2D);
	// Pinta imágen de fondo de la pantalla
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Presentacion2.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-15.0f, -4.0f, 0);
	glTexCoord2d(1, 1);		glVertex3f(15.0f, -4.0f, 0);
	glTexCoord2d(1, 0);		glVertex3f(15.0f, 18.5f, 0);
	glTexCoord2d(0, 0);		glVertex3f(-15.0f, 18.5f, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
void HistoriaImagenes::Presentacion3(void) {
	gluLookAt(0, 7.5, 30, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	glEnable(GL_TEXTURE_2D);
	// Pinta imágen de fondo de la pantalla
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Presentacion3.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);		glVertex3f(-15.0f, -4.0f, 0);
	glTexCoord2d(1, 1);		glVertex3f(15.0f, -4.0f, 0);
	glTexCoord2d(1, 0);		glVertex3f(15.0f, 18.5f, 0);
	glTexCoord2d(0, 0);		glVertex3f(-15.0f, 18.5f, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}