use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

#[derive(Debug)]
struct Node {
    name: String,
    size: Option<i32>,
    children: Option<Vec<Node>>,
}


fn main() {
    if let Ok(lines) = read_lines("./inputs/7.No Space Left On Device.txt") {
        let mut root: Node = Node{name: String::from("/"), size: None, children: Some(vec!())};
        let mut parent = &mut root;
        let mut current = &mut root;

        for line in lines {
            if let Ok(command) = line {
                let mut command = command.split_whitespace().collect::<Vec<&str>>();
                if command[0].eq("$") {
                    let action = command[1];
                    let destination = command.get(2);
                    if action.eq("ls") {
                        continue;
                    } else if action.eq("cd") {
                        continue;
                    }
                } else {
                    let size_or_type = command[0];
                    let name = command[1].to_string();
                    let mut children = current.children.as_mut().unwrap();
                    if size_or_type.eq("dir") {
                        children.push(Node{name: name, size: None, children: Some(vec!())});
                    } else {
                        children.push(Node{name: name, size: Some(size_or_type.parse::<i32>().unwrap()), children: None});
                    }
                }
            }
        }

        println!("{:?}", root);
        
    }
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}