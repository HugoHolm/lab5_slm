#include "KGram.h"
#include "textgenerator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <k> <input.txt> <length> [seed_kgram]" << std::endl;
        return 1;
    }
    // Defining variables for later 
    std::string text;
    std::ifstream file;
    int k;
    std::string seed;
    int text_length;

    // Assigning value to variables from input 
    
    text_length = std::stoi(argv[3]);
    k = std::stoi(argv[1]);
    file.open(argv[2]);
    if (!file) {
        std::cerr << "Error: could not open textfile." << std::endl;
    return 1; 
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    text = buffer.str();

    if (argc == 5) {
        seed = argv[4];
        if (seed.size() != static_cast<std::size_t>(k)) {
            std::cerr << "<kgram_seed> must have same size as <k>" << std::endl; 
            return 1;
        }
    }
    else {
        if (text.size() < static_cast<size_t>(k)) {
            std::cerr << "Error: training text is shorter than k = " << k << std::endl;
            return 1;
        }
        seed = text.substr(0,k);
    }

    // Building model
    KGram model(k);
    model.train(text);
    TextGenerator generator(model);
    
    std::string output = generator.generate(seed, text_length);

    std::cout << output << std::endl;

    return 0;
}