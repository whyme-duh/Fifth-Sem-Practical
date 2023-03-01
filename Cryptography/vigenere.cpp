#include <iostream>
#include <string>

using namespace std;

string vigenereEncrypt(string plaintext, string key) {
    string ciphertext;

    // Iterate through the plaintext
    for (int i = 0, j = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];

        // Encrypt only alphabetical characters
        if (c >= 'a' && c <= 'z') {
            c = (c + key[j] - 2 * 'a') % 26 + 'a';
            j = (j + 1) % key.length();
        }
        else if (c >= 'A' && c <= 'Z') {
            c = (c + key[j] - 2 * 'A') % 26 + 'A';
            j = (j + 1) % key.length();
        }

        ciphertext += c;
    }

    return ciphertext;
}

string vigenereDecrypt(string ciphertext, string key) {
    string plaintext;

    // Iterate through the ciphertext
    for (int i = 0, j = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];

        // Decrypt only alphabetical characters
        if (c >= 'a' && c <= 'z') {
            c = (c - key[j] + 26) % 26 + 'a';
            j = (j + 1) % key.length();
        }
        else if (c >= 'A' && c <= 'Z') {
            c = (c - key[j] + 26) % 26 + 'A';
            j = (j + 1) % key.length();
        }

        plaintext += c;
    }

    return plaintext;
}

int main() {
    string plaintext, key;
    int option;
    cout<<"Student Roll No: 23497"<<endl;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
   
    cout << "Enter key: ";
    getline(cin, key);
    cout<<"Enter 0 for encryption and 1 for decryption:";
    cin>>option;
    string ciphertext = vigenereEncrypt(plaintext, key);
    string decryptedtext = vigenereDecrypt(plaintext, key);
    switch (option)
    {
    case 0:
        cout << "Encrypted text: " << ciphertext << endl;
        break;
    case 1:
        cout << "Decrypted text: " << decryptedtext << endl;
        break;
    default:
        break;
    }
    return 0;
}
