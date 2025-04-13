#include "PmergeMe.hpp"

PmergeMeVector::PmergeMeVector(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error: Invalid input. Only positive integers are allowed." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        sequence.push_back(num);
    }
}

void PmergeMeVector::mergeInsertionSort(std::vector<int>& vec) {
    size_t n = vec.size();
    if (n <= 1) return;

    // ペアごとに分けて、ソートする
    std::vector<int> left, right;
    for (size_t i = 0; i < n / 2; ++i) {
        left.push_back(vec[i]);
    }
    for (size_t i = n / 2; i < n; ++i) {
        right.push_back(vec[i]);
    }

    // 左右の部分列を再帰的にソート
    mergeInsertionSort(left);
    mergeInsertionSort(right);

    // ソートされた部分列をマージ
    size_t i = 0, j = 0;
    std::vector<int> merged;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            merged.push_back(left[i]);
            ++i;
        } else {
            merged.push_back(right[j]);
            ++j;
        }
    }

    // 残りの要素を追加
    while (i < left.size()) {
        merged.push_back(left[i]);
        ++i;
    }

    while (j < right.size()) {
        merged.push_back(right[j]);
        ++j;
    }

    // 結果を元の配列に戻す
    vec = merged;
}


void PmergeMeVector::printSequence(const std::vector<int>& vec) const {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void PmergeMeVector::printTime() const {
    std::cout << "Time taken: " << timeTaken << " ms" << std::endl;
}

void PmergeMeVector::sortAndPrint() {
    std::cout << "Before: ";
    printSequence(sequence);

    clock_t start = std::clock();
    mergeInsertionSort(sequence);
    clock_t end = std::clock();

    timeTaken = 1000.0 * (end - start) / CLOCKS_PER_SEC;

    std::cout << "After: ";
    printSequence(sequence);
    printTime();
}

PmergeMeDeque::PmergeMeDeque(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error: Invalid input. Only positive integers are allowed." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        sequence.push_back(num);
    }
}

void PmergeMeDeque::mergeInsertionSort(std::deque<int>& deq) {
    size_t n = deq.size();
    if (n <= 1) return;

    // ペアごとに分ける
    std::deque<int> left, right;
    for (size_t i = 0; i < n / 2; ++i) {
        left.push_back(deq[i]);
    }
    for (size_t i = n / 2; i < n; ++i) {
        right.push_back(deq[i]);
    }

    // 左右の部分列を再帰的にソート
    mergeInsertionSort(left);
    mergeInsertionSort(right);

    // ソートされた部分列をマージ
    deq.clear();
    while (!left.empty() && !right.empty()) {
        if (left.front() < right.front()) {
            deq.push_back(left.front());
            left.pop_front();
        } else {
            deq.push_back(right.front());
            right.pop_front();
        }
    }

    // 残りの要素を追加
    while (!left.empty()) {
        deq.push_back(left.front());
        left.pop_front();
    }
    while (!right.empty()) {
        deq.push_back(right.front());
        right.pop_front();
    }
}

void PmergeMeDeque::printSequence(const std::deque<int>& deq) const {
    for (size_t i = 0; i < deq.size(); ++i) {
        std::cout << deq[i];
        if (i < deq.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void PmergeMeDeque::printTime() const {
    std::cout << "Time taken: " << timeTaken << " ms" << std::endl;
}

void PmergeMeDeque::sortAndPrint() {
    std::cout << "Before: ";
    printSequence(sequence);

    clock_t start = std::clock();
    mergeInsertionSort(sequence);
    clock_t end = std::clock();

    timeTaken = 1000.0 * (end - start) / CLOCKS_PER_SEC;

    std::cout << "After: ";
    printSequence(sequence);
    printTime();
}
