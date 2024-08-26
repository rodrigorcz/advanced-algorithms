use std::io;
use std::collections::BinaryHeap;
use std::cmp::Reverse;

fn main(){
  let n  = read_int();
  let mut heap = BinaryHeap::new();

  for _ in 0 .. n {
    let input = read_string();
    let mut iter = input.split_whitespace();

    let t: i64 = iter.next().unwrap().parse().expect("Error");
    let d: i64 = iter.next().unwrap().parse().expect("Error");

    heap.push(Reverse((t, d)));
  }

  let mut cust = 0;
  let mut stack = 0;

  for _ in 0 .. n{
    if let Some(Reverse((t, d))) = heap.pop(){
      cust = cust + d - (t + stack);
      stack = stack + t;
    }
  }

  println!("{cust}");
}

fn read_int() -> i64 {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Error Input");
  input.trim().parse().expect("Error")
}

fn read_string() -> String {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Error Input");
  input.trim().to_string()
} 
