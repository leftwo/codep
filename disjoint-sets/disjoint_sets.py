# python3
#
# Stub functions for disjoint-set tree an array with rank.
class DisjointSet:
    def __init__(self, n):
        self._parent = list(range(n))
        self._rank = [0 for x in range(n)]

    def PrintSet(self):
        print("P {}".format(self._parent))
        print("R {}".format(self._rank))

    def MakeSet(self, i):
          self._parent[i] = i
          self._rank[i] = 0

    def Find(self, i):
        """ Walk the parents until we find the top """
        while self._parent[i] != i:
            i = self._parent[i]
        return i

    def Union(self, i, j):
        i_id = self.Find(i)
        j_id = self.Find(j)
        if i_id == j_id:
            return

        if self._rank[i_id] > self._rank[j_id]:
            self._parent[j_id] = i_id
        else:
            self._parent[i_id] = j_id
            if self._rank[i_id] == self._rank[j_id]:
                self._rank[j_id] = self._rank[j_id] + 1

if __name__ == '__main__':
    ds = DisjointSet(13)
    ds.PrintSet()
    ds.Union(2, 10)
    ds.Union(7, 5)
    ds.Union(6, 1)
    ds.Union(3, 4)
    ds.Union(5, 11)
    ds.Union(7, 8)
    ds.Union(7, 3)
    ds.Union(12, 2)
    ds.Union(9, 6)
    ds.PrintSet()
    print("{} {} {} {}".format(ds.Find(6), ds.Find(3), ds.Find(11), ds.Find(9)))
