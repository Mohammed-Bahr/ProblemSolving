
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    fn dfs(
        root: &Option<Rc<RefCell<TreeNode>>>,
        target: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {

        match root {
            None => None,

            Some(node) => {
                let (left, right, val) = {
                    let node = node.borrow();
                    (
                        node.left.clone(),
                        node.right.clone(),
                        node.val,
                    )
                };

                let left = Self::dfs(&left, target);
                let right = Self::dfs(&right, target);

                let should_delete =
                    val == target &&
                    left.is_none() &&
                    right.is_none();

                {
                    let mut node = node.borrow_mut();

                    node.left = left;
                    node.right = right;
                }

                if should_delete {
                    None
                } else {
                    Some(Rc::clone(node))
                }
            }
        }
    }

    pub fn remove_leaf_nodes(
        root: Option<Rc<RefCell<TreeNode>>>,
        target: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {

        Self::dfs(&root, target)
    }
}
