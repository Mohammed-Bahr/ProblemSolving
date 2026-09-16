/// Returns true if `nums` can be split into at most `k` contiguous
/// subarrays such that every subarray sum is <= `limit`.
fn can_split(nums: &[i32], k: i32, limit: i64) -> bool {
    let mut parts = 1; // we need at least one subarray
    let mut sum: i64 = 0;

    for &x in nums {
        let x = x as i64;
        if sum + x > limit {
            parts += 1;
            sum = x;
            if parts > k {
                return false;
            }
        } else {
            sum += x;
        }
    }
    true
}

/// Minimum possible largest subarray sum when splitting `nums` into `k` parts.
fn split_array(nums: &[i32], k: i32) -> i32 {
    // Lower bound: largest single element.
    // Upper bound: sum of all elements.
    let mut lo: i64 = 0;
    let mut hi: i64 = 0;
    for &x in nums {
        lo = lo.max(x as i64);
        hi += x as i64;
    }

    // Binary search for the smallest feasible limit.
    while lo < hi {
        let mid = lo + (hi - lo) / 2;
        if can_split(nums, k, mid) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    lo as i32
}

fn main() {
    let nums = vec![7, 2, 5, 10, 8];
    let k = 2;
    println!("{}", split_array(&nums, k)); // 18
}
