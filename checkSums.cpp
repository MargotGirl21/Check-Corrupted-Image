#include "checkSums.h"
#include <iostream>
#include<fstream>

    int checkSums::checkSumReader(std::string file) {
        checkedSums.clear();
        
        std::ifstream reader = std::ifstream(file);

        if (!reader.is_open()) {
            std::cerr << "Error: Unable to open checksum file." << std:: endl;
            return -1;
        }
        int checked;

            while(reader >> checked) {
                if (checked < 0) {
                    std::cerr << "Error: no negative values allowed.";
                    reader.close();
                    return -1;
            }
            checkedSums.push_back(checked);
            
            }
            if (checkedSums.empty()) {
                std::cerr << "Error: No checksums found in file provided";
                reader.close();
                return -1;
            }
            reader.close();
            return 0;
    }

    std::vector<int> checkSums:: getChecked() {
        return checkedSums;
    };