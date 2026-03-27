#include <iostream>
#include <memory>
#include <string>

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
