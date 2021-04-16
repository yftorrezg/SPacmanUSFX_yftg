#include "Fantasma.h"
#include <iostream>

using namespace std;

Fantasma::Fantasma(SDL_Renderer* _renderer, SDL_Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron):
	GameObject(_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	// Inicializa propiedade de de pacman
	velocidadX = 3;
	velocidadY = 3;
	velocidadPatron = _velocidadPatron;
	tope = rand() % 2;
	renderer = _renderer;
	fantasmaTexture = _fantasmaTexture;
}

void Fantasma::move()
{
	//si es x==0 va hacia arriba y abajo
	if (tope == 0) {
		// Mover el fantasma a la izquierda o derecha
		posicionX += velocidadX;

		// Verificar si la posicion del fantasma no salio de los bordes izquierdo o derecho
		if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
		{
			// Mover fantasma atras
			posicionX -= velocidadX;
			velocidadX *= -1;
			if (posicionX >= anchoPantalla - 30) {
				tope = rand() % 2;
			}
			if (posicionX < 20) {
				tope = rand() % 2;
			}
		}

	}
	// Mover el fantasma arriba o abajo
	if (tope == 1) {
		posicionY += velocidadY;

		// Verificar si la posicion del fantasma no salio de los bordes superior e inferior
		if ((posicionY < 0) || (posicionY + alto > altoPantalla))
		{
			// Mover fantasma atras
			posicionY -= velocidadY;
			velocidadY *= -1;
			if (posicionX >= altoPantalla - 30) {
				tope = rand() % 2;
			}
			if (posicionY < 20) {
				tope = rand() % 2;
			}

		}
	}
}

void Fantasma::render()
{
	SDL_Rect renderQuad = { getPosicionX(), getPosicionY(), getAncho(), getAlto() };

	//Render to screen
	SDL_RenderCopyEx(renderer, fantasmaTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}
