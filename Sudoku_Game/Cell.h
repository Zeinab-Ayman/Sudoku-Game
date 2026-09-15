#pragma once

#include <set>
using namespace std;

/**
 * Represents a single Sudoku cell.
 * Related SRS sections: 3.2 (Gameplay and Board Interaction), 5.1 (Class Structure).
 */
class Cell {
public:
    Cell();

    int getValue() const;
    void setValue(int value);
    void clearValue();

    bool isEmpty() const;

    bool isFixed() const;
    void setFixed(bool fixed);

    // Candidate values for this cell (useful for hints / pencil-mark style features).
    set<int>& candidates();
    const set<int>& candidates() const;
    void resetCandidates();

private:
    int value;        // 0 means empty, otherwise 1-9
    bool isFixed_;      // true if this cell was part of the original puzzle (FR-7)
    set<int> candidates_;
};

