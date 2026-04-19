# Dịch đề bài: Message Route (Tuyến tin nhắn)

**Mô tả bài toán:**

Mạng lưới của Syrjälä có **n** máy tính và **m** kết nối. Nhiệm vụ của bạn là xác định xem Uolevi có thể gửi tin nhắn đến Maija hay không, và nếu có thể, thì số lượng máy tính **tối thiểu** trên tuyến đường như vậy là bao nhiêu.

---

**Input (Đầu vào):**

- Dòng đầu tiên chứa hai số nguyên **n** và **m**: số lượng máy tính và số lượng kết nối. Các máy tính được đánh số từ 1, 2, ..., n. Máy tính của Uolevi là số **1** và máy tính của Maija là số **n**.

- Sau đó, có **m** dòng mô tả các kết nối. Mỗi dòng chứa hai số nguyên **a** và **b**: có một kết nối giữa hai máy tính này.

- Mỗi kết nối là giữa hai máy tính khác nhau, và giữa bất kỳ hai máy tính nào có **tối đa một** kết nối.

---

**Output (Đầu ra):**

- Nếu có thể gửi tin nhắn, đầu tiên in ra **k**: số lượng máy tính tối thiểu trên một tuyến đường hợp lệ. Sau đó, in ra một ví dụ về tuyến đường như vậy (in ra thứ tự các máy tính đi qua). Bạn có thể in ra bất kỳ lời giải hợp lệ nào.

- Nếu không có tuyến đường nào, in ra **"IMPOSSIBLE"**.

---

**Constraints (Ràng buộc):**
- 2 ≤ n ≤ 10⁵
- 1 ≤ m ≤ 2 × 10⁵
- 1 ≤ a, b ≤ n

---

**Ví dụ:**

**Input:**
```
5 5
1 2
1 3
1 4
2 3
5 4
```

**Output:**
```
3
1 4 5
```

**Giải thích ví dụ:** 
- Có 5 máy tính và 5 kết nối
- Tuyến đường ngắn nhất từ máy 1 đến máy 5 là: 1 → 4 → 5
- Số máy tính trên tuyến đường này là 3

---

**Bản chất bài toán:** Đây là bài toán tìm **đường đi ngắn nhất** trên đồ thị vô hướng từ đỉnh 1 đến đỉnh n (tính theo số đỉnh trên đường đi).