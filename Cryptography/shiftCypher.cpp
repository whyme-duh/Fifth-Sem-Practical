// WAP to Implement shift cipher (Encyrption and Decryption/ input should be taken by the user)

#include<iostream>
using namespace std;

int encryption(){
    char text[100], ch;
    int key;
    cout<<"Enter any key : ";
    cin>>key;

    cout<<"Enter the text to encrypt :";
    cin >> text;
    for(int i = 0; text[i] != '\0'; ++i){
        ch = text[i];
        if(ch >='a' && ch <= 'z'){
            ch =ch + key;
            if(ch < 'a') {
                ch = ch + 'z' - 'a'  + 1; 
            }
            text[i] = ch;
        }
        
        else if(ch >= 'A' && ch <= 'Z'){
            ch =ch + key;
            if(ch < 'A'){
                ch = ch  + 'Z' - 'A' +1;
            }
            text[i] = ch;
        }
        
    }
    cout<<"Encrpted text : " << text;
    return 0;
}


int decryption(){
    char text[100], ch;
    int key;
    cout<<"Enter any key : ";
    cin>>key;
    cout<<"Enter the text to decrypt :";
    cin >> text;
    for(int i = 0; text[i] != '\0'; ++i){
        ch = text[i];
        if(ch >='a' && ch <= 'z'){
            ch =ch - key;
            if(ch < 'a') {
                ch = ch - 'z' + 'a'  - 1; 
            }
            text[i] = ch;
        }
        
        else if(ch >= 'A' && ch <= 'Z'){
            ch =ch - key;
            if(ch < 'A'){
                ch = ch  - 'Z' + 'A' - 1;
            }
            text[i] = ch;
        }
        
    }
    cout<<"Encrpted text : " << text;
    return 0;
}

int main(){
    int option;
    cout<<"Student roll no : 23497"<<endl;
    cout<<"Press 1 for encryption and 2 for decryption: ";
    cin>>option;
    
    switch (option)
    {
    case 1:
        encryption();
        break;

    case 2:
        decryption();
        break;
    
    default:

        break;
    }
}




