use std::collections::HashMap;

const NIL: usize = usize::MAX;

struct Node {
    key: i32,
    value: i32,
    freq: usize,
    prev: usize,
    next: usize,
}

#[derive(Clone, Copy)]
struct Bucket {
    head: usize, // LRU
    tail: usize, // MRU
}

struct LFUCache {
    capacity: usize,
    nodes: Vec<Node>,               // arena
    free: Vec<usize>,               // recycled arena slots
    map: HashMap<i32, usize>,       // key -> arena index
    buckets: HashMap<usize, Bucket>, // freq -> list ends
    min_freq: usize,
}

impl LFUCache {
    fn new(capacity: i32) -> Self {
        Self {
            capacity: capacity.max(0) as usize,
            nodes: Vec::new(),
            free: Vec::new(),
            map: HashMap::new(),
            buckets: HashMap::new(),
            min_freq: 0,
        }
    }

    /// Detach node from its frequency list; drop the bucket if it becomes empty.
    fn unlink(&mut self, idx: usize) {
        let (prev, next, freq) = {
            let n = &self.nodes[idx];
            (n.prev, n.next, n.freq)
        };
        if prev != NIL { self.nodes[prev].next = next; }
        if next != NIL { self.nodes[next].prev = prev; }

        let b = self.buckets.get_mut(&freq).unwrap();
        if prev == NIL { b.head = next; }
        if next == NIL { b.tail = prev; }
        if b.head == NIL {
            self.buckets.remove(&freq);
        }
    }

    /// Append node (at its current freq) as most-recently-used.
    fn push_back(&mut self, idx: usize) {
        let freq = self.nodes[idx].freq;
        self.nodes[idx].prev = NIL;
        self.nodes[idx].next = NIL;

        match self.buckets.get_mut(&freq) {
            Some(b) => {
                let tail = b.tail;
                b.tail = idx;
                self.nodes[tail].next = idx;
                self.nodes[idx].prev = tail;
            }
            None => {
                self.buckets.insert(freq, Bucket { head: idx, tail: idx });
            }
        }
    }

    fn touch(&mut self, idx: usize) {
        let f = self.nodes[idx].freq;
        self.unlink(idx);
        if self.min_freq == f && !self.buckets.contains_key(&f) {
            self.min_freq += 1;
        }
        self.nodes[idx].freq = f + 1;
        self.push_back(idx);
    }

    fn get(&mut self, key: i32) -> i32 {
        let idx = match self.map.get(&key) {
            Some(&i) => i,
            None => return -1,
        };
        self.touch(idx);
        self.nodes[idx].value
    }

    fn put(&mut self, key: i32, value: i32) {
        if self.capacity == 0 { return; }

        let existing = self.map.get(&key).copied();
        if let Some(idx) = existing {
            self.nodes[idx].value = value;
            self.touch(idx);
            return;
        }

        // Evict LFU (ties -> LRU) in O(1)
        if self.map.len() == self.capacity {
            let victim = self.buckets[&self.min_freq].head;
            self.unlink(victim);
            let k = self.nodes[victim].key;
            self.map.remove(&k);
            self.free.push(victim);
        }

        let node = Node { key, value, freq: 1, prev: NIL, next: NIL };
        let idx = match self.free.pop() {
            Some(i) => { self.nodes[i] = node; i }
            None => { self.nodes.push(node); self.nodes.len() - 1 }
        };
        self.map.insert(key, idx);
        self.push_back(idx);
        self.min_freq = 1;
    }
}

fn main() {
    let mut cache = LFUCache::new(2);
    let mut result: Vec<String> = vec!["null".into()];

    cache.put(1, 1); result.push("null".into());
    cache.put(2, 2); result.push("null".into());
    result.push(cache.get(1).to_string());
    cache.put(3, 3); result.push("null".into());
    result.push(cache.get(2).to_string());
    result.push(cache.get(3).to_string());
    cache.put(4, 4); result.push("null".into());
    result.push(cache.get(1).to_string());
    result.push(cache.get(3).to_string());
    result.push(cache.get(4).to_string());

    println!("[{}]", result.join(", "));
}
