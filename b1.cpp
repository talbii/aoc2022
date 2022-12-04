#include "bits/stdc++.h"
using namespace std;

#define int int64_t

/*
 * Note, this solution finds the 3 biggest-calorie elves in O(log n) time, 
 * where n is the number of elves. This is ignoring the time cost of reading the input.
 *
 * It is possible, whilst reading the input, to find the three-biggest, however
 * implementing this is much more tedious.
 * */

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
