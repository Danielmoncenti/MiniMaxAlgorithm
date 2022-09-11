#pragma once

#include "Tablero.h"

class Minimax
{
	private:
		Tablero* tablero;
	
		/*
		 * Explora todas las posibles tiradas del jugador en
		 * las posiciones vacías.
		 * Para cada una de estas posibles tiradas, se llama al
		 * BuscaMax, que buscará la mejor tirada posible de la IA
		 * a partir de esa posición.
		 * De cada una de las tiradas posible, sube una puntuación desde
		 * BuscaMax. BuscaMin nos retorna la puntuación más baja (min)
		 * Los casos triviales son:
		 * - Que se haya llegado a la _profundidad indicada (la primera de
		 * las llamadas empieza con profundidad 0).
		 * - Que el tablero esté lleno
		 * - Que haya ganado o bien el jugador o bien la IA
		 * Al llegar al caso trivial, se retorna el resultado de la función
		 * ValoraJuego()
		 */
		int BuscaMin(int _profundidad); //jugador
		
		/*
		 * Explora todas las posibles tiradas de la IA en
		 * las posiciones vacías.
		 * Para cada una de estas posibles tiradas, se llama al
		 * BuscaMin, que buscará la mejor tirada posible del jugador
		 * a partir de esa posición.
		 * De cada una de las tiradas posible, sube una puntuación desde
		 * BuscaMin. BuscaMax nos retorna la puntuación más alta (max)
		 * Los casos triviales son:
		 * - Que se haya llegado a la _profundidad indicada (la primera de
		 * las llamadas empieza con profundidad 0).
		 * - Que el tablero esté lleno
		 * - Que haya ganado o bien el jugador o bien la IA
		 * Al llegar al caso trivial, se retorna el resultado de la función
		 * ValoraJuego()
		 */
		int BuscaMax(int _profundidad); //ia

		/*
		 * Retorna una valoración de la situación
		 * del tablero que se puede basar en:
		 * Puntuación = Evaluación(IA) - Evaluación(JUGADOR)
		 * Se debe usar la función evaluación ya implementada
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
		 * Constructor por parámetros.
		 * Utiliza SetTablero.
		 */
		Minimax(Tablero* _tablero);

		/*
		 * Iguala los punteros tablero
		 */
		void SetTablero(Tablero* _tablero);

		/*
		 * Lanza el algoritmo Minimax y retorna
		 * la posición mejor valorada.
		 * Parte de la situación actual del tablero y
		 * empieza explorando todas las posibles tiradas de
		 * la IA tratando de maximizar su puntuación (BuscaMax)
		 */
		Posicion AlgoritmoMinimax();

		/*
		 * Destructor. No hace nada.
		 * El puntero ya viene con memoria
		 * pedida. Se liberará fuera.
		 */
		~Minimax();
};
