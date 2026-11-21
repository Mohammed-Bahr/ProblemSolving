

use std::cell::RefCell;
use std::rc::Rc;

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

struct Solution;

impl Solution {
    pub fn postorder_traversal(
        root: Option<Rc<RefCell<TreeNode>>>
    ) -> Vec<i32> {

        let mut result = Vec::new();

        fn dfs(
            node: Option<Rc<RefCell<TreeNode>>>,
            result: &mut Vec<i32>,
        ) {
            let Some(node) = node else {
                return;
            };

            let node = node.borrow();

            // Left
            dfs(node.left.clone(), result);

            // Right
            dfs(node.right.clone(), result);

            // Root
            result.push(node.val);
        }

        dfs(root, &mut result);

        result
    }
}

