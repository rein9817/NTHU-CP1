#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Cat {
    string name;
    string position;
    int age;

    bool operator<(const Cat& other) const {
        if (position != other.position) {
            // Sort by position from old to young
            map<string, int> positionPriority = {{"elder", 0}, {"nursy", 1}, {"kit", 2}, {"warrior", 3},
                                                 {"appentice", 4}, {"medicent", 5}, {"deputy", 6}, {"leader", 7}};
            return positionPriority[position] > positionPriority[other.position];
        }
        if (position == "appentice") {
            // Sort apprentices from young to old
            return age < other.age;
        }
        if (age != other.age) {
            // Sort by age from old to young
            return age > other.age;
        }
        // If position and age are the same, use lexicographical comparison of names
        return name < other.name;
    }
};

int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<Cat> cats;
        for (int i = 0; i < N; i++) {
            string name, position;
            int age;
            cin >> name >> position >> age;
            cats.push_back({name, position, age});
        }

        sort(cats.begin(), cats.end());

        for (int i = 0; i < min(M, N); i++) {
            cout << cats[i].name << endl;
        }
    }
    return 0;
}
