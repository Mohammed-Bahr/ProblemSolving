public class peakIndexInMountainArray {
    public int PeakIndexInMountainArray(int[] var1) {
        int var2 = 1;
  
        int var3;
        for(var3 = 0; var1[var3] < var1[var2]; ++var2) {
           ++var3;
        }
  
        return var3;
     }
}
