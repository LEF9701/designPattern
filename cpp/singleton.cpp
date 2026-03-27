#include <iostream>

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
