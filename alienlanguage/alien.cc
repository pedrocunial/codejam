#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>


void generate_words(std::unordered_set<char> words[], unsigned char L)
{
  unsigned char i = 0;
  unsigned char in_par = 0;
  std::string line;
  std::cin >> line;
  for (char c : line) {
    switch (c) {
    case '(':
      in_par = true;
      break;
    case ')':
      in_par = false;
      break;
    default:
      words[i].insert(c);
    }
    if (!in_par) i++;
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

void check_words(std::unordered_set<char> words[],
                 std::unordered_set<std::string> &dic,
                 unsigned char L,
                 unsigned _case)
{
  std::unordered_set<std::string> _dic(dic);
  std::unordered_set<std::string> ans;
  for (unsigned char i = 0; i < L; i++) {
    for (std::string str : _dic) {
      if (words[i].find(str[i]) != words[i].end())
        ans.insert(str);
    }
    _dic = ans;
    ans.clear();
  }
  printf("Case #%u: %lu\n", _case, _dic.size());
}

int main(void)
{
  std::unordered_set<std::string> dic;
  unsigned char L;
  unsigned D, N;
  scanf("%hhu %u %u", &L, &D, &N);
  create_dic(D, dic);
  for (unsigned i = 1; i <= N; i++) {
    std::unordered_set<char> words[L];
    generate_words(words, L);
    check_words(words, dic, L, i);
  }
  return 0;
}
