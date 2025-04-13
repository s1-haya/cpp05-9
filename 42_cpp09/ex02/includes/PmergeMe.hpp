#ifndef EX02_PMERGE_ME_HPP_
#define EX02_PMERGE_ME_HPP_

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>

class PmergeMeVector {
public:
    PmergeMeVector(int argc, char* argv[]);
    void sortAndPrint();

private:
    std::vector<int> sequence;
    double timeTaken;

    void mergeInsertionSort(std::vector<int>& vec);
    void printSequence(const std::vector<int>& vec) const;
    void printTime() const;
};

class PmergeMeDeque {
public:
    PmergeMeDeque(int argc, char* argv[]);
    void sortAndPrint();

private:
    std::deque<int> sequence;
    double timeTaken;

    void mergeInsertionSort(std::deque<int>& deq);
    void printSequence(const std::deque<int>& deq) const;
    void printTime() const;
};

#endif
