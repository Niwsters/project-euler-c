srcs = $(wildcard src/*.c)
progrs = $(patsubst src/%.c, bin/%, $(srcs))
cflags = -fsanitize=address

all: $(progrs)
%: src/%.c
	gcc $(cflags) -o bin/$@ $<
	./bin/$@ $<

clean:
	rm -f $(progrs)
