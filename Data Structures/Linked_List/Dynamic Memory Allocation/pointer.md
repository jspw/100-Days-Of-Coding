# Pointer in C/C++

Let's consider a int type variable **var**.

```c++
int var = 10;
```

So if we print **var** it will be like :

```c++
printf("%d",var);
```

Output : `10`

There is a location in our system memory where every variables are stored when we declare them.
So where is the variable **var** ?
To print the momory address or location of a variable we have to use **unary &** operator

```c++
print("The memory address of a is %p: ",&a); //%p is used to print a pointer
```

Output :`The memory address of a is : 0x7fffbabdb6f0`

The memory address can be different as it takes a random memory address everytime you build your program, but looks like same(**0x..........**).

Let's declare a pointer :

```c++
int *pa; // or int * pa
```

**Note : If you are pointing the pointer at a data type you have to declare it at the declaration of the pointer**
Now point Pointer **pa** at **var**;

```c++
pa = &var;
```

Now the pointer is pointed at the **var** variable and it takes the location or memory address of **var**.
Let's print **pa** :

```c++
printf("%p",pa);
```

Output : `0x7fffbabdb6f0`
Which is same as the memory address of **var** variable.

We can also print the value of a memory address using **unary \*** operator.This is also called **Dereferencing**

```c++
printf("%d",*pa);
```

Output : `10`

Now we can say a **Pointer** is an object in many programming languages that stores a memory address.

Let's see what happens if we change the value of **var**.

```c++
var = 10001;
printf("Value of var : %d\n",var);
printf("Value of memory  address %p is : %d",pa,*pa);
```

Output :

```
Value of var : 10001
Value of Memory address 0x7fffbabdb6f0 is : 10001
```

We can see changing the value of **var** changes the value of **pa** memory address.

Whaf if we increase the value of the Pointer **pa** ? Let's see:

```c++
pa++;
printf("Pointer (pa) is pointed to %p and value becomes : %d\n", pa, *pa);
```

Output :

```
Pointer (pa) is pointed to 0x7fffbabdb6f8 and value becomes : -1161971980
```

Here **-1161971980** is a gurbage value as nothing is initialized in memory address **0x7fffbabdb6f8**

But what if there were more then one int in our code like anaother variable **var2** ?
Let's see :

```c++
int x = 12;
int *px = &x;

printf("Value of memory  address(px) %p is : %d\n",px,*px);

pa++;

printf("Pointer (pa) is pointed to %p and value becomes : %d\n", pa, *pa);
```

Output :

```
Value of Memory address (px) 0x7fffbabdb6f4 is 12
Pointer (pa) is pointed to 0x7fffbabdb6f4 and value becomes : 12
```

A **int** data type takes **2 or 4 bytes** Storage in memory.
**var** was taking memory address from **0x7fffbabdb6f0** to **0x7fffbabdb6f3**, using **++** operator in pointer it jummped to the next memory address and it was **0x7fffbabdb6f4**

Pointer increment incrase by it's type !

### Pointer Expressions and Pointer Arithmetic:

A limited set of arithmetic operations can be performed on pointers. A pointer may be:

- incremented ( ++ )
- decremented ( -- )
- an integer may be added to a pointer ( + or += )
- an integer may be subtracted from a pointer ( – or -= )

Pointer arithmetic is meaningless unless performed on an array.

**Note : Pointers contain addresses. Adding two addresses makes no sense, because there is no idea what it would point to. Subtracting two addresses lets you compute the offset between these two addresses.**

#### Pointer in Arrays

Declare an array:

```c++
int ar[] = {1, 2, 3, 4, 5};
```

Declare pointer variable:

```c++
int *ptr;
```

Assign the address of v[0] to ptr

```c++
ptr = ar; //We can use ptr=&ar[0];(both are same)
```

Let's print array elements with thieir memory address :

```c++
for (int i = 0; i < 5; i++)
{
    printf("Value of *ptr = %d\n", *ptr);
    printf("Value of ptr = %p\n", ptr);

    // Increment pointer ptr by 1
    ptr++;
}
```

Output :

```
Value of *ptr = 1
Value of ptr = 0x7fffe4378a30
Value of *ptr = 2
Value of ptr = 0x7fffe4378a34
Value of *ptr = 3
Value of ptr = 0x7fffe4378a38
Value of *ptr = 4
Value of ptr = 0x7fffe4378a3c
Value of *ptr = 5
Value of ptr = 0x7fffe4378a40
```

We can also use :

```c++
for (int i = 0; i < 5; i++)
{
    cout<<ptr[i]<<" ";
}
cout<<endl;
```

Output : `1 2 3 4 5`

As an array name acts like a pointer constant. The value of this pointer constant is the address of the first element.

**Pointer to pointer**

Have you even think that if a variable has a memory address in the memory then what about the pointer we are using to point on the variable?
Yes,a pointer also has a memory address.

```cpp
int sum =10;
int * psum = &a;
printf("Memory address of variable(sum) : %p\n",psum);
printf("Memory Address of pointer(psum) :  %p\n",&psum);
```

Output :

```
Memory address of variable(sum) : 0x7ffc3b46638c
Memory Address of pointer(psum) :  0x7ffc3b466398
```

Let's declare a pointer for a int pointer :3

```cpp
int **ppsum = &psum; //as ppsum is a pointer of a int type variable's pointer
```

print the memory address of the pointer :

```cpp
printf("Memory Address of pointer(psum) :  %p\n",ppsum);
```

Output :

```
Memory Address of pointer(psum) :  0x7ffc712e6780
```

### Pass by Value

```cpp
void passByValue(int x){
    x = 20;
    print("In passByValue function, x = %d\n",x);
}

int main(){
    int x = 10;
    passByValue(x);
    print("In main Function, x = : %d\n",x);
    return 0;
}
```

Output :

```
In passByValue function, x = 20
In main Function, x = : 10
```

In this case, `x` in passByValue() function and `x` in main() function are not same, just the variable names are same but they indicate two different memory locations.
Let's go deeper :3

```cpp
void passByValue(int x){
    cout<<"In passByValue Function : "<<endl;
    x = 20;
    printf("x = %d\n",x);
    cout<<"Memory address of x = "<<&x<<endl;
}

int main(){
    int x = 10;
    passByValue(x);
    cout<<"In main Function : "<<endl;
    printf("x = %d\n",x);
    cout<<"Memory address of x = "<<&x<<endl;
    return 0;
}
```

Output :

```
In passByValue Function :
x = 20
Memory address of x = 0x7ffc6c07397c
In main Function :
x = 10
Memory address of x = 0x7ffc6c0739a0
```

So looking at the outputs we can find that the memory addresses are not same ! The two `x` are not same.

### Pass by Reference

```c++
void passByReference(int *px){
    *px = 100;
    printf("In passByReference() function, Memory address =  %p\n",px);
}

int main(){
    int x = 10;
    cout<<"(Before) Value of x : "<<x<<endl;
    passByReference(&x);
    cout<<"(After) Value of x : "<<x<<endl;
    cout<<"Memory address of x = "<<&x<<endl;
    return 0;
}

```

Output :

```
(Before) Value of x : 10
Memory address =  0x7ffe2bd44670
(After) Value of x : 100
Memory address of x = 0x7ffe2bd44670
```

In pass by reference we are sending the memory address of `x` and then in the function we are chnaging the value which is stored in the memory address.
So chaging value of memory address will also chnage the value of `a` as it is stored in the memory address.

### Dangling Pointers

```c++
int* getValue(){
    int x;
    x=2;
    return &x;
}

int main(){
    int *px = getValue();
    print("Value in memory address(px) = %d\n",*px);
}

```

Output : `Value in memory address(px) = 2`

In this case getValue() returns the memory address where `x` were stored. After returning memory address `x` vanishes but the value in that address remains and after that if we take a variable like

```c++
int var3 = 120
```

there is a huge possibility that `var3` can be stored in that memory address which can make problem for you and that is called **Dangling Pointer**

**Dangling pointers** arise during object destruction, when an object that has an incoming reference is deleted or deallocated, without modifying the value of the pointer, so that the pointer still points to the memory location of the deallocated memory.

So hare comes the term **Dynamic Memory Allocation**

### Dynamic Memory Allocation

1. Stack ->
2. Heap
3. BSS
4. Data
5. Code

C Dynamic Memory Allocation can be defined as a procedure in which the size of a data structure (like Array) is changed during the runtime.

C provides some functions to achieve these tasks. There are 4 library functions provided by C defined under <stdlib.h> header file to facilitate dynamic memory allocation in C programming. They are:

- malloc()
- calloc()
- free()
- realloc()

#### C malloc() method

**“malloc”** or **“memory allocation”** method in C is used to dynamically allocate a single large block of memory with the specified size. It returns a pointer of type void which can be cast into a pointer of any form. It initializes each block with default garbage value.

**Syntax:**
`ptr = (cast-type*) malloc(byte-size)`

**For Example:**

```cpp
int* ptr = (int*) malloc(100 * sizeof(int));
```

Since the size of int is 4 bytes, this statement will allocate 400 bytes of memory. And, the pointer ptr holds the address of the first byte in the allocated memory.

#### C free() method

**“free”** method in C is used to dynamically de-allocate the memory. The memory allocated using functions malloc() and calloc() is not de-allocated on their own. Hence the free() method is used, whenever the dynamic memory allocation takes place. It helps to reduce wastage of memory by freeing it.

```cpp
free(ptr);
```

**Note:When we declare a pointer it pointed to a random memory address of the memory so better practice is to set them null first**

```cpp
int* px = NULL;
```

#### C calloc() method

**“calloc”** or **“contiguous allocation”** method in C is used to dynamically allocate the specified number of blocks of memory of the specified type. It initializes each block with a default value ‘0’.

**Syntax:**

`ptr = (cast-type*)calloc(n, element-size);`

**For Example:**

```cpp
ptr = (float*) calloc(25, sizeof(float));
```

This statement allocates contiguous space in memory for 25 elements each with the size of the float.

**Note:alloc() function allocate n bytes in memory where calloc() function allocate x blocks of y bytes in memory**



#### C realloc() method

**“realloc”** or **“re-allocation”** method in C is used to dynamically change the memory allocation of a previously allocated memory. In other words, if the memory previously allocated with the help of malloc or calloc is insufficient, realloc can be used to dynamically re-allocate memory. re-allocation of memory maintains the already present value and new blocks will be initialized with default garbage value.

**Syntax:**

```
ptr = realloc(ptr, newSize);
```

where ptr is reallocated with new size 'newSize'.

```cpp
int* p = (int*)malloc(n*sizeof(int));
p = realloc(p,n*sizeof(int));
```


for more [Dynamic Memory Allocation and Fragmentation in C and C++](https://www.design-reuse.com/articles/25090/dynamic-memory-allocation-fragmentation-c.html)

