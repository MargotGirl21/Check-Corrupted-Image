#include "imageReader.h"
#include<iostream>
#include <fstream>

int imageReader::readImage(std::string file) {
    sums.clear();
    
    std::ifstream reader = std::ifstream(file);
    if (!reader.is_open()) {
        std::cerr << "Error: unable to open file." << std::endl;
        return -1;
    }

    std:: string header;
    reader >> header;
    
    if (header != "P3") {
        std:: cerr << "Error: Incorrect ppm header";
        reader.close();
        return -1;
    }
    
        int width, height, maxPixelValue;

        if (!(reader >> width) || width <= 0) {
            std::cerr << "Error: no width in the file" << std::endl;
            reader.close();
            return -1;
        }

        if (!(reader >> height) || height <= 0) {
            std::cerr << "Error: no height found" << std::endl;
            reader.close();
            return -1;
        }
        if (!(reader >> maxPixelValue) || maxPixelValue <= 0) {
            std::cerr << "Error: max pixel not found" << std::endl;
            reader.close();
            return -1;
        }

        int valuesToRead = width * height * 3;
        std::vector<int> numbers;

        for (int i = 0; i < valuesToRead; i++) {
            int currPixel;
            if (!(reader >> currPixel)) {
                std::cerr << "Error: no values to read" << std::endl;
                reader.close();
                return -1;
            }

            if (currPixel > maxPixelValue || currPixel < 0) {
                std::cerr << "Error: pixel value out of range." << std::endl;
                reader.close();
                return -1;
            }
            numbers.push_back(currPixel);
        }
        reader.close();

        for (int k = 0; k < height; k++) {
            int sum = 0;
            for (int j = width * 3 * k; j < width * 3 * (k + 1); j++) {
                sum += numbers[j];
        }
        sums.push_back(sum);
        }   
        return 0;   
    }

std:: vector<int> imageReader:: getSums() {
    return sums;
}

int imageReader:: fileChecker(const std::string& file, const std::string& extension) {
    if (file.length() >= extension.length() &&
        file.substr(file.length() - extension.length()) == extension) {
            return 0;
        }
        return -1;
}




