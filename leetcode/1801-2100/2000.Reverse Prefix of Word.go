package main

import (
	"fmt"
	"strings"
)

func reversePrefix(word string, ch byte) string {
    idx := strings.Index(word, string(ch))

    if idx < 0 {
        return word
    }

    arr := strings.Split(word, "")
    for i := 0; i <= idx / 2; i+=1 {
        arr[i], arr[idx - i] = arr[idx - i], arr[i]  
    }

    return strings.Join(arr, "")
}

func main() {
    fmt.Print(reversePrefix("abcdefd", 'd'))
}
