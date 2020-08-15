package add

import (
	"fmt"
	"strconv"
)

/**
	给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。
	如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
	您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

	示例：
	输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
	输出：7 -> 0 -> 8
*/

type LinkInteger struct {
	digit byte
	next *LinkInteger
}

func (a *LinkInteger) ToString() []string {
	result := []string{}
	for {
		if a == nil {
			break
		}

		result = append(result, strconv.Itoa(int(a.digit)))
		a = a.next
	}
	
	return result
}

func (a *LinkInteger) Add(b *LinkInteger) *LinkInteger {
	var result *LinkInteger
	last := result
	carry := byte(0)
	for {
		if a == nil || b == nil {
			break
		}

		sum := a.digit + b.digit + carry
		carry = sum / 10
		sum = sum % 10
		if last == nil {
			result = &LinkInteger{sum, nil}
			last = result
			a = a.next
			b = b.next
			continue
		}
		last.next = &LinkInteger{sum, nil}
		last = last.next

		a = a.next
		b = b.next
	}

	for {
		if a == nil {
			break
		}

		if last == nil {
			result = &LinkInteger{a.digit, nil}
			last = result
			continue
		}
		last.next = &LinkInteger{a.digit, nil}
		last = last.next
		a = a.next
	}

	for {
		if b == nil {
			break
		}

		if last == nil {
			result = &LinkInteger{b.digit, nil}
			last = result
			continue
		}
		last.next = &LinkInteger{b.digit, nil}
		last = last.next
		b = b.next
	}

	return result
}

func MakeLinkInteger(abc int) *LinkInteger {
	if abc < 0 {
		return nil
	} else if abc == 0 {
		return &LinkInteger{0, nil}
	}

	mod := abc % 10
	head := &LinkInteger{byte(mod), nil}
	last := head
	for {
		abc = abc / 10
		if abc <= 0 {
			break
		}
		mod = abc % 10
		node := &LinkInteger{byte(mod), nil}
		last.next = node
		last = node
	}

	return head
}

func RunSample() {
	t1 := MakeLinkInteger(1654530)
	t2 := MakeLinkInteger(43654)
	fmt.Println("param1:", t1.ToString())
	fmt.Println("param2:", t2.ToString())
	fmt.Println("sum:   ", t2.Add(t1).ToString())
}
