#ifndef _UTIL_TOOLS_H_
#define _UTIL_TOOLS_H_

#define  SAFE_DEL(x) if ((x))\
	{\
		delete (x); (x) = NULL;\
	}


/*
<string.h>
	<string.h>是C版本的头文件，包含比如strcpy、strcat之类的字符串处理函数。
<cstring>
	在C++标准化(1998年)过程中，为了兼容以前，标准化组织将所有这些文件都进行了新的定义，加入到了标准库中，
	加入后的文件名就新增了一个"c"前缀并且去掉了.h的后缀名，所以string.h头文件成了cstring头文件。
	但是其实现却是相同的或是兼容以前的，这就是<cstring>的来源，不要觉得又多了一个东西。相当于标准库组织给它盖了个章，说“你也是我的标准程序库的一份子了”。
<string>
	<string>是C++标准定义的头文件，它定义了一个string的字符串类，里面包含了string类的各种操作，如s.size(), s.erase(), s.insert()等。但<string>又包含了老的C版本的字符串操作如strcpy、strcat等，
	这就相当于，在<string>的文件中除了定义自己的string类之外，还加了一个#include<string.h>一句包含了C版本的字符串操作。
	没有<cstring.h>这样的头文件。
*/
#endif // !_UTIL_TOOLS_H_





