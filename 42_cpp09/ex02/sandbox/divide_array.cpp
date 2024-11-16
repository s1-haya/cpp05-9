#include <string>

int main() {
	#if DEBUG
		printf("DEBUG");
	#else
		printf("Release");
	#endif
	return 0;
}
