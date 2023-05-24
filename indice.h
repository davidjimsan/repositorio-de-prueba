//David Jiménez Sánchez 70837115-J grupo: PA2
#ifndef __INDICE_H
#define __INDICE_H
#include <stdio.h>
#include "secuencial.h"
typedef struct {
	char dni[9];
	int  NRR;
} tipoIndice;

// Funciones a entregar
int generaIndice(char *ficheroDatos, char *ficheroIndice);
int busquedaIndice(char *dni, char *fDatos, char *fIndice, tipoAlumno *alumno);

#endif
