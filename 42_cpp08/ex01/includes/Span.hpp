#ifndef EX01_SPAN_HPP_
#define EX01_SPAN_HPP_

#include <iostream>
#include <vector>

class Span{
public:
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int n);
	void addRandomNumbers(std::size_t n, int min, int max);
	size_t shortestSpan();
	size_t longestSpan();

	void printStorage();
	size_t getStorageSize() const;

private:
	unsigned int max_size_;
	std::vector<int> storage_;
	Span();
};

#endif
