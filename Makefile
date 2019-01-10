# Compiler and Linker
CC=gcc

include config.mk

$(info "STATIC FLAG =" [${STATIC_LIB_BUILD}])
$(info "DEBUG FLAG ="  [${DEBUG}])


EXT_FLAGS=

# Settings from .mk
ifeq ($(DEBUG),y)
	EXT_FLAGS=-g
endif

TEST_DIR=test
INSTALL_LIB_DIR=libs
SHARED_LIB=libsco.so
STATIC_LIB=libsco.a

# Flags
CFLAGS=-c -Wall -pedantic -Wall -Wextra $(EXT_FLAGS)
LDFLAGS=-lm

# Include, Source and Libs
INCDIR=-I./include
LIBDIR=
SRCDIR=./src/
SOURCES=$(SRCDIR)interface.c 
OBJECTS=$(SOURCES:.c=.o)

ifeq ($(STATIC_LIB_BUILD),y)
	TARGET=$(SOURCES) $(STATIC_LIB)
else
	TARGET=$(SOURCES) $(SHARED_LIB)
endif

all: $(TARGET)

$(STATIC_LIB):
	ar -rcsv $(STATIC_LIB) $^
	@echo	 "Creating Static Lib"
	ranlib $(STATIC_LIB)

$(SHARED_LIB): $(OBJECTS)
	@echo "Creating Dynamic Lib"
	$(CC) -shared -fPIC -o $@ $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) $< -o $@

.PHONY: clean install all test

clean:
	
ifneq ("$(wildcard $(STATIC_LIB))","")
	@echo "Removing static lib"
	@rm $(STATIC_LIB);
endif

ifneq ("$(wildcard $(SHARED_LIB))","")
	@echo "Removing shared lib"
	@rm $(SHARED_LIB);rm ./src/*.o
endif

ifneq ("$(wildcard $(INSTALL_LIB_DIR))","")
	@echo "Removing installation folder"
	@rm -rf $(INSTALL_LIB_DIR)
endif

install:
	@echo "Install libs on libs/ folder"	
ifneq ("$(wildcard $(STATIC_LIB))","")
	@mkdir $(INSTALL_LIB_DIR); mv $(STATIC_LIB) $(INSTALL_LIB_DIR)
else
	@mkdir $(INSTALL_LIB_DIR); mv $(SHARED_LIB) $(INSTALL_LIB_DIR)
endif	

test:   $(OBJECTS)
	$(CC) $(CFLAGS) -o exec_test $^ $(INCDIR) $(LIBDIR) 
