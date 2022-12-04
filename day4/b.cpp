#include "bits/stdc++.h"
using namespace std;
// A copy of `a.cpp`, but uses a different macro.
#define int int64_t

/* Returns true if [a,b] subseteq [X, Y] */
#define contains(X, Y, a, b) ((a >= X) && (b <= Y))

/* Returns true if { [a,b] intersection [X, Y] } is nonempty */
#define overlaps(X, Y, a, b) ((b >= X) && (b <= Y))

signed main(void) {
    string s;
    int count = 0;

    while(getline(cin, s)) {
        for(auto &c : s) if (c == ',') c = '-';
        
        int x,y,a,b;
        istringstream stream(s);
        string num;

        /* Not a great solution at all, but suffices for now. */
        array a_ref { &x,&y,&a,&b };
        int i = 0;

        while(getline(stream, num, '-')) {
            *a_ref[i++] = stoll(num);
        }


        if(overlaps(x,y,a,b)) ++count;
        else if(overlaps(a,b,x,y)) ++count; 
    }

    cout << "The number of fully contained ranges is: " << count << '\n';
}
