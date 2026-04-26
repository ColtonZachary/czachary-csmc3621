#include <iostream>
#include <queue>
#include <cstdlib>  // for atoi
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <row_number>" << endl;
        return 1;
    }

    int N = atoi(argv[1]);
    if (N < 1) {
        cout << "Row number must be >= 1" << endl;
        return 1;
    }

    queue<int> q;
    q.push(1);  // First row

    for (int row = 1; row < N; ++row) {
        int prev = 0;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int current = q.front();
            q.pop();
            int nextVal = current + prev;
            q.push(nextVal);
            prev = current;
        }
        q.push(1);  // Last element of each row is always 1
    }

    // Print the Nth row
    while (!q.empty()) {
        cout << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
    }
    cout << endl;

    return 0;
}
