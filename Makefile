srcs = $(wildcard src/*.c)
progrs = $(patsubst src/%.c, bin/%, $(srcs))
cflags = -fsanitize=address -lgmp -lm -pg -std=c99

all: $(progrs)
%: src/%.c
	gcc -o bin/$@ $< $(cflags)
	./bin/$@ $<

clean:
	rm -f $(progrs)
