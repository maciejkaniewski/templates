# templates

templates is a project I realized in the second semester of my studies within the Object Oriented Programming course at the Wroclaw University of Technology in the field of Control Engineering and Robotics. The main goal of this task was to combine the existing [linear-equation-systems](https://github.com/maciejkaniewski/linear-equation-systems.git) program with a part of the [complex-number-test](https://github.com/maciejkaniewski/complex-number-test.git) program to get the possibility of solving equation systems with complex numbers. For this purpose, the functionalities of the templates had to be used.

## Table of Contents

  - [Features](#features)
  - [Setup](#setup)
  - [Usage](#usage)
  - [Concepts I Learned](#concepts-i-learned)
  
## Features

- Solve systems of equations with a user-defined number of unknowns
- Solve equation systems in real or complex domain
- Load equation systems as text files
- Identification of the domain of equation systems based on the input file

## Setup
Prerequisites:
* Installed CMake *(minimum VERSION 3.0)*,

Clone repository:

    git clone https://github.com/maciejkaniewski/templates.git

Create `build` directory and launch `CMake`:

    cd templates
    mkdir build
    cd build
    cmake ..

Run `make` command and execute the program. Redirect the data file to the program input:

    make
    ./Templates < ../data/4_SYSTEM5C.DAT

If the data file has not been redirected to the program input, the data has to be entered manually, which is not a very convenient method.
If at the beginning of the input data file there is no character identifying the system domain the following message will be displayed:

    No options to define the type of input data.
    Available:  R, C.

## Usage

After successfully starting the program, the following result appears in the terminal:

    System of equations:

    | (2+3i) (0+1i) (1+0i) (2-1i) (2-5i) |   |x_1|   | (0+12i) |
    | (0+5i) (4-2i) (1+0i) (0+4i) (5-4i) |   |x_2|   | (1+2i) |
    | (0+3i) (5+0i) (2+0i) (0+1i) (0+13i) | * |x_3| = | (0+4i) |
    | (2+12.76i) (0+5i) (0+13i) (1+0i) (2+0i) |   |x_4|   | (2+3i) |
    | (1.23-5.234i) (59+21.22i) (5+0i) (1+0i) (3+0i) |   |x_5|   | (0+1i) |

    Solution x = ((2.53213-1.07722i), (0.316153+0.0563241i), (-2.2519+1.00576i), (-3.01023+0.580133i), (-0.221484-0.0208837i))

### Changing size of equation system

The size of the equation can be changed in the `vector.hh` file:

```C++
#ifndef VECTOR_HH
#define VECTOR_HH

#define SIZE 5

.
.
.

#endif // VECTOR_HH
```

After changing the `SIZE` value, the program must be recompiled.

## Concepts I Learned

- Usage of templates.
