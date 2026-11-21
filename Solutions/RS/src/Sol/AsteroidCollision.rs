
struct Solution;

impl Solution {
    pub fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
        let mut stack : Vec<i32> = Vec::new();
        let mut destroyed = false;
        for asteroid in asteroids {
            if asteroid > 0 {
                stack.push(asteroid);
            } else {
                while let Some(&top) = stack.last() {
                    if top < 0 {
                        break;
                    } else if top == asteroid.abs() {
                        stack.pop();
                        destroyed = true;
                        break;
                    } else if top > asteroid.abs() {
                        destroyed = true;
                        break;
                    } else {
                        stack.pop();
                    }
                }

                if !destroyed && (stack.is_empty() || *stack.last().unwrap() < 0) {
                    stack.push(asteroid);
                }
                destroyed = false;
            }
        }
        stack
    }
}

fn main() {
    let asteroids = vec![5, 10, -5];
    let result = Solution::asteroid_collision(asteroids);
    println!("{:?}", result); // Output: [5, 10]

    let asteroids2 = vec![8, -8];
    let result2 = Solution::asteroid_collision(asteroids2);
    println!("{:?}", result2); // Output: []

    let asteroids3 = vec![10, 2, -5];
    let result3 = Solution::asteroid_collision(asteroids3);
    println!("{:?}", result3); // Output: [10]

    let asteroids4 = vec![-2,1,-1,-2];
    let result4 = Solution::asteroid_collision(asteroids4);
    println!("{:?}", result4); // Output: [-2, -1, 1, 2]
}