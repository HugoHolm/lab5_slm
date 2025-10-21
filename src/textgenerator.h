#ifndef TEXTGENERATOR_H
#define TEXTGENERATOR_H

#include "KGram.h"
#include <string>
#include <unordered_map>
#include <random>

class TextGenerator {
public:
    explicit TextGenerator(KGram& model, unsigned int seed = std::random_device{}());
    
    void reseed(unsigned int seed);

    std::string generate(std::string seed_kgram, std::size_t length);

    char sample_next(const std::string& w);

private:
    KGram& model_;
    int k_;
    std::mt19937 rng_;
    
    char weighted_choice(const std::unordered_map<char, std::size_t>& distribution);
};
#endif