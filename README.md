# GAME TICTACTOE
## Mục lục:

#### 1. Tổng quan về game:
##### 1.1 Giới thiệu:
##### 1.2 Kiến thưc áp dụng:
##### 1.3 Chia sẻ về quá trình làm game:
#### 2. Cài đặt chương trình:
##### - sdlsupport.h
##### - button.h
##### - pregame.h
##### - game.h
##### - AI.h
##### - AIextendEasy.h
##### - AIextendMedium.h
##### - AIextendHard.h
##### - main.cpp

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
#### [DEMO GAME TRÊN YOUTUBE](https://www.youtube.com/watch?v=tYu1I2Vqdb8&t=61s)
TICTACTOE là game được phát triển bởi Phạm Tiến Du, MSV 20020039 cho bài tập lớn môn LTNC INT2215 6.
Game dựa trên game cờ ca rô tuổi thơ. Board của game là một lưới ô vuông m * n.
Game dùng duy nhất chuột để chơi.
2 người chơi sẽ lần lượt đánh "X" và đánh "O" cho đến khi đủ k "X" liên tiếp hoặc k "O" liên tiếp theo hàng dọc, ngang hoặc chéo thì người chơi đó thắng hoặc thua. Nếu không ai có thể đạt được như vậy thì trò chơi sẽ hòa.
Trong game TICTACTOE này sẽ có 4 loại màn chơi: 3x3 với k = 3, 5x5 thì k = 4, 9x9 và 12x12 thì k = 12. Ngoài chế độ chơi 2 người với nhau, TICTACTOE còn được thiết kế để người chơi chơi với AI ở bàn 3x3 và 9x9, 12x12 với các mức độ chơi easy, medium, hard.

### 1.2 Kiến thức áp dụng:
####
- Ngôn ngữ lập trình C++.
- Thư viện đồ họa SDL2 qua slide cô Châu và lazyfoo.
- Kiến thức về OOP: lớp, đối tượng, tính đóng gói, tính thừa kế, lớp trừu tượng. (tham khảo qua giáo trình OOP_2013 của ĐHCN-ĐHQGHN)
- Kiến thức về Trí tuệ nhân tạo: các chiến lược tìm kiếm có đối thủ: thuật toán minimax, prunning alpha-beta.(tham khảo qua google, giáo trình trí tuệ nhân tạo)
- Kiến thức về game cờ caro: Để viết hàm đánh giá tốt cho AI trong game.
### 1.3 Chia sẻ về quá trình làm game:
####
- Em không thích làm game lắm và sẽ không có dự định theo nghiệp game sau này. Vì vậy game của em có khác biệt so với các bạn 1 tý. Thay vì chăm chút đồ họa, em coi trọng kiến thức học được và áp dụng vào game nhiều hơn.
- Tầm đến tuần 5 hay 6 gì đấy em mới mày mò SDL vì thật sự không muốn làm game chút nào. Vừa lúc đấy thì em có học qua được thuật toán minimax trong môn trí tuệ nhân tạo. Nên em quyết định làm game cờ ca rô có AI.
- Quá trình làm game thì khá đơn giản. Ngoài cài mấy cái SDL lằng nhằng ra thì mọi thứ rất nhanh gọn nhẹ. Vì căn bản em cũng có nền tảng code từ cấp 3 rồi, game cũng không có đồ họa gì nhiều mà khó khăn cả nên em có thể tự tư duy viết game mà không cần xem mẫu cô Châu.
- Nhưng rồi em phát hiện là mình viết nó cứ lằng nhằng. Thêm tính năng thì cũng khá là mệt. Em nhớ đến lập trình hướng đối tượng. Em cũng đã tìm hiểu sơ qua từ trước nhưng chưa hiểu lắm. Lần này thì em in luôn giáo trình OOP ra đọc.
- Bỏ qua chương Java để đọc những chương lý thuyết là chính, em khá là hiểu dù chưa dám chắc mình hiểu sâu. Rồi em quay lại áp dụng cho game của mình. Cách coi từng thành phần là đối tượng, rồi game chỉ là các đối tượng gọi nhau, hay là cách đóng gói, kế thừa, lớp trừu tượng đều là điều hay ho và cần thiết lúc này đối với em.
- Thiết kế xong chương trình rất oke rồi thì lại đến phần khó nhất là làm AI cho game từ minimax. Em biết là nó khá khó đối với em nhưng không nghĩ lại khó đến thế. Trước tiên ta làm minimax cho map 3x3 trước vì nó khá dễ.
- Thuật toán minimax nó cũng không khác kiểu 1 cách quy hoạch động đơn giản trên đồ thị là mấy. Cho nên việc tự cài khá dễ, ai học minimax rồi chắc cũng làm được hết. 3x3 khá nhiều người làm trên mạng rồi nên cho nên dù đã tự viết được nhưng em vẫn lấy sườn trên mạng về vì người ta viết khá tốt, dễ dùng, dễ phát triển. Nhất là phần cắt cụt alpha-beta.
- Đến phần AI trên map lớn hơn. Lúc này không thể xây cả cây tìm kiếm như map 3x3 vì độ phức tạp của cây tìm kiếm là O((m*n)!) với m, n là kích thước bảng. Với 3x3 là 9! còn có thể chấp nhận được. chỉ 4x4 thôi cũng là 16! rồi. Dù cắt cụt alpha-beta cũng chỉ giảm đi khoảng 2-3 lần.
- Ta chỉ xây được đến depth nào đó rồi ta phải đánh giá cái board đấy có lợi cho ai. Giá trị càng dương thì càng có lợi cho AI. Rồi em viết 1 hàm đánh giá khá ngây thơ. Nhưng vì chọn depth = 5 nên nó vẫn chạy đủ khôn để đánh khôn nên rất vui.
- Nhưng user experience thì khá tệ. Map 9x9 thì độ phức tạp là 81x80x79x78x77xđộ phức tạp hàm đánh giá(cứ cho 5 phép tính đi) > 10^10. Theo kiến thức CP cũ em được biết, 1 giây chạy khoảng 10^8 phép tính đơn giản. Vậy là AI sẽ mất 100s cho 1 nước đi. Cắt cụt alpha-beta giảm rất tốt nhưng cũng chạy tận 15s. Đã chờ lâu, mà còn spam cái, game sẽ lại not responding. Không còn gì cáu hơn nữa.
- Em giảm độ sâu xuống 4 thì chạy cũng tạm tàm. Nhưng mà đánh kém lắm. Do hàm đánh giá em vẫn ngây thơ. Em không phải người chơi cờ caro giỏi. Truyền hoàn toàn tri thức của mình cho máy tính cũng không phải là dễ nữa. Thế em quyết định sẽ giữ nguyên độ sâu 5 và cố gắng cắt bớt nhánh phát triển đi. Đồng thời cũng đi học cách đánh cờ caro giỏi.
- Em duyệt đến đâu, em đánh giá đến đấy luôn. Rồi sort lại và chỉ phát triển 1 nửa số đỉnh ở phần trên của sort. Thời gian chạy vẫn tầm 5s mà đánh cũng chả thông minh hơn. Giảm số đỉnh phát triển xuống 1/3 thì còn kém hơn nữa. Dù em đã viết dần lại hàm đánh giá cho thông minh hơn, nhưng việc cắt đi nhánh dù sort rổi cũng làm mất đi khá nhiều con đường sáng lạng.
- Có những nước đi căn bản là lúc đầu thấy tốt nhưng về sau bế tắc, lúc đầu tính điểm kém nhưng về sau lại tốt. Vì vậy cắt đi thế là không hiệu quả. Nhưng sau này em mới nhận ra. Còn trong tầm 2-3 tuần, em chỉ nghĩ do em đánh giá kém và viết đi viết lại hàm đánh giá.
- Để rồi tuyệt vọng rồi, không biết làm cách nào nữa. Em định nộp con AI lởm luôn. Nhưng tự nhiên đầu lại nảy việc thử lại depth = 4 xem sao. Không ngờ nó lại nhanh hơn rất nhiều, đánh lại cực kì khôn. Vì hàm đánh giá đủ tốt, phát triển 4 nước thôi thì vẫn là tốt. Khoảnh khắc sửa được rất là sung sướng.
- Thế rồi em chia level bằng cách kế thừa. Lấy AI thông minh đấy là hard, em chặn khả năng tấn công của AI và cho đấy là level medium. Em chặn tiếp khả năng chặn của AI thành kém thì thành mode easy. Em chỉ lại đồ họa và chỉnh sửa lại code nữa và nó thành như bây giờ. Phải nó làm em khá tự hào về game này, Tự hào về con AI em viết ra chạy được map 12x12 mượt mà lại đánh tốt.
- Có 1 ý thêm là hàm đánh giá em tự viết hoàn toàn do trên mạng chỉ có minimax 3x3. Ý tưởng chính là mình sẽ xét từng ô 1. Với mỗi ô xem dọc ngang chéo phát triển được không. Nếu chỉ 1 hướng phát triển được thì có a điểm. Nhưng nếu có 1 hướng nước phát triển tốt và tạo ra b điểm. Ta sẽ trả về a * b để giá trị rất cao nhằm ưu tiên "nước đôi". Nếu có cơ hội em sẽ trình bày hàm đánh giá kĩ hơn sau.
## 2. Cài đặt chương trình:
### sdlsupport.h:
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

### button.h:
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

### pregame.h:
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

### game.h:
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

### AI.h
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
### AIextendEasy.h:
#### là class kế thừa từ class AI, có thuật toán chỉ biết chặn, như chọn nước để chặn thì cũng rất kém.(làm suy yếu từ AIextendMedium)
### AIextendMedium.h:
#### là class kế thừa từ class AI, có thuật toán chỉ biết chặn, như chọn nước để chặn khá khôn, biết nước sẽ thắng.(làm suy yếu từ AIextendHard)
### AIextendHard.h:
#### là class kế thừa từ class AI, không chỉ biết chặn mà còn biết tấn công tạo nước đôi cực tốt, là niềm tự hào của game nào cũng như người tạo ra game này.
### main.cpp:
- chứa biến inGame(= 1 là đang ở trong game, = 0 là đang ở preGame).
- chứa các biến khởi tạo cho SDL.
- gọi hàm setData từ SDLsupport.
- Vòng lặp game: nếu check sự kiện nếu đổi inGame thành 0 thì vô preGame, dổi thành 1 thì vô game. trước khi vô game thì set giá trị map, player từ preGame cho game.
