package main

import "fmt"

func search(nums []int, target int) int {
    
    start := 0
    end := len(nums) - 1

    for start <= end {
        idx := (start + end) / 2
        if nums[idx] < target {
            start = idx + 1
        } else if nums[idx] > target {
            end = idx - 1
        } else {
            return idx
        }
    }

    return -1
}

func main() {
    fmt.Println(search([]int{1,2,3,4,5,6}, 7))
}

