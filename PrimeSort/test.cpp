#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
        return false;

    int sqrtNum = sqrt(num);
    for (int i = 2; i <= sqrtNum; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int arr[] = { 3, 7, 2, 8, 5, 11, 13, 17, 19, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n); // 对原数组进行排序

    int primeCnt = 0; // 统计素数个数
    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i]))
            primeCnt++;
    }

    int* primeArr = new int[primeCnt]; // 动态分配素数数组空间
    int idx = 0; // 素数数组下标
    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i]))
            primeArr[idx++] = arr[i];
    }

    sort(primeArr, primeArr + primeCnt); // 对素数数组进行排序

    cout << "排序后的素数数组为：";
    for (int i = 0; i < primeCnt; i++)
    {
        cout << primeArr[i] << " ";
    }
    cout << endl;

    delete[] primeArr; // 释放素数数组空间

    return 0;
}