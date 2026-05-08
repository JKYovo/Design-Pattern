# Design Patterns and C++ Notes

This project collects small C++ examples for design patterns. The structure follows one pattern per directory, and each example can be compiled independently. The examples keep the earlier One Piece themed style so the abstract class relationships are easier to connect with concrete stories.

The project now covers all 23 GoF design patterns, plus Simple Factory as an extra learning example.

## Run An Example

Each `.cpp` file is standalone:

```bash
g++ -std=c++11 "Design pattern/22.State Pattern/state.cpp" -o state
./state
```

When a directory contains a `.md` file, read it first and then follow the class relationships in the code.

## Pattern Index

### Creational Patterns

| No. | Pattern | Directory | Note |
| --- | --- | --- | --- |
| 1 | Simple Factory | [1.Simple Factory Pattern](Design%20pattern/1.Simple%20Factory%20Pattern) | Extra example; useful, but not one of the GoF 23 patterns. |
| 2 | Factory Method | [2.Factory Pattern](Design%20pattern/2.Factory%20Pattern) | Let subclasses decide which concrete object to create. |
| 3 | Abstract Factory | [3.Abstract Factory Pattern](Design%20pattern/3.Abstract%20Factory%20Pattern) | Create families of related objects. |
| 4 | Singleton | [4.Singleton Pattern](Design%20pattern/4.Singleton%20Pattern) | Ensure only one instance exists. |
| 5 | Prototype | [5.Prototype Pattern](Design%20pattern/5.Prototype%20Pattern) | Create objects by cloning prototypes. |
| 6 | Builder | [6.Builder Pattern](Design%20pattern/6.Builder%20Pattern) | Build complex objects step by step. |

### Structural Patterns

| No. | Pattern | Directory | Note |
| --- | --- | --- | --- |
| 7 | Adapter | [7.Adapter Pattern](Design%20pattern/7.Adapter%20Pattern) | Convert an incompatible interface into the expected one. |
| 8 | Composite | [8.Composite Pattern](Design%20pattern/8.Composite%20Pattern) | Represent part-whole hierarchies as trees. |
| 9 | Decorator | [9.Decorator Pattern](Design%20pattern/9.Decorator%20Pattern) | Add responsibilities to objects dynamically. |
| 10 | Proxy | [10.Proxy Pattern](Design%20pattern/10.Proxy%20Pattern) | Control access to another object. |
| 15 | Bridge | [15.Bridge Pattern](Design%20pattern/15.Bridge%20Pattern) | Separate abstraction and implementation. |
| 16 | Facade | [16.Facade Pattern](Design%20pattern/16.Facade%20Pattern) | Provide one simple interface to a complex subsystem. |
| 17 | Flyweight | [17.Flyweight Pattern](Design%20pattern/17.Flyweight%20Pattern) | Share intrinsic state across many similar objects. |

### Behavioral Patterns

| No. | Pattern | Directory | Note |
| --- | --- | --- | --- |
| 11 | Observer | [11.Observer Pattern](Design%20pattern/11.Observer%20Pattern) | Notify subscribers when state changes. |
| 12 | Strategy | [12.Strategy Pattern](Design%20pattern/12.Strategy%20Pattern) | Encapsulate interchangeable algorithms. |
| 13 | Template Method | [13.Template Pattern](Design%20pattern/13.Template%20Pattern) | Define an algorithm skeleton in a base class. |
| 14 | Command | [14.Command Pattern](Design%20pattern/14.Command%20Pattern) | Encapsulate requests as command objects. |
| 18 | Chain of Responsibility | [18.Chain of Responsibility Pattern](Design%20pattern/18.Chain%20of%20Responsibility%20Pattern) | Pass requests along a handler chain. |
| 19 | Iterator | [19.Iterator Pattern](Design%20pattern/19.Iterator%20Pattern) | Traverse a collection without exposing its internals. |
| 20 | Mediator | [20.Mediator Pattern](Design%20pattern/20.Mediator%20Pattern) | Centralize communication between objects. |
| 21 | Memento | [21.Memento Pattern](Design%20pattern/21.Memento%20Pattern) | Save and restore object state. |
| 22 | State | [22.State Pattern](Design%20pattern/22.State%20Pattern) | Change behavior when internal state changes. |
| 23 | Visitor | [23.Visitor Pattern](Design%20pattern/23.Visitor%20Pattern) | Add operations through visitor objects. |
| 24 | Interpreter | [24.Interpreter Pattern](Design%20pattern/24.Interpreter%20Pattern) | Define and interpret a small language. |

## Suggested Order

1. Start with creational patterns to understand how object creation is decoupled.
2. Move to structural patterns to see how classes and objects are composed.
3. Finish with behavioral patterns to study collaboration, notification and state changes.

## Notes

- Existing `.exe` files are historical build outputs and are not required.
- Some older `.cpp` files use a different text encoding, so comments may look garbled in some terminals.
- New examples use `C++11` and prefer `unique_ptr` / `shared_ptr` for simple lifetime management.
