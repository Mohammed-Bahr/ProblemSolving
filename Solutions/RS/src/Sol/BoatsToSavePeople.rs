// struct Solution;

// impl Solution {
//     pub fn num_rescue_boats(people: Vec<i32>, limit: i32) -> i32 {
//         let size = people.len();
//         let mut sum: i64 = 0;
//         let mut peoples = people.clone();
//         peoples.sort();

//         // for i in 0..size {
//         //     sum += people[i] as i64;
//         // }

//         // let result = (sum as f64 / limit as f64).ceil() as i32;

//         // result
//         let mut rst = 1;
//         for i in 0..size {
//             if sum <= limit as i64 {
//                 sum += peoples[i] as i64;
//             } else {
//                 rst += 1;
//                 sum = peoples[i] as i64;
//             }
//         }
//         rst += 1;
//         rst
//     }
// }

// fn main() {
//     let result = Solution::num_rescue_boats(vec![3,2,2,1], 3);
//     println!("{}", result);
// }



struct Solution;

impl Solution {
    pub fn num_rescue_boats(mut people: Vec<i32>, limit: i32) -> i32 {
        people.sort();

        let mut left = 0;
        let mut right = people.len();
        let mut boats = 0;

        while left < right {
            right -= 1;

            if people[left] + people[right] <= limit {
                left += 1;
            }

            boats += 1;
        }

        boats
    }
}
fn main() {
    let result = Solution::num_rescue_boats(vec![3, 2, 2, 1], 3);
    println!("{}", result);
}
