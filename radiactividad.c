#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (void){
	
	float masafin, porc, masainic, decremento, masainic2,limit;
	int dias=0;
	
	puts("\n============================================================\n");
	puts("\n            CALCULO DE DIAS DE DESINTEGRACION          \n");
	puts("\n============================================================\n");
	
	 do {
	 	printf("\n introduzca el valor de la masa radiactiva:\n");
	 	scanf("%f",&masainic);
	 	
	 } while (masainic<0);
	 
	 do {
	 	printf("\n introduzca el valor del porcentaje de desintegracion diario:\n");
	 	scanf("%f",&porc);
	 	
	 	
	 } while (porc<0 || porc>100);
	 
	 	masafin=masainic;
	 	limit=masainic/2;
	 	printf("\n  dia     Masa inical            Decremento         Masa final\n");
	 
	 while (masafin>=limit){
	 	masainic2=masafin;
	 	decremento= masafin*(porc/100);
	 	masafin=masafin-decremento;
	 	dias++;
	 	
	 	printf("\n   %d        %.4f              %.4f           %.4f     \n",dias,masainic2,decremento,masafin);
	 	
	 	
	 }
	 puts("");
	 system("pause");
	 return 0;
	 
}

