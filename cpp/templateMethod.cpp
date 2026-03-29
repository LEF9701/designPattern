#include <iostream>

// Pros of Template Method:
// 1. Defines a fixed overall workflow in one place.
// 2. Lets subclasses customize only specific steps of the algorithm.
// 3. Encourages code reuse by sharing common logic in the base class.
// 4. Keeps the high-level process consistent across different subclasses.
// 5. Works well when many classes follow the same procedure with small variations.

// Cons of Template Method:
// 1. Relies on inheritance, so flexibility is lower than composition-based designs.
// 2. Changes to the base algorithm can affect all subclasses.
// 3. Subclasses are tightly coupled to the parent class structure.
// 4. Too many overridable steps can make the design harder to understand.
// 5. Can feel excessive for very simple workflows.


struct DataMiner{
    void mine(){
        openFile();
        extractData();
        parseData();
        analyzeData();
        closeFile();
    }

    virtual void openFile() = 0;
    virtual void extractData() = 0;
    virtual void parseData() = 0;

    // Default steps (subclass may override)
    virtual void analyzeData(){std::cout << "Analyzing..." << std::endl;}
    virtual void closeFile(){std::cout << "File closed." << std::endl;}
    virtual ~DataMiner() = default;
};

struct CSVMiner : DataMiner{
    void openFile() override{std::cout << "OpenCSV" << std::endl;}
    void extractData() override{std::cout << "Extract CSV rows." << std::endl;}
    void parseData() override{std::cout << "Parse commas." << std::endl;}
};

int main(){
    CSVMiner miner;
    miner.mine();

    return 0;
}
