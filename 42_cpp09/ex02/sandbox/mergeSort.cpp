#include <iostream>
#include <vector>
#include <algorithm> // for std::min and std::copy

// Function to merge two sorted vectors with minimal comparisons
void merge(std::vector<int>& vec, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = vec[i++];
    }

    while (j <= right) {
        temp[k++] = vec[j++];
    }

    std::copy(temp.begin(), temp.end(), vec.begin() + left);
}

// Simplified function to perform the Ford-Johnson sorting algorithm
void fordJohnsonSort(std::vector<int>& vec, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    // Recursively sort the two halves
    fordJohnsonSort(vec, left, mid);
    fordJohnsonSort(vec, mid + 1, right);

    // Merge the two sorted halves
    merge(vec, left, mid, right);
}

int main() {
    int numbers_array[] = {7, 3, 5, 1, 6, 4, 2};
    std::vector<int> numbers(numbers_array, numbers_array + sizeof(numbers_array) / sizeof(int));

    fordJohnsonSort(numbers, 0, numbers.size() - 1);

    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
