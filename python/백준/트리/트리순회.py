import sys
input = sys.stdin.readline

def preorder(node):
    print(node,end='')
    for val in tree[node]:
        if not val == '.':
            preorder(val)
            
def inorder(node):
    if node != '.':
        inorder(tree[node][0])
        print(node,end='')
        inorder(tree[node][1])
                
def postorder(node):    
    if node != '.':
        postorder(tree[node][0])
        postorder(tree[node][1])
        print(node,end='')
        

N = int(input())
visited = [False]*N
tree = {}
for i in range(N):
    root, left, right = input().split()
    tree[root] = [left, right]

preorder('A')
print()
inorder('A')
print()
postorder('A')
