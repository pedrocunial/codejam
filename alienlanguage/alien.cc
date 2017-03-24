#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>


void generate_words(std::vector<std::string> &words, unsigned char L)
{
  unsigned char i = 0;
  std::string line;
  std::cin >> line;
  while (i < L) {

  }
}

void create_dic(unsigned D, std::unordered_set<std::string> &dic)
{
  std::string *v = new std::string[D];
  while (D--) {
    std::cin >> v[D];
    dic.insert(v[D]);
  }
}

int main(void)
{
  std::unordered_set<std::string> dic;
  unsigned char L;
  unsigned D, N;
  scanf("%hhu %u %u", &L, &D, &N);
  create_dic(D, dic);
  for (unsigned i = 0; i < N; i++) {
    std::vector<std::string> words;
    generate_words(words, L);
  }
  return 0;
}
