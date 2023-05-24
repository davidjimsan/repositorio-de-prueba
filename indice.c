//David Jiménez Sánchez 70837115-J grupo: PA2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "indice.h"
//#include "secuencial.h"

int generaIndice(char *ficheroDatos, char *ficheroIndice)
{
	FILE *datos, *indice;
	tipoAlumno *alumno;
	tipoIndice indx;
	int i=0;
	
	if ((datos=fopen(ficheroDatos, "rb"))==NULL){
		return -2;
	}	
	if ((indice=fopen(ficheroIndice, "wb"))==NULL){
		return -3;
	}	
	
	if ((alumno=(tipoAlumno *) malloc(sizeof(tipoAlumno)))==NULL){
		printf("error reserva");	
		return -4;
	}
	/*if ((indx=(tipoIndice *) malloc(sizeof(tipoIndice)))==NULL){
		printf("error reserva");	
		return -4;
	}*/
	
	while (!feof(datos)){
		if (fread(alumno, sizeof(tipoAlumno), 1, datos)>0){
			strcpy(indx.dni, alumno->dni);
			indx.NRR=i;
			fwrite(&indx, sizeof(indx), 1, indice);
			i++;
		}
	}
	fclose (indice);
	fclose (datos);
	return i;
	
}

int busquedaIndice(char *dni, char *fDatos, char *fIndice, tipoAlumno *alumno)
{
	int NRR=-1;
	tipoIndice *indx;
	tipoAlumno *alum;
	FILE *datos, *indice;
	
	if ((datos=fopen(fDatos, "rb"))==NULL){
		return -2;
	}	
	if ((indice=fopen(fIndice, "rb"))==NULL){
		return -3;
	}
	if ((alum=(tipoAlumno *) malloc(sizeof(tipoAlumno)))==NULL){
		printf("error reserva");	
		return -4;
	}
	if ((indx=(tipoIndice *) malloc(sizeof(tipoIndice)))==NULL){
		printf("error reserva");	
		return -4;
	}
	
	while (!feof(indice)){
		if (fread(indx, sizeof(tipoIndice), 1, indice)>0){
			if (strcmp(indx->dni, dni)==0){
				NRR=indx->NRR;
				fseek(datos, NRR*sizeof(tipoAlumno), SEEK_SET);
				fread(alum, sizeof(tipoAlumno), 1, datos);
				strcpy(alumno->dni, alum->dni);
				strcpy(alumno->nombre, alum->nombre);
				strcpy(alumno->ape1, alum->ape1);
				strcpy(alumno->provincia, alum->provincia);
				strcpy(alumno->ape2, alum->ape2);
				return NRR;
			}
		}	
	}
	
	return NRR;
}
