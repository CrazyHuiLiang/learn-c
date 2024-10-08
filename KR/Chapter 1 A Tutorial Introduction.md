# 导言

> Demo: [Hello world](./002-hello.c)

在Unix操作系统中，通常使用`cc`进行C语言的编译和链接；一个C语言程序都是由函数和变量组成的，函数中包含一些语句，以指定所要执行的计算操作；变量用于存储计算过程中使用的值。

```bash
# 在 KR目录下
cc 002-hello.c

# 运行
./a.out
```

## 符号常量

用双引号括起来的字符序列称为字符串或者字符串常量

* `\n` 表示换行符
* `\t` 表示制表符
* `\b` 表示回退符
* `\"` 表示双引号
* `\\` 表示反斜杠本身

在C语言中，所有变量都必须先声明后使用。

数据类型有：

* `int` 整型
* `char` 字符
* `short` 短整型
* `long` 长整型
* `float` 单精度浮点型
* `double` 双精度浮点型

>Demo: [打印华氏温度与摄氏温度对照表](./004-fahr-celsius.c)
>
>Demo: [打印华氏温度与摄氏温度对照表 浮点数版本](./006-fahr-celsius.c)

`printf函数` 的第一个参数是一个格式说明，其中的`%`分别对应于第二个、第三个、 ... 参数，他们在数目和类型上都必须匹配。printf函数并不是C语言的一部分，C语言本身没有定义输入/输出功能。printf仅仅是标准库函数中一个有用的函数而已。

如果在printf语句的第一个参数中的%d中指明打印宽度，则打印的数字会在打印区内右对齐；格式说明可以省略宽度与精度，一些示例：

* `%3.0f` 待打印的浮点数至少占3个字符宽，且不带小数点和小数部分
* `%6.1f` 待打印的浮点数至少占6个字符宽，且小数点后面有1位数字
* `%6f` 表示待打印的浮点数至少有6个字符宽
* `%.2f` 表示待打印的浮点数的小数点后有2位小数
* `%o` 表示八进制数
* `%x` 表示十六进制数
* `%c` 表示字符
* `%%` 表示百分号本身

`#define` 指令可以把符号名（符号常量）定义为一个特定的字符串、数字、表达式；注意`#define`指令行的末尾没有分号

```c
#define 名字 替换文本
```

## 字符输入/输出

无论文本从何处输入，输出到何处，其输入/输出都是按照字符流的方式处理。文件流是由多行字符构成的字符序列，每行行末是一个换行符。标准库负责使每个输入输出都能够遵守这一模型。标准库提供了一次读/写一个字符的函数，最简单的是：

* `char getchar()` 读一个字符
* `putchar(c)` 写一个字符

> Demo: [文件复制](./010-copyFile.c)
> Demo: [文件复制 v2](./011-copyFile.c)

在没有输入时，getchar函数将返回一个特殊值，这个特殊值与任何实际字符都不同。这个值被称为EOF(end of file，文件结束)，在终端中输入 **control + D** 相当于输入EOF，EOF定义在头文件 **<stdio.h>** 中。

## 语句

单引号中的字符表示一个整型值，我们称之为字符常量

单独的分号称为空语句

逻辑与（&&）仅比逻辑或（||）高一个优先级

## 函数

函数的定义的一般形式为：

```c
返回值类型 函数名(0个或多个参数声明) {
    声明部分
    语句序列
}
```

函数声明的一般形式为：

```c
返回值类型 函数名(0个或多个参数声明);
```

函数定义可以以任意次序出现在一个源文件或多个源文件中，但同一函数不能分割存放在多个文件中。函数原型与函数声明中参数名不要求相同，事实上，函数原型中的参数名是可选的，比如下面两种形式是等价的：

```c
int power(int m, int n);
int power(int, int);
```

在C语言中，所有函数参数都是“通过值”传递的，被调用函数不能直接修改主调函数中变量的值，而只能修改其私有临时副本的值。

必要时也可以让函数能够修改主调函数中的变量。这种情况下，调用者需要向被调用函数提供设置值的变量的地址，而被调用函数则需要将对应的参数声明为指针类型，并通过它间接访问变量。

当把数组名作为参数时，传递给函数的值是数组起始元素的位置或地址 - 他并不复制数组元素本身。在被调用函数中，可以通过数组下标访问或修改元素的值。

## 字符数组

> Demo: [打印最长的输入行](./021-printLongestLine.c)

字符 `\0` （及空字符串，其值为0）插入到数组的末尾，以标记字符串的结束。这一约定已被C语言采用。

## 外部变量与作用域

main函数中的变量是main函数的私有变量或者局部变量。由于他们是在main函数中声明的，因此其他函数不能直接访问它们。其他函数中声明的变量也同样如此。函数中的每个局部变量只在函数被调用时存在，在函数执行完毕退出时消失，这类变量也被称为自动变量。

除自动变量外，还可以定义位于所有函数外部的变量，也就是说，在所有函数中都可以通过变量名访问这种类型的变量，外部变量在程序执行期间一直存在。外部变量必须定义在所有函数之外，且只能定义一次，定义后编译器程序将为它分配存储单元。在每个需要访问外部变量的函数中，必须声明相应的外部变量，此时说明其类型。声明时可以用 `extern` 语句显示声明，也可以通过上下文隐式声明。

在源文件中，如果外部变量的定义出现在使用他的函数之前，那么在那个函数中就没有必要使用 `extern` 声明。通常的做法中，所有外部变量的定义都放在源文件的开始处，这样就可以省略 `extern` 声明。

如果程序包含在多个源文件中，而某个变量在file1文件中定义、在file2和file3文件中使用，那么在文件file2和file3中就需要使用 `extern` 声明来建立该变量与其定义之间的联系。人们通常把变量和 `extern` 声明放在一个单独的文件中（习惯上称之为头文件），并在每个源文件的开头使用 `#include` 语句把所要用的头文件包含进来。

* 定义（define)：表示创建变量或分配存储单元
* 声明（declaration）：指说明变量的性质，但并不分配存储单元
