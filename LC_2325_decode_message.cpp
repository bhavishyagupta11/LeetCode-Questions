#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Step 1: Create mapping
string decodeMessage(string key, string message) {
    unordered_map<char, char> mapping;
    char space = ' ';
    mapping[space]= space;

    char start = 'a';
    int index = 0;

while(start <= 'z' && index < key.length()) {
    char keyKaCurrentCharacter = key[index];
    // start -> mapping abcd;
    // mapping -> keykaCurrentCharacter -> alphabet

    // Check if the current character is already mapped
    if (mapping.find(keyKaCurrentCharacter) != mapping.end()) {
        // agar currCharacter ki mapping already present hai
        //no need to store any mapping here
        //just move to next character ink key
        // If mapping is already present, move to the next character

    index++ ;
    } 
    else {
        // If not present, create mapping and move ahead
        mapping[keyKaCurrentCharacter] = start;
        start++;
        index++;
    }
}


// Step 2: Use mapping to decode the message
string ans = " ";

for(int i = 0;i<message.length();i++) {
    char msgCharacter = message[i];
    char mappedCharacter = mapping[msgCharacter];
    ans.push_back(mappedCharacter);
}

return ans;
}

int main() {
    string key, message;
    cout << "Enter the key: ";
    getline(cin, key);

    cout << "Enter the message to decode: ";
    getline(cin, message);

    string decodedMessage = decodeMessage(key, message);
    cout << "Decoded Message: " << decodedMessage << endl;

    return 0;
}
