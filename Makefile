# Configurar arquivos aqui
INCLUDES=-I./include
SOURCES=A.cpp BFS.cpp SearchSolver.cpp Parameters.cpp main.cpp
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

SRC_WILD = $(addprefix $(SDIR), %.cpp)
OBJ_WILD = $(addprefix $(BDIR), %.o)

make: $(BDIR) $(BINARIES)

eco:
	@echo $(OBJ)
	@echo $(SRC)
	@echo $(INCLUDES)

$(OBJ_WILD): $(SRC_WILD)
	$(CC) $(INCLUDES) -c $< -o $@ $(CFLAGS)

solver: $(OBJ)
	$(CC) -o $@ $(OBJ) $(LFLAGS)

$(BDIR):
	@mkdir $@

clean:
	rm -f *.o $(OBJ) $(BINARIES)
	rm -rf $(BDIR)
