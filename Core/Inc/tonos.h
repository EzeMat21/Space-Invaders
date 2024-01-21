/*
 * tonos.h
 *
 *  Created on: Jan 21, 2024
 *      Author: ezema
 */

#ifndef INC_TONOS_H_
#define INC_TONOS_H_


#define VECES_622HZ 170
#define VECES_587HZ 160
#define VECES_554HZ 150
#define VECES_TONOS_VARIABLES 10


typedef enum{
	f622,
	f587,
	f554,
	variables
}tonos_t ;

uint8_t tonos_variables[] = {

	127,177,219,246,254,242,211,167,117,68,29,5,1,17,51,97,148,195,232,252,251,231,195,147,96,50,17,1,5,29,68,117,168,212,242,254,246,
	218,176,126,77,127,177,219,246,254,241,211,166,116,67,28,5,1,18,52,98,149,197,233,252,251,230,193,145,94,48,16,1,6,31,71,120,171,214
	,243,254,244,216,173,122,73,127,177,219,246,254,241,210,166,115,66,27,4,1,18,53,100,151,198,234,252,250,229,191,142,92,46,14,0,7,33,74
	,124,174,216,245,254,243,213,169,119,69,127,177,219,246,254,241,210,165,114,65,27,4,1,19,54,101,152,199,235,252,250,228,189,140,89,45,
	13,0,8,35,77,127,177,219,246,254,241,210,165,115,66,127,177,219,246,254,241,209,164,113,65,26,4,2,20,55,103,154,201,236,253,249,226,187,
	138,87,43,12,0,9,37,79,130,180,221,247,254,240,207,162,111,62,127,177,219,246,254,241,209,164,113,64,25,4,2,21,57,104,155,202,237,253,249
	,225,185,136,85,41,11,0,10,39,82,133,183,223,248,253,238,204,158,107,59,127,177,219,246,254,240,208,163,112,63,25,3,2,21,58,106,157,203,
	237,253,248,224,183,133,82,39,10,0,11,41,85,136,185,225,249,253,236,201,155,103,56,127,177,220,246,254,240,208,162,111,62,24,3,2,22,59,107
	,159,205,238,253,248,222,181,131,80,37,9,0,12,43,88,139,188,227,250,252,234,198,151,99,52,127,178,220,247,254,240,207,162,110,62,24,3,2,23
	,60,109,160,206,239,254,247,221,179,129,78,35,8,0,13,45,91,142,191,229,251,252,232,195,147,96,49,127,178,220,247,254,240,207,161,110,61,23
	,3,3,23,61,110,162,207,240,254,246,219,177,126,76,34,7,0,15,47,93,145,194,231,252,251,230,192,143,92,46,127,178,220,247,254,239,207,160,109,
	60,23,2,3,24,63,112,163,209,241,254,246,218,175,124,74,32,6,1,16,50,96,148,196,233,252,250,228,189,140,88,43,127,178,220,247,254,239,206,160,
	108,59,22,2,3,25,64,113,165,210,242,254,245,217,173,122,71,30,5,1,17,52,99,151,199,235,253,249,226,186,136,84,40,127,178,220,247,254,239,206,
	159,107,59,21,2,4,26,65,115,166,211,242,254,244,215,171,120,69,29,5,1,19,54,102,154,202,237,253,249,224,182,132,81,37,127,178,220,247,254,
	239,205,158,106,58,21,2,4,27,66,116,168,213,243,254,244,214,169,117,67,27,4,2,20,57,105,157,204,238,253,247,221,179,128,77,34,127,178,221,
	247,254,239,205,158,106,57,20,2,4,27,67,118,169,214,244,254,243,212,167,115,65,26,3,2,22,59,108,160,207,240,254,246,219,176,124,74,32,127,
	178,221,247,254,238,204,157,105,56,20,1,4,28,69,119,171,215,244,254,242,210,165,113,63,24,3,3,23,62,111,163,209,241,254,245,216,172,121,70,
	29,127,178,221,247,253,238,204,156,104,56,19,1,5,29,70,121,172,216,245,254,241,209,163,110,61,23,2,3,25,64,114,166,212,243,254,244,214,169,
	117,67,27,127,178,221,247,253,238,203,156,103,55,19,1,5,30,71,122,174,218,246,254,240,207,161,108,59,21,2,4,27,67,117,169,214,244,254,242,
	211,165,113,63,24,127,178,221,248,253,238,203,155,102,54,18,1,5,31,72,124,175,219,246,254,239,206,158,106,57,20,1,4,28,69,120,172,216,245
	,254,241,208,162,109,60,22,127,179,221,248,253,237,202,154,102,53,18,1,6,31,74,125,177,220,247,254,238,204,156,104,55,19,1,5,30,72,123,175
	,218,246,254,239,205,158,106,57,20,127,179,221,248,253,237,202,154,101,53,17,1,6,32,75,127,178,221,248,253,237,202,154,101,53,17,1,6,32,74
	,126,178,221,247,253,238,203,155,102,53,18

};

uint8_t tono_622hz[] = {

		127, 187, 232, 253, 245, 209, 154, 92, 39, 6, 2, 27, 75, 136

};

uint8_t tono_587hz[] = {

		127, 183, 228, 252, 249, 221, 174, 116, 61, 20, 1, 8, 40, 91, 149

};

uint8_t tono_554hz[] = {

		127, 181, 224, 250, 252, 231, 191, 139, 85, 38, 8, 0, 16, 53, 103, 158

};



#endif /* INC_TONOS_H_ */