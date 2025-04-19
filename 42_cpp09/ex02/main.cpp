#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Please provide a sequence of positive integers." << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Vector Merge Insertion Sort" << std::endl;
    PmergeMeVector vectorSorter(argc, argv);
    vectorSorter.sortAndPrint();
	
    std::cout << std::endl;

    std::cout << "Deque Merge Insertion Sort" << std::endl;
    PmergeMeDeque dequeSorter(argc, argv);
    dequeSorter.sortAndPrint();

    return EXIT_SUCCESS;
}
