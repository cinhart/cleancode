#include "random.h"

#include <fstream>
#include <iostream>
#include <vector>

int randint(int min, int max) {
    static std::default_random_engine  generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{min, max};
    return distribution(generator);
}

std::vector<std::string> fileIntoArray(std::string path) {
    std::vector<std::string> outputArray;
    std::string line;

    std::ifstream file(path);

    if(!file.fail()){
        while(std::getline(file, line)){
        //std::cout << line << "\n";
        outputArray.push_back(line);
        }       
    }

    else {
        std::cerr << "Couldn't load file at " << path << std::endl;
        std::vector<std::string> backupArray = {"dinosaur","ruby","pokemon","alternate","monkey","cupcake","quantum","superman","desk",
        "anticonstitution", "helpful", "minecraft", "kingdom", "superficial", "computer", "networks", "banana", "friendship", "pikachu"};
        outputArray.insert(outputArray.end(), backupArray.begin(), backupArray.end());
    }

    return outputArray;
}

std::string randword() {
    std::vector<std::string> wordList = fileIntoArray("assets/wordList.txt");
    return wordList[randint(0, wordList.size()-1)];
}