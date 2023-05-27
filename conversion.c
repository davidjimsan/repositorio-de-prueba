#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
	char opcion;
	//int opcion2;
	int flag=1;
	float valorlibra=0, valordolar=0;
	float euros=0, dolares=0, libras=0;
	float valortemp=0, valortemp2=0;
	    puts("\n                                    ========================================\n");
		puts("\n                                         CONVERSION DE DIVISAS               \n");
		puts("\n                                    ========================================\n");
	
	while(flag) {
		
		puts("\n                                   o) introducir valores cotizacion divisas\n");
		puts("\n                                   a) convertir euros a dolares y libras\n");
		puts("\n                                   b) convertir dolares a euros y libras\n");
		puts("\n                                   c) convertir libras a dolares y euros\n");
		puts("\n                                   s) salir\n");
		puts("\n opcion?");
		scanf("%c",&opcion);
		fflush (stdin);
			switch (opcion){
				case 'o':
				case 'O':
					printf("\nintroduzca cuantas libras son un euro");
					scanf("%f", &valorlibra);
					printf("\nintroduzca cuantos dolares son un euro:");
					scanf("%f", &valordolar);
					fflush (stdin);
					break;
				case 'a':
				case 'A':
					if (valordolar==0 || valorlibra==0){
						puts ("INTRODUZCA PRIMERO LOS VALORES DE CONVERSION");
						break;
					}else {
					
					
					printf("\nintroduzca importe en euros:");
					scanf("%f", &euros);
					fflush (stdin);
					libras=euros*valorlibra;
					dolares=euros*valordolar;
					printf("\n%g euros \n",euros);
					printf("\n%g libras --- 1 euros =%glibras\n",libras,valorlibra);
					printf("\n%g dolares ----1 euro=%gdolares\n", dolares,valordolar);
					system ("pause");
					break;
				}
				case 'b':
				case 'B':
						if (valordolar==0 || valorlibra==0){
						puts ("INTRODUZCA PRIMERO LOS VALORES DE CONVERSION");
						break;
					}else {
						printf("\nintroduzca importe en dolares:");
					scanf("%f", &dolares);
					fflush (stdin);
					valortemp=valorlibra/valordolar;
					valortemp2=1/valordolar;
					libras=dolares*valortemp;
					euros=dolares*valortemp2;
					printf("\n%g dolares \n",dolares);
					printf("\n%g libras --- 1 dolar =%glibras\n",libras,valortemp);
					printf("\n%g euros ----1 dolar=%geuros\n", euros,valortemp2);
					system ("pause");
					break; }
				case 'c':
				case 'C':
						if (valordolar==0 || valorlibra==0){
						puts ("INTRODUZCA PRIMERO LOS VALORES DE CONVERSION");
						break;
					}else {
					printf("\nintroduzca importe en libras:");
					scanf("%f", &libras);
					fflush (stdin);
					valortemp=valordolar/valorlibra;
					valortemp2=1/valorlibra;
					dolares=libras*valortemp;
					euros=libras*valortemp2;
					printf("\n%g libras \n",libras);
					printf("\n%g dolares --- 1 libra =%gdolares\n",dolares,valortemp);
					printf("\n%g euros ----1 libra=%geuros\n", euros,valortemp2);
					system ("pause");
					break; }
				case 's':
				case 'S':
					flag=0;
					puts("\nA SELECCCIONADO SALIR DEL MENU\n");
					break;
				default :
					puts ("OPCION NO VALIDA, PORFAVOR ELIGA UNA OPCION DEL MENU");
					
					
					
					
			}
		/*	puts("SI DESEA BORRAR LA PANTALLA PULSE 1");
			scanf ("%d", &opcion2);
			if (opcion2==1)
			system ("cleans");*/
	}// while (flag);
	
	system ("pause");
	return 0;
	
	
	
	
}
