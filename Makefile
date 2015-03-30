CFLAGS= --static



all:t2s

	
	g++ audiomain.cpp -o d2a $(CFLAGS)



t2s:
	g++ t2smain.cpp -o t2s $(CFLAGS)


install:	

	sudo cp d2a /bin
	sudo cp t2s /bin

	
clean: 
	rm t2s
	rm d2a
	
