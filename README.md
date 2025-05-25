# Tetris C++

## Additional Information

This project uses **C++14** with **CMake** 3.27.

To compile the project, the operating system must have the following libraries installed:

* libpng  
* SDL2  
* SDL2_ttf  
* SDL2_image  

## How to Run

The program is compatible with all platforms.

### Steps

Clone the repository:

```
git clone git@github.com:asanme/tetris-cpp.git
```

Go to the repository folder:

```
cd tetris-cpp
```

Run `cmake` and specify the name of the folder where the necessary compilation files will be generated:

```
cmake -B build-folder
```

Go to the generated folder:

```
cd build-folder
```

Finally, compile:

```
make
```

Inside the folder, you will find the executable `tetris_cpp`.