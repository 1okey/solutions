use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

#[derive(Debug)]
struct StackMove {
    count: usize,
    from: usize,
    to: usize,
}


fn move_from_line(line: String) -> StackMove {
    let  move_vec = line.split_whitespace()
        .filter(|&w| w.chars().next().unwrap().is_digit(10))
        .collect::<Vec<&str>>();

    let mut move_vec_iter = move_vec.iter();

    StackMove{
        count: move_vec_iter.next().unwrap().parse::<usize>().unwrap(),
        from: move_vec_iter.next().unwrap().parse::<usize>().unwrap(),
        to: move_vec_iter.next().unwrap().parse::<usize>().unwrap(),
    }
}

fn parse_stacks(stack_lines: Vec<String>) -> Vec<Vec<char>> {
    let mut stacks: Vec<Vec<char>> = vec!();
    let mut rev_it = stack_lines.iter().rev();
    
    let stack_ids = rev_it.next().unwrap().split_whitespace().map(|w| w.parse::<u8>().unwrap()).collect::<Vec<u8>>();
    for i in 0..*stack_ids.last().unwrap() {
        stacks.push(vec!());
    }

    for line in rev_it {
        let mut char_idx = 0;
        for (idx, c) in line.chars().enumerate() {
            if idx % 4 == 1 {
                if c.is_alphabetic() {
                    stacks[char_idx].insert(0, c);
                }
                char_idx += 1;
            }
        }        
    }

    stacks
}

fn main() {
    if let Ok(mut lines) = read_lines("./inputs/5.Supply Stacks.txt") {

        let mut stack_lines = vec!();
        for _ in 0..10 {
            if let Some(Ok(stack_line)) = lines.next() {
                stack_lines.push(stack_line);    
            }
        }

        stack_lines.pop();
        let mut parsed_map = parse_stacks(stack_lines);
        
        for (idx, line) in lines.enumerate() {
            if let Ok(ok_line) = line {
                let stack_move = move_from_line(ok_line);
                let from_len = parsed_map[stack_move.from - 1];

                let drain_count = if stack_move.count > from_len {from_len } else { stack_move.count };

                let drain = parsed_map[stack_move.from - 1].drain(..drain_count).collect::<Vec<char>>();

                // removing .rev() is a solution to part 1
                for d in drain.iter().rev() {
                    parsed_map[stack_move.to - 1].insert(0, *d);    
                }
            }
        }

        let top_crates = parsed_map.iter().map(|stack| stack.first().unwrap()).collect::<String>();

        println!("{:?}", top_crates);
    }
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}