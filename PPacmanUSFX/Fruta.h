#pragma once
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include "GameObject.h"

class Fruta: public GameObject
{
private:
	/*TIPO_FRUTA tipoFruta;*/
	int frutitas;
	int tiempoVisible;
	int tiempoNoVisible;

	int contadorTiempoVisible;
	int contadorTiempoNoVisible;

public:
	// Renderizador de la ventana
	SDL_Renderer* renderer = nullptr;

	// Array de las texturas de las diferentes frutas;
	SDL_Texture* frutasTextures;


public:
	//Constructores y destructores
	Fruta(SDL_Renderer* _renderer, SDL_Texture* _frutasTextures, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
	//~Fruta();

	//Metodos accesores
	int getTiempoVisible() { return tiempoVisible; }
	int getTiempoNoVisible() { return tiempoNoVisible; }
	int getfrutitas() { return frutitas; }
	/*void setTipoFruta(TIPO_FRUTA _tipoFruta) { tipoFruta = _tipoFruta; }*/
	void setTiempoVisble(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }
	void setTiempoNoVisble(int _tiempoNoVisible) { tiempoNoVisible = _tiempoNoVisible; }
	void setfrutitas(int _frutaImagenes) { frutitas= _frutaImagenes; }
	// Metodos varios

	// Manejador de eventos de la fruta
	//void handleEvent(SDL_Event& e);

	// Mostrar u ocultar fruta
	void mostrar();
	// Renderizar imagen fruta
	void render();

};

