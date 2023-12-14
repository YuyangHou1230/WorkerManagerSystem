# 职工管理系统
---
基于Qt的职工管理系统，使用mysql数据库作为存储

## 功能概述

- 用户登录/注销
- 用户权限管理
- 职工增删查改
- 考勤管理
- 工资计算

## mysql开发环境搭建
这里主要是说明如何搭建mysql的开发环境，Qt从5.12.3之后不再默认提供mysql的驱动库qsqlmysql.dll，需要自行编译，该项目使用的是Qt5.14.2版本下 mingw64位编译的数据库驱动，相应动态库来自MysqlServer8.0版本
将lib目录中的动态库libcrypto-3-x64、libssl-3-x64、libmysql放到Qt安装目录对应编译器bin目录或者生成的程序目录下
以我的编译器目录举例：
C:\Qt\Qt5.14.2\5.14.2\mingw73_64\bin

将qsqlmysql放到编译器的插件目录，以我的目录举例：
C:\Qt\Qt5.14.2\5.14.2\mingw73_64\plugins\sqldrivers

