#include <iostream>
#include <memory>
#include <string>

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

