#tree - 비선형 자료구조
# 계층을 갖는 계층형 자료구조
# 노드로 이루어진 자료구조
# 간선-노드를 연결하는 선
# 깊이-루트 노드로부터의 거리
# 높이-최대 깊이
# 레벨-같은 깊이의 노드들의 집합
# 차수-자식 노드의 수
# 루트 노드는 부모 노드가 없는 노드
# 단말 노드는 자식 노드가 없는 노드
# 노드의 수준은 루트 노드로부터의 거리
# 노드의 높이는 최대 수준
# 이진트리 - 자식 노드가 최대 2개인 트리  
# 이진탐색트리 - 이진트리의 일종으로 왼쪽 자식 노드는 부모 노드보다 작고 오른쪽 자식 노드는 부모 노드보다 크다.
# 이진힙 - 이진트리의 일종으로 부모 노드가 자식 노드보다 크거나 같다. 
#   - 최대힙, 최소힙 (최대힙은 부모 노드가 자식 노드보다 크거나 같고 최소힙은 부모 노드가 자식 노드보다 작거나 같다.) 
# 이진트리의 순회
#   - 중위순회, 전위순회, 후위순회
#   - 중위순회: 왼쪽 자식 노드, 부모 노드, 오른쪽 자식 노드
#   - 전위순회: 부모 노드, 왼쪽 자식 노드, 오른쪽 자식 노드
#   - 후위순회: 왼쪽 자식 노드, 오른쪽 자식 노드, 부모 노드
#루비로 이진트리 구현
class Node
  attr_accessor :value, :left, :right
  def initialize(value)
    @value = value
    @left = nil
    @right = nil
  end
end

class BinaryTree
  def initialize
    @root = nil
  end

  def insert(value)
    if @root.nil?
      @root = Node.new(value)
    else
      insert_node(@root, value)
    end
  end

  def insert_node(node, value)
    if value < node.value
      if node.left.nil?
        node.left = Node.new(value)
      else
        insert_node(node.left, value)
      end
    else
      if node.right.nil?
        node.right = Node.new(value)
      else
        insert_node(node.right, value)
      end
    end
  end

  def in_order_traversal(node = @root, &block)
    return if node.nil?

    in_order_traversal(node.left, &block)
    yield node.value
    in_order_traversal(node.right, &block)
  end

  def pre_order_traversal(node = @root, &block)
    return if node.nil?

    yield node.value
    pre_order_traversal(node.left, &block)
    pre_order_traversal(node.right, &block)
  end

  def post_order_traversal(node = @root, &block)
    return if node.nil?

    post_order_traversal(node.left, &block)
    post_order_traversal(node.right, &block)
    yield node.value
  end
end

# 이진트리 사용 예제
tree = BinaryTree.new
tree.insert(10)
tree.insert(5)
tree.insert(15)
tree.insert(3)
tree.insert(7)
tree.insert(12)
tree.insert(18)

puts "중위순회:"
tree.in_order_traversal { |value| print "#{value} " }
puts "\n전위순회:"
tree.pre_order_traversal { |value| print "#{value} " }
puts "\n후위순회:"
tree.post_order_traversal { |value| print "#{value} " }