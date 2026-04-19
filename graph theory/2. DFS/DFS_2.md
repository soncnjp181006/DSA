# Chuyến Đi Tròn (Round Trip)

**Giới hạn thời gian:** 1.00 s  
**Giới hạn bộ nhớ:** 512 MB

ByteLand có $n$ thành phố và $m$ con đường nối giữa chúng. Nhiệm vụ của bạn là thiết kế một chuyến đi tròn bắt đầu từ một thành phố, đi qua hai hoặc nhiều thành phố khác, và cuối cùng quay trở lại thành phố bắt đầu. Mọi thành phố trung gian trên tuyến đường phải là khác nhau.

## Đầu vào

Dòng đầu tiên chứa hai số nguyên $n$ và $m$: số lượng thành phố và con đường.  
Các thành phố được đánh số $1, 2, \ldots, n$.

Sau đó, có $m$ dòng mô tả các con đường. Mỗi dòng chứa hai số nguyên $a$ và $b$: có một con đường nối giữa hai thành phố đó.

Mỗi con đường nối giữa hai thành phố khác nhau, và có tối đa một con đường giữa bất kỳ hai thành phố nào.

## Đầu ra

Đầu tiên in ra một số nguyên $k$: số lượng thành phố trên tuyến đường. Sau đó in ra $k$ thành phố theo thứ tự chúng sẽ được thăm. Bạn có thể in ra bất kỳ lời giải hợp lệ nào.

Nếu không tồn tại lời giải, in ra "IMPOSSIBLE".

## Ràng buộc

- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$

## Ví dụ

**Đầu vào:**
```
5 6
1 3
1 2
5 3
1 5
2 4
4 5
```

**Đầu ra:**
```
4
3 5 1 3
```