# CharactorSet
对于一个字符串来说，就是一对二进制流，必需有一种编码和解码的方式来解析二进制串
## ASCII,uincode,utf-8,utf-16,utf-32,gb2312，char,tchar_w，gb2312的关系

### ASCII:
   只能表示英文字符，对应1252字符集；
### UNICODE
   编码了世界上的绝大部分字体。Unicode的编码空间划分为17个平面，每个平面有65535个码位；第一个平面为基本多语言平面（包含基础的3000个中文字），其它平面称为辅助平面。 
__utf-8,utf-16,utf-32__： 都属于UNICODE字符集.

#### UTF8
1. 其中utf-8是变长编码，对于一个Unicode的字符被编码为1至4个字节。大部分的中文字为3byte的编码，少数为4byte; 
2. 优点： 向后兼容ASCII；没有字节序（大小端）的问题，适合网络传输；存储英文比较省空间
3. 缺点： 变长不利于文本处理；对中文存储比较浪费；

#### UTF-16
1. UTF-16分为大小端，也是一种变长编码，一个Unicode字符被编码为1或者2个码元，每个码元16位
2. 优点： 处理中文省空间，文本处理简单；
3. 缺点：存储和传输要考虑字节序，不兼容ASCII; 

#### UCS2(2 byte universal character set)　
1. UCS2是一种定长编码，编码范围0x0000-0xFFFF,在基本多语言平面下与utf-16等价。Windows下wchart_t就是使用UCS2来编码。
`wchar_t wc = L('𪚥');`在MSVC下编译不通过，因为𪚥这个字不在基本多语言平面内。
2. 优点： 文本处理方便；缺点：不能表示全部的unicode

#### UCS4/UTF-32
1. UTF-32使用4个字节表示一个码元，其值与Unicode编码值相等；
2. 优点：定长容易文本处理；
3. 缺点：空间浪费与字节序；
 


#### char wchart_t c++11 WCSL
在C++11之前C++中有个wchar_t的类型用于存储宽字符,以L开头的字符字面量为WCSL(Wide-Character String Literals)，由于标准没有规定这个实现，wchart_t及其字面量与实现相关，
1. Windows平台下sizeof(wchar_t)为2，使用UCS2编码；
2. Linux平台下sizeof(wchar_t)为4，使用utf-32编码；

C++11的USL
1. 什么也不带的字符串， const char*　，　原始编码 
2. 带u8的，  const char*, utf-8编码
3. 带L的，   const wchart_t*, 宽字符
4. 带u的，   const char16_t*, utf-16编码
5. 带U的，   const char32_t*, utf-32编码

以上只是字符串带前缀的，是用来提示编译器用什么方式从源码里读来再编码的。

## 代码h，cpp的文件保存格式与代码里中文字符串问题
__尽量不用中文注释与中文字符串，最好从文本里读__

### 代码里写中文到输出经历了哪些？
1. 代码.cpp保存时使用的字符集，（带BOM的utf8或者原始编码GB2312,中文机器上一般默认是GB2312编码）
2. 编译器读取源代码文件时使用的内部字符集，编译器内部使用utf8来编码，也就是说编译器读文件后的字符串会被重编码为utf8
3. 编译器在生成编译时使用的字符集
4. 可执行程序的字符集

__只有当编译的机器是gb2312编码，并且运行的机器也是gb2312才能输出中文__

#### 为什么这么说，出问题的情况
可以做一下这个实验  

	char datas[] = "张张";
	std::cout << datas << std::endl;

1. 保存成不带BOM的UTF-8
2. 保存成带BOM的UTF-8
3. 保存成GB2312  

运行结果  

1. 寮犲紶
2. 张张
3. 张张

原因
1. 一定要把断点打到std::cout之前来观察datas的字节码; 
2. 用“张张”而不是“张”是为了防止第一种情况编译不过。原因再讲；
2. 第一种情况,保存成不带BOM的UTF-8: datas=[0xE5,0xBC,0xA0,0xE5,0xBC,0xA0,0x00]；
3. 第二种情况，保存成带BOM的UTF-8： datas=[0xD5,0xC5,0xD5,0xC5,0x00];
4. 第三种情况,保存成GB2312:datas=[0xD5,0xC5,0xD5,0xC5,0x00];

张的utf8编码为0xE5,0xBC,0xA0,GB2312的编码为0xD5,0xC5.   

第一种情况下，编译器检测不出来文件的编码，因为没带BOM头，就按GB2312的编码来读取（本身是utf8)，结果出错；  
第二种情况下，编译器检查出是带BOM的utf8,按utf8编码，正确读取文件字符“张张”；  
第三种情况下,编译器检测不出来文件的编码，因为没带BOM头，就按GB2312的编码来读取，因为原来就是GB2312的编码，所以正确读取文件“张张”。__注意__,vs默认都是无编码的，只是中文机器上是GB2312编码，如果机器上没有GB2312编码，这种情况下“0xD5 0xC5”是无法转化为“张张”的；

那么问题又来了，为什么第二种情况下，是0xD5,0xC5而不是按utf8编码。
再来做一个实验，一定要用带BOM的UTF8来编码

	char datasUTF8[] = u8"张张";
	std::cout << datasUTF8 << std::endl;

可以看到dataUTF8=[0xE5,0xBC,0xA0,0xE5,0xBC,0xA0,0x00]  
说明：__编译器读取“张张”后，如果是默认的，就按默认的Code Page转一下，如果带u8等前缀，会按前缀转__

__注意__,这个时候，因为是编译成字节码了，也就是在可执行的二进制的代码里面这些内存是以什么形式存在的呢？只能看汇编了。通过汇编可知：__和当前的内存里保存的一致__。也就是说，带u8的话，字符串已经按utf8的二进制保存到了可执行代码里。

__注意__，以上已经在本地编译完了，可见中文的话因为保存的方式不一样就可以引起结果很不一样了。 

以下是执行结果的解释
1. 第一种情况，数据是错的，输出有问题；
2. 第二种情况，数据是GB2312,默认的编码，输出是正确的；
3. 第三种情况，数据是GB2312,默认的编码，输出是正确的。

问题来了，如果输出datasUTF8呢，结果是“寮犲紶”，说明控制输出时使用默认的code page.

实现验证，改控制台的code page,发现没有效果，原因是就算code page换成utf8，控制台输出的还是乱码，原因未知。 


## 总结
代码里，不要放非英文字符之外的字符，包括注释与代码。










