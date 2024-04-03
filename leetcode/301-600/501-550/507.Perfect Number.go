package main

import "fmt"


func checkPerfectNumber(num int) bool {
    sum := 0
    div := 1
    for div <= num / 2 {
        if num % div == 0 {
            sum += div
        }
        div += 1
    }

    return sum == num
}

func main() {
		fmt.Print(checkPerfectNumber(28))
}
