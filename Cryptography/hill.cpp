#include <iostream>
using namespace std;

// Key matrix (2x2)
int key[2][2] = {
    {2, 3},
    {1, 5}
};

// Function to encrypt the plaintext
string encrypt(string plaintext) {
    // Resulting ciphertext
    string ciphertext = "";

    // Iterate through the plaintext in pairs of 2
    for (int i = 0; i < plaintext.length(); i += 2) {
        // Get the next pair of letters from the plaintext
        char a = plaintext[i];
        char b = plaintext[i + 1];

        // Convert the letters to numbers (A = 0, B = 1, ..., Z = 25)
        int a_num = a - 'A';
        int b_num = b - 'A';

        // Perform matrix multiplication to get the corresponding ciphertext letters
        int c_num = (key[0][0] * a_num + key[0][1] * b_num) % 26;
        int d_num = (key[1][0] * a_num + key[1][1] * b_num) % 26;

        // Convert the numbers back to letters
        char c = 'A' + c_num;
        char d = 'A' + d_num;

        // Append the letters to the ciphertext
        ciphertext += c;
        ciphertext += d;
    }

    return ciphertext;
}

// Function to decrypt the ciphertext
string decrypt(string ciphertext) {
    // Resulting plaintext
    string plaintext = "";

    // Inverse of the key matrix
    int inv_key[2][2] = {
        {9, 21},
        {5, 8}
    };

    // Iterate through the ciphertext in pairs of 2
    for (int i = 0; i < ciphertext.length(); i += 2) {
        // Get the next pair of letters from the ciphertext
        char c = ciphertext[i];
        char d = ciphertext[i + 1];

        // Convert the letters to numbers (A = 0, B = 1, ..., Z = 25)
        int c_num = c - 'A';
        int d_num = d - 'A';

        // Perform matrix multiplication to get the corresponding plaintext letters
        int a_num = (inv_key[0][0] * c_num + inv_key[0][1] * d_num) % 26;
        int b_num = (inv_key[1][0] * c_num + inv_key[1][1] * d_num) % 26;

        // Convert the numbers back to letters
        char a = 'A' + a_num;
        char b = 'A' + b_num;

        // Append the letters to the plaintext
        plaintext += a;
        plaintext += b;
    }

    return plaintext;
}

int main() {
    // Get the plaintext from the user
    string plaintext;
    int option;
    cout<<"Student roll no : 23497"<<endl;
    cout << "Enter the plaintext: ";
    cin >> plaintext;
    cout<<"The encryted text is :"<<encrypt(plaintext)<<endl;
    cout<<"The decrypted text is :"<<decrypt(plaintext);
    return 0;

}

