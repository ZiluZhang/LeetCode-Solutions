#include <bits/stdc++.h>

using namespace std;



// Complete the winner function below.
string winner(string erica, string bob) {


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string erica;
    getline(cin, erica);

    string bob;
    getline(cin, bob);

    string res = winner(erica, bob);

    fout << res << "\n";

    fout.close();

    return 0;
}
