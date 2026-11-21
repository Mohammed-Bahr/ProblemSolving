
struct Solution{}

impl Solution {
    // merge sort
    pub fn merge(arr: &mut [i32], left: usize, mid: usize, right: usize) {
        let n1 = mid - left + 1;
        let n2 = right - mid;

        let l: Vec<i32> = arr[left..left + n1].to_vec();
        let r: Vec<i32> = arr[mid + 1..mid + 1 + n2].to_vec();

        let (mut i, mut j, mut k) = (0usize, 0usize, left);

        while i < n1 && j < n2 {
            if l[i] <= r[j] {
                arr[k] = l[i];
                i += 1;
            } else {
                arr[k] = r[j];
                j += 1;
            }
            k += 1;
        }

        while i < n1 {
            arr[k] = l[i];
            i += 1;
            k += 1;
        }
        while j < n2 {
            arr[k] = r[j];
            j += 1;
            k += 1;
        }
    }

    pub fn merge_sort(arr: &mut [i32], left: usize, right: usize) {
        if left < right {
            let mid = left + (right - left) / 2;
            Self::merge_sort(arr, left, mid);
            Self::merge_sort(arr, mid + 1, right);
            Self::merge(arr, left, mid, right);
        }
    }

    pub fn sort_colors(nums: &mut Vec<i32>) {
        let right = nums.len() - 1;
        Self::merge_sort(nums, 0, right);
    }
}

fn main() {
    let mut nums = vec![2,0,2,1,1,0];
    Solution::sort_colors(&mut nums);
    println!("{:?}", nums);
}
