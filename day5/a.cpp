#include "bits/stdc++.h"
using namespace std;

#define int int64_t

/*
 * Note: the input for this question is absolutely horrible. 
 * My solution:
 *  note that if the contains N stacks (in this case, N = 9)
 *  the a line size (excluding \n) is exactly:
 *   3*N + N - 1
 *  where:
 *   - 3*N comes from representing [X] - the crate in a single stack
 *   - N - 1 comes from the spacing between crates, e.g.,
 *       v
 *    [X] [Z]
 *    [Y] [W]
 *     1   2
 *       ^--- the spacing
 *
 *  given a single line, we can extract from it the number of stacks, and
 *  using that information compute for each stack the index in which a crate
 *  may appear. Let us look at the last example, but with [Z] in the third stack:
 *    [X]     [Z]
 *    [Y] [W]   
 *     1   2   3
 *  in this case, in order to jump from X to Z and still preserve the indices 1,3
 *  we can use:
 *   line[1 + 4*i] <=> X, ' ', Z  (note the zero-based indexing)
 *  which works OK, but is quite horrific to be honest.
 *   */

auto get_initial_stack(void) {
    string s;
    
    getline(cin, s);
    int N = (s.size() + 1) / 4;
    
    vector<list<int>> result(N); 

    do {
        // cout << "The line is: " << s << '\n' << "Which has " << s.size() << " characters.\n";

        for(int i = 0; i < N; ++i) {
            if(s[1 + 4*i] != ' ') {
                // cout << "I will be inserting " << (int) s[i] << " (" << s[i] << ") which appears at " << i << '\n';
                result[i].push_back(s[1 + 4*i]);
            }
        }

        getline(cin, s);
    } while(s[1] != '1'); // again, not a great solution. 
                          // We detect the first line that starts with '1',
                          // i.e., the line which numbers the stacks.
    getline(cin, s); // skip empty line
    // cout << "The value of N is: " << N << '\n';
    return move(result); 
}

signed main(void) {
    auto mat = get_initial_stack ();

//    for(auto &v : mat) {
//        for(auto & x : v) {
//            cout << x << ' ';
//        }
//        cout << '\n';
//    }
    cout << "yay\n";
    string s;
    while(getline(cin, s)) {
        istringstream stream(s); // move X from Y to Z
        int amount, from, to;

        stream.ignore(4); // ignore 'move'
        stream >> amount;
        stream.ignore(5); // ignore 'from'
        stream >> from;
        stream.ignore(3); // ignore 'two'
        stream >> to;
        
        --from, --to; // make zero-based
        cout << "Moving " << amount << " from " << from << " to " << to << '\n';
        while(amount--) {
            auto crate = mat[from].front();
            mat[from].pop_front();
            mat[to].push_front(crate);
        }
    }

    
    cout << "The crates ontop of each stack are: ";
    for(auto & stack : mat) if(!stack.empty())
        cout << (char) stack.front();

    cout << '\n';
} /* I am going to be leaving all my 'cout'-s to showcase my pain and suffering. */
