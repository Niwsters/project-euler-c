srcs = $(wildcard src/*.c)
progrs = $(patsubst src/%.c, bin/%, $(srcs))

all: $(progrs)
%: src/%.c
	$(CC) $(CFLAGS) -o bin/$@ $<
	./bin/$@ $<

clean:
	rm -f $(progrs)

build:
	gcc ./src/*c -o ./bin/program -lm -lgmp

build-profile:
	gcc ./src/*c -o ./bin/program -lm -pg -lgmp

build-sanitize:
	gcc ./src/*c -o ./bin/program -fsanitize=address -lm -pg -lgmp

run:
	./bin/program

run-test:
	./bin/program --test

test: build-sanitize run-test

dev: build-sanitize run

profile: build-profile run
	gprof ./bin/program | vim
