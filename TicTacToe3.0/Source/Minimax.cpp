#include "Minimax.h"


Minimax::Minimax()
{
    
}

Minimax::Posicion Minimax::AlgoritmoMinimax()
{
    
    int mejorPuntuacion = INT32_MIN;
    Posicion mejorTirada;
    mejorTirada.x = 0;
    mejorTirada.y = 0;
   

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (tablero->GetFichaPosicion(i, j) == Ficha::VACIO) 
            {
                tablero->PonTirada(i, j, 2);
              int puntuacionActual = BuscaMax(0);
              tablero->QuitaTirada(i ,j);
                /*std::cout << i << " " << j <<" "<< puntuacionActual<< std::endl;*/
               
                
              
                if (mejorPuntuacion < puntuacionActual) {
                    mejorPuntuacion = puntuacionActual;
                    mejorTirada.x =i;
                    mejorTirada.y =j;
                }

                
                
            }
        }

    }
   

    return mejorTirada;
}

Minimax::~Minimax()
{
}

Minimax::Minimax(Tablero* _tablero)
{
    SetTablero(_tablero);
}

void Minimax::SetTablero(Tablero* _tablero)
{
    tablero = _tablero;
}


int Minimax::BuscaMin(int _profundidad)
{
    if (_profundidad >= PROFUNDIDAD) return ValoraJuego();
    else if (tablero->HayGanador() != Ficha::VACIO) return ValoraJuego();
    else if (tablero->GetNumPosicionesOcupadas() == 9) return ValoraJuego();
    int mejorPuntuacion = INT32_MIN;


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tablero->GetFichaPosicion(i, j) == Ficha::VACIO) {
                tablero->PonTirada(i, j, 2);
                //std::cout << *tablero;
                int puntuacionActual=Minimax::BuscaMax(++_profundidad);
                tablero->QuitaTirada(i, j);
                if (puntuacionActual > mejorPuntuacion) {
                    mejorPuntuacion = puntuacionActual;
                  
                }
            }
        }

    }
 
    return mejorPuntuacion;
}

int Minimax::BuscaMax(int _profundidad)
{  


    if (_profundidad >= PROFUNDIDAD) return ValoraJuego();
    else if (tablero->HayGanador() != Ficha::VACIO) return ValoraJuego();
    else if (tablero->GetNumPosicionesOcupadas() == 9) return ValoraJuego();

    int mejorPuntuacion = INT32_MAX;
   
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tablero->GetFichaPosicion(i,j) == Ficha::VACIO) {
                tablero->PonTirada(i, j, 1);
              //  std::cout << *tablero;
               
                int puntuacionActual = Minimax::BuscaMin(++_profundidad);
                
                tablero->QuitaTirada(i, j);
                if (puntuacionActual < mejorPuntuacion) {
                    mejorPuntuacion = puntuacionActual;
                  
                }
            }
        }
      
    }

    return mejorPuntuacion;
}

int Minimax::ValoraJuego()
{

    return tablero->Evaluacion(Ficha::IA) - tablero->Evaluacion(Ficha::JUGADOR);
}



