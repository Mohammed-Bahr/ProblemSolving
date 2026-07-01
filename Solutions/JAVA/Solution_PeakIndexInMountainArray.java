public class Solution_PeakIndexInMountainArray {
    public int peakIndexInMountainArray(int[] arr) {
        int point = 1 ;
        int i = 0 ;
        while (arr[i] < arr[point]){
            i++;
            point++;
        }
        return i ;
    }
}
