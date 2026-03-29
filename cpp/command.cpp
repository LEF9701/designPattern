#include <iostream>
#include <stack>
#include <functional>
#include <string>

// Pros of Command:
// 1. Encapsulates an action as an object-like unit.
// 2. Makes undo functionality easy to implement.
// 3. Decouples the invoker from the actual operation logic.
// 4. Makes it easy to add new commands without changing existing code much.
// 5. Works well for history, logging, macro commands, and queued operations.

// Cons of Command:
// 1. Can introduce extra abstraction for simple actions.
// 2. Storing many commands may increase memory usage.
// 3. Undo logic can become complex for real-world operations.
// 4. Code can be harder to follow when behavior is hidden inside command objects.
// 5. May feel unnecessary in very small programs with only a few direct actions.


struct Command{
    std::function<void()> exec, undo;
};

class TextEditor{
    private:
        std::string text;
        std::stack<Command> history;
    public:
        void execute(Command cmd){
            cmd.exec();
            history.push(cmd);
        }
        void undoLast(){
            if(!history.empty()){
                history.top().undo();
                history.pop();
            }
        }
        void append(const std::string& s){
            Command cmd;
            cmd.exec = [this, s]{
                text += s;
                std::cout << "text: " << text << "\n";
            };
            cmd.undo = [this, s]{
                text.erase(text.size() - s.size());
                std::cout << "undo: " << text << "\n";
            };
            execute(cmd);
        }
};

int main(){
    TextEditor ed;
    ed.append("Hello");
    ed.append(", world");
    ed.undoLast(); // remove ", world"

    return 0;
}
