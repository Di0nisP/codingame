#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <queue>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

/*
void log(std::queue<string> q1, std::queue<string> q2, uint32_t n) noexcept
{
    cerr << "n = " << n << endl;
    if (q1.empty()) {
        cerr << "1: empty" << endl;
    } else {
        cerr << "1: ";
        for (; !q1.empty(); q1.pop())
            cerr << q1.front() << ' ';
        cerr << endl;
    }
    if (q2.empty()) {
        cerr << "2: empty" << endl;
    } else {
        cerr << "2: ";
        for (; !q2.empty(); q2.pop())
            cerr << q2.front() << ' ';
        cerr << endl;
    }
} //*/

int rankValue(const string& card) {
    if (card.empty()) return -1;
    switch (card.at(0)) {
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case '1': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case 'A': return 14;
        default: return -1;
    }
}

/*
string step(
    std::queue<string>& q1, std::queue<string>& q2, 
    std::queue<string> q1s = {}, 
    std::queue<string> q2s = {}, 
    uint32_t n = 1) 
{
    //log(q1, q2, n);
    
    if (q1.empty() || q2.empty()) 
        return "PAT";

    if (rankValue(q1.front()) > rankValue(q2.front())) {
        while (!q1s.empty()) { q1.push(q1s.front()); q1s.pop(); }
        q1.push(q1.front()); q1.pop();
        while (!q2s.empty()) { q1.push(q2s.front()); q2s.pop(); }
        q1.push(q2.front()); q2.pop();
        if (q1.size() > 0 && q2.size() > 0) {
            return step(q1, q2, q1s, q2s, n + 1);
        } else {
            return "1 " + to_string(n);
        }
    }
        
    if (rankValue(q1.front()) < rankValue(q2.front())) {
        while (!q1s.empty()) { q2.push(q1s.front()); q1s.pop(); }
        q2.push(q1.front()); q1.pop();
        while (!q2s.empty()) { q2.push(q2s.front()); q2s.pop(); }
        q2.push(q2.front()); q2.pop();
        if (q1.size() > 0 && q2.size() > 0) {
            return step(q1, q2, q1s, q2s, n + 1);
        } else {
            return "2 " + to_string(n);
        }
    }

    // War
    //if (q1.front().at(0) == q2.front().at(0))

    if (q1.size() < 4 || q2.size() < 4)
        return "PAT";

    for (uint16_t i = 0; i < 4; ++i) {
        q1s.push(q1.front()); q1.pop();
        q2s.push(q2.front()); q2.pop();
    }
    
    return step(q1, q2, q1s, q2s, n);
}; //*/

string step(queue<string>& q1, queue<string>& q2) {
    queue<string> q1s, q2s;
    uint32_t n = 1;

    while (true) {
        if (q1.empty() || q2.empty()) {
            return "PAT";
        }

        const int r1 {rankValue(q1.front())};
        const int r2 {rankValue(q2.front())};

        if (r1 > r2) {
            // Победа q1
            // Добавляем карты из q1s и q2s в q1
            while (!q1s.empty()) { q1.push(q1s.front()); q1s.pop(); }
            q1.push(q1.front()); q1.pop();
            while (!q2s.empty()) { q1.push(q2s.front()); q2s.pop(); }
            q1.push(q2.front()); q2.pop();

            if (q1.empty() || q2.empty()) {
                return "1 " + to_string(n);
            }
            n++;
        } else if (r1 < r2) {
            // Победа q2
            while (!q1s.empty()) { q2.push(q1s.front()); q1s.pop(); }
            q2.push(q1.front()); q1.pop();
            while (!q2s.empty()) { q2.push(q2s.front()); q2s.pop(); }
            q2.push(q2.front()); q2.pop();

            if (q1.empty() || q2.empty()) {
                return "2 " + to_string(n);
            }
            n++;
        } else {
            // Война
            if (q1.size() < 4 || q2.size() < 4) {
                return "PAT";
            }
            for (uint8_t i = 0; i < 4; ++i) {
                q1s.push(q1.front()); q1.pop();
                q2s.push(q2.front()); q2.pop();
            }
            // n не увеличиваем, так как ход не завершён
        }
    }
}

int main()
{
    int n; // the number of cards for player 1
    cin >> n; cin.ignore();

    std::queue<string> q1;
    for (int i = 0; i < n; i++) {
        string cardp_1; // the n cards of player 1
        cin >> cardp_1; cin.ignore();
        q1.push(cardp_1);
    }
    
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    
    std::queue<string> q2;
    for (int i = 0; i < m; i++) {
        string cardp_2; // the m cards of player 2
        cin >> cardp_2; cin.ignore();
        q2.push(cardp_2);
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << step(q1, q2) << endl;
}