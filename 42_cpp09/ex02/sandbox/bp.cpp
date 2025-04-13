#include <iostream>
#include <vector>

int fibonacci(int n) {
    std::vector<int> memo(n + 1);

    memo[0] = 0;
    if (n > 0) {
        memo[1] = 1;
    }
    
    for (int i = 2; i <= n; ++i) {
        memo[i] = memo[i - 1] + memo[i - 2];
		std::cout << "memo[" << i << "]: " << memo[i]; 
		std::cout << ", "; 
		std::cout << "memo[" << i - 1 << "]: " << memo[i - 1]; 
		std::cout << ", "; 
		std::cout << "memo[" << i - 2 << "]: " << memo[i - 2]; 
		std::cout << std::endl; 
    }
    
    return memo[n];
}

int main() {
    int n;
    std::cout << "フィボナッチ数列のn番目の数を計算します。nの値を入力してください: ";
    std::cin >> n;
    
    int result = fibonacci(n);
    std::cout << "フィボナッチ数列の" << n << "番目の数は " << result << " です。" << std::endl;
    
    return 0;
}
