# GAME TICTACTOE
## Mục lục:

### 1. Tổng quan về game:
#### 1.1 Giới thiệu:
#### 1.2 Ngôn ngữ và thư viện được dùng:


####
####
![alt](https://github.com/dupham2206/TicTacToe_LTNC/blob/master/pictures/demo.png)
#### Hình 1
####
![alt](https://github.com/dupham2206/TicTacToe_LTNC/blob/master/pictures/demo2.png)
#### Hình 2
####


## 1. Tổng quan về game:
### 1.1 Giới thiệu:
#### TICTACTOE là game được phát triển bởi Phạm Tiến Du, MSV 20020039 cho bài tập lớn môn LTNC INT2215 6. Game dựa trên luật cờ ca rô tuổi thơ. Board của game là một lưới ô vuông m * n. 2 người chơi sẽ lần lượt đánh "X" và đánh "O" cho đến khi đủ k "X" liên tiếp hoặc k "O" liên tiếp theo hàng dọc, ngang hoặc chéo thì người chơi đó thắng hoặc thua. Nếu không ai có thể đạt được như vậy thì trò chơi sẽ hòa. Trong game TICTACTOE này sẽ có 4 loại màn chơi: 3x3 với k = 3, 5x5 thì k = 4, 9x9 và 12x12 thì k = 12. Ngoài chế độ chơi 2 người với nhau, TICTACTOE còn được thiết kế để người chơi chơi với AI ở bàn 3x3 và 9x9.
  
### 1.2 Ngôn ngữ và thư viện được dùng:
#### TICTACTOE được viết bởi C++ cùng thư viện đồ họa SDL2. Ngoài ra TICTACTOE có cài thêm SDL2_image để render ảnh và SDL2_mixer để render âm thanh.
## 2. Chi tiết cài đặt:
### 2.1 Mô hình cài đặt:
#### Gồm 6 file, trong đó 1 file main và 5 file tương ứng với 5 đối tượng lớn trong game.
#### SDL_support: chứa những hàm mà SDL hỗ trợ người dùng như loadMedia, RenderMedia, logSDLError, initSDL, quitSDL. Đây đều là những hàm tham khảo trên slides của cô Châu và lazyfoo vào được sửa lại để phù hợp với project.SDL_support cũng chứa các biến toàn cục cần dùng như ScreenHeight, ScreenWidth...Ngoài ra SDL_support còn chứa rất nhiều enum để phân loại dữ liệu về sau. Ví dụ enum về type of button như ENTER_GAME(button dùng cho enter game), SQUARE_GAME(button dành cho hiển thị "X" và "O"). Đáng nhẽ chúng nên được thừa kế từ class cha(ví dụ vừa nãy class cha là button, class con là enterButton) nhưng em cảm thấy chúng không khác nhau nhiều lắm nên quyết định chia ít class hơn và sử dụng enum. Cuối cùng là SDL_support chứa hàm load toàn bộ data ảnh và âm thanh trước khi bắt đầu game. Em cũng khá phân vân khi gọi SDL_support là đối tượng.
