#include <iostream>
#include <vector>
#include <algorithm>  // std::sort


void fillvec(std::vector<long> &v, size_t n)
{
  for (size_t i = 0; i < n; i++) {
    long tmp;
    scanf("%ld", &tmp);
    v.push_back(tmp);
  }
}

void problem(size_t T)
{
  long prod = 0;
  size_t n;
  std::vector<long> v1, v2;

  scanf("%lu", &n);
  fillvec(v1, n);
  fillvec(v2, n);
  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end(),
            [](const long a, const long b)
            {
              return a > b;
            });

  for (size_t i = 0; i < n; i++)
    prod += v1[i] * v2[i];

  printf("Case #%lu: %ld\n", T, prod);
}

int main(void)
{
  size_t T;
  scanf("%lu", &T);
  for (size_t i = 1; i <= T; i++)
    problem(i);
  return 0;
}
