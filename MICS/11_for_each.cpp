// 11_for_each.cpp

#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

void Print(int& v) { cout << v << endl; }

int main()
{
    int arr[5] = { 1,2,3,4,5 };
    vector<int> vec = { 1,2,3,4,5 };

    // ���� ����ϴ� ���
    if (false)
    {
        for (auto& ele : arr)
            Print(ele);

        for (int i = 0; i < 5; i++)
        {
            arr[i]++;
        }

        for (auto& ele : arr)
            Print(ele);

        cout << endl << endl;

        for (auto& ele : vec)
            Print(ele);

        for (int i = 0; i < 5; i++)
        {
            vec[i]++;
        }

        for (auto& ele : vec)
            Print(ele);
    }

    if (true)
    {
        for_each(arr, &arr[5], Print);

        for_each(arr, &arr[5], [](int& n) {n++; });

        for_each(arr, &arr[5], Print);
        cout << endl << endl;

        for_each(vec.begin(), vec.end(), Print);

        for_each(vec.begin(), vec.end(), [](int& n) {n++; });

        for_each(vec.begin(), vec.end(), Print);
    }
    return 0;
}