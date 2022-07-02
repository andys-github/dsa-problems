#include <iostream>
#include <vector>

using namespace std;

void solve1(vector<int> arr, int d);
void solve2(vector<int> arr, int d);
void solve3(vector<int> arr, int d);
void reverse(vector<int> &arr, int lo, int hi);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int inputArraySize, rotateBy;

    cin >> inputArraySize;
    cin >> rotateBy;

    vector<int> inputArray(inputArraySize);

    for(int i = 0; i < inputArraySize; i++) {
        cin >> inputArray[i];
    }

    // Solution 1
    cout << "Solution 1: " << endl;
    solve1(inputArray, rotateBy);

    cout << endl << endl;

    // Solution 2
    cout << "Solution 2: " << endl;
    solve2(inputArray, rotateBy);

    cout << endl << endl;

    // Solution 3
    cout << "Solution 3: " << endl;
    solve3(inputArray, rotateBy);

    return 0;
}

void solve1(vector<int> arr, int d) {
    int n = arr.size();
    vector<int> result(n);

    for(int i = 0; i < n; i++) {
        int newLocation = i - d;

        if (newLocation < 0) {
            newLocation = newLocation + n;
        }

        result[newLocation] = arr[i];
    }

    for(int el : result) cout << el << " ";
}

void solve2(vector<int> arr, int d) {
    int n = arr.size();
    vector<int> result(n);

    for(int i = 0; i < n; i++) {
        result[i] = arr[(i + d) % n];
    }

    for(int el : result) cout << el << " ";
}

void solve3(vector<int> arr, int d) {
    int n = arr.size();

    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);

    for(int el : arr) cout << el << " ";
}

void reverse(vector<int> &arr, int lo, int hi) {
    while(lo < hi) {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}
