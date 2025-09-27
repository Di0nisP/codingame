#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <deque>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

/*
string func(int l, int c, vector<int>& q) 
{
    if (q.size() == 0 || l == 0 || c == 0) 
        return "0";
    
    uint64_t dirhams {};
    for (; c > 0; --c) {
        uint64_t pi_count {static_cast<uint64_t>(q.front())};
        if (l > pi_count) {
            for (size_t i = 1; i < q.size(); ++i) {
                const uint64_t pi_count_tmp {pi_count + q.at(i)};
                if (l >= pi_count_tmp) {
                    pi_count = pi_count_tmp;
                } else {
                    q.insert(q.end(), q.begin(), q.begin() + i);
                    q.erase(q.begin(), q.begin() + i);
                    break;
                }
            }
        } else if (l == pi_count) {
            q.push_back(q.front());
            q.erase(q.cbegin(), q.cbegin() + 1);
        } else {
            return to_string(dirhams);
        }
        dirhams += pi_count;
    }
    
    return to_string(dirhams);
} //*/


// O(N + C)
string func(int L, int C, const vector<int>& q) {
    size_t N = q.size();
    if (N == 0 || L == 0 || C == 0) return "0";

    // O(N)
    vector<int> q2(2 * N);
    for (size_t i = 0; i < N; ++i) {
        q2[i] = q[i];
        q2[i + N] = q[i];
    }

    vector<long long> earnings(N);
    vector<int> nextPos(N);

    long long sum = 0;
    size_t r = 0;
    for (size_t i = 0; i < N; ++i) {
        while (r < i + N && sum + q2[r] <= L) {
            sum += q2[r];
            ++r;
        }
        earnings[i] = sum;  // Сколько людей сядет, если стартуем с позиции i
        nextPos[i] = r % N; // Где окажется начало очереди после посадки
        sum -= q2[i];
    }

    // O(C)
    // Симуляция запусков с обнаружением циклов
    
    long long total = 0;    // Накопленная сумма людей
    int pos = 0;            // Текущее начало в очереди
    long long ride = 0;     // Номер запуска
    // Массивы для обнаружения повторяющихся состояний
    vector<long long> seenRide(N, -1);
    vector<long long> seenTotal(N, 0);

    while (ride < C) {
        if (seenRide[pos] != -1) {
            const long long &prevRide = seenRide[pos];
            const long long &prevTotal = seenTotal[pos];
            const long long cycleLen = ride - prevRide;
            const long long cycleProfit = total - prevTotal;
            if (cycleLen > 0) {
                const long long remaining = C - ride;
                const long long cyclesToSkip = remaining / cycleLen;
                if (cyclesToSkip > 0) {
                    total += cyclesToSkip * cycleProfit;
                    ride += cyclesToSkip * cycleLen;
                }
            }
        }
        if (ride >= C) break;

        seenRide[pos] = ride;
        seenTotal[pos] = total;

        total += earnings[pos];
        pos = nextPos[pos];
        ++ride;
    }

    return to_string(total);
}

int main()
{
    int l;
    int c;
    int n;
    cin >> l >> c >> n; cin.ignore();

    vector<int> q;
    for (int i = 0; i < n; i++) {
        int pi;
        cin >> pi; cin.ignore();
        q.push_back(pi);
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << func(l, c, q) << endl;
}