use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashSet};

struct Solution;

impl Solution {
    pub fn swim_in_water(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let dirs: [(i32, i32); 4] = [
            (0, 1),   // Right
            (1, 0),   // Down
            (0, -1),  // Left
            (-1, 0),  // Up
        ];

        let mut visited = HashSet::new();
        let mut min_h = BinaryHeap::new(); // min heap using Reverse

        min_h.push(Reverse((grid[0][0], 0usize, 0usize)));

        while let Some(Reverse((time, row, col))) = min_h.pop() {
            if visited.contains(&(row, col)) {
                continue;
            }
            visited.insert((row, col));

            if row == n - 1 && col == n - 1 {
                return time;
            }

            for (dr, dc) in dirs {
                let nr = row as i32 + dr;
                let nc = col as i32 + dc;

                if nr >= 0 && nc >= 0 && nr < n as i32 && nc < n as i32 {
                    let nr = nr as usize;
                    let nc = nc as usize;

                    if !visited.contains(&(nr, nc)) {
                        let next_time = time.max(grid[nr][nc]);
                        min_h.push(Reverse((next_time, nr, nc)));
                    }
                }
            }
        }

        unreachable!()
    }
}

fn main() {
    let grid = vec![
        vec![0, 1, 2, 3, 4],
        vec![24, 23, 22, 21, 5],
        vec![12, 13, 14, 15, 16],
        vec![11, 17, 18, 19, 20],
        vec![10, 9, 8, 7, 6],
    ];

    let result = Solution::swim_in_water(grid);
    println!("{}", result); // 16
}
