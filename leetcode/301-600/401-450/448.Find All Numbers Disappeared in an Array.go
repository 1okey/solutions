package main

import "fmt"

func findDisappearedNumbers(nums []int) []int {
    counter:= 0
    for counter < len(nums) {
        if nums[nums[counter] - 1] != nums[counter] {
            nums[nums[counter] - 1], nums[counter] = nums[counter], nums[nums[counter] -1]
        } else {
            counter += 1
        }
    }

    disappeared := []int{}
    for idx, n := range nums {
        if n != idx + 1 {
            disappeared = append(disappeared, int(idx + 1))
        }
    }

    return disappeared
}

func main() {
		fmt.Println(findDisappearedNumbers([]int{4,3,1,3}))
}
