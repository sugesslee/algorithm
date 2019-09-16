//
// Created by red on 2019/9/16.
//

#include "ChickProblem.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int cock, hen, chick;
    int count = 0;
    int result[4][3];

    for (cock = 0; cock <= 20; cock++) {
        hen = (100 - 7 * cock) / 4;
        chick = (300 + 3 * cock) / 4;
        if (hen <= 0 || chick <= 0) {
            break;
        }
        if ((chick % 3 == 0) && (cock + hen + chick == 100) && (cock * 5 + hen * 3 + chick / 3 == 100)) {
            result[count][0] = cock;
            result[count][1] = hen;
            result[count][2] = chick;
            count++;
        }
    }
    cout << count << endl;

    for (int i = 0; i < sizeof(result[0][0]); i++) {
        cout << "cock=" << setw(3) << result[i][0] << ",hen=" << setw(3) << result[i][1] << ",chick=" << setw(3)
             << result[i][2] << endl;
    }

    return 0;
}
