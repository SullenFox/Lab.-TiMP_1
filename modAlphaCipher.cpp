#include <iostream>
#include <cctype>
#include "modMarshCipher.h"
#include <string>
#include <locale>
#include <codecvt>
using namespace std;

modAlphaCipher::modAlphaCipher(const std::string& skey)
{
    locale loc("ru_RU.UTF-8"); // русская локаль
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //UTF-8 кодек
    wstring ws = codec.from_bytes(numAlpha);
    for (unsigned i=0; i<ws.size(); i++) {
        alphaNum[ws[i]]=i;
    }
    key = convert(skey);
}

std::string modAlphaCipher::encrypt(const std::string& open_text)
{
    std::vector<int> work = convert(open_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

std::string modAlphaCipher::decrypt(const std::string& cipher_text)
{
    std::vector<int> work = convert(cipher_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

inline std::vector<int> modAlphaCipher::convert(const std::string& s)
{
    std::vector<int> result;
    locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
    wstring ws = codec.from_bytes(s); // перекодируем
    for (unsigned i=0; i<ws.size(); i++) {
        result.push_back(alphaNum[ws[i]]);
    }
    return result;
}

inline std::string modAlphaCipher::convert(const std::vector<int>& v)
{
    std::string result;
    locale loc("ru_RU.UTF-8"); // русская локаль для корректной смены регистра
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec; //кодек UTF-8
    wstring ws = codec.from_bytes(numAlpha);
    wstring result_s = codec.from_bytes("");
    for (unsigned i=0; i<v.size(); i++) {
        result_s.push_back(ws[v[i]]);
    }
    result = codec.to_bytes(result_s);
    return result;
}
