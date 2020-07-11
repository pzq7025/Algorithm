check = ["Hello", "Alaska", "Dad", "Peace"]
a, b, c, d = set('qwertyuiop'), set('asdfghjkl'), set('zxcvbnm'), []
for one in check:
    target = set(one.lower())
    if a & target == target or b & target == target or c & target == target:  # 与操作进行判断
        d.append(one)
print(d)
