class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int start = 0;
        long long int end = num;
        
        while(start <= end) {
            long long int mid = (start + end) / 2;
            long long int square = mid * mid;
            
            if(square == num) return true;
            
            if(square < num)
                start = mid + 1;
            else
                end = mid - 1;
        }
        
        return false;
    }
};