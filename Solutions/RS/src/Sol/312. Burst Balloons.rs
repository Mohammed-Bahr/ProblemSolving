impl Solution {
    pub fn max_coins(nums: Vec<i32>) -> i32 {
        let mut arr = vec![1];
        arr.extend_from_slice(&nums);
        arr.push(1);
        let n = arr.len();
        let mut dp = vec![vec![0i32; n]; n];
        for gap in 2..n {
            for l in 0..n - gap {
                let r = l + gap;
                for k in l + 1..r {
                    let coins = arr[l] * arr[k] * arr[r];
                    let total = dp[l][k] + coins + dp[k][r];
                    if total > dp[l][r] {
                        dp[l][r] = total;
                    }
                }
            }
        }
        dp[0][n - 1]
    }
}

struct Solution;

fn main() {
    let test_cases = vec![
        (vec![3, 1, 5, 8], 167),
        (vec![1, 5],        10),
        (vec![5],           5),
        (vec![1, 2, 3],     12),
    ];

    for (nums, expected) in test_cases {
        let result = Solution::max_coins(nums.clone());
        let status = if result == expected { "✓ PASS" } else { "✗ FAIL" };
        println!("{status} | Input: {nums:?} | Got: {result} | Expected: {expected}");
    }
}
