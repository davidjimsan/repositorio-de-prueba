//David Jiménez Sánchez 70837115-J grupo: PA2
#include "dispersion.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

tipoAlumno *busquedaHash (FILE *f, char *dni, int *nCubo, int *ncuboDes, int *posReg, int *error)
{
	int dnii, posCubo, i, n;
	tipoAlumno *alumno;
	tipoCubo cubo;
	*ncuboDes=-1;
	*error=-1;
	if ((alumno=(tipoAlumno *) malloc(sizeof(tipoAlumno)))==NULL){
		*error=-4;	
		return NULL;
	}
	
	dnii=atoi(dni);
	posCubo=dnii % CUBOS;
	*nCubo=posCubo;
	fseek(f, posCubo*sizeof(tipoCubo), SEEK_SET);
	fread(&cubo, sizeof(cubo), 1, f);
	if (cubo.numRegAsignados<=C){
		for (i=0; i<cubo.numRegAsignados; i++){
			if (strcmp(dni, cubo.reg[i].dni)==0){ 
				strcpy(alumno->dni, cubo.reg[i].dni);
				strcpy(alumno->nombre, cubo.reg[i].nombre);
				strcpy(alumno->ape1, cubo.reg[i].ape1);
				strcpy(alumno->ape2, cubo.reg[i].ape2);
				strcpy(alumno->provincia, cubo.reg[i].provincia);
				*posReg=i;
				*error=0;
				return alumno;
			}
		}
	}else{
		
		for (i=0; i<C; i++){
			if (strcmp(dni, cubo.reg[i].dni)==0){
				strcpy(alumno->dni, cubo.reg[i].dni);
				strcpy(alumno->nombre, cubo.reg[i].nombre);
				strcpy(alumno->ape1, cubo.reg[i].ape1);
				strcpy(alumno->ape2, cubo.reg[i].ape2);
				strcpy(alumno->provincia, cubo.reg[i].provincia);
				*posReg=i;
				*error=0;
				return alumno;
			}
		}
		
		i=0;
		do{
			fseek(f, (CUBOS+i)*sizeof(tipoCubo), SEEK_SET);
			fread(&cubo, sizeof(cubo), 1, f);
			for (n=0; n<cubo.numRegAsignados; n++){
				if (strcmp(dni, cubo.reg[n].dni)==0){
					strcpy(alumno->dni, cubo.reg[n].dni);
					strcpy(alumno->nombre, cubo.reg[n].nombre);
					strcpy(alumno->ape1, cubo.reg[n].ape1);
					strcpy(alumno->ape2, cubo.reg[n].ape2);
					strcpy(alumno->provincia, cubo.reg[n].provincia);
					*posReg=n;
					*error=0;
					*ncuboDes=i;
					return alumno;
				}
			}
			i++;
		}while (i<CUBOSDESBORDE && cubo.numRegAsignados>=C);
	}
	
	
	return NULL;

}


int modificarReg (char *fichero, char *dni, char *provincia)
{
	FILE *f;
	int nCubo, nCuboDes, posReg, error;
	tipoAlumno *alumno;
	tipoCubo cubo;
	if ((f=fopen(fichero, "rb+"))==NULL){
		return -2;
	}
	if ((alumno=(tipoAlumno *) malloc(sizeof(tipoAlumno)))==NULL){	
		return -4;
	}
	
	alumno = busquedaHash(f, dni, &nCubo, &nCuboDes, &posReg, &error);	
	if (error==0){
		if (nCuboDes==-1){
			fseek (f, nCubo*sizeof(tipoCubo), SEEK_SET);
			fread(&cubo, sizeof(cubo), 1, f);
			fseek (f, nCubo*sizeof(tipoCubo), SEEK_SET);
		}else{
			fseek (f, (CUBOS+nCuboDes)*sizeof(tipoCubo), SEEK_SET);
			fread(&cubo, sizeof(cubo), 1, f);
			fseek (f, (CUBOS+nCuboDes)*sizeof(tipoCubo), SEEK_SET);
		}
		*alumno=cubo.reg[posReg];
		strcpy(alumno->provincia, provincia);
		cubo.reg[posReg]=*alumno;
		fwrite(&cubo, sizeof(cubo), 1, f);
		fclose(f);
		return nCubo;
	}else{
		fclose(f);
		return error;
	}	
}


/***********************************************************************************************/
int creaHash(char *fichEntrada,char *fichHash){
  FILE *entrada, *salida;
  int desborde = 0;
  tipoAlumno alumno;
  tipoCubo cubo;
  int dni, numeroCubo, i;

  creaHvacio(fichHash);
  
  if( (entrada=fopen(fichEntrada,"rb")) == NULL){
      fprintf(stderr, "ERROR: fopen( %s )\n", fichEntrada);
     return -2;
  }

  if( (salida=fopen(fichHash,"r+b")) == NULL){
      fprintf(stderr, "ERROR: fopen( %s )\n", fichHash);
     return -3;
  }

 	while (fread( &alumno ,sizeof(tipoAlumno),  1, entrada)){
  		numeroCubo=fHash(alumno.dni);
  		fseek (salida, numeroCubo*sizeof(cubo), SEEK_SET);	
  		fread(&cubo, sizeof(tipoCubo), 1, salida);
  		if (cubo.numRegAsignados < C){
  			cubo.reg[cubo.numRegAsignados]=alumno;
  			cubo.numRegAsignados+=1;
  			fseek (salida , -sizeof(tipoCubo), SEEK_CUR);
  			fwrite(&cubo, sizeof(cubo), 1, salida);	
  		}else{
  			cubo.numRegAsignados+=1;
  			fseek (salida , -sizeof(tipoCubo), SEEK_CUR); //aumentamos el cubo original
  			fwrite(&cubo, sizeof(cubo), 1, salida);
  			desborde++;
  			fseek(salida,CUBOS*sizeof(tipoCubo),SEEK_SET);
    		i=-1;
    		while(i<CUBOSDESBORDE-1 && cubo.numRegAsignados>=C){
     			i++;
      			fread(&cubo,sizeof(tipoCubo),1,salida);
      		}
      		if (i<CUBOSDESBORDE){
      			cubo.reg[cubo.numRegAsignados]=alumno;
      			fseek(salida,-sizeof(tipoCubo),SEEK_CUR);
    			fwrite(&cubo,sizeof(tipoCubo),1,salida);
    			incrementarDesborde(i,salida);
      		}
    	}
  		}
  	fclose(entrada);
  	fclose(salida);
  	return desborde;
}


void incrementarDesborde(int hasta, FILE* f){
  int i;
  tipoCubo c;

  fseek(f,CUBOS*sizeof(tipoCubo),SEEK_SET);

  i=0;
  while(i<=hasta){
    fread(&c,sizeof(tipoCubo),1,f);
    c.numRegAsignados += 1;
    fseek(f,-sizeof(tipoCubo),SEEK_CUR);
    fwrite(&c,1,sizeof(tipoCubo),f);
    i++;
  }

}


int fHash(char *cad){

  return (atoi(cad) % CUBOS);
}

void creaHvacio(char *fichHash)
{ FILE *fHash;
  tipoCubo cubo;
  int j;
  int numCubos =CUBOS+CUBOSDESBORDE;

  memset(&cubo,0,sizeof(cubo));

  fHash = fopen(fichHash,"wb");
  for (j=0;j<numCubos;j++) fwrite(&cubo,sizeof(cubo),1,fHash);
  fclose(fHash);
}



