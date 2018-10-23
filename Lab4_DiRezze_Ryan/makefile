
CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

OBJS = main.o menu.o inputValidation.o people.o university.o

SRCS = main.cpp menu.cpp inputValidation.cpp people.cpp university.cpp

HEADERS = menu.hpp inputValidation.hpp people.hpp university.hpp

#target: dependencies
#	rule to build
#

OSUIMS: ${SRCS} ${HEADERS}		# OSUIMS = Oregon State University Information Management System
	${CXX} ${CXXFLAGS} ${SRCS} -o OSUIMS

#${OBJS}: ${SRCS}
#	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
