use std::io;

static MOD: i64 = 1000000007;

fn dp(grid: &Vec<Vec<char>>, n: usize) -> i64 {
    let mut memo = vec![vec![0; n]; n];

    if grid[0][0] != '*' {
        memo[0][0] = 1;
    }

    for x in 0..n {
        for y in 0..n {

            if grid[x][y] == '*'{
                continue;
            }

            if x > 0{
                memo[x][y] = (memo[x][y] + memo[x - 1][y]) % MOD;
            }

            if y > 0{
                memo[x][y] = (memo[x][y] + memo[x][y - 1]) % MOD;
            }

            if x > 0 && y > 0{
                memo[x][y] = (memo[x][y] + memo[x - 1][y - 1]) % MOD;
            }
        }
    }

    memo[n - 1][n - 1] 
}

fn read_input() -> (usize, Vec<Vec<char>>) {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("ERRO");
    let n: usize = input.trim().parse().expect("ERRO");

    let mut grid: Vec<Vec<char>> = Vec::new();

    for _ in 0..n {
        input.clear();
        io::stdin().read_line(&mut input).expect("ERRO");
        let line: Vec<char> = input.trim().chars().collect();
        grid.push(line);
    }

    (n, grid)
}

fn main(){
    let (n, grid) = read_input();
    println!("{}", dp(&grid,n));
}