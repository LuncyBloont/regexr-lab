#include <fstream>
#include <regex>
#include <sstream>
#include <iostream>

int main()
{
    std::ifstream fi("0.txt");
    std::stringstream text;

    text << fi.rdbuf();

    fi.close();

    std::string regPatterns;
    std::getline(std::cin, regPatterns);
    std::regex re(regPatterns);

    const std::string res = std::regex_replace(text.str(), re, "\x1b[30;43m$&\x1b[0m");

    std::cout << res << std::endl;
    
    return 0;
}