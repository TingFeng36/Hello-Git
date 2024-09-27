#include <iostream>
#include <vector>

int coinChange(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (i >= 1) dp[i] += dp[i - 1];
        if (i >= 2) dp[i] += dp[i - 2];
        if (i >= 5) dp[i] += dp[i - 5];
    }
    return dp[n];
}

int main() {
    int n;
    std::cout << "输入要凑的钱数（单位：元）：";
    std::cin >> n;
    std::cout << "凑出 " << n << " 元钱的方法数为：" << coinChange(n) << std::endl;
    return 0;
}
