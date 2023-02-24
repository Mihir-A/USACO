#include <iostream>

using namespace std;
int numbers[10], N;

bool hasDigit(int d)
{
    for (int i = 0; i < N; i++)
        if (d == numbers[i])
            return true;
    return false;
}

bool numWorks(int num, int len)
{
    int n = 0, cnt = 0;
    while (num > 0)
    {
        int d = num % 10;
        num /= 10;
        n++;
        if (hasDigit(d))
            cnt++;
    }

    return len == n && n == cnt;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    int res = 0;
    for (int a = 0; a < N; a++)
        for (int b = 0; b < N; b++)
            for (int c = 0; c < N; c++)
                for (int d = 0; d < N; d++)
                {
                    for (int e = 0; e < N; e++)
                    {
                        int num1 = numbers[a] * 100 + numbers[b] * 10 + numbers[c];
                        int num2 = numbers[d] * 10 + numbers[e];
                        int num3 = num1 * numbers[d];
                        int num4 = num1 * numbers[e];
                        int num5 = num1 * num2;

                        if (numWorks(num3, 3) && numWorks(num4, 3) && numWorks(num5, 4))
                        {
                            res++;
                        }
                    }
                }
    cout << res << endl;

    return 0;
}