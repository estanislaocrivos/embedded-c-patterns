# Embedded C Design Patterns

This repository contains examples of design patterns implemented in embedded C. The goal is to demonstrate how common design patterns can be applied in the context of embedded systems programming.

The examples were developed based on the Martin K. Schröder course "Design Patterns in Embedded C" available on [Udemy](https://www.udemy.com/course/embedded-c-programming-design-patterns/?srsltid=AfmBOoq7tYXLs5xy7H3ZCYdd2eG4GdPBi336JkoWeg7D51fpguUF-v9z&couponCode=ST4MT20725A) (also available on YouTube).

## Patterns

### Object pattern

The object pattern is a design pattern that encapsulates data and behavior in a single structure, similar to an object in object-oriented programming. It allows for better organization of code and promotes encapsulation. The object pattern was implemented in the `object` source and header files.

### Interface pattern

The interface pattern defines a contract for behavior that can be implemented by different objects. It allows for polymorphism and decouples the code from specific implementations. The interface pattern was implemented in the `interface` source and header files. An example is provided in the `main` source file, where an interface is used to define a common behavior for different objects.

### Singleton object pattern

The singleton object pattern ensures that a class has only one instance and provides a global point of access to it. This is useful in embedded systems where resources are limited and you want to avoid multiple instances of a resource-intensive object. The singleton pattern was implemented in the `singleton` source and header files. An example is provided in the `main` source file, where a singleton object is created and used.

### Opaque object pattern

The opaque object pattern is a design pattern that hides the implementation details of an object from the user. It provides a clean interface for interacting with the object while keeping its internal structure hidden. This pattern is useful for encapsulating complex data structures and providing a simple API for users. The opaque object pattern was implemented in the `opaque` source and header files. This patter allows for the creation of multiple instances of the same object type. An example is provided in the `main` source file, where multiple instances of an opaque object are created and used.

### Factory pattern

The factory pattern is a creational design pattern that provides an interface for creating different objects with a common base interface. It allows for flexibility in object creation based on the available types. The factory pattern was implemented in the `factory` source and header files. An example is provided in the `main` source file, where a factory function creates instances of different objects based on the type requested.

### Callback (or Observer) pattern

The callback pattern, also known as the observer pattern, allows for the registration of callback functions that can be invoked when certain events occur. This is useful in embedded systems where you want to notify multiple components about specific events without tightly coupling them. The callback pattern was implemented in the `callback` source and header files. An example is provided in the `main` source file, where a UART driver (implemented on the `minimal_driver` library) notifies registered observers when a byte is received.

### Inheritance pattern

The inheritance pattern allows for the creation of derived classes that inherit properties and methods from a base class. This promotes code reuse and allows for polymorphism. The inheritance pattern was implemented in the `inheritance` source and header files. An example is provided in the `main` source file, where a derived object inherits from a base object and adds additional functionality.

### Virtual API pattern

The virtual API pattern is a design pattern that allows for the creation of a common interface for different implementations. It provides a way to define a set of functions that can be overridden by derived classes, enabling polymorphism. The virtual API pattern was implemented in the `virtual_api` source and header files, along with the `virtual_api_driver` source and header files which implement a minimal driver for the virtual API. An example is provided in the `main` source file, where a serial API is used to define a common behavior for different drivers.

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
