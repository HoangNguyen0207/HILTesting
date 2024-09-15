
1. Thư mục Example: project dùng thư viện api
2. Thư mục linux: chứa thư viện cho nền tảng linux
3. Thư mục window: chứ thư viện cho nền tảng window

4. Cách dùng lib 
- (ví dụ trong mainwindow.cpp của project example)
- include #include "fmsapi.h"
- khởi tạo ban đầu: FmsManager::Instance()->initialize();
- Chỉnh config file và copy vào thư mục chạy của project example
- gọi api (danh sách api trong file fmsapi.h)
