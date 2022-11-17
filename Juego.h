#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"


typedef enum EstadoJuego {
	JUGANDO,
	CONGELADO,
	REINICIADO,
	TERMINADO
};

class Juego {
	private:
		Tablero* tablero;
		EstadoJuego estado;
		int turnoActual;
		int nacimientosPromedio;
		int muertesPromedio;
		int nacidasEnTurno;
		int muertasEnTurno;
		int diasSinCambio;
		void actualizarJuego();
	public:
		Juego();
		Juego(char* configuracion);
		void mostrarTablero();
		EstadoJuego getEstado();
		Tablero* getTablero();
		unsigned int getTurnoActual();
		unsigned int getNacimientosPromedio();
		unsigned int getMuertesPromedio();
		unsigned int getNacidasEnTurno();
		unsigned int getMuertasEnTurno();
		unsigned int getDiasSinCambio();
		void mostrarEstadisticas();
		void jugarTurno(char inputUser);
};


#endif /* JUEGO_H */