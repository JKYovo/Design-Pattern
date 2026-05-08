# 设计模式与 C++ 学习笔记

这个项目用 C++ 小例子整理设计模式。代码尽量保持一个模式一个目录、一个示例可以单独编译运行，案例风格延续之前的《海贼王》角色和场景，方便把抽象结构和具体故事对应起来。

项目目前包含 GoF 23 种设计模式，另外保留了一个常见但不属于 GoF 23 种的简单工厂模式。

## 如何运行

每个示例都是独立的 `.cpp` 文件，可以直接用 `g++` 编译：

```bash
g++ -std=c++11 "Design pattern/22.State Pattern/state.cpp" -o state
./state
```

如果目录里有 `.md` 文件，可以先读说明，再看代码里的类关系和调用流程。

## 目录索引

### 创建型模式

| 序号 | 模式 | 目录 | 说明 |
| --- | --- | --- | --- |
| 1 | 简单工厂模式 | [1.Simple Factory Pattern](Design%20pattern/1.Simple%20Factory%20Pattern) | 用一个工厂根据条件创建对象，学习价值高，但不属于 GoF 23 种。 |
| 2 | 工厂方法模式 | [2.Factory Pattern](Design%20pattern/2.Factory%20Pattern) | 把对象创建延迟到子类。 |
| 3 | 抽象工厂模式 | [3.Abstract Factory Pattern](Design%20pattern/3.Abstract%20Factory%20Pattern) | 创建一组相关对象。 |
| 4 | 单例模式 | [4.Singleton Pattern](Design%20pattern/4.Singleton%20Pattern) | 保证一个类只有一个实例。 |
| 5 | 原型模式 | [5.Prototype Pattern](Design%20pattern/5.Prototype%20Pattern) | 通过克隆已有对象创建新对象。 |
| 6 | 生成器模式 | [6.Builder Pattern](Design%20pattern/6.Builder%20Pattern) | 分步骤构建复杂对象。 |

### 结构型模式

| 序号 | 模式 | 目录 | 说明 |
| --- | --- | --- | --- |
| 7 | 适配器模式 | [7.Adapter Pattern](Design%20pattern/7.Adapter%20Pattern) | 把不兼容接口转换成客户端期望的接口。 |
| 8 | 组合模式 | [8.Composite Pattern](Design%20pattern/8.Composite%20Pattern) | 用树形结构表示整体和部分。 |
| 9 | 装饰器模式 | [9.Decorator Pattern](Design%20pattern/9.Decorator%20Pattern) | 动态给对象叠加新能力。 |
| 10 | 代理模式 | [10.Proxy Pattern](Design%20pattern/10.Proxy%20Pattern) | 通过代理对象控制对真实对象的访问。 |
| 15 | 桥接模式 | [15.Bridge Pattern](Design%20pattern/15.Bridge%20Pattern) | 拆分抽象和实现，让两个维度独立变化。 |
| 16 | 外观模式 | [16.Facade Pattern](Design%20pattern/16.Facade%20Pattern) | 给复杂子系统提供统一入口。 |
| 17 | 享元模式 | [17.Flyweight Pattern](Design%20pattern/17.Flyweight%20Pattern) | 共享大量相似对象的内部状态。 |

### 行为型模式

| 序号 | 模式 | 目录 | 说明 |
| --- | --- | --- | --- |
| 11 | 观察者模式 | [11.Observer Pattern](Design%20pattern/11.Observer%20Pattern) | 对象状态变化时通知订阅者。 |
| 12 | 策略模式 | [12.Strategy Pattern](Design%20pattern/12.Strategy%20Pattern) | 把算法封装起来并可互换。 |
| 13 | 模板方法模式 | [13.Template Pattern](Design%20pattern/13.Template%20Pattern) | 在父类定义流程骨架，子类实现细节。 |
| 14 | 命令模式 | [14.Command Pattern](Design%20pattern/14.Command%20Pattern) | 把请求封装成命令对象。 |
| 18 | 责任链模式 | [18.Chain of Responsibility Pattern](Design%20pattern/18.Chain%20of%20Responsibility%20Pattern) | 请求沿处理链传递，直到被处理。 |
| 19 | 迭代器模式 | [19.Iterator Pattern](Design%20pattern/19.Iterator%20Pattern) | 不暴露集合内部结构也能遍历元素。 |
| 20 | 中介者模式 | [20.Mediator Pattern](Design%20pattern/20.Mediator%20Pattern) | 用中介对象管理多个对象之间的交互。 |
| 21 | 备忘录模式 | [21.Memento Pattern](Design%20pattern/21.Memento%20Pattern) | 保存并恢复对象历史状态。 |
| 22 | 状态模式 | [22.State Pattern](Design%20pattern/22.State%20Pattern) | 对象行为随内部状态改变。 |
| 23 | 访问者模式 | [23.Visitor Pattern](Design%20pattern/23.Visitor%20Pattern) | 把新操作封装到访问者中。 |
| 24 | 解释器模式 | [24.Interpreter Pattern](Design%20pattern/24.Interpreter%20Pattern) | 为简单语言定义语法并解释执行。 |

## 建议学习顺序

1. 先看创建型模式：理解对象创建为什么要和业务代码解耦。
2. 再看结构型模式：理解类和对象如何组合得更灵活。
3. 最后看行为型模式：理解对象之间如何协作、通知、切换行为。

## 备注

- 目录中已有的 `.exe` 是历史编译产物，不影响源码阅读。
- 部分旧 `.cpp` 文件使用了不同编码，终端里可能出现乱码，但不影响设计模式结构本身。
- 新增示例使用 `C++11` 标准，并尽量用 `unique_ptr`、`shared_ptr` 管理示例对象生命周期。
