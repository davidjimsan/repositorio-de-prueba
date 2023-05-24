#David Jiménez Sánchez 70837115-J grupo: PA2
#prueba memoria secundaria

prueba: prueba.c indice.h dispersion.h dispersion.o indice.o
	gcc -g prueba.c dispersion.o indice.o -o prueba

dispersion.o: dispersion.c dispersion.h
	gcc -g -c dispersion.c
	
indice.o: indice.c indice.h secuencial.h
	gcc -g -c indice.c
