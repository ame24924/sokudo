import numpy as np
import time

N = 1000 # 下の表のNと一致
ma = np.random.rand(N, N).astype(np.float64)
t1 = time.time()
for i in range (0, int(1E+2)):
    np.dot(ma, ma)

t2 = time.time()
elapsed_time = t2-t1
print("elapsed_time = ", elapsed_time)


