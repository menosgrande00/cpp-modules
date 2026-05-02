# 🚀 C++ Modules (00 - 09): Journey to Object-Oriented Programming

![C++](https://img.shields.io/badge/language-C++98-blue.svg)
![OOP](https://img.shields.io/badge/concept-OOP-orange.svg)
![STL](https://img.shields.io/badge/library-STL-lightgrey.svg)

## 📌 Overview
This repository contains a series of 10 modules (from `CPP00` to `CPP09`) developed as part of the 42 curriculum. The overarching goal of these modules is to transition from procedural programming in C to **Object-Oriented Programming (OOP)** in C++. 

To deeply understand the inner workings of the language, all projects are strictly written in **C++98 standard**. This restriction ensures a solid understanding of memory management, pointer manipulation, and class architecture before relying on modern C++ syntactic sugar (like smart pointers or `auto`).

## 🧠 Core Competencies Acquired
Throughout these 10 modules, I have developed a strong foundation in:
* **Object-Oriented Design:** Encapsulation, Abstraction, Inheritance, and Polymorphism.
* **Orthodox Canonical Class Form (OCCF):** Enforced strict class structures including default constructors, copy constructors, copy assignment operators, and destructors for safe memory handling.
* **Memory Management:** Safe dynamic allocation/deallocation using `new` and `delete`, preventing memory leaks and deep vs. shallow copy issues.
* **Exception Handling:** Using `try`, `catch`, and custom exception classes for robust error management.
* **Generic Programming:** Designing flexible and reusable code using C++ `templates`.
* **Standard Template Library (STL):** Advanced usage of containers (Vectors, Maps, Lists, Stacks) and algorithms to solve complex computational problems.

## 🗂️ Modules Breakdown

Here is a summary of the concepts tackled in each specific module:

### [CPP 00] Basics & Encapsulation
* Introduction to C++ syntax, standard input/output streams (`std::cin`, `std::cout`).
* Namespaces, classes, member functions, and instance variables.
* **Project Highlight:** A retro phonebook application demonstrating basic encapsulation.

### [CPP 01] Memory Allocation & Pointers
* Dynamic memory allocation (`new` and `delete`).
* Pointers to members, References, and the `switch` statement.
* Understanding stack vs. heap memory in an OOP context.

### [CPP 02] Ad-hoc Polymorphism & Operator Overloading
* Introduction to the **Orthodox Canonical Class Form**.
* Operator overloading (`+`, `-`, `*`, `/`, `<<`, etc.).
* Fixed-point numbers and floating-point arithmetic representation.

### [CPP 03] Inheritance
* Class derivation and access specifiers (`public`, `protected`, `private`).
* Constructor and destructor execution order in inheritance chains.
* **Project Highlight:** A role-playing game character system (Claptrap/Scavtrap) demonstrating parent-child class relationships.

### [CPP 04] Subtype Polymorphism & Abstract Classes
* Virtual functions, pure virtual functions, and abstract classes.
* Interfaces and deep copying of polymorphic objects.
* Overriding behaviors at runtime.

### [CPP 05] Exception Handling
* Building robust programs using `try/catch` blocks.
* Creating custom exceptions extending `std::exception`.
* **Project Highlight:** A hierarchical bureaucracy simulation managing varying grades and permission levels securely.

### [CPP 06] Type Casting
* Deep dive into C++ casting operators.
* `static_cast` (compile-time conversions).
* `dynamic_cast` (safe downcasting in polymorphic hierarchies).
* `reinterpret_cast` (low-level reinterpreting of bit patterns).
* `const_cast` (removing constness).

### [CPP 07] Templates
* Introduction to generic programming.
* Function templates and Class templates.
* Creating type-independent data structures and algorithms.

### [CPP 08] Templated Containers, Iterators, Algorithms
* Utilizing STL (Standard Template Library) containers.
* Iterators as a bridge between containers and algorithms.
* Implementing and utilizing standard algorithms (e.g., `std::for_each`, `std::find`).

### [CPP 09] Advanced STL Data Structures
* Solving complex algorithmic challenges strictly using STL containers.
* **Bitcoin Exchange:** Data parsing, date management, and relational mapping using `std::map`.
* **Reverse Polish Notation (RPN):** Expression evaluation using `std::stack`.
* **PmergeMe:** Implementing the **Ford-Johnson algorithm** (merge-insert sort) to sort thousands of elements efficiently using multiple containers (e.g., `std::vector` and `std::deque`) to compare performance.

## 🛠️ Compilation & Usage

Each module is contained within its own directory and includes a standard `Makefile`.

### General Instructions
1. Navigate into any module/exercise directory (e.g., `cd cpp04/ex00`).
2. Compile the source code using `make`:
   ```bash
   make
   ```
3. Run the compiled executable (name varies per exercise, check the Makefile or prompt)
   ```bash
   ./<executable_name>
   ```
