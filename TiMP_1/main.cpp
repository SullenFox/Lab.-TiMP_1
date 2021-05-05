#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <string>
#include <locale>
#include <codecvt>
using namespace std;
bool isValid(const string& s)
{
    std::locale loc("ru_RU.UTF-8");
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    std::wstring ws = codec.from_bytes(s);
    std::string numAlpha = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    std::wstring wA = codec.from_bytes(numAlpha);
    for(int i = 0; i < ws.size(); i++) {
        if (wA.find(ws[i]) == string::npos) {
            return false;
        }
    }
    return true;
}
int main(int argc, char **argv)
{
    string key;
    string text;
    unsigned op;
    cout<<"Cipher ready. Input key: ";
    cin>>key;
    if (!isValid(key)) {
        cerr<<"key not valid\n";
        return 1;
    }
    cout<<"Key loaded\n";
    modAlphaCipher cipher(key);
    do {
        cout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        cin>>op;
        if (op > 2) {
            cout<<"Illegal operation\n";
        } else if (op >0) {
            cout<<"Cipher ready. Input text: ";
            cin>>text;
            if (isValid(text)) {
                if (op==1) {
                    cout<<"Encrypted text: "<<cipher.encrypt(text)<<endl;
                } else {
                    cout<<"Decrypted text: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                cout<<"Operation aborted: invalid text\n";

            }
        }
    } while (op!=0);
    return 0;
}
