#include <iostream>
#include <memory>
#include <string>

// Pros of Decorator:
// 1. Adds new behavior without changing existing classes.
// 2. Features can be combined flexibly at runtime.
// 3. Avoids creating many subclasses for every possible combination.
// 4. Follows the open/closed principle well.
// 5. Keeps the same interface for both basic objects and decorated objects.

// Cons of Decorator:
// 1. Introduces more small classes into the design.
// 2. Nested wrapping can make object creation harder to read.
// 3. Debugging can be harder because behavior is spread across layers.
// 4. The order of decorators may affect the final result.
// 5. Can feel over-engineered for very small programs.

struct Coffee{
    virtual int cost() const = 0;
    virtual std::string desc() const = 0;
    virtual ~Coffee() = default;
};

struct Espresso : Coffee{
    int cost() const override{return 2;}
    std::string desc() const override{return "Espresso";}
};

struct AddOn : Coffee{
    std::shared_ptr<Coffee> inner;
    AddOn(std::shared_ptr<Coffee> c) : inner(std::move(c)){}
};

struct Milk : AddOn{
    using AddOn::AddOn;
    int cost() const override{return inner->cost() + 1;}
    std::string desc() const override{return inner->desc() + " + milk";}
};

struct Caramel : AddOn{
    using AddOn::AddOn;
    int cost() const override{return inner->cost() + 2;}
    std::string desc() const override{return inner->desc() + " + caramel";}
};

int main(){
    auto drink = std::make_shared<Caramel>(
        std::make_shared<Milk>(
            std::make_shared<Espresso>(
            )
        )
    );
    std::cout << drink->desc() << " $" << drink->cost() << std::endl;
    // Espresso + milk + caramel $5
    return 0;

}

