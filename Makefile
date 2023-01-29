SDCCOPTS ?= --iram-size 128

SRC=avvisoBoule.c 
#SRC = $(wildcard *.c)
OBJ=$(patsubst %.c,build/%.rel, $(SRC))

build/%.rel: %.c
	mkdir -p $(dir $@)
	sdcc $(SDCCOPTS) -o build/ -c $<

all: avvisoBoule

avvisoBoule: $(OBJ)
	sdcc -o build/ $(SDCCOPTS) $^
	cp build/$@.ihx $@.hex

clean:
	rm -f *.ihx *.hex *.bin
	rm -f build/*
