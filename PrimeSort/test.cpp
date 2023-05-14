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

    sort(arr, arr + n); // ��ԭ�����������

    int primeCnt = 0; // ͳ����������
    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i]))
            primeCnt++;
    }

    int* primeArr = new int[primeCnt]; // ��̬������������ռ�
    int idx = 0; // ���������±�
    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i]))
            primeArr[idx++] = arr[i];
    }

    sort(primeArr, primeArr + primeCnt); // �����������������

    cout << "��������������Ϊ��";
    for (int i = 0; i < primeCnt; i++)
    {
        cout << primeArr[i] << " ";
    }
    cout << endl;

    delete[] primeArr; // �ͷ���������ռ�

    return 0;
}