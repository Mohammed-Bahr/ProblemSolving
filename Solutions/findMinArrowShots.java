import java.util.Arrays;

public int findMinArrowShots(int[][] points) {
    if (points == null || points.length == 0) {
        return 0;
    }

    // Sort the intervals by their ending point
    Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));

    int count = 1;          // At least one arrow is needed
    int end = points[0][1]; // Position of the first arrow

    for (int i = 1; i < points.length; i++) {
        if (points[i][0] > end) {
            // Balloon not covered by previous arrow
            count++;
            end = points[i][1]; // Shoot new arrow at end of this balloon
        }
    }

    return count;
}
