# Simple Pong Clone

This is a simple Pong game implemented in C++ using the raylib library.

## Game Control

- Player:
  - Up Arrow: Move paddle up
  - Down Arrow: Move paddle down

## Compiling Locally

To compile the game locally, you need to follow these steps:

1. Install raylib:
   - Visit the [raylib GitHub repository](https://github.com/raysan5/raylib) and follow the installation instructions for your platform.

2. Clone this repository:
    - `git clone https://github.com/your-username/simple-pong-clone.git`

3. Navigate to the project directory:
    - `cd pong`



4. Compile the game:
- On Windows:
  ```
  g++ -o pong.exe src\main.cpp -Iexternal -lraylib -lopengl32 -lgdi32 -lwinmm -static -std=c++11
  ```

- On macOS:
  ```
  g++ -o pong src/main.cpp -Iexternal -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -std=c++11
  ```

- On Linux:
  ```
  g++ -o pong pong.cpp -Iexternal -lraylib -lGL -lm -lpthread -ldl -lrt -std=c++11
  ```

5. Run the game:
- On Windows:
  ```
  .\pong.exe
  ```

- On macOS and Linux:
  ```
  ./pong
  ```

## Acknowledgements

This game is based on the classic Pong game and was created using the raylib library.


