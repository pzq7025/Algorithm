grid = [[1, 1, 0, 0], [0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 0, 1]]
m_x = len(grid)
m_y = len(grid[0])
count_x = [0] * m_x  # 记录x的值
count_y = [0] * m_y  # 记录y的值
for i in range(m_x):
    print(grid[i])
for i in range(m_x):
    for k in range(m_y):
        if grid[i][k] == 1:
            # 统计x和y的线性个数
            count_x[i] += 1
            count_y[k] += 1
count = 0
for i in range(m_x):
    for k in range(m_y):
        # 条件判定
        if grid[i][k] == 1:
            if count_x[i] > 1 or count_y[k] > 1:
                count += 1
print(count)
