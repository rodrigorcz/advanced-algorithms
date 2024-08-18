use std::io;
use std::collections::BinaryHeap;
use std::cmp::Reverse;

fn main(){

  let n_inputs: i32 = read_int();
  let mut heap = BinaryHeap::new();

  for _ in 0..n_inputs{
    let input = read_string();
    let mut iter = input.split_whitespace();

    let _ = iter.next().unwrap().to_string(); 
    let year: i32 = iter.next().unwrap().parse().expect("Error");
    let time: i32 = iter.next().unwrap().parse().expect("Error");

    heap.push(Reverse((time, year, time)));
  }

  let cases: i32 = read_int();

  for _ in 0..cases{
    if let Some(Reverse((currt, year, time))) = heap.pop(){
      println!("{year}");

      let new_currt:i32 = currt + time;
      heap.push(Reverse((new_currt, year, time)));
    }
  }
}

fn read_int() -> i32 {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Error Input");
  input.trim().parse().expect("Error")
}

fn read_string() -> String {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Error Input");
  input.trim().to_string()
}