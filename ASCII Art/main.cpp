#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int l; cin >> l; cin.ignore();
    int h; cin >> h; cin.ignore();
    
    string t; getline(cin, t);

    vector<string> font(h);
    for (int i = 0; i < h; i++) {
        getline(cin, font.at(i));
    }

    for (char &c : t)
        c = toupper(static_cast<unsigned char>(c));

    for (int r = 0; r < h; r++) {
        string row;
        for (char c : t) {
            const int idx = (c >= 'A' && c <= 'Z') ? c - 'A' : 26; // 26 = '?'
            row += font.at(r).substr(idx * l, l);
        }
        cout << row << '\n';
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
}