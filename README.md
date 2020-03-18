# FastCAE_Linux源码下载与编译说明（源码下载编译必读）

#特别注意：
1. 源码绝对路径中不要出现中文字符;
2. 源码文件夹中不要出现空格(){}*/?|\等特殊字符
3. 要求自行安装gcc,g++,Qt5.4.2和python37
4. 建议使用Linux系统为Ubuntu16.04

#源码下载：
两种方式可以下载源码，直接下载和使用git克隆
1. 直接下载，从GitHub直接一次性打包下载全部源码。
2. git克隆，使用git克隆代码仓库，后续可以不断拉取更新。

#文件夹结构
1. Code    FastCAE_Linux源码
2. OCC     OpenCASCADE7.2.0编译的第三方库，适用于Linux平台
3. VTK     VTK7.1.0编译的第三方库，适用于Linux平台
4. output  程序的编译输出
5. cgns     cgns第三方库，适用于Linux平台
6. quazip   压缩文件的第三方库
sh
#编译过程
1. 第一次编译需要运行 Run.sh，会对配置好软件运行所需要的环境

#重要脚本说明：
1. Run.sh                     下载完源码之后在本机配置生成开发环境，在一台机器上正确运行一次即可，若中间出现错误可重复运行
2. Create_Linux64_Project.sh  将Qt管理的工程文件转化为VS的工程文件，当工程设置出现修改的时候（*.Pro*.pri修改）需要重新运行
3. Copy_SOs.sh                将程序运行必需的dll拷贝到运行目录下
4. Copy_Pys.sh                将程序运行必需的python脚本拷贝到运行目录
5. _Create_Project.sh         存在于每个模块中，作用与Create_Linux64_Project.sh相同，区别在于各模块只是更新各自的VS工程文件
