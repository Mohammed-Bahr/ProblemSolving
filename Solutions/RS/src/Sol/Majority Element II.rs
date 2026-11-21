use std::collections::HashMap;

struct Solution;

impl Solution {
    fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        let mut result = Vec::new();
        let mut freq: HashMap<i32, i32> = HashMap::new();

        // Count occurrences
        for num in &nums {
            *freq.entry(*num).or_insert(0) += 1;
        }

        // Collect elements appearing more than n/3 times
        for (num, count) in freq {
            if count > (nums.len() / 3) as i32 {
                result.push(num);
            }
        }

        result
    }
}

fn main() {
    let nums = vec![3, 2, 3];
    let result = Solution::majority_element(nums);

    for num in result {
        print!("{} ", num);
    }
    println!();
}
