struct NumMatrix {
    new_matrix: Vec<Vec<i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumMatrix {
    fn new(matrix: Vec<Vec<i32>>) -> Self {
        let mut new_matrix = Vec::new();

        for row in &matrix {
            let mut new_row = Vec::new();
            let mut prev = 0;

            for col in row {
                prev += *col;
                new_row.push(prev);
            }

            new_matrix.push(new_row);
        }

        Self { new_matrix }
    }

    fn sum_region(&self, row1: i32, col1: i32, row2: i32, col2: i32) -> i32 {
        let mut sum = 0;

        for row in row1..=row2 {
            let r = row as usize;
            let c1 = col1 as usize;
            let c2 = col2 as usize;

            if c1 == 0 {
                sum += self.new_matrix[r][c2];
            } else {
                sum += self.new_matrix[r][c2] - self.new_matrix[r][c1 - 1];
            }
        }

        sum
    }
}

fn main() {
    let matrix = vec![
        vec![3, 0, 1, 4, 2],
        vec![5, 6, 3, 2, 1],
        vec![1, 2, 0, 1, 5],
        vec![4, 1, 0, 1, 7],
        vec![1, 0, 3, 0, 5],
    ];

    let obj = NumMatrix::new(matrix);
    let ret_1 = obj.sum_region(2, 1, 4, 3);

    println!("{}", ret_1); // 8
}
