#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class StringLine {
private:
    string text;

public:
    explicit StringLine(const string& text);
    string getText() const;
    string getKeyFromFirstLetters() const;
};