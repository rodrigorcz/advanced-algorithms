use std::io;

const P: i64 = 1_000_000_007;

fn main() {
    let n = read_int();
    
    for _ in 0 .. n {
        let input = read_string();
        let mut iter = input.split_whitespace();

        let a: i64 = iter.next().unwrap().parse().expect("Error");
        let b: i64 = iter.next().unwrap().parse().expect("Error");

        let res = expon(a, b);
        println!("{res}");
    }
}

fn expon(mut a: i64, mut b: i64) -> i64 {
    let mut res = 1;
    a %= P;
    
    while b > 0 {
        
        if b % 2 == 1 {
            res = res * a % P;
        }
       
        a = a * a % P;
        b /= 2;
    }
    
    res
}

fn read_int() -> usize {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Error Input");
  input.trim().parse().expect("Error")
}

fn read_string() -> String {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Error Input");
  input.trim().to_string()
} 