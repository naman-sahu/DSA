class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        
        // Closest point on rectangle to circle center
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Squared distance
        long long dx = xCenter - closestX;
        long long dy = yCenter - closestY;

        return dx * dx + dy * dy <= 1LL * radius * radius;
    }
};