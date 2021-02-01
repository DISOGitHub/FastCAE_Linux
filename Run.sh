#!/bin/bash

path=$(pwd)
sudo chmod 666 /etc/ld.so.conf
sudo echo $path/output/bin >> /etc/ld.so.conf
sudo chmod 644 /etc/ld.so.conf
sudo /sbin/ldconfig

cd Code 

chmod +x Copy_SOs.sh
./Copy_SOs.sh

chmod +x Copy_Pys.sh
./Copy_Pys.sh

chmod +x Create_Linux64_Project.sh
./Create_Linux64_Project.sh

cd $path/output/bin
if [ ! -e "FastCAE" ]
    then 
    echo 编译失败！
else
    echo 编译成功！
    chmod 775 FastCAE
	sudo /sbin/ldconfig
fi
