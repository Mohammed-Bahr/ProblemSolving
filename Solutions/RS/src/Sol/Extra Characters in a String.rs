
struct Solution;

use std::collections::HashSet;

impl Solution {
    pub fn min_extra_char(s: String, dictionary: Vec<String>) -> i32 {
        let words: HashSet<&str> = dictionary.iter().map(|x| x.as_str()).collect();
        let n = s.len();
        let mut dp = vec![None; n + 1];
        fn dfs(i: usize, s: &str, words: &HashSet<&str>, dp: &mut Vec<Option<usize>>) -> usize {
            if i == s.len() {
                return 0;
            }

            if let Some(val) = dp[i] {
                return val;
            }

            let mut res = 1 + dfs(i + 1, s, words, dp);

            for j in i..s.len() {
                if words.contains(&s[i..=j]) {
                    res = res.min(dfs(j + 1, s, words, dp));
                }
            }

            dp[i] = Some(res);
            res
        }

        dfs(0, &s, &words, &mut dp) as i32
    }
}
fn main() {
    let s: String = "leetscode".to_string();
    let dictionary: Vec<String> = vec!["leet".to_string(), "code".to_string(), "leetcode".to_string()];

    let result = Solution::min_extra_char(s, dictionary);

    println!("{}", result);
}
