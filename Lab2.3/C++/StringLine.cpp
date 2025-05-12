#include "StringLine.h"

StringLine::StringLine(const string& text) : text(text) {}

string StringLine::getText() const {
    return text;
}

string StringLine::getKeyFromFirstLetters() const {
    if (text.empty()) return "";

    istringstream iss(text);
    string word;
    string result;

    while (iss >> word) {
        if (!word.empty()) {
            result += word[0];
        }
    }
    return result;
}