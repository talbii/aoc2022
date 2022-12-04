#include "bits/stdc++.h"
using namespace std;

#define int int64_t

signed main(void) {
    string x;
    set<int> s;
    int sum = 0;

    while(getline(cin, x)) {
        if(x.size() == 0) {
            s.insert(sum);
            sum = 0;
        } else
            sum += stoll(x);
    }

    if(sum != 0)
        s.insert(sum);

    auto largest = s.cend();
    --largest; // get actual pointer to largest-calorie elf

    cout << "The sum of the 3 largest calorie elves is: " <<
        *largest + *prev(largest, 1) + *prev(largest, 2) << '\n';

}
