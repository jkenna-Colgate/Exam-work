.PHONY: clean
CC=gcc
CFLAGS=-g -std=c11 -fpic -Wall -D_DEFAULT_SOURCE
BINS=sleeping ring strdivide
LIBS=$(patsubst %,lib%.so,$(BINS))
OBJS=$(patsubst %,%.o,$(BINS))

all: $(BINS) $(LIBS)

sleeping: sleeping.o
	$(CC) -Wall -o $@ $^

strdivide: strdivide.o
	$(CC) -Wall -o $@ $^

ring: ring.o
	$(CC) -Wall -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -Wall -o $@ $<

lib%.so: %.o
	$(CC) -shared -Wall -o $@ $<

clean:
	rm -f $(OBJS) $(BINS) $(LIBS)
