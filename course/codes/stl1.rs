use std::io;
use std::collections::HashMap;

fn main(){

    let n_cases: i32 = read_int();

    for i in 0..n_cases {
        let m_cases: i32 = read_int();
        
        let mut courses: HashMap<String, i32> = HashMap::new();

        for _ in 0..m_cases{
            let input = read_string();
            let mut iter = input.split_whitespace();

            let word = iter.next().unwrap().to_string(); 
            let n_days: i32 = iter.next().unwrap().parse().expect("Error");
    
            courses.insert(word, n_days);
        }

        let days: i32 = read_int();
        let search = read_string();

        let key = courses.get(&search).unwrap_or(&0);

        if *key <= days && *key != 0{
            println!("Case {}: Ufa!", i+1);
        }else if *key <= days + 5 && *key != 0{
            println!("Case {}: Atrasado", i+1);
        }else{
            println!("Case {}: Deu ruim! Va trabalhar", i+1);
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