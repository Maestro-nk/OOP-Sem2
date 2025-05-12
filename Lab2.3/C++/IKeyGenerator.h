#pragma once
#include <string>

using namespace std;

class IKeyGenerator {
public:
    virtual ~IKeyGenerator() = default;
    virtual string generateKeyFromFirstLetters() const = 0;
};