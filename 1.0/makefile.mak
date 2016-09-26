#--------------------------------------------
# makefile zur Erzeugung der .exe zur SRJ
# incl. LaTEX-Teil zur Erstellung von PDF
#--------------------------------------------
.PHONY: all clean

# Definition der Variablen
CXX := gcc
CXXFLAGS := -std=c99 -c -Wall -IS:\User\Ra\Programme\C\masteval\1.0\lib\\
LDFLAGS := -g
HEADERS := $(wildcard S:\User\Ra\Programme\C\masteval\1.0\lib\*.h)
objs := main.o 

all: masteval_v1-0.exe

# Ziel 1
masteval_v1-0.exe: $(objs)
	$(CXX) $(LDFLAGS) -o $@ $^

# Ziel 2
main.o: main.c $(HEADERS)
	$(CXX) $(CXXFLAGS) $<

# Ziel 3
file_creation.o: file_creation.c
	$(CXX) $(CXXFLAGS) $<

# Alle *.o Dateien löschen
clean:
	del $(objs)

