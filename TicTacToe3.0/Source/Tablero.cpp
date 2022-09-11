#include "Tablero.h"

Tablero::Tablero()
{
	for (size_t i = 0; i < MAX; i++) {
		for (size_t j = 0; j < MAX; j++)
		{
			tablero[i][j] = Ficha::VACIO;
		}
	}
}

Ficha Tablero::HayGanador()
{
	//Primera Diagonal
	if (tablero[0][0] != Ficha::VACIO
		&& tablero[0][0] == tablero[1][1]
		&& tablero[1][1] == tablero[2][2]) 
	{
		return tablero[0][0];
	}

	//Segunda Diagonal
	if (tablero[0][2] != Ficha::VACIO
		&& tablero[0][2] == tablero[1][1]
		&& tablero[1][1] == tablero[2][0])
	{
		return tablero[0][2];
	}

	//Horizontales y Verticales
	for (int i = 0; i < MAX; i++) {
		if (tablero[i][0] != Ficha::VACIO && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) 
		{
			return tablero[i][0];
		}
		if (tablero[0][i] != Ficha::VACIO && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) 
		{
			return tablero[0][i];
		}
	}

	return Ficha::VACIO;

}

Ficha Tablero::GetFichaPosicion(int _x, int _y)
{
	return tablero[_x][_y];
}

int Tablero::GetNumPosicionesOcupadas()
{
	int pos = 0;
	for (size_t i = 0; i < MAX; i++)
	{
		for (size_t j = 0; j < MAX; j++)
		{
			if (tablero[i][j] != Ficha::VACIO) pos++;
		}
	}
	return pos;
}

bool Tablero::PonTirada(int _x, int _y, int _ficha /*Ficha _ficha*/)
{
	if (tablero[_x][_y] != Ficha::VACIO) { return false; }
	else {
		if (_ficha == 1) {
			tablero[_x][_y] = Ficha::JUGADOR;
			return true;
		}
		else {
			tablero[_x][_y] = Ficha::IA;
			return true;
		}
	}
}

void Tablero::QuitaTirada(int _x, int _y)
{
	tablero[_x][_y] = Ficha::VACIO;
}

int Tablero::Evaluacion(Ficha _jugador)
{
	int Return = 0;

	if (HayGanador() == _jugador) { Return =  1000; }

	//Horizontales y Verticales
	for (int i = 0; i < MAX; i++) {
		if (tablero[i][0] == Ficha::VACIO && tablero[i][1] == _jugador && tablero[i][2] == _jugador) Return = 100;
		
		else if (tablero[i][0]==_jugador && tablero[i][1]==_jugador && tablero[i][2] == Ficha::VACIO) Return = 100;
		
		else if (tablero[i][0] ==_jugador&& tablero[i][2]==_jugador && tablero[i][1] == Ficha::VACIO) Return = 100;
		

		if (tablero[0][i] == Ficha::VACIO && tablero[1][i] ==_jugador && tablero[2][i]==_jugador) Return = 100;
	
		else if (tablero[0][i] ==_jugador&& tablero[1][i]==_jugador && tablero[2][i] == Ficha::VACIO) Return = 100;
		
		else if (tablero[0][i] ==_jugador&& tablero[2][i]==_jugador && tablero[1][i] == Ficha::VACIO) Return = 100;
	}

	//Diagonales
	//Izquierdas
	if (tablero[0][0] == Ficha::VACIO && tablero[1][1] ==_jugador && tablero[2][2]==_jugador) Return = 100;

	else if (tablero[1][1] == Ficha::VACIO && tablero[0][0] ==_jugador && tablero[2][2]==_jugador) Return = 100;
	
	else if (tablero[2][2] == Ficha::VACIO && tablero[0][0] ==_jugador&& tablero[1][1]==_jugador) Return = 100;
	

	//Derechas
	if (tablero[0][2] == Ficha::VACIO && tablero[1][1] ==_jugador && tablero[2][0]==_jugador) Return = 100;
	
	else if (tablero[1][1] == Ficha::VACIO && tablero[0][2] ==_jugador && tablero[2][0]==_jugador) Return = 100;

	else if (tablero[2][0] == Ficha::VACIO && tablero[0][2] ==_jugador && tablero[1][1]==_jugador) Return = 100;

	return Return;
}

int Tablero::PreguntarTurno()
{
	int quienempieza;
	system("cls");
	std::cout << "Tipo de juego" << std::endl;
	std::cout << "1.- Jugador vs Jugador\n2.- Jugador vs IA\n";
	std::cin >> tipo;
	if (tipo == 1)
	{
		std::cout << "Quien tira primero?\n1.- Jugador 1\n2.- Jugador 2\n";
		std::cin >> quienempieza;
		return quienempieza;
	}
	else if (tipo == 2) 
	{
		std::cout << "Quien tira primero?\n1.- Jugador\n2.- IA\n";
		std::cin >> quienempieza;
		return quienempieza;
	}
	
	return 0;
	
}


	


std::ostream& operator<<(std::ostream& _os, Tablero _tablero)
{
	for (size_t i = 0; i < MAX; i++)
	{
		for (size_t j = 0; j < MAX; j++)
		{
			_os << (char)_tablero.tablero[j][i];
		}
		_os << "\n";
	}
	return _os;

}
