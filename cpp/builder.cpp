#include <iostream>

// Pros of Builder:
// 1. Makes object construction more readable, especially with method chaining.
// 2. Good when an object has many optional fields.
// 3. Avoids long constructors with many parameters.
// 4. Lets each parameter be set step by step in a clear way.
// 5. Can add validation inside build() before creating the final object.

// Cons of Builder:
// 1. Adds extra code and an extra class.
// 2. Can be unnecessary for small and simple structs.
// 3. Makes the design more verbose than direct initialization.
// 4. Slightly increases complexity for beginners.
// 5. If overused, it can turn simple object creation into overengineering.

struct Pizza{
    std::string size, crust, topping;
    void show(){
        std::cout << size << " pizza, " << crust << " crust, " << topping << " topping" << std::endl;
    }
};

class PizzaBuilder{
    private:
        Pizza p;
    public:
        PizzaBuilder& setSize(const std::string& s){p.size = s; return *this;}
        PizzaBuilder& setCrust(const std::string& c){p.crust = c; return *this;}
        PizzaBuilder& setTopping(const std::string& t){p.topping = t; return *this;}
        Pizza build(){return p;}
};

int main(){
    Pizza pizza = PizzaBuilder()
                    .setSize("large")
                    .setCrust("thin")
                    .setTopping("mushrooms")
                    .build();
    pizza.show();

}
