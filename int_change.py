a, b = 2, 30
# 使用位运算  就是相同为0  相异为1
z = format((a & 0xffffffff) ^ (b & 0xffffffff), 'b').count('1')
print(z)
