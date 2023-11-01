class MinStack:
    def __init__(self):
        self.arr = []

    def push(self, val: int) -> None:
        self.arr.append(val)

    def pop(self) -> None:
        self.arr.pop()

    def top(self) -> int:
        return self.arr[-1]

    def getMin(self) -> int:
        flag = False
        min = 0
        for i in range(len(self.arr)):
            if self.arr[i] < min and flag:
                min = self.arr[i]

            if not flag:
                min = self.arr[i]
                flag = True
        
        return min
    

stack = MinStack()
stack.arr = [9,4,5,6,2]
print(stack.top())
print(stack.arr)
print(stack.pop())
print(stack.getMin())
print(stack.arr)
print(stack.push(69))
print(stack.arr)