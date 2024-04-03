package main

import "fmt"


func countSegments(s string) int {
    count := 0
    for i := 0; i < len(s); {
        if s[i] == ' ' {
            i += 1
            continue
        } else if i + 1 < len(s) && s[i + 1] == ' '{
            count += 1
        }
        i += 1
    }

    if len(s) > 0 && s[len(s) - 1] != ' ' {
        count += 1
    }

    return count
}

func main() {
    fmt.Println(countSegments("Hello my name is Anton"))
}
