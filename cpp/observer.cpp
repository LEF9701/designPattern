#include <iostream>
#include <vector>
#include <functional>

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
