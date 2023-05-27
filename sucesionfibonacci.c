//programa que calcula la sucession de Fibonacci.






#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main (void){
	
	int t1, t2;
	int tn=0;
	int limite ;
	
	puts("\n=======================================\n");
	puts("\n       SUCESION DE FIBONACCI            \n");
	puts("\n=======================================\n");
	
	printf("\n introduzca el limite de la sucesion:\n");
	scanf("%d",&limite);
	puts("");
    
    while (tn<=limite){
    	
    	tn=t1+t2;
    	t2=tn-t2;
    	t1=tn;
    	printf("%d  ",tn);
	}
	
	
	puts("");
	puts("");
	system ("pause");
	return 0;
	
}
