#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <boost/algorithm/string.hpp>


void invert(std::string &line, int id)
{
    std::vector<std::string> toks;
    boost::split(toks, line, boost::is_any_of(" "));
    std::cout << "Case #" << id << ':';
    for (int i = toks.size() - 1; i >= 0; i--) {
        std::cout << " " << toks[i];
    }
    std::cout << '\n';
}

void exercise(std::ifstream &infile)
{
    std::string line;
    std::getline(infile, line);
    int i = 0;
    for (line; std::getline(infile, line);) {
        invert(line, ++i);
    }
}

int main(void)
{
    std::ifstream infile("B-large-practice.in");
    exercise(infile);
    return 0;
}
