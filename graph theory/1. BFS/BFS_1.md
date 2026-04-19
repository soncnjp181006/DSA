# Xây dựng đường đi

**Giới hạn thời gian:** 1.00 s &nbsp;&nbsp; **Giới hạn bộ nhớ:** 512 MB

Byteland có $n$ thành phố và $m$ con đường nối giữa chúng. Mục tiêu là xây dựng thêm các con đường mới sao cho giữa hai thành phố bất kỳ đều có đường đi.

Nhiệm vụ của bạn là tìm số lượng đường đi tối thiểu cần xây dựng, và xác định xem nên xây những con đường nào.

## Đầu vào

Dòng đầu tiên chứa hai số nguyên $n$ và $m$: số lượng thành phố và số lượng đường đi. Các thành phố được đánh số từ $1, 2, \ldots, n$.

Sau đó là $m$ dòng mô tả các con đường. Mỗi dòng chứa hai số nguyên $a$ và $b$: có một con đường nối giữa hai thành phố đó.

Một con đường luôn nối hai thành phố khác nhau, và giữa hai thành phố bất kỳ có nhiều nhất một con đường.

## Đầu ra

Đầu tiên in ra một số nguyên $k$: số lượng đường đi cần xây dựng.

Sau đó, in ra $k$ dòng mô tả các con đường mới. Bạn có thể in ra bất kỳ phương án hợp lệ nào.

## Ràng buộc

- $1 \leq n \leq 10^5$
- $1 \leq m \leq 2 \cdot 10^5$
- $1 \leq a, b \leq n$

## Ví dụ

**Đầu vào:**
```
4 2
1 2
3 4
```

**Đầu ra:**
```
1
2 3
```