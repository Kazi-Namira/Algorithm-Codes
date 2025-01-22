#include <bits/stdc++.h>
using namespace std;

void printMaxActivities(int s[], int f[], int n)
{
    vector<pair<pair<int, int>, int>> activities;
    for (int i = 0; i < n; i++)
    {
        activities.push_back({{f[i], s[i]}, i});
    }


    sort(activities.begin(), activities.end());


    int i = activities[0].second;


    cout << "Selected activities are: ";
    cout << "(" << s[i] << "," << f[i] << ") ";


    for (int j = 1; j < n; j++)
    {
        if (activities[j].first.second >= activities[i].first.first)
        {
            cout << "(" << s[activities[j].second] << "," << f[activities[j].second] << ") ";
            i = j;
        }
    }

    cout << endl;
}

int main()
{
    int s[] = { 1, 3, 0, 5, 8, 5 };
    int f[] = { 2, 4, 6, 7, 9, 9 };
    int n = sizeof(s) / sizeof(s[0]);

    printMaxActivities(s, f, n);

    return 0;
}
