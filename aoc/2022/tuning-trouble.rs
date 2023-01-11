use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::collections::HashSet;

#[derive(Debug)]
struct StackMove {
    count: usize,
    from: usize,
    to: usize,
}

fn main() {
    const packet_size: usize = 14;
    if let Ok(lines) = read_lines("./inputs/6.Tuning Trouble.txt") {
        for line in lines {
            if let Ok(seq) = line {
                println!("{:?}", seq.chars().collect::<Vec<char>>().windows(packet_size).position(|w| {
                    let chars =  w.iter().collect::<HashSet<&char>>();
                    chars.len() == packet_size
                }).unwrap() + packet_size);
            }
        }
    }
}


fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}