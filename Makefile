srcs = $(wildcard src/*.c)
progrs = $(patsubst src/%.c, bin/%, $(srcs))
cflags = -fsanitize=address -lgmp

all: $(progrs)
%: src/%.c
	gcc -o bin/$@ $< $(cflags)
	./bin/$@ $<

clean:
	rm -f $(progrs)
