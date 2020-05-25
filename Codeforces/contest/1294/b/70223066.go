package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
	"sort"
)

type Vertex struct {
	x, y int
}

func getMove(from, to Vertex) string{
	var move string
	for i := 0; i < to.x - from.x; i++ {
		move = move + "R"
	}
	for j := 0; j < to.y - from.y; j++ {
		move = move + "U"
	}
	return move
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var t int
	fmt.Fscan(in, &t)
	var ans []string
	for i := 0; i < t; i++ {
		var n int
		var input []Vertex
		fmt.Fscan(in, &n)
		for j := 0; j < n; j++ {
			var x, y int
			fmt.Fscan(in, &x, &y)
			input = append(input, Vertex{x, y})
		}
		input = append(input, Vertex{0, 0})
		sort.Slice(input, func(i, j int)bool {
			if input[i].x < input[j].x{
				return true;
			}else{
				if input[i].y < input[j].y{
					return true;
				}else{
					return false;
				}
			}
		})
		ok := true
		n = n + 1
		var tmp string
		//fmt.Println(input)
		for j := 1; j < n; j++ {
			if input[j].x>=input[j-1].x&&input[j].y>=input[j-1].y {
				tmp = tmp + getMove(input[j-1], input[j])
			}else{
				ok = false
			}
		}
		if ok {
			ans = append(ans, "YES")
			ans = append(ans, tmp)
		}else{
			ans = append(ans, "NO")
		}
	}
	fmt.Fprintln(out, strings.Join(ans, "\n"));
}