#pragma once
#include <vector>
#include <string>
#include <map>
class modAlphaCipher
{
private:
    std::string numAlpha =
        "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //русский алфави
    std::map <char,int> alphaNum; 
    std::vector <int> key; 
    std::vector <int> convert(const std::string& s); 
    std::string convert(const std::vector<int>& v); 
public:
    modAlphaCipher()=delete; 
    modAlphaCipher(const std::string& skey); 
    std::string encrypt(const std::string& open_text); 
    std::string decrypt(const std::string& cipher_text);
};
