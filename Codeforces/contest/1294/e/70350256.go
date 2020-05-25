package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
	"sort"
	"math"
	"strconv"
)

var _ = sort.Slice
var _ = math.Sqrt
var _ = strconv.Itoa

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var n, m int
	fmt.Fscan(in, &n, &m)
	var ans []string
	mape := make([][]int, m)
	for i := 0; i < m; i++ {
		mape[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			fmt.Fscan(in, &mape[j][i])
		}
	}
	moves := 0
	for i := 0; i < m; i++ {
		tmp := make([]int, n)
		move := n
		//fmt.Println(i)
		for j := 0; j < n; j++ {
			start := i+1
			now := mape[i][j]
			orgplace := (now-start)/m
			if ((now - start) % m == 0 && now <= n*m){
				tmp[(j-orgplace+n)%n]++
			}
		}
		for j := 0; j < n; j++{
			nowmove := n - tmp[j] + j
			if nowmove < move {
				move = nowmove
			}
		}
		moves = moves + move
	}
	ans = append(ans, fmt.Sprint(moves))
	fmt.Fprintln(out, strings.Join(ans, "\n"));
}