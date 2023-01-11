use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn get_ranges(first: &str, second: &str) -> (Vec<i32>, Vec<i32>) {
    (
        first.split("-").map(|num| num.parse::<i32>().unwrap()).collect::<Vec<i32>>(), 
        second.split("-").map(|num| num.parse::<i32>().unwrap()).collect::<Vec<i32>>()
    )
}

fn do_contain(first: Vec<i32>, second: Vec<i32>) -> bool {
    (first[0] >= second[0] && first[1] <= second[1]) || 
    (second[0] >= first[0] && second[1] <= first[1])
}

fn do_overlap(first: Vec<i32>, second: Vec<i32>) -> bool {
    (first[1] >= second[0] && first[1] <= second[1]) || 
    (second[1] >= first[0] && second[1] <= first[1])
}

fn main() {
    if let Ok(lines) = read_lines("./inputs/4.Camp Cleanup.txt") {
        let mut contain = 0;
        let mut overlap = 0;

        for line in lines {
            if let Ok(ok_line) = line {
                let mut pairs = ok_line.split(",");
                let (first, second) = (pairs.next().unwrap(), pairs.next().unwrap());
                let (r_range, l_range) = get_ranges(first, second);

                if do_contain(r_range.clone(), l_range.clone()) {
                    contain += 1;
                }

                if do_overlap(r_range, l_range) {
                    overlap += 1;
                }
            }
        }

        println!("contain = {}, overlap = {}", contain, overlap);
    }
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}