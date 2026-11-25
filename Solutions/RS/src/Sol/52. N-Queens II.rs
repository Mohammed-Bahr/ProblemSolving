
use std::collections::HashSet;

struct Solution;

impl Solution {
    pub fn total_n_queens(n: i32) -> i32 {
        let mut col = HashSet::new();
        let mut neg_diag = HashSet::new();
        let mut pos_diag = HashSet::new();
        let mut res = 0;

        fn backtracking(
            r: i32,
            n: i32,
            col: &mut HashSet<i32>,
            neg_diag: &mut HashSet<i32>,
            pos_diag: &mut HashSet<i32>,
            res: &mut i32,
        ) {
            if r == n {
                *res += 1;
                return;
            }

            for c in 0..n {
                let pos = r + c;
                let neg = r - c;

                if col.contains(&c)
                    || neg_diag.contains(&neg)
                    || pos_diag.contains(&pos)
                {
                    continue;
                }

                col.insert(c);
                pos_diag.insert(pos);
                neg_diag.insert(neg);

                backtracking(
                    r + 1, n,
                    col, neg_diag, pos_diag, res
                );

                col.remove(&c);
                pos_diag.remove(&pos);
                neg_diag.remove(&neg);
            }
        }

        backtracking(
            0, n,
            &mut col,
            &mut neg_diag,
            &mut pos_diag,
            &mut res,
        );

        res
    }
}
