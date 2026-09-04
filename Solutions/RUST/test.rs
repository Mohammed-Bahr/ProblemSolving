fn main () {
    let mut s = String::from("foo");
    s.push_str("bar"); // for string slice  // "foobar"
    s.push('!'); //for one char   // "foobar!"

    let s0 = "welcome".to_string();
    // or
    let s1 = String::from("Hello, ");
    let s2 = String::from("world!");
    let s3 = s1 + &s2;          // s1 moved, s2 borrowed
    // s1 no longer valid

    println!("s0: {},  s3: {}", s0, s3);

    // Format macro (doesn't take ownership)
    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");
    let s = format!("{s1}-{s2}-{s3}");  // "tic-tac-toe"
    println!("s: {} , s1: {}, s2: {}, s3: {}", s, s1, s2, s3);
}