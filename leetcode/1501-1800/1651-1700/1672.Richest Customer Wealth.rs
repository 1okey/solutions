// https://leetcode.com/problems/richest-customer-wealth

impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        let mut max = 0;
        let wealths: Vec<i32> = accounts.iter().map(|customer| {
            customer.iter().fold(0, |acc, &account| account + acc)
        }).collect();

        for wealth in wealths {
            max = if max > wealth { max } else { wealth }
        }

        max
    }
}

impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        accounts.iter().map(|account| account.iter().sum()).max().unwrap()
    }
}