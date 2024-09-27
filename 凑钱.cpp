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
    std::cout << "����Ҫ�յ�Ǯ������λ��Ԫ����";
    std::cin >> n;
    std::cout << "�ճ� " << n << " ԪǮ�ķ�����Ϊ��" << coinChange(n) << std::endl;
    return 0;
}
