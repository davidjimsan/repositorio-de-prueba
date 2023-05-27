#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
	int sobresalientes=0;
	int notables=0;
	int aprobado=0;
	int suspenso=0;
	int muydefi=0;
	float media=0;
	float nota;
	float sobpor=0;
	float notpor=0;
	float apropor=0;
	float susppor=0;
	float muydepor=0;
	int notas=0;
	float suma=0;
	
	printf ("\nintroduzca las notas de los alumnos:\n");
	printf ("\nsi desea salir teclee un numero negativo.\n");
	
	puts ("\nintroduzca una nota:");
		scanf("%f", &nota);
	
	while (nota>=0) {
		
		
		if (nota<=10 && nota>=9){
			notas++;
			sobresalientes++;
			suma+=nota;
		}	else if (nota<9 && nota>=7){
		             notas++;
			         notables++;
			         suma+=nota;
			    } else if (nota<7 && nota >=5){
			    	       notas++;
				           aprobado++;
				           suma+=nota;
			         } else if(nota<5 && nota >=2){
			         	     notas++;
                             suspenso++;
							 suma+=nota;					        
					        }else if(nota<2 && nota>=0){
					        	notas++;
					        	muydefi++;
					        	suma+=nota;
					               }else
							       puts ("numero mayor que 10"); 
							   
		 
					           
		puts ("\nintroduzca una nota:");
		scanf("%f", &nota);
		}
		 
		 media=suma/notas;
		 sobpor=((float)sobresalientes/notas)*100;
		 notpor=((float)notables/notas)*100;
		 apropor=((float)aprobado/notas)*100;
		 susppor=((float)suspenso/notas)*100;
		 muydepor=((float)muydefi/notas)*100;
		 
		 printf("\ntotal de alumnos presentados..............:%d",notas);
		 printf("\n\nnumero de sobresalientes................:%d.....(%.2f%%)",sobresalientes,sobpor);
		 printf("\n\nnumero de notables......................:%d.....(%.2f%%)", notables,notpor);
		 printf("\n\nnumero de aprobados.....................:%d.....(%.2f%%)",aprobado,apropor);
		 printf("\n\nnumero de suspensos.....................:%d.....(%.2f%%)", suspenso,susppor);
		 printf("\n\nnumero de muy deficientes...............:%d.....(%.2f%%)", muydefi, muydepor);
		 printf("\n\nla nota media es........................:%.2f", media);
		 puts("");
		 system ("pause");
		 return 0;
			
						
			
	}

