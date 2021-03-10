#pragma once
#include "Mundo.h"
#include "Boss.h"
#include "HistoriaImagenes.h"

class CoordinadorETSIDI
{
public:
	CoordinadorETSIDI();
	virtual ~CoordinadorETSIDI();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	Mundo Mundo;
	Boss Boss;
	HistoriaImagenes HistoriaImagenes;
	void loadTextura(const char *ruta, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4);
	int genero;

	//void Setgenero(int _genero) { genero = _genero; };
	//int Getgenero() { return genero; };



protected:
	enum Estado { INICIO, PRESENTACION, PRESENTACION1, PRESENTACION2, ELECCION, ELECCION_H, ELECCION_M, JUEGO, HISTORIA, BOSS, GAMEOVER, FIN, PAUSA };
	Estado estado;
	int pasillo;
	bool flag_final_pasillo;
	bool flag_final_pasillo_1;
	bool flag_final_pasillo_2;
	int vida;
	int r;

	
};