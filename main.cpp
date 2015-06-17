#include <iostream>
#include "Interpreter.h"

using namespace std;

int main() {
    Interpreter interpreter(30000);
    string inp;

    while (getline(std::cin, inp)) {
        interpreter.add_to_program(inp);
        interpreter.execute();
    }
    return 0;
}
