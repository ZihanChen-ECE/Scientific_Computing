CPP = g++ 
CPPFLAGS = -I${SCINET_OPENBLAS_INC} -std=c++11 -Wall -g -O2
LDFLAGS =  -L${SCINET_OPENBLAS_LIB} -lfftw3 -lopenblas

rundata:  readdata.o filename.o sort.o
	${CPP} ${LDFLAGS} readdata.o filename.o sort.o -o rundata 

readdata.o:  readdata.cpp filename.h
	${CPP} ${CPPFLAGS} readdata.cpp -c -o readdata.o
 
filename.o: filename.cpp
	${CPP} ${CPPFLAGS} filename.cpp -c -o filename.o

sort.o: sort.cpp
	${CPP} ${CPPFLAGS} sort.cpp -c -o sort.o  

run: rundata
	./rundata |tee CCoutput.txt

clean:
	rm -f *.o 
	rm -f rundata
 