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
    int nb_floors; // number of floors
    int width; // width of the area
    int nb_rounds; // maximum number of rounds
    int exit_floor; // floor on which the exit is found
    int exit_pos; // position of the exit on its floor
    int nb_total_clones; // number of generated clones
    int nb_additional_elevators; // ignore (always zero)
    int nb_elevators; // number of elevators
    cin >> nb_floors >> width >> nb_rounds >> exit_floor >> exit_pos >> nb_total_clones >> nb_additional_elevators >> nb_elevators; cin.ignore();
    
    vector<pair<int, int>> floor_pos(nb_elevators + 1);
    for (int i = 0; i < nb_elevators; i++) {
        int elevator_floor; // floor on which this elevator is found
        int elevator_pos; // position of the elevator on its floor
        cin >> elevator_floor >> elevator_pos; cin.ignore();
        floor_pos.at(i) = {elevator_floor, elevator_pos};
    }
    floor_pos.at(nb_elevators) = {exit_floor, exit_pos};
    if (floor_pos.size() > 1)
        std::sort(floor_pos.begin(), floor_pos.end(), 
        [](pair<int, int>& a, pair<int, int>& b) { return a.first < b.first; }); 

    // game loop
    while (1) {
        int clone_floor; // floor of the leading clone
        int clone_pos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> clone_floor >> clone_pos >> direction; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        if (direction == "NONE") {
            cout << "WAIT" << endl;
            continue;
        }
       
        //cerr << "clone_floor = " << clone_floor << endl;
        //cerr << "clone_pos = " << clone_pos << endl;
        //cerr << "floor_pos.second = " << floor_pos.at(clone_floor).second << endl;

        const auto& elevator = floor_pos.at(clone_floor);

        if (direction == "RIGHT") {
            if (clone_pos <= elevator.second)
                cout << "WAIT" << endl;
            else
                cout << "BLOCK" << endl;
        } else if (direction == "LEFT") {
            if (clone_pos >= elevator.second)
                cout << "WAIT" << endl;
            else
                cout << "BLOCK" << endl;
        }
    }
}