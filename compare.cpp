#include <iostream>
#include "checkSums.h"
#include "imageReader.h"
#include "compare.h"

    int compare:: matchSums() {
        std::vector<int> checkSums = checker.getChecked();
        std::vector<int> imageSums = reader.getSums();

        if (checkSums.empty() || imageSums.empty()) {
            std::cerr <<"Error: one or both files are empty." << std::endl;
            return -1;
        }

        if (checkSums.size() != imageSums.size()) {
            std::cerr << "Error: mismatched number of rows";
            return -1;
        }

        for (size_t i = 0; i < checkSums.size(); i++) {
                if (checkSums[i] != imageSums[i]) {
                    std::cerr << "Error in row: " << i << ". Image file sum is: " << imageSums[i]
                              << ", Check sum is: " << checkSums[i] << std::endl;
                    return -(i+2);
                }
        }

        std::cout << "Success." << std::endl;
        return 0;
        
};