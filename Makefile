srcs = $(wildcard src/*.c)
progrs = $(patsubst src/%.c, bin/%, $(srcs))
cflags = -fsanitize=address -lgmp -lm

all: $(progrs)
%: src/%.c
	gcc -o bin/$@ $< $(cflags)
	./bin/$@ $<

clean:
	rm -f $(progrs)
