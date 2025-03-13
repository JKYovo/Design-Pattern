设计模式与 C++ 特性学习项目
================

本项目旨在通过代码案例、UML 图和详细解释，帮助开发者深入理解 23 种设计模式，并学习 C++ 的一些高级特性。无论你是初学者还是有经验的开发者，都可以通过本项目提升对设计模式和 C++ 的理解。

* * * *

​**项目内容**
---------

### 1\. ​**23 种设计模式的代码案例**

-   每种设计模式都有对应的 C++ 实现代码。
-   代码简洁明了，注释详细，便于理解。

### 2\. ​**部分 UML 图**

-   提供了关键设计模式的 UML 类图，帮助理解类之间的关系。
-   UML 图使用 PlantUML 绘制。

### 3\. ​**设计模式的解释**

-   对每种设计模式的核心思想、应用场景、优缺点进行详细说明。
-   结合实际案例，帮助理解设计模式的实际应用。

### 4\. ​**C++ 特性的学习**

-   结合设计模式，学习 C++ 的一些高级特性，如：
    -   智能指针（`std::unique_ptr`, `std::shared_ptr`）
    -   Lambda 表达式
    -   模板编程
    -   移动语义（Move Semantics）
    -   右值引用（Rvalue References）

* * * *

​**项目结构**
---------

```
Design-Patterns-CPP/
├── CreationalPatterns/         # 创建型模式
│   ├── Singleton/              # 单例模式
│   ├── FactoryMethod/          # 工厂方法模式
│   ├── AbstractFactory/        # 抽象工厂模式
│   ├── Builder/                # 建造者模式
│   └── Prototype/              # 原型模式
├── StructuralPatterns/         # 结构型模式
│   ├── Adapter/                # 适配器模式
│   ├── Bridge/                 # 桥接模式
│   ├── Composite/              # 组合模式
│   ├── Decorator/              # 装饰器模式
│   ├── Facade/                 # 外观模式
│   ├── Flyweight/              # 享元模式
│   └── Proxy/                  # 代理模式
├── BehavioralPatterns/         # 行为型模式
│   ├── ChainOfResponsibility/  # 责任链模式
│   ├── Command/                # 命令模式
│   ├── Iterator/               # 迭代器模式
│   ├── Mediator/               # 中介者模式
│   ├── Memento/                # 备忘录模式
│   ├── Observer/               # 观察者模式
│   ├── State/                  # 状态模式
│   ├── Strategy/               # 策略模式
│   ├── TemplateMethod/         # 模板方法模式
│   └── Visitor/                # 访问者模式
├── UML/                        # UML 图
│   ├── Singleton.puml          # 单例模式 UML 图
│   ├── FactoryMethod.puml      # 工厂方法模式 UML 图
│   └── ...                     # 其他 UML 图
├── CppFeatures/                # C++ 特性学习
│   ├── SmartPointers/          # 智能指针
│   ├── LambdaExpressions/      # Lambda 表达式
│   ├── Templates/              # 模板编程
│   └── MoveSemantics/          # 移动语义
├── README.md                   # 项目说明
└── CMakeLists.txt              # CMake 配置文件
```
