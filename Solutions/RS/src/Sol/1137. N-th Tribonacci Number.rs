struct Solution;

impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        if n == 0 {
            return 0;
        }
        if n == 1 || n == 2 {
            return 1;
        }

        let (mut t0, mut t1, mut t2) = (0, 1, 1);

        for _ in 3..=n {
            let t3 = t0 + t1 + t2;

            t0 = t1;
            t1 = t2;
            t2 = t3;
        }

        t2
    }
}

fn main() {
    let n = 10;
    let result = Solution::tribonacci(n);
    println!("The {}th Tribonacci number is {}", n, result);
}
