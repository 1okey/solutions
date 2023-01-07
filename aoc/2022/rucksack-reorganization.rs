use std::collections::HashSet;
use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;


fn main() {

    if let Ok(lines) = read_lines("./inputs/3.Rucksack Reorganization.txt") {
        let mut score = 0;
        let mut group_score = 0;
        let mut group_count = 1;

        let mut group_rucksacks = Vec::new();
        for line in lines {

            if let Ok(rucksack) = line {

                // part one
                let word_slice = rucksack.chars().collect::<Vec<char>>();
                let mut chunks = word_slice.chunks(rucksack.len() / 2).map(|chunk| {
                    chunk.iter().collect::<HashSet<&char>>()
                });
                let (first, second) = (chunks.next().unwrap(), chunks.next().unwrap());
                let intersection = first.intersection(&second).next().unwrap();
                if intersection.is_lowercase() {
                    score += (**intersection as u32) - 96;
                } else {
                    score += (**intersection as u32) - 64 + 26;
                }

                // part two
                group_rucksacks.push(rucksack);
                if group_count == 3 {
                    let mut rucksacks = group_rucksacks.iter().map(|rucksack| {
                        rucksack.chars().collect::<HashSet<char>>()
                    });
                    let (first,second,third) = (rucksacks.next().unwrap(), rucksacks.next().unwrap(), rucksacks.next().unwrap());
                    let (first_inter, second_inter) = (first.intersection(&second), first.intersection(&third));

                    let (first_set, second_set) = (first_inter.collect::<HashSet<&char>>(), second_inter.collect::<HashSet<&char>>());
                    let intersection = first_set.intersection(&second_set).next().unwrap();
                    if intersection.is_lowercase() {
                        group_score += (**intersection as u32) - 96; // 96 ascii code preceding 'a'
                    } else {
                        group_score += (**intersection as u32) - 64 + 26 // 64 ascii code preceding 'A' , 26 - beggining of uppercase score;
                    }
                    group_rucksacks.clear();
                }
                group_count = (group_count % 3) + 1;
            }
        }
        println!("{}, {}", score, group_score);
    }
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}