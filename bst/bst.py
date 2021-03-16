# python3

# Implementation of a binary search tree

class TreeNode(object):
    """ node key is larger than any key of left children.
        node key is smaller than any key of right children.
    """
    def __init__(self, key = None, parent = None, left = None, right = None):
        self.key = key
        self.parent = parent
        self.left = left
        self.right = right

 
class bst(object):
    def __init__(self):
        self._root_node = None

    def find_recursive(self, key, node = None):

        if node == None:
            node = self._root_node

        if node.key == key:
            return node

        elif node.key > key:
            if node.left != None:
                return self.find_recursive(key, node.left)
            return node

        # else node.key < key
        if node.right != None:
            return self.find_recursive(key, node.right)
        return node

    def insert(self, key):

        if self._root_node == None:
            self._root_node = TreeNode(key, None, None, None)
            return

        parent = self.find_recursive(key, self._root_node)
        if key > parent.key:
            # assert parent.right == None
            parent.right = TreeNode(key, parent, None, None)
            return

        # We should be less than key, assert it!
        parent.left = TreeNode(key, parent, None, None)

    def print_tree_r(self, node, depth):

        depth += 1
        if node.right != None:
            self.print_tree_r(node.right, depth)

        space = ""
        for i in range(depth):
            space += " "

        print("{0}{1}".format(space, node.key))

        if node.left != None:
            self.print_tree_r(node.left, depth)

    def print_tree(self):
        if self._root_node == None:
            print("Empty tree")
            return

        self.print_tree_r(self._root_node, 1)
        print("")


if __name__ == "__main__":

    my_bst = bst()
    my_bst.print_tree()
    my_bst.insert(5)
    my_bst.print_tree()
    my_bst.insert(2)
    my_bst.print_tree()
    my_bst.insert(8)
    my_bst.print_tree()
    my_bst.insert(1)
    my_bst.print_tree()
