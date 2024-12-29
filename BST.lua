Node = {}
Node.__index = Node

function Node:new(value)
    local node = {
        value = value,
        left = nil,
        right = nil
    }
    setmetatable(node, Node)
    return node
end

BST = {}
BST.__index = BST

function BST:new()
    local bst = {
        root = nil
    }
    setmetatable(bst, BST)
    return bst
end
function BST:getNode(value)
    return self:_getNode(self.root, value)
end

function BST:_getNode(currentNode, value)
    if currentNode == nil then
        return nil
    end
    if value == currentNode.value then
        return currentNode
    elseif value < currentNode.value then
        return self:_getNode(currentNode.left, value)
    else
        return self:_getNode(currentNode.right, value)
    end
end

function BST:insert(value)
    local newNode = Node:new(value)
    if self.root == nil then
        self.root = newNode
    else
        self:_insertNode(self.root, newNode)
    end
end

function BST:_insertNode(currentNode, newNode)
    if newNode.value < currentNode.value then
        if currentNode.left == nil then
            currentNode.left = newNode
        else
            self:_insertNode(currentNode.left, newNode)
        end
    else
        if currentNode.right == nil then
            currentNode.right = newNode
        else
            self:_insertNode(currentNode.right, newNode)
        end
    end
end

function BST:search(value)
    return self:_searchNode(self.root, value)
end

function BST:_searchNode(currentNode, value)
    if currentNode == nil then
        return false
    end
    if value == currentNode.value then
        return true
    elseif value < currentNode.value then
        return self:_searchNode(currentNode.left, value)
    else
        return self:_searchNode(currentNode.right, value)
    end
end

local bst = BST:new()
bst:insert(10)
bst:insert(5)
bst:insert(15)
print(bst:search(10))
print(bst:search(7))