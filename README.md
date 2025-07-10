# Embedded C Design Patterns

This repository contains examples of design patterns implemented in embedded C. The goal is to demonstrate how common design patterns can be applied in the context of embedded systems programming.

The examples were developed based on the Martin K. Schröder course "Design Patterns in Embedded C" available on [Udemy](https://www.udemy.com/course/embedded-c-programming-design-patterns/?srsltid=AfmBOoq7tYXLs5xy7H3ZCYdd2eG4GdPBi336JkoWeg7D51fpguUF-v9z&couponCode=ST4MT20725A) (also available on YouTube).

## Patterns

### Object pattern

The object pattern is a design pattern that encapsulates data and behavior in a single structure, similar to an object in object-oriented programming. It allows for better organization of code and promotes encapsulation. The object pattern was implemented in the `object` source and header files.

### Interface pattern

The interface pattern defines a contract for behavior that can be implemented by different objects. It allows for polymorphism and decouples the code from specific implementations. The interface pattern was implemented in the `interface` source and header files.

### Singleton object pattern

The singleton object pattern ensures that a class has only one instance and provides a global point of access to it. This is useful in embedded systems where resources are limited and you want to avoid multiple instances of a resource-intensive object. The singleton pattern was implemented in the `singleton` source and header files.

### Opaque object pattern

The opaque object pattern is a design pattern that hides the implementation details of an object from the user. It provides a clean interface for interacting with the object while keeping its internal structure hidden. This pattern is useful for encapsulating complex data structures and providing a simple API for users. The opaque object pattern was implemented in the `opaque` source and header files. This patter allows for the creation of multiple instances of the same object type.

## Factory pattern

The factory pattern is a creational design pattern that provides an interface for creating different objects with a common base interface. It allows for flexibility in object creation based on the available types. The factory pattern was implemented in the `factory` source and header files.

## Prerequisites

To build and run this project locally, make sure you have the following installed:

- A C compiler (`clang` or `gcc`)
- [`make`](https://www.gnu.org/software/make/)
- [`cmake`](https://cmake.org/) (only if using CMake-based build)

You may check if you have these tools installed by running:

```bash
gcc --version
clang --version
make --version
cmake --version
```

## Building the Project

You may build and run the project using the provided `run.sh` script. This script will compile the project and execute the resulting binary.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
