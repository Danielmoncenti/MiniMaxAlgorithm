#pragma once

#include <iostream>

enum class Ficha { VACIO = '.', JUGADOR = 'X', IA = 'O' };
const size_t MAX = 3;
const size_t PROFUNDIDAD = 8;

class Tablero
{
		
	Ficha tablero[MAX][MAX];

	public:

		/*
		 * Constructor por defecto.
		 * Coloca en todas las casillas de tablero un VACIO
		 */
		Tablero();
		
		/*
		 * Comprueba si hay ganador. Si lo hay retorna el símbolo del que ha ganado.
		 * Sino ha ganado nadie, retorna VACIO.
		 */
		Ficha HayGanador();
		
		/*
		 * Retorna qué ficha hay en la posición indicada
		 */
		Ficha GetFichaPosicion(int _x, int _y);
		
		/*
		 * Retorna el número de posiciones ocupadas
		 */
		int GetNumPosicionesOcupadas();
		
		/*
		 * Coloca la ficha indicada en la posición x,y.
		 * Retorna true si la posición destino estaba vacía
		 * Retorna false si esa posición estaba ocupada y no se
		 * puede colocar la ficha
		 */
		bool PonTirada(int _x, int _y, int _ficha /*Ficha _ficha*/);
		
		/*
		 * Elimina la ficha que hay en esa posición y coloca un VACIO
		 * Esto vendrá bien cuando estemos recorriendo todas las
		 * posibilidades de tiradas y tengamos que volver atrás en la
		 * recursión.
		 */
		void QuitaTirada(int _x, int _y);
		
		/*
		 * Retorna valoración de la situación del tablero
		 * La valoración será la siguiente:
		 * 1. Si ha ganado la ficha _jugador --> se retorna 500
		 * 2. Si hay dos fichas seguidas de _jugador y la tercera posición
		 * es vacía --> se retorna 300
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


