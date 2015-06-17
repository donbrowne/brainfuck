//
// Created by Don Browne on 14/06/15.
//

#include "AbstractMachine.h"

AbstractMachine::AbstractMachine(size_t tape_length) {
    tape = std::unique_ptr<std::vector<unsigned char> >(new std::vector<unsigned char>(tape_length));
    size = tape_length;
}

void AbstractMachine::next() {
    index++;
}

void AbstractMachine::prev() {
    index--;
}

void AbstractMachine::write(unsigned char val) {
    (*tape)[index] = val;
}

unsigned char AbstractMachine::read() {
    return (*tape)[index];
}

void AbstractMachine::incr() {
    (*tape)[index]++;
}

void AbstractMachine::decr() {
    (*tape)[index]--;
}