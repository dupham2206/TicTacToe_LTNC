# GAME TICTACTOE
## Mục lục:

##### 1. Tổng quan về game:
###### --- [1.1 Giới thiệu:](#introduction)
###### ---[1.2 Kiến thưc áp dụng:](#knowledge)
###### ---[1.3 Chia sẻ về quá trình làm game:](#share)
##### 2. Cài đặt chương trình:
###### --- [sdlsupport.h](#sdlsupport.h)
###### --- [button.h](#button.h)
###### --- [pregame.h](#pregame.h)
###### --- [game.h](#game.h)
###### --- [AI.h](#AI.h)
###### --- [AIextendEasy.h](#AIextendEasy.h)
###### --- [AIextendMedium.h](#AIextendMedium.h)
###### --- [AIextendHard.h](#AIextendHard.h)
###### --- [main.cpp](#main.cpp)

##
------------------------------------------------
------------------------------------------------
------------------------------------------------



####
![alt](https://github.com/dupham2206/TicTacToe_LTNC/blob/master/pictures/demo.png)
#### Hình 1
####
![alt](https://github.com/dupham2206/TicTacToe_LTNC/blob/master/pictures/demo2.png)
#### Hình 2
####


## 1. Tổng quan về game:
### 1.1 Giới thiệu: <a name="introduction"></a>
#### [DEMO GAME TRÊN YOUTUBE](https://www.youtube.com/watch?v=tYu1I2Vqdb8&t=61s)
TICTACTOE là game được phát triển bởi Phạm Tiến Du, MSV 20020039 cho bài tập lớn môn LTNC INT2215 6.
Game dựa trên game cờ ca rô tuổi thơ. Board của game là một lưới ô vuông m * n.
Game dùng duy nhất chuột để chơi.
2 người chơi sẽ lần lượt đánh "X" và đánh "O" cho đến khi đủ k "X" liên tiếp hoặc k "O" liên tiếp theo hàng dọc, ngang hoặc chéo thì người chơi đó thắng hoặc thua. Nếu không ai có thể đạt được như vậy thì trò chơi sẽ hòa.
Trong game TICTACTOE này sẽ có 4 loại màn chơi: 3x3 với k = 3, 5x5 thì k = 4, 9x9 và 12x12 thì k = 12. Ngoài chế độ chơi 2 người với nhau, TICTACTOE còn được thiết kế để người chơi chơi với AI ở bàn 3x3 và 9x9, 12x12 với các mức độ chơi easy, medium, hard.

### 1.2 Kiến thức áp dụng: <a name="knowledge"></a>
####
- Ngôn ngữ lập trình C++.
- Thư viện đồ họa SDL2 qua slide cô Châu và lazyfoo.
- Kiến thức về OOP: lớp, đối tượng, tính đóng gói, tính thừa kế, lớp trừu tượng. (tham khảo qua giáo trình OOP_2013 của ĐHCN-ĐHQGHN)
- Kiến thức về Trí tuệ nhân tạo: các chiến lược tìm kiếm có đối thủ: thuật toán minimax, prunning alpha-beta.(tham khảo qua google, giáo trình trí tuệ nhân tạo)
- Kiến thức về game cờ caro: Để viết hàm đánh giá tốt cho AI trong game.
### 1.3 Chia sẻ về quá trình làm game: <a name="share"></a>
#### Mở đầu làm game và chọn đề tài:
#####
- Em không thích làm game lắm và sẽ không có dự định theo nghiệp game sau này. Vì vậy game của em có khác biệt so với các bạn 1 tý. Thay vì chăm chút đồ họa, em coi trọng kiến thức học được và áp dụng vào game nhiều hơn.
- Tầm tuần 5, 6 Vừa lúc đấy thì em có được tìm hiểu qua được thuật toán A*, minimax trong môn trí tuệ nhân tạo. Nên em quyết định làm game cờ ca rô có AI.
- Quá trình làm game thì khá đơn giản. Ngoài cài mấy cái SDL lằng nhằng ra thì mọi thứ rất nhanh gọn nhẹ. Vì em cũng có nền tảng lập trình từ cấp 3, game cũng không có đồ họa gì nhiều mà khó khăn cả nên em có thể tự tư duy viết game cờ ca rô ban đầu chưa có AI.
#### Giai đoạn tìm hiểu và viết lại theo OOP:
#####
- Em phát hiện là code mình viết khá khó phát triển. Việc thêm các thành phần game vào dần cũng như tính năng khá mệt. Em nhớ đến lập trình hướng đối tượng. Em cũng đã tìm hiểu sơ qua từ trước những chưa có cơ hội để áp dụng và hiểu sâu. Vì vậy em in giáo trình OOP ra đọc.
- Bỏ qua chương Java để đọc những chương lý thuyết là chính, em khá hiểu dù chưa dám chắc mình hiểu sâu. Rồi em quay lại áp dụng cho game của mình. Cách coi từng thành phần là đối tượng, rồi game chỉ là các đối tượng gọi nhau, hay là cách đóng gói, kế thừa, đa hình, lớp trừu tượng đều là điều hay ho và cần thiết lúc này đối với em.
- Đọc xong lý thuyết rồi em quay lại áp dụng oop khá cồng kềnh, thiết kế chương trình chưa hoàn hảo. Nhưng dần dần tự bơi thì cũng bơi được. Em cảm thấy thiết kế chương trình bây giờ của em khá gọn, dễ hiểu. Mọi thứ đều được chia ra làm các đối tượng, quan hệ HAS A, IS A rõ ràng. Chỉ 1 file sdlsupport là em khá phân vân. Trong file đấy sẽ chứa load data ảnh, nhạc, hàm init, quit SDL... Em nghĩ sẽ tốt hơn nếu coi nó là biến toàn cục thay vì cho vào class và đi theo class.
- Lúc này game sẽ có 2 phần là preGame(menu) và game. preGame sẽ có chọn map chơi, chọn chơi với AI hoặc 1 player khác(lúc này chưa tích hợp AI) và sound cùng button enter to game. Game sẽ có board để chơi, button restart game và  button return menu. Sau này preGame và game sẽ có thê bảng thông báo. Pregame sẽ có phần chọn chế độ hard, medium, easy của AI.
#### Phát triển minimax 3x3
#####
- Thiết kế xong chương trình thì lại đến phần khó nhất là làm AI cho game từ minimax. Trước tiên ta làm minimax cho map 3x3 trước vì nó khá dễ.
- Nói qua về thuật toán minimax(em nghĩ em diễn đạt khó hiểu, cô có thể tra google dễ hiểu hơn) thì nó là 1 thuật toán trí tuệ nhân tạo trong các phương pháp tìm kiểu giải pháp có đối thủ. Minimax có thể áp dụng trực tiếp cho nhiều trò chơi đối kháng như cờ ca rô, cờ vua, cờ tướng. Minimax là 1 thuật toán thiên về backtracking, nó sẽ "đánh thử" và đánh giá nước đi. Coi mỗi trạng thái của bàn cờ là 1 đỉnh, minimax sẽ dfs từ đỉnh đầu tiên là bàn cờ ca rô trống không tới trạng thái kết thúc.
- Trạng thái kết thúc là khi thắng thua hoặc hòa. Mỗi lần ta sẽ tính value của mỗi đỉnh thông qua max và min của các đỉnh con, tức là các trạng thái đánh cờ tiếp theo. Lấy max khi nước tiếp theo là nước đánh của AI, lấy min khi nước tiếp theo là nước của người chơi. Vì value sẽ phản ánh khả năng thắng thua của bàn chơi. Value càng lớn thì ta có khả năng thắng càng cao và ngược lại. Value = 0 tức là 2 người khả năng hòa. Vì vậy khi đến nước AI đánh, ta phải lấy max, tức là đánh sao cho vào trạng thái tốt nhất, và cũng tương tự thế ta sẽ lấy min khi nước cờ của đối thủ.
- Về cắt cụt alpha-beta(em nghĩ cô cũng nên google alpha beta prunning), nó cũng như kiểu cắt nhánh cận trong backtrack. Giả sử nút A cần lấy max, ta tính được xong con B1 của A và đang tính con B2 của A. Ta tính được cháu C1 là con của B2 có value(C1) < value(B1) thì ta sẽ không phát triển B2 nữa. Vì B2 lấy min nên value(B2) < value(C1) < value(B1). Mà A lấy max nên kiểu gì cũng ít nhất lấy B1 chứ không lấy B2.
- Bình thường, value phải tự đánh giá qua kinh nghiệm của con người(thế mới đúng trí tuệ nhân tạo) nhưng vì 3x3 thì độ phức tạp để duyệt cây trò chơi là O(9!)(nước đầu có 9 cách chọn, nước sau có 8 cách chọn...) nhưng do ta cho người chơi đi trước(nên chỉ còn 8!), cắt cụt alpha beta và cả có những nước đi đến nước thứ 5 là hết ván nên chỉ max có 8000 lần duyệt hàm dfs. Giảm 5 lần so với cây trò chơi dự kiến.
- Phần alpha beta em có tham khảo cách viết trên mạng, vì em viết theo ý hiểu của em về alpha beta thì độ phức tạp tăng gấp đôi.
#### Phát triển minimax 9x9
#####
- Đến phần AI trên map lớn hơn. Lúc này không thể xây cả cây tìm kiếm như map 3x3 vì độ phức tạp của cây tìm kiếm là O((m*n)!) với m, n là kích thước bảng. Với 3x3 là 9! còn có thể chấp nhận được. chỉ 4x4 thôi cũng là 16! rồi. Dù cắt cụt alpha-beta cũng chỉ giảm đi khoảng 2-4 lần tùy trường hợp.
- Ta chỉ xây được đến depth nào đó rồi ta phải đánh giá cái trạng thái bàn cờ đấy có lợi cho ai như thế nào thông qua value. Giá trị càng dương thì càng có lợi cho AI.
- Lúc đầu em viết 1 hàm đánh giá khá ngây thơ do cũng chưa chơi cờ ca rô giỏi. Hàm đánh giá lúc đầu chỉ đơn thuần đếm cả đường ngang, chéo dọc ở mỗi ô rồi nhân vào nhau(vì ưu tiên nước đôi). Nhưng vì chọn depth = 5 nên nó vẫn chạy đủ nhiều trạng thái để đánh thông minh. Điều này khá là vui.
- Nhưng user experience thì khá tệ. Map 9x9 thì độ phức tạp là 81x80x79x78x77xđộ phức tạp hàm đánh giá(cứ cho trung bình 5 phép tính) > 10^10. Theo kiến thức CP cũ em được biết, 1 giây chạy khoảng 10^8 phép tính đơn giản. Vậy là AI sẽ mất 100s cho 1 nước đi. Cắt cụt alpha-beta giảm rất tốt nhưng cũng chạy tận 15 - 30s. Đã chờ lâu rồi, mà còn spam cái, game sẽ lại not responding. Không còn gì cáu hơn nữa.
- Lúc này em nghĩ ra 2 cách giảm độ phức tạp. Thứ nhất là giảm độ sâu của cây tìm kiếm. Nhưng vì hàm đánh giá của em khá kém nên giảm xuống độ sâu depth = 4 thì đánh như đánh bừa. Thứ 2 là cắt bớt nhánh phát triển mỗi bước. Ví dụ thay vì phát triể 80 nước, mình đánh giá 40 nước tốt nhất rồi phát triển 40 nước đấy.
- Em tập trung giảm độ phức tạp theo cách 2: cách cắt bớt nhánh phát triển trong thời gian rất lâu và không quan tâm lắm tới việc giảm độ sâu vì em tin tưởng cách 2 hơn. Em tập trung cả việc nâng cao kiến thức đánh cờ cả rô nữa. Vì mình cần đánh giá bằng trí tuệ của con người trong bàn cờ ca rô. Mình đánh cờ ca rô đã giỏi là khó, nhưng truyền đạt suy nghĩ của mình để máy tính đánh giá bàn cờ ca rô thì khó hơn nhiều lần.
- Việc cắt nhánh là 1 con đường khá sai. Có thể 1,2 nước đầu đánh kém hơn vài nước còn lại nhưng về sau có thể tốt hơn. Nhưng vừa thấy kém đi là mình có thể loại nó để phát triển các nhánh khác. Chưa kể mỗi 1 nút, ta phải đánh giá hết các nút con, sau đó sort lại vào phát triển tầm 1/3 số nút. Độ phức tạp giảm thực sự cũng không nhiều, vẫn chạy từ 5-10s mà máy đánh cực kém. Nhưng thay vì nghi ngờ cắt nhánh, em lại nghi ngờ hàm đánh giá em viết kém. Cứ thế sửa đi sửa lại hàm đánh giá mãi mãi chả khá lên nhiều.
- Cho đến tuần 14, em nhớ lại về việc giảm độ sâu. Em thử bỏ cắt nhánh và giảm độ sâu xuống 4. AI đánh cực kì tốt. Hiếm khi nào em đổi mood vui sướng nhanh như vậy, vì đã tuyệt vọng vài tuần rồi khi có những ngày ngồi viết đi viết lại hàm đánh giá từ sáng tới tối.
- Còn về việc sau giảm độ sâu xuống 4 lại chạy tốt. Bởi nó không phát triển thiếu nhánh nào. Chỉ là nó không phát triển đủ sâu. Dù thiếu giảm độ sâu là thiệt thòi lớn, nhưng với hàm đánh giá tốt thì đánh vẫn xuất sắc và còn nhanh nữa. Lúc này độ phức tạp chỉ đơn thuần là O(80x79x78x77x2). Đây chỉ là dựa trên tính toán. Còn thực tế cắt cụt rất nhiều, 2 cũng chỉ là con số ước lượng cho hàm đánh giá, còn bản chất thì nhiều nút đánh giá rất ít hoặc không đánh giá. Và hơn thế nữa chơi map 12x12 trải nghiệm người dùng vẫn rất tốt.
#### Chi tiết hàm đánh giá - thứ tự hàm nhất của game này.
#####
- Nhắc lại rằng, ta đánh giá là đánh giá 1 cái bàn cờ xem cái trạng thái đấy của bàn cờ đang có lợi cho ai. Càng đánh giá ra dương nhiều thì mình nhiều cửa thắng, ngược lại thì mình nhiều cửa thua.
- Đầu tiên, ta xét từng ô 1. Với mỗi ô khác ô trống, ta sẽ khởi tạo 1 biến curvalue. Sau đó ta sẽ đếm giá trị từ các ô trên 2 đường chéo và 2 đường thẳng đi qua nó qua hàm cntContinue. Nếu cntContinue trả về giá trị khác 0, ta nhân nó vào curValue. Việc nhân này giúp đánh giá cao nước đôi, nước ba... Cuối cùng ta sẽ cộng vào value tổng nếu nó là nước đi của AI, -value tổng nếu nó là nước đi của người chơi.
```sh
int AI::heuristicValue(){
    int value = 0;
    for(int x = 1; x <= sizeOfBoard.second; ++x){
        for(int y = 1; y <= sizeOfBoard.first; ++y){
            if(boardState[x][y] == 1){ // STATE_PLAYER = 1
                int curValue = 1;
                for(int i = 0; i < 4; ++i){
                    int lengthCanBeWin = cntContinue(x, y, dx[i], dy[i], 1);
                    if(lengthCanBeWin) curValue *= lengthCanBeWin;
                }
                if(curValue != 1) value -= curValue;
            }
            if(boardState[x][y] == 2){ // STATE_AI = 2
                int curValue = 1;
                for(int i = 0; i < 4; ++i){
                    int lengthCanBeWin = cntContinue(x, y, dx[i], dy[i], 2);
                    if(lengthCanBeWin) curValue *= lengthCanBeWin;
                }
                if(curValue != 1) value += curValue;
            }
        }
    }
    return value;
}
```
- Tiếp theo là về hàm cntContinue. Cách tính của hàm khá đơn giản. Ta có biến cntWin là để đếm giá trị. Ta sẽ loang theo hướng dx, dy cho sẵn theo 2 đầu của hướng dx, dy. 
- Giả sử ta đánh X. Nếu ô tiếp theo gặp X thì ta +3 vào cntWin. Nếu ta gặp một ô trống chưa đánh. Ta +1 vào cntWin và đánh dấu đã gặp ô trống để Ta gặp ô trống thứ 2 sẽ dừng không duyệt nữa. Vì đến ô trống thứ 2 sẽ không gây nguy hiểm. x_xxx hoặc (x_xxo và có 1 nước đôi hướng khác) thì sẽ khá nguy hiểm nhưng x_x_xo thì chả có tẹo nguy hiểm, chặn sau được.
- Nếu ta gặp block(tường, ô đã đánh O) thì ta sẽ dừng lại và đánh dấu gặp block. Để rồi cuối cùng, ta xét các trường hợp có 2 block, 1 block, không có block nào.
- Đối với mỗi trường hợp, ta lại xét cntWin, rồi lại ánh xạ lên một giá trị khác rồi mới trả về. Ví dụ block = 2, cntWin >= 13, 13 tức là trường hợp 2 O vây 4 X và 1 cách(oxxx xo chẳng hạn), trường hợp nguy hiểm phải chặn ngay không thua, nên return 16. Còn cntWin = 11, block = 2 là trường hợp 3 dấu X và 2 dấu cách, chưa nguy hiểm lắm, ta trả về 2. Còn lại nước đấy không thể phát triển hoặc kém phát triển(hay đánh tù) ta trả về 0. Tương tự đối với block = 0, = 1.
- Nghe thì có vẻ nhiều đoạn vô lý, nhưng em đã suy nghĩ kĩ và cũng đã test với nhiều số, nhiều ánh xạ. Đoạn trước dùng nhân cntContinue, hay đoạn này ánh xạ cntWin đến nay chạy vẫn tốt. Nó vẫn làm nổi bật nên những nước đi khó, khoai nhất.
- Khi bắt tay vào viết hàm đánh giá thì mới biết viết khó như nào ạ. Chơi giỏi không là gì so với việc truyền tốt ý tưởng cho máy tính hiểu. Hàm đánh giá này còn nhiều chỗ có thể chưa tốt, nhưng đặc tính của máy tính không phải là thông minh, mà là làm tỷ phép tính trong 1 giây mà. Ta vẫn được xét hết các trường hợp, rồi mới tổng kết lại. Vi vậy, điều đó mới làm nên hàm đánh giá được trạng thái bàn cờ tốt.
- Em để hàm đánh giá tốt nhất là Hard. Chế độ chơi medium thì em chỉnh sao cho AI chỉ biết chặn, không biết tấn công. Chế độ chơi easy thì em return thẳng cntWin, không ánh xạ ra giá trị tốt hơn. Cả 3 chế độ đều được viết vào 1 class riêng rồi kế thừa qua hàm cntContinue.
```sh
    int cntContinue(int x, int y, int dx, int dy, int statePlayer){
        int cntWin = 0, block = 0;
        bool HaveEmpty = 0;
        for(int i = 1; i <= 4; ++i){
            if(!checkInsideBoard(x + i * dx, y + i * dy)){
                block++;
                break;
            }
            if(boardState[x + i * dx][y + i * dy] == statePlayer) cntWin += 3;
            if(boardState[x + i * dx][y + i * dy] == STATE_EMPTY){
                if(HaveEmpty == 0){
                    cntWin++;  HaveEmpty = 1;
                }
                else break;
            }
            if(boardState[x + i * dx][y + i * dy] == 3 - statePlayer){
                block++;
                break;
            }
        }
        HaveEmpty = 0;
        for(int i = -1; i >= -4; --i){
            if(!checkInsideBoard(x + i * dx, y + i * dy)){
                block++;
                break;
            }
            if(boardState[x + i * dx][y + i * dy] == statePlayer) cntWin += 3;
            if(boardState[x + i * dx][y + i * dy] == STATE_EMPTY){
                if(HaveEmpty == 0){
                    cntWin++;   HaveEmpty = 1;
                }
                else break;
            }
            if(boardState[x + i * dx][y + i * dy] == 3 - statePlayer){
                block++;
                break;
            }
        }
        cntWin += 3;
        if(block == 2){
            if(cntWin >= 13) cntWin = 16;
            else if(cntWin >= 11) cntWin = 2;
            else return 0;
        }
        if(block == 1){
            if(cntWin >= 11) cntWin = 16;
            else if(cntWin >= 10) cntWin = 2;
            else return 0;
        }
        if(block == 0){
            if(cntWin >= 13) cntWin = 2048;
            else if(cntWin >= 11) cntWin = 32;
            else if(cntWin >= 8) cntWin = 2;
            else return 0;
        }
        if(statePlayer == 1) return cntWin * 2;
        else return cntWin;
    }
```
## 2. Cài đặt chương trình:
### sdlsupport.h: <a name="sdlsupport.h"></a>
#### Chứa những biến toàn cục liên quan đến window và data, những hàm mà SDL2 support, hàm load hình ảnh và âm thanh ,nhiều enum đánh dấu đặc điểm dữ liệu.
- loadMedia(): load 1 ảnh [tham khảo lazyfoo rồi chỉnh sửa lại].
- RenderMedia(): render 1 ảnh [tham khảo lazyfoo rồi chỉnh sửa lại].
- logSDLError(): thông báo lỗi và xem có quit chương trình hay không [copy slide cô Châu].
- initSDL(): khởi tạo SDL2 [copy slide cô Châu].
- quitSDL(): thoát SDL2 [copy slide cô Châu].
- dataImage[20][20]: data ảnh, đều là những ảnh tự thiết kế. Cả 2 chiều dữ liệu đều là đánh dấu loại ảnh.(về sau sẽ truy cập bằng qua enum)
- dataChunk[10]: data nhạc, gồm click, endGame và error(video demo có tiếng).
- SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE: Thông tin window.
- các loại enum: phân biệt tất cả các trạng thái game, trạng thái pregame, loại button, trạng thái button, trạng thái bảng thông báo...
- setData(): load trước tất cả các ảnh, nhạc. Nếu vừa chơi vừa load rất tốn dữ liệu.

### button.h:  <a name="button.h"></a>
#### Chứa class Button. Bất kì đối tượng nút nào để ấn và tạo sự kiện trong game đều tạo từ class Button.
####
**private:**
- int typeOfButton: loại button, ví dụ như button hiện thị "X","O", button restart, button returnMenu sẽ được ghi lại qua typeOfButton với những thông số khác nhau để đánh dấu(qua enum ở SDLsupport)
- int stateButton: chỉ các button square dùng để đánh đấu là ô đấy có X, có O hay trống. Nhưng vì hồi đấy chưa biết đến kế thừa nên biến này vẫn xuất hiện.
- point positionTopLeft: đánh dấu vị trí trên cao cùng bên trái của button.
- pair lengthOfButton: ghi lại độ rộng và dài của button

(hàm ở trong private là hàm hỗ trợ các hàm public bên ngoài).
- bool checkInsideButton(int x,int y): trả về 1 nếu điểm (x,y) nằm trong button. Hỗ trợ check sự kiện ấn click.
####
**public:**
- void setTypeOfButton(int type): set type từ bên ngoài
- void setPositionTopLeft(int _x,int _y):
- void setLengthOfButton(int lengthX, int lengthY):
- void setStateButton(int state):

- SDL_Point getPositionTopLeft(): trả về điểm topLeft
- pair<int,int> getLengthOfButton():
- int getStateButton():

- bool handleEventButton(): check sự kiện button click, nếu button đấy bị ấn sẽ thay đổi state
- render(): render ảnh của button. Có thể render có khung hoặc không(nút X,O có khung bên ngoài), có thể renderPresent lại luôn hay không(nhằm tạo thẩm mỹ).

### pregame.h: <a name="pregame.h"></a>
#### Chứa menu:
#####
+ tiêu đề game(trên cùng)
+ bảng thông báo cho người chơi(bulletinBoard ở góc phải trên): Thông báo các trạng thái lỗi.
+ tiêu đề "choose map options": trước khi vào chơi phải chọn map sẽ chơi.
+ các button map để chọn ngay dưới tiêu đề(3x3, 5x5, 9x9, 12x12).
+ tiêu đề "choose player options"; trước khi vào chơi phải chọn chơi với người hay chơi với AI.
+ các button để chọn ngay dưới tiêu đề(play with player, play with AI)
+ enterGame: button vào game
+ sound: trạng thái âm thanh đang bật hay tắt
+ easy, medium, hard: các mức chọn mức độ khó của AI. Chỉ xuất hiện khi ấn vào map 9x9 hoặc 12x12 và ấn chọn chơi với AI.
####
*cài đặt:*
####
**private:**
- pair<int, int> choiceSizeOfBoard[4]: những sự lựa chọn về map có những size gì(ví dụ map 3x3 thi giá trị sẽ là pair {3,3}.
- int choiceNumberOfPieceConsecutiveToWin[4]: những sự lựa chọn về map bao quân X/O liên tiếp để thắng/thua(ví dụ 12x12 cần 5, 5x5 cần 4
- Button ChoiceMap[4]: 4 button map để chọn
- Button ChoicePlayerAI[2]: 2 button chọn chơi với người hay AI.
- Button ChoiceLevel[3]: 3 level đánh dấu độ khó của AI khi chơi map 12x12 or 9x9.
- Button EnterToGame:
- Button ChoiceSound: button để chọn nhạc on hay off.
- int currentButtonChoosingMap = NOT_CHOOSE: map hiện tại đang chọn, khởi tạo là chưa chọn.
- int currentButtonChoosingPlayerAI = STATE_EMPTY: player hay AI đang chọn, khởi tạo là chưa chọn.
- int currentLevelChoosing = NOT_HAVE_ANYTHING: level of AI(hard, medium, easy), khởi tạo là chưa có gì.
- int stateOfBulletinBoard = EMPTY: trạng thái bảng thông báo để hiển thị ra theo ý muốn, khởi tạo là trống.
- int currentSound = ON: âm thanh hiện tại, khởi tạo là đang bật.
- (hàm ở trong private là để hỗ trợ các hàm ở public)
- void setUpForInfoOfMap(): để điền thông tin vào 2 biến đầu tiên ở trên. Ví dụ map 3x3 có chiều rộng 3, chiều dài 3, cần 3 quân để thắng.
- void setUpForButtonMap(): set up tọa độ, chiều dài, loại, trạng thái cho button map.
- void setUpForButtonPlayerAI(): set up tọa độ, chiều dài, loại, trạng thái cho button PlayerAI.
- void setUpForButtonEnterGame(): set up tọa độ, chiều dài, loại, trạng thái cho button enter.
- void setUpForButtonChoiceLevel(): set up tọa độ, chiều dài, loại, trạng thái cho button chọn level.
- void setUpForButtonChoiceSound(): set up tọa độ, chiều dài, loại, trạng thái cho button chọn tắt bật nhạc.
- void checkEventForMapButton(): check xem có sự kiện và đổi trạng thái cho button map.
- void checkEventForPlayerAIButton: tương tự trên.
- void checkEventForEnterButton: tương tự trên.
- void checkEventForLevelButton: tương tự trên.
- void checkEventForSoundButton: tương tự trên.
####
**public**
- pair<int,int> getChooseSizeOfBoard(): lấy thông tin dài rộng của bàn chơi. Ví dụ map 3x3 có chiều rộng 3, chiều dài 3.
- int GetChoiceNumberOfPieceConsecutiveToWin(): Thông tin số quân liên tiếp để thắng.
- int getAIorPlayer(): trả về đánh với AI hay đánh với player.
- int getLevel(): trả về level người chơi chọn.
- int getStateSound(): trả về âm thanh tắt hay bật.
- void setUpPreGame(): setUp tất cả về mặt giao diện và trạng thái. Hàm này sẽ gọi tất cả các hàm "setUp" trong private ở trên.
- void handleEvent(): check sự kiện cho preGame. Gọi tất cả các hàm check sự kiện trong private ở trên.
- void render(): in ra cái preGame.

### game.h:   <a name="game.h"></a>
#### Chứa game gồm:
#####
+ m*m ô button(trống lúc đầu) là board để đánh. m phụ thuộc vào preGame người chơi chọn map gì.
+ bảng thông báo cho người chơi(bulletinBoard ở góc phải trên): Thông báo lượt của ai, kết thúc trận đấu.
+ ảnh thông báo ai thắng(ngay dưới bảng thông báo, kết thúc game mới có).
+ button restart.
+ button return Menu(Pregame).
####
*cài đặt:*
####
**private:**
- Button square[20][20]: các button hiển thị trống, "X", "O".
- Button restartButton:
- Button returnMenuButton;
- AI* botPlayer: tạo đối tượng trí tuệ nhân tạo để đánh với người chơi.
- int stateOfBulletinBoard: trạng thái bảng thông báo để in ra theo đúng ý muốn.
- int stateSound: trạng thái nhạc tắt hay bật.
- int numberOfPieceConsecutiveToWin: số quân liên tiếp để thắng/thua(3,4,5,5).
- pair<int,int> sizeOfBoard: kích cỡ bàn chơi(3x3,5x5,9x9,12x12).
- pair<int,int> squareHavingPlayed: cái ô vừa đánh, đánh dấu lại để hiện thị khác màu để dễ nhìn.
- int turnOfPlayer = FIRST_PLAYER: lượt chơi của ai(người thứ nhất, người thứ 2, nếu có AI thì AI luôn đánh sau và là người thứ 2).
- int winner = NOT_ENDGAME: biến đánh dấu người 1 hay người 2 thắng hay hòa. Trạng  thái ban đầu là trận đấu chưa kết thúc.
- bool isPlayWithAI: chơi với người hay chơi với AI.
- const int directX[10] = {1, 1, 0, 1, 0, -1, -1, -1}: các hướng để duyệt(loang) theo chiều ngang.
- const int directY[10] = {1, 0, 1, -1, -1, 1, 0, -1};
- bool checkFullLandOfPlayer(int posX, int posY, int dX, int dY, int landOfPlayer): check xem ô (x,y) duyệt theo hướng (dx,dy) đã đủ số ô thuộc lượt của landOfPlayer chưa. Nếu đủ rồi tức là người chơi landOfPlayer thắng và trả về 1.

- void setAttributeForAllSquares(): set up topLeft, lenght button giống trong preGame.
- void setAttributeForRestartButton():
- void setAttributeForReturnMenuButton():
- void changeTurn(SDL_Renderer* renderer): thay đổi lượt chơi, thay đổi cả trạng thái bảng thông báo để hiển thị.
- int PlayerWinGame(): Trả về game chưa xong hoặc ai thắng hoặc hòa.
- void AiMove: lấy nước đi của đối tượng botPlayer sau, đánh dấu ô đấy vừa được đánh, phát nhạc click và render lại. Nếu nó botPlayer trả về ô (0,0) thì tức là botPlayer nhận thua(vì minimax không tìm thấy ô đánh phù hợp)
- void restart: restart lại game thành ván mới nhưng vẫn map đấy và đánh với người/máy đấy.
- void renderBulletinBoard: render bảng thông báo.
- void endGame(SDL_Renderer* renderer): kết thúc game, phát ra âm thanh kết thúc, in ra trạng thái thắng thua hòa, in lại bảng thông báo.
####
**public:**
- void setWhoPlay(int AIplay):  gọi từ bên ngoài vào xem có chơi với AI hay không.
- void setSizeOfBoard(int x,int y): gọi từ bên ngoài set sizeMap.
- void setNumberOfPieceConsecutiveToWin(int number): gọi từ bên ngoài set sizeNumberWin.
- void setLevelOfAI(int stateLevel): gọi từ bên ngoài set levelAI. Từ đó chọn kế thừa theo AI easy, medium hay hard.
- void setStateSound(int state): gọi từ bên ngoài set sound on/off.
- void setAllAttribute(): gọi tất cả các hàm setAttribute trong private.
- void handleEvent(): check event cho mọi button có trong giao diện đối tượng game.
- void render: render giao diện đối tượng game. bao gồm gọi render tất cả ảnh và button.

### AI.h  <a name="AI.h"></a>
#### là class chứa thuật toán minimax cùng hàm đánh giá và các biến liên quan đến bàn chơi.
*cài đặt:*
####
**protected: (để kế thừa)**
- const int dx[10] = {1, 1, 0, -1, 0, 1, -1, -1}: hướng loang theo chiều rộng.
- const int dy[10] = {1, 0, 1, 1, -1, -1, 0, -1}:
- int boardState[15][15]: hiện thị trạng thái bàn chơi. mỗi ô có thể có giá trị X, O, trống. Tạo riêng ở class AI 1 cái bảng thay vì lấy từ game vì để tiết kiệm thời gian chạy minimax.
- pair<int,int> sizeOfBoard:
- int numStepToWin: số quân cờ liên tiếp để thắng.

- virtual int cntContinue(int x, int y, int dx, int dy, int statePlayer){}: hàm trừu tượng, đếm số ô lợi thế và trả về giá trị điểm. Mỗi chế độ thừa kế AI là easy, hard, medium sẽ khác nhau ở hàm này.
- bool checkInsideBoard(int x,int y): check xem vị trí đấy có ở trong bàn chơi không. Ví dụ map 3x3, ô (5,4) không ở trong màn chơi.(cho ra protected vì lớp con dùng)
####
**private:**
- int minimax(bool isTurnOfAI, int alpha, int beta, int depth): hàm minimax(trình bày ở trên).
- int heuristicValue(): hàm đánh giá trạng thái của bàn cờ đang chơi lợi thế cho ai.
- bool havePlayerWin(int turnOfPlayer): check xem người "turnOfPlayer" thắng chưa?
- bool gameOver(): check xem hết quân để đánh chưa? (board full but draw).
####
**public:**
- void setBoardState(int i,int j, int value):
- void setSizeOfBoard(int x,int y):
- void setNumStepToWin(int value):
- pair<int,int> bestMove(): trả về ô mà AI sẽ đi sau khi duyệt minimax.
### AIextendEasy.h:   <a name="AIextendEasy.h"></a>
#### là class kế thừa từ class AI, có thuật toán chỉ biết chặn, như chọn nước để chặn thì cũng rất kém.(làm suy yếu từ AIextendMedium)
### AIextendMedium.h: <a name="AIextendMedium.h"></a>
#### là class kế thừa từ class AI, có thuật toán chỉ biết chặn, như chọn nước để chặn khá khôn, biết nước sẽ thắng.(làm suy yếu từ AIextendHard)
### AIextendHard.h:   <a name="AIextendHard.h"></a>
#### là class kế thừa từ class AI, không chỉ biết chặn mà còn biết tấn công tạo nước đôi cực tốt, là niềm tự hào của game nào cũng như người tạo ra game này.
### main.cpp: <a name="main.cpp"></a>
- chứa biến inGame(= 1 là đang ở trong game, = 0 là đang ở preGame).
- chứa các biến khởi tạo cho SDL.
- gọi hàm setData từ SDLsupport.
- Vòng lặp game: nếu check sự kiện nếu đổi inGame thành 0 thì vô preGame, dổi thành 1 thì vô game. trước khi vô game thì set giá trị map, player từ preGame cho game.
