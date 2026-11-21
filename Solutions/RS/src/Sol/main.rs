fn main() {
    let s = String::from("hello world");

    println!("{}", s);

    let pointer = &s;

    println!("{}", pointer.chars().nth(4).unwrap());

    println!("{}", s);
}
