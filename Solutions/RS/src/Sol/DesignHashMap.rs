struct Pair {
    key: i32,
    value: i32,
}

pub struct MyHashMap {
    // The map actually holds the list of pairs
    map: Vec<Pair>,
}

impl MyHashMap {
    // Initialize your empty map here
    fn new() -> Self {
        Self { map: Vec::new() }
    }

    // Changed to &mut self because we are modifying the vector
    fn put(&mut self, key: i32, value: i32) {
        let mut found = false;
        for item in &mut self.map {
            if item.key == key {
                item.value = value;
                found = true;
                break;
            }
        }
        if !found {
            self.map.push(Pair { key, value });
        }
    }

    // &self is fine here because we are only reading
    fn get(&self, key: i32) -> i32 {
        for item in &self.map {
            if item.key == key {
                return item.value;
            }
        }
        -1
    }

    // Changed to &mut self. Used position() to safely find and remove the item.
    fn remove(&mut self, key: i32) {
        if let Some(index) = self.map.iter().position(|item| item.key == key) {
            self.map.remove(index);
        }
    }
}

fn main() {
    let mut obj = MyHashMap::new();
    obj.put(1, 10);

    let ret_2: i32 = obj.get(1);
    println!("Got value: {}", ret_2); // Prints 10

    obj.remove(1);

    let ret_3: i32 = obj.get(1);
    println!("After removal: {}", ret_3); // Prints -1
}
