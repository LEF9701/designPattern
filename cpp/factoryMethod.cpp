#include <iostream>
#include <memory>
#include <string>

// Pros of Factory Method / Factory:
// 1. Reduces coupling: client code depends on Shape, not Circle or Square.
// 2. Centralizes object creation logic in one place.
// 3. Easier to extend: adding a new shape usually only requires changing the factory.
// 4. Supports runtime selection of concrete object type.
// 5. Makes client code cleaner and more abstract.

// Cons of Factory Method / Factory:
// 1. Adds extra abstraction, which may be unnecessary for small programs.
// 2. Can make the design more complex than direct construction.
// 3. The factory may need modification whenever a new product type is added.
// 4. String-based selection like "circle" / "square" can be error-prone.
// 5. May hide simple construction behind indirection, reducing clarity for beginners.


// Product interface
struct Shape{
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

struct Circle : Shape{
    void draw() override{std::cout << "Circle\n";}
};

struct Square : Shape{
    void draw() override{std::cout << "Square\n";}
};

struct ShapeFactory{
    static std::unique_ptr<Shape> create(const std::string& type){
        if(type == "circle") return std::make_unique<Circle>();
        if(type == "square") return std::make_unique<Square>();
        return nullptr;
    }
};

int main() {
    auto s1 = ShapeFactory::create("circle");
    auto s2 = ShapeFactory::create("square");
    if(s1) s1->draw(); // Circle
    if(s2) s2->draw(); // Square
}
