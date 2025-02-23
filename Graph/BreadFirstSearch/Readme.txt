		Breadth First Search (BFS)

+ Dạng đồ thị sử dụng 
Để làm quen với thuật toán này ta sẽ sử dụng đồ thị dạng AdjList Graph
(Nếu như quên cách biểu diễn Graph với kiểu AdjList thì có thể xem lại
mục ReprenstationGraph trong repo này).

+ Mục tiêu:
Mục tiêu của thuật toán này là sẽ xét theo chiều ngang (ngược lại với với DFS).
Nếu như DFS xét theo chiều dọc nghĩa là các các node được xét là các node đầu tiên
được trỏ tới bởi AdjList như ví dụ sau:
    Ví dụ: Graph
	1 : 2 3
	2 : 1 3	
	3 : 1 4
	4 : 1
giả sử DFS sẽ xét 1 trước => 1 liên kết với 2 và 3
			     xét 3: liên kết với 1 4
			     xét 4: lien kết với 1
		   	     xét 2: liên kết với 1 3 

BFS sẽ xét theo chiều ngang nghĩa là xét hết các node liền kết với node đang được xét
sau đó lại xét hết các node liền kề với node liền kề.
Với Graph ví dụ trên:
giả sử BFS sẽ xét 1 trước => 1 liên kết với 2 3
			     xét 2: liên kết với 1 3
			     xét 3: liên kết với 1 4
			     xét 4: liên kết với 1

+ Implement:
 
Để thực hiện được mục tiêu đã nêu trên thì ta sẽ dùng queue: các node liền kề sẽ được
cho vào một queue. Sau đó lấy các node trong queue ra và xét tiếp nếu node đó chưa xét
Khi xét một node thì node đó sẽ được đánh dấu.

Ví dụ Code: Cho một đồ thị giả dụ có N node biểu diễn dưới dạng AdjList Và muốn
biểu diễn và set với dạng BFS.

#define NOT_CHECK -1
#define IN_QUEUE 0
#define CHECKED 1

vector<vector<int>> Graph;
	
vector<int> markingNode(N, NOT_CHECK); //Các node chưa được xét thì được đánh dấu bằng -1

void BFS(int i){	
	queue<int> NodeQueue;
	NodeQueue.push(i); //Push node đầu tiên hay root vào queue
	while(!NodeQueue.empty()){
		int CheckingNode = NodeQueue.front();
		markingNode[CheckingNode] = CHECKED; //Đánh dấu rằng node đã được set
		NodeQueue.pop();
		for(int i = 0; i < Graph[ChekingNode].size(); i++) {
			if(NOT_CHECK == Graph[CheckingNode][i]) {
				NodeQueue.push(Graph[CheckingNode][i]);
				markingNode[Graph[CheckingNode][i]] = IN_QUEUE;
			}
		}
	}	
}

int main() {	
	for(int i = 0; i < N; i++) {
		if(NOT_CHECK == markingNode[i]){
			BFS(i);
		}
	}
}