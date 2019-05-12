###
### File: makefile
### Author: Group 27: Yousif Albaker, April Castaneda, Victoria Fisher, 
### 			Patrick Oh, & Katie Stuts
### Description: Makefile for Group Project
###

 CXX = g++

 CXXFLAGS = -std=c++11

 OBJS = main.o menu.o inputValidation.o Board.o Critter.o Ant.o Doodlebug.o

 SRCS = main.cpp menu.cpp inputValidation.cpp Board.cpp Critter.cpp Ant.cpp Doodlebug.cpp

 HEADERS = menu.hpp inputValidation.hpp Board.hpp Critter.hpp Ant.hpp Doodlebug.hpp

 edit: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o edit

 main.o: main.cpp ${HEADERS}
	${CXX} ${CXXFLAGS} main.cpp -c

 menu.o: menu.cpp menu.hpp
	${CXX} ${CXXFLAGS} menu.cpp -c

 inputValidation.o: inputValidation.cpp inputValidation.hpp
	${CXX} ${CXXFLAGS} inputValidation.cpp -c

 Board.o: Board.cpp Board.hpp
	${CXX} ${CXXFLAGS} Board.cpp -c

 Critter.o: Critter.cpp Critter.hpp
	${CXX} ${CXXFLAGS} Critter.cpp -c

 Ant.o: Ant.cpp Ant.hpp
	${CXX} ${CXXFLAGS} Ant.cpp -c

 Doodlebug.o: Doodlebug.cpp Doodlebug.hpp
	${CXX} ${CXXFLAGS} Doodlebug.cpp -c

 clean:
	rm edit ${OBJS}