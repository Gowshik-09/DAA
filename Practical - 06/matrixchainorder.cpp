#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainOrder(const vector<int>& p) {
int n = p.size() - 1;

vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
for (int l = 2; l <= n; l++) {
for (int i = 1; i <= n - l + 1; i++) {

int j = i + l - 1;
dp[i][j] = INT_MAX;
for (int k = i; k < j; k++) {
    
int cost = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
dp[i][j] = min(dp[i][j], cost);
}
}
}
return dp[1][n];
}
int main() {
int n;

cout << "Enter number of matrices: ";
cin >> n;
vector<int> arr(n + 1);
cout << "Enter dimensions (size " << n+1 << "): ";
for (int i = 0; i <= n; i++) {
cin >> arr[i];
}
cout << "Minimum number of scalar multiplications is: "
<< matrixChainOrder(arr) << endl;
return 0;
}