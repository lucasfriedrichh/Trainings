priority = {
    '^': 6,
    '*': 5,
    '/': 5,
    '+': 4,
    '-': 4,
    '>': 3,
    '<': 3,
    '=': 3,
    '#': 3,
    '.': 2, 
    '|': 1  
}

def is_operator(c):
    return c in priority

def is_operand(c):
    return c.isalpha() or c.isdigit()

def infix_to_postfix(expression):
    stack = []
    output = []
    for char in expression:
        if is_operand(char):
            output.append(char)
        elif char == '(':
            stack.append(char)
        elif char == ')':
            while stack and stack[-1] != '(':
                output.append(stack.pop())
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                return "Syntax Error!" 
        elif is_operator(char):
            while stack and stack[-1] != '(' and priority[stack[-1]] >= priority[char]:
                output.append(stack.pop())
            stack.append(char)
        else:
            return "Lexical Error!" 

    while stack:
        top = stack.pop()
        if top == '(':
            return "Syntax Error!" 
        output.append(top)

    return ''.join(output)

def process_expression(expression):
    expression = expression.replace(" ", "") 

   
    last_char = ""
    open_parentheses = 0
    for i, char in enumerate(expression):
        if char not in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789()^*/+-><=#.|":
            return "Lexical Error!"
        
        if char == '(':
            open_parentheses += 1
        elif char == ')':
            open_parentheses -= 1
            if open_parentheses < 0:
                return "Syntax Error!" 
        
        if i > 0:
            if is_operator(char) and is_operator(last_char):
                return "Syntax Error!" 
            if is_operand(char) and is_operand(last_char):
                return "Syntax Error!" 

        last_char = char
    
    if open_parentheses != 0:
        return "Syntax Error!" 

   
    return infix_to_postfix(expression)

# Leitura da entrada até EOF
import sys
for line in sys.stdin:
    line = line.strip()
    if line:
        print(process_expression(line))
