check = "USA"
result = False
count = 0
# 统计大写字母
for i in check:
    if 0 <= ord(i) - 65 <= 26:
        count += 1
# 这个是统计结果判断
if count == 0 or count == len(check) or (count == 1 and 0 <= ord(check[0]) - 65 <= 26):
    result = True
print(result)
