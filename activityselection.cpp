#include <iostream>
using namespace std;

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    int n = 6;

    cout << "Selected Activities:\n";

    int i = 0;
    cout << "A" << i + 1 << endl;

    for (int j = 1; j < n; j++) {
        if (start[j] >= finish[i]) {
            cout << "A" << j + 1 << endl;
            i = j;
        }
    }

    return 0;
}