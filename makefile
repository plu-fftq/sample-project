CXX = g++
CFLAGS = -c -g -Wall
TARGET = runtest
OBJS=stb_csv_reader.o stb_csv_writer.o stb_utils.o main.o
RMF=rm -f

${TARGET}: ${OBJS}
	${CXX} -o ${TARGET} $^

main.o: main.cpp
	${CXX} ${CFLAGS} main.cpp -o main.o

stb_csv_reader.o: stb_csv_reader.cpp stb_csv_reader.h
	${CXX} ${CFLAGS} -c stb_csv_reader.cpp -o stb_csv_reader.o

stb_csv_writer.o: stb_csv_writer.cpp stb_csv_writer.h
	${CXX} ${CFLAGS} -c stb_csv_writer.cpp -o stb_csv_writer.o

stb_utils.o: stb_utils.cpp stb_utils.h
	${CXX} ${CFLAGS} -c stb_utils.cpp -o stb_utils.o

all: ${TARGET}

.PHONY: clean all

clean:
	${RMF} *.o runtest
