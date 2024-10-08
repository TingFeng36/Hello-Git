#!/bin/bash
# 检查输入文件是否存在
if [! -f "input.txt" ]; then
    echo "输入文件 input.txt 不存在。"
    exit 1
fi
sum=0
count=0
# 读取文件中的数字并计算总和和数量
while read -r num; do
    ((sum+=num))
    ((count++))
done < input.txt
# 计算平均值
if [ $count -gt 0 ]; then
    average=$(echo "scale=2; $sum / $count" | bc)
else
    average=0
fi
# 将总和与平均值输出到 JSON 文件
echo "{\"sum\":$sum,\"average\":$average}" > output.json
echo "总和和平均值已输出到 output.json 文件。"0