EXEC = sim

SRC = $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
HEA= $(SRC:.cpp=.h)

# SRCDIR=modules/*
# OBJDIR=build

# SRC = $(wildcard $(SRCDIR)/*.c)
# TMP_OBJ = $(subst .c,.o,$(SRC))
# NEW_OBJ = $(subst $(SRCDIR)/,$(OBJDIR)/,$(TMP_OBJ))

CC=g++

SYSTEMC=/usr/local/systemc-2.3.3

LDFLAGS= -L$(SYSTEMC)/lib-linux64 -Wl,-rpath=$(SYSTEMC)/lib-linux64 -lm -lsystemc
CXXFLAGS= -W -Wall -pedantic -g -I$(SYSTEMC)/include -DDEBUG_SYSTEMC



all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)


%.o: %.cpp %.h
	$(CC) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

tar: $(HEA) $(SRC)
	tar -cvf $(EXEC).tar makefile $^
