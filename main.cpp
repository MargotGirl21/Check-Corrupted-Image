#include <iostream>
#include <string>
#include "imageReader.h"
#include "checkSums.h"
#include "compare.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr <<"Incorrect number of arguments";
        return -1;
    }
    std::string imageFile = argv[1];
    std::string checkSumsFile = argv[2];

    imageReader reader;
    checkSums checker;

    reader.fileChecker(imageFile, ".ppm");
    reader.fileChecker(checkSumsFile, "txt");

    if(reader.readImage(imageFile) != 0) {
        return -1;
    }
    if (checker.checkSumReader(checkSumsFile) != 0) {
        return -1;
    }

    compare matcher(reader, checker);
    int result = matcher.matchSums();

    return result;
}