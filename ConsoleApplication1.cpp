#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
        return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
    });
    int num = people.size();
    vector<vector<int>> queue(num);
    vector<bool> flag(num, 0);
    int n_shorter = 0;
    for (int i = 0; i < num; i++) {
        int hi = people[i][0];
        int ki = people[i][1];
        int j = 0;
        while (true) {
            if (flag[j]) {
                n_shorter++;
            }
            if (j == ki + n_shorter) {
                queue[j] = people[i];
                flag[j] = 1;
                break;
            }
            j++;
        }
        n_shorter = 0;
    }
    return queue;
}

int main()
{
    //vector<vector<int>> people = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
    vector<vector<int>> people;
    vector<int> temp = { 7, 0 };
    people.push_back(temp);
    temp = { 4, 4 };
    people.push_back(temp);
    temp = { 7, 1 };
    people.push_back(temp);
    temp = { 5, 0 };
    people.push_back(temp);
    temp = { 6, 1 };
    people.push_back(temp);
    temp = { 5, 2 };
    people.push_back(temp);
    temp.clear();

    vector<vector<int>> queue = reconstructQueue(people);

    cout << queue[0][1] << queue[0][2];
}

