#include "textgenerator.h"
#include <stdexcept>
#include <vector>
#include <random>

TextGenerator::TextGenerator(KGram& model, unsigned int seed)
    : model_(model), k_(model.k()), rng_(seed)
{

}

void TextGenerator::reseed(unsigned int seed) {
    rng_.seed(seed);
}

char TextGenerator::weighted_choice(const std::unordered_map<char, std::size_t>& distribution) {
    if (distribution.empty()) {
        return '\0';
    }
std::vector<char> symbols;
symbols.reserve(distribution.size());
std::vector<std::size_t> weights;
weights.reserve(distribution.size());

for (const auto& kv : distribution) {
    if (kv.second > 0) {
        symbols.push_back(kv.first);
        weights.push_back(kv.second);
    }
}
if (symbols.empty()) {
    return '\0';
}
std::discrete_distribution<std::size_t> dist(weights.begin(), weights.end());
std::size_t idx = dist(rng_);
return symbols[idx];
}

char TextGenerator::sample_next(const std::string& w) {
    if (static_cast<int> (w.size()) != k_) {
        throw std::invalid_argument("KGram has wrong length.");
    }
    const auto& next = model_.nextCounts(w);
    char sample = weighted_choice(next);
    return sample;
}

std::string TextGenerator::generate(std::string seed_kgram, std::size_t length) {
    if (!model_.finished_training()) {
        throw std::logic_error("Model not trained.");
    }
    if (static_cast<int>(seed_kgram.size()) != k_) {
        throw std::invalid_argument("Seed k-gram length != k.");
    }

    std::string result;
    result.reserve(length);

    std::string w = seed_kgram;

    for (std::size_t i = 0; i < length; ++i) {
        char c = sample_next(w);
        if (c == '\0') {
            break;
        }
        result.push_back(c);

        w.erase(w.begin());
        w.push_back(c);
    }

    return result;
}