#include "bits/stdc++.h"
using namespace std;

#define int int64_t

signed main(void) {
    string s;
    int global_maximum = 0, local_maximum = 0;

    while(getline(cin, s)) {
        if(s.size() == 0) {
            global_maximum = max(global_maximum, local_maximum);
            local_maximum = 0;
        } else
            local_maximum += stoll(s);
    }

    cout << "The maximal total calories are: " << global_maximum << '\n';
}
