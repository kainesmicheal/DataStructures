class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BST(object):
    def __init__(self, root):
        self.root = Node(root)

    def insert(self, new_val):
        self.insertTool(self.root, new_val)
        return 


    def insertTool(self, start, new_val):
        if start:
            if(new_val < start.value and start.left == None):
                start.left = Node(new_val)
            elif(new_val > start.value and start.right == None):
                start.right = Node(new_val)
            else:
                if(start.value < new_val):
                    return self.insetTool(start.right,new_val)
                else:
                    return self.insertTool(start.left,new_val)
        return 

    def search(self, find_val):
        if(self.searchTool(self.root,find_val)):
            return True
        return False

    def searchTool(self,start,find_val):
        if start:
            if(start.value == find_val):
                return True
            else:
                if(find_val > start.value):
                    return self.searchTool(start.right,find_val)
                else:
                    return self.searchTool(start.left,find_val)
        return False
    
# Set up tree
tree = BST(4)

# Insert elements
tree.insert(2)
tree.insert(1)
tree.insert(3)
tree.insert(5)

# Check search
# Should be True
print (tree.search(4))
# Should be False
print (tree.search(6))
