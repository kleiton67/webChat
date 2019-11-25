OBJ = word.o controle.o server.o serverchat.o comunication.o
LIB = -lpthread 

server.run: ${OBJ}
	g++ main.cpp ${OBJ} -o ./server.run ${LIB}

word.o : ../word/word.cpp  ../word/word.h
	g++ ${LIB} -c ../word/word.cpp
controle.o : controle.cpp controle.h
	g++ ${LIB} -c controle.cpp
server.o : server.cpp server.h structArg.h
	g++ ${LIB} -c server.cpp
serverchat.o : serverchat.cpp serverchat.h
	g++ ${LIB} -c serverchat.cpp
comunication.o : ../comunication/comunication.cpp ../comunication/comunication.cpp
	g++ ${LIB} -c ../comunication/comunication.cpp
clean :
	rm ./bin/server.run ${OBJ}
