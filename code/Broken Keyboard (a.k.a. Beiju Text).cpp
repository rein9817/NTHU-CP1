#include <bits/stdc++.h>
#define rein ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int main()
{
	
	string input;

	while (getline(cin, input)) 
    {
        list<char> line;
		auto it = line.begin();
		for (auto& i : input) 
        {
			if (i == '[') it = line.begin();
			else if (i == ']') it = line.end();
			else line.emplace(it, i);
		}
		for (auto& i : line) cout << i;
		cout << "\n";
	}
}