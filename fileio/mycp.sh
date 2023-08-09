#########################################################################
# File Name: mycp.sh
# Author: csgec
# mail: 12345678@qq.com
# Created Time: 2023年08月09日 星期三 19时36分46秒
#########################################################################
#!/bin/bash

echo $1 $2 > ./input.txt
#echo "\0" >> ./input.txt
#echo $2"\n" >> ./input.txt
#echo "\0" >> ./input.txt

gcc mycp.c -o mycp

./mycp

