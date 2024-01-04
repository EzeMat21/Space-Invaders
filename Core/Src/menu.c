/*
 * menu.c
 *
 *  Created on: Dec 26, 2023
 *      Author: ezema
 */


#include "menu.h"


extern osEventFlagsId_t notificationFlag;
extern osEventFlagsId_t notificationFlag2;

menu_t menu;

menu_t *getMenu(){

	return &menu;
}


void menuInit(){

	//Inicializacion de la pantalla.
	SSD1306_Init ();
	SSD1306_Clear();
	SSD1306_UpdateScreen();

	//Se inicializan las posiciones iniciales del player y de los aliens.
	playerInit();
	InvaderInit();
	disparoInit();

	//Se inicializa el cursor de la pantalla principal.
	//getMenu()->menuActual = guardar_nombre;
	getMenu()->menuActual = menu_principal;
	getMenu()->posicion_MenuPrincipal = POSICION_CURSOR_JUGAR;


	//Se inicializa el cursor de la pantalla Guardado de nombre
	getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X_INICIAL;
	getMenu()->GuardarNombre.posicion_y = GUARDADO_POSICION_Y1;
	getMenu()->GuardarNombre.indice = 0;

}

void menuActualizar(uint8_t x, uint8_t y, uint8_t boton){


	switch(getMenu()->menuActual){

//--------------------------------------------------------------MENU PRINCIPAL-----------------------------------------------------------------------------
	case menu_principal:

		SSD1306_DrawBitmap(35, 0, SpaceInvaders, 64, 32, 1);

		SSD1306_GotoXY(45, 35);
		SSD1306_Puts("JUGAR", &Font_7x10, 1);
		SSD1306_GotoXY(45, 45);
		SSD1306_Puts("PUNTAJES", &Font_7x10, 1);


		if(y == arriba){
			getMenu()->posicion_MenuPrincipal = POSICION_CURSOR_JUGAR;
		}
		else if(y == abajo){
			getMenu()->posicion_MenuPrincipal = POSICION_CURSOR_PUNTAJES;
		}

		SSD1306_DrawCircle(POSICION_CURSOR_X, getMenu()->posicion_MenuPrincipal, 3, 1);


		switch(boton){
		case true:
			if(getMenu()->posicion_MenuPrincipal == POSICION_CURSOR_JUGAR){
				getMenu()->menuActual = juego;
			}
			else if(getMenu()->posicion_MenuPrincipal == POSICION_CURSOR_PUNTAJES){
				getMenu()->menuActual = puntajes;
			}
			break;
		case false:
			break;
		default:
			break;
		}

		break;

//--------------------------------------------------------------  JUEGO -----------------------------------------------------------------------------

	case juego:

		//Se grafican el player, aliens y disparo.
		plotPlayer(x, getPlayer());
		plotAliens();

		disparar();


		//Prender led si se apretó el boton
		if(boton == true){

			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
			//boton_apretado = 1;
			getDisparo()->numero_disparos = getDisparo()->numero_disparos + 1;
		}
		else{
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
		}

		break;

//-------------------------------------------------------------- PUNTAJES-----------------------------------------------------------------------------
	case puntajes:

		//Titulo 'Puntajes'
		SSD1306_GotoXY(35, 0);
		SSD1306_Puts("PUNTAJES", &Font_7x10, 1);

		uint8_t posicion;
		uint8_t buffer[2];

		//	EN PRINICIPIO, EL PUNTERO A LA STRUCT getPuntajes() SOLO SERÁ LEIDO POR LA TAREA MENU/PANTALLA.
		//	TODAS AQUELLAS ESCRITURAS DE LA VARIABLE SE REALIZARÁN EN LA TAREA MEMORIA. POR TANTO NO SERÁ NECESARIO UTILIZAR
		// 	UN MUTEX.

		//char buff_retorno[5][6];

		//Nombres

		for(uint8_t j=0; j<5;j++){

			posicion = j*10 + 13;

			SSD1306_GotoXY(15, posicion);
			//strcpy(buff_retorno[j], "jdsa");
			SSD1306_Puts(getPuntajes(j)->nombre, &Font_7x10, 1);
		}


		//Puntuaciones
		for(uint8_t j=0; j<5;j++){

			posicion = j*10 + 13;

			SSD1306_GotoXY(90, posicion);
			itoa(getPuntajes(j)->puntaje,(char*)buffer,10);
			SSD1306_Puts((char *)buffer, &Font_7x10, 1);
		}


		switch(y){
		case arriba:
				getMenu()->menuActual = menu_principal;
			break;
		default:
			break;
		}
		break;


//-------------------------------------------------------------- GUARDADO DEL NOMBRE-----------------------------------------------------------------------------
	case guardar_nombre:

		char buff_qwerty[] = "qwertyuiop";
		char buff_asdf[] = "asdfghjkl@";
		char buff_zxc[] = "zxcvbnm";
		char enter = '<';
		char borrar = 'x';

		uint8_t posicion_x;

		SSD1306_DrawRectangle(30, 0, 60, 15, 1);
		//SSD1306_GotoXY(43, 5);
		//SSD1306_Puts("capaz", &Font_7x10, 1);


			for(uint8_t i=0;i<10;i++){

				posicion_x = i*(12) + 6;

				SSD1306_GotoXY(posicion_x, 23);
				SSD1306_Putc(buff_qwerty[i], &Font_7x10, 1);
				SSD1306_GotoXY(posicion_x, 38);
				SSD1306_Putc(buff_asdf[i], &Font_7x10, 1);

			}


			for(uint8_t i=0;i<7;i++){

				posicion_x = i*(12) + 26;

				SSD1306_GotoXY(posicion_x, 53);
				SSD1306_Putc(buff_zxc[i], &Font_7x10, 1);
			}

			//BOTON BORRAR
			SSD1306_DrawRectangle(3, 50, 16, 16, 1);
			SSD1306_GotoXY(8, 53);
			SSD1306_Putc(borrar, &Font_7x10, 1);

			//BOTON ENTER
			SSD1306_DrawRectangle(108, 50, 16, 16, 1);
			SSD1306_GotoXY(113, 53);
			SSD1306_Putc(enter, &Font_7x10, 1);


			//Esto es algo "raro" que hice. En lugar de procesar el eje x y el eje y del joystick a la vez, voy a definir una variable mov
			//la cual solo puede tomar el valor de x o el valor de y, es decir, tomara los valores de (arriba, abajo, der,izq, nulo)

			uint8_t mov;
			switch(y){

				case arriba:
					mov = arriba;
					break;
				case abajo:
					mov = abajo;
					break;
				case nulo:
					mov = x;
					break;

			}

			int8_t div;


			TickType_t Timenow;
			Timenow = xTaskGetTickCount();

			//Este if es para generar un retraso al mover el cursor en el eje x como en el ya que sino se mueve demasiado rapido.
			if((Timenow - getMenu()->GuardarNombre.xLastWakeTime_y) > pdMS_TO_TICKS(150) && (y!=nulo)){

				getMenu()->GuardarNombre.xLastWakeTime_y = xTaskGetTickCount();

			switch(mov){
				case arriba:

					switch(getMenu()->GuardarNombre.posicion_y){
						case GUARDADO_POSICION_Y2:
							getMenu()->GuardarNombre.posicion_y = GUARDADO_POSICION_Y1;
							break;

						case GUARDADO_POSICION_Y3:

							getMenu()->GuardarNombre.posicion_y = GUARDADO_POSICION_Y2;

							if(getMenu()->GuardarNombre.posicion_x >= GUARDADO_POSICION_X3_INICIAL ){

								div = getMenu()->GuardarNombre.posicion_x - (GUARDADO_POSICION_X3_INICIAL);

								if(div < 0) getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X_INICIAL;

								else{

									div = div / GUARDADO_OFFSET_X_CURSOR;

									 getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X_INICIAL + (div+1)*GUARDADO_OFFSET_X_CURSOR ;
									}
								}
							else{
								getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X_INICIAL;
							}

							break;

					}

					break;

				case abajo:

					switch(getMenu()->GuardarNombre.posicion_y){
						case GUARDADO_POSICION_Y1:
							getMenu()->GuardarNombre.posicion_y = GUARDADO_POSICION_Y2;
							break;

						case GUARDADO_POSICION_Y2:
							getMenu()->GuardarNombre.posicion_y = GUARDADO_POSICION_Y3;

							div = getMenu()->GuardarNombre.posicion_x - (GUARDADO_POSICION_X_INICIAL);
							div = div/GUARDADO_OFFSET_X_CURSOR;

							if(div == 0){
								getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X_BORRAR;
							}
							else if(div == 8 || div == 9){
								getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X_ENTER;
							}
							else{
								getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X3_INICIAL + (div-1)*GUARDADO_OFFSET_X_CURSOR;
							}

							break;

						default:
							break;
						}

					break;
				default:
					break;
				}

			}

			Timenow = xTaskGetTickCount();

			//Este if es para generar un retraso al mover el cursor en el eje x como en el ya que sino se mueve demasiado rapido.
		if((Timenow - getMenu()->GuardarNombre.xLastWakeTime_x) > pdMS_TO_TICKS(100) && (x!=nulo) ){

			getMenu()->GuardarNombre.xLastWakeTime_x= xTaskGetTickCount();

			switch(mov){
				case izquierda:

					getMenu()->GuardarNombre.posicion_x = getMenu()->GuardarNombre.posicion_x - GUARDADO_OFFSET_X_CURSOR;

					if(getMenu()->GuardarNombre.posicion_y != GUARDADO_POSICION_Y3){

						if(getMenu()->GuardarNombre.posicion_x == (uint8_t)(GUARDADO_POSICION_X_INICIAL - GUARDADO_OFFSET_X_CURSOR)){
							getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X_FINAL;
						}
					}
					else{
						if(getMenu()->GuardarNombre.posicion_x == (uint8_t)(GUARDADO_POSICION_X3_INICIAL - GUARDADO_OFFSET_X_CURSOR) ){

							getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X_BORRAR;
						}
						else if(getMenu()->GuardarNombre.posicion_x == (uint8_t)(GUARDADO_POSICION_X_ENTER - GUARDADO_OFFSET_X_CURSOR)){

							getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X3_FINAL;
						}

						else if(getMenu()->GuardarNombre.posicion_x == (uint8_t)(GUARDADO_POSICION_X_BORRAR - GUARDADO_OFFSET_X_CURSOR)){

							getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X_BORRAR;
						}
					}

					break;
				case derecha:

					getMenu()->GuardarNombre.posicion_x = getMenu()->GuardarNombre.posicion_x + GUARDADO_OFFSET_X_CURSOR;

					if(getMenu()->GuardarNombre.posicion_y != GUARDADO_POSICION_Y3){

						if(getMenu()->GuardarNombre.posicion_x > GUARDADO_POSICION_X_FINAL){
								getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X_INICIAL;
						}
					}
					else{

						if(getMenu()->GuardarNombre.posicion_x == (uint8_t)(GUARDADO_POSICION_X3_FINAL + GUARDADO_OFFSET_X_CURSOR)){
							getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X_ENTER;
						}
						else if(getMenu()->GuardarNombre.posicion_x == (uint8_t)(GUARDADO_POSICION_X_ENTER + GUARDADO_OFFSET_X_CURSOR)){
							getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X_BORRAR;
						}
						else if(getMenu()->GuardarNombre.posicion_x == (uint8_t)(GUARDADO_POSICION_X_BORRAR + GUARDADO_OFFSET_X_CURSOR)){
							getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X3_INICIAL;
						}
					}

					break;
				default:
					break;
				}

		}


			Timenow = xTaskGetTickCount();

			//Este if es para generar un retraso al mover el cursor en el eje x como en el ya que sino se mueve demasiado rapido.
		if((Timenow - getMenu()->GuardarNombre.xLastWakeTime_boton) > pdMS_TO_TICKS(100) && (boton !=false) ){

			getMenu()->GuardarNombre.xLastWakeTime_boton= xTaskGetTickCount();


			//uint8_t indice_debug;
			//uint8_t buffer_debug[6];


			if((boton == true) && (getMenu()->GuardarNombre.indice <= 5)){

						if((getMenu()->GuardarNombre.posicion_y != GUARDADO_POSICION_Y3)){

							div = getMenu()->GuardarNombre.posicion_x - GUARDADO_POSICION_X_INICIAL;
							div = div / (GUARDADO_OFFSET_X_CURSOR);

							if((getMenu()->GuardarNombre.posicion_y == GUARDADO_POSICION_Y1)){
								getMenu()->GuardarNombre.nombre[getMenu()->GuardarNombre.indice] = buff_qwerty[div];
								getMenu()->GuardarNombre.indice = getMenu()->GuardarNombre.indice + 1;

							}
							else if((getMenu()->GuardarNombre.posicion_y == GUARDADO_POSICION_Y2)){
								getMenu()->GuardarNombre.nombre[getMenu()->GuardarNombre.indice] = buff_asdf[div];
								getMenu()->GuardarNombre.indice = getMenu()->GuardarNombre.indice + 1;
							}

						}


						else{

							div = getMenu()->GuardarNombre.posicion_x - GUARDADO_POSICION_X3_INICIAL;

							if(div < 0){	//SI SE APRIETA EL BOTON BORRAR


								//indice_debug = getMenu()->GuardarNombre.indice;
								//strcpy(buffer_debug,getMenu()->GuardarNombre.nombre );

								getMenu()->GuardarNombre.indice = getMenu()->GuardarNombre.indice - 1;
								if(getMenu()->GuardarNombre.indice < 0){
										getMenu()->GuardarNombre.indice = 0;
									}

								getMenu()->GuardarNombre.nombre[getMenu()->GuardarNombre.indice] = '\0';

								//indice_debug = getMenu()->GuardarNombre.indice;
								//strcpy(buffer_debug,getMenu()->GuardarNombre.nombre );

							}
							else{
								div = div / GUARDADO_OFFSET_X_CURSOR;

								//indice_debug = getMenu()->GuardarNombre.indice;

									if(div == 7){	//SI SE APRIETA EL BOTON ENTER

										if((getMenu()->GuardarNombre.indice != 0 )){


											//Guardo el nuevo nombre en la posicion 5 de getPuntajes()->nombre.
											strcpy(getPuntajes(4)->nombre,getMenu()->GuardarNombre.nombre);


										    // Notifica a la tarea Task2 utilizando VTaskNotify
										    osEventFlagsSet(notificationFlag, NOTIFICATION_VALUE);

										    uint32_t flags = osEventFlagsWait(notificationFlag2, NOTIFICATION_VALUE2, osFlagsWaitAny, osWaitForever);

										    if (flags == NOTIFICATION_VALUE2){
										    	getMenu()->menuActual = puntajes;
										    }



										}
									}
									else{

										getMenu()->GuardarNombre.nombre[getMenu()->GuardarNombre.indice] = buff_zxc[div];
										getMenu()->GuardarNombre.indice = getMenu()->GuardarNombre.indice + 1;

										//indice_debug = getMenu()->GuardarNombre.indice;

									}

								}


							}

						if(getMenu()->GuardarNombre.indice > 5){
							getMenu()->GuardarNombre.indice = 5;
							getMenu()->GuardarNombre.nombre[5] = '\0';
						}

				}


		}




				//Se actualiza el cursor
				SSD1306_DrawFilledCircle(getMenu()->GuardarNombre.posicion_x,  getMenu()->GuardarNombre.posicion_y, 5, 1);

				//Se actualiza el nombre en el recuadro.
				SSD1306_GotoXY(43, 5);
				SSD1306_Puts(getMenu()->GuardarNombre.nombre, &Font_7x10, 1);


		break;


//-------------------------------------------------------------- GAME OVER -----------------------------------------------------------------------------
	case game_over:

		//SSD1306_GotoXY(35, 25);
		//SSD1306_Puts("GAME OVER", &Font_7x10, 1);

		SSD1306_DrawBitmap(15, 10, game_over_figura, 100, 40, 1);

		if(y == arriba){

			getMenu()->menuActual = guardar_nombre;

		}

		break;
	default:
		break;
	}

}


void menuGuardaNombre_Reset(){

	getMenu()->GuardarNombre.posicion_x = GUARDADO_POSICION_X3_INICIAL;
	getMenu()->GuardarNombre.posicion_y = GUARDADO_POSICION_Y3;
	getMenu()->GuardarNombre.indice = 0;

}











