# python3
#
# Stub functions for binary tree min heap as an array.

import math

class HeapBuilder:
    def __init__(self):
        self._swaps = []
        self._data = []
        self._size = 0
        self._mi = 0

    def ReadData(self):
        n = int(input())
        self._data = [int(s) for s in input().split()]
        assert n == len(self._data)
        self._size = n
        if n > 0:
            self._mi = n - 1

    def WriteResponse(self):
        print(len(self._swaps))
        for swap in self._swaps:
            print(swap[0], swap[1])

    def PrintHeap(self, text=None):
        if text != None:
            print(text)

        print("size:{} mi:{}".format(self._size, self._mi));
        for i in range(self._size):
            print("[{}]:{} ".format(i, self._data[i]));
            if self._mi == i:
                print("End of active Array")

        print("")

    def PrintArray(self):
        for i in range(len(self._data)):
            print("[{}]:{} ".format(i, self._data[i]), end = "");
            if self._mi == i:
                print("E ", end = "")

        print("")

    def Insert(self):
        """ Add element to the end of the array, increase size
        Verify it's less than max if we have a max """

    def ExtractMin(self):
        """ replace root with last leaf (in array model)
        sift down until children are > us.
        Reduce size by one (the end of the heap portion of the array)"""

    def SiftUp(self, i):
        """ swap a node with it's parent until max or parent is < """
        while i > 0 and self._data[self.Parent(i)] > self._data[i]:
            self._swaps.append((i, self.Parent(i)))
            self._data[i], self._data[self.Parent(i)] = \
                        self._data[self.Parent(i)], self._data[i]
            i = self.Parent(i) 

    def SiftDown(self, i):
        """ push i down until the values below it are all greater """
        minIndex = -1
        # print("sift down:{}".format(i))
        while i != minIndex:
            minIndex = i
            li = self.LeftChild(i)
            # print("li:{} mi:{}".format(li, minIndex))
            if li <= self._mi and self._data[li] < self._data[minIndex]:
                minIndex = li

            ri = self.RightChild(i)
            # print("ri:{} mi:{}".format(ri, minIndex))
            if ri <= self._mi and self._data[ri] < self._data[minIndex]:
                minIndex = ri

            if i != minIndex:
                # print("index:{} swap with index:{}".format(i, minIndex))
                self._data[i], self._data[minIndex] = self._data[minIndex], self._data[i]
                self._swaps.append((i, minIndex))
                i = minIndex
                minIndex = -1
                
        
    def BuildHeap(self):
        """ make an array into a heap. """
        for i in range(self._mi // 2, -1, -1):
            self.SiftDown(i)

    def ChangePriority(self, i, newp):
        """ Change value, then let element sift up or down depending """

    def Remove(self, i):
        """ Change priority to infinity, sift up, then extract max """

    def Parent(self, i):
        """ parent floor of i/2 """
        return math.floor((i - 1) / 2)

    def LeftChild(self, i):
        """ left child is 2i """
        return 2 * i + 1

    def RightChild(self, i):
        """ right child 2i + 2 """
        return 2 * i + 2

    def Solve(self):
        self.ReadData()
        self.PrintHeap()
        self.BuildHeap()
        self.PrintHeap()
        self.WriteResponse()

if __name__ == '__main__':
    heap_builder = HeapBuilder()
    heap_builder.Solve()
