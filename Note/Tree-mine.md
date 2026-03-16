## 寻找树的LCA

### 递归的思想

- 来了一个请求，root，p，q
  - 我是p或者q 或者为空吗？
    - **是那我返回**
    - 不是，我问问我的左节点、右节点
      - 如果左节点、右边节点均为空→返回空
      - 如果左节点、右节点均有→返回当前节点
      - 如果左节点，右节点有其中一个不为空→返回不为空

### 迭代的思想

#include<`unordered_set` >

#include<`unordered_map` >

---

- 来了一个q和p
- 首先将tree每个节点对应的父节点存在一个**字典**中
  - 采用queue的方式，每次root的父节点为nullptr
  - root先入queue
    - 读root，读左、右节点 作为key，root做为key，pop 最前面那个
    - 如果左节点不为空，push，如果右节点不为空，push
- 将q的父节点存在一个list
  - 迭代，如果q→father不为nullptr，则push到一个vector，q=→father
- p每次找一下上面的父节点，直到某个父节点出现在q的list中，退出，返回该节点
  - 使用set的find功能，如果找到了，则返回
  - 没找到则p=p→father

## 两数之和

一个列表中有很多数，我需要找出哪两个数字的和等于给定的数，并给出下标

---

假设给的是一个数组{1,2,3,4,5}

- 初始化一个容器，从0开始，到N-2
  - 这个数和后面的数相加，看看等不等，如果等于，将这i和j保存在现在的容器中，如果不等于继续往下找
- 返回vector

---

```bash
* @brief 变体 1: 返回所有不重复的数对 (值对)
* 输入数组可能包含重复元素，且需要处理重复结果。
* 
* 策略：先排序，使用双指针（虽然题目要求哈希表，但排序双指针处理重复更直观，
* 这里也提供哈希表版本）。
```

面对{1,2,2,2,3,4,5,6,7,7,7,8}

### 双指针

- 返回一个pair，首先给出一个left、一个right，分别占据两段。
- 先对传入的vector进行一个排序
- 只有left<right才执行
  - 如果left+right == target ，就这两个推进去
    - 如果left++，直到left变化，right --,直到right变化
  - 如果left+right<target，那就left++
  - 如果left+right>target，那就right--
- 返回pair

---

## Hash表的频率统计

- 接受一个vector的nums，定一个hash表，也就是一个dict
- 遍历这个数组
  - 如果这个数在dict中存在，则dict对应的nums对应的key++
  - 如果不存在，则设其为1
- 遍历哈希表（使用auto）(for(auto it = nums))
  - 打印这个数字，以及其对应的频率

