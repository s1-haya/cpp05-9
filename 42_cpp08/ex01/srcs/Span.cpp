#include "Span.hpp"

#include <cstdlib>

Span::Span(unsigned int N) : max_size_(N) {}

Span::Span(const Span &other) { *this = other; }

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    this->max_size_ = other.max_size_;
    this->storage_ = other.storage_;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
  if (this->storage_.size() == this->max_size_)
    throw(std::range_error("This storage is max."));
  this->storage_.push_back(n);
}

void Span::addRandomNumbers(std::size_t n, int min, int max) {
  try {
    if (min > max) throw(std::range_error("min is greater than max"));
    size_t range = max - min;
    if (RAND_MAX < range)
      throw(std::range_error("range is greater than RAND_MAX"));
    for (std::size_t i = 0; i < n; i++) {
      this->addNumber((std::rand() % range) + min);
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

unsigned long Span::shortestSpan() {
  if (this->storage_.size() < 2) throw(std::range_error("Not enough..."));
  std::sort(this->storage_.begin(), this->storage_.end());
  unsigned long shortest = this->storage_.at(1) - this->storage_.at(0);
  for (std::size_t i = 1; i < this->storage_.size() - 1; i++) {
    unsigned long diff = this->storage_[i + 1] - this->storage_[i];
    if (diff < shortest) shortest = diff;
  }
  return (shortest);
}

unsigned long Span::longestSpan() {
  if (this->storage_.size() < 2) throw(std::range_error("Not enough..."));
  long min = *(std::min_element(this->storage_.begin(), this->storage_.end()));
  long max = *(std::max_element(this->storage_.begin(), this->storage_.end()));
  unsigned long longest = max - min;
  return (longest);
}

void Span::printStorage() {
  if (this->storage_.size()) {
    std::cout << "storage_ = ";
    for (std::vector<int>::iterator i = this->storage_.begin();
         i != this->storage_.end(); i++) {
      std::cout << *i << " ";
    }
  } else {
    std::cout << "This storage is empty because nothing has been stored yet";
  }
  std::cout << std::endl;
}
