#include <iostream>
#include <string>
// Pros of Adapter:
// 1. Lets incompatible interfaces work together.
// 2. Reuses existing legacy code without modifying it.
// 3. Keeps client code dependent on the new target interface only.
// 4. Improves flexibility when integrating third-party or old components.
// 5. Helps isolate interface conversion logic in one place.

// Cons of Adapter:
// 1. Adds an extra wrapper class.
// 2. Can make the design more complex in very small programs.
// 3. May introduce slight overhead because calls go through another layer.
// 4. Too many adapters can make the codebase harder to follow.
// 5. Does not improve the old class itself, it only hides incompatibility.



// Legacy interface
struct OldPrinter{
    void printOld(const std::string& text){
        std::cout << "[old]" << text << std::endl;
    }
};

// Target interface the client expects
struct Printer{
    virtual void print(const std::string& text) = 0;
    virtual ~Printer() = default;
};

// Adapter wraps OldPrinter, exposes Printer
struct PrinterAdapter : Printer{
    OldPrinter legacy;
    void print(const std::string& text) override{
        legacy.printOld(text); // delegate to old API
    }
};

void clientCode(Printer& p){p.print("Hello!");}

int main(){
    PrinterAdapter adapter;
    clientCode(adapter);

    return 0;
}
