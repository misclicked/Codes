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
	var q, x, y int
	fmt.Fscan(in, &q, &x)
	var ans []string
	mape := make([]int, x)
	ansi := 0
	for i := 0; i < q; i++ {
		fmt.Fscan(in, &y);
		mape[y%x]++
		for mape[ansi%x] > 0 {
			mape[ansi%x]--
			ansi++
		}
		ans = append(ans, fmt.Sprint(ansi))
	}
	fmt.Fprintln(out, strings.Join(ans, "\n"));
}