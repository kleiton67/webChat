OBJ = word.o ctrlCliente.o  comunication.o cliente.o
LIB = -lpthread 

server.run: ${OBJ}
	g++ ${OBJ} main.cpp -o ./cliente.run ${LIB}

word.o : ../word/word.cpp  ../word/word.h
	g++ ${LIB} -c ../word/word.cpp
ctrlCliente.o : ctrlCliente.cpp ctrlCliente.h
	g++ ${LIB}  -c ctrlCliente.cpp
comunication.o : ../comunication/comunication.cpp ../comunication/comunication.cpp
	g++ ${LIB} -c ../comunication/comunication.cpp
cliente.o : cliente.cpp cliente.h
	g++ ${LIB} -c cliente.cpp
clean :
	rm cliente.run ${OBJ}
