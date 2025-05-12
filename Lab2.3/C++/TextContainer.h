#pragma once
#include "StringLine.h"
#include "IKeyGenerator.h"
#include <vector>

using namespace std;

class TextContainer : public IKeyGenerator {
private:
    vector<StringLine> lines;

public:
    void addLine(const StringLine& line);
    void removeLine(size_t index);
    void clear();
    size_t countLinesOfLength(size_t length) const;
    void capitalizeFirstLetters();
    string generateKeyFromFirstLetters() const override;
    size_t getLineCount() const;
    const StringLine& getLine(size_t index) const;
};