#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


string doubleToString(double num)
{
    char str[256];
    sprintf(str, "%.2f", num);
    string result = str;
    return result;
}

// Complete the findMaxGoalsProbability function below.
string findMaxGoalsProbability(vector<int> teamGoals) {
	int maxScore = INT_MAX;
	int match = 0;
	for(int i = 0; i < teamGoals.size(); i++) {
		for(int j = i+1; j < teamGoals.size(); j++) {
			maxScore = max(maxScore, teamGoals[i] + teamGoals[j]);
			match++;
		}
	}

	int count = 0;
	for(int i = 0; i < teamGoals.size(); i++) {
		for(int j = i+1; j < teamGoals.size(); j++) {
			int score = teamGoals[i] + teamGoals[j];
			if(score == maxScore)
				count++;
		}
	}
	double result = (double) count / match;
	// result = round(result * 100) / 100.0;
	// string res = doubleToString(result);
	string res = doubleToString(result);
	return res;
}

int main()