#include <iostream> 
#include <vector> 
using namespace std; 
 
class CoinChangeWays { 
private: 
    vector<int> coins; 
    int amount; 
 
public: 
    // Function to take input 
    void getInput() { 
        int n; 
        cout << "Enter number of coin types: "; 
        cin >> n; 
 
        coins.resize(n); 
        cout << "Enter coin denominations: "; 
        for (int i = 0; i < n; i++) { 
            cin >> coins[i]; 
        } 
 
        cout << "Enter target amount: "; 
 
        cin >> amount; 
    } 
 
    void solve() { 
        vector<long long> dp(amount + 1, 0); 
 
        dp[0] = 1; // Base case: one way to make amount 0 
        for (int coin : coins) { 
            for (int i = coin; i <= amount; i++) { 
                dp[i] += dp[i - coin]; 
            } 
        } 
 
        cout << "Number of ways to make change = " << dp[amount] << endl; 
    } 
}; 
 
int main() { 
    CoinChangeWays obj; 
    obj.getInput(); 
    obj.solve(); 
    return 0; 
} 