package linkedlist

import (
	"errors"
)

// Define List and Node types here.
// Note: The tests expect Node type to include an exported field with name Value to pass.

type Node struct {
	Value any
	next  *Node
	prev  *Node
}

type List struct {
	head *Node
	tail *Node
}

func NewList(elements ...any) *List {
	list := &List{head: nil, tail: nil}

	for _, val := range elements {
		// NewListn := &Node{Value: val}
		//n.Value = val
		list.Push(val)
	}
	return list
}

func (n *Node) Next() *Node {
	if n == nil {
		return nil
	}
	return n.next
}

func (n *Node) Prev() *Node {
	if n == nil {
		return nil
	}
	return n.prev
}

func (l *List) Unshift(v any) {
	n := &Node{Value: v}
	oldHead := l.First()
	if oldHead == nil {
		l.head = n
		l.tail = n
	} else {
		n.next = oldHead
		oldHead.prev = n
		l.head = n
	}
}

func (l *List) Push(v any) {
	n := &Node{Value: v}

	if l.tail == nil {
		l.head = n
		l.tail = n
	} else {
		t := l.Last()
		t.next = n
		n.prev = t
		l.tail = n
	}
}

func (l *List) Shift() (any, error) {
	oldHead := l.First()

	// shift on empty list
	if oldHead == nil {
		return 0, errors.New("shift on empty list")
	}

	l.head = oldHead.next

	// after shift, list is now empty
	if l.head == nil {
		l.tail = nil
		return oldHead.Value, nil
	}

	// list is now length 1
	if l.head.next == nil {
		l.head.prev = nil
		l.head.next = nil
		l.tail = l.head
		return oldHead.Value, nil
	}
	l.head.prev = nil
	return oldHead.Value, nil
}

func (l *List) Pop() (any, error) {
	t := l.Last()
	h := l.First()

	// Empty LL
	if h == nil {
		return 0, errors.New("popped on empty list")
	}

	// LL of length 1
	if h == t {
		l.head = nil
		l.tail = nil
		return h.Value, nil
	}

	if l.Count() == 2 {
		oldTail := l.tail
		l.tail = l.head
		l.head.next = nil
		l.head.prev = nil
		l.tail.prev = nil
		l.tail.next = nil
		return oldTail.Value, nil
	}

	// LL of length > 2
	newTail := t.prev
	newTail.next = nil
	l.tail = newTail
	return t.Value, nil

}

func (l *List) Reverse() {
	curr := l.Last()
	for curr != nil {
		newNext := curr.prev
		newPrev := curr.next
		curr.next = newNext
		curr.prev = newPrev
		curr = newNext
	}
	newHead := l.Last()
	l.tail = l.head
	l.head = newHead
	if l.head != nil {
		l.head.prev = nil
	}
	if l.tail != nil {
		l.tail.next = nil
	}
}

func (l *List) First() *Node {
	return l.head
}

func (l *List) Last() *Node {
	return l.tail
}

func (l *List) Count() int {
	num := 0
	curr := l.First()
	for curr != nil {
		num++
		curr = curr.next
	}
	return num
}

// Delete removes the first node in a list with a given value.
// Returns true if a node was removed.
func (l *List) Delete(v any) bool {
	curr := l.First()
	for curr != nil {
		if curr.Value == v {

			// node is head and tail
			if curr.prev == nil && curr.next == nil {
				l.head, l.tail = nil, nil
			} else if curr.prev == nil {
				newHead := l.head.next
				newHead.prev = nil
				l.head = newHead
			} else if curr.next == nil {
				newTail := l.tail.prev
				newTail.next = nil
				l.tail = newTail
			} else {
				prev := curr.prev
				next := curr.next
				prev.next = next
				next.prev = prev
			}
			return true
		}
		curr = curr.next
	}
	return false
}
