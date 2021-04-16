#include "Fruta.h"
#include <iostream>

using namespace std;

Fruta::Fruta(SDL_Renderer* _renderer, SDL_Texture* _frutasTextures, int _posicionX, int _posicionY,
	int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) :
	GameObject(_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla), renderer(_renderer){
	// Inicializa propiedade de la fruta

	visible = false;

	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
	//renderer = _renderer;
	frutasTextures= _frutasTextures;
}


void Fruta::mostrar()
{
	if (contadorTiempoVisible >= tiempoVisible) {
		visible = false;
		if (contadorTiempoNoVisible >= tiempoNoVisible) {
			posicionX = 1 + rand() % anchoPantalla;
			posicionY = 1 + rand() % altoPantalla;
			contadorTiempoVisible = 0;
			contadorTiempoNoVisible = 0;
			visible = true;
		}
		else {
			contadorTiempoNoVisible++;
			//contadorTiempoNoVisible = contadorTiempoNoVisible + 1;
		}
	}
	else {
		contadorTiempoVisible++;
	}
}

void Fruta::render()
{
	if (visible) {
		
		SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };
		SDL_RenderCopyEx(renderer, frutasTextures, nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
	}
}