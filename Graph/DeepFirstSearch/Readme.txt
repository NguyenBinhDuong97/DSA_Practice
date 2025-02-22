		DFS(Deep first search)

Nguyên lý: 

+ Ta sẽ sử dụng kiểu biểu diễn AdjcentListGraph để thực hiện thuật toán DeepFirstSearch
+ ví dụ
A: B C D
B: A D
C: A B D
D: A
Note: Nếu không nhớ cách biểu diễn Gprah bằng AdjcentList thì có thể xem lại phần 
"GraphRepresentation" trong repo này.


+ Mục tiêu của thuật toán này sẽ search hết các node theo chiều sâu (từ node này
sang node khác được chỉ đến bởi list) các node đã đi qua được đánh dấu để nhận biết.
Các node được xét lần lượt (nếu tới các node đã xét) thì bỏ qua 
như thế cho đến khi xét hết các node trong đồ thị.

+ Để thực hiện hóa mục tiêu đã nêu ra của DFS ta có thể sử dụng stack.
Các node(chưa được xét được đánh dấu = 0) được chỉ bởi node đầu tiên 
ta có thể thêm vào stack.Đánh dấu rằng các node đó đang được ở trong stack (gán = -1) 
và sẽ không xét đến nó nữa cho đến khi node trong stack được pop ra từ stack và 
được đánh dấu là node đã được xét cho được đánh dấu là 1.

Lưu ý ta chỉ xét đến các node đã được đánh dấu là 0;

Implement:
Ví dụ ta có một đồ thị N node

Trước tiên ta sẽ đánh dấu các node đó là các node chưa được xét bằng cách cho các node
đó bằng 0;

vector<int> NodeMarking(N, -1);

void visit(i) {
	stack<int> stackNode;
	stackNode.push(i);
	while(!stackNode.empty()) {
		CheckingNode = stackNode.top();
		stackNode.pop();
		NodeMarking[CheckingNode] = 1;
		for(int i = 0; i < Graph[CheckingNode].size(); i++) {
			if(Graph[CheckingNode][i] == -1) {
				stackNode.push(Graph[CheckingNode][i]);
				NodeMarking[Graph[CheckingNode][i]] = 0;
			}
		}
	}	
}


int main(){
	for(int i = 0; i < N; i++) {
		if(-1 == NodeMarking[i]) {
			visit(i);
		}
	}


}



