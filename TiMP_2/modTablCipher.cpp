#include <iostream>
#include <cctype>
#include "modTablCipher.h"
#include <string>
#include <locale>
#include <codecvt>
using namespace std;

std::string modTablCipher::encrypt(const std::string& open_text)
{
    string n_s = open_text;
    int dl, nstrok, index, k;
    dl = open_text.length();
    nstrok = (dl - 1) / key1 + 1;
    k = 0;
    for (int i = key1; i > 0; i--) {
        for (int j = 0; j < nstrok; j++) {
            index = i+key1*j;
            if (index-1 < dl) {
                n_s[k] = open_text[index-1];
                k++;
            }
        }
    }
    return n_s;
}

std::string modTablCipher::decrypt(const std::string& cipher_text)
{
    string n_s = cipher_text;
    int dl, nstrok, index, k;
    dl = cipher_text.length();
    nstrok = (dl - 1) / key1 + 1;
    k = 0;
    for (int i = key1; i > 0; i--) {
        for (int j = 0; j < nstrok; j++) {
            index = i+key1*j;
            if (index-1 < dl) {
                n_s[index-1] = cipher_text[k];
                k++;
            }
        }
    }
    return n_s;
}
