#include <iostream>

using namespace std;

int main() {
    string s;
    int t = 0;
    while(getline(cin, s) && s != "#") {
        
        t++;
        
        cout << "Case " << t << ": ";
        
        if (s == "HELLO") {
            cout << "ENGLISH";
        } else if (s == "HOLA") {
            cout << "SPANISH";
        } else if (s == "HALLO") {
            cout << "GERMAN";
        } else if (s == "BONJOUR") {
            cout << "FRENCH";
        } else if (s == "CIAO") {
            cout << "ITALIAN";
        } else if (s == "ZDRAVSTVUJTE") {
            cout << "RUSSIAN";
        } else {
            cout << "UNKNOWN";
        }
        
        cout << "\n";
        
    }
}
