# Tô Màu Đồ Thị

Đây là chương trình C++ để tô màu đồ thị bằng ý tưởng thuật toán DSaTur.

## Cài đặt

1. Đảm bảo rằng bạn đã cài đặt trình biên dịch C++ trên máy tính của mình.
2. Sao chép toàn bộ mã nguồn vào tệp `main.cpp`.
3. Biên dịch mã nguồn bằng trình biên dịch C++ vd GCC (GNU Compiler Collection) (bản mới nhất) hoặc Clang (bản mới nhất)

## Sử dụng

1. Chuẩn bị các tệp dữ liệu đầu vào trong thư mục gốc hoặc đường dẫn tùy chọn. Các tệp dữ liệu đầu vào phải có định dạng `.txt` và tuân theo định dạng sau:
   - Dòng đầu tiên chứa hai số nguyên `n` và `m`, lần lượt là số đỉnh và số cạnh của đồ thị.
   - `m` dòng tiếp theo mô tả các cạnh của đồ thị, mỗi dòng chứa hai số nguyên biểu diễn một cạnh.
2. Đặt các tệp dữ liệu đầu vào trong thư mục gốc (Chung thư mục với file chạy `main`).
3. Mở Command Prompt (Window) hoặc Terminal(Linux) và di chuyển đến thư mục chứa file `main.cpp`.
4. Biên dịch chương trình bằng câu lệnh sau:
g++ main.cpp -o main
5. Chạy chương trình bằng câu lệnh sau:
./main
6. Kết quả sẽ được ghi vào các tệp đầu ra trong thư mục `output` và được đặt tên theo quy tắc `gc_n_mtomau.txt`, trong đó `n` và `m` là số đỉnh và số cạnh tương ứng của đồ thị đầu vào.
7. Kết quả cũng sẽ được kiểm tra bằng chương trình `check_valid_coloring.exe`. Hãy đảm bảo rằng bạn đã đặt file `check_valid_coloring.exe` trong thư mục `output`.

## Câu hỏi và Hỗ trợ

Nếu bạn có bất kỳ câu hỏi hoặc gặp vấn đề nào, vui lòng tạo một vấn đề mới trong phần "Issues" của dự án này. 

Lưu ý: -Đảm bảo rằng bạn đã có file `check_valid_coloring.exe`, các tệp test case `gc`, chương trình thực thi `main`  được đặt chung trong thư mục `output`. Bạn có thể download toàn bộ thư mục trong đường dẫn sau : https://bom.so/output, chúng tôi đã thiết lập sẵn vị trí các file output và check_valid. Chúng tôi khuyến nghị dùng VS code để chạy chương trình.

## Đóng góp

Nếu bạn muốn đóng góp vào dự án này, hãy làm theo các bước sau:

1. Fork dự án (https://github.com/yourusername/coloring/fork)
2. Tạo một nhánh tính năng mới (`git checkout -b feature/feature_name`)
3. Commit các thay đổi của bạn (`git commit -am 'Add some feature'`)
4. Push nhánh của bạn lên kho chứa (`git push origin feature/feature_name`)
5. Tạo một yêu cầu kéo mới (Pull Request) trên GitHub
