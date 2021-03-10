#include "Interaccion.h"
#include <cmath>

Interaccion::Interaccion(void)
{
}


Interaccion::~Interaccion(void)
{
}

void Interaccion::rebote(Personaje &h, Caja c)
{
	float xmax=c.suelo.limite2.x-2;
	float xmin=c.suelo.limite1.x+2;

	float ymin = c.pared_dcha.limite1.y;

	if(h.posicion.x>xmax){
		h.posicion.x=xmax;
		h.velocidad.x=0;
	}
	if(h.posicion.x<xmin){
		h.posicion.x=xmin;
		h.velocidad.x=0;
	}
	if (h.posicion.y < ymin) h.posicion.y = ymin;
}



void Interaccion::rebote(Personaje& h, Pared plataforma) {
	float ymax = plataforma.limite1.y;

	if ((plataforma.limite2.x < h.getPosX() < plataforma.limite1.x)) {
		if (-0.2 < (ymax - h.getPosY()) < 1) {
			h.setVelY(0.0);
		}
	}
	if ((h.getPosX() > plataforma.limite1.x) && (h.getPosX() < plataforma.limite2.x)) {
		if ((ymax < h.getPosY())&&(h.getPosY()>(ymax+0.2))) {
			h.setVelY(0.0);
			h.setPosY(ymax + 0.1);
		}
	}
}


//void Interaccion::rebote(Personaje h, Pared p) {
//
//	float ymax = p->limite1.y;
//
//	//if ((h.getPosX() > p->limite1.x) && (h.getPosX() < p->limite2.x)) {
//	if ((p.limite1.x) < h.getPosX() < (p.limite2.x)) {
//		if (0.1 < (ymax - h.getPosY()) < 1.0) {
//			h.setVelY(0.0);
//		}
//	}
//	if ((h.getPosX() > p.limite1.x) && (h.getPosX() < p.limite2.x)) {
//		if ((ymax < h.getPosY()) && (h.getPosY() < (ymax + 0.2))) {
//			h.setVelY(0.0);
//			h.setPosY(ymax + 0.1);
//		}
//	}
//
//}

void Interaccion::rebote(Esfera& e, Caja c)
{
	rebote(e,c.suelo);
	rebote(e,c.techo);
	rebote(e,c.pared_dcha);
	rebote(e,c.pared_izq);
}
bool Interaccion::rebote(Esfera &e, Pared p)
{
	Vector2D dir;
	float dif=p.distancia(e.posicion,&dir)-e.radio;
	if(dif<=0.0f)
		{
		Vector2D v_inicial=e.velocidad;
		e.velocidad=v_inicial-dir*2.0*(v_inicial*dir);
		e.posicion=e.posicion-dir*dif;
		return true;
		}
	return false;
}

bool Interaccion::rebote(Esfera &esfera1, Esfera &esfera2)
{
	//Vector que une los centros
	Vector2D dif=esfera2.posicion-esfera1.posicion;
	float d=dif.modulo();
	float dentro=d-(esfera1.radio+esfera2.radio);

	if(dentro<0.0f)//si hay colision
	{
		//El modulo y argumento de la velocidad de la pelota1
		float v1=esfera1.velocidad.modulo();
		float ang1=esfera1.velocidad.argumento();

		//El modulo y argumento de la velocidad de la pelota2
		float v2=esfera2.velocidad.modulo();
		float ang2=esfera2.velocidad.argumento();
	
		//el argumento del vector que une los centros
		float angd=dif.argumento();	
		
		//Separamos las esferas, lo que se han incrustado
		//la mitad cada una
		Vector2D desp(dentro/2*cos(angd),dentro/2*sin(angd));	
		esfera1.posicion=esfera1.posicion+desp;
		esfera2.posicion=esfera2.posicion-desp;

		angd=angd-3.14159f/2;//la normal al choque
	
		//El angulo de las velocidades en el sistema relativo antes del choque
		float th1=ang1-angd;	
		float th2=ang2-angd;
		
		//Las componentes de las velocidades en el sistema relativo ANTES del choque
		float u1x=v1*cos(th1);
		float u1y=v1*sin(th1);
		float u2x=v2*cos(th2);
		float u2y=v2*sin(th2);	
	
		//Las componentes de las velocidades en el sistema relativo DESPUES del choque
		//la componente en X del sistema relativo no cambia
		float v1x=u1x;
		float v2x=u2x;

		//en el eje Y, rebote elastico
		float m1=esfera1.radio;
		float m2=esfera2.radio;
		float py=m1*u1y+m2*u2y;//Cantidad de movimiento inicial ejey
		float ey=m1*u1y*u1y+m2*u2y*u2y;//Energia cinetica inicial ejey
	
		//los coeficientes y discriminante de la ecuacion cuadrada
		float a=m2*m2+m1*m2;
		float b=-2*py*m2;
		float c=py*py-m1*ey;	
		float disc=b*b-4*a*c;
		if(disc<0)disc=0;

		//las nuevas velocidades segun el eje Y relativo
		float v2y=(-b+sqrt(disc))/(2*a);
		float v1y=(py-m2*v2y)/m1;
		
		//Modulo y argumento de las velocidades en coordenadas absolutas
		float modv1,modv2,fi1,fi2;
		modv1=sqrt(v1x*v1x+v1y*v1y);
		modv2=sqrt(v2x*v2x+v2y*v2y);
		fi1=angd+atan2(v1y,v1x);
		fi2=angd+atan2(v2y,v2x);
		
		//Velocidades en absolutas despues del choque en componentes
		esfera1.velocidad.x=modv1*cos(fi1);
		esfera1.velocidad.y=modv1*sin(fi1);
		esfera2.velocidad.x=modv2*cos(fi2);
		esfera2.velocidad.y=modv2*sin(fi2);	
	}
	return false;
}
bool Interaccion::colision(Esfera e, Personaje h)
{
	Vector2D pos=h.getPos(); //la posicion del Personaje de la base
	pos.y+=h.getAltura()/2.0f; //posicion del centro

	float distancia=(e.posicion-pos).modulo();
	if(distancia<e.radio)
		return true;	
	return false;
}


bool Interaccion::colision(ObjetoAtaca o, Personaje h)
{
	Vector2D pos = h.getPos(); //la posicion del Personaje de la base
	pos.y += h.getAltura() / 2.0f; //posicion del centro

	float distancia = (o.posicion - pos).modulo();
	if (distancia < (o.lado+0.3))
		return true;
	return false;
}




bool Interaccion::colision(ObjetoAtaca *o, Pared p) {
	if ((o->getPosY() < (p.getLimiteY2() + 0.2)) || (o->getPosY() > (p.getLimiteY2() - 0.2))) {
		if ((o->getPosX() - p.getLimiteX2()) < 0.1) {
			return true;
		}
	}
	return false;
}
/*void Interaccion::rebote(ObjetoAtaca *o, Pared *p) {
	float ymax = p->limite1.y;
	if ((o->getPos.x() > p->limite1.x) && (o->getPos.x() < p->limite2.x)) {
		if (((ymax - o->getPos.x()) < 0.4) && ((ymax - o->getPos.x()) > 0.1)) {
			o->setVel.y(0.0);
		}
	}
	if ((o->getPos.x() > p->limite1.x) && (o->getPos.x() < p->limite2.x)) {
		if ((ymax < o->getPos.y()) && (o->getPos.y() < (ymax + 0.2))) {
			o->setVel.y(0.0);
			o->setPos.y(ymax + 0.1);
		}
	}
}*/
bool Interaccion::colision(ObjetoAtaca* o, Caja c) {
	return colision(o, c.pared_dcha);
}

void Interaccion::rebote(Personaje&h, Pared*p) {

	float ymax = p->limite1.y;

	//if ((h.getPosX() > p->limite1.x) && (h.getPosX() < p->limite2.x)) {
	if ((p->limite1.x) < h.getPosX() < (p->limite2.x)) {
		if (0.1<(ymax - h.getPosY()) < 1.0) {
			h.setVelY(0.0);
		}
	}
	if ((h.getPosX() > p->limite1.x) && (h.getPosX() < p->limite2.x)) {
		if ((ymax < h.getPosY()) && (h.getPosY() < (ymax + 0.2))) {
			h.setVelY(0.0);
			h.setPosY(ymax + 0.1);
		}
	}

}


