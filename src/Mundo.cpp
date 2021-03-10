//version del SDK de windows 10.0.16299.0

#include "Mundo.h"
#include "glut.h"
#include <cmath>
#include "Interaccion.h"
#include "CoordinadorPang.h"

Mundo::Mundo() {}


Mundo::~Mundo()
{
	volador.destruirContenido();
	enemigo.destruirContenido();
	
}

void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
float Mundo::getOjoX() {
	if (personaje.getPosX() < 0.0f)return 0.0f;
	if (personaje.getPosX() > 90.f)return 90.0f;
	return personaje.getPosX();
	
}

float Mundo::Ojo(Personaje p) {
	if (p.getPosX() < (0.0f)) {
		x_ojo = 0.0f;
		return x_ojo;
	}
	if (p.getPosX() > 90.0f) {
		x_ojo = 90.0f;
		return x_ojo;
	}
	return p.getPosX();
}





void Mundo::dibuja_p1(int genero)
{
	gluLookAt(Ojo(personaje), y_ojo, z_ojo,  // posicion del ojo
		Ojo(personaje), y_ojo, 0.0,      // hacia que punto mira  
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

							 //aqui es donde hay que poner el codigo de dibujo
	caja.dibuja();
	if (genero == 1) {
		personaje.SetHombre();
		personaje.Dibujahombre();
	}
	if (genero == 2) {
		personaje.SetMujer();
		personaje.Dibujamujer();
	}
	//plataforma.dibuja();
	//plataformas.dibuja();
	enemigo.SetLimpieza();
	enemigo.DibujaLimpieza();//Señora de la llimpieza


}
void Mundo::dibuja_p2(int genero)
{
	gluLookAt(Ojo(personaje), y_ojo, z_ojo,  // posicion del ojo
		Ojo(personaje), y_ojo, 0.0,      // hacia que punto mira  
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

//aqui es donde hay que poner el codigo de dibujo
	caja.dibuja_p2();
	if (genero == 1) {
		personaje.SetHombre();
		personaje.Dibujahombre();
	}
	if (genero == 2) {
		personaje.SetMujer();
		personaje.Dibujamujer();
	}
	
	enemigo.SetAlumno();
	enemigo.DibujaAlumno();
}
void Mundo::dibuja_p3(int genero)
{
	gluLookAt(Ojo(personaje), y_ojo, z_ojo,  // posicion del ojo
		Ojo(personaje), y_ojo, 0.0,      // hacia que punto mira  
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

//aqui es donde hay que poner el codigo de dibujo
	caja.dibuja_p3();
	if (genero == 1) {
		personaje.SetHombre();
		personaje.Dibujahombre();
	}
	if (genero == 2) {
		personaje.SetMujer();
		personaje.Dibujamujer();
	}
	
	enemigo.SetAlumno();
	enemigo.DibujaAlumno();
	volador.dibuja();
}
void Mundo::mueve_p1()
{

	personaje.mueve(0.025f);
	enemigo.mueve(0.025f);



	//enemigo.colision(caja);
	//enemigo.colision(personaje);

	Interaccion::rebote(personaje, caja);
	Interaccion::rebote(personaje, plataforma);


	//DESTRUCION enemigo
	for (int i = 0; i < num; i++) {
		if (Interaccion::colision(enemigo[i], caja)) {
			enemigo.eliminar(enemigo[i]);
		}
	}

	if ((3 - enemigo.getNumero()) > 0) {
		for (int i = 0; i < (3 - enemigo.getNumero()); i++) {
			ObjetoAtaca* a = new ObjetoAtaca();
			a->setPos(94, 1);
			enemigo.agregar(a);
		}
	}

	if (enemigo.colision(personaje)) impacto = true;

}
void Mundo::mueve_p2()
{
	enemigo.mueve(0.025f);
	personaje.mueve(0.025f);

	//enemigo.colision(plataforma);
	//enemigo.colision(caja);
	//enemigo.colision(personaje);


	Interaccion::rebote(personaje, caja);
	Interaccion::rebote(personaje, plataforma);

	for (int i = 0; i < plataformas.getNumero(); i++) {

		Interaccion::rebote(personaje, plataformas[i]);


	}

	//DESTRUCION enemigo
	for (int i = 0; i < num; i++) {
		if (Interaccion::colision(enemigo[i], caja)) {
			enemigo.eliminar(enemigo[i]);
		}
	}

	if ((3 - enemigo.getNumero()) > 0) {
		for (int i = 0; i < (3 - enemigo.getNumero()); i++) {
			ObjetoAtaca* a = new ObjetoAtaca();
			a->setPos(94, 1);
			enemigo.agregar(a);
		}
	}

	if (enemigo.colision(personaje)) impacto = true;


}

void Mundo::mueve_p3()
{
	enemigo.mueve(0.025f);
	personaje.mueve(0.025f);
	volador.mueve(0.025f);
	
	volador.rebote();
	volador.rebote(plataforma);
	volador.rebote(caja);
	
	//enemigo.colision(plataforma);
	//enemigo.colision(caja);
	//enemigo.colision(personaje);

	Interaccion::rebote(personaje, caja);
	Interaccion::rebote(personaje, plataforma);

	volador.colision(personaje);
	


	for (int i = 0; i < plataformas.getNumero(); i++) {

		Interaccion::rebote(personaje, plataformas[i]);


	}

	//DESTRUCION enemigo
	for (int i = 0; i < num; i++) {
		if (Interaccion::colision(enemigo[i], caja)) {
			enemigo.eliminar(enemigo[i]);
		}
	}

	if ((3 - enemigo.getNumero()) > 0) {
		for (int i = 0; i < (3 - enemigo.getNumero()); i++) {
			ObjetoAtaca* a = new ObjetoAtaca();
			a->setPos(94, 1);
			enemigo.agregar(a);
		}
	}

	if (enemigo.colision(personaje)) impacto = true;
	if (volador.colision(personaje)) impacto = true;


}


void Mundo::inicializa_p1()
{
	//Destrucción del viejo mundo

	impacto = false;


	personaje.setPos(0, 0);

	volador.destruirContenido();
	enemigo.destruirContenido();
	volador.destruirContenido();

	//Creación del nuevo mundo

	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	nivel = 0;


	//plataforma.setPos(-5.0f,5.0f,5.0f,5.0f);

	//creando enemigos

	//4º Matricula
	for (i = 0; i < 3; i++) {
		ObjetoAtaca* a = new ObjetoAtaca();
		a->setPos(1 + rand() % (101 - 1), 1);
		enemigo.agregar(a);
	}




	//Carga de la lista de plataformas
	/*for (i = 0; i < 5; i++) {
		Pared *p = new Pared();
		p->setPos(-3.0 + a, b, 3.0f + a, b);
		p->setColor(0, 0, 0);
		plataformas.Agregar(p);
		a += 10 + (5 + rand() % (11 - 5));
		b = (4 + rand() % (8 - 4));
	}*/
}
void Mundo::inicializa_p2()
{
	//Destrucción del viejo mundo

	impacto = false;
	personaje.setPos(0, 0);
	//volador.destruirContenido();
	enemigo.destruirContenido();
	//volador.destruirContenido();

	//Creación del nuevo mundo

	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	nivel = 0;


	//plataforma.setPos(-5.0f,5.0f,5.0f,5.0f);

	//creando enemigos




}

void Mundo::inicializa_p3()
{
	//Destrucción del viejo mundo

	impacto = false;
	personaje.setPos(0, 0);
	volador.destruirContenido();
	enemigo.destruirContenido();


	//Creación del nuevo mundo

	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	nivel = 0;



	//creando enemigos

	//4º Matricula
	for (i = 0; i < 3; i++) {
		ObjetoAtaca* a = new ObjetoAtaca();
		a->setPos(1 + rand() % (101 - 1), 1);
		enemigo.agregar(a);
	}

	Esfera* e1 = new Esfera(1.5f, 56, 4, 5, 15);
	e1->setColor(0, 0, 255);
	volador.agregar(e1); //esfera

	Esfera* e2 = new Esfera(2, 58, 2, -5, 15);
	e2->setColor(255, 255, 255);
	volador.agregar(e2); //esfera2

	Esfera* e3 = new Esfera(2, 58, 2, -5, 15);
	e3->setColor(255, 255, 255);
	volador.agregar(e3); //esfera3


	Esfera* e4 = new Esfera(2, 35, 10, -6, 11);
	e4->setColor(255, 255, 255);
	volador.agregar(e4); //esfera4

	Esfera* e5 = new Esfera(2, 10, 8, -8, 14);
	e5->setColor(255, 255, 255);
	volador.agregar(e5); //esfera5


}



void Mundo::tecla(unsigned char key)   //WTF
{
		switch(key)
	{
		case '1':	
 			volador.agregar (new Esfera(0.5f,0,10));
			break;
		case '2':	
 			volador.agregar (new Esfera(1.0f,0,10));
			break;
		case '3':	
 			volador.agregar (new Esfera(1.5f,0,10));
			break;
		case '4':	
 			volador.agregar (new Esfera(2.0f,0,10));
			break;
	}

}

void Mundo::teclaEspecial(unsigned char key)
{
	switch(key)
	{
	case GLUT_KEY_LEFT:
		personaje.setVel (-5.0f, 0.0f);
		
		break;
	case GLUT_KEY_RIGHT:
		personaje.setVel (5.0f, 0.0f);
		
		break;
	case GLUT_KEY_UP:
	
		for (int i = 0; i < plataformas.getNumero(); i++) {
			if(-0.1<(personaje.getPosY()-(plataformas[i]->getLimiteY2()))<0.1) personaje.setVelY(15.0f);
			
		}
		if (-0.1 < (personaje.getPosY() - (plataforma.getLimiteY2())) < 0.1) personaje.setVelY(15.0f);
		
		if ((personaje.getPosY() - caja.getSueloLimiteY2()) < 0.05) {
			personaje.setVelY(15.0f);
			ETSIDI::play("sonidos/boing.wav");
		}
		break;
	}
	
}

