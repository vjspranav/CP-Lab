#include <bits/stdc++.h>
using namespace std;

int maxSubSeq(int arr[], int n)
{
    int max = 0, i, j;
    int dp[n];

    for (i = 0; i < n; i++)
        dp[i] = arr[i];

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
                dp[i] = dp[j] + arr[i];

    for (i = 0; i < n; i++)
        if (max < dp[i])
            max = dp[i];

    return max;
}