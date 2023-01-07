
// A for Rock, B for Paper, and C for Scissors. 

// The second column X for Rock, Y for Paper, and Z for Scissors

// 1 for Rock, 2 for Paper, and 3 for Scissors

use std::collections::HashMap;
use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;


fn main() {

    let values: HashMap<char, i32> = HashMap::from([
        ('X', 1), ('Y', 2), ('Z', 3)
    ]);

    let outcomes: HashMap<char, HashMap<char, i32>> = HashMap::from([
        ('A', HashMap::from([
            ('X', 3),
            ('Z', 0),
            ('Y', 6),
        ])), 
        ('B', HashMap::from([
            ('X', 0),
            ('Y', 3),
            ('Z', 6),
        ])),
        ('C', HashMap::from([
            ('X', 6),
            ('Y', 0),
            ('Z', 3),
        ])),
    ]);

    let outcomes_v2: HashMap<char, HashMap<char, (char, i32)>> = HashMap::from([
        ('A', HashMap::from([
            ('X', ('Z', 0)),
            ('Z', ('Y', 6)),
            ('Y', ('X', 3)),
        ])), 
        ('B', HashMap::from([
            ('X', ('X', 0)),
            ('Z', ('Z', 6)),
            ('Y', ('Y', 3)),
        ])),
        ('C', HashMap::from([
            ('X', ('Y', 0)),
            ('Z', ('X', 6)),
            ('Y', ('Z', 3)),
        ])),
    ]);


    if let Ok(lines) = read_lines("./inputs/2.Rock Paper Scissors.txt") {
        let mut score = 0;    
        let mut score_v2 = 0;    
        for line in lines {
            if let Ok(play) = line {
                // part one
                let mut play = play.chars();
                let (opp, mine) = (play.nth(0).unwrap(), play.nth(1).unwrap());
                score += outcomes[&opp][&mine] + values[&mine];

                // part two
                let (val, result) = outcomes_v2[&opp][&mine];
                score_v2 += result + values[&val];
            }
        }
        println!("{}, {}", score, score_v2);
    }
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}