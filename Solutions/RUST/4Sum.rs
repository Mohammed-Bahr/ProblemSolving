use std::cmp::Ordering;

struct Solution;
impl Solution {
    pub fn four_sum(mut nums: Vec<i32>, target: i32) -> Vec<Vec<i32>>
    {
        // Cast target to account for integer overflow
        let target = target as i64;
        let mut out = Vec::new();

        // Four pointer algorithm requires sorted input
        nums.sort();

        // Early termination conditions
        if nums.len() < 4
        || nums.iter().take(4).fold(0,|sum,&x| sum + (x as i64)) > target // Min sum too large
        || nums.iter().rev().take(4).fold(0,|sum,&x| sum + (x as i64)) < target // Max sum too small
        {
            return out;
        }

        // Limit loop iterations
        let n = nums.len();
        let imax = n - 3;
        let jmax = n - 2;

        // Same as 3 sum, but we use two reference pointers to determine the remaining amount
        for i in 0..imax
        {
            // Skip repeated numbers for i>0 and j>j0
            if i > 0 && nums[i] == nums[i-1]
            {
                continue;
            }

            let j0 = i+1;
            for j in j0..jmax
            {
                if j > j0 && nums[j] == nums[j-1]
                {
                    continue;
                }

                // Compute a new target for the scanning loop
                let pair_target = target - (nums[i] as i64) - (nums[j] as i64);
                let mut L = j+1;
                let mut R = n-1;

                // Scan for pairs that will complete the sum
                while L < R
                {
                    let sum = (nums[L] as i64) + (nums[R] as i64);

                    match sum.cmp(&pair_target)
                    {
                        Ordering::Less    => L += 1,
                        Ordering::Greater => R -= 1,
                        Ordering::Equal   => {
                            out.push(vec![nums[i], nums[j], nums[L], nums[R]]);
                            L += 1;
                            R -= 1;
                            while L < R && nums[L] == nums[L-1]
                            {
                                L += 1;
                            }
                        }
                    } // match sum
                } // while L < R
            } // for j in ...
        } // for i in ...

        out
    }
}


fn main() {
    let nums = vec![2,2,2,2,2];
    let target = 0;
    let result = Solution::four_sum(nums, target);
    println!("{:?}", result);
}
