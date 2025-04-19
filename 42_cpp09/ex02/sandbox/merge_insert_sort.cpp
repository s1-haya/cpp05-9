#include <vector>
#include <iostream>
#include <ctime>
#include <list>

void printVector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void printVector(const std::string &title, const std::vector<int>& vec) {
    std::cout << "-------"<< title << "-------" << std::endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void printVector(const std::string &title, const std::vector<size_t>& vec) {
    std::cout << "-------"<< title << "-------" << std::endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void printPairList(const std::list< std::pair<int, int> >& pairList) {
    std::cout << ">>> Pair List:" << std::endl;
    for (std::list< std::pair<int, int> >::const_iterator it = pairList.begin(); it != pairList.end(); ++it) {
        std::cout << "[" << it->first << ", " << it->second << "] ";
    }
    std::cout << std::endl;
}


std::vector<int> extractSmallerBySortedLarger(
    const std::list< std::pair<int, int> >& pairList,
    const std::vector<int>& sortedLarger
) {
    std::vector<int> result;
    for (size_t i = 0; i < sortedLarger.size(); ++i) {
        int big = sortedLarger[i];
        for (std::list< std::pair<int, int> >::const_iterator it = pairList.begin(); it != pairList.end(); ++it) {
            if (it->first == big) {
                result.push_back(it->second);
                break;
            }
        }
    }
    for (std::list< std::pair<int, int> >::const_iterator it = pairList.begin(); it != pairList.end(); ++it) {
        if (it->first == -1) {
            result.push_back(it->second);
            break;
        }
    }
    return result;
}

std::vector<int> extractLargerValues(const std::list<std::pair<int, int> >& pairList) {
    std::vector<int> result;
    for (std::list<std::pair<int, int> >::const_iterator it = pairList.begin(); it != pairList.end(); ++it) {
        if (it->first != -1) {
            result.push_back(it->first);
        }
    }
    return result;
}


std::list< std::pair<int, int> > makePairs(const std::vector<int>& input) {
    std::list< std::pair<int, int> > pairList;
    size_t i = 0;

    while (i + 1 < input.size()) {
        int a = input[i];
        int b = input[i + 1];
        if (a >= b)
            pairList.push_back(std::make_pair(a, b));
        else
            pairList.push_back(std::make_pair(b, a));
        i += 2;
    }

    if (i < input.size()) {
        pairList.push_back(std::make_pair(-1, input[i]));
    }

    return pairList;
}

// Jacobsthal数列を生成（C++98準拠）
std::vector<size_t> generateJacobsthalSequence(size_t size) {
    std::vector<size_t> seq;
    size_t a = 0;
    size_t b = 1;
    while (b < size) {
        if (std::find(seq.begin(), seq.end(), b) == seq.end()) {
            seq.push_back(b);
        }
        size_t tmp = b;
        b = b + 2 * a;
        a = tmp;
    }
    return seq;
}

std::vector<int>::iterator lower_bound(std::vector<int>::iterator first,
                                       std::vector<int>::iterator last,
                                       int value) {
    while (first != last) {
        std::vector<int>::iterator mid = first + (last - first) / 2;
        if (*mid < value)
            first = mid + 1;
        else
            last = mid;
    }
    return first;
}

std::vector<int> mergeInsertionSort(const std::vector<int>& input) {
    if (input.size() <= 1)
        return input;

    std::list< std::pair<int, int> > pairList = makePairs(input);
    printPairList(pairList);
    std::vector<int> larger = extractLargerValues(pairList);
    # ifdef DEBUG
        printVector(">>>Sorting larger...", larger);
    # endif
    std::vector<int> sorted = mergeInsertionSort(larger);
    # ifdef DEBUG
        printVector(">>>Sorting ...", sorted);
    # endif
    std::vector<int> smaller = extractSmallerBySortedLarger(pairList, sorted);
    # ifdef DEBUG
        printVector(">>>Sorting smaller...", smaller);    
    # endif
    
    std::vector<size_t> jacobSeq = generateJacobsthalSequence(smaller.size());
    # ifdef DEBUG
        printVector(">>>Jacobsthal Sequence", jacobSeq);
    # endif
    std::vector<bool> inserted(smaller.size(), false);

    for (size_t j = 0; j < jacobSeq.size(); ++j) {
        size_t idx = jacobSeq[j];
        if (idx < smaller.size()) {
            int val = smaller[idx];
            std::vector<int>::iterator pos = lower_bound(sorted.begin(), sorted.end(), val);
            sorted.insert(pos, val);
            inserted[idx] = true;
        }
    }

    for (size_t k = 0; k < smaller.size(); ++k) {
        if (!inserted[k]) {
            int val = smaller[k];
            std::vector<int>::iterator pos = lower_bound(sorted.begin(), sorted.end(), val);
            sorted.insert(pos, val);
        }
    }

    return sorted;
}

void sortAndPrint(const std::vector<int> &input) {
    double timeTaken;

    std::cout << "Before: ";
    printVector(input);
    
    clock_t start = std::clock();
    std::vector<int> sorted = mergeInsertionSort(input);
    clock_t end = std::clock();
    
    timeTaken = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    
    std::cout << "After: ";
    printVector(sorted);
    std::cout << "Time taken: " << timeTaken << " ms" << std::endl;
}

int main(int argc, char **argv)
{
	std::vector<int> input;
    for (int i = 1; i < argc; i++) {
        input.push_back(atoi(argv[i]));
    }
	printVector("Before Sorted", input);
	std::vector<int> sorted = mergeInsertionSort(input);
    printVector("After Sorted", sorted);
	return 0;
}
