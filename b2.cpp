#include "bits/stdc++.h"
using namespace std;

#define int int64_t

// A = Rock     [X]  
// B = Paper    [Y]
// C = Scissors [Z]
//
// X = Lose this round }     Play  rps_map[enemy]
// Y = Tie             } <=> Play  enemy 
// Z = Win             }     Play  inverse_rps_map[enemy] = 

int round_score(char enemy, char me) {
    constexpr auto diff = 'X' - 'A';
    enemy += diff;

    constexpr array rps_map = {'Z', 'X', 'Y'};
    constexpr array play_point = {1, 2, 3};
    constexpr array inverse_rps_map = {'Y', 'Z', 'X'};

    if(me == 'X') return play_point[ rps_map[enemy - 'X'] - 'X']; // Lose
    if(me == 'Y') return play_point[enemy - 'X'] + 3; // Tie
   
    me = inverse_rps_map[enemy - 'X'];
    return 6 + play_point[me - 'X'];
}

signed main(void) {
    string s;
    int score = 0;

    while(getline(cin, s)) {
        score += round_score(s[0], s[2]);
    }

    cout << "The final score is: " << score << '\n';
}
