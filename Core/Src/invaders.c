/*
 * invaders.c
 *
 *  Created on: Dec 18, 2023
 *      Author: ezema
 */


#include "invaders.h"

//Variables del jugador Player
player_t Player;
disparo_t Disparo;

//Variables de los aliens
movimiento_aliens_t movimiento_Aliens;
alien_t Alien[NUM_ALIEN_FILA][NUM_ALIEN_COLUMNA];


extern dificultad_t dificultad;



player_t *getPlayer(){

	return &Player;
}

alien_t *getAlien(uint8_t fila, uint8_t columna){
	return &Alien[fila][columna];
}

movimiento_aliens_t *getMovAliens(){
	return &movimiento_Aliens;
}

disparo_t *getDisparo(){
	return &Disparo;
}

void playerInit(){

	Player.posicion_X = 64;

}

void plotPlayer(uint8_t direccion, player_t *player){

	if(direccion == derecha){

		if(player->posicion_X >= 120){
			player->posicion_X = 120;
		}
		else{
			player->posicion_X = player->posicion_X + 4;
		}

	}
	else if(direccion == izquierda){

		if(player->posicion_X <= 0){
			player->posicion_X = 0;
		}
		else{
			player->posicion_X = player->posicion_X - 4;
		}
	}

	SSD1306_DrawBitmap(player->posicion_X, 56, nave, 8,8,1);
}



void InvaderInit(){

	movimiento_Aliens.orientacion = mov_derecha;

	for(uint8_t y=0; y<NUM_ALIEN_FILA ;y++){
		for(uint8_t x=0; x<NUM_ALIEN_COLUMNA; x++){
			getAlien(y,x)->posicion_X  =  OFFSET_INICIO + x*(TAMANO_ALIEN+ ESPACIO_ENTRE_COLUMNAS);
			getAlien(y,x)->posicion_Y = y*(TAMANO_ALIEN+ ESPACIO_ENTRE_FILAS);
			getAlien(y, x)->vivo = true;
			getAlien(y, x)->conteo_explosion = 2;
		}
	}

}

void plotAliens(){


	//Esta parte se encarga de ir moviendo los aliens de izquierda a derecha, derecha a izquierda.
	if(getMovAliens()->conteo_horizontal % dificultad.velocidad_horizontal == 0){
			switch(getMovAliens()->orientacion){
				case mov_derecha:

						for(uint8_t y=0; y<NUM_ALIEN_FILA ;y++){
							for(uint8_t x=0; x<NUM_ALIEN_COLUMNA; x++){
								getAlien(y,x)->posicion_X  = getAlien(y,x)->posicion_X + 1;


							}
						}

					break;

				case mov_izquierda:

						for(uint8_t y=0; y<NUM_ALIEN_FILA ;y++){
							for(uint8_t x=0; x<NUM_ALIEN_COLUMNA; x++){

								getAlien(y,x)->posicion_X  = getAlien(y,x)->posicion_X - 1;

							}
						}

						break;
				default:
					break;
		}


	//Aqui se cambia la orientacion de los aliens: cuando se llega al borde de la pantalla los aliens pasan a moverse hacia la derecha o hacia la izquierda.

			if( (getAlien(0,6)->posicion_X + TAMANO_ALIEN + 4) >= 127){

				getMovAliens()->orientacion = mov_izquierda;
			}
			if( (getAlien(0,0)->posicion_X) <= 0){
				getMovAliens()->orientacion = mov_derecha;
				getMovAliens()->conteo_bajada = getMovAliens()->conteo_bajada + 1;
			}



		//Esta parte se encarga de ir bajando los aliens.
			if(getMovAliens()->conteo_bajada == 10){
				for(uint8_t y=0; y<NUM_ALIEN_FILA ;y++){
					for(uint8_t x=0; x<NUM_ALIEN_COLUMNA; x++){

						getAlien(y,x)->posicion_Y  = getAlien(y,x)->posicion_Y + dificultad.velocidad_bajada;
						getMovAliens()->conteo_bajada = 0;

					}
				}
			}

	}

	getMovAliens()->conteo_horizontal = getMovAliens()->conteo_horizontal + 1;


	//Acá se grafican los aliens en la pantalla.
	//Se grafican los aliens que solo estan vivos.
		for(uint8_t y=0; y<NUM_ALIEN_FILA ;y++){
			for(uint8_t x=0; x<NUM_ALIEN_COLUMNA; x++){

					switch(y){

					case 0:
						if(getAlien(y,x)->vivo == true){
							SSD1306_DrawBitmap(getAlien(y,x)->posicion_X, getAlien(y,x)->posicion_Y,InvaderMiddleGfx,16,8,1);
						}
						break;
					case 1:
						if(getAlien(y,x)->vivo == true){
							SSD1306_DrawBitmap(getAlien(y,x)->posicion_X, getAlien(y,x)->posicion_Y,InvaderMiddleGfx,16,8,1);
						}
						break;
					default:
						if(getAlien(y,x)->vivo == true){
							SSD1306_DrawBitmap(getAlien(y,x)->posicion_X, getAlien(y,x)->posicion_Y,InvaderBottomGfx,16,8,1);
						}
						break;
					}
			}

		}

}


void disparoInit(){

	Disparo.posicion_x = 0;
	Disparo.posicion_y = POSICION_INICIAL_DISPARO;
	Disparo.disparo = false;
}


void disparar(){


			if(getDisparo()->numero_disparos == 1){
				getDisparo()->disparo = true;
				getDisparo()->posicion_x = getPlayer()->posicion_X;
			}


			if(getDisparo()->disparo == true){
				SSD1306_DrawLine(getDisparo()->posicion_x + 4, getDisparo()->posicion_y, getDisparo()->posicion_x + 4, getDisparo()->posicion_y + 3, 1);
				getDisparo()->posicion_y = getDisparo()->posicion_y - VELOCIDAD_DISPARO_PLAYER;


				if(getDisparo()->posicion_y <= 0){
					//Se reinician los valores del disparo
					getDisparo()->disparo = false;
					getDisparo()->posicion_y = POSICION_INICIAL_DISPARO;
					getDisparo()->numero_disparos = 0;
				}
			}


			//Eliminar los aliens si se produce un disparo. Se fija si el disparo se encuentra en el area comprendido por cada alien.
			for(uint8_t y=0; y<NUM_ALIEN_FILA ;y++){
				for(uint8_t x=0; x<NUM_ALIEN_COLUMNA; x++){

					if( (getDisparo()->posicion_x >= getAlien(y,x)->posicion_X) &&  (getDisparo()->posicion_x <= getAlien(y,x)->posicion_X + (TAMANO_ALIEN+ ESPACIO_ENTRE_COLUMNAS) )){
						if( (getDisparo()->posicion_y >= getAlien(y,x)->posicion_Y) && (getDisparo()->posicion_y <= getAlien(y,x)->posicion_Y + (TAMANO_ALIEN+ ESPACIO_ENTRE_FILAS)) ){

								if(getAlien(y,x)->vivo == true){
									getAlien(y,x)->vivo = false;
									getAlien(y,x)->explosion = true;

									//Se reinician los valores del disparo
									getDisparo()->disparo = false;
									getDisparo()->posicion_y = POSICION_INICIAL_DISPARO;
									getDisparo()->numero_disparos = 0;


								}
						}

					}

					//Se grafican las explosiones, como la pantalla se refresca muy rapido, las se utiliza una variable 'conteo_explosiones' para
					//que se grafique la explosion por mas tiempo y cuando conteo_explosiones = 0 ahi se deja de graficar las explosiones.
					//Tambien se definio una variable explosion, si es true se entra a este if y se decrementa conteo_explosiones.
					if(getAlien(y,x)->explosion == true){
						SSD1306_DrawBitmap(getAlien(y,x)->posicion_X, getAlien(y,x)->posicion_Y,explosion,16,8,1);
						getAlien(y,x)->conteo_explosion = getAlien(y,x)->conteo_explosion - 1;

						if(getAlien(y,x)->conteo_explosion == 0){
							getAlien(y,x)->explosion = false;
						}
					}
				}
			}
}














