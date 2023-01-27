build:
	gcc ./src/*c -o ./bin/program -lm

build-profile:
	gcc ./src/*c -o ./bin/program -lm -pg

build-sanitize:
	gcc ./src/*c -o ./bin/program -fsanitize=address -lm -pg

run:
	./bin/program

run-test:
	./bin/program --test

test: build-sanitize run-test

dev: build-sanitize run

profile: build-profile run
	gprof ./bin/program | vim
