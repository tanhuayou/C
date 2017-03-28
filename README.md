# 1,函数调用规约
|   调用方式    |   堆栈清除    |   参数传递        |
|:-------------:|:-------------:|:-----------------:|
|   __cdecl     |    调用者     |从右到左,通过堆栈传递|
|   __stdcall   |    函数体     |从右到左,通过堆栈传递|
|   __fastcall  |    函数体     |从右到左,优先使用寄存器(ECX,EDX),然后使用堆栈|
|   thiscall    |    函数体     |this指针默认通过ECX传递,其它参数从右到左入栈|

# 2,
