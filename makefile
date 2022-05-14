CC  = gcc
CFLAGS    =
TARGET  = 
SRCS    =$(wildcard src/*.c)
NAMES =   $(basename $(notdir $(SRCS)))
OBJS    =  $(foreach name,$(NAMES),bin/$(name).o)

INCDIR  = -I src

LIBDIR  = 

LIBS    = 

out/$(TARGET): 
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)
	
bin/%.o: 
	@[ -d bin ]
	$(CC) $(CFLAGS) $(INCDIR) -o $@ -c $<


results/$(TARGET).txt : out/$(TARGET)
	./$< > $@

check : results/$(TARGET).txt
	diff $< results/$(TARGET).res.txt
all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(TARGET) $(OBJS) *.d　out/*
add :
	$(CC) -MM src/$(TARGET).c >> makefile

out/testMultiply : bin/testMultiply.o bin/Multiply.o
out/testInverse : bin/testInverse.o bin/Inverse.o
out/testAffine : bin/testAffine.o  bin/Affine.o
out/test1 : bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test1.o bin/cipherH.o \
bin/debug.o bin/keyexpand1.o bin/shiftrows.o bin/mixcolumns.o bin/subbytes.o \
bin/addroundkey.o 

bin/Multiply.o: src/Multiply.c src/aes128.h
bin/Affine.o: src/Affine.c src/aes128.h
bin/Inverse.o: src/Inverse.c src/aes128.h
bin/keyexpand.o: src/keyexpand.c src/aes128.h
keyexpand.o: src/keyexpand.c src/aes128.h
