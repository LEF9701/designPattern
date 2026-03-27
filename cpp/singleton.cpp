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

    return 0;
}

/*
OUTPUT:

Logger created
[LOG]App started
[LOG]Another message


*/
