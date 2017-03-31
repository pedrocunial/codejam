#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


void solve(char c)
{
  unsigned N;
  cin >> N;  // # of wires
  size_t A[N], B[N];
  for (unsigned i = 0; i < N; i++)
    scanf("%lu %lu", &A[i], &B[i]);

  size_t count = 0;
  for (unsigned i = 0; i < N; i++) {
    for (unsigned j = N - 1; j > i; j--) {
      // a > b = 1, c < d = 1; 1 == 1 -> 1
      // a > b = 0, c < d = 0; 0 == 0 -> 1
      if (A[i] < A[j] == B[i] > B[j])
        count++;
    }
  }
  printf("Case #%hhd: %lu\n", c, count);
}

int main(void)
{
  char T;
  scanf("%hhd", &T);
  for (char i = 1; i <= T; i++)
    solve(i);
  return 0;
}
