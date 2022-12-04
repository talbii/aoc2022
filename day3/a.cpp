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
    string s;
    int sum_priorities = 0;

    while(getline(cin, s)) {
        auto ss = string_view(s); // efficient substring manipulation of s
        auto n = s.size();

        auto left_s = ss.substr(0, n/2),
             right_s = ss.substr(n/2, n);


        auto left = unique_elements(left_s),
            right = unique_elements(right_s);

        vector<int> v;

        set_intersection(left.cbegin(), left.cend(),
            right.cbegin(), right.cend(), back_inserter(v));

        for(const auto &item : v)
            sum_priorities += priority(item);
    }

    cout << "The sum of all priorties over all rucksacks is: " << sum_priorities << '\n';
}
