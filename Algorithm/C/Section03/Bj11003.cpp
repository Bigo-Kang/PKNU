//
// Created by 강대원 on 09/10/2018.
//
#include <iostream>
#include <deque>
using namespace std;

const int MAX = 5000000;

int arr[MAX];
deque<pair<int, int>> dq; //value, idx

int main(void)
{

    int N, L;
    cin >> N >> L;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
    {
        //dq에는 최대 L개의 값이 저장
        if (!dq.empty() && dq.front().second <= i - L)
            dq.pop_front();
        //arr[i]가 덱 내에서 제일 큰 숫자
        while (!dq.empty() && dq.back().first > arr[i])
            dq.pop_back();

        dq.push_back(make_pair(arr[i], i));
        cout << dq.front().first << " ";
    }
    cout << "\n";
    return 0;
}
