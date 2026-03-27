#include <iostream>
#include <memory>

// Pros of Prototype:
// 1. Creates new objects by copying existing ones.
// 2. Useful when object creation is expensive or complicated.
// 3. Supports polymorphic copying through a common base class.
// 4. Reduces the need to repeatedly write initialization code.
// 5. Convenient when many similar objects need to be created.

// Cons of Prototype:
// 1. Requires a clone() function in each derived class.
// 2. Can be harder to understand than direct construction.
// 3. Deep copy may be difficult if the object owns complex resources.
// 4. Copying may accidentally duplicate unwanted internal state.
// 5. Can be unnecessary if normal constructors are already simple.

struct Enemy{
    std::string type;
    int health;

    virtual std::unique_ptr<Enemy> clone() const = 0;
    virtual void show() const{
        std::cout << type << "hp= " << health << std::endl;
    }
    virtual ~Enemy() = default;
};

struct Goblin : Enemy{
    Goblin(int hp) { type = "Goblin"; health = hp;}
    std::unique_ptr<Enemy> clone() const override{
        return std::make_unique<Goblin>(*this); //copy ctor
    }
};

int main(){
    Goblin proto(80);
    auto g1 = proto.clone();
    auto g2 = proto.clone();
    g1->show();
    g2->show();

    return 0;
}
