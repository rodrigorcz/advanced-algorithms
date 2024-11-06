use std::io;

const P: i64 = 1_000_000_007;
const PHI_P: i64 = P - 1; 

fn main() {
    let n = read_int();
    
    for _ in 0 .. n {
        let input = read_string();
        let mut iter = input.split_whitespace();

        let a: i64 = iter.next().unwrap().parse().expect("Error");
        let b: i64 = iter.next().unwrap().parse().expect("Error");
        let c: i64 = iter.next().unwrap().parse().expect("Error");


        let res1 = expon(b, c, PHI_P);
        let res2 = expon(a, res1, P);
        
        println!("{res2}");
    }
}

fn expon(mut a: i64, mut b: i64, modi: i64) -> i64 {
    let mut res = 1;
    a %= modi;
    
    while b > 0 {
        
        if b % 2 == 1 {
            res = res * a % modi;
        }
       
        a = a * a % modi;
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