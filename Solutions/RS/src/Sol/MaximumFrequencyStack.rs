use std::collections::HashMap;

struct FreqStack {
    f: HashMap<i32, i32>,
    mp: HashMap<i32, Vec<i32>>,
    m: i32,
}

impl FreqStack {
    fn new() -> Self {
        Self {
            f: HashMap::new(),
            mp: HashMap::new(),
            m: 0,
        }
    }

    fn push(&mut self, val: i32) {
        // f[val]++
        let freq = self.f.entry(val).or_insert(0);
        *freq += 1;

        let freq = *freq;

        // mp[freq].push_back(val)
        self.mp
            .entry(freq)
            .or_insert_with(Vec::new)
            .push(val);

        // m = max(m, freq)
        self.m = self.m.max(freq);
    }

    fn pop(&mut self) -> i32 {
        // int ans = mp[m].back()
        let stack = self.mp.get_mut(&self.m).unwrap();
        let ans = *stack.last().unwrap();

        // mp[m].pop_back()
        stack.pop();

        // f[ans]--
        *self.f.get_mut(&ans).unwrap() -= 1;

        // if(mp[m].empty()) m--
        if stack.is_empty() {
            self.m -= 1;
        }

        ans
    }
}

fn main() {
    let mut obj = FreqStack::new();

    obj.push(5);
    obj.push(7);
    obj.push(5);
    obj.push(7);
    obj.push(4);
    obj.push(5);

    let param_2 = obj.pop();

    println!("{}", param_2);
}
