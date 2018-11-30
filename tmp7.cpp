#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



// Complete the MinSliceWeight function below.
int MinSliceWeight(vector<vector<int>> Matrix) {
    int n = sizeof(Matrix);
    if (n == 0){
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n,0));
    for(int k = 0; k < n; k++){
    	dp[0][k] = Matrix[0][k];
    }

    for(int i = 1; i < n; i++) {
    	for(int j = 0; j < n; j++) {
    		if(j == 0) {
    			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1])+Matrix[i][j];
    		} else if (j == n - 1) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + Matrix[i][j];
            } else {
                int minimum = min(dp[i - 1][j], dp[i - 1][j + 1]);
                dp[i][j] = min(minimum, dp[i - 1][j - 1]) + Matrix[i][j];
            }
    	}
    }

    int path = INT_MAX;
    for(int k = 0; k < n; k++) {
    	path = min(path, dp[n-1][k]);
    }
    return path;
}

int main(){}