//  ImplementQueueusingStacks.rs
//


struct MyQueue {
    in_stack: Vec<i32>,
    out_stack: Vec<i32>,
}

impl MyQueue {
    fn new() -> Self {
        MyQueue { in_stack: Vec::new(), out_stack: Vec::new() }
    }

    fn push(&mut self, x: i32) {
        self.in_stack.push(x);
    }

    fn pop(&mut self) -> i32 {
        self.move_if_needed();
        self.out_stack.pop().unwrap()
    }

    fn peek(&mut self) -> i32 {
        self.move_if_needed();
        *self.out_stack.last().unwrap()
    }

    fn empty(&self) -> bool {
        self.in_stack.is_empty() && self.out_stack.is_empty()
    }

    fn move_if_needed(&mut self) {
        if self.out_stack.is_empty() {
            while let Some(x) = self.in_stack.pop() {
                self.out_stack.push(x);
            }
        }
    }
}
/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.peek();
 * let ret_4: bool = obj.empty();
 */

fn main() {
    let mut obj = MyQueue::new();
    obj.push(1);
    obj.push(2);
    let ret_2: i32 = obj.pop();
    let ret_3: i32 = obj.peek();
    let ret_4: bool = obj.empty();
    println!("ret_2: {}", ret_2);
    println!("ret_3: {}", ret_3);
    println!("ret_4: {}", ret_4);

}
