
struct Solution;

impl Solution {
    pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {

        fn all_combinations(nums: &[i32]) -> Vec<Vec<i32>> {

            fn backtrack(
                nums: &[i32],
                index: usize,
                current: &mut Vec<i32>,
                result: &mut Vec<Vec<i32>>,
            )
            {
                // Base case: processed all elements
                if index == nums.len() {
                    result.push(current.clone());
                    return;
                }

                // Choice 1: Include current element
                current.push(nums[index]);

                backtrack(nums, index + 1, current, result);

                // Undo the previous choice
                current.pop();

                // Choice 2: Exclude current element
                backtrack(nums, index + 1, current, result);
            }

            let mut result = Vec::new();
            let mut current = Vec::new();

            backtrack(nums, 0, &mut current, &mut result);

            result
        }

        let comb = all_combinations(&nums);
        let mut result = 0;

        for subset in &comb {
            let mut xor = 0;

            for &num in subset {
                xor ^= num;
            }

            result += xor;
        }

        result
    }
}

fn main() {
    let nums = vec![1, 3];

    let result = Solution::subset_xor_sum(nums);

    println!("The result is: {}", result);
}
