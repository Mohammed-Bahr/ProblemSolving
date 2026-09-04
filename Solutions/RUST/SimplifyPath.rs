
// You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

// The rules of a Unix-style file system are as follows:

//     A single period '.' represents the current directory.
//     A double period '..' represents the previous/parent directory.
//     Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
//     Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.

// The simplified canonical path should follow these rules:

//     The path must start with a single slash '/'.
//     Directories within the path must be separated by exactly one slash '/'.
//     The path must not end with a slash '/', unless it is the root directory.
//     The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.

// Return the simplified canonical path.

use std::time::Instant;

struct Solution ;
impl Solution {
    pub fn simplify_path(path: String) -> String {
        let mut stack: Vec<&str> = Vec::new();
        for part as &str in path.split('/') {
            if part == ".."   {
                if stack.is_empty(){
                    continue;
                }
                stack.pop();
            } else if part != "." && !part.is_empty() {
                stack.push(part);
            }
        }
        let mut result = stack.into_iter().collect::<Vec<&str>>().join("/");
        result.insert(0, '/');
        result
    }
}


// #[derive(Serialize, Deserialize)]
struct ObtimizedSolution ;
impl ObtimizedSolution {
    pub fn simplify_path(path: String) -> String {
        let mut stack: Vec<&str> = Vec::new();

        for part in path.split('/') {
            if part.is_empty() || part == "." {
                continue;
            }
            if part == ".." {
                stack.pop();
            } else {
                stack.push(part);
            }
        }

        if stack.is_empty() {
            "/".to_string()
        } else {
            format!("/{}", stack.join("/"))
        }
    }
}


fn main() {
    let path = "/home/user/Documents/../Pictures/./test/../../Downloads/";

    let iterations = 1_000_000;

    let start = Instant::now();

    for _ in 0..iterations {
        let _ = Solution::simplify_path(path.to_string());
    }

    let duration1 = start.elapsed();

    let start = Instant::now();

    for _ in 0..iterations {
        let _ = ObtimizedSolution::simplify_path(path.to_string());
    }

    let duration2 = start.elapsed();

    println!("Solution: {:?}", duration1);
    println!("Optimized: {:?}", duration2);
}
