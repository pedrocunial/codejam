#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>


using namespace std;

void prob(long n, char c)
{
    long ans = n;
    vector<char> digits;
    // while (ans > 0) {
    //     digits.push_back(ans % 10);
    //     ans /= 10;
    // }
    // char len = digits.size();
    while (n > 0) {
        ans = n;
        char past = ans % 10;
        char fail = -1;
        char id = 0;
        ans /= 10;
        while (ans > 0) {
            char curr = ans % 10;
            if (curr > past) {
                fail = id;
                break;
            }
            past = curr;
            ans /= 10;
            id++;
        }
        if (fail != -1)
            // printf("ans = %lu", ans);
            n -= pow(10, id);
        else
            break;
        printf("%hhd\n", id);
        printf("%ld\n", n);
    }
    printf("Case #%hhd: %ld", c, n);
    printf("\n");
    // while (1) {
    //     if (c == 2) {
    //         for (char i = lid; i >= 0; i--) {
    //             if (digits[i] != 0)
    //                 printf("%hhd", digits[i]);
    //         }
    //         printf("\n");
    //     }
    //     char flag = 1;
    //     for (char i = lid; i > 0; i--) {
    //         if (digits[i] > digits[i - 1]) {
    //             if (digits[i - 1] > 0) {
    //                 digits[i - 1]--;
    //             } else {
    //                 char j = i - 1;
    //                 while (digits[j] == 0) {
    //                     digits[j] = 9;
    //                     j++;
    //                 }
    //                 digits[i]--;
    //             }
    //             flag = 0;
    //             break;
    //         }
    //     }
    //     if (flag) break;
    // }
    // printf("Case #%hhd: ", c);
    // for (char i = lid; i >= 0; i--) {
    //     if (digits[i] != 0)
    //         printf("%hhd", digits[i]);
    // }
    // printf("\n");
}

int main(void)
{
    char T;
    scanf("%hhd", &T);
    for (char i = 1; i <= T; i++) {
        long N;
        scanf("%lu", &N);
        prob(N, i);
    }
    return 0;
}
