CC  = gcc
CFLAGS    =
TARGET  = 
SRCS    = src/$(TARGET).c

OBJS    = #$(SRCS:.cpp=.o)

INCDIR  = -I src

LIBDIR  = 

LIBS    = 

out/$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)
	
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCDIR) -c $(SRCS)


results/$(TARGET).txt : out/$(TARGET)
	./$< > $@

check : results/$(TARGET).txt
	diff $< results/$(TARGET).res.txt
all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(TARGET) *.d　out/*

src/sbox.c : out/mksbox
	./$< > $@
src/mbox02.c : out/mkmbox02
	./$< > $@
src/mbox03.c : out/mkmbox03
	./$< > $@

out/testMultiply : bin/testMultiply.o src/Multiply.c
out/testInverse : bin/testInverse.o src/Inverse.c src/Multiply.c
out/testAffine : bin/testAffine.o  src/Affine.c
out/test1 : src/Multiply.c src/Inverse.c src/Affine.c bin/test1.o bin/cipherH.o \
bin/debug.o bin/keyexpand1.o bin/shiftrows.o bin/mixcolumns.o bin/subbytes.o \
bin/addroundkey.o 
out/mksbox :src/mksbox.c src/Mutiply.c src/Inverse.c src/Affine.c
out/mkmbox02 :src/mkmbox02.c src/Multiply.c
out/mkmbox03:src/mkmbox03.c src/Multiply.c
out/testSubbytes :src/Subbytes.c src/Multiply.c src/sbox.c bin/test1.o bin/cipherH.o \
bin/debug.o bin/keyexpand2.o bin/shiftrows.o bin/mixcolumns.o
out/testMixcolumns src/Mixcolumns.c src/Subbytes.c bin/test1.o bin/cipherH.o \
bin/debug.o bin/keyexpand2.o bin/shiftrows.o