class Solution {
  public:
    int distance(int x1, int y1, int x2, int y2) {
        // Code here.
        double x = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)); 
        int x_low = x;
        int x_high = ceil(x);
        
        return abs(x - x_low) > abs(x-x_high) ?  x_high : x_low;
    }
};
