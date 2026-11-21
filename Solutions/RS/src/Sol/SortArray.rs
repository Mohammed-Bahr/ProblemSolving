struct Solution {}

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

    pub fn sort_array(nums: Vec<i32>) -> Vec<i32> {
        let mut arr = nums.clone();
        let right = arr.len() - 1;
        Self::merge_sort(&mut arr, 0, right);
        arr
    }
}

fn main() {
    let nums = vec![5, 2, 3, 1];
    let sorted = Solution::sort_array(nums);
    println!("{:?}", sorted);
}
