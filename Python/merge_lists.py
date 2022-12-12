"""
MergeSort LinkedList

@author: R.J. Both <r.j.both@uva.nl> and Vlad Niculae <v.niculae@uva.nl>

# TODO Add here you student name and number.

"""

from __future__ import annotations
from typing import Optional
from dataclasses import dataclass


@dataclass
class Node:
    weight: float
    link: Optional[Node] = None
    
    def __repr__(self):
        return str(self.weight);

def merge(a_list: ItemList, b_list: ItemList):
    """
    This function takes two linked lists, assumed sorted, and merges them
    in-place, without creating new Nodes, just by changing the links.
    """
    print("******")
    print(a_list)
    print(b_list)
    
    def insert_node_in_a(a_list, temp):
        
        if temp is None or a_list is None:
            return
        
        node = a_list.head
        prev = None
        if node is not None:
            while node is not None and temp.weight >= node.weight:
                prev = node
                node = node.link
        
        temp.link = node
        if node == a_list.head:
            a_list.head = temp
        if prev:
            prev.link = temp

    # Traverse through b_list
    # for each element in b_list
    # find its position in a_list and insert there
    if b_list is not None:
        prev = b_list.head
        node = b_list.head
        
    while node:
        prev = node
        node = node.link
        insert_node_in_a(a_list, prev)
        
    # print(a_list)
    return a_list
    
    
class ItemList:
    head: Optional[Node]

    def __init__(self):
        """Initialize an empty linked list for warehouse items."""

        self.head = None
        self._length = 0

    def __len__(self) -> int:
        return self._length

    def insert(self, val: int) -> ItemList:
        """Insert a new item with given weight, at the beginning of the list"""

        new_node = Node(weight=val, link=self.head)
        self.head = new_node
        self._length += 1
        return self

    def find_middle(self):
        total_length = len(self)
        midpoint = len(self) // 2
        first_half_length = midpoint
        second_half_length = total_length - first_half_length
        
        print(f"First half lenght = {first_half_length}")
        print(f"Second half lenght = {second_half_length}")
        
        print("middle node index: ", midpoint)
        node = self.head
        prev = self.head
        for i in range(midpoint):
            prev = node
            node = node.link
        
        print(f"prev = {prev}")
        print(f"mid node = {node}")
        self._length = first_half_length
        prev.link = None
        
        second_half = ItemList()
        second_half.head = node
        second_half._length = second_half_length
        
        return [self, second_half]
        
    def split_half(self) -> tuple[ItemList, ItemList]:
        """
        This function finds the middle two nodes of the current list (rounded
        downwards), sever the link between them, and create a new ItemList.
        """
        total_length = len(self)
        midpoint = len(self) // 2
        first_half_length = midpoint
        second_half_length = total_length - first_half_length
        
        print(f"First half lenght = {first_half_length}")
        print(f"Second half lenght = {second_half_length}")
        
        print("middle node index: ", midpoint)
        node = self.head
        prev = self.head
        for i in range(midpoint):
            prev = node
            node = node.link
        
        print(f"prev = {prev}")
        print(f"mid node = {node}")
        self._length = first_half_length
        prev.link = None
        
        second_half = ItemList()
        second_half.head = node
        second_half._length = second_half_length
        
        return (self, second_half)

    def __repr__(self):
        """This function prints the list in a nice way."""

        node = self.head
        out = "["
        while node is not None:
            out += str(node.weight)
            if node.link is not None:
                out += ", "
            node = node.link
        out += "]"
        return out

    def sort_merge(self) -> ItemList:
        """Implementation of merge sort"""

        if len(self) <= 1:
            return self

        a, b = self.split_half()
        print("Split halves", a, b)
        a = a.sort_merge()
        b = b.sort_merge()

        print("Sorted halves", a, b)

        return merge(a, b)


def main():
    warehouse = (
        ItemList()
        .insert(50)
        .insert(40)
        .insert(30)
        .insert(60)
        .insert(20)
        .insert(20)
        .insert(20)
        .insert(10)
        #.insert(4.20)
    )
    print("Input:", warehouse)
    #a, b = warehouse.find_middle()
   
    print("Sorted:", warehouse.sort_merge())
    #out = merge(ItemList().insert(10).insert(10), ItemList().insert(20).insert(20))
    #out = merge(ItemList().insert(20).insert(20), ItemList().insert(10).insert(10))
    #print("out = " , out)


if __name__ == "__main__":
    main()

