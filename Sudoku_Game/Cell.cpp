#include "Cell.h"

Cell::Cell() : value(0), isFixed_(false) {
    resetCandidates();
}

int Cell::getValue() const {
    return value;
}

void Cell::setValue(int value) {
    this->value = value;
}

void Cell::clearValue() {
    value = 0;
}

bool Cell::isEmpty() const {
    return value == 0;
}

bool Cell::isFixed() const {
    return isFixed_;
}

void Cell::setFixed(bool fixed) {
    isFixed_ = fixed;
}

std::set<int>& Cell::candidates() {
    return candidates_;
}

const std::set<int>& Cell::candidates() const {
    return candidates_;
}

void Cell::resetCandidates() {
    candidates_.clear();
    for (int v = 1; v <= 9; ++v) {
        candidates_.insert(v);
    }
}
