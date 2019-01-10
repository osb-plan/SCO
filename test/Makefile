# Compiler and Linker
CC=gcc

# Settings from .mk
ifeq ($(DEBUG),y)
	EXT_FLAGS=-g
else
	EXT_FLAGS=
endif

# Target Binary
TARGET=exec_program

INSTALL_DIR=dist
# Flags
CFLAGS=-c -Wall $(EXT_FLAGS)
LDFLAGS=-lm -lsco

# Include, Source and Libs
INCDIR=-I../include
LIBDIR=-L../ 
SRCDIR=./
SOURCES=test.c
OBJECTS=$(SOURCES:.c=.o)

EXECUTABLE=exec_program

all: $(SOURCES) $(EXECUTABLE)
	    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(INCDIR) $(LIBDIR) -o $@ $(LDFLAGS) 

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) $< -o $@

.PHONY: clean install all 

clean:
ifeq (,$(wildcard ./$(TARGET)))
	@rm $(SRCDIR)*.o; rm -rf $(INSTALL_DIR)
else
	@rm $(SRCDIR)*.o $(TARGET); rm -rf $(INSTALL_DIR)
endif

install:
	@mkdir $(INSTALL_DIR); mv $(TARGET) $(INSTALL_DIR)
	
