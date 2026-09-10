/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */

fn guess(num: i32) -> i32 {
    if (num == 7) {
        return 0;
    } else if (num > 7) {
        return -1;
    } else {
        return 1;
    }
}

impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let mut left = 1;
        let mut right = n;
        while left <= right {
            let mid = left + (right - left) / 2;
            let res = guess(mid);
            if res == 0 {
                return mid;
            } else if res == -1 {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        -1
    }
}



fn main() {
    let result = Solution::guessNumber(10);
    println!("{}", result);
}
