#include <vector>
#include <iostream>
#include <unordered_map>
#include <cstdlib>
using namespace std ;
class DetectSquares {
private:
    // Map to store count of each point: map[x][y] = count
    unordered_map<int, unordered_map<int, int>> pointCount;

public:
    DetectSquares() {
        // Initialize empty map
    }

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        pointCount[x][y]++;
    }

    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int result = 0;

        // Iterate through all x-coordinates that have points
        for (auto& [x3, yMap] : pointCount) {
            // Skip if same x-coordinate (can't form square)
            if (x3 == x1) continue;

            // Calculate the side length
            int sideLength = abs(x3 - x1);

            // Iterate through all y-coordinates for this x
            for (auto& [y3, count3] : yMap) {
                // Skip if same y-coordinate (can't form square)
                if (y3 == y1) continue;

                // Check if this forms a square (width == height)
                if (abs(y3 - y1) != sideLength) continue;

                // Check if the other two corners exist
                // The four corners are: (x1,y1), (x1,y3), (x3,y1), (x3,y3)
                if (pointCount[x1].count(y3) && pointCount[x3].count(y1)) {
                    int count1 = pointCount[x1][y3];  // Corner at (x1, y3)
                    int count2 = pointCount[x3][y1];  // Corner at (x3, y1)

                    // Multiply counts (each duplicate is a different way)
                    result += count3 * count1 * count2;
                }
            }
        }

        return result;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
int main() {
    cout << "hello world" << endl;
}
