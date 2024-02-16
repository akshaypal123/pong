build:
	g++ -o app/pong.exe src/main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run: build
	./app/pong.exe