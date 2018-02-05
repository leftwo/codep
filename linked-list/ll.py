# python3

# Template used for linked list implementation for a coursera programming
# assignment.

class Node(object):                                                 
    def __init__(self, data=None, next_node=None):
        self.data = data
        self.next_node = next_node

    def get_next(self):
        return self.next_node

    def get_data(self):
        return self.data

    def set_next(self, new_next):
        self.next_node = new_next

class LinkedList(object):
    def __init__(self, head=None):
        self.head = head

    def find(self, data):
        current = self.head
        while current:
            if current.get_data() == data:
                return current
            else:
                current = current.get_next()

        return None

    def insert(self, data):
        """ Insert a new node, but don't insert duplicate data items """
        if self.find(data) == None:
            new_node = Node(data)
            new_node.set_next(self.head)
            self.head = new_node

    def print(self):
        """ Print out contents of list """
        current = self.head
        count = 0
        while current:
            print("[{}]:{} ".format(count, current.get_data()), end = "")
            current = current.get_next()
            count = count + 1

        print("")

    def delete(self, data):
        """ Delete the node with matching data from the list.
            If it's not found, return without issue
        """
        current = self.head
        previous = None
        while current:
            if current.get_data() == data:
                break
            else:
                previous = current
                current = current.get_next()

        if current is not None:
            if previous is None:
                self.head = current.get_next()
            else:
                previous.set_next(current.get_next())

if __name__ == '__main__':
    ll = LinkedList()
    ll.insert(5)
    ll.insert(25)
    ll.insert(2)
    ll.insert(2)
    ll.insert(2)
    ll.insert(2)
    ll.insert(2)
    ll.print()
    ll.delete(25)
    ll.delete(44)
    ll.delete(25)
    ll.print()
    node = ll.find(9)
    if node:
        print("{}".format(node.get_data()))
    else:
        print("missing")
