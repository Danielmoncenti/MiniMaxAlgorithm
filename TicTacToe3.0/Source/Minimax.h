#pragma once

#include "Tablero.h"

class Minimax
{
	private:
		Tablero* tablero;
	
		/*
		 * Explora todas las posibles tiradas del jugador en
		 * las posiciones vac�as.
		 * Para cada una de estas posibles tiradas, se llama al
		 * BuscaMax, que buscar� la mejor tirada posible de la IA
		 * a partir de esa posici�n.
		 * De cada una de las tiradas posible, sube una puntuaci�n desde
		 * BuscaMax. BuscaMin nos retorna la puntuaci�n m�s baja (min)
		 * Los casos triviales son:
		 * - Que se haya llegado a la _profundidad indicada (la primera de
		 * las llamadas empieza con profundidad 0).
		 * - Que el tablero est� lleno
		 * - Que haya ganado o bien el jugador o bien la IA
		 * Al llegar al caso trivial, se retorna el resultado de la funci�n
		 * ValoraJuego()
		 */
		int BuscaMin(int _profundidad); //jugador
		
		/*
		 * Explora todas las posibles tiradas de la IA en
		 * las posiciones vac�as.
		 * Para cada una de estas posibles tiradas, se llama al
		 * BuscaMin, que buscar� la mejor tirada posible del jugador
		 * a partir de esa posici�n.
		 * De cada una de las tiradas posible, sube una puntuaci�n desde
		 * BuscaMin. BuscaMax nos retorna la puntuaci�n m�s alta (max)
		 * Los casos triviales son:
		 * - Que se haya llegado a la _profundidad indicada (la primera de
		 * las llamadas empieza con profundidad 0).
		 * - Que el tablero est� lleno
		 * - Que haya ganado o bien el jugador o bien la IA
		 * Al llegar al caso trivial, se retorna el resultado de la funci�n
		 * ValoraJuego()
		 */
		int BuscaMax(int _profundidad); //ia

		/*
		 * Retorna una valoraci�n de la situaci�n
		 * del tablero que se puede basar en:
		 * Puntuaci�n = Evaluaci�n(IA) - Evaluaci�n(JUGADOR)
		 * Se debe usar la funci�n evaluaci�n ya implementada
		 * en tablero*/
		int ValoraJuego();

	public:

		struct Posicion{
			int x;
			int y;
		};
	
		
		
		
		

		/*
		 * Constructor por defecto
		 */
		Minimax();

		/*
		 * Constructor por par�metros.
		 * Utiliza SetTablero.
		 */
		Minimax(Tablero* _tablero);

		/*
		 * Iguala los punteros tablero
		 */
		void SetTablero(Tablero* _tablero);

		/*
		 * Lanza el algoritmo Minimax y retorna
		 * la posici�n mejor valorada.
		 * Parte de la situaci�n actual del tablero y
		 * empieza explorando todas las posibles tiradas de
		 * la IA tratando de maximizar su puntuaci�n (BuscaMax)
		 */
		Posicion AlgoritmoMinimax();

		/*
		 * Destructor. No hace nada.
		 * El puntero ya viene con memoria
		 * pedida. Se liberar� fuera.
		 */
		~Minimax();
};
