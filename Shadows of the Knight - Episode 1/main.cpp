#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <cmath>
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct Position {
    int x, y;

    std::string str() const {
        return to_string(x) + " " + to_string(y);
    }
};

struct Area {
    Position min, max;

    void fix_x(int x) {
        max.x = min.x = x;
    }

    void fix_y(int y) {
        max.y = min.y = y;
    }
};

int main()
{
    int w; // width of the building.
    int h; // height of the building.
    cin >> w >> h; cin.ignore();
    int n; // maximum number of turns before game over.
    cin >> n; cin.ignore();
    int x0;
    int y0;
    cin >> x0 >> y0; cin.ignore();

    Position pos_0 {x0, y0}, pos_1 {pos_0};
    Area area {{0, 0}, {w-1, h-1}};

    // game loop
    while (1) {
        string bomb_dir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cerr << "Status: " << bomb_dir << endl;

        cerr << "Area0: " 
        << "(" << area.min.x << ", " << area.min.y << ") "
        << "(" << area.max.x << ", " << area.max.y << ")" 
        << endl;
        
        if (bomb_dir.find("U") != std::string::npos) {
            area.max.y = pos_0.y - 1;
        } else if (bomb_dir.find("D") != std::string::npos) {
            area.min.y = pos_0.y + 1;
        } else {
            area.fix_y(pos_0.y);
        }

        if (bomb_dir.find("R") != std::string::npos) {
            area.min.x = pos_0.x + 1;
        } else if (bomb_dir.find("L") != std::string::npos) {
            area.max.x = pos_0.x - 1;
        } else {
            area.fix_x(pos_0.x);
        }

        cerr << "Area1: " 
        << "(" << area.min.x << ", " << area.min.y << ") "
        << "(" << area.max.x << ", " << area.max.y << ")" 
        << endl;

        //pos_1.x = std::ceil((area.min.x + area.max.x) / 2.0f);
        //pos_1.y = std::ceil((area.min.y + area.max.y) / 2.0f);
        pos_1.x = (area.min.x + area.max.x) / 2;
        pos_1.y = (area.min.y + area.max.y) / 2;

        pos_0 = pos_1;

        // the location of the next window Batman should jump to.
        cout << pos_1.str() << endl;
    }
}