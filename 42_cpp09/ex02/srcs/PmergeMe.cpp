#include "PmergeMe.hpp"
// ----------------------------------
// PmergeMeVector class implementation
// ----------------------------------
PmergeMeVector::PmergeMeVector(int argc, char* argv[]) {
    this->time = 0;
	for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error: Invalid vector. Only positive integers are allowed." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        this->vector.push_back(num);
    }
}

PmergeMeVector::~PmergeMeVector() {}

void PmergeMeVector::printVector(const std::vector<int>& vec) const {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMeVector::printVector(const std::string &title, const std::vector<int>& vec) const {
    std::cout << "-------"<< title << "-------" << std::endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMeVector::printVector(const std::string &title, const std::vector<size_t>& vec) const {
    std::cout << "-------"<< title << "-------" << std::endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMeVector::printPairList(const std::list< std::pair<int, int> >& pairList) const {
    std::cout << ">>> Pair List:" << std::endl;
    for (std::list< std::pair<int, int> >::const_iterator it = pairList.begin(); it != pairList.end(); ++it) {
        std::cout << "[" << it->first << ", " << it->second << "] ";
    }
    std::cout << std::endl;
}


std::vector<int> PmergeMeVector::extractSmallerBySortedLarger(
    const std::list< std::pair<int, int> >& pairList,
    const std::vector<int>& sortedLarger
) const {
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

std::vector<int> PmergeMeVector::extractLargerValues(const std::list<std::pair<int, int> >& pairList) const {
    std::vector<int> result;
    for (std::list<std::pair<int, int> >::const_iterator it = pairList.begin(); it != pairList.end(); ++it) {
        if (it->first != -1) {
            result.push_back(it->first);
        }
    }
    return result;
}


std::list< std::pair<int, int> > PmergeMeVector::makePairs(const std::vector<int>& vector) const {
    std::list< std::pair<int, int> > pairList;
    size_t i = 0;

    while (i + 1 < vector.size()) {
        int a = vector[i];
        int b = vector[i + 1];
        if (a >= b)
            pairList.push_back(std::make_pair(a, b));
        else
            pairList.push_back(std::make_pair(b, a));
        i += 2;
    }

    if (i < vector.size()) {
        pairList.push_back(std::make_pair(-1, vector[i]));
    }

    return pairList;
}

std::vector<size_t> PmergeMeVector::generateJacobsthal(size_t size) const {
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

std::vector<int>::iterator PmergeMeVector::lower_bound(std::vector<int>::iterator first,
                                       std::vector<int>::iterator last,
                                       int value) const {
    while (first != last) {
        std::vector<int>::iterator mid = first + (last - first) / 2;
        if (*mid < value)
            first = mid + 1;
        else
            last = mid;
    }
    return first;
}

std::vector<int> PmergeMeVector::mergeInsertionSort(const std::vector<int>& vector) const {
    if (vector.size() <= 1)
        return vector;

    std::list< std::pair<int, int> > pairList = makePairs(vector);
    # ifdef DEBUG
		printPairList(pairList);
    # endif
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
    
    std::vector<size_t> jacobSeq = generateJacobsthal(smaller.size());
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

void PmergeMeVector::sortAndPrint() {
    std::cout << "Before: ";
    printVector(this->vector);
    
    clock_t start = std::clock();
    std::vector<int> sorted = mergeInsertionSort(this->vector);
    clock_t end = std::clock();
    
    this->time = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    
    std::cout << "After: ";
    printVector(sorted);
    std::cout << "Time taken: " << this->time << " ms" << std::endl;
}

// ----------------------------------
// PmergeMeDeque class implementation
// ----------------------------------
PmergeMeDeque::PmergeMeDeque(int argc, char* argv[]) {
    this->time = 0;
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error: Invalid deque. Only positive integers are allowed." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        this->deque.push_back(num);
    }
}

PmergeMeDeque::~PmergeMeDeque() {}

void PmergeMeDeque::printDeque(const std::deque<int>& dq) const {
    for (size_t i = 0; i < dq.size(); ++i) {
        std::cout << dq[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMeDeque::printDeque(const std::string &title, const std::deque<int>& dq) const {
    std::cout << "-------" << title << "-------" << std::endl;
    for (size_t i = 0; i < dq.size(); ++i) {
        std::cout << dq[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMeDeque::printDeque(const std::string &title, const std::deque<size_t>& dq) const {
    std::cout << "-------" << title << "-------" << std::endl;
    for (size_t i = 0; i < dq.size(); ++i) {
        std::cout << dq[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMeDeque::printPairList(const std::list<std::pair<int, int> >& pairList) const {
    std::cout << ">>> Pair List:" << std::endl;
    for (std::list<std::pair<int, int> >::const_iterator it = pairList.begin(); it != pairList.end(); ++it) {
        std::cout << "[" << it->first << ", " << it->second << "] ";
    }
    std::cout << std::endl;
}

std::list<std::pair<int, int> > PmergeMeDeque::makePairs(const std::deque<int>& deque) const {
    std::list<std::pair<int, int> > pairList;
    size_t i = 0;

    while (i + 1 < deque.size()) {
        int a = deque[i];
        int b = deque[i + 1];
        if (a >= b)
            pairList.push_back(std::make_pair(a, b));
        else
            pairList.push_back(std::make_pair(b, a));
        i += 2;
    }

    if (i < deque.size()) {
        pairList.push_back(std::make_pair(-1, deque[i]));
    }

    return pairList;
}

std::deque<int> PmergeMeDeque::extractLargerValues(const std::list<std::pair<int, int> >& pairList) const {
    std::deque<int> result;
    for (std::list<std::pair<int, int> >::const_iterator it = pairList.begin(); it != pairList.end(); ++it) {
        if (it->first != -1) {
            result.push_back(it->first);
        }
    }
    return result;
}

std::deque<int> PmergeMeDeque::extractSmallerBySortedLarger(const std::list<std::pair<int, int> >& pairList, const std::deque<int>& sortedLarger) const {
    std::deque<int> result;
    for (size_t i = 0; i < sortedLarger.size(); ++i) {
        int big = sortedLarger[i];
        for (std::list<std::pair<int, int> >::const_iterator it = pairList.begin(); it != pairList.end(); ++it) {
            if (it->first == big) {
                result.push_back(it->second);
                break;
            }
        }
    }
    for (std::list<std::pair<int, int> >::const_iterator it = pairList.begin(); it != pairList.end(); ++it) {
        if (it->first == -1) {
            result.push_back(it->second);
            break;
        }
    }
    return result;
}

std::deque<size_t> PmergeMeDeque::generateJacobsthal(size_t size) const {
    std::deque<size_t> seq;
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

std::deque<int>::iterator PmergeMeDeque::lower_bound(std::deque<int>::iterator first, std::deque<int>::iterator last, int value) const {
    while (first != last) {
        std::deque<int>::iterator mid = first + (last - first) / 2;
        if (*mid < value)
            first = mid + 1;
        else
            last = mid;
    }
    return first;
}

std::deque<int> PmergeMeDeque::mergeInsertionSort(const std::deque<int>& deque) const {
    if (deque.size() <= 1)
        return deque;

    std::list<std::pair<int, int> > pairList = makePairs(deque);
	# ifdef DEBUG
		printPairList(pairList);
	# endif
	std::deque<int> larger = extractLargerValues(pairList);
	# ifdef DEBUG
		printDeque(">>>Sorting larger...", larger);
	# endif
	std::deque<int> sorted = mergeInsertionSort(larger);
	# ifdef DEBUG
		printDeque(">>>Sorting ...", sorted);
	# endif
	std::deque<int> smaller = extractSmallerBySortedLarger(pairList, sorted);
	# ifdef DEBUG
		printDeque(">>>Sorting smaller...", smaller);    
	# endif
	std::deque<size_t> jacobSeq = generateJacobsthal(smaller.size());
	# ifdef DEBUG
		printDeque(">>>Jacobsthal Sequence", jacobSeq);
	# endif

    std::vector<bool> inserted(smaller.size(), false);

    for (size_t j = 0; j < jacobSeq.size(); ++j) {
        size_t idx = jacobSeq[j];
        if (idx < smaller.size()) {
            int val = smaller[idx];
            std::deque<int>::iterator pos = lower_bound(sorted.begin(), sorted.end(), val);
            sorted.insert(pos, val);
            inserted[idx] = true;
        }
    }

    for (size_t k = 0; k < smaller.size(); ++k) {
        if (!inserted[k]) {
            int val = smaller[k];
            std::deque<int>::iterator pos = lower_bound(sorted.begin(), sorted.end(), val);
            sorted.insert(pos, val);
        }
    }

    return sorted;
}

void PmergeMeDeque::sortAndPrint() {
    std::cout << "Before: ";
    printDeque(this->deque);

    clock_t start = std::clock();
    std::deque<int> sorted = mergeInsertionSort(this->deque);
    clock_t end = std::clock();

    this->time = 1000.0 * (end - start) / CLOCKS_PER_SEC;

    std::cout << "After: ";
    printDeque(sorted);
    std::cout << "Time taken: " << this->time << " ms" << std::endl;
}
