## Nginx安装

下载nginx
```c
yum -y install gcc gcc-c++ wget
wget http://nginx.org/download/nginx-1.10.1.tar.gz
tar -zxvf nginx-1.10.1.tar.gz
```

编译安装nginx
```c
yum -y install pcre-devel openssl-devel zlib-devel

cd nginx-1.10.1

./configure \
--prefix=/usr/local/nginx \
--with-http_ssl_module

make && make install
```

## nginx源码分析

### nginx目录结构

>* src目录: 存放nginx源码。
* man目录: 存放nginx帮助文档。
* html目录: 存放默认网站文件。
* contrib目录: 存放其它机构或组织贡献的文档资料。
* conf目录: 存放nginx服务器的配置文件。
* auto目录: 存放大量的脚本文件，和configure脚本程序相关。
* configure文件: Nginx自动安装脚本，用于环境检查，生成编译代码需要的makefile文件。
* CHANGES,CHANGES.ru,LICENSE和README都是Nginx服务器的相关资料。

### src目录结构

>* core: Nginx的最基础的库和框架。包括了内存池、链表、hashmap、String等常用的数据结构。
* event: 事件模块。
* http: HTTP的模块。
* os\unix:
* mail:
* misc:

### nginx内存池
#### 对应文件
1. ```src/os/unix/ngx_alloc.c```
2. ```src/os/unix/ngx_alloc.h```
3. ```src/core/ngx_palloc.c```
4. ```src/core/ngx_palloc.h```
#### 数据结构定义
ngx
#### 相关函数实现

### 数组结构

#### 对应文件
1. ```ngx_array.h```
2. ```ngx_array.c```

#### 数据结构定义

#### 相关函数实现


### 缓冲区结构
#### 对应文件

#### 数据结构定义

#### 相关函数实现

### 双向链表结构
#### 对应文件

#### 数据结构定义

#### 相关函数实现

### 单向链表结构
#### 对应文件

#### 数据结构定义

#### 相关函数实现

### hash表结构
#### 对应文件

#### 数据结构定义

#### 相关函数实现

### 字符串结构
#### 对应文件

#### 数据结构定义

#### 相关函数实现