package main

import "fmt"

func smallestEqual(nums []int) int {
    smallest := -1
    l := len(nums) - 1
    for idx, _ := range nums {
        fmt.Println(l-idx, nums[l-idx], smallest)
        if (l - idx) % 10 == nums[l - idx] {
            smallest = l - idx
        } 
    }
    
    return smallest
}

func main() {
    fmt.Print(smallestEqual([]int{0,1,2}))
}
