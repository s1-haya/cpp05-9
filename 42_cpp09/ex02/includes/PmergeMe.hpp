#ifndef EX02_PMERGE_ME_HPP_
#define EX02_PMERGE_ME_HPP_

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <ctime>
#include <algorithm>
#include <cstdlib>

class PmergeMeVector {
public:
    PmergeMeVector(int argc, char* argv[]);
    ~PmergeMeVector();
    void sortAndPrint();

private:
    PmergeMeVector();
    PmergeMeVector(const PmergeMeVector& other);
    PmergeMeVector& operator=(const PmergeMeVector& other);

    std::vector<int> vector;
    double time;

    void printVector(const std::string& title, const std::vector<int>& vec) const;
    void printVector(const std::string& title, const std::vector<size_t>& vec) const;
    void printVector(const std::vector<int>& vec) const;
    void printPairList(const std::list<std::pair<int, int> >& pairList) const;

    std::list<std::pair<int, int> > makePairs(const std::vector<int>& input) const;
    std::vector<int> extractLargerValues(const std::list<std::pair<int, int> >& pairList) const;
    std::vector<int> extractSmallerBySortedLarger(const std::list<std::pair<int, int> >& pairList, const std::vector<int>& sortedLarger) const;
    std::vector<size_t> generateJacobsthal(size_t size) const;
    std::vector<int>::iterator lower_bound(std::vector<int>::iterator first, std::vector<int>::iterator last, int value) const;
    std::vector<int> mergeInsertionSort(const std::vector<int>& input) const;
};

class PmergeMeDeque {
public:
    PmergeMeDeque(int argc, char* argv[]);
    ~PmergeMeDeque();
    void sortAndPrint();

private:
    PmergeMeDeque();
    PmergeMeDeque(const PmergeMeDeque& other);
    PmergeMeDeque& operator=(const PmergeMeDeque& other);

    std::deque<int> deque;
    double time;

    void printDeque(const std::string& title, const std::deque<int>& dq) const;
    void printDeque(const std::string &title, const std::deque<size_t>& dq) const;
    void printDeque(const std::deque<int>& dq) const;
    void printPairList(const std::list<std::pair<int, int> >& pairList) const;

    std::list<std::pair<int, int> > makePairs(const std::deque<int>& input) const;
    std::deque<int> extractLargerValues(const std::list<std::pair<int, int> >& pairList) const;
    std::deque<int> extractSmallerBySortedLarger(const std::list<std::pair<int, int> >& pairList, const std::deque<int>& sortedLarger) const;
    std::deque<size_t> generateJacobsthal(size_t size) const;
    std::deque<int>::iterator lower_bound(std::deque<int>::iterator first, std::deque<int>::iterator last, int value) const;
    std::deque<int> mergeInsertionSort(const std::deque<int>& input) const;
};

#endif
