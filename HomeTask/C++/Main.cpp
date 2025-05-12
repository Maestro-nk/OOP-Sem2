#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

class CharMatrix {
private:
    vector<vector<char>> matrix;
    int vowelCount;

    bool isVowel(char c) {
        char lower = tolower(c);
        return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
    }

public:
    CharMatrix(int rows, int cols) : vowelCount(0) {
        matrix.resize(rows, vector<char>(cols));
        srand(time(0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = 'a' + rand() % 26;
                if (isVowel(matrix[i][j])) {
                    vowelCount++;
                }
            }
        }
    }

    string operator[](int diagonal) {
        if (diagonal != 0 && diagonal != 1) {
            throw out_of_range("Diagonal must be 0 (main) or 1 (anti)");
        }

        int size = min(matrix.size(), matrix[0].size());
        string result;

        if (diagonal == 0) {
            for (int i = 0; i < size; ++i) {
                result += matrix[i][i];
            }
        }
        else {
            for (int i = 0; i < size; ++i) {
                result += matrix[i][size - 1 - i];
            }
        }

        return result;
    }

    int getVowelCount() const {
        return vowelCount;
    }
};

int main() {
    CharMatrix cm(5, 5);

    cout << "Main diagonal: " << cm[0] << endl;
    cout << "Anti diagonal: " << cm[1] << endl;
    cout << "Vowel count: " << cm.getVowelCount() << endl;

    return 0;
}