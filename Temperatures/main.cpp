#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>

#include <optional>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();

    int negativ {-273}, positiv {5526};
    bool allow_negativ {}, allow_positiv {};

    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();

        cerr << "t = " << t << endl;

        if (t < 0) {
            allow_negativ = true;
            if (t > negativ) negativ = t;
        } else {
            allow_positiv = true;
            if (t < positiv) positiv= t;
            if (t == 0) break;
        }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    int result = 0;
    if (allow_negativ) {
        if (allow_positiv) {
            result = (-negativ) >= positiv ? positiv : negativ;
        } else {
            result = negativ;
        }
    } else {
        if (allow_positiv) {
            result = positiv;
        }
    }
    
    cout << result << endl;

}