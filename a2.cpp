#include "bits/stdc++.h"
using namespace std;

#define int int64_t

// X = Rock
// Y = Paper
// Z = Scissors

int round_score(char enemy, char me) {
    constexpr auto diff = 'X' - 'A';
    enemy += diff;
    
    array rps_map = {'Z', 'X', 'Y'};
    array play_point = {1, 2, 3};

    if(rps_map[enemy - 'X'] == me) return 0 + play_point[me - 'X']; // I lost
    if(rps_map[me - 'X'] == enemy) return 6 + play_point[me - 'X']; // I won

    return 3 + play_point[me - 'X'];
}

signed main(void) {
    string s;
    int score = 0;
    while(getline(cin, s)) {
        score += round_score(s[0], s[2]);
    }

    cout << "The final score is: " << score << '\n';
}
