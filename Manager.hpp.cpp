#pragma once
#include <vector>

template <typename T>
class Manager {
    std::vector<T> elemente; 
public:
    void adauga(const T& elem) {
        elemente.push_back(elem);
    }

    void stergeUltimul() {
        if (!elemente.empty()) {
            elemente.pop_back();
        }
    }

    std::vector<T>& getElemente() {
        return elemente;
    }

    int getDimensiune() const {
        return elemente.size();
    }
};