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
	var t int
	fmt.Fscan(in, &t)
	var ans []string
	for i := 0; i < t; i++ {
		var n int
		fmt.Fscan(in, &n)
		cnt := 0
		var lst []int
		for i := 2; i*i <= n; i++ {
			for n%i == 0 {
				n = n / i
				lst = append(lst, i)
				cnt++
			}
		}
		if n != 1 {
			lst = append(lst, n)
			cnt++
		}
		sta :=[]int{lst[0]}
		ansstr := []string{strconv.Itoa(lst[0])}
		now := 1
		top := 0
		set := make(map[int]bool)
		set[lst[0]] = true
		for i := 1; i < len(lst); i++{
			now = now * lst[i]
			if set[now] == false && (top != 1 || i == len(lst)-1) {
				ansstr = append(ansstr, strconv.Itoa(now))
				sta = append(sta, now)
				set[now] = true
				top++
				now = 1
			}
		}
		
		if top == 2{
			ans = append(ans, "YES");
			ans = append(ans, strings.Join(ansstr[:3], " "))
		}else{
			ans = append(ans, "NO")
		}
	}
	fmt.Fprintln(out, strings.Join(ans, "\n"));
}