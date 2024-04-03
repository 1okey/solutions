package main

import (
	"fmt"
	"reflect"
)


func construct2DArray(original []int, m int, n int) [][]int {

    matrix := make([][]int, 0)
    if len(original) != m * n {
        return matrix
    }

    start := 0
    for i:= 1; i <= m; i+= 1 {
        matrix = append(matrix, original[start:n * i])
        start = i * n
    }

    return matrix
}


func main () {
		var result [][]int = construct2DArray([]int{1,2,3,4}, 2, 2)

		expected := [][]int{{1,2,},{3,4}}

		fmt.Print(reflect.DeepEqual(expected, result))
}
