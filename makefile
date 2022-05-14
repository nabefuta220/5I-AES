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

out/testMultiply : bin/testMultiply.o src/Multiply.c
out/testInverse : bin/testInverse.o src/Inverse.c src/Multiply.c