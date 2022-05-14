CC  = gcc
CFLAGS    =
TARGET  = Sample
SRCS    = src/$(TARGET).c

OBJS    = $(wildcard bin/*.o)

INCDIR  = -I src

LIBDIR  = 

LIBS    = 

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)
	
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCDIR) -c $(SRCS)

results/out.$(TARGET).txt : $(TARGET)
	./$(TARGET).out >> $@

cheak : results/out.$(TARGET).txt
	diff $< results/$(TARGET).res.txt
all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(TARGET) *.d

