#include Soundex.h

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
    char c = toupper(c)
    auto it = soundexMap.find(c);
    return (it != soundexMap.end()) ? it->second : '0';
}
 
 
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";
 
    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);
    for (size_t i = 1; i <= name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(toupper(name[i]));
        if(code == prevCode){
            continue;
        }
        if ((name[i - 1] == 'H' || name[i - 1] == 'W' || name[i - 1] == 'Y') && code != '0' && code != prevCode) 
        {
            soundex += code;
        }
        else if ((name[i - 1] != 'A' && name[i - 1] != 'E' && name[i - 1] != 'I' && name[i - 1] != 'O' && name[i - 1] != 'U') && code != '0')
        {
            soundex += code;
        }
        prevCode = code;
    }
 
    soundex.resize(4, '0');
    
 
    return soundex;
}
