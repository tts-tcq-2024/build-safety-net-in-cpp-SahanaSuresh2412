#include "Soundex.h"
using namespace std;
 
char getSoundexCode(char c) {
    std::map<char, char> soundexMap = {
        {'A', '0'}, {'E', '0'}, {'I', '0'}, {'O', '0'}, {'U', '0'},
        {'H', '0'}, {'W', '0'}, {'Y', '0'}, {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
    auto it = soundexMap.find(toupper(c));
    return (it != soundexMap.end()) ? it->second : '0';
}

void handelSoundexCode(std::string& soundex, const std::string& name,char& code,char& prevCode,int index)
{
        std::cout << "Code " << code << std::endl;
        if ((name[index - 1] == 'H' || name[index - 1] == 'W' || name[index - 1] == 'Y')  && code != prevCode && code != '0') 
        {
            soundex += code;
        }
        else if ((name[index - 1] != 'A' && name[index - 1] != 'E' && name[index - 1] != 'I' && name[index - 1] != 'O' && name[index - 1] != 'U'&& code != '0'))
        {
            soundex += code;
        }
}
 
void createSoundex(std::string& soundex, const std::string& name){
    char prevCode = getSoundexCode(name[0]);
    std::cout << "Soundex " << soundex << std::endl;
    for (size_t index = 1; index <= name.length() && soundex.length() < 4; ++index) {
        char code = getSoundexCode(toupper(name[index]));
        if(code == prevCode){
            continue;
        }
        else handelSoundexCode(soundex, name, code, prevCode, index);
        prevCode = code;
    }
    std::cout << "Soundex at end" << soundex << std::endl;
    soundex.resize(4, '0');
}
 
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";
    std::string soundex(1, toupper(name[0]));
    createSoundex(soundex, name);
 
    return soundex;
}
