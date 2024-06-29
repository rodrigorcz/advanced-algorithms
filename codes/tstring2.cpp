#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct Trie {
	map<char, Trie> mp;
	int cnt = 0; 
	int end = 0; 

	void add(string& s, int i = 0) {
		cnt++;
		if (i < (int) s.size()) {
			mp[s[i]].add(s, i + 1);
		} else end++;
	}
	
	void remove(string& s, int i = 0) {
        cnt--;
        if (i < (int) s.size()) {
            mp[s[i]].remove(s, i + 1);
        } else end--;
    }

    int search(string& s, int i = 0) {
        if (i == (int) s.size()) return cnt;
        if (mp.count(s[i])) return mp[s[i]].search(s, i + 1);
        return 0;
    }
};

int main(){
    int n;
    cin >> n;

    Trie root;
    for(int i = 0;i < n;i++){
        int x;
        string s;

        cin >> x >> s;

        if(x == 1)
            root.add(s);
        
        if(x == 2)
            root.remove(s);
        
        if(x == 3)
            cout << root.search(s) << endl;
    }

    return 0;
}