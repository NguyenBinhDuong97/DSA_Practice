		Back Track

+ Giới thiệu: Back Track 

Đây là một trong nhiều phương pháp dùng để liệt kê các cấu hình có thể có của bài toán.
Rất đơn giản là Back Track sẽ thử từng cấu hình một trong dải tìm kiếm của bài toán 
cho đến khi có cấu hình phù hợp hay đúng nhất thì sẽ được đưa vào miền kết quả.
Cuối cùng chúng ta có thể in miền kết quả ấy ra.

Tuy nhiên chúng ta cần xét đến sự liên quan của các phần tử trong cấu hình đã chọn
dựa theo yêu cầu của bài toán
(hay đúng hơn là các điều kiện rằng buộc trong miền tìm kiếm).

Ví dụ: trong một dãy gồm các số nguyên ta chỉ có thể chọn một số ở một vị trí 
nhất định sau đó ta sẽ đánh dấu phần tử được chọn trong dãy đó để lần sau khi chọn 
sẽ không lặp lại nữa

Ví dụ: Trong bài toán con hậu thì điều kiện rằng buộc là các con hậu không được nằm
cùng hàng hay cùng cột hay cùng đường chéo.

+ Công thức xây dựng Back Track 
	
Dựa vào ba yếu tố:
	_ Choices (miền tìm kiếm)
	_ Constraints (điều kiện giới hạn, điều kiện ràng buộc của tìm kiếm)
	_ Goals (Mục tiêu cần đạt để có thể đưa một cấu hình vào miền kết quả)

Khi xác định được ba yếu tố này thì ta có công thức cho Back Track được xây dựng 
như sau:
	void BackTrack(result, param) { // Param tượng trưng có thể dùng nhiều tham số.
		if(GOALS REACHED) // Khi đạt được GOAL
			add configuration to result; // thêm config vào miền result
			return; // thoát ra khỏi vòng lặp tìm kiếm cho 1 config 
				// đến đây chưa hết và chúng ta có thể có config khác.
		for(int i = 0; i < NB_CHOICES; i++) { // lựa chọn trong miền tìm kiếm
			if(CHOICES[i] is valide) {
				make choices[i]; // đánh dấu lựa chọn đã chọn
				BackTrack(res, param); // Tiếp tục chọn phần tử tiếp
				undo choices[i]; // hủy đánh dấu lựa chọn đã chọn
			}
		}
	}
	

+ Resource:

Phần này được viết và có sự tham khảo ngoài sách DSA của thầy Lê Hoàng Minh 
còn có các link hướng dẫn:
	+ https://www.youtube.com/watch?v=Nabbpl7y4Lo
	+ https://www.youtube.com/watch?v=Zq4upTEaQyM
	 