use std::io;
use std::cmp;
use std::convert::TryInto;

fn dp(memo: &mut Vec<i32>, values: &Vec<i32>, n: usize, v: usize) -> i32{
  if v >= (n-1).try_into().unwrap() {
    return 0;
  }

  if memo[v] != -1 {
    return memo[v];
  }

  if values[v] == 0 {
    return i32::MAX-1;
  }

  memo[v] = i32::MAX-1;

  for i in 1..values[v]+1{
    let next = v + i as usize;

    if next < n.try_into().unwrap() {
      memo[v] = cmp::min(memo[v], dp(memo, values, n, next) + 1);
    }
  }

  memo[v]
}

fn main(){
  let n: usize = read_int();
  
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("ERRO");

  let values: Vec<i32> = input
      .trim()
      .split_whitespace()
      .map(|s| s.parse().expect("ERRO"))
      .collect();

  let mut memo: Vec<i32> = vec![-1; n];
  let res = dp(&mut memo, &values, n, 0);

  if (res >= i32::MAX-1) || (res < 0) {
    println!("Salto impossivel");
  }else{
    println!("{res}");
  }
}

fn read_int() -> usize {
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("Error Input");
  input.trim().parse().expect("Error")
}
