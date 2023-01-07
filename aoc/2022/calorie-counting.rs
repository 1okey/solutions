use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::collections::BTreeSet;


fn main() {
    if let Ok(lines) = read_lines("./inputs/1.Calorie Counting.txt") {
        let mut acc = 0;
        let mut max = 0;
        let mut leaderboard = BTreeSet::new();

        for line in lines {
            if let Ok(ip) = line {
                if let Ok(calorie) = ip.parse::<i32>() {
                    acc += calorie;
                } else {
                    leaderboard.insert(acc);
                    max = if acc > max { acc } else { max };
                    acc = 0;
                }
            }
        }

        let first = leaderboard.pop_last().unwrap();
        let second = leaderboard.pop_last().unwrap();
        let third = leaderboard.pop_last().unwrap();
        println!("{}", first + second + third);
    }
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}