# advent-of-code-2022-c-plusplus

Trying my hand at learning C++ with this advent of code.

I have zero experience with C++, so this will be fun.
I'll write out my thoughts as I code each of the problems.

## Basics

### Compiler

To get started with C++, we'll need a compiler, which is a program that takes the code and turns it into an executable program. There are a number of different compilers.

Because I'm using a Mac with Visual Studio Code, I'll use the Clang C++ compiler, which is included with the Xcode command-line tools on a Mac. To get it set up, run the following command:

```
xcode-select --install
```

### First Code file

Once we have a compiler installed, we start writing the program like this:

```
#include <iostream>

int main()
{
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
```

Some observations - `cout` is a part of `iostream`, so we gotta import that. `main()` seems like the entry point to any program.

To compile and run the program, save it to a file with a `.cpp` extension. Then we use C++ compiler to compile the program and get the executable file.

Then, you can finally compile the code like this

```
clang++ -o hello hello.cpp
```

and you'll get a `hello` file. The `hello` file will look like gibberish. Something like this

```
bufEv__ZNKSt3__18ios_base5rdbufEv__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenEc__ZNSt3__1L9use_facetINS_5ctypeIcEEEERKT_RKNS_6localeE__ZNKSt3__15ctypeIcE5widenEc__ZNSt3__18ios_base8setstateEjGCC_except_table4GCC_except_table7GCC_except_table11GCC_except_table40GCC_except_table45��
                                         ����
                                             �^X
�`
�  @hello5�+П�
 �P:��k`[uX���jc2���`���Xo��f����kOX�|�|z�ڽ�H�,�^i�zFlD�W�n��U� ���5NF�Q�8JIn��8�Z��`�� Aƚ�~�����O\��8Ҍ �PtJ�(s-T������:����C���hZ������`�.�T������%
```

Finally, you can execute that gibberish by writing

```
./hello
```

in the terminal and voila!

```
Hello, world!
```

### A little automation...

Coming from a purely python and javascript dev environment, I'm used to simply running a file and getting the output. What I want to build now is _something_ that, when I save `hello.cpp`, it gets automatically compiled onto `hello` and that `hello` file gets executed immediately.

What we'll do is use a build system. The build system is a tool that automates the process of building and compiling the C++ code. It can take care of tasks such as finding the right compiler to use, running the compiler, and linking any external libraries or dependencies that the code may need.
