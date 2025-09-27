#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/

int main()
{
    constexpr const int mountain_count {8}; // +
    std::vector<int> mountain_h_array {}; // +
    mountain_h_array.reserve(static_cast<std::size_t>(mountain_count));

    // game loop
    while (1) {
        mountain_h_array.clear();
        
        for (int i = 0; i < mountain_count; i++) {
            int mountain_h; // represents the height of one mountain.
            cin >> mountain_h; cin.ignore();
            mountain_h_array.emplace_back(mountain_h); // +
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        const auto me {std::max_element(mountain_h_array.cbegin(), mountain_h_array.cend())};
        const int pos {static_cast<int>(std::distance(mountain_h_array.cbegin(), me))};

        cout << to_string(pos) << endl; // The index of the mountain to fire on.
    }
}