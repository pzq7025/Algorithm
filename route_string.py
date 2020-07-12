def rotateString(self, A: str, B: str) -> bool:
        return (A*2).find(B) > -1 and len(A) == len(B)  # 结果需要A==B的长度的原因是因为  A="aa" B="a" 这种包含的结果也会被查找到
