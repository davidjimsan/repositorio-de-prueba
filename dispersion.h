//David Jiménez Sánchez 70837115-J grupo: PA2
#include <stdio.h>
#include "secuencial.h"
#define C 5	                // capacidad del cubo
#define CUBOS 20           // Número de cubos en el area prima
#define CUBOSDESBORDE  4   // Número de cubos area de desborde

/*#ifndef __SECUENCIAL_H
typedef struct {
	char dni[9];
	char nombre[19];
	char ape1[19];
	char ape2[19];
	char provincia[11];
	} tipoAlumno;
#endif*/

typedef struct {
	tipoAlumno reg[C];
	int cuboDES;      // De momento no la vamos a utilizar
	int numRegAsignados;
	}tipoCubo;

// funciones proporcionadas
void creaHvacio(char *fichHash);
int leeHash(char *fichHash);
// funciones a codificar
int creaHash(char *fichEntrada,char *fichHash);
//int buscaReg(FILE *fHash, tipoAlumno *reg,char *dni);
int insertaRegistros(FILE *f, tipoAlumno *reg);
void incrementarDesborde(int hasta, FILE* f);
int fHash(char *cad);
//*************************************************
tipoAlumno *busquedaHash (FILE *f, char *dni, int *nCubo, int *ncuboDes, int *posReg, int *error);
int modificarReg (char *fichero, char *dni, char *provincia);



