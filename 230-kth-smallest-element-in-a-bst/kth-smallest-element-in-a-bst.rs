// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
        let mut s = Vec::new();
        let mut curr = root;
        let mut count = 0;
        while curr.is_some() || !s.is_empty() {
            while let Some(node) = curr {
                s.push(node.clone());
                curr = node.borrow().left.clone();
            }
            if let Some(node) = s.pop() {
                count += 1;
                if count == k {
                    return node.borrow().val;
                }
                curr = node.borrow().right.clone();
            }
        }
        -1
    }
}