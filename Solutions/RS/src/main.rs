struct Solution;

impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        // Base cases
        if n == 0 {
            return 0;
        }
        if n == 1 || n == 2 {
            return 1;
        }

        // Initialize the first three numbers
        // We use `mut` because we will update them in the loop
        let (mut t0, mut t1, mut t2) = (0, 1, 1);

        // Loop from 3 up to n (inclusive)
        for _ in 3..=n {
            let t3 = t0 + t1 + t2; // Calculate the next number

            // Shift the variables forward
            t0 = t1;
            t1 = t2;
            t2 = t3;
        }

        // t2 will hold the n-th Tribonacci number
        t2
    }
}
