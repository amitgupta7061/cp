#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
}

int f(vector<pair<int, int>> &time){
    sort(time.begin(), time.end(), cmp);

    int currEnd = 0, result = 0;
    for (auto &movie : time) {
        if (movie.first >= currEnd) {
            result++;
            currEnd = movie.second;
        }
    }
    return result;
}

int main() {
    int movies;
    cin >> movies;
    vector<pair<int, int>> time(movies);
    for (auto &it : time) cin >> it.first >> it.second;

    cout << f(time);
    return 0;
}
