struct Solution;

impl Solution {
    pub fn cal_points(operations: Vec<String>) -> i32 {
        let mut stack: Vec<i32> = Vec::new();

        for operation in operations {
            if operation == "+" {
                let n = stack.len();

                let op = stack[n - 1] + stack[n - 2];

                stack.push(op);
            }
            else if operation == "D" {
                let op = stack.last().unwrap() * 2;

                stack.push(op);
            }
            else if operation == "C" {
                stack.pop();
            }
            else {
                let num = operation.parse::<i32>().unwrap();

                stack.push(num);
            }
        }

        stack.iter().sum()
    }
}

fn main() {
    let operations = vec![
        String::from("5"),
        String::from("2"),
        String::from("C"),
        String::from("D"),
        String::from("+"),
    ];

    println!("{}", Solution::cal_points(operations));
}
