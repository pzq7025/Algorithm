import itertools
def cal_time_max():
    a = [5, 5, 5, 5]
    m = -1
    # itertools一个迭代工具   permutations是全排列的结果  product是笛卡尔积的结果
    # url：https://docs.python.org/zh-cn/3/library/itertools.html
    for h1, h2, m1, m2 in itertools.permutations(a):
        hour = h1 * 10 + h2
        min_ = m1 * 10 + m2
        cal_time = hour * 60 + min_
        if 0 <= hour <= 23 and 0 <= min_ <= 59:
            if cal_time > m:
                m = cal_time
    # divmod返回两个值，第一个是//的值  第二个是%的值
    # 其中*是将其获取出来
    return "{:02}:{:02}".format(*divmod(m, 60)) if m >= 0 else ""
    
# 函数结果
print(*divmod(100, 60))
print(*[1, 2, 35, 78])
