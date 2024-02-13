build:
	g++ -o pong src/main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run: build
	./pong