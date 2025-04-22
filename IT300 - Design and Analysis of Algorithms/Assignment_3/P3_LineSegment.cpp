#include <bits/stdc++.h>
using namespace std;
//Time O(nlogn)
static bool cmp(const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2) {
    if (p1.second.first == p2.second.first) {
        return p1.second.second > p2.second.second;
    }
    return p1.second.first < p2.second.first;
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<pair<int, pair<int, int>>> points;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cout << "Enter coordinates (x, y) for point " << i << ": ";
        cin >> x >> y;
        points.push_back({i, {x, y}});
    }

    sort(points.begin(), points.end(), cmp);

    int count = 0;
    int max_end = INT_MIN;

    for (int i = 0; i < points.size(); i++) {
        int current_start = points[i].second.first;
        int current_end = points[i].second.second;

        if (current_end <= max_end) {
            count++;
        }

        max_end = max(max_end, current_end);
    }

    cout << "No of such pairs: " << count << endl;

    return 0;
}

