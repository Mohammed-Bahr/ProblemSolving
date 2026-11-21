use std::rc::Rc;
use std::cell::RefCell;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode { val, left: None, right: None }
    }
}

impl Solution {
    /// Post-order DFS.
    /// Returns (rob_here, skip_here) for this subtree,
    /// and pushes every node's (rob_here, skip_here) onto `stack` for inspection.
    fn dfs(
        root: &Option<Rc<RefCell<TreeNode>>>,
        stack: &mut Vec<(i32, i32)>,
    ) -> (i32, i32) {
        match root {
            None => (0, 0),
            Some(node) => {
                let node = node.borrow();

                // recurse first  →  post-order
                let (l_rob,  l_skip)  = Self::dfs(&node.left,  stack);
                let (r_rob,  r_skip)  = Self::dfs(&node.right, stack);

                let rob_here = node.val + l_skip + r_skip;
                let skip_here = l_rob.max(l_skip) + r_rob.max(r_skip);

                stack.push((rob_here, skip_here));
                (rob_here, skip_here)
            }
        }
    }

    pub fn rob(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut stack: Vec<(i32, i32)> = Vec::new();
        let (rob_root, skip_root) = Self::dfs(&root, &mut stack);

        // The two possible outputs you asked for:
        println!("start WITH root  (rob root ) = {}", rob_root);
        println!("start WITHOUT root (skip root) = {}", skip_root);

        rob_root.max(skip_root)
    }
}
