//
// Created by red on 2019/9/16.
//

#include "ChickProblemN.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int cock, hen, chick;
    int count = 0;
    int cockSum = 0;

    int N = 0;
    cin >> N;

    for (cock = 0; cock <= 100; cock++) {
        hen = (N - 7 * cock) / 4;
        chick = (3 * N + 3 * cock) / 4;
        if (hen <= 0 || chick <= 0) {
            break;
        }
        if ((chick % 3 == 0) && (cock + hen + chick == N) && (cock * 5 + hen * 3 + chick / 3 == N)) {
            cockSum += cock;
            count++;
        }
    }
    if (count == 0) {
        cout << count << " " << -1;
    } else {
        cout << count << " " << cockSum;
    }

    return 0;
}