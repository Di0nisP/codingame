#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <unordered_map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

enum class Action : uint8_t {
    N  = 0b0001, 
    //NE , 
    E  = 0b0010, 
    //SE , 
    S  = 0b0100, 
    //SW , 
    W  = 0b1000, 
    //NW ,
};

inline constexpr uint8_t operator|(Action a, Action b) {
    return static_cast<uint8_t>(a) | static_cast<uint8_t>(b);
};

static const std::unordered_map<uint8_t, std::string> action_str {
    {static_cast<uint8_t>(Action::N),    "N"},
    {Action::N | Action::E,             "NE"},
    {static_cast<uint8_t>(Action::E),    "E"},
    {Action::S | Action::E,             "SE"},
    {static_cast<uint8_t>(Action::S),    "S"},
    {Action::S | Action::W,             "SW"},
    {static_cast<uint8_t>(Action::W),    "W"},
    {Action::N | Action::W,             "NW"},
};

struct Position {
    int x, y;
};

struct Move {
    Move(Position ight, Position initial_T) 
        : ight_ {ight}
        , initial_T_ {initial_T}
        , current_T_ {initial_T}
    {
        
    }

    std::string exec(const int& remaining_turns) {
        uint8_t direction {};

        if (ight_.x > current_T_.x) {
            direction += static_cast<uint8_t>(Action::E);
            ++current_T_.x;
        } else if (ight_.x < current_T_.x) {
            direction += static_cast<uint8_t>(Action::W);
            --current_T_.x;
        }

        if (ight_.y > current_T_.y) {
            direction += static_cast<uint8_t>(Action::S);
            ++current_T_.y;
        } else if (ight_.y < current_T_.y) {
            direction += static_cast<uint8_t>(Action::N);
            --current_T_.y;
        }

        if (action_str.find(direction) != action_str.end()) {
            return action_str.at(direction);
        }

        cerr << "Direction detection error" << endl;

        return "";
    }

private:

    const Position ight_, initial_T_;

    Position current_T_;
};

int main()
{
    int light_x; // the X position of the light of power
    int light_y; // the Y position of the light of power
    int initial_tx; // Thor's starting X position
    int initial_ty; // Thor's starting Y position
    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();

    Move move_obj({light_x, light_y}, {initial_tx, initial_ty});

    // game loop
    while (1) {
        int remaining_turns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remaining_turns; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        cout << move_obj.exec(remaining_turns) << endl;
    }
}