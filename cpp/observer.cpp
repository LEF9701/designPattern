#include <iostream>
#include <vector>
#include <functional>

// Pros:
// 1. Simple way to notify many listeners.
// 2. Emitter does not need to know concrete listener types.
// 3. Easy to use with lambdas.
// 4. Flexible because std::function can store many callable forms.
// 5. Useful for event-driven design.

// Cons:
// 1. No unsubscribe support.
// 2. std::function may add runtime overhead.
// 3. Harder to trace flow in large systems.
// 4. All listeners must match the same function signature.
// 5. No listener priority or filtering.

class EventEmitter{
    std::vector<std::function<void(int)>> listeners;
    public:
        void subscribe(std::function<void(int)> fn){
            listeners.push_back(fn);
        }

        void emit(int value){
            for(auto& fn : listeners) fn(value);
        }
};

int main(){
    EventEmitter emitter;

    emitter.subscribe([](int v){std::cout << "Listener A got: " << v << std::endl;});
    emitter.subscribe([](int v){std::cout << "Listener B got: " << v << std::endl;});

    emitter.emit(42);
    emitter.emit(99);
    return 0;
}
