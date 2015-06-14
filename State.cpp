//
// Created by Don Browne on 14/06/15.
//

#include "State.h"

State::State(size_t tape_length) {
    tape = std::unique_ptr<std::vector<unsigned char> >(new std::vector<unsigned char>(tape_length));
    size = tape_length;
}

size_t State::get_size() {
    return size;
}

size_t State::get_index() {
    return index;
}

void State::next() {
    index++;
}

void State::prev() {
    index--;
}

void State::write(unsigned char val) {
    (*tape)[index] = val;
}

unsigned char State::read() {
    return (*tape)[index];
}

void State::incr() {
    (*tape)[index]++;
}

void State::decr() {
    (*tape)[index]--;
}