### **Labyrinth (Mê cung)**

**Giới hạn:**
*   Thời gian: 1.00 giây
*   Bộ nhớ: 512 MB

**Mô tả bài toán:**
Bạn được cho một bản đồ mê cung, nhiệm vụ của bạn là tìm một đường đi từ điểm bắt đầu đến điểm kết thúc. Bạn có thể di chuyển sang trái, phải, lên và xuống.

**Dữ liệu vào (Input):**
*   Dòng đầu tiên chứa hai số nguyên $n$ và $m$: lần lượt là chiều cao và chiều rộng của bản đồ.
*   Tiếp theo là $n$ dòng, mỗi dòng gồm $m$ ký tự mô tả mê cung. Mỗi ký tự có thể là:
    *   `.` : Sàn (ô có thể đi qua).
    *   `#` : Tường (ô không thể đi qua).
    *   `A` : Điểm bắt đầu (Start).
    *   `B` : Điểm kết thúc (End).
*   Đảm bảo trong dữ liệu đầu vào có chính xác một ký tự `A` và một ký tự `B`.

**Dữ liệu ra (Output):**
*   Đầu tiên, in ra `"YES"` nếu tồn tại đường đi từ A đến B, và `"NO"` nếu ngược lại.
*   Nếu có đường đi, hãy in ra độ dài của **đường đi ngắn nhất** đó và mô tả đường đi dưới dạng một chuỗi ký tự bao gồm:
    *   `L` (Left - Sang trái)
    *   `R` (Right - Sang phải)
    *   `U` (Up - Lên trên)
    *   `D` (Down - Xuống dưới)
*   Bạn có thể in ra bất kỳ lời giải hợp lệ nào (nếu có nhiều đường đi ngắn nhất).

**Ràng buộc (Constraints):**
*   $1 \le n, m \le 1000$

**Ví dụ (Example):**

*Dữ liệu vào:*
```text
5 8
########
#.A#...#
#.#.##B#
#......#
########
```

*Dữ liệu ra:*
```text
YES
9
LDDRRRRRU
```

---
Đây là bài toán tìm đường đi ngắn nhất trên đồ thị (cụ thể là lưới 2 chiều). Vì các bước đi đều có trọng số bằng nhau (mỗi bước đi tốn 1 đơn vị), thuật toán tối ưu nhất để giải quyết bài này là **BFS (Breadth-First Search - Duyệt theo chiều rộng)**. Sơn nhớ lưu lại vết (parent) hoặc hướng đi để reconstruct (dựng lại) đường đi sau khi tìm thấy đích nhé.