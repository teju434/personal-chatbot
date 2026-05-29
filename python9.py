class listnode:
    def __init__(self, value):
        self.val = value
        self.next = None
class linkedlist:
    def __init__(self):
        self.head = None
    def insert_at_beginning(self, x):
        newNode = listnode(x)
        newNode.next = self.head
        self.head = newNode
    def append(self, x):
        newNode = listnode(x)
        if self.head is None:
            self.head = newNode
            return
        temp = self.head
        while temp.next is not None:
            temp = temp.next
        temp.next = newNode
    def insert(self, index, x):
        if index == 0:
            self.insert_at_beginning(x)
             return
        newNode = listnode(x)
        temp = self.head
        count = 0
        while temp is not None and count < index - 1:
            temp = temp.next
            count += 1

        if temp is None:
            print("List index out of range")
            return

        newNode.next = temp.next
        temp.next = newNode

    def display(self):
        temp = self.head
        while temp is not None:
            end = " -> " if temp.next else ""
            print(temp.val, end=end)
            temp = temp.next
        print()

    def length(self):
        count = 0
        temp = self.head
        while temp is not None:
            count += 1
            temp = temp.next
        return count

    def reverse(self):
        prev = None
        curr = self.head
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        self.head = prev

    def has_cycle(self):
        slow = self.head
        fast = self.head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False
    def delete_value(self, x):
        curr=self.head
        

List = linkedlist()
List.append(10)
List.append(20)
List.append(30)
List.append(40)
List.append(50)

print("After append:")
List.display()

print("Insert at beginning (5):")
List.insert_at_beginning(5)
List.display()

print("Insert 60 at index 3:")
List.insert(3, 60)
List.display()

print("Length of list:", List.length())

print("Reversing list...")
List.reverse()
List.display()
k = 2
List.delete_value(k)
print("After deleting", k, ":")
List.display()

print("Cycle present?", List.has_cycle())
print("Creating a cycle for testing...")
temp = List.head
while temp.next:
    temp = temp.next
temp.next = List.head.next  

print("Cycle present after creating loop?", List.has_cycle())
