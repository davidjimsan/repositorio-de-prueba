//David Jiménez Sánchez 70837115-J grupo: PA2
#include <stdio.h>
#include "dispersion.h"
#include <stdlib.h>
#include "indice.h"

int main (){

	FILE *f, *ficheroDatos;
	int error, nCubo, nCuboDes, posReg;
	tipoAlumno *alumno;
	int registros;
	int NRR;
	if ((alumno=(tipoAlumno *) malloc(sizeof(tipoAlumno)))==NULL){	
		return 0;
	}
	
	puts ("********************************************************************");
	puts ("*                       PRIMER EJERCICIO                           *");
	puts ("********************************************************************");
	
	registros=generaIndice("alumnos.dat", "indice.idx");
	printf("generados %d registros\n\n", registros);
	puts ("BUSCAMOS DNI: 7389298 QUE EXISTE");
	NRR=busquedaIndice("7389298", "alumnos.dat", "indice.idx", alumno);
	if (NRR>0)
		printf("NRR: %d nombre %s, apellidos %s %s dni: %s\n\n", NRR, alumno->nombre, alumno->ape1, alumno->ape2, alumno->dni);
	else
		puts ("no existe registro");
	puts("BUSCAMOS DNI QUE NO EXISTE");
	NRR=busquedaIndice("123456789", "alumnos.dat", "indice.idx", alumno);
	if (NRR>0)
		printf("NRR: %d nombre %s, apellidos %s %s dni: %s\n\n", NRR, alumno->nombre, alumno->ape1, alumno->ape2, alumno->dni);
	else
		puts ("no existe registro");
		
	
	puts ("********************************************************************");
	puts ("*                       SEGUNDO EJERCICIO                          *");
	puts ("********************************************************************");
	
	error=creaHash("alumnos.dat", "alumnos.hash");
	f=fopen("alumnos.hash", "rb");
	puts("CREADO EL ARCHIVO HASH");
	puts("");
	puts("BUSCAMOS DNI 7395860");
	alumno=busquedaHash(f, "7395860", &nCubo, &nCuboDes, &posReg, &error);
	if (error==-1){
		printf("error no existe ese dni\n");
	}else{
		puts ("si existe");
		printf("nombre: %s apellidos: %s %s provincia: %s\n", alumno->nombre, alumno->ape1,alumno->ape2, alumno->provincia);
		printf("posiciones -> ncubo: %d, ncubodes: %d, posreg: %d\n", nCubo, nCuboDes, posReg);
	}
	fclose(f);
	puts("MODIFICAMOS SU PROVINCIA A AVILA");
	error=modificarReg("alumnos.hash", "7395860", "avila");
	if (error<0){
		printf("error al modificar\n");
	}else{
		puts("registro modificado comprobamos si se efectuo el cambio");
		f=fopen("alumnos.hash", "rb");
		alumno=busquedaHash(f, "7395860", &nCubo, &nCuboDes, &posReg, &error);
		printf("nueva provincia -> %s\n", alumno->provincia);
		fclose(f);
	}
	f=fopen("alumnos.hash", "rb");
	puts("");
	puts("BUSCAMOS DNI 7389298");
	alumno=busquedaHash(f, "7389298", &nCubo, &nCuboDes, &posReg, &error);
	if (error==-1){
		printf("error no existe ese dni\n");
	}else{
		puts ("si existe");
		printf("nombre: %s apellidos: %s %s provincia: %s\n", alumno->nombre, alumno->ape1,alumno->ape2, alumno->provincia);
		printf("posiciones -> ncubo: %d, ncubodes: %d, posreg: %d\n", nCubo, nCuboDes, posReg);
	}
	fclose(f);
	puts("MODIFICAMOS SU PROVINCIA A SALAMANCA");
	error=modificarReg("alumnos.hash", "7389298", "salamanca");
	if (error<0){
		printf("error al modificar\n");
	}else{
		puts("registro modificado comprobamos si se efectuo el cambio");
		f=fopen("alumnos.hash", "rb");
		alumno=busquedaHash(f, "7389298", &nCubo, &nCuboDes, &posReg, &error);
		printf("nueva provincia -> %s\n", alumno->provincia);
		fclose(f);
	}
	f=fopen("alumnos.hash", "rb");
	puts("");
	puts("BUSCAMOS DNI 7219752");
	alumno=busquedaHash(f, "7219752", &nCubo, &nCuboDes, &posReg, &error);
	if (error==-1){
		printf("error no existe ese dni\n");
	}else{
		puts ("si existe");
		printf("nombre: %s apellidos: %s %s provincia: %s\n", alumno->nombre, alumno->ape1,alumno->ape2, alumno->provincia);
		printf("posiciones -> ncubo: %d, ncubodes: %d, posreg: %d\n", nCubo, nCuboDes, posReg);
	}
	fclose(f);
	puts("MODIFICAMOS SU PROVINCIA A AVILA");
	error=modificarReg("alumnos.hash", "7219752", "avila");
	if (error<0){
		printf("error al modificar\n");
	}else{
		puts("registro modificado comprobamos si se efectuo el cambio");
		f=fopen("alumnos.hash", "rb");
		alumno=busquedaHash(f, "7219752", &nCubo, &nCuboDes, &posReg, &error);
		printf("nueva provincia -> %s\n", alumno->provincia);
		fclose(f);
	}
	
	f=fopen("alumnos.hash", "rb");
	puts("");
	puts("BUSCAMOS DNI 12345567 NO EXISTE");
	alumno=busquedaHash(f, "12345567", &nCubo, &nCuboDes, &posReg, &error);
	if (error==-1){
		printf("error no existe ese dni\n");
	}else{
		puts ("si existe");
		printf("nombre: %s apellidos: %s %s provincia: %s\n", alumno->nombre, alumno->ape1,alumno->ape2, alumno->provincia);
		printf("posiciones -> ncubo: %d, ncubodes: %d, posreg: %d\n", nCubo, nCuboDes, posReg);
	}
	fclose(f);
	puts("MODIFICAMOS SU PROVINCIA A AVILA");
	error=modificarReg("alumnos.hash", "12345567", "avila");
	if (error<0){
		printf("error al modificar\n");
	}else{
		puts("registro modificado comprobamos si se efectuo el cambio");
		f=fopen("alumnos.hash", "rb");
		alumno=busquedaHash(f, "12345567", &nCubo, &nCuboDes, &posReg, &error);
		printf("nueva provincia -> %s\n", alumno->provincia);
		fclose(f);
	}
	
	puts ("********************************************************************");
	puts ("*                       FIN DE LA PRUEBA                           *");
	puts ("********************************************************************");
	return 0;
}
