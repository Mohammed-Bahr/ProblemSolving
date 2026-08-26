struct Solution {}

impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &Vec<i32>, _n: i32) {
        // Remove the extra zeros from nums1
        nums1.truncate(m as usize);

        // Add nums2 elements
        nums1.extend_from_slice(nums2);

        // Sort everything
        nums1.sort();
    }
}

fn main() {
    let mut nums1 = vec![1, 2, 3, 0, 0, 0];
    let m = 3;

    let nums2 = vec![2, 5, 6];
    let n = 3;

    Solution::merge(&mut nums1, m, &nums2, n);

    println!("{:?}", nums1);
}
