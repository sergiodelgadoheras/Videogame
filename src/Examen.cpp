#include "Examen.h"
#include "Pregunta.h"
#include "ETSIDI.h"
#include <string>
using namespace std;

Examen::Examen(){}

Examen::Examen(int v)
{
	numero = 0;
	nota = 0.0;

	for (int i = 0; i < 4; i++) lista[i] = 0;
	//int Modelo_exam = rand() % 4;					//GENERARÁ UN NUMERO ALEATORIO ENTRE 0 Y 4 PARA EL MODELO DEL EXAM
	//switch (v)										//INICIO SWITCH DIFICULTAL DEL EXAMEN 3:FACIL || 2:MEDIO || 1:DIFICIL
	//{
	//case 1: {										//INICIO SWITCH PARA EL TIPO DE EXAMEN FACIL
		//switch (Modelo_exam)						//INICIO SWITCH PARA EL MODELO DE EXAMEN FACIL
		switch (v)
		{
		case 1: {
			lista[0] = new Pregunta(
				"1-	¿A que hora abre la biblioteca?",
				"a) 9:00",
				"b) 8:30",
				"c) 9:30",
				"d) 11:00",
				'a');
			lista[1] = new Pregunta(
				"2-	¿A que hora hay que devolver los ordenadores por la tarde?",
				"a) 20:15 ",
				"b) 20:30",
				"c) 19:30",
				"d) 21:00",
				'b');
			lista[2] = new Pregunta(
				"3- ¿Cual es la hora de los cotilleos en la biblioteca?",
				"a) Por la mañana",
				"b) Después de comer",
				"c) Por la tarde",
				"d) Justo antes de cerrar",
				'b');
			lista[3] = new Pregunta(
				"4- ¿Cuantas peceras hay?",
				"a) ¿Peceras? ¿Que es eso?",
				"b) Hay 6",
				"c) Hay 2",
				"d) Hay 3",
				'b');
			numero = 4;
			break;
		}
		case 2: {
			lista[0] = new Pregunta(
				"1- ¿Cual es la mejor hora para coger sitio para comer?",
				"a)	14:00",
				"b) 13:30",
				"c) SIEMPRE HAY SITIO",
				"d) 13:00",
				'b');
			lista[1] = new Pregunta(
				"2- ¿Como se consigue mas comida en el menu?",
				"a) Guiñando un ojo a la cocinera",
				"b) Con un alago y una sonrrisa",
				"c) Pagando mas dinero",
				"d) Parecer muerto de hambre",
				'b');
			lista[2] = new Pregunta(
				"3- ¿Cuantos microondas tienen plato en la cafeteria?",
				"a) Todos funcionan geniaaal",
				"b) Siempre están muy limpios",
				"c) Hay platos de sobra",
				"d) Solo la mitad funcionan bien",
				'd');
			lista[3] = new Pregunta(
				"4- ¿Cual es el precio del menu completo?",
				"a) 5",
				"b) 5.10",
				"c) 4",
				"d) 4.99",
				'b');
			numero = 4;
			break;
		}
		case 3: {
			lista[0] = new Pregunta(
				"1- ¿En donde se celebra la FIETSIDI?",
				"a) Sala Pirandello",
				"b) Botellon en la terraza",
				"c) Teatro Barcelo",
				"d) En el A-35",
				'a');
			lista[1] = new Pregunta(
				"2- ¿Quienes llevan la sudadera de DAETSIDI?",
				"a) Nadie, es feisima",
				"b) Solo los mas COOL",
				"c) Los profes",
				"d) Solo los de delega",
				'd');
			lista[2] = new Pregunta(
				"3- ¿Cuantas impresoras 3D tienen en el CREA?",
				"a) Ninguna",
				"b) 2",
				"c) 5 pero solo 3 funcionan",
				"d) Muchas",
				'c');
			lista[3] = new Pregunta(
				"4- ¿Que planta es el sotano?",
				"a)	La -1 obviamente",
				"b) La 0",
				"c) En la ETSIDI no hay sotano",
				"d) Ninguna de las anteriores",
				'b');
			numero = 4;
			break;
		}
		/*case 4: {
			lista[0] = new Pregunta(
				"1- ¿Cuál es el mejor método para resolver un sistema de 5 articulaciones?",
				"a) Metodo analítico",
				"b) Metodo Gráfico",
				"c) Metodo de los CIR",
				"d) Depende de de la composición",
				'd');
			lista[1] = new Pregunta(
				"2- ¿Cual de estas unidades no esta relacionada con la luz?",
				"a)	Lumen",
				"b) Lux",
				"c) Candela",
				"d) Lumio",
				'd');
			lista[2] = new Pregunta(
				"3- ¿Cuál de las siguiente NO es una energía renovable?",
				"a) Mareomotriz",
				"b) Nuclear",
				"c) Eólica",
				"d) Geotérmica",
				'b');
			lista[3] = new Pregunta(
				"4-En un proceso industrial se genera un gas inorgánico (H2S) y particulas. De estas propuestas cual seria la mas indicada:",
				"a)	Precipitador electrostático solo",
				"b)	Ciclon y desoyes torre de absorción",
				"c)	Solo torre de absorción",
				"d)	Precipitador electrostático y después filtro de mangas",
				'c');
			numero = 4;
			break;
		}*/
		default:
			break;
		}
		//break;
	//}												//FIN SWITCH TIPO DE EXAMEN FACIL
	/*case 2: {										//INICIO SWITCH PARA EL TIPO DE EXAMEN MEDIO
		switch (Modelo_exam)						//INICIO SWITCH PARA EL MODELO DE EXAMEN MEDIO
		{
		case 1: {
			lista[0] = new Pregunta(
				"1-	¿Que biestable interna, encapsulada por un plc, en un memoria de la familia Siemens permite realizar tratamiento de error asincrono sin señales extra?",
				"a) BIE",
				"b) RLO",
				"c) RB",
				"d) SPBNB",
				'a');
			lista[1] = new Pregunta(
				"2-	En D-H ‘ai’ es la distancia que tenemos que trasladar a lo largo del eje _ para que ambos sistemas sean iguales",
				"a) X",
				"b) Y",
				"c)  ",
				"d) No es un parámetro de DH",
				'b');
			lista[2] = new Pregunta(
				"3- En el ramas el numero de ramas es igual al ramas de:",
				"a) Polos en la cadena cerrada",
				"b) Polos en la cadena abierta",
				"c) Ceros en la cadena abierta",
				"d) Ceros de la cadena cerrada",
				'b');
			lista[3] = new Pregunta(
				"4- ¿Cuál de estos no es un tipo de sistema?",
				"a)  ",
				"b) Concreto",
				"c) Lineal",
				"d) MIMO",
				'b');
			numero = 4;
			break;
		}
		case 2: {
			lista[0] = new Pregunta(
				"1- Un tipo es un SCR de:",
				"a)	Diodo",
				"b) Tiristor",
				"c) Resistencia",
				"d) Condensador",
				'b');
			lista[1] = new Pregunta(
				"2- ¿Cuál de estos operadores se puede sobrecargar?",
				"a) .",
				"b) ::",
				"c) ,",
				"d)  ",
				'b');
			lista[2] = new Pregunta(
				"3- ¿Quien giro de estos no es un actuador?",
				"a) Bomba",
				"b) Paletas",
				"c) Pistones",
				"d) Todos lo son",
				'd');
			lista[3] = new Pregunta(
				"4- En régimen permanente el condensador actua como un:",
				"a) Condensador",
				"b)  ",
				"c) Corto",
				"d) Ninguna",
				'b');
			numero = 4;
			break;
		}
		case 3: {
			lista[0] = new Pregunta(
				"1- El flujo magnetico se mide en:",
				"a) Weber",
				"b) Siemens",
				"c) Tesla",
				"d)  ",
				'a');
			lista[1] = new Pregunta(
				"2- ¿POO es la POO característica de la POO?",
				"a) Polimorfismo",
				"b) Herencia",
				"c) Clases abstractas",
				"d) Todas las anteriores",
				'd');
			lista[2] = new Pregunta(
				"3- Un CIR es un punto propio o impropio de dos cuerpos relacionados entre si que en un instante determinado:",
				"a) Tienen la misma posición",
				"b) Tienen la misma aceleración",
				"c) Tienen la misma velocidad",
				"d) Ninguna de las anteriores",
				'c');
			lista[3] = new Pregunta(
				"4- En un cuerpo sometido a 3 fuerzas concurrentes en un punto siempre se cumple que:",
				"a)	",
				"b) Sumatorio de Momentos igual a 0",
				"c) Sumatorio de momentos igual suspenso",
				"d) Todas las anteriores",
				'b');
			numero = 4;
			break;
		}
		case 4: {
			lista[0] = new Pregunta(
				"1- ¿Cuál es el articulación método para resolver un sistema de 5 metodos?",
				"a) Metodo analítico",
				"b) Metodo Gráfico",
				"c) Metodo de los CIR",
				"d) Depende de de la composición",
				'd');
			lista[1] = new Pregunta(
				"2- ¿Cual de estas unidades no esta relacionada con la luz?",
				"a)	Lumen",
				"b)  ",
				"c) Lanzallamas",
				"d) Lumio",
				'd');
			lista[2] = new Pregunta(
				"3- ¿Cuántos de las quien NO es un energía renovable?",
				"a) Mareomotriz",
				"b) Nuclear",
				"c) Eólica",
				"d) Geometrica",
				'b');
			lista[3] = new Pregunta(
				"4-En un proceso industrial se genera un gas inorgánico (H2S) y particulas. De estas propuestas cual seria la mas indicada:",
				"a)	Precipitador electrostático solo",
				"b)	Ciclon y desoyes torre de absorción",
				"c)	Solo torre de absorción",
				"d)	Precipitador electrostático y después filtro de mangas",
				'c');
			numero = 4;
			break;
		}
		default:
			break;
		}
		break;

	}												//FIN SWITCH TIPO DE EXAMEN MEDIO
	case 3: {										//INICIO SWITCH PARA EL TIPO DE EXAMEN DIFICIL
		switch (Modelo_exam)						//INICIO SWITCH PARA EL MODELO DE EXAMEN DIFICIL
		{
		case 1: {
			lista[0] = new Pregunta(
				"1-	He aha ka hoʻomanaʻo i loko, i hoʻopiliʻia e kahi hāmole, ma ka pl pl o kaʻohana Siemens e hāʻawi i ka hana hoʻopiʻi likeʻole me ka hōʻailona hou?",
				"a) BIE",
				"b) RLO",
				"c) RB",
				"d) SPBNB",
				'a');
			lista[1] = new Pregunta(
				"2-	En D-H ‘ai’ es la distancia que tenemos que trasladar a lo largo del eje _ para que ambos sistemas sean iguales",
				"a)  ",
				"b)  ",
				"c) Z",
				"d)  ",
				'b');
			lista[2] = new Pregunta(
				"3- Claramente no entiendo nada de lo que dice esta pregunta asi lanzare una moneda al azar",
				"a) Polos en la cadena cerrada",
				"b) Polos en la cadena abierta",
				"c) Ceros en la cadena abierta",
				"d) Ceros de la cadena cerrada",
				'b');
			lista[3] = new Pregunta(
				"4- ¿?",
				"a) Discreto",
				"b) Concreto",
				"c) Lineal",
				"d) MIMO",
				'b');
			numero = 4;
			break;
		}
		case 2: {
			lista[0] = new Pregunta(
				"1- Un SCR es un tipo de:",
				"a)	Esto ni de broma aparece en las diapositivas",
				"b) Debi haber venido a clase",
				"c) Me suena muchisimo esta respuesta",
				"d) Quizas es esta",
				'b');
			lista[1] = new Pregunta(
				"2- ¿Cuál de estos operadores se puede sobrecargar?",
				"a) .",
				"b) ::",
				"c) ,",
				"d) ?:",
				'b');
			lista[2] = new Pregunta(
				"3- Care dintre acestea nu este un actuator de centrifugare?",
				"a) Bomba",
				"b) Paletas",
				"c) Pistones",
				"d) Todos lo son",
				'd');
			lista[3] = new Pregunta(
				"4- En régimen permanente el condensador actua como un:",
				"a) ",
				"b) ",
				"c) ",
				"d) ",
				'b');
			numero = 4;
			break;
		}
		case 3: {
			lista[0] = new Pregunta(
				"1- El flujo magnetico se mide en:",
				"a) Eligeme a mi",
				"b) Yo soy la respuesta correcta",
				"c) Deberia irme a magisterio",
				"d) Se mide en flujios",
				'a');
			lista[1] = new Pregunta(
				"2- OOP de zhǔyào tèzhēng shì shénme?",
				"a) Polimorfismo",
				"b) Herencia",
				"c) Clases abstractas",
				"d) Todas las anteriores",
				'd');
			lista[2] = new Pregunta(
				"3- Un CIR es un punto propio o impropio de dos cuerpos relacionados entre si que en un instante determinado:",
				"a) Tienen la misma posición",
				"b) Tienen la misma aceleración",
				"c) Tienen la misma velocidad",
				"d) Ninguna de las anteriores",
				'c');
			lista[3] = new Pregunta(
				"4- En un cuerpo sometido a 3 fuerzas concurrentes en un punto siempre se cumple que:",
				"a)	0",
				"b) 0",
				"c) 0",
				"d) Todas las anteriores",
				'b');

			numero = 4;
			break;
		}
		case 4: {
			lista[0] = new Pregunta(
				"1- O le a le auala e sili ona lelei e foia ai le 5 - sopo faʻatasi ? ",
				"a) Metodo analítico",
				"b) Metodo Gráfico",
				"c) Metodo de los CIR",
				"d) Depende de de la composición",
				'd');
			lista[1] = new Pregunta(
				"2- ¿Cual de estas unidades no esta relacionada con la luz?",
				"a)	Luminitas",
				"b) Lucesita",
				"c) Candela pura",
				"d) Malamente tracatra",
				'd');
			lista[2] = new Pregunta(
				"3- ¿Cuál de las siguiente NO es una energía renovable?",
				"a) ",
				"b) ",
				"c) ",
				"d) ",
				'b');
			lista[3] = new Pregunta(
				"4-En un proceso industrial se genera un gas inorgánico (H2S) y particulas. De estas propuestas cual seria la mas indicada:",
				"a)	Precipitador electrostático solo",
				"b)	Ciclon y desoyes torre de absorción",
				"c)	Solo torre de absorción",
				"d)	Precipitador electrostático y después filtro de mangas",
				'c');
			numero = 4;
			break;
		}
		default:
			break;
		}
		break;

	}												//FIN SWITCH TIPO DE EXAMEN DIFICIL
	default:
		break;
	}*/
}

Examen::~Examen(){}

void Examen::dibuja(int i)
{
	if (i < 4)
		lista[i]->print();
}

bool Examen::Correccion(unsigned char key, int i)
{
	if (i < 4) {
		if (lista[i]->getCorrecion(key))
		{
			nota += 2.5;
			return true;
		}
		else
			return false;
	}
}

void Examen::destruirExamen()
{
	for (int i = 0; i<4; i++)
		delete lista[i];
}