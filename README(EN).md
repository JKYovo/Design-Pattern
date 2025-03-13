Design Patterns and C++ Features Learning Project
=================================================

This project aims to help developers deeply understand the 23 design patterns and learn some advanced C++ features through code examples, UML diagrams, and detailed explanations. Whether you are a beginner or an experienced developer, this project will enhance your understanding of design patterns and C++.

* * * *

​**Project Content**
--------------------

### 1\. ​**Code Examples for 23 Design Patterns**

-   Each design pattern is accompanied by a corresponding C++ implementation.
-   The code is concise, well-commented, and easy to understand.

### 2\. ​**Partial UML Diagrams**

-   Provides UML class diagrams for key design patterns to help understand the relationships between classes.
-   UML diagrams are created using PlantUML.

### 3\. ​**Explanations of Design Patterns**

-   Detailed explanations of the core concepts, use cases, advantages, and disadvantages of each design pattern.
-   Practical examples are included to help understand real-world applications of design patterns.

### 4\. ​**Learning C++ Features**

-   Combines design patterns with learning advanced C++ features, such as:
    -   Smart pointers (`std::unique_ptr`, `std::shared_ptr`)
    -   Lambda expressions
    -   Template programming
    -   Move semantics
    -   Rvalue references

* * * *

​**Project Structure**
----------------------

```
Design-Patterns-CPP/
├── CreationalPatterns/         # Creational Patterns
│   ├── Singleton/              # Singleton Pattern
│   ├── FactoryMethod/          # Factory Method Pattern
│   ├── AbstractFactory/        # Abstract Factory Pattern
│   ├── Builder/                # Builder Pattern
│   └── Prototype/              # Prototype Pattern
├── StructuralPatterns/         # Structural Patterns
│   ├── Adapter/                # Adapter Pattern
│   ├── Bridge/                 # Bridge Pattern
│   ├── Composite/              # Composite Pattern
│   ├── Decorator/              # Decorator Pattern
│   ├── Facade/                 # Facade Pattern
│   ├── Flyweight/              # Flyweight Pattern
│   └── Proxy/                  # Proxy Pattern
├── BehavioralPatterns/         # Behavioral Patterns
│   ├── ChainOfResponsibility/  # Chain of Responsibility Pattern
│   ├── Command/                # Command Pattern
│   ├── Iterator/               # Iterator Pattern
│   ├── Mediator/               # Mediator Pattern
│   ├── Memento/                # Memento Pattern
│   ├── Observer/               # Observer Pattern
│   ├── State/                  # State Pattern
│   ├── Strategy/               # Strategy Pattern
│   ├── TemplateMethod/         # Template Method Pattern
│   └── Visitor/                # Visitor Pattern
├── UML/                        # UML Diagrams
│   ├── Singleton.puml          # UML Diagram for Singleton Pattern
│   ├── FactoryMethod.puml      # UML Diagram for Factory Method Pattern
│   └── ...                     # Other UML Diagrams
├── CppFeatures/                # C++ Features Learning
│   ├── SmartPointers/          # Smart Pointers
│   ├── LambdaExpressions/      # Lambda Expressions
│   ├── Templates/              # Template Programming
│   └── MoveSemantics/          # Move Semantics
├── README.md                   # Project Description
└── CMakeLists.txt              # CMake Configuration File
```