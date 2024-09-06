use std::io;

fn func_aux(pages: &[i32], n: usize, m: i32, max_pages: i32) -> bool {
    let mut students = 1;
    let mut current: i32 = 0;

    for &page in pages.iter().take(n) {
        if page > max_pages {
            return false;
        }

        if current + page > max_pages {
            students += 1;
            current = page;

            if students > m {
                return false;
            }
        } else {
            current += page;
        }
    }

    true
}

fn find_min(pages: &[i32], n: usize, m: i32) -> i32 {
    let low = *pages.iter().max().unwrap_or(&0);
    let high: i32 = pages.iter().sum();
    let mut result = high;

    let mut low = low;
    let mut high = high;

    while low <= high {
        let mid = (high + low) / 2;

        if func_aux(pages, n, m, mid) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    result
}

fn read_input() -> (Vec<i32>, usize, i32) {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("ERRO");
    let values: Vec<i32> = input
        .trim()
        .split_whitespace()
        .map(|s| s.parse().expect("ERRO"))
        .collect();

    let n = values[0] as usize;
    let m = values[1];

    input.clear();
    io::stdin().read_line(&mut input).expect("ERRO");

    let pages: Vec<i32> = input
        .trim()
        .split_whitespace()
        .map(|s| s.parse().expect("ERRO"))
        .collect();

    (pages, n, m)
}

fn main() {
    let (pages, n, m) = read_input();
    println!("{}", find_min(&pages, n, m));
}