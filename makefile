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

bin/mkibox.o: src/mkibox.c src/aes128.h
out/mkibox : bin/Inverse.o bin/Multiply.o bin/mkibox.o
src/ibox.c : out/mkibox
	./$< > $@
bin/Finverse.o: src/Finverse.c src/aes128.h src/ibox.c
out/testFinverse : bin/testInverse.o bin/Finverse.o bin/Multiply.o
bin/finverse.o: src/finverse.c src/aes128.h
out/testfinverse : bin/testInverse.o bin/finverse.o bin/Multiply.o

out/test2sm : bin/Msubbytes.o bin/Mmixcolumns.o bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test2.o \
bin/keyexpand1.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o
out/test2SM : bin/Subbytes.o bin/Mixcolumns.o bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test2.o \
bin/keyexpand2.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o

out/test2sM : bin/Msubbytes.o bin/Mixcolumns.o bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test2.o \
bin/keyexpand1.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o
out/test2Sm : bin/Subbytes.o bin/Mmixcolumns.o bin/Multiply.o bin/Inverse.o bin/Affine.o bin/test2.o \
bin/keyexpand2.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o

out/test2fsm : bin/Msubbytes.o bin/Mmixcolumns.o bin/Multiply.o bin/finverse.o bin/Affine.o bin/test2.o \
bin/keyexpand1.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o
out/test2fSM : bin/Subbytes.o bin/Mixcolumns.o bin/Multiply.o bin/finverse.o bin/Affine.o bin/test2.o \
bin/keyexpand2.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o

out/test2fsM : bin/Msubbytes.o bin/Mixcolumns.o bin/Multiply.o bin/finverse.o bin/Affine.o bin/test2.o \
bin/keyexpand1.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o
out/test2fSm : bin/Subbytes.o bin/Mmixcolumns.o bin/Multiply.o bin/finverse.o bin/Affine.o bin/test2.o \
bin/keyexpand2.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o

out/test2Fsm : bin/Msubbytes.o bin/Mmixcolumns.o bin/Multiply.o bin/Finverse.o bin/Affine.o bin/test2.o \
bin/keyexpand1.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o
out/test2FSM : bin/Subbytes.o bin/Mixcolumns.o bin/Multiply.o bin/Finverse.o bin/Affine.o bin/test2.o \
bin/keyexpand2.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o

out/test2FsM : bin/Msubbytes.o bin/Mixcolumns.o bin/Multiply.o bin/Finverse.o bin/Affine.o bin/test2.o \
bin/keyexpand1.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o
out/test2FSm : bin/Subbytes.o bin/Mmixcolumns.o bin/Multiply.o bin/Finverse.o bin/Affine.o bin/test2.o \
bin/keyexpand2.o bin/cipher.o bin/Addroundkey.o bin/Shiftrows.o

clock : out/$(TARGET)
	(time ./$< ) 2>&1 | cat > results/time_$(TARGET).txt

bin/Invsubbyte.o: src/Invsubbyte.c src/aes128.h
bin/testInvsubbyte.o: src/testInvsubbyte.c src/aes128.h src/isbox.c
out/testInvsubbyte : bin/testInvsubbyte.o bin/Invsubbyte.o bin/Affine.o bin/Inverse.o bin/Multiply.o

bin/mkisbox.o: src/mkisbox.c src/aes128.h src/sbox.c
out/mkisbox : bin/mkisbox.o

src/isbox.c : out/mkisbox
	./$< > $@

bin/Invmixcolumns.o: src/Invmixcolumns.c src/aes128.h
bin/testInvmixcolumns.o: src/testInvmixcolumns.c src/aes128.h
out/testInvmixcolumns : bin/testInvmixcolumns.o bin/Invmixcolumns.o bin/Multiply.o bin/debug.o

bin/Invshiftrows.o: src/Invshiftrows.c src/aes128.h
bin/testInvshiftrows.o: src/testInvshiftrows.c src/aes128.h
out/testInvshiftrows : bin/Invshiftrows.o bin/testInvshiftrows.o bin/debug.o \

bin/InvCipher.o: src/InvCipher.c src/aes128.h

bin/testInvCipher.o: src/testInvCipher.c src/aes128.h
out/testInvCipher : bin/testInvCipher.o bin/InvCipher.o \
bin/debug.o bin/Invshiftrows.o bin/Invsubbyte.o bin/Addroundkey.o \
bin/Invmixcolumns.o bin/Multiply.o bin/Cipher.o bin/shiftrows.o bin/Mmixcolumns.o bin/subbytes.o bin/Affine.o bin/Inverse.o