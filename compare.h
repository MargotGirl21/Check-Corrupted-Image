#ifndef COMPARE_H
#define COMPARE_H
#include "imageReader.h"
#include "checkSums.h"

class compare {
    private: 
    imageReader &reader;
    checkSums &checker;
    
    public: 
    int matchSums();
    compare(imageReader &r, checkSums &c)
    : reader(r), checker(c) {}

};
#endif
