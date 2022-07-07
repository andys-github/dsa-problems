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

    // Get the number of elements in array
    int numberOfElementsInArray;
    cin >> numberOfElementsInArray;

    // Initialize the array
    vector<int> inputArray(numberOfElementsInArray);
    
    // Store the rotation amount
    int rotateBy;
    cin >> rotateBy;

    // Fill up the array
    for(int i = 0; i < numberOfElementsInArray; i++) {
        cin >> inputArray[i];
    }

    // Solve 1
    cout << "Solution 1: " << endl;
    solve1(inputArray, rotateBy);

    cout << endl << endl;

    // Solve 2
    cout << "Solution 2: " << endl;
    solve2(inputArray, rotateBy);

    cout << endl << endl;

    // Solve 3
    cout << "Solution 3: " << endl;
    solve3(inputArray, rotateBy);

    return 0;
}

/**
 * ------------------------------
 * n: Size of input array
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * ------------------------------
 */
void solve1(vector<int> arr, int d) {
    int n = arr.size();
    vector<int> result(n);

    for(int i = 0; i < n; i++) {
        int newLocation = i + d;

        if(newLocation >= n) {
            newLocation = newLocation - n;
        }
        result[newLocation] = arr[i];
    }

    for(int e: result) cout << e << " ";
}

/**
 * ------------------------------
 * n: Size of input array
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * ------------------------------
 */
void solve2(vector<int> arr, int d) {
    int n = arr.size();
    vector<int> result(n);

    for(int i = 0; i < n; i++) {
        result[i] = arr[(i + (n - d)) % n];
    }

    for(int e: result) cout << e << " ";
}

/**
 * ------------------------------
 * n: Size of input array
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * ------------------------------
 */
void solve3(vector<int> arr, int d) {
    int n = arr.size();

    reverse(arr, 0, n - d - 1);
    reverse(arr, n - d, n - 1);
    reverse(arr, 0, n - 1);

    for(int e: arr) cout << e << " ";
}

void reverse(vector<int> &arr, int lo, int hi) {
    while(lo < hi) {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
    }
}
