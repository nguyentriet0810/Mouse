# HƯỚNG DẪN SỬ DỤNG

## Các câu lệnh khởi tạo ban đầu
- Khởi tạo môi trường ảo
```
conda create --name mouse python==3.10.8
```
- Bật môi trường ảo để sử dụng
```
conda activate mouse
```
- Cài đặt các thư viện liên quan
``` 
pip install -r requirements.txt
```

## Cách xài Git (Trên CMD)
### Đẩy code lên Github
- Kiểm tra các branch trên máy Local
```
git branch
```
- Tạo một nhánh mới
```
git branch [new branch]
```
- Truy cập đến nhánh chỉ định
```
git checkout [new branch]
```
- Chọn tất cả file và lời nhắn
```
git add .
git commit -m "message"
```
- Đẩy code lên Github
```
git push --set-upstream origin [new branch]
```
### Xác nhận đẩy code lên branch mới trên Github
- Trên giao diện Github, chọn Compare & pull request
- Nhập các mô tả cho code mới đẩy lên
- Nhấp chọn Create pull request
- Lưu ý: Không tuỳ tiện bấm Merge pull request khi chưa có sự đồng ý của Leader

### Đồng bộ code từ Github về máy tính Local
- Chuyển về nhánh cần đồng bộ và nhập lệnh git pull
```
git branch [branch name]
git pull
```

### Tạo pull request thủ công
- Trên web Github, chọn mục Pull requests
- Ở góc trái trên cùng màn hình, chọn New pull request
- Ở mục "base:main <- compare:main", sửa lại mục compare nhánh mà chúng ta muốn pull
- Chọn Create pull request 
