#include <bits/stdc++.h>

using namespace std;



// Complete the differentTeams function below.
int differentTeams(string skills) {
	if(skills == null || skills.length() < 5) return 0;

	map<char, int> m;
	for(int i = 0; i < skills.length(); i++) {
		char c = skills[i];
		if(!m.count(c))
			m[c] = 1;
		else
			m[c]++;
	}

	if(m.size() < 5) return 0;

	int minimum = INT_MAX;
	map<char, int>::iterator it;
	it = m.begin();
	while(it != m.end()) {
		char key = it->first;
		minimum = min(minimum, m[key])
		it++;
	}
	return minimum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string skills;
    getline(cin, skills);

    int res = differentTeams(skills);

    fout << res << "\n";

    fout.close();

    return 0;
}