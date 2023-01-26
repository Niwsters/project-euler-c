build:
	gcc ./src/*c -o ./bin/program -fsanitize=address -lm

run:
	./bin/program

dev: build run
