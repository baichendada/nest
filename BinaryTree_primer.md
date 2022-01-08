<font size=5😀大家好，我是**白晨**，一个不是很能熬夜😫，但是也想日更的人✈。</font>如果喜欢这篇文章，**点个赞**👍，**关注一下**👀白晨吧！你的支持就是我最大的动力！💪💪💪

![自我介绍1](C:\Users\李若尘\Desktop\素材\栈与队列\自我介绍1.gif)



[TOC]

---

# 🍇前言

---

上一篇文章，我们讲述了[栈和队列](https://blog.csdn.net/baichendada/article/details/122279166?spm=1001.2014.3001.5501)这两种结构。回首[以前的文章](https://blog.csdn.net/baichendada/category_11556944.html?spm=1001.2014.3001.5482)，我们都在关注线性存储结构，本篇文章我们就来开始讲解**非线性结构**，也就是**一个结点与多个结点相对应（俗称“一对多”）的结构**。本篇文章我们要讲述的主角，即使你没有了解过它，但你应该也听说过它，它就是`二叉树`。

准备好了吗？我们开始吧！🚀

---

# 1.树

---

## 1.1 树的基本概念

---

> `树`(tree)是由n（n>=0）个**有限结点**组成一个**具有层次关系**的集合，记为T。
>
> - 当n=0时，它是一棵空树。
> - 当n>0时，有一个特殊的结点，称为**根结点**，根结点没有前驱结点。
> - 除根结点外，**其余结点**被分成M(M>0)个**互不相交**的集合T1、T2、……、Tm，其中每一个集合Ti(1<= i  <= m)又是一棵结构与树类似的子树。*每棵子树的根结点有且只有一个前驱结点，可以有0个或多个后继结点*。
> - 因为此种存储形状在逻辑结构上看，类似于实际生活中倒着的树，所以被称为“树”。
>
> ![image-20220106211154017](C:\Users\李若尘\Desktop\素材\二叉树\树1.png)
>
> - 可以看到，`A`前没有任何结点，所以`A`就是根结点。
>
> - `A`对应着`B,C,D`三个结点，所以树可以是“一对多”的结构，就是非线性结构。
>
> - 我们可以看出，`A`树集合包含了`B,C,D`树的集合，并且`B`树又包含了`E`树集合。这就说明了一棵树可以分为若干个子树。
>
> - 我们在这里先下一个定义，后文会具体解释：`树是由根结点和若干棵子树构成的`。
>
> - **特别注意**：树的结点都是不相交的，如果有相交的结点，那么一定不是树。见下图：
>
>   ![image-20220106212955276](C:\Users\李若尘\Desktop\素材\二叉树\非树.png)

---

## 1.2 树的基本术语

---

![image-20220106221842468](C:\Users\李若尘\Desktop\素材\二叉树\树的概念.png)


- 子树：整棵树的根结点为`A`，而如果单看结点` C,F,I,K,L`组成的部分来说，也是棵树，而且`C`为这棵树的根结点。所以称` C,F,I,K,L`这几个结点组成的树为整棵树的子树；同样，结点`F,I,K,L`构成的也是一棵子树，根结点为`F`。并且，**单结点也是一棵树**，只不过树上只有一个结点，也为构成整棵树的子树。例如，`H,I,J,K,L,M,N`都为一棵树，也为根为`A`结点的这棵树的子树。

  所以说：**树是由根结点和若干棵子树构成的**。

- 空树：没有结点的树，空树特征就是集合T为空。

- 结点的度：一个结点含有的子树的个数称为该结点的度； 例如，`A`的度为3，`B`的度为1。

- 叶子结点或终端结点：度为0的结点称为叶结点；例如，此树中`H,I,K,L,M,N`都为叶子结点。

- 非终端结点或分支结点：度不为0的结点； 例如，此树中`A,B,C,D,E,F,G`为非终端结点。

- 双亲结点或父结点：若一个结点含有子结点，则这个结点称为其子结点的父结点； 例如，`A`为`B,C,D`的双亲/父结点

- 孩子结点或子结点：一个结点含有的子树的根结点称为该结点的子结点；例如，`B,C,D`为`A`的子结点。

- 兄弟结点：具有相同父结点的结点互称为兄弟结点； 例如，`B,C,D`为兄弟结点。

- 树的度：一棵树中，最大的结点的度称为树的度； 此树中，`A,F`的度是3，其余结点的度都小于3，所以此树的度就为3。

- 结点的层次：从根开始定义起，根为第1层，根的子结点为第2层，以此类推； 此树旁的箭头上的数字就代表该层结点的层次

- 树的高度或深度：树中结点的最大层次； 此树结点的层次都小于等于4，所以此树的高度/深度就为4。

- 堂兄弟结点：双亲在同一层的结点互为堂兄弟；例如，`E,F,G`为堂兄弟结点

- 结点的祖先：从根到该结点所经分支上的所有结点；例如，`A`为其余结点的祖先，`H`的祖先为`A,B,E`。

- 子孙：以某结点为根的子树中任一结点都称为该结点的子孙。例如：`A`的子孙就是除`A`以外的其余结点。

- 森林：由m（m>0）棵互不相交的树的集合称为森林；例如，下图的两个树就被称为森林。

  ![image-20220106224523202](C:\Users\李若尘\Desktop\素材\二叉树\森林.png)

---
## 1.3 树的逻辑表示

---

1. 树形表示法

   > 用一个圆圈表示一个结点，圆圈内的符号代表该结点的数据信息，结点之间的关系用连线表示。
   >
   > ![a](C:\Users\李若尘\Desktop\素材\二叉树\树形表示法.png)

2. 文氏图表示法

   > 每棵树对应一个圆圈，圆圈内包含根结点和子树的圆圈，同一个结点下的各子树对应的圆圈不能相交。
   >
   > ![image-20220106214642416](C:\Users\李若尘\Desktop\素材\二叉树\文氏图表示法.png)

3. 凹入表示法

   > 每棵树的根对应一个条形，子树的根对应一个较短的条形，同一个根下的各子树的条形长度相同。
   >
   > ![image-20220106214943818](C:\Users\李若尘\Desktop\素材\二叉树\凹入表示法.png)

4. 括号表示法

   > 每棵树对应一个由根作为名字的表，表名放在表的左边，表由一个括号里的各子树对应的表组成，表之间用逗号分隔。
   >
   > ![image-20220106215903185](C:\Users\李若尘\Desktop\素材\二叉树\括号表示法.png)
   >
   > 

此处的逻辑表示方法可以只做一了解，唯一需要掌握并且用的最多的就是树形表示法。

---

## 1.4 树的表示

---

从上文中，我们已经知道了树的各种逻辑表示，那么我们怎么用代码实现这种结构呢？

树的结构既要存储结点的数据元素，又要存储结点之间的逻辑关系，下面就介绍三种常见的表示方法[^1]。

1. 双亲表示法

   > 双亲存储结构是一种顺序表的结构，用一组连续的空间存储树的所有结点，每个结点存有数据和双亲结点的位置(下标)。存储过程是顺序存储各个结点的同时，给各结点附加一个记录其父结点位置的变量。
   >
   > ```c
   > #define MAX_SIZE 100
   > typedef int TreeDataType;
   > // 双亲表示法
   > // 树结点结构定义
   > typedef struct TreeNode
   > {
   > 	TreeDataType data;
   > 	int parent;// 一棵树的根结点没有双亲结点，所以一般将其parent置为-1。
   > }BTNode;
   > 
   > // 树结构定义
   > typedef struct Tree
   > {
   >  // 存储全部结点的结构体指针
   > 	BTNode tree[MAX_SIZE];
   > }Tree;
   > ```
   >
   > ![a](C:\Users\李若尘\Desktop\素材\二叉树\树形表示法.png)
   >
   > 双亲表示法为：
   >
   > | 数组下标 | 0    | 1    | 2    | 3    | 4    | 5    | 6    |
   > | -------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
   > | data     | A    | B    | C    | D    | E    | F    | G    |
   > | parent   | -1   | 0    | 0    | 1    | 1    | 2    | 2    |
   >
   > 可以发现，这个结构是一个结构体数组，也就是顺序表。
   >
   > 这样表示有很大的缺陷：
   >
   > 1. 必须限定数组大小，不能动态调整，容易出现空间浪费或者空间不够的情况。
   > 2. 这种结构找双亲结点很容易，但是找一个结点的子结点却需要遍历整个数组

2. 孩子表示法

   > 孩子表示法存储普通树采用的是 "顺序表+链表" 的组合结构，每个结点包含指向所有孩子[^2]的指针。其存储过程是：从树的根结点开始，使用顺序表依次存储树中各个结点，需要注意的是，与双亲表示法不同，孩子表示法会给各个结点配备一个链表，用于存储各结点的孩子结点位于顺序表中的位置。
   >
   > ```c
   > 1. > #define MAX_SIZE 100
   >    > typedef int TreeDataType;
   >    > // 孩子表示法
   >    > // 树结点结构定义
   >    > typedef struct TreeSonNode
   >    > {
   >    > 	TreeDataType data;
   >    > 	// 所有子结点的指针数组
   >    > 	struct TreeSonNode* son[MAX_SIZE];
   >    > }TreeNode;
   >    >
   >    > // 树结构定义
   >    > typedef struct SonTree
   >    > {
   >    > 	// 存储全部结点的结构体数组
   >    > 	TreeNode tree[MAX_SIZE];
   >    > }Tree;
   > 
   > ```
   >
   > ![a](C:\Users\李若尘\Desktop\素材\二叉树\树形表示法.png)
   >
   > 孩子表示法为：
   >
   > | 数组下标                      | 0    | 1    | 2    | 3    | 4    | 5    | 6    |
   > | ----------------------------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
   > | data                          | A    | B    | C    | D    | E    | F    | G    |
   > | son(此处代表指向该结点的指针) | B,C  | D,E  | F,G  | NULL | NULL | NULL | NULL |
   >
   > 这样表示也有很大的缺陷：
   >
   > 1. 这里的一个结点里就包含了一个容量为最大结点的度的指针数组，可能有空间浪费。
   > 2. 这种结构找子结点很容易，但是找一个结点的双亲结点却需要从根开始查找。

3. 孩子兄弟表示法
   
   > 孩子兄弟存储结构是一种链式存储结构，每个结点除了存储数据，还要包含该结点的第一个孩子的指针和该结点指向(右边)兄弟的指针。
   >
   > ```c
   > typedef int TreeDataType;
   > // 孩子兄弟表示法
   > // 树结点结构定义
   > typedef struct TreeNode
   > {
   > 	// 第一个孩子结点
   > 	struct Node* firstChild; 
   > 	// 指向其下一个兄弟结点
   > 	struct Node* NextBrother; 
   > 	// 结点中的数据域
   > 	TreeDataType data; 
   > }TreeNode;
   > ```
   >
   > 这是最优的表示方法，我们可以结合图像来理解。
   >
   > ![image-20220106235948386](C:\Users\李若尘\Desktop\素材\二叉树\孩子兄弟表示法.png)
   > 这种方法可以解决上述的大部分问题，但是有一个问题还是很麻烦，这种结构找兄弟结点很容易，但是找一个结点的双亲结点却需要从根开始查找

[^1]: 这里的表示方式重点就是结点的定义方式，树的结构其实大同小异。
[^2]: 注意是孩子，而不是子孙。

---

---

# 2.二叉树

---

## 2.1 二叉树的基本概念

---

> 二叉树(binary tree)是另一种树形结构，它的`每个结点的度至多为2`(也即每个结点最多有两颗子树)，并且二叉树的子树有`左子树与右子树`之分，其`次序不能颠倒`。
>
> ![image-20220107112452043](C:\Users\李若尘\Desktop\素材\二叉树\二叉树2.png)
>
> 上图就是一棵二叉树，`A`的左子树为以`B`为根的树，右子树为以`C`为根的树。
>
> ![树1](C:\Users\李若尘\Desktop\素材\二叉树\树1.png)
>
> 上图树的度为3，所以此树不为二叉树。
>
> ![image-20220107112754148](C:\Users\李若尘\Desktop\素材\二叉树\相同二叉树1.png)
>
> 上图中的二叉树，不是相同的二叉树，因为二叉树的左右次序不能颠倒。
>
> ![image-20220107112957954](C:\Users\李若尘\Desktop\素材\二叉树\相同二叉树2.png)
>
> 同理，上图也不是相同的二叉树。
>
> ![image-20220107113520899](C:\Users\李若尘\Desktop\素材\二叉树\二叉树基本组成.png)
>
> - 任意二叉树都可以由以上情况复合而成。

---

## 2.2 二叉树的性质

---

1. 若规定根结点的层数为1，则一棵非空二叉树的第`i`层上最多有$2^{i-1}$个结点。

2. 若规定根结点的层数为1，则深度为`h`的二叉树的最大结点数是$2^h-1$。

3. 若规定根结点的层数为1，具有`N`个结点的二叉树的深度，深度`h`的取值为$[log_2~(N+1),N]$。 

   > 具体图解如下：
   >
   > ![image-20220107134818231](C:\Users\李若尘\Desktop\素材\二叉树\二叉树性质3.png)
   >
   >点击跳转到[完全二叉树](#complete)

4. 对任何一棵二叉树, 如果度为0其叶结点个数(叶子结点)为$n_0$, 度为2的分支结点个数为$n_2$,则有$n_0 = n_2 + 1$。

   > 对于一棵树来说，总结点数 = 度为0的结点数 + 度为1的结点数 + 度为2的结点数。所以$N = n_0 + n_1 +n_2$;
   >
   > 再有，除根结点外，对于每一个结点来说都是由其父结点分支表示的，所以设分支为B，N = B + 1;
   >
   > 且分支数可由度来表示B = $n_1+2*n_2$;
   >
   > 综上，可推得$n_0 = n_2 + 1$。



---

## 2.3 特殊二叉树

---

### 2.3.1 满二叉树

---

> 一棵二叉树中除了叶子结点，每个结点的度都为 2，则此二叉树称为**满二叉树**。
>
> ![image-20220107130107904](C:\Users\李若尘\Desktop\素材\二叉树\满二叉树2.png)
>
> 由上图可知，满二叉树除了满足普通二叉树的性质，还具有以下性质：
>
> 1. 满二叉树中第` i `层的结点数为$2^{i-1}$个。
> 2. 深度为 `h` 的满二叉树必有  个结点$2^h-1$ ，叶子数为$2^{h-1}$ 。
> 3. 满二叉树中不存在度为 1 的结点，每一个分支点中都两棵深度相同的子树，且叶子结点都在最底层。
> 4. 具有 `N`个结点的满二叉树的深度为 $log_2~(N+1)$。



---

### 2.3.2 完全二叉树

---

> 一棵二叉树中**最后一层结点以上结点构成满二叉树**，且**最后一层的结点依次从左到右分布**，则此二叉树被称为**完全二叉树**。
>
> ![image-20220107132702223](C:\Users\李若尘\Desktop\素材\二叉树\完全二叉树.png)
>
> 上图中，第四层以上的前三层构成满二叉树结构，最后一层从左到右结点连续，所以上树为一棵完全二叉树。
>
> 完全二叉树有如下特性：<span id="complete"></span>
>
> 1. 若规定根结点的层数为1，具有`N`个结点的完全二叉树的深度，h=$[log_2~N]+1$][^3]。 
>
>    ![image-20220107131706625](C:\Users\李若尘\Desktop\素材\二叉树\二叉树性质.png)
>
> <span id="jump"></span>
>
> 2.对于具有`n`个结点的完全二叉树，如果按照从上至下从左至右的数组顺序对所有结点从0开始编号，则对于序号为`i`的结点有： 
>
> 1. 若`i`>0，`i`位置结点的双亲序号：(`i`-1)/2；`i`=0，`i`为根结点编号，无双亲结点
> 2. `i`位置结点的孩子序号：
>    - 左孩子：2*`i`+1；
>    - 右孩子：2*`i`+2；
> 3. 若2`i`+1=n，则无左孩子 
> 4. 若2`i`+2=n，则无右孩子


[^3]:  []为向下取整。

---

---

## 2.4 二叉树的存储结构

---

二叉树的存储一般分为两种——`顺序存储`和`链式存储`。

### 2.4.1 二叉树的顺序存储

---

> 二叉树的顺序存储结构是用一组连续的空间(一般为数组)来存放二叉树的数据元素，其存放顺序是按照结点在空间中存放的先后顺序依次存放。树中每个结点的编号与同深度的完全二叉树对应结点的编号相同。**此结构一般被用来存储完全二叉树**。
>
> ![image-20220107202313927](C:\Users\李若尘\Desktop\素材\二叉树\线性表示.png)
>
>上树对应的顺序存储为：
>
> | 数组下标 | 0    | 1    | 2    | 3    | 4    | 5    | 6    |
> | -------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
> | data     | A    | B    | C    |      |      | F    | G    |
>
> 可见，如果不是完全二叉树就会造成空间浪费，值得注意的是，`3,4`两个位置对应`B`的子结点，在数组中必须空下来以保证其余结点的顺序以及[节点编号的查找](#jump)。

---

### 2.4.2 二叉树的链式结构

---

> 二叉树的链式存储结构是指，用链表来表示一棵二叉树，即用链来指示元素的逻辑关系。 通常的方法是链表中每个结点由三个域组成，**数据域**和**左右指针域**，左右指针分别用来给出该结点左孩子和右孩子所在的链结点的存储地址 。链式结构又分为`二叉链`和`三叉链`，当前我们学习中一般都是二叉链，后面高阶数据结构如红黑树等会用到三叉链。
>
> ![image-20220107204023510](C:\Users\李若尘\Desktop\素材\二叉树\二叉树链式结构2.png)
>
> ![image-20220107203900230](C:\Users\李若尘\Desktop\素材\二叉树\二叉树链式结构.png)
>
> ```c
> typedef int BTDataType;
> // 二叉链
> struct BinaryTreeNode
> {
>     // 指向当前结点左孩子
>  	struct BinTreeNode* Left; 
>     // 指向当前结点右孩子
>  	struct BinTreeNode* Right; 
>     // 当前结点值域
>  	BTDataType data; 
> };
> // 三叉链
> struct BinaryTreeNode
> {
>     // 指向当前结点的双亲
>  	struct BinTreeNode* Parent; 
>     // 指向当前结点左孩子
> 	struct BinTreeNode* Left; 
>     // 指向当前结点右孩子
>  	struct BinTreeNode* Right; 
>     // 当前结点值域
>  	BTDataType data; 
> };
> ```

---

---

## 2.5 二叉树的遍历

---

> 二叉树的遍历是指按照一定的顺序访问二叉树中的所有结点，并且每个结点仅被访问一次的过程。遍历对于线性结构是一个很容易解决的问题，对于二叉树则必须设计特殊算法来遍历所有结点。
>
> 对于后续二叉链树，我们都使用如下结构：
>
> ```c
> typedef char BTDataType;
> 
> typedef struct BinaryTreeNode
> {
> 	BTDataType data;
> 	struct BinaryTreeNode* left;
> 	struct BinaryTreeNode* right;
> }BTNode;
> ```
>
> 由二叉树定义可知，二叉树由三个基本单元组成：根结点、左子树和右子树。因此只要遍历这三个部分就可以遍历所有结点。假设以`L,D,R`分别表示遍历**左子树，访问根结点，遍历右子树**。根据排列组合，有六种遍历的方式，如果我们再限定先左后右，就有只有三种遍历方式，分别称为**先(前)序遍历，中序遍历，后续遍历**。基于二叉树的递归定义，我们可以得到以下3种遍历二叉树的递归算法。
>
> 我们以下图的树为例子：
>
> ![image-20220107212002319](C:\Users\李若尘\Desktop\素材\二叉树\遍历二叉树2.png)

### 2.5.1 先序遍历

---

> 先序遍历，又叫前序遍历，遍历顺序是`DLR`。
> 具体操作为：若二叉树为空，则返回；否则
>
> 1. 访问根结点。
> 2. 先序遍历左子树。
> 3. 先序遍历右子树。
>
> ![image-20220107212029965](C:\Users\李若尘\Desktop\素材\二叉树\前序遍历1.png)
>
> 上树具体先序遍历过程：
>
> 1. 访问该二叉树的根结点，找到 `A`；
> 2. 访问结点 `A` 的左子树，找到结点 `B`；
> 3. 访问结点 `B` 的左子树，找到结点 `D`；
> 4. 由于结点 `D` 左子树为空，且右子树也为空，因此以结点 `D` 为根结点的子树遍历完成。但结点 `B` 还没有遍历其右子树，因此现在开始遍历，即访问结点 `E`；
> 5. 由于结点 `E` 左右子树都为空，因此结点 `E` 遍历完成，并且由此以结点 `B` 为根结点的子树也遍历完成。现在回到结点 `A` ，并开始遍历该结点的右子树，即访问结点 `C`；
> 6. 访问结点 `C` 左子树，找到结点 `F`；
> 7. 由于结点 `F` 左右子树都为空，因此结点 `F` 遍历完成，回到结点 `C` 并遍历其右子树，`C` 右子树为空，返回 `C`；
> 8. 结点 `C` 为根结点的子树遍历完成，同时回归结点 `A`。由于结点 `A` 的左右子树全部遍历完成，因此整个二叉树遍历完成；
>
> 所以先序遍历得到的序列为：`A,B,D,E,C,F`。

现在我们来用代码实现先序遍历的逻辑：

```c
void PreOrder(BTNode* root)
{
    // 遇到空树就返回
	if (root == NULL)
	{
		return;
	}

	printf("%c ", root->data);// 这里我们用打印来代表对根结点进行访问
	PreOrder(root->left);// 对左子树进行先序遍历
	PreOrder(root->right);// 对右子树进行先序遍历
}
```



---

### 2.5.2 中序遍历

---

> 中序遍历的顺序为`LDR`。
>
> 具体操作为：若二叉树为空，则返回；否则
>
> 1. 中序遍历左子树。
> 2. 访问根结点。
> 3. 中序遍历右子树。
>
> ![image-20220107213544141](C:\Users\李若尘\Desktop\素材\二叉树\中序遍历.png)
>
> 上树具体中序遍历过程为：
>
> 1. 通过该二叉树的根结点，找到 `A`；
> 2. 遍历结点 `A` 的左子树，找到结点 `B`；
> 3. 遍历结点 `B` 的左子树，找到结点 `D`；
> 4. 由于结点 `D` 无左孩子，因此找到结点 `D`，并遍历结点 `D` 的右子树；
> 5. 由于结点 `D` 无右子树，因此结点 `B` 的左子树遍历完成，访问结点 `B`;
> 6. 遍历结点 `B` 的右子树，找到结点 `E`;
> 7. 由于结点 `E` 无左子树，因此访问结点 `E` ，又因为结点 `E` 没有右子树，因此结点 `A` 的左子树遍历完成，访问结点 `A` ，并遍历结点 `A` 的右子树，找到结点 `C`;
> 8. 遍历结点 `C` 的左子树，找到结点 `F`;
> 9. 由于结点 `F` 无左子树，因此访问结点 `F`，又因为该结点无右子树，因此结点 `C` 的左子树遍历完成，开始访问结点 `C` ，并遍历结点 `C` 的右子树，由于 `C` 无右子树，返回 `A` ;
> 10. 因此结点 `A` 的右子树遍历完成，即整棵树遍历完成；
>
> 所以中序遍历得到的序列为：`D,E,B,A,F,C`。

代码实现中序遍历的逻辑：

```c
void InOrder(BTNode* root)
{
	// 遇到空树就返回
	if (root == NULL)
	{
		return;
	}

	InOrder(root->left);// 对左子树进行中序遍历
	printf("%c ", root->data);// 对根结点进行访问
	InOrder(root->right);// 对右子树进行中序遍历
}
```



---

### 2.5.3 后序遍历

---

> 后续遍历的顺序为`LDR`。
>
> 具体操作为：若二叉树为空，则返回；否则
>
> 1. 后序遍历左子树。
> 2. 后序遍历右子树。
> 3. 访问根结点。
>
> ![image-20220107214843438](C:\Users\李若尘\Desktop\素材\二叉树\后序遍历.png)
>
> 上树具体后续遍历过程为：
>
> 1. 从根结点 `A` 开始，遍历该结点的左子树（以结点 `B` 为根结点）;
> 2. 遍历结点 `B` 的左子树（以结点 `D` 为根结点）;
> 3. 由于结点 `D` 既没有左子树，也没有右子树，此时访问该结点中的元素 `D`，并回退到结点 `B` ，遍历结点 `B` 的右子树（以 `E` 为根结点）;
> 4. 由于结点 `E` 无左右子树，因此可以访问结点 `E` ，并且此时结点 `B` 的左右子树也遍历完成，因此也可以访问结点 `B`；
> 5. 此时回退到结点 `A` ，开始遍历结点 `A` 的右子树（以结点 `C` 为根结点）;
> 6. 遍历结点 `C` 的左子树（以结点 `F` 为根结点）;
> 7. 由于结点 `F` 无左右子树，因此访问结点 `F`，并回退到结点 `C`，开始遍历结点 `C` 的右子树（NULL）,所以返回`C`;
> 8. 结点 `C` 的左右子树也遍历完成，可以访问结点 `C`；结点 `A` 的左右子树也遍历完成，可以访问结点 `A`；
> 9. `A` 结点结束，整棵树的遍历结束。
>
> 所以后序遍历得到的序列为：`D,E,B,F,C,A`。

代码实现后序遍历逻辑：

```c
void PostOrder(BTNode* root)
{
	// 遇到空树就返回
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);//  对左子树进行后序访问
	PostOrder(root->right);// 对右子树进行后序访问
	printf("%c ", root->data);// 对根结点进行访问
}
```



---

### 2.5.4 层序遍历

---

> 除了上述三种遍历方式，还有一种很多人都能想到，但是相较于以上三种比较难实现的遍历方式——层序遍历。
>
> 层序遍历，顾名思义，就是从上到下，从左到右，一层层遍历所有结点。
>
> 具体操作为：假定二叉树深度为` k`，若二叉树为空，则返回；否则
>
> 1. 访问第一层的根结点。
> 2. 从左到右访问第二层结点。
> 3. 从左到右访问第三层所有结点，依次类推，直到完第`K`层所有结点。
>
> 这种遍历方式比较符合大众的思想，所以遍历过程也比较简单。
>
> ![image-20220108133153017](C:\Users\李若尘\Desktop\素材\二叉树\层序遍历.png)
>
> 层序遍历上树得到的序列是：`A,B,C,D,E,F`。

层序遍历虽然在思想上很好理解，但是代码实现却要比以上三个逻辑难。

在进行层序遍历时，对某一层结点访问完成后，再按照他们的访问次序对各个结点的左、右孩子进行顺序访问，这样的操作就需要在访问一个结点时，将此结点的左、右孩子记录下来，依次将某一层的结点孩子记录下来，然后访问完这一层后，就去访问这一层第一个结点的左孩子，再对左孩子所在的这一层进行顺序访问。以上操作符合“**先进先出，后进后出**”的特点，所以我们需要使用到上篇文章讲述的数据结构——[队列](https://blog.csdn.net/baichendada/article/details/122279166?spm=1001.2014.3001.5501)。

层序遍历代码层面的过程是：

1. 先将根结点进队。
2. 队列不为空时，循环**步骤2到步骤4**，直到队列为空。
3. 从队列中出队一个结点，进行访问。
4. 如果该结点左孩子不为空，将左孩子进队；如果该结点右孩子不为空，将右孩子进队。

![image-20220108140122752](C:\Users\李若尘\Desktop\素材\二叉树\层序具体.png)

代码实现层序遍历逻辑如下(可以将代码和上图结合理解)：

```c
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	// 利用队列先进先出的特点，可以实现层序遍历，先将root入队
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		// 如果此结点的孩子不为空，才可入队
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", tmp->data);

		if (tmp->left)
			QueuePush(&q, tmp->left);
		if (tmp->right)
			QueuePush(&q, tmp->right);
	}

	printf("\n");
	QueueDestroy(&q);
}
```



---

---



## 2.6 二叉树常用接口函数

---

### 2.6.1 二叉树总结点个数

---

> 使用分治的思想，将求二叉树总结点个数转化为：
>
> 1. 判断根是否为空结点，如果为否，执行以下三步
> 2. 求左子树总结点个数
> 3. 求右子树总结点个数
> 4. 将左、右子树结点个数和根(1)相加得到总结点

利用以上思想，代码实现为：

```c
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : 1 + BinaryTreeSize(root->left)
		+ BinaryTreeSize(root->right);
}
```

上述思想其实是先序遍历思想的变式：

- 访问根结点，先判断根结点是否为空，为空返回0，不为空执行以下操作。
- 先序遍历左子树，返回左子树结点个数。
- 先序遍历右子树，返回右子树结点个数
- 遍历结束，返回该树总结点个数

动态遍历过程如下：

![总结点计算1](C:\Users\李若尘\Desktop\素材\二叉树\总结点计算1.gif)

---



### 2.6.2 二叉树叶子结点个数

---

> 使用分治的思想，将求一棵树的叶子结点转化成
>
> 1. 判断根是否为叶子结点，如果为否，执行以下两步
> 2. 求左子树叶子结点的个数
> 3. 求右子树叶子结点的个数

利用以上的思想可以将一棵树，无限细分，直到**分到叶子结点或者NULL**。

如何判断一个结点是否为叶子结点呢？
根据定义，叶子结点的度为0，就是左孩子和右孩子都为NULL。

具体代码实现如下：

```c
int BinaryTreeLeafSizeCBTNode(BTNode* root)
{
    // 判断root是否为空，如果为空直接返回0
	if (root == NULL)
	{
		return 0;
	}
	// 判断root是否为叶子结点，如果是，返回1
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	// 返回左子树叶子结点数量和右结点叶子结点数量之和
	return BinaryTreeLeafSizeCBTNode(root->left) + BinaryTreeLeafSizeCBTNode(root->right);
}
```

上述过程其实也可以视为一次先序遍历的变形：

- 先访问根结点，判断根结点是否为空和是否为叶子结点。
- 其次先序遍历左子树，确定左子树叶子结点的数量。
- 接着先序遍历右子树，确定右子树叶子结点的数量。
- 最后返回左、右子树叶子结点的数量和。

详细遍历过程见下图：

![叶子结点的计算1](C:\Users\李若尘\Desktop\素材\二叉树\叶子结点的计算1.gif)

---

### 2.6.3 二叉树第层结点个数

---

> 要求二叉树第`k`层的结点个数，依旧可以使用分治的思想：
>
> 1. 判断根结点是否为第`k`层的结点，如果为否，执行以下两步
> 2. 计算左子树第`k-1`层结点的个数
> 3. 计算左子树第`k-1`层结点的个数

依照以上思想，可以将一棵树分为第`1`层的结点和NULL。

如何判断这就是第`k`层的结点呢？
利用递归的思想，在一棵树中第`k`层的结点的，就是左子树的`k-1`层结点，就是左子树的左子树的`k-2`层结点，以此类推，到一棵树中的第`k`层结点时，就是该结点的第`1`层结点。

利用这个思想，我们可以完成代码实现：

```c
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k >= 1);
	
    // 当root为NULL时，返回0
	if (root == NULL)
	{
		return 0;
	}
	// 当k=1时，这是就是该树的第k层，返回1
	if (k == 1)
	{
		return 1;
	}
	// 返回左子树和右子树第k-1层结点的数量和
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
```

上述思想也是先序遍历思想的变形。

详细实现图解见下：

![第k层的计算](C:\Users\李若尘\Desktop\素材\二叉树\第k层的计算.gif)

---

### 2.6.4 二叉树的高度/深度

---

> 求二叉树的高度/深度，根据定义，就是求树中结点的最大层次，利用分治的思想，转化这个问题为：
>
> 1. 判断根结点是否为空
> 2. 求出左子树的高度
> 3. 求出右子树的高度
> 4. 比较左右子树的高度，选择较高的子树的高度
> 5. 返回整棵树的高度

这个思想比之之前的思想，多出了判断的过程，要保留高子树的高度，但是实现方法其实与前面的函数没有区别。

代码实现如下：

```c
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftRet = BinaryTreeDepth(root->left);
	int rightRet = BinaryTreeDepth(root->right);

	return leftRet > rightRet ? leftRet + 1 : rightRet + 1;
}
```

动态代码过程见下：

![二叉树的深度](C:\Users\李若尘\Desktop\素材\二叉树\二叉树的深度.gif)

---

### 2.6.5 查找二叉树结点

---

> 查找二叉树结点就是查找二叉树的结点中的数据是否有和要查找的数据相同的结点。
>
> 具体思路：
>
> 1. 判断根结点的数据是否是所要寻找的数据
> 2. 判断左子树中是否有和要查找的数据相同的结点
> 3. 判断右子树中是否有和要查找的数据相同的结点

实现思路：

1. 先判断根结点是否为空，如为空，返回NULL；不为空执行以下操作。
2. 判断根结点中的数据是否与所要查找的数据相同，如果相同，返回该结点指针；不相同执行以下操作。
3. 在左子树中查找，如果找到，返回数据相同的结点的指针；不相同执行以下操作。
4. 在右子树中查找，如果找到，返回数据相同的结点的指针；不相同返回NULL。

代码实现如下：

```c
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
    // 先判断根结点是否为空，如为空，返回NULL
	if (root == NULL)
	{
		return NULL;
	}
	// 判断根结点中的数据是否与所要查找的数据相同，如果相同，返回该结点指针
	if (root->data == x)
	{
		return root;
	}
	// 在左子树中查找，如果找到，返回数据相同的结点的指针
	BTNode* leftRet = BinaryTreeFind(root->left, x);
	if (leftRet)
	{
		return leftRet;
	}
	// 在右子树中查找，如果找到，返回数据相同的结点的指针
	BTNode* rightRet = BinaryTreeFind(root->right, x);
	if (rightRet)
	{
		return rightRet;
	}
	// 不相同返回NULL
	return NULL;
}
```

![二叉树的查找](C:\Users\李若尘\Desktop\素材\二叉树\二叉树的查找.gif)

---

### 2.6.6 判断一颗二叉树是否为完全二叉树

---

> 完全二叉树最后一层以上的结构为满二叉树，最后一层的结点连续。

根据这个连续的特点，我们可以想到用层序遍历，遍历完整棵树。

- 如果从根到最后一个结点全部连续，那么这棵树就是完全二叉树；
- 如果中间出现不连续，那么这颗二叉树就不是完全二叉树。

代码实现思路：

- 层序遍历，但是这次层序遍历必须要把结点的全部孩子(包括NULL)都入队，以便判断是否连续。
- 一旦遍历到空结点，说明要么是已经遍历完整棵树，要么是中间不连续。
- 继续从空结点向后判断，如果以后都为空，那么说明这棵树是完全二叉树。
- 如果出现不为空的结点，说明这棵树不是完全二叉树。

具体代码实现：

```c
bool BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	// 完全二叉树在层序遍历时一定是连续的，可以通过这一点来判断

	while (!QueueEmpty(&q))
	{
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);
		
        // 一旦遍历到空结点，就开始判断队列中剩余结点是否有不为空的结点。
		if (tmp == NULL)
		{
			while (!QueueEmpty(&q))
			{
				if (QueueFront(&q) != NULL)
				{
					return false;
				}
				QueuePop(&q);
			}
			return true;
		}
		
        // 将结点的全部孩子入队
		QueuePush(&q, tmp->left);
		QueuePush(&q, tmp->right);

	}
}

```

---

### 2.6.7 销毁二叉树

---

销毁二叉树其实也是遍历二叉树的过程，不过销毁二叉树我们一般用后序遍历。
因为，后序遍历最后访问根结点，这样我们就可以先释放根结点的字结点，最后释放根结点。而不用担心根结点被提前释放而找不到子结点。

后序遍历销毁二叉树：

```c
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;

	// 思想：先释放孩子，再释放根
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
```

还有一种遍历也可以销毁二叉树，那就是层序遍历。
因为层序遍历会在遍历结点时将它的孩子入队，借助这个遍历的独特优势可以完成销毁。

层序遍历销毁二叉树：

```c
void BinaryTreeDestory1(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);

		if (tmp->left)
			QueuePush(&q, tmp->left);
		if (tmp->right)
			QueuePush(&q, tmp->right);

		free(tmp);
	}
}
```

---
### 2.6.8 二叉树全局代码
---

```c
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//测试用来创建二叉树
BTNode* BuyNode(BTDataType x);
// 二叉树先(前)序遍历 
void PreOrder(BTNode* root);
// 二叉树中序遍历
void InOrder(BTNode* root);
// 二叉树后序遍历
void PostOrder(BTNode* root);
// 二叉树结点个数
int BinaryTreeSize(BTNode* root);
void BinaryTreeSize1(BTNode* root, int* cnt);
// 二叉树叶子结点个数
int BinaryTreeLeafSizeCBTNode(BTNode* root);
// 二叉树第k层结点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 二叉树的高度\深度
int BinaryTreeDepth(BTNode* root);
// 查找二叉树元素
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root);
// 通过前序遍历的数组构建二叉树
// eg."ABD##E#H##CF##G##"
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);
// 二叉树销毁
void BinaryTreeDestory(BTNode* root);


BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

void PreOrder(BTNode* root)
{    
	// 遇到空树就返回
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->data);// 这里我们用打印来代表对根结点进行访问
	PreOrder(root->left);// 对左子树进行先序遍历
	PreOrder(root->right);// 对右子树进行先序遍历
}

void InOrder(BTNode* root)
{
	// 遇到空树就返回
	if (root == NULL)
	{
		return;
	}

	InOrder(root->left);// 对左子树进行中序遍历
	printf("%c ", root->data);// 对根结点进行访问
	InOrder(root->right);// 对右子树进行中序遍历
}

void PostOrder(BTNode* root)
{
	// 遇到空树就返回
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);//  对左子树进行后序访问
	PostOrder(root->right);// 对右子树进行后序访问
	printf("%c ", root->data);// 对根结点进行访问
}

// 输出型参数,与静态变量有相同的缺陷，需要求一次结点个数新创建一个变量
void BinaryTreeSize1(BTNode* root,int* cnt)
{
	if (root == NULL)
	{
		return;
	}

	(*cnt)++;
	BinaryTreeSize1(root->left, cnt);
	BinaryTreeSize1(root->right, cnt);
}

int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : 1 + BinaryTreeSize(root->left)
		+ BinaryTreeSize(root->right);
}

int BinaryTreeLeafSizeCBTNode(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return BinaryTreeLeafSizeCBTNode(root->left) + BinaryTreeLeafSizeCBTNode(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k >= 1);

	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftRet = BinaryTreeDepth(root->left);
	int rightRet = BinaryTreeDepth(root->right);

	return leftRet > rightRet ? leftRet + 1 : rightRet + 1;
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}

	BTNode* leftRet = BinaryTreeFind(root->left, x);
	if (leftRet)
	{
		return leftRet;
	}

	BTNode* rightRet = BinaryTreeFind(root->right, x);
	if (rightRet)
	{
		return rightRet;
	}

	return NULL;
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	// 利用队列先进先出的特点，可以实现层序遍历，先将root入队
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		// 如果此结点的孩子不为空，才可入队
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", tmp->data);

		if (tmp->left)
			QueuePush(&q, tmp->left);
		if (tmp->right)
			QueuePush(&q, tmp->right);
	}

	printf("\n");
	QueueDestroy(&q);
}


bool BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	// 完全二叉树在层序遍历时一定是连续的，可以通过这一点来判断

	while (!QueueEmpty(&q))
	{
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);

		if (tmp == NULL)
		{
			while (!QueueEmpty(&q))
			{
				if (QueueFront(&q) != NULL)
				{
					return false;
				}
				QueuePop(&q);
			}
			return true;
		}
		
		QueuePush(&q, tmp->left);
		QueuePush(&q, tmp->right);

	}
}

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	// 遇到#，i++以后，返回NULL
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	// 还是分治思想，根上插入数据，再让根连接上左子树和右子树，最后返回根
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->data = a[(*pi)++];
	root->left = BinaryTreeCreate(a, pi);
	root->right = BinaryTreeCreate(a, pi);

	return root;
}


// 层序销毁
void BinaryTreeDestory1(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);

		if (tmp->left)
			QueuePush(&q, tmp->left);
		if (tmp->right)
			QueuePush(&q, tmp->right);

		free(tmp);
	}
}

// 后序销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;

	// 思想：先释放孩子，再释放根
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
```



---
---

## 2.7 二叉树相关经典入门题目

---

### 2.7.1 单值二叉树

---

![image-20220108200241448](C:\Users\李若尘\Desktop\素材\二叉树\单值二叉树.png)

思想：

- 先判断根结点是否为空，为空，返回真；不为空，执行以下操作。
- 判断左孩子是否存在，如果存在，比较左孩子和根结点的数据。
- 判断右孩子是否存在，如果存在，比较右孩子和根结点的数据。
- 以上操作为访问根结点的过程。
- 接下来判断左子树是否为单值二叉树，再判断右子树是否为单值二叉树。
- 二者都为单值二叉树，则返回真；其中有一个不为单值二叉树，则返回假。

具体代码实现：

```c
bool isUnivalTree(struct TreeNode* root) 
{
    //遇到空结点，返回真
    if (root == NULL)
    {
        return true;
    }
    //左孩子存在且父亲的值必须等于孩子
    if (root->left && root->val != root->left->val)
    {
        return false;
    }

    if (root->right && root->val != root->right->val)
    {
        return false;
    }

    //左右子树如果全为真，才为真
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}

```

---

### 2.7.2 相同的树

---

![image-20220108201237820](C:\Users\李若尘\Desktop\素材\二叉树\相同的树.png)

- 先判断这两个树根结点是否为空，都为空，返回真；一个不为空，另一个为空，返回假；都不为空执行以下操作。
- 比较两个根结点的值，不相等，返回假；否则执行以下操作。
- 判断一个根结点左子树和另一个根结点的左子树是否相同，再比较一个根结点右子树和另一个结点的右子树是否相同。
- 都相同，返回真；其中有一不相同，返回假。

代码实现：

```c
bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
    // 都为空
    if(p == NULL && q == NULL)
        return true;
    // 其中有一个不为空
    if(p == NULL || q == NULL)
        return false;
	// 比较两根结点的值
    if (p->val != q->val)
    {
        return false;
    }
	// 判断左右子树是否相同
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
```

---

### 2.7.3 对称二叉树

---

![image-20220108202850215](C:\Users\李若尘\Desktop\素材\二叉树\对称二叉树.png)

这道题其实就是相同的树的变式，只不过实现思想略有变化，从判断两棵树到判断一棵树的左右子树。

- 先判断这这棵树是否为空树，如为空树，返回真；不为空，执行以下操作。
- 判断左子树和右子树根结点是否为空，都为空，返回真；一个不为空，另一个为空，返回假；都不为空执行以下操作。
- 比较两个根结点的值，不相等，返回假；否则执行以下操作。
- 判断一个根结点左子树和另一个根结点的右子树是否相同，再比较一个根结点右子树和另一个根结点的左子树是否相同。
- 都相同，返回真；其中有一不相同，返回假。

```c
bool _isSymmetric(struct TreeNode* root1, struct TreeNode* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->val != root2->val)
        return false;

    return _isSymmetric(root1->left, root2->right) && _isSymmetric(root1->right, root2->left);
}


bool isSymmetric(struct TreeNode* root) 
{
    if (root == NULL)
        return true;

    return _isSymmetric(root->left, root->right);
}
```

---

### 2.7.4 另一棵树的子树

---

![image-20220108203611017](C:\Users\李若尘\Desktop\素材\二叉树\另一棵树的子树.png)

这道题也是相同的树的变式。

实现思想：

> 以root的每个结点为根，判断是否与subRoot相同。

代码实现；

```c
bool isSameTree(struct TreeNode* root1, struct TreeNode* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->val != root2->val)
        return false;

    return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) 
{
    // 由于subRoot至少有一个结点，所以root为空时，subRoot必不为root子树
    if (root == NULL)
        return false;

    return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
```

---

### 2.7.5 反转二叉树

---

![image-20220108204243858](C:\Users\李若尘\Desktop\素材\二叉树\反转二叉树.png)

依然使用分治的思想：

- 先判断根结点是否为空，如果为空，返回NULL；不为空，执行以下操作。
- 反转左子树，再拿到左子树的根结点。
- 反转右子树，再拿到右子树的根结点。
- 然后让反转后的右子树成为根结点的左孩子，再让反转后的左子树成为根结点的右孩子。

代码实现：

```c
struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    struct TreeNode* leftRet = invertTree(root->left);
    struct TreeNode* rightRet = invertTree(root->right);

    root->left = rightRet;
    root->right = leftRet;

    return root;
}
```

---

### 2.7.6 平衡二叉树

---

![image-20220108205053617](C:\Users\李若尘\Desktop\素材\二叉树\平衡二叉树.png)

依然使用分治的思想：

- 先判断根结点是否为空，为空，返回真；不为空，执行以下操作。
- 判断左右子树的高度差是否超过1，超过1，返回假；
- 再从上到下以各个结点为根，判断各个左右子树的高度是否超过1；

代码实现：

```c
int BinaryTreeDepth(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftRet = BinaryTreeDepth(root->left);
    int rightRet = BinaryTreeDepth(root->right);

    return leftRet > rightRet ? leftRet + 1 : rightRet + 1;
}

bool isBalanced(struct TreeNode* root) 
{
    if (root == NULL)
        return true;

    return (int)fabs(BinaryTreeDepth(root->left) - BinaryTreeDepth(root->right)) <= 1
        && isBalanced(root->left) && isBalanced(root->right);
}
```

上述方法有些值得改进的地方，比如：重复计算了多次高度。如果我们从下到上计算高度，就可以避免这个问题，并且可以从下到上判断一棵树的平衡，这样更符合一般人的思维。

- 判断根结点是否为空，为空，返回0；不为空执行以下操作。
- 递归计算左子树的高度，再递归计算右子树的高度。
- 如果左右子树的高度差超过1，返回-1。
- 一旦一棵树中有一个地方是不平衡的，那么这棵树就是不平衡的。
- 如果高度差不超过1，返回这棵树的高度。
- 最后返回的值，如果等于-1，这棵树就是不平衡的；如果大于等于0，说明这棵树为平衡二叉树。

```c
int BinaryTreeDepth(struct TreeNode* root) 
{
    if (root == NULL) {
        return 0;
    }
    // 计算左右子树的高度
    int leftDepth = BinaryTreeDepth(root->left);
    int righDepth = BinaryTreeDepth(root->right);
    // 如果左右子树的高度差超过1，返回-1
    // 一旦一棵树中有一个地方是不平衡的，那么这棵树就是不平衡的
    if (leftDepth == -1 || righDepth == -1 || fabs(leftDepth - righDepth) > 1) 
    {
        return -1;
    } 
    else 
    {
        // 如果高度差不超过1，返回这棵树的高度
        return leftDepth > rightDepth ? leftDepth + 1 : righDepth + 1;
    }
}

bool isBalanced(struct TreeNode* root) 
{
    return BinaryTreeDepth >= 0;
}
```

---

---

---

# 🍎后记

---

如果你能读到这里，相信你已经掌握了二叉树入门的大部分知识，恭喜🥳🥳。在掌握二叉树的基本知识以后，我们就能以此为跳板，去实现更多复杂的数据结构了。🎉✨🎊

这篇文章属于是我写的文章中花费时间之最了，本来想着不断精简文章内容，但是成品经过反复修改后，还是写了万字以上。我尝试着每次文章都能有进步，这次也在制作的大量的图片，使用了较为详细的图解。希望大家可以喜欢我这篇文章。😜

最后如果大家喜欢我这篇文章，不如给我一个`大拇指` 👍和`小星星` :star:，支持一下白晨吧！喜欢白晨[《数据结构》](https://blog.csdn.net/baichendada/category_11556944.html?spm=1001.2014.3001.5482)系列的话，不如`关注`:eyes:白晨，以便看到最新更新哟！！！

我是不太能熬夜的白晨，我们下篇文章见。

---

