#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <string>
#include <vector>

class imageReader {
    public:
    std::vector<int> sums = std::vector<int>();
    int readImage(std::string file);
    int fileChecker(const std::string& file, const std::string & extention);
    std::vector<int> getSums();
};

#endif