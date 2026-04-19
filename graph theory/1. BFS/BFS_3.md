**5978. Đi trong mê cung**

Một mê cung bao gồm **R** hàng và **C** cột ô vuông. Một số ô có chướng ngại vật, không thể đi qua; một số ô là ô trống, có thể đi qua.

Cho một mê cung, hãy tìm số bước ít nhất cần thiết để đi từ góc trên bên trái đến góc dưới bên phải (dữ liệu đảm bảo chắc chắn có thể đi được).

Chỉ có thể di chuyển theo phương ngang hoặc phương dọc, không được đi chéo.

**Định dạng đầu vào:**
- Dòng đầu tiên là hai số nguyên **R** và **C**, đại diện cho chiều dài và chiều rộng của mê cung.
- Tiếp theo là **R** dòng, mỗi dòng có **C** ký tự, đại diện cho toàn bộ mê cung.
- Ô trống được biểu diễn bằng ký tự `.`, ô có chướng ngại vật được biểu diễn bằng ký tự `#`.
- Ô góc trên bên trái và góc dưới bên phải đều là `.`.

**Định dạng đầu ra:**
- In ra số bước ít nhất để đi từ góc trên bên trái đến góc dưới bên phải (tức là số ô trống ít nhất cần đi qua).
- Việc đếm bước bao gồm cả điểm xuất phát và điểm kết thúc.

**Phạm vi dữ liệu:**
1 ≤ R, C ≤ 40

**Ví dụ đầu vào:**
```
5 5
..###
#....
#.#.#
#.#.#
#.#..
```

**Ví dụ đầu ra:**
```
9
```