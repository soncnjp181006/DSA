# Building Teams (Xây dựng đội)

**Thời gian:** 1.00 giây | **Bộ nhớ:** 512 MB

Có $n$ học sinh trong lớp của Uolevi, và $m$ tình bạn giữa họ. Nhiệm vụ của bạn là chia các học sinh thành hai đội sao cho **không có hai học sinh nào trong cùng một đội là bạn bè**. Bạn có thể tự do chọn kích thước của các đội.

## Input

Dòng đầu tiên chứa hai số nguyên $n$ và $m$: số lượng học sinh và số lượng tình bạn. Các học sinh được đánh số $1, 2, \ldots, n$.

Sau đó, có $m$ dòng mô tả các tình bạn. Mỗi dòng chứa hai số nguyên $a$ và $b$: học sinh $a$ và $b$ là bạn bè.

Mỗi tình bạn là giữa hai học sinh khác nhau. Bạn có thể giả sử rằng có nhiều nhất một tình bạn giữa bất kỳ hai học sinh nào.

## Output

In ra một ví dụ về cách xây dựng các đội. Với mỗi học sinh, in ra "1" hoặc "2" tùy thuộc vào đội mà học sinh đó được phân vào. Bạn có thể in ra bất kỳ phương án hợp lệ nào.

Nếu không tồn tại lời giải, in ra "IMPOSSIBLE".

## Constraints (Ràng buộc)

- $1 \leq n \leq 10^5$
- $1 \leq m \leq 2 \cdot 10^5$
- $1 \leq a, b \leq n$

## Example (Ví dụ)

**Input:**
```
5 3
1 2
1 3
4 5
```

**Output:**
```
1 2 2 1 2
```

---

**Ghi chú:** Đây là bài toán kiểm tra đồ thị **hai phía (bipartite graph)**. Bạn cần tô màu đồ thị với 2 màu sao cho hai đỉnh kề nhau không cùng màu.