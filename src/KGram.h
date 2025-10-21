#ifndef KGRAM_H
#define KGRAM_H
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>

class KGram {
    public: 
    explicit KGram(int k);

    void train(const std::string& text);

    int k() const {return k_; }
    bool finished_training() const;

    std::size_t KGram_count(const std::string& w) const;
    std::size_t next_char_count(std::string& w, char c) const;
    const std::unordered_map<char, std::size_t>& nextCounts(const std::string& w) const;


    private: 
    int k_{1};
    std::unordered_map<std::string, std::size_t> kgram_count_;
    std::unordered_map<std::string, std::unordered_map<char, std::size_t>> next_char_count_;

    static std::string slice(const std::string& text, std::size_t i, std::size_t k_);
};
#endif