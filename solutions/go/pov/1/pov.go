package pov

type Tree struct {
	value    string
	children []*Tree
}

// New creates and returns a new Tree with the given root value and children.
func New(value string, children ...*Tree) *Tree {
	curr := &Tree{
		value: value,
	}

	for _, child := range children {
		curr.children = append(curr.children, child)
	}

	return curr
}

// Value returns the value at the root of a tree.
func (tr *Tree) Value() string {
	if tr == nil {
		return ""
	}
	return tr.value
}

// Children returns a slice containing the children of a tree.
// There is no need to sort the elements in the result slice,
// they can be in any order.
func (tr *Tree) Children() []*Tree {
	children := tr.children
	return children
}

// String describes a tree in a compact S-expression format.
// This helps to make test outputs more readable.
// Feel free to adapt this method as you see fit.
func (tr *Tree) String() string {
	if tr == nil {
		return "nil"
	}
	result := tr.Value()
	if len(tr.Children()) == 0 {
		return result
	}
	for _, ch := range tr.Children() {
		result += " " + ch.String()
	}
	return "(" + result + ")"
}

// POV problem-specific functions

// findPath: Returns an in-order slice of nodes from root to target, if target exists
func findPath(node *Tree, target string) []*Tree {
	// verify node exists
	if node == nil {
		return nil
	}

	if node.value == target {
		return []*Tree{node}
	}

	// search all children of each node
	for _, c := range node.children {
		if next := findPath(c, target); next != nil {
			return append([]*Tree{node}, next...)
		}
	}

	// base case when no children and target not found
	return nil
}

// FromPov returns the pov from the node specified in the argument.
func (tr *Tree) FromPov(from string) *Tree {
	pathToNode := findPath(tr, from)

	if pathToNode == nil {
		return nil
	}
	for i, node := range pathToNode {
		// make current node child of next node
		if i+1 < len(pathToNode) {
			pathToNode[i+1].children = append(pathToNode[i+1].children, node)

			// delete pointer of current node that makes next its child
			for j, n := range node.children {
				if n == pathToNode[i+1] {
					node.children = append(node.children[:j], node.children[j+1:]...)
				}
			}
		}
	}

	return pathToNode[len(pathToNode)-1]

}

// PathTo returns the shortest path between two nodes in the tree.
func (tr *Tree) PathTo(from, to string) []string {
	newRoot := tr.FromPov(from)
	pathToTarget := findPath(newRoot, to)
	if pathToTarget == nil {
		return nil
	}

	result := make([]string, len(pathToTarget))
	for i, n := range pathToTarget {
		result[i] = n.value
	}

	return result
}
