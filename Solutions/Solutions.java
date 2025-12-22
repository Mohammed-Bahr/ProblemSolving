import java.util.Arrays;

public class Solutions {
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

    public int peakIndexInMountainArray(int[] arr) {
        int point = 1 ;
        int i = 0 ;
        while (arr[i] < arr[point]){
            i++;
            point++;
        }
        return i ;
    }

    public int findMin(int[] nums) {
        for(int i = 1; i < nums.length; i++){
            if(nums[i] < nums[i-1]){
                return nums[i];
            }
        }
        return nums[0];
    }

    public static void main(String[] args) {
        Solutions sol = new Solutions();
        int[] nums = {3,4,5,1,2};
        System.out.println(sol.findMin(nums));
    }
}
