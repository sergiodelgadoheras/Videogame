//DERKACH
#include "CoordinadorPang.h"
#include "Mundo.h"
#include "ETSIDI.h"
#include "glut.h"

int cont = 0;

CoordinadorETSIDI::CoordinadorETSIDI()
{
		estado = INICIO;                      // subrrayado
		pasillo = 0;
		flag_final_pasillo = false;
		vida = 6;
		genero = 1;
}


CoordinadorETSIDI::~CoordinadorETSIDI(){}

void CoordinadorETSIDI::dibuja()
{
	if (estado == INICIO) {
		ETSIDI::stopMusica();
		Mundo.inicializa_p1();
		//Boss.inicializa(vida);
		vida = 6;
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		glEnable(GL_TEXTURE_2D);
		// Pinta imágen de fondo de la pantalla
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Inicio.png").id);
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

		/*ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Quicksand-Bold.otf", 100);
		ETSIDI::printxy("ETSIDI GAME", -8, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Quicksand-Bold.otf", 20);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -13, 3);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -13, 2);
		ETSIDI::printxy("UTILICE LAS FLECHAS PARA MOVERSE Y SALTAR", -13, 1);
		ETSIDI::setFont("fuentes/Quicksand-Bold.otf", 30);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::printxy("ATANCE, BAREA, DERKACH", 2, 1);*/

	}
	else if (estado == PRESENTACION) {
		HistoriaImagenes.Presentacion1();
		
	}
	else if (estado == PRESENTACION1) {
		HistoriaImagenes.Presentacion2();

	}
	else if (estado == PRESENTACION2) {
		HistoriaImagenes.Presentacion3();

	}
	else if (estado == JUEGO)
	{
		
		if (pasillo == 0)
		{
			Mundo.mueve_p1();
			Mundo.dibuja_p1(genero);
			if (Mundo.getPosX() > 96)
			{
				flag_final_pasillo = true;
				pasillo = 1;

			}
			
		}
		if (pasillo == 1)
		{
			if (cont == 0) {
				Mundo.inicializa_p2();
				cont++;
			}
			Mundo.dibuja_p2(genero);
			Mundo.mueve_p2();
			if (Mundo.getPosX() < 96)
			{
				Boss.destruirEx();
				flag_final_pasillo_1 = true;
				pasillo = 2;

			}
			
		}

		if (pasillo == 2)
		{
			if (cont == 1) {
				Mundo.inicializa_p3();
				cont++;
			}
			Mundo.dibuja_p3(genero);
			Mundo.mueve_p3();
			if (Mundo.getPosX() > 96)
			{// en el ultimo nivel que tenga que matar a todos
				Boss.destruirEx();
				flag_final_pasillo_2 = true;
				pasillo = 0;
			}
		
		}

		

		if (flag_final_pasillo) {

			estado = HISTORIA;
			
		}
		if (flag_final_pasillo_1) {
			estado = HISTORIA;
		}
		if (flag_final_pasillo_2) {
			estado = HISTORIA;
		}
		///////////////////////////TEXTURAS VIDA
		if (vida == 6) {
			// 6 corazones
			glEnable(GL_TEXTURE_2D);
			loadTextura("imagenes/1.png", -8.0f + Mundo.getOjoX(), 12.5f, 8, -4.0f + Mundo.getOjoX(), 12.5f, 8, -4.0f + Mundo.getOjoX(), 14.5f, 8, -8.0f + Mundo.getOjoX(), 14.5f, 8);
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
		}
		if (vida == 5) {
			// 5 corazones
			glEnable(GL_TEXTURE_2D);
			loadTextura("imagenes/2.png", -8.0f + Mundo.getOjoX(), 12.5f, 8, -4.0f + Mundo.getOjoX(), 12.5f, 8, -4.0f + Mundo.getOjoX(), 14.5f, 8, -8.0f + Mundo.getOjoX(), 14.5f, 8);
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
		}
		if (vida == 4) {
			// 4 corazones
			glEnable(GL_TEXTURE_2D);
			loadTextura("imagenes/3.png", -8.0f + Mundo.getOjoX(), 12.5f, 8, -4.0f + Mundo.getOjoX(), 12.5f, 8, -4.0f + Mundo.getOjoX(), 14.5f, 8, -8.0f + Mundo.getOjoX(), 14.5f, 8);
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
		}

		if (vida == 3) {
			// 3 corazones
			glEnable(GL_TEXTURE_2D);
			loadTextura("imagenes/4.png", -8.0f + Mundo.getOjoX(), 12.5f, 8, -4.0f + Mundo.getOjoX(), 12.5f, 8, -4.0f + Mundo.getOjoX(), 14.5f, 8, -8.0f + Mundo.getOjoX(), 14.5f, 8);
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
		}
		if (vida == 2) {
			// 2 corazones
			glEnable(GL_TEXTURE_2D);
			loadTextura("imagenes/5.png", -8.0f + Mundo.getOjoX(), 12.5f, 8, -4.0f + Mundo.getOjoX(), 12.5f, 8, -4.0f + Mundo.getOjoX(), 14.5f, 8, -8.0f + Mundo.getOjoX(), 14.5f, 8);
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
		}
		if (vida == 1) {
			//Carga la imagen de 1 corazon
			glEnable(GL_TEXTURE_2D);
			loadTextura("imagenes/6.png", -8.0f + Mundo.getOjoX(), 12.5f, 8, -4.0f + Mundo.getOjoX(), 12.5f, 8, -4.0f + Mundo.getOjoX(), 14.5f, 8, -8.0f + Mundo.getOjoX(), 14.5f, 8);
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
		}
		////////////////FIN TEXTURAS VIDA

	}
	else if (estado == ELECCION)
	{

		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		glEnable(GL_TEXTURE_2D);
		// Pinta imágen de fondo de la pantalla
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/eleccion.png").id); //cambiar imagen chico//chica
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
	else if (estado == ELECCION_H) {

		genero = 1;
		estado = JUEGO;
	}
	else if (estado == ELECCION_M) {

		genero = 2;
		estado = JUEGO;
	}

	else if (estado == BOSS)
	{
		
		Boss.dibuja();
	}
	else if (estado == GAMEOVER)
	{
		Mundo.dibuja_p1(genero);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", Mundo.getOjoX()-3, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", Mundo.getOjoX()-3, 5);
	}
	else if (estado == PAUSA)
	{
		Mundo.dibuja_p1(genero);
		
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSE", Mundo.getOjoX()-3, 10);
		ETSIDI::printxy("Pulsa -C- para VOLVER", Mundo.getOjoX()-3, 5);
	}
	else if (estado == FIN)
	{
		//Boss.dibuja();
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setFont("fuentes/Quicksand-Bold.otf", 20);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("ENHORABUENA, ¡Has terminado el examen!", -8, 10);
		ETSIDI::setFont("fuentes/Quicksand-Bold.otf", 30);
		ETSIDI::printxy("Tu nota es: ", -8, 6);
		ETSIDI::setFont("fuentes/Quicksand-Bold.otf", 50);
		ETSIDI::printxy(std::to_string(Boss.getNota()).c_str(), -3, 6);
		ETSIDI::setFont("fuentes/Quicksand-Bold.otf", 15);
		ETSIDI::printxy("Pulsa -C- para continuar", -8, 3);
	}
	else if (estado == HISTORIA) {
		if (flag_final_pasillo) {
			HistoriaImagenes.Profesor1();
		}
		if (flag_final_pasillo_1) {
			HistoriaImagenes.Profesor2();
			
		}
		if (flag_final_pasillo_2) {
			HistoriaImagenes.Profesor3();
		}
	}
}

void CoordinadorETSIDI::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e')
		{

			//ETSIDI::play("sonidos/welcome.wav");
			//ETSIDI::playMusica("sonidos/song.mp3", true);
			estado = PRESENTACION;
		}
		if (key == 's') {
			exit(0);
		}
	}
	else if (estado == PRESENTACION) {
		if (key == 'c') {
			estado = PRESENTACION1;
		}
	}
	else if (estado == PRESENTACION1) {
		if (key == 'c') {
			estado = PRESENTACION2;
		}
	}
	else if (estado == PRESENTACION2) {
		if (key == 'c') {
			estado = ELECCION;
			
		}
	}
	else if (estado == ELECCION) {
		
			if (key == 'd') {

				estado = ELECCION_M;
				
			}
			if (key == 'a') { //hombre
				estado = ELECCION_H;
				
			}
		
	}

	else if (estado == GAMEOVER)
	{
		if (key == 'c') {
			estado = INICIO;
		}
	}
	else if (estado == FIN)
	{
		if (key == 'c') {
			estado = INICIO;
		}
	}
	else if (estado == JUEGO)
	{
		if (key == 'p')
			estado = PAUSA;
	}
	else if (estado == PAUSA)
	{
		if (key == 'c')
			estado =JUEGO;   // da problema porque se elimina Juego
	}
	else if (estado == BOSS) {
		Boss.teclaEspecial(key);
	}
	else if (estado == HISTORIA) {
		if (key == 'c') {
			Boss.inicializa(pasillo);
			estado = BOSS;
		}
	}
}

//establecemos valor al atributo genero


void CoordinadorETSIDI::teclaEspecial(unsigned char key)
{
	if (estado == JUEGO)
		Mundo.teclaEspecial(key);
	if (estado == BOSS)
		Boss.teclaEspecial(key);
}

void CoordinadorETSIDI::mueve()
{
	if (estado == JUEGO)
	{
		Mundo.mueve_p1();
		
		if (Mundo.getImpacto()) {
			int audio = rand()%2;
			switch (audio) {
			case 0:ETSIDI::play("sonidos/a_julio.wav");
				break;
			case 1:ETSIDI::play("sonidos/suspenso.wav");
				break;
			}
			if (vida > 0)
			{
				vida--;
				Mundo.resetImpacto();
			}
			if (vida == 0)
			{
				estado = GAMEOVER;
			}
		}
	}
	if (estado == BOSS)
	{
		if (pasillo == 1) {
			if (Boss.indiceImpresionPreguntas == 4) {

				flag_final_pasillo = false;  // pone false por si quiere volver a jugar sin iniciar el juego

				Boss.indiceImpresionPreguntas = 0;
				estado = JUEGO;
				ETSIDI::stopMusica();
				if (Boss.getNota() < 5.0)ETSIDI::playMusica("sonidos/SUSPENSO.mp3");
			}
			else
				Boss.mueve(0.025, 0.2);
		}
		if (pasillo == 2) {
			if (Boss.indiceImpresionPreguntas == 4) {

				flag_final_pasillo_1 = false;  // pone false por si quiere volver a jugar sin iniciar el juego

				Boss.indiceImpresionPreguntas = 0;
				estado = JUEGO;
				ETSIDI::stopMusica();
				if (Boss.getNota() < 5.0)ETSIDI::playMusica("sonidos/SUSPENSO.mp3");
			}
			else
				Boss.mueve(0.025, 0.2);
		}
		if (pasillo == 0) {
			if (Boss.indiceImpresionPreguntas == 4) {

				flag_final_pasillo_2 = false;  // pone false por si quiere volver a jugar sin iniciar el juego

				Boss.indiceImpresionPreguntas = 0;
				estado = JUEGO;
				ETSIDI::stopMusica();
				if (Boss.getNota() < 5.0)ETSIDI::playMusica("sonidos/SUSPENSO.mp3");
			}
			else
				Boss.mueve(0.025, 0.2);
		}
	}
}

//Funcion para cargar texturas
void CoordinadorETSIDI::loadTextura(const char *ruta, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4) {
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