//
// Created by Don Browne on 14/06/15.
//

#ifndef BF_STATE_H
#define BF_STATE_H

#include <memory>
#include <vector>

class AbstractMachine {
private:
    std::unique_ptr<std::vector<unsigned char> > tape;
    size_t index;
    size_t size;
public:
    AbstractMachine(size_t tape_length);
    ~AbstractMachine() {};

    void next();
    void prev();
    void write(unsigned char val);
    unsigned char read();
    void incr();
    void decr();
};

#endif //BF_STATE_H
