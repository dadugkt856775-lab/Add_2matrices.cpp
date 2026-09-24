#include <bits/stdc++.h>
using namespace std;

int main() {
    string beginWord, endWord;
    int n;

    cin >> beginWord >> endWord;
    cin >> n;

    unordered_set<string> words;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.insert(word);
    }

    if (!words.count(endWord)) {
        cout << "Transformation Not Possible" << endl;
        return 0;
    }

    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    unordered_set<string> visited;
    visited.insert(beginWord);

    while (!q.empty()) {
        auto [word, steps] = q.front();
        q.pop();

        if (word == endWord) {
            cout << "Minimum Transformations: "
                 << steps << endl;
            return 0;
        }

        for (int i = 0; i < word.size(); i++) {
            string temp = word;

            for (char c = 'a'; c <= 'z'; c++) {
                temp[i] = c;

                if (words.count(temp) &&
                    !visited.count(temp)) {

                    visited.insert(temp);
                    q.push({temp, steps + 1});
                }
            }
        }
    }

    cout << "Transformation Not Possible" << endl;

    return 0;
}
