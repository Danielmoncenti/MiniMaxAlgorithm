#pragma once

#include <iostream>

enum class Ficha { VACIO = '.', JUGADOR = 'X', IA = 'O' };
const size_t MAX = 3;
const size_t PROFUNDIDAD = 8;

class Tablero
{
		/*TODO: Eres el programador de todo esto, decide una representaci�n*/
	Ficha tablero[MAX][MAX];

	public:

		/*
		 * Constructor por defecto.
		 * Coloca en todas las casillas de tablero un VACIO
		 */
		Tablero();
		
		/*
		 * Comprueba si hay ganador. Si lo hay retorna el s�mbolo del que ha ganado.
		 * Sino ha ganado nadie, retorna VACIO.
		 */
		Ficha HayGanador();
		
		/*
		 * Retorna qu� ficha hay en la posici�n indicada
		 */
		Ficha GetFichaPosicion(int _x, int _y);
		
		/*
		 * Retorna el n�mero de posiciones ocupadas
		 */
		int GetNumPosicionesOcupadas();
		
		/*
		 * Coloca la ficha indicada en la posici�n x,y.
		 * Retorna true si la posici�n destino estaba vac�a
		 * Retorna false si esa posici�n estaba ocupada y no se
		 * puede colocar la ficha
		 */
		bool PonTirada(int _x, int _y, int _ficha /*Ficha _ficha*/);
		
		/*
		 * Elimina la ficha que hay en esa posici�n y coloca un VACIO
		 * Esto vendr� bien cuando estemos recorriendo todas las
		 * posibilidades de tiradas y tengamos que volver atr�s en la
		 * recursi�n.
		 */
		void QuitaTirada(int _x, int _y);
		
		/*
		 * Retorna valoraci�n de la situaci�n del tablero
		 * La valoraci�n ser� la siguiente:
		 * 1. Si ha ganado la ficha _jugador --> se retorna 500
		 * 2. Si hay dos fichas seguidas de _jugador y la tercera posici�n
		 * es vac�a --> se retorna 300
		 * 3. Si no se cumple ninguna de las anteriores --> se retorna 0
		 */
		int Evaluacion(Ficha _jugador);

		 /*
		 * Si el jugador humano tira primero, retorna 0
		 * En caso contrario, 1
		 */
		int PreguntarTurno();

		/*
		 * Sobrecarga del operador << para mostrar el tablero por pantalla
		 */
		friend std::ostream& operator<<(std::ostream& _os, Tablero _tablero);

		int tipo;
};


