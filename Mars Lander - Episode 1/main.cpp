#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

inline constexpr const float g {3.711};

int main()
{
    int surface_n; // the number of points used to draw the surface of Mars.
    cin >> surface_n; cin.ignore();
    for (int i = 0; i < surface_n; i++) {
        int land_x; // X coordinate of a surface point. (0 to 6999)
        int land_y; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> land_x >> land_y; cin.ignore();
    }

    int y0;
    bool first {true};
    int count {0};

    // game loop
    while (1) {
        int x;
        int y;
        int h_speed; // the horizontal speed (in m/s), can be negative.
        int v_speed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        cin >> x >> y >> h_speed >> v_speed >> fuel >> rotate >> power; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        if (first) {
            y0 = y;
            first = false;
        }

        static const int y_switch = (2*g*y0 - 40*40) / (2*4);

        cerr << "y_switch =" << y_switch << endl;

        int s3 = v_speed - (g - 1);
        s3 += s3 - (g - 2);
        s3 += s3 - (g - 3);
        s3 = -s3;

        cerr << "s3 =" << s3 << endl;

        if (y_switch + s3 >= y) {
            if (count++ < 4) 
                cout << "0 " << count << endl;
            else 
                cout << "0 4" << endl;
        } else {
            cout << "0 0" << endl;
        }

        // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).
    }
}