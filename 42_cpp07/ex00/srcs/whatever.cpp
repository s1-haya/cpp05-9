template <typename T>
void swap(T* a, T* b) {
  T* tmp;

  tmp = *a;
  *a = *b;
  *b = *a;
}
