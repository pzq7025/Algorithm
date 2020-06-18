matrixx_ = [
    [14, 15, 100, 9, 3],
    [32, 1, 9, 3, 5],
    [15, 29, 2, 6, 8, 7],
    [7, 10]
]
def spare_(matrix):
    # 求解文本矩阵的相似度：交集/并集的结果为相似度
    matrix = [set(i) for i in matrix]
    final_result = []
    for i in range(len(matrix)):
        for k in range(i + 1, len(matrix)):
            # 如果有交集才进行并集运算
            union = matrix[i] & matrix[k]
            if len(union) > 0:
                combine = matrix[i] | matrix[k]
                # 这里需要注意一下精度的问题
                num_detail = int(len(union) / len(combine) * 10 ** 5)
                if num_detail % 10 >= 5:
                    num_detail = (num_detail // 10 * 10 + 10) / (10 ** 5)
                else:
                    num_detail = num_detail / (10 ** 5)
                result = f"{i},{k}: {num_detail:.4f}"
                final_result.append(result)
    print(final_result)
spare_(matrix_)
