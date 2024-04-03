package main

import (
	"fmt"
	"strings"
)

func checkAlmostEquivalent(word1 string, word2 string) bool {
    dict := make(map[rune]int)
    for _, ch := range word1 {
        dict[ch]++
    }
    for _, ch := range word2 {
        dict[ch]--
    }

    for _, v := range dict {
        if v > 3 || v < -3 {
            return false
        }
    }

    return true
}

func main() {
    fmt.Print(checkAlmostEquivalent("abcdeef","abaaacc"))
}
