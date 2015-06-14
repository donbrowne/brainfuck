//
// Created by Don Browne on 14/06/15.
//

#include <iostream>
#include "Program.h"

Program::Program(size_t state_size) {
    pc = 0;
    program = "";
    state = std::unique_ptr<State>(new State(state_size));
}

void Program::add_to_program(std::string fragment) {
    program += fragment;
}

void Program::reset() {
    pc = 0;
}

void Program::execute() {
    size_t len = program.length();
    for (; pc < len; pc++) {
        switch (program[pc]) {
            case '>':
                state->next();
                break;
            case '<':
                state->prev();
                break;
            case '+':
                state->incr();
                break;
            case '-':
                state->decr();
                break;
            case '.':
                std::cout << (int)state->read() << std::endl;
                break;
            case ',':
                unsigned char inp;
                std::cin >> inp;
                state->write(inp);
                break;
            case '[':
                if (state->read() != 0) {
                    // Scan ahead until the character after PC is [ or the next char is off the edge of the program
                    while ((++pc) + 1 < len && program[pc + 1] != '[');
                    if (pc >= len) {
                        std::cout << "Reached end of program looking for matching ]" << std::endl;
                        exit(1);
                    }
                } else {
                    jump_stack.push(pc);
                }
                break;
            case ']':
                if (jump_stack.empty()) {
                    std::cout << "Hit ] without matching [" << std::endl;
                    exit(1);
                } else {
                    pc = jump_stack.top() - 1;
                    jump_stack.pop();
                    continue;
                }
            default:
                break;
        }
    }
}
