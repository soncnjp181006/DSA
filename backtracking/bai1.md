**Các tổ hợp dấu ngoặc hợp lệ**

Viết hàm `BracketCombinations(num)` nhận vào `num` là một số nguyên lớn hơn hoặc bằng 0, và trả về số lượng các tổ hợp hợp lệ có thể được tạo thành với `num` cặp dấu ngoặc đơn.

Ví dụ, nếu đầu vào là 3, thì các tổ hợp có thể có của 3 cặp dấu ngoặc đơn là:
- `()()()`
- `()(())`
- `(())()`
- `((()))`
- `(()())`

Tổng cộng có 5 tổ hợp khi đầu vào là 3, vì vậy chương trình nên trả về 5.

**Ví dụ:**

```
Input: 3
Output: 5
```

```
Input: 2
Output: 2
```

(Lưu ý: Với input = 2, các tổ hợp hợp lệ là: `()()` và `(())`)

---

**Ghi chú:** Đây là bài toán kinh điển về **số Catalan** (Catalan Numbers).