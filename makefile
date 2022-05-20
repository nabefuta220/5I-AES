CC  = gcc
CFLAGS    =
TARGET  = 
SRCS    =$(wildcard src/*.c)
NAMES =   $(basename $(notdir $(SRCS)))
OBJS    =  $(foreach name,$(NAMES),bin/$(name).o)

INCDIR  = -I src

LIBDIR  = 

LIBS    = 

out/$(TARGET) :
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)

out/%: 
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)
	
bin/%.o: src/%.c
	@[ -d bin ]
	$(CC) $(CFLAGS) $(INCDIR) -o $@ -c $<


results/$(TARGET).txt : out/$(TARGET)
	./$< > $@

check : results/$(TARGET).txt
	diff $< results/$(TARGET).res.txt
all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(TARGET) $(OBJS) *.d　out/
add :
	$(CC) -MM src/$(TARGET).c >> makefile

out/testMultiply : bin/testMultiply.o bin/Multiply.o
out/testInverse : bin/testInverse.o bin/Inverse.o bin/Multiply.o
out/testAffine : bin/testAffine.o  bin/Affine.o
out/test1 : bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test1.o bin/cipherH.o \
bin/debug.o bin/keyexpand1.o bin/shiftrows.o bin/mixcolumns.o bin/subbytes.o \
bin/addroundkey.o 

bin/Multiply.o: src/Multiply.c src/aes128.h
bin/Affine.o: src/Affine.c src/aes128.h
bin/Inverse.o: src/Inverse.c src/aes128.h
bin/keyexpand.o: src/keyexpand.c src/aes128.h
keyexpand.o: src/keyexpand.c src/aes128.h

src/sbox.c : out/mksbox
	./$< > $@
src/mbox02.c : out/mkmbox02
	./$< > $@
src/mbox03.c : out/mkmbox03
	./$< > $@


out/mksbox :bin/mksbox.o bin/Multiply.o bin/Inverse.o bin/Affine.o
out/mkmbox02 :bin/mkmbox02.o bin/Multiply.o
out/mkmbox03 :bin/mkmbox03.o bin/Multiply.o
out/testSubbytes :bin/Subbytes.o bin/Multiply.o bin/Cipher.o bin/test1.o \
bin/debug.o bin/keyexpand2.o bin/Shiftrows.o bin/Mmixcolumns.o bin/Addroundkey.o 
out/testMixcolumns : bin/Mixcolumns.o bin/Subbytes.o bin/test1.o bin/Cipher.o \
bin/debug.o bin/keyexpand2.o bin/Shiftrows.o bin/Addroundkey.o 

bin/mksbox.o: src/mksbox.c
bin/mkmbox02.o: src/mkmbox02.c
bin/mkmbox03.o: src/mkmbox03.c
bin/Subbytes.o: src/Subbytes.c src/aes128.h src/sbox.c
bin/Mixcolumns.o: src/Mixcolumns.c src/aes128.h src/mbox02.c src/mbox03.c
out/test2sm : bin/Msubbytes.o bin/Mmixcolumns.o bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test2.o \
bin/keyexpand1.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o
out/test2SM : bin/Subbytes.o bin/Mixcolumns.o bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test2.o \
bin/keyexpand2.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o

out/test2sM : bin/Msubbytes.o bin/Mixcolumns.o bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test2.o \
bin/keyexpand1.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o
out/test2Sm : bin/Subbytes.o bin/Mmixcolumns.o bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test2.o \
bin/keyexpand2.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o

out/testRoundkey : bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test1.o bin/cipherH.o \
bin/debug.o bin/keyexpand1.o bin/shiftrows.o bin/mixcolumns.o bin/subbytes.o \
bin/Addroundkey.o 
bin/Addroundkey.o: src/Addroundkey.c src/aes128.h

out/testsubbytes : bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test1.o bin/cipherH.o \
bin/debug.o bin/keyexpand1.o bin/shiftrows.o bin/mixcolumns.o bin/Msubbytes.o \
bin/addroundkey.o 
bin/Msubbytes.o: src/Msubbytes.c src/aes128.h

out/testShiftrows : bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test1.o bin/cipherH.o \
bin/debug.o bin/keyexpand1.o bin/Shiftrows.o bin/mixcolumns.o bin/subbytes.o \
bin/addroundkey.o 
bin/Shiftrows.o: src/Shiftrows.c src/aes128.h

out/testmixcolumns : bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test1.o bin/cipherH.o \
bin/debug.o bin/keyexpand1.o bin/shiftrows.o bin/Mmixcolumns.o bin/subbytes.o \
bin/addroundkey.o 

bin/Mmixcolumns.o: src/Mmixcolumns.c src/aes128.h

out/Test1 : bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test1.o bin/Cipher.o \
bin/debug.o bin/keyexpand1.o bin/Shiftrows.o bin/Mmixcolumns.o bin/Msubbytes.o \
bin/Addroundkey.o 
bin/Cipher.o: src/Cipher.c src/aes128.h
