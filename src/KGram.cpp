#include "KGram.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

KGram::KGram(int k) : k_(k) {
    if (k_ < 1) {
        throw std::invalid_argument("KGram: k must be >= 1");
    }
}

bool KGram::finished_training() const {
    return !kgram_count_.empty();
}

void KGram::train(const std::string& text) {
    if (text.size() < static_cast<size_t> (k_)) {
        return;
    }
    for (std::size_t i=0; i+k_ < text.size(); ++i) {
        std::string w = slice(text, i, k_);
        char next = text[i + k_];
        kgram_count_[w]++;
        next_char_count_[w][next]++;
    }
        std::string last = slice(text, text.size() - k_, k_);
        ++kgram_count_[last];
}

std::string KGram::slice(const std::string& text, std::size_t i, std::size_t k_) {
    return text.substr(i, k_);
}

std::size_t KGram::KGram_count(const std::string& w) const {
    auto it = kgram_count_.find(w);
    return (it == kgram_count_.end()) ? 0 : it->second;
}

std::size_t KGram::next_char_count(std::string& w, char c) const {
    auto it_w = next_char_count_.find(w);
    if (it_w == next_char_count_.end()) return 0;
    auto it_c = it_w->second.find(c);
    return (it_c == it_w->second.end()) ? 0 : it_c->second;
}

const std::unordered_map<char, std::size_t>& KGram::nextCounts(const std::string& w) const {
    static const std::unordered_map<char, std::size_t> empty;
    auto it = next_char_count_.find(w);
    return (it == next_char_count_.end()) ?  empty : it->second;
}