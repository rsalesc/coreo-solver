# Configurar arquivos aqui
INCLUDES=-I./include
SOURCES=BFS.cpp SearchSolver.cpp Parameters.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
BINARIES=solver

# Configurar flags de compilação aqui
CC = g++
CFLAGS = -std=c++11 -g3
LFLAGS = -lm

#######################

BDIR = ./build/
SDIR = ./src/
SRC = $(addprefix $(SDIR),$(SOURCES))
OBJ = $(addprefix $(BDIR),$(OBJECTS))

make: $(BDIR) $(BINARIES)

eco:
	@echo $(OBJ)
	@echo $(SRC)
	@echo $(INCLUDES)

$(addprefix $(BDIR), %.o): $(addprefix $(SDIR), %.cpp)
	$(CC) $(INCLUDES) -c $< -o $@ $(CFLAGS)

solver: $(OBJ)
	$(CC) -o $@ $(OBJ) $(LFLAGS)

$(BDIR):
	@mkdir $@

clean:
	rm -f *.o $(OBJ) $(BINARIES)
	rm -rf $(BDIR)
