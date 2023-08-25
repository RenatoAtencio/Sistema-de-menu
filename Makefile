OPTIONS= -O3 -Xcompiler -fopenmp 
SRC=main.cpp Usuario.cpp funcionesParaUsuario.cpp funcionesParse.cpp funcionesMenu.cpp
all:
	nvcc ${OPTIONS} ${SRC} -o main
