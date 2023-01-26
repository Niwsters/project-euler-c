build:
	gcc ./src/*c -o ./bin/program -lm

build-profile:
	gcc ./src/*c -o ./bin/program -lm -pg

build-sanitize:
	gcc ./src/*c -o ./bin/program -fsanitize=address -lm -pg

run:
	./bin/program

dev: build-sanitize run

profile: build-profile run
	gprof ./bin/program | vim
