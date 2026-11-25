struct Solution;

impl Solution {
    pub fn makesquare(matchsticks: Vec<i32>) -> bool {
        if matchsticks.len() < 4 {
            return false;
        }

        let mut sticks = matchsticks;
        sticks.sort_by(|a, b| b.cmp(a)); // Longest first so dead ends show up fast

        let sum: i32 = sticks.iter().sum();
        if sum % 4 != 0 {
            return false;
        }

        let edge_length = sum / 4;
        if sticks[0] > edge_length {
            return false;
        }

        fn backtrack(idx: usize, sticks: &[i32], edge_length: i32, sides: &mut [i32; 4]) -> bool {
            if idx == sticks.len() {
                return sides.iter().all(|&s| s == edge_length);
            }

            let stick = sticks[idx];

            for i in 0..4 {
                if sides[i] + stick > edge_length {
                    continue;
                }
                if sides[..i].contains(&sides[i]) {
                    continue;
                }
                sides[i] += stick;
                if backtrack(idx + 1, sticks, edge_length, sides) {
                    return true;
                }
                sides[i] -= stick;
            }
            false
        }

        let mut sides = [0; 4];
        backtrack(0, &sticks, edge_length, &mut sides)
    }
}

fn main() {
    // let matchsticks: Vec<i32> = vec![1, 1, 2, 2, 2];
    let matchsticks: Vec<i32> = vec![3, 3, 3, 3, 4];
    let result = Solution::makesquare(matchsticks);
    println!("Can form a square: {}", result);
}
