#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



// Complete the playlist function below.
long playlist(vector<int> songs) {


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string songs_count_temp;
    getline(cin, songs_count_temp);

    int songs_count = stoi(ltrim(rtrim(songs_count_temp)));

    vector<int> songs(songs_count);

    for (int i = 0; i < songs_count; i++) {
        string songs_item_temp;
        getline(cin, songs_item_temp);

        int songs_item = stoi(ltrim(rtrim(songs_item_temp)));

        songs[i] = songs_item;
    }

    long res = playlist(songs);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
