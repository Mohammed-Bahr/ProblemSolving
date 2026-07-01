// struct Solution;

// impl Solution {
//     pub fn max_profit(prices: Vec<i32>) -> i32 {
//         if prices.is_empty() {
//             return 0;
//         }

//         let mut profit = 0;
//         let size = prices.len();
//         let mut low;
//         let mut high;
//         let mut i = 0;

//         while i < size - 1 {
//             // Find valley (buy point)
//             while i < size - 1 && prices[i] >= prices[i + 1] {
//                 i += 1;
//             }
//             low = prices[i];

//             // Find peak (sell point)
//             while i < size - 1 && prices[i] <= prices[i + 1] {
//                 i += 1;
//             }
//             high = prices[i];

//             profit += high - low;
//         }

//         profit
//     }
// }

// fn main() {
//     let prices = vec![7, 1, 5, 3, 6, 4];
//     let profit = Solution::max_profit(prices);
//     println!("{}", profit);
// }


struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let n = prices.len();
        if n < 2 {
            return 0;
        }

        let mut left = 0;   // buy pointer
        let mut right = 0;  // scan pointer
        let mut profit = 0;

        while right < n - 1 {
            // Find valley (buy point)
            while right < n - 1 && prices[right] >= prices[right + 1] {
                right += 1;
            }
            left = right;

            // Find peak (sell point)
            while right < n - 1 && prices[right] <= prices[right + 1] {
                right += 1;
            }

            profit += prices[right] - prices[left];
        }

        profit
    }
}

fn main() {
    let prices = vec![7, 1, 5, 3, 6, 4];
    println!("{}", Solution::max_profit(prices));
}
