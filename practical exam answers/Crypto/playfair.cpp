#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
 
using namespace std;
 
string encrypt(string text);
string decrypt(string text);
void createKeyMatrix(string key);
void findInMatrix(char letter, int &row, int &col);
string createPairs(string input);
string removeX(string text);
 
char keyMatrix[5][5];
 
void output() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            cout << keyMatrix[i][j] << " ";
        cout << "\n";
    }
}
 
int main() {
    string input, key, option;
    cout << "key:\n";
    getline(cin, key);
    createKeyMatrix(key);
    output();
    while (1) {
        cout << "Encryption/Decryption (e/d) + input:\n";
        getline(cin, option);
        getline(cin, input);
        char c = option[0];
        if (c == 'e') {
            input = createPairs(input);
            cout << encrypt(input) << endl;
        }
        else if (c == 'd')
            cout << removeX(decrypt(input)) << endl;
        else if (c == 'n') {
            cout << "new key:\n";
            getline(cin, key);
            createKeyMatrix(key);
        }
        else cout << "invalid option\n";
    }
}
 
int mod(int a, int b) {
    int r = a % b;
    return r < 0 ? r + b : r;
}
void replace(string &text, int pos, char from, char to) {
    if (text[pos] == from)   text[pos] = to;
    if (text[pos+1] == from) text[pos+1] = to;
}
void findInMatrix(char letter, int &row, int &col) {
    for (int r = 0; r < 5; ++r)
        for (int c = 0; c < 5; ++c)
            if (letter == keyMatrix[r][c]) {
                row = r; col = c;
                return;
            }
}
string encrypt(string text) {
    string output = "";
    int row1, col1, row2, col2;
    int size = text.length();
    for (int pos = 0; pos < size; pos += 2) {
        replace(text, pos, 'j', 'i');
        findInMatrix(text[pos], row1, col1);
        findInMatrix(text[pos+1], row2, col2);
 
        if (row1 == row2) {
            output += keyMatrix[row1][mod(col1+1, 5)];
            output += keyMatrix[row2][mod(col2+1, 5)];
        }
 
        else if (col1 == col2) {
            output += keyMatrix[mod(row1+1, 5)][col1];
            output += keyMatrix[mod(row2+1, 5)][col2];
        }
 
        // diagonal -> swap columns
        else {
            output += keyMatrix[row1][col2];
            output += keyMatrix[row2][col1];
        }
    }
    return output;
}
 
string decrypt(string text) {
    string output = "";
    int row1, col1, row2, col2;
    int size = text.length();
    for (int pos = 0; pos < size; pos += 2) {
        // get position of pairs in the matrix
        findInMatrix(text[pos], row1, col1);
        findInMatrix(text[pos+1], row2, col2);
 
        // same row -> shift to the right mod 5
        if (row1 == row2) {
            output += keyMatrix[row1][mod(col1-1, 5)];
            output += keyMatrix[row2][mod(col2-1, 5)];
        }
        // same col -> shift down mod 5
        else if (col1 == col2) {
            output += keyMatrix[mod(row1-1, 5)][col1];
            output += keyMatrix[mod(row2-1, 5)][col2];
        }
        // diagonal -> swap columns
        else {
            output += keyMatrix[row1][col2];
            output += keyMatrix[row2][col1];
        }
    }
    return output;
}
 
string removeX(string text) {
    string original = "";
    original += text[0];
    int size = text.length();
 
    // start at 1 and stop at size-1 since we access i-1 AND i+1
    // we do this becase an 'x' will never be at the 0th index
    // aa -> axa
    for (int i = 1; i < size-1; ++i) {
        if (!(text[i] == 'x' && text[i-1] == text[i+1]))
            original += text[i];
    }
 
    // last letter is misssed
    original += text[size-1];
    return original;
}
 
 
// return whether the letter c has already been used
bool found(char c, vector<char> used) {
    return find(used.begin(), used.end(), c) != used.end();
}
 
void createKeyMatrix(string key) {
    vector<char> used; // stores used letters
    used.push_back('j');
    int size = key.length();
    int count = 0;
    char fillLetter = 'a';
 
    for (int row = 0; row < 5; ++row)
        for (int col = 0; col < 5; ++col) {
            if (count < size) { // insert key stage
                char letter = key[count];
                if (!found(letter, used)) {
                    keyMatrix[row][col] = letter;
                    used.push_back(letter);
                }
                else --col; // lag back try next letter
                ++count;
            }
            else { // fill matrix when key is inserted
                if (!found(fillLetter, used))
                    keyMatrix[row][col] = fillLetter;
                else --col; // lag behind
                ++fillLetter;
            }
        }
}
 
string createPairs(string input) {
    string newString = "";
    int size = input.length();
 
    // start at 1 to prevent index out of bounds exception
    // also makes it easier to dodge spaces this way
    for (int i = 1; i < size; ++i) {
        if (!isspace(input[i-1])) {
            newString += input[i-1];
            // if there is a repeat 'aa' then add 'axa'
            if (input[i-1] == input[i])
                newString += 'x';
        }
    }
 
    // size - 1 is missed because we read i - 1 and not i
    newString += input[size-1];
    if ((newString.length() & 1) == 1)
        newString += 'x';
    return newString;
}
 