package main

import (
	"fmt"
	"reflect"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func preorderTraversal(root *TreeNode) []int {
	result := []int{}
	if root == nil {
		return result
	}

	stack := []*TreeNode{root}

	for len(stack) > 0 {
		// pop from the end
		n := len(stack) - 1
		nt := stack[n]
		stack = stack[:n]

		result = append(result, nt.Val)

		// Push right first so left is processed first (LIFO).
		if nt.Right != nil {
			stack = append(stack, nt.Right)
		}
		if nt.Left != nil {
			stack = append(stack, nt.Left)
		}
	}

	return result
}

// Build a tree from a LeetCode-style level-order slice (nil = null).
func buildTree(arr []*int) *TreeNode {
	if len(arr) == 0 || arr[0] == nil {
		return nil
	}

	root := &TreeNode{Val: *arr[0]}
	q := []*TreeNode{root}
	i := 1

	for len(q) > 0 && i < len(arr) {
		cur := q[0]
		q = q[1:]

		if i < len(arr) {
			if arr[i] != nil {
				cur.Left = &TreeNode{Val: *arr[i]}
				q = append(q, cur.Left)
			}
			i++
		}
		if i < len(arr) {
			if arr[i] != nil {
				cur.Right = &TreeNode{Val: *arr[i]}
				q = append(q, cur.Right)
			}
			i++
		}
	}

	return root
}

func iptr(v int) *int { return &v }

func main() {
	// Level-order: 1 -> (2,3); 2 -> (4,5); 3 -> (nil,8);
	//              5 -> (6,7); 8 -> (9,nil)
	input := []*int{
		iptr(1), iptr(2), iptr(3),
		iptr(4), iptr(5), nil, iptr(8),
		nil, nil, iptr(6), iptr(7), iptr(9),
	}

	root := buildTree(input)
	result := preorderTraversal(root)
	expected := []int{1, 2, 4, 5, 6, 7, 3, 8, 9}

	fmt.Printf("Result  : %v\n", result)
	fmt.Printf("Expected: %v\n", expected)

	if !reflect.DeepEqual(result, expected) {
		panic("Preorder traversal mismatch!")
	}
	fmt.Println("PASS")

	if len(preorderTraversal(nil)) != 0 {
		panic("Empty tree failed")
	}
	fmt.Println("Empty tree PASS")
}
