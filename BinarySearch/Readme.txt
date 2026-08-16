			Binary Search

Do hiện tại tôi đang cố gắng dành chứng chỉ của công ty liên quan đến DSA nên mặc dù
có nhiều thuật toán tìm kiếm khác nhau nhưng tôi sẽ chú trọng đến Binary Search vì nó
liên quan đến chứng chỉ lần này :)

+ Giới thiệu:

Binary Search là một thuật toán tìm kiếm được áp dụng trên "một miền đã được sắp xếp
từ trước" (Xin nhấn mạnh là một miền được sắp xếp từ trước).
Với nguyên lý rất đơn giản là chia không gian tìm kiếm thành hai miền
	+ lớn hơn giá trị cần tìm (ví dụ nằm ở bên phải tận cùng kí hiệu là r)
	+ nhỏ hơn giá trị cần tìm (ví dụ nằm ở bên trái tận cùng kí hiệu là l)
Trước tiên ta tìm giá trị ở chính giữa của r và l
=> vị trí cần tìm: m = (l+r)/2
=> + Nếu tại vị trí m chứa giá trị lớn hơn giá trị cần tìm 
   => ta thu nhỏ khoảng cách của r lại với r = mid - 1;
   + Nếu tại ví trí m chứa giá trị nhỏ hơn giá trị cần tìm 
   => giá trị cần tìm ở bên phải
   => cần thu hẹp khoảng tìm kiếm về bên phải l = mid + 1;
=> tiếp tục như vậy khi l > r thì ta dừng tìm kiếm.

+ Biểu diễn bằng code: 
	int BinarySearch (int[] array, int left, int right, int value) {
		while (left <= right) {
			int mid = (left + right)/2;
			if(array[mid] == value) {
				return mid;
			}
			else {
				if(array[mid] < value) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}
		return -1;
	}

+ Tìm kiếm số xuất hiện đầu tiên hoặc cuối cùng trong mảng 
(hoặc có thể hiểu là tìm một giá trị cuối cùng hay đầu tiên thỏa mãn một biểu thức)

ví dụ code:

int binarySearch (vector<int> arr, int l, int r, int val) {
	while(l <= r) {
		int mid = (l+r)/2;
		if(arr[mid] <= val) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return r;
}

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

C2: Ngoài ra có thêm một cách nữa để biểu diễn binary search.
Đó là dùng các bước nhảy để tìm vị trí cần tìm.
Ví dụ cho một vị trí bắt đầu bằng k = 0 sau đó khởi tạo bước nhảy b với một số nào đó
nếu ta thấy vị trí k thỏa mãn điều kiện chặn dưới cần tìm thì k sẽ nhảy 
với bước nhảy b : k = k+b 
Nếu không thỏa mãn điều kiện thì bước nhảy sẽ giảm dần thang b/4 b/8 cho tới khi bằng 1

Ví dụ tìm giá trị x trong array có n phần tử
	int k = 0;
	for (int b = n/2; b >= 1; b /= 2) {
		while (k+b < n && array[k+b] <= x) k += b;
	}
	if (array[k] == x) {
		// x found at index k
	}

=====================

+ Tìm vị trí đầu tiền thay đổi giá trị 

Ví dụ 

x     |	1 | 2 | 3 | 4 | ... | 5 | 6 | 7 | 8 |
===============================================
ok(x) |	f | f | f | f | ... | f | t | t | t |

int x = -1;
for (int b = z; b >= 1; b /= 2) {
	while (!ok(x+b)) x += b;
}
int k = x+1;

Note: lưu ý trọn z sao cho lần đầu tiên xét ok(x) có giá trị bằng t.

====================

+ Tìm giá trị max trong một dãy số chia đều

Binary search can also be used to find the maximum value for a function that is
first increasing and then decreasing. Our task is to find a position k such that
	• f (x) ˙ f (x¯1) when x ˙ k, and
	• f (x) ¨ f (x¯1) when x ‚ k.
The idea is to use binary search for finding the largest value of x for which
f (x) ˙ f (x-1). This implies that k ˘ x-1 because f (x-1) ¨ f (x-2). The following
code implements the search:

int x = -1;
for (int b = z; b >= 1; b /= 2) {
	while (f(x+b) < f(x+b+1)) x += b;
}
int k = x+1;

Note that unlike in the ordinary binary search, here it is not allowed that
consecutive values of the function are equal. In this case it would not be possible
to know how to continue the search.