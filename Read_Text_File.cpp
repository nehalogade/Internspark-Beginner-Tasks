#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ifstream file("TEXT_File.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    map<string, int> wordFreq;
    string word;

    while (file >> word) {
        // Convert word to lowercase and remove punctuation
        string cleanedWord = "";

        for (char ch : word) {
            if (isalnum(ch)) {
                cleanedWord += tolower(ch);
            }
        }

        if (!cleanedWord.empty()) {
            wordFreq[cleanedWord]++;
        }
    }

    file.close();

    cout << "Word Frequencies:\n";
    for (auto const &pair : wordFreq) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}