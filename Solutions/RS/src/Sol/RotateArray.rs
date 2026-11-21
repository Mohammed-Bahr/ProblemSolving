struct Solution;
impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let n = nums.len();
        let mut nn = k;
        if k > n as i32 {
            nn %= n as i32;
        }
        let mut slice : Vec<i32> = nums.drain(n-nn as usize..n).collect();
        slice.append(nums);
        *nums = slice;
    }
}


fn main() {
    let mut nums = vec![1];
    Solution::rotate(&mut nums, 10000);
    println!("{:?}", nums);
}
