###
### File: makefile
### Author: Group 27: Yousif Albaker, April Castaneda, Victoria Fisher, 
### 			Patrick Oh, & Katie Stuts
### Description: Makefile for Group Project
###

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time

SRCS = *.cpp
EXEC = Group27

build:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${EXEC}

zip:
	zip $(EXEC).zip *.cpp *.hpp *.* makefile

clean:
	rm -rf *o *.dSYM ${EXEC}
