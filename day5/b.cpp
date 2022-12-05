#include "bits/stdc++.h"
using namespace std;

#define int int64_t

// This is the same function as in a.cpp, comments withdrawn. 
auto get_initial_stack(void) {
    string s;

    getline(cin, s);
    int N = (s.size() + 1) / 4;

    vector<list<int>> result(N);

    do {
        for(int i = 0; i < N; ++i) {
            if(s[1 + 4*i] != ' ') {
                result[i].push_back(s[1 + 4*i]);
            }
        }

        getline(cin, s);
    } while(s[1] != '1'); 
                          
    getline(cin, s); 
    return move(result);
}
signed main(void) {
    auto mat = get_initial_stack ();

    string s;
    while(getline(cin, s)) {
        int amount, from, to;
        istringstream stream(s);

        stream.ignore(4);
        stream >> amount;
        stream.ignore(5);
        stream >> from;
        stream.ignore(3);
        stream >> to; 

        --from, --to;
        auto &l1 = mat[from], &l2 = mat[to];
        auto it = l1.begin();
        advance(it, amount); // splice's range is exclusive, i.e., [first, last). 
                             // In practice, we insert l1.begin() ... l1.begin() + (amount - 1)

        /* Moves the elements in [l1.begin(), it) from l1 to l2. */
        l2.splice(l2.begin(), l1, l1.begin(), it);
    }

    cout << "The crates ontop of each stack are: ";
    for(auto & stack : mat) if(!stack.empty())
        cout << (char) stack.front();
    cout << '\n';
}
