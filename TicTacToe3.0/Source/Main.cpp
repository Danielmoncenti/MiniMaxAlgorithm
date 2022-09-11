#include <iostream>
#include "Tablero.h"
#include "Minimax.h"

int main() {
	int turnoA; //Para saber a quien le toca
	bool ok= false; //para saber si se ha equivocado en decir las posiciones donde tirar

	Tablero tablero;
	Minimax minimax(&tablero);
	if (tablero.PreguntarTurno() == 1) turnoA = 1;
	else turnoA = 2;

	if (tablero.tipo == 1) //jugador vs jugador
	{
		while (tablero.GetNumPosicionesOcupadas() < 9) {
	
			std::cout << tablero;

			int x, y;

			do {
				std::cout << "Turno jugador" << turnoA << ":\nIndica posicion X: ";
				std::cin >> x;
				std::cout << "Indica posicion Y: ";
				std::cin >> y;
				std::cout << std::endl;
			} while (!tablero.PonTirada(x, y, turnoA)); //intercambio x e y por como se pintan los arrays
					
			/*std::cout << "Posicion ocupada, vuelve a tirar por favor." << std::endl;
			system("pause");
			}*/
			
			if (turnoA == 1) turnoA = 2;
			else turnoA = 1;

			if (tablero.HayGanador() == Ficha::VACIO) {
				system("cls");
				std::cout << tablero;
			}
			else {
				break;
			}
			

		}
	}
	else // jugador versus IA
	{
		while (tablero.GetNumPosicionesOcupadas() < 9) {
			system("cls");
			std::cout << tablero;

			int y, x;

			do {
				if (turnoA == 1) {
					std::cout << "Turno jugador" << turnoA << ":\nIndica posicion X: ";
					std::cin >> x;
					std::cout << "Indica posicion Y: ";
					std::cin >> y;
					std::cout << std::endl;
				}
				else {
					Minimax::Posicion posicion = minimax.AlgoritmoMinimax();
					x = posicion.x;
					y = posicion.y;
				}
				
			} while (!tablero.PonTirada(x, y, turnoA)); //intercambio x e y por como se pintan los arrays
			if (turnoA == 1) turnoA = 2;
			else turnoA = 1;
			/*std::cout << "Posicion ocupada, vuelve a tirar por favor." << std::endl;
			system("pause");
			}*/

			

			if (tablero.HayGanador() == Ficha::VACIO) {
				
				std::cout << tablero;
			}
			else {
				break;
			}


		}

	}


	if (tablero.HayGanador() == Ficha::JUGADOR) {
	
		std::cout << "HA GANADO EL JUGADOR 1!" << std::endl;
		std::cout << tablero;
	}
	else if (tablero.HayGanador() == Ficha::IA) {
		
		std::cout << "HA GANADO EL JUGADOR 2!" << std::endl;
		std::cout << tablero;
	}

	system("pause");
	return 0;
}