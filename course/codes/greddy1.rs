use std::io;

fn main() {
    let n: usize = read_int();
    
    let numbers: Vec<usize> = read_string()
        .split_whitespace()
        .map(|s| s.parse().expect("Error"))
        .collect();
    
    let mut indexes = vec![0; n];

    for (i, &num) in numbers.iter().enumerate() {
        indexes[num-1] = i;
    }
    
    let mut qtd = 1;
    
    for i in 0 .. (n-1){
        if indexes[i] > indexes[i+1] {
            qtd+=1;
        }
    }
    
    println!("{qtd}");
    
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