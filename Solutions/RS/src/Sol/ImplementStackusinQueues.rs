use std::collections::VecDeque;

struct MyStack {
    queue1: VecDeque<i32>,
    queue2: VecDeque<i32>,
}

impl MyStack {
    fn new() -> Self {
        Self {
            queue1: VecDeque::new(),
            queue2: VecDeque::new(),
        }
    }

    fn push(&mut self, x: i32) {
        // Put the new element in queue2
        self.queue2.push_back(x);

        // Move everything from queue1 to queue2
        while let Some(value) = self.queue1.pop_front() {
            self.queue2.push_back(value);
        }

        // Swap the queues
        std::mem::swap(&mut self.queue1, &mut self.queue2);
    }

    fn pop(&mut self) -> i32 {
        self.queue1.pop_front().unwrap()
    }

    fn top(&self) -> i32 {
        *self.queue1.front().unwrap()
    }

    fn empty(&self) -> bool {
        self.queue1.is_empty()
    }
}

fn main() {
    let mut obj = MyStack::new();

    obj.push(1);
    obj.push(2);

    let ret_2 = obj.pop();
    let ret_3 = obj.top();
    let ret_4 = obj.empty();

    println!("ret_2: {}", ret_2);
    println!("ret_3: {}", ret_3);
    println!("ret_4: {}", ret_4);
}
