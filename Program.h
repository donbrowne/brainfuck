//
// Created by Don Browne on 14/06/15.
//

#ifndef BF_PROGRAM_H
#define BF_PROGRAM_H

#include <stack>
#include <string>
#include "State.h"

class Program {
private:
    size_t pc;
    std::stack<size_t> jump_stack;
    std::string program;
    std::unique_ptr<State> state;
public:
    Program(size_t state_size);
    ~Program() {};

    void add_to_program(std::string fragment);
    void execute();
    void reset();
};

#endif //BF_PROGRAM_H
