#include <iostream>

// Pros of Singleton:
// 1. Ensures that only one instance of the class exists.
// 2. Provides a global access point to that instance.
// 3. Useful for shared resources such as logger, configuration, or manager objects.
// 4. Avoids repeated creation of the same service object.
// 5. Lifetime is controlled in one place.

// Cons of Singleton:
// 1. Introduces global state, which can make code harder to reason about.
// 2. Increases coupling because many parts of the program may depend on the same global object.
// 3. Makes testing harder, especially when mocking or resetting state is needed.
// 4. Can hide dependencies instead of passing them explicitly.
// 5. Often overused in simple programs where normal objects would be clearer.


class Logger{
    private:
        Logger(){std::cout << "Logger created\n";}
    public:
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        static Logger& getInstance(){
            static Logger instance;
            return instance;
        }

        void log(const std::string& msg){
            std::cout << "[LOG]" << msg << std::endl;
        }
};

int main(){
    Logger::getInstance().log("App started");
    Logger::getInstance().log("Another message");
    
    Logger& l1 = Logger::getInstance();
    l1.log("This is l1");
    Logger& l2 = Logger::getInstance();
    l2.log("This is l2");

    return 0;
}
