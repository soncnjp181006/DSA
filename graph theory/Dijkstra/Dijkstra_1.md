## **Mô tả đề bài**
Cho một đồ thị vô hướng có n (1 ≤ n ≤ 2500) đỉnh và m (1 ≤ m ≤ 6200) cạnh, hãy tìm đường đi ngắn nhất từ đỉnh s đến đỉnh t.

## **Định dạng đầu vào**
- Dòng đầu tiên chứa bốn số nguyên cách nhau bởi dấu cách: n, m, s, t.
- m dòng tiếp theo, mỗi dòng chứa ba số nguyên dương sᵢ, tᵢ, wᵢ (1 ≤ wᵢ ≤ 10⁹), biểu diễn một cạnh từ đỉnh sᵢ đến đỉnh tᵢ với độ dài wᵢ.

## **Định dạng đầu ra**
Một số nguyên biểu diễn độ dài đường đi ngắn nhất từ s đến t. Dữ liệu đảm bảo luôn tồn tại ít nhất một đường đi.

## **Ví dụ**

**Input:**
```
7 11 5 4
2 4 2
1 4 3
7 2 2
3 4 3
5 7 5
7 3 3
6 1 1
6 3 4
2 4 3
5 6 3
7 2 1
```

**Output:**
```
7
```

---

**Ghi chú:** Đây là bài toán tìm đường đi ngắn nhất cơ bản trên đồ thị vô hướng có trọng số. Với constraints như trên, bạn có thể sử dụng Dijkstra với heap hoặc SPFA để giải.