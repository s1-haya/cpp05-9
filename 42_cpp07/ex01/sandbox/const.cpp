int main(void) {
	const int& a = 1;
	int const& b = 1;

	const int c = 1;

	int d = 2;
	//wconst.cpp:4:9: error: expected unqualified-id
	// const &int c = 1;

	//error: 'const' qualifier may not be applied to a reference
	//error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
	// int& const d = 1;

	// const int vs const int&
	// const intは値をコピーするみたい。
}