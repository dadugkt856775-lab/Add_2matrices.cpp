#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    int capacity, minFreq;

    unordered_map<int, int> value;
    unordered_map<int, int> frequency;

    unordered_map<int, list<int>> keys;
    unordered_map<int, list<int>::iterator> position;

    void increaseFrequency(int key) {
        int freq = frequency[key];

        keys[freq].erase(position[key]);

        if (keys[freq].empty()) {
            keys.erase(freq);

            if (minFreq == freq)
                minFreq++;
        }

        frequency[key]++;

        keys[freq + 1].push_front(key);
        position[key] = keys[freq + 1].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (!value.count(key))
            return -1;

        increaseFrequency(key);
        return value[key];
    }

    void put(int key, int val) {
        if (capacity == 0)
            return;

        if (value.count(key)) {
            value[key] = val;
            increaseFrequency(key);
            return;
        }

        if (value.size() == capacity) {
            int removeKey = keys[minFreq].back();

            keys[minFreq].pop_back();

            value.erase(removeKey);
            frequency.erase(removeKey);
            position.erase(removeKey);
        }

        value[key] = val;
        frequency[key] = 1;

        keys[1].push_front(key);
        position[key] = keys[1].begin();

        minFreq = 1;
    }
};

int main() {
    int capacity, q;
    cin >> capacity >> q;

    LFUCache cache(capacity);

    while (q--) {
        string operation;
        cin >> operation;

        if (operation == "put") {
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
        }
        else if (operation == "get") {
            int key;
            cin >> key;

            cout << cache.get(key) << endl;
        }
    }

    return 0;
}
