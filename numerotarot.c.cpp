#include <stdio.h>
#include <stdlib.h>


int main (void)
{
	int anonac;   //año de naciamiento
	int mesnac;   //mes de nacimiento
	int dianac;   //dia de nacimiento
	int unidades; //variable intermedia de unidades
	int decenas;  //variable intermedia de decenas
	int centenas; //variable intermedia de centenas
	int millares; //variable intermedia de millares
	int temp;     //variable para division
	int suma;     //suma de el dia, el mes y el año de nacimiento
	int tarot;    //variable salida numero tarot
		puts("\nCALCULO DE NUMERO TAROT\n");
		printf("\nintroduzca la fecha de su nacimiento con el siguiente formato dd/mm/aa:");
		scanf("%d/%d/%d",&dianac,&mesnac,&anonac);
			suma=anonac+mesnac+dianac;
			unidades=suma%10;
    		temp=suma/10;
   			decenas=temp%10;
    		temp=temp/10;
    		centenas=temp%10;
     		temp=temp/10;
    		millares=temp%10;
    		tarot=unidades+decenas+centenas+millares;
    			if (tarot>=10){
    				unidades=tarot%10;
    				decenas=tarot/10;
    				tarot=unidades+decenas;
		}
    	
     	printf("\nsu numero tarot es el siguiente:%d",tarot);
     	puts("");
     	puts("");
	system("pause");
	return 0;	
}
