#include "PmergeMe.hpp"

void testTitle(const std::string& title);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Please provide a sequence of positive integers." << std::endl;
        return EXIT_FAILURE;
    }

    testTitle("Vector Merge Insertion Sort");
    PmergeMeVector vectorSorter(argc, argv);
    vectorSorter.sortAndPrint();
	
    testTitle("Deque Merge Insertion Sort");
    PmergeMeDeque dequeSorter(argc, argv);
    dequeSorter.sortAndPrint();

    return EXIT_SUCCESS;
}
