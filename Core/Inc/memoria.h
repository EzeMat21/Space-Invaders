/*
 * memoria.h
 *
 *  Created on: Dec 29, 2023
 *      Author: ezema
 */

#ifndef INC_MEMORIA_H_
#define INC_MEMORIA_H_


#include "stdint.h"
#include "main.h"
#include "string.h"
#include <stdlib.h>
#include "cmsis_os.h"


#define true 1
#define false 0

typedef struct{

	char nombre[6];
	uint16_t puntaje;

}puntajes_t;

extern osMutexId_t mutexPuntajesHandle;
extern SPI_HandleTypeDef hspi1;

//opcodes
#define READ 	0b110
#define WRITE 	0b101
#define WEN 	0b10011000000000
#define WDS 	0b10000000000000
#define ERASE 	0b111
#define ERAL 	0b100
#define WRAL 	0b100


#define CHIP_SELECT_PIN GPIO_PIN_5
#define CHIP_SELECT_PORT GPIOB

#define MEMORIA_ADDRESS 0
#define TAMANO_PAGINA 64

#define MEMORIA_TAMANO_PUNTAJE 8	//6 bytes de nombre y 2 bytes de puntaje
#define TAMANO_TOTAL_PUNTAJES 40


puntajes_t *getPuntajes(uint8_t indice);
void Write_Enable();
void Write_Memoria(uint16_t address, uint8_t dato);
uint8_t Read_memoria(uint16_t address);
void Read_all(uint16_t address, uint16_t tamano, uint8_t *buffer);
void memoriaInit();


void Ordenamiento_Puntajes();
void guardarNuevosPuntaje();
void writeNuevosPuntajes(uint8_t cambios);


#endif /* INC_MEMORIA_H_ */
