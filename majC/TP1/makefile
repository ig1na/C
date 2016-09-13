ex : premierprog.c
	gcc -o ex premierprog.c
test : aux.o test.c
	gcc -o test aux.o test.c 
aux.o : aux.c
	gcc -c aux.c
mcu_wc : aux.o mcu_wc.c
	gcc -o mcu_wc aux.o mcu_wc.c 
