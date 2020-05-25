package main

import (
	"fmt"
)

func main() {
	var t int64
	fmt.Scan(&t)
	for i := int64(0); i < t; i++ {
		var a, b, c, n int64
		fmt.Scan(&a,&b,&c,&n)
		result := a+b+c+n
		if result%3 == 0 && result/3 >= a && result/3 >= b && result/3 >= c{
			fmt.Println("YES")
		}else{
			fmt.Println("NO")
		}
	}
}