#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &arr) {
    int answer = arr[0];
    
    for(int i = 1; i < arr.size(); i++) {
        answer ^= arr[i];
    }
    
    cout << answer;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    
    for(int i = 0; i < n; i++) cin >> v[i];
    
    solve(v);
    
    return 0;
}