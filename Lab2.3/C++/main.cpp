#include <iostream>
#include <limits>
#include "TextContainer.h"
#include "StringLine.h"

using namespace std;

void displayMenu() {
    cout << "\n=== Text Container Menu ===" << endl;
    cout << "1. Add line" << endl;
    cout << "2. Remove line" << endl;
    cout << "3. Clear all lines" << endl;
    cout << "4. Generate key from first letters" << endl;
    cout << "5. Count lines of specific length" << endl;
    cout << "6. Capitalize first letters" << endl;
    cout << "7. Display all lines" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

void addLine(TextContainer& container) {
    string line;
    cout << "Enter line to add: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, line);
    container.addLine(StringLine(line));
    cout << "Line added successfully!" << endl;
}

void removeLine(TextContainer& container) {
    size_t index;
    cout << "Enter line index to remove (0-" << container.getLineCount() - 1 << "): ";
    cin >> index;
    if (index < container.getLineCount()) {
        container.removeLine(index);
        cout << "Line removed successfully!" << endl;
    }
    else {
        cout << "Invalid index!" << endl;
    }
}

void countLinesOfLength(const TextContainer& container) {
    size_t length;
    cout << "Enter line length to count: ";
    cin >> length;
    cout << "Number of lines with length " << length << ": "
        << container.countLinesOfLength(length) << endl;
}

void displayAllLines(const TextContainer& container) {
    cout << "\n=== All Lines ===" << endl;
    for (size_t i = 0; i < container.getLineCount(); ++i) {
        cout << i << ": " << container.getLine(i).getText() << endl;
    }
}

int main() {
    TextContainer container;
    int choice = 0;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addLine(container);
            break;
        case 2:
            removeLine(container);
            break;
        case 3:
            container.clear();
            cout << "All lines cleared!" << endl;
            break;
        case 4:
            cout << "Generated key: " << container.generateKeyFromFirstLetters() << endl;
            break;
        case 5:
            countLinesOfLength(container);
            break;
        case 6:
            container.capitalizeFirstLetters();
            cout << "First letters capitalized!" << endl;
            break;
        case 7:
            displayAllLines(container);
            break;
        case 8:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    } while (choice != 8);

    return 0;
}