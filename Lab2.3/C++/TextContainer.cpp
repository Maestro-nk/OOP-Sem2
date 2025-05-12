#include "TextContainer.h"
#include <cctype>

void TextContainer::addLine(const StringLine& line) {
    lines.push_back(line);
}

void TextContainer::removeLine(size_t index) {
    if (index < lines.size()) {
        lines.erase(lines.begin() + index);
    }
}

void TextContainer::clear() {
    lines.clear();
}

size_t TextContainer::countLinesOfLength(size_t length) const {
    return count_if(lines.begin(), lines.end(),
        [length](const StringLine& line) {
            return line.getText().length() == length;
        });
}

void TextContainer::capitalizeFirstLetters() {
    for (auto& line : lines) {
        string text = line.getText();
        if (text.empty()) continue;

        bool newWord = true;
        for (char& c : text) {
            if (newWord && isalpha(c)) {
                c = toupper(c);
                newWord = false;
            }
            else if (isspace(c)) {
                newWord = true;
            }
        }
    }
}

string TextContainer::generateKeyFromFirstLetters() const {
    string result;
    for (const auto& line : lines) {
        result += line.getKeyFromFirstLetters();
    }
    return result;
}

size_t TextContainer::getLineCount() const {
    return lines.size();
}

const StringLine& TextContainer::getLine(size_t index) const {
    return lines.at(index);
}