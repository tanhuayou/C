# C笔记
----------
### 函数调用 ###
|   调用方式    |   堆栈清除    |   参数传递        |
|:------------:|:------------:|:-----------------:|
|   __cdecl    |    调用者     |从右到左,通过堆栈传递|
|   __stdcall  |    函数体     |从右到左,通过堆栈传递|
|   __fastcall |    函数体     |从右到左,优先使用寄存器(ECX,EDX),然后使用堆栈|
|   thiscall   |    函数体     |this指针默认通过ECX传递,其它参数从右到左入栈|


----------
### 运算符优先级 ###
由上至下优先级递减

|运算符     |名称       |结合性    |
|:---------:|:---------:|:------------:|
|() [] -> . |前述运算符 |自左向右 ->   |
|! & ~ - * ++ -- sizeof|单目运算符 |自右向左  **<-** |
| * % /    |算术运算符 |自左向右 ->   |
| + -      |算术运算符 |自左向右 ->   |
| <<  >>    |移位运算符 |自左向右 ->   |
| \> \>= < <=|关系运算符 |自左向右 ->   |
|  == !=    |关系运算符 |自左向右 ->   |
|  &        |逻辑运算符 |自左向右 ->   |
|  ^        |逻辑运算符 |自左向右 ->   |
|  \|       |逻辑运算符 |自左向右 ->   |
|  &&       |逻辑运算符 |自左向右 ->   |
|  \|\|     |逻辑运算符 |自左向右 ->   |
|  ?:       |条件运算符 |自右向左 ->   |
|  =        |赋值运算符 |自右向左 ->   |
|  ,        |逗号运算符 |自左向右 ->   |


