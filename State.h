//
// Created by Don Browne on 14/06/15.
//

#ifndef BF_STATE_H
#define BF_STATE_H

#include <memory>
#include <vector>

class State {
private:
    std::unique_ptr<std::vector<unsigned char> > tape;
    size_t index;
    size_t size;
public:
    State(size_t tape_length);
    ~State() {};

    size_t get_size();
    size_t get_index();
    void next();
    void prev();
    void write(unsigned char val);
    unsigned char read();
    void incr();
    void decr();
};

#endif //BF_STATE_H
