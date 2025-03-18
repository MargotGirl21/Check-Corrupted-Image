#ifndef CHECKSUMS_H 
#define CHECKSUMS_H

#include <string>
#include <vector>

class checkSums {
    public:
    int checkSumReader(std::string file);
    std::vector<int> getChecked();
    std::vector<int> checkedSums;

};

#endif
