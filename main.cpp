#include <iostream>
#include "Program.h"

using namespace std;

int main() {
    Program pg(30000);
    string inp;

    while (getline(std::cin, inp)) {
        pg.add_to_program(inp);
        pg.execute();
    }
    return 0;
}
