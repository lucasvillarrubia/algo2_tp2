
#include "Juego.h"
#include <iostream>
using namespace std;


/*
 *              revisar getters y asignaciones (?)
 */


Juego::Juego(){
        // CONFIGURACON PREDETERMINADA - INICIO RÁPIDO,         etc. etc.
        this->tablero = new Tablero(1,1);
	this->turnoActual = 0;
	this->nacimientosPromedio = 0;
	this->muertesPromedio = 0;
	this->nacidasEnTurno = 0;
	this->muertasEnTurno = 0;
	this->diasSinCambio = 0;
}


Juego::Juego(char* configuracion){
        // FUNCIÓN QUE LEE ARCHIVO .TXT         etc. etc.
}


void Juego::mostrarTablero(){
        // USANDO EL BITMAP,            etc. etc.
}


unsigned int Juego::getTurnoActual(){
        return this->turnoActual;
}


unsigned int Juego::getNacimientosPromedio(){
        return this->nacimientosPromedio;
}


unsigned int Juego::getMuertesPromedio(){
        return this->muertesPromedio;
}


unsigned int Juego::getNacidasEnTurno(){
        return this->nacidasEnTurno;
}


unsigned int Juego::getMuertasEnTurno(){
        return this->muertasEnTurno;
}


unsigned int Juego::getDiasSinCambio(){
        return this->diasSinCambio;
}


Tablero* Juego::getTablero(){
        return this->tablero;
}


void Juego::mostrarEstadisticas(){
        cout << "Days without freezing: " << this->getTurnoActual() << endl;
	cout << "\nEl turno anterior se contabilizaron:" << endl;
	cout << "\tNacimientos: " << this->getNacidasEnTurno() << endl;
	cout << "\tMuertes: " << this->getMuertasEnTurno() << endl;
	cout << "\nPromedio total de nacimientos: " << this->getNacimientosPromedio() << endl;
	cout << "Promedio total de muertes: " << this->getMuertesPromedio() << endl;
}


void Juego::actualizarJuego (){

	if (this->getDiasSinCambio() >= 2)
		this->estado = CONGELADO;
	int nacimientosTotales = 0, muertesTotales = 0;

        // en mi tp1, el tablero era  el que tenía información sobre las células, no sé en dónde estaría
        // el método de conteo, si en el tablero o en el juego.-
	//      int vivasAntes = this->getTablero()->getCelulasVivas(); ????????????
        //      int muertasAntes = this->getTablero()->getCelulasMuertas(); ????????????
	this->turnoActual++;

        // DEFINIDA MÁS ABAJO, COMENTADA PARA COPYPASTE EN tablero.cpp
	this->getTablero()->actualizarTablero();

        // idem lo de más arriba, si se agregan los métodos al TDA Tablero quedaría así:
	//      this->nacidasEnTurno = this->getTablero()->getCelulasVivas() - vivasAntes;
	//      this->muertasEnTurno = this->getTablero()->getCelulasMuertas() - muertasAntes;
	nacimientosTotales += this->getNacidasEnTurno();
	this->nacimientosPromedio = (nacimientosTotales / this->getTurnoActual());
	muertesTotales += this->getMuertasEnTurno();
	this->muertesPromedio = (muertesTotales / this->getTurnoActual());
	if (this->getNacidasEnTurno() == 0 && this->getMuertasEnTurno() == 0)
		this->diasSinCambio++;
}


void Juego::jugarTurno(char inputUser){
	switch (inputUser) {
		case 'x':
			this->estado = TERMINADO;
                        // TERMINAR
			cout << "\nJuego terminado. Nos vemos en otra vida." << endl;
			break;
		case 'r':
			this->estado = REINICIADO;
			// REINICIAR
			cout << "REINICIADO" << endl;
			break;
		default:
			this->actualizarJuego();
			if (this->getEstado() == CONGELADO) {
				// CONGELAMIENTO (???)
                                this->estado = CONGELADO;
			}
	}
}




/*******************************		NEW		   *******************************/

// una función privada que cuenta las vecinas de una célula (no sé si es tan necesaria)
//
// int Tablero::celulaVecinasVivas (Celula* celula) 
// {
// 	int contadorVecinasVivas = 0;
// 	for (int i = 0; i < 8; i++) {
// 		if (celula->mostrarCelulasVecinas(i) == vivo) {
// 			contadorVecinasVivas++;
// 		}
// 	}
// 	return contadorVecinasVivas;
// }


// función pública que junta en una matriz (o tablero 2D) los números de vecinas vivas de cada célula
// para "diagnosticar" a cada una estáticamente y no en medio de un recorrido 
//
// void Tablero::actualizarTablero(){
// 	int screenshotTablero [this->filas][this->columnas];
// 	for (int i = 0; i < this->filas; i++) {
// 		for (int j = 0; j < this->columnas; j++) {
// 			screenshotTablero [i][j] = this->celulaVecinasVivas(this->getCasillero(i,j)->getCelula());
// 		}
// 	}
// 	for (int i = 0; i < this->filas; i++) {
// 		for (int j = 0; j < this->columnas; j++) {
// 			if ((this->getCasillero(i,j)->getCelula()->getEstado() == muerto) && (screenshotTablero[i][j] == 3)) {
// 				this->getCasillero(i,j)->getCelula()->setCelulaViva();
// 			}
// 			else if (this->getCasillero(i,j)->getCelula()->getEstado() == vivo && (screenshotTablero[i][j] < 2 || screenshotTablero[i][j] > 3)) {
// 				this->getCasillero(i,j)->getCelula()->setCelulaMuerta();
// 			}
// 		}
// 	}
// }
/*********************************************************************************************/