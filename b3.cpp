#include "bits/stdc++.h"
using namespace std;

#define int int64_t

set<int> unique_elements(const string_view &s) {
    set<int> res;
    for(const auto &c : s)
        res.insert(c);

    return res;
}

int priority(int item) {
    if(item >= 'a' && item <= 'z')
        return item - 'a' + 1;
    else return item - 'A' + 27;
}

signed main(void) {
    string s1, s2, s3;
    int sum_priorities = 0;

    while(getline(cin, s1)) { // got a new string, thus we must have two more elves.
        getline(cin, s2);
        getline(cin, s3);

        auto u1 = unique_elements(s1),
             u2 = unique_elements(s2),
             u3 = unique_elements(s3);


        set<int> u1u2; // the intersection of u1 and u2.
#define all_c(X) X.cbegin(), X.cend()

        set_intersection(all_c(u1), all_c(u2), inserter(u1u2, u1u2.end()));
        set<int> intr; // the intersection of u1, u2 and u3.
        set_intersection(all_c(u1u2), all_c(u3), inserter(intr, intr.end()));
        
        for(const auto &item : intr)
           sum_priorities += priority(item); 
   }

    cout << "The sum of all priorties over all rucksacks is: " << sum_priorities << '\n';
}
