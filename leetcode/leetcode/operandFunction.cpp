#include"leetcode.h"
//int partition(vector<T>, int, int);


vector<int> reverseVector(vector<int>& nums)
{
	vector<int> temp;
	for (int i = nums.size() - 1; i >= 0; i--)
		temp.push_back(nums[i]);
	return temp;
}

vector<int> getVec(int nums[], int n)
{
	vector<int> res;
	for (int i = 0; i < n; i++)
		res.push_back(nums[i]);
	return res;
}
void quick_sort(vector<int> &array)
{
	quick_sort(array, 0, array.size() - 1);
}
void swap(int&a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void printVec(vector<int> nums)
{
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << "\n";
}
/*
使用随机快排，保证数据时间复杂度是nlog（n）
*/
void quick_sort(vector<int> &array, int left, int right)
{

	//int left=begin, right=end, low, high;
	if (left < right)
	{

		int baseIndex = left + rand() % (right - left + 1);
		int base = array[baseIndex];
		int low = left, high = right;
		/*
		 需要特殊处理，不然跳不出来循环
		 */
		if (right - left == 1)
		{
			if (array[left]>array[right])
				swap(array[left], array[right]);
			return;
		}
		while (low < high)
		{
			/*
			不要使用等号判断，否则容易生成low==high这种形式陷入死循环
			*/
			while (low < high&&array[low] < base)
				low++;
			while (low<high&&array[high]>base)
				high--;
			if (low < high)
			{
				int temp = array[low];
				array[low] = array[high];
				array[high] = temp;
				low++;
				high--;
			}
		}
		quick_sort(array, left, high);
		quick_sort(array, low, right);
	}
}

int mySqrt(int x)
{
	int low = 1;
	int high = x;
	int middle = 0;
	if (x == 0)
		return 0;
	while (low < high)
	{
		middle = low / 2 + (high) / 2;
		if (x / (middle*1.0) - middle < 0)
		{
			high = middle - 1;
		}
		else if (x / (middle*1.0) - middle == 0)
			return middle;
		else
			low = middle + 1;
	}
	middle = (low + high) / 2;
	if (x / middle < middle)
		return middle - 1;
	return middle;

}

int searchInsert(vector<int>& nums, int target)
{
	int low = 0, high = nums.size() - 1;
	int mid;
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
	{
		if (nums[0] >= target)
			return 0;
		else
			return 1;
	}

	while (low <= high)
	{
		if (low % 2 == 1 && (high - low) % 2 == 0)
			mid = low / 2 + high / 2 + 1;
		else
			mid = low / 2 + high / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (high == -1)
		return 0;
	if (nums[high] < target)
		return high + 1;
	else if (nums[high]>target)
		return high;
	return 0;

}
void nextPermutation(vector<int>& nums)
{
	if (nums.size() == 1)
		return;
	int minIndex = -1, i, size = nums.size();
	for (i = 0; i < nums.size() - 1; i++)
		if (nums[i] < nums[i + 1] && i > minIndex)
		{
			minIndex = i;
		}
	if (minIndex == -1)
	{
		i = 0;
		while (i < size / 2)
		{
			int temp = nums[i];
			nums[i] = nums[size - 1 - i];
			nums[size - 1 - i] = temp;
			i++;
		}
	}
	else
	{
		int narrowMax = nums[minIndex + 1];
		int narrowMaxIndex = minIndex + 1;
		for (int j = minIndex + 2; j <nums.size(); j++)
			if (nums[j]>nums[minIndex] && nums[j] < narrowMax)
			{
				narrowMax = nums[j];
				narrowMaxIndex = j;
			}
		int temp = nums[minIndex];
		nums[minIndex] = narrowMax;
		nums[narrowMaxIndex] = temp;
		quick_sort(nums, minIndex + 1, nums.size() - 1);
	}
}


bool isNotEqual(vector<int> a, vector<int> b)
{
	int i = 0;
	if (a.size() != b.size())
		return false;
	while (i < a.size())
	{
		if (a[i] != b[i])
			break;
		i++;
	}
	return i == a.size() ? true : false;
}
vector<vector<int>> permute(vector<int>& nums)
{
	vector<int> initNums = nums;
	vector<vector<int>> res;

	do
	{
		nextPermutation(nums);
		res.push_back(nums);

	} while (!isNotEqual(nums, initNums));

	return res;
}
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	ListNode *newHead = (ListNode*)(malloc(sizeof(ListNode)));
	newHead->next = NULL;
	ListNode *newP = newHead, *p = head;
	int i = 1;
	while (i < m)
	{
		newP->next = p;
		newP = p;
		p = p->next;
		i++;
	}
	ListNode *tail = p;
	if (tail == NULL || tail->next == NULL)
		return head;
	while (i <= n&&p != NULL)
	{
		ListNode *temp = p->next;
		p->next = newP->next;
		newP->next = p;
		i++;
		p = temp;
	}
	while (p != NULL)
	{
		tail->next = p;
		tail = p;
		p = p->next;
	}
	tail->next = NULL;
	head = newHead->next;
	return head;
}
ListNode *getListNode(int* nums, int n)
{
	vector<int> vecNums;
	for (int i = 0; i < n; i++)
		vecNums.push_back(nums[i]);
	return getListNode(vecNums);
}

ListNode * getListNode(vector<int> nums)
{
	ListNode *head = NULL;
	ListNode *tail = NULL;
	for (int i = 0; i < nums.size(); i++)
	{
		ListNode* node = (ListNode*)(malloc(sizeof(ListNode)));
		node->val = nums[i];
		node->next = NULL;
		if (head == NULL)
		{
			head = node;
			tail = head;
			continue;
		}
		tail->next = node;
		tail = node;
	}
	return head;
}
void quick_sort_pointer(ListNode* left, ListNode *right)
{
	int base = right->val;

	ListNode *i = left, *j = left;
	ListNode *jPre = NULL;
	if (left != right)
	{
		for (; i != right; i = i->next)
			if (i->val < base)
			{
				int temp = j->val;
				j->val = i->val;
				i->val = temp;
				jPre = j;
				j = j->next;
			}
		right->val = j->val;
		j->val = base;
		if (jPre == NULL)
			quick_sort_pointer(j->next, right);
		else
		{
			quick_sort_pointer(left, jPre);
			if (j == right)
				return;
			quick_sort_pointer(j->next, right);
		}

	}
}
ListNode * getListNodeTail(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *tail = head->next;
	while (tail->next)
		tail = tail->next;
	return tail;
}
ListNode* sortList(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *tail = head->next;
	while (tail->next)
		tail = tail->next;
	quick_sort_pointer(head, tail);
	return head;

}
/*
采用二路归并方式对单链表进行排序
*/
ListNode *divide_binary_sort(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *pre = head;
	ListNode *middle = pre, *cursor = pre;
	ListNode *preMiddle = pre;
	while (cursor&&cursor->next)
	{
		preMiddle = middle;
		middle = middle->next;
		cursor = cursor->next->next;
	}
	preMiddle->next = NULL;
	head = divide_binary_sort(head);
	middle = divide_binary_sort(middle);
	return mergeTwoLists(head, middle);
}




/*
查看数组中是否有两个数在指定的索引方位内相同
*/
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	unordered_map<int, int> numsMap;
	unordered_map<int, int>::iterator mapIterator;
	for (int i = 0; i < nums.size(); i++)
	{
		mapIterator = numsMap.find(nums[i]);
		if (mapIterator != numsMap.end())
		{
			if (k >= i - mapIterator->second)
				return true;
			else
				numsMap.erase(nums[i]);
		}
		numsMap.insert(make_pair(nums[i], i));
	}
	return false;
}
int cout_prime(int n)
{
	if (n < 2)
		return 0;
	if (n < 4)
		return n - 1;
	vector<int> nums;
	nums.resize(n + 1, 1);
	int i, j;
	for (i = 2; i <= n / 2; i++)
		for (j = 2 * i; j <= n; j += i)
		{
			nums[j] = 0;
		}
	int count = 0;
	for (int i = 2; i <= n; i++)
		if (nums[i] == 1)
		{
			count++;
			//cout << setw(4) << i;
		}
	return count;
}
/*
删除排序数组中的重复元素
*/
ListNode* deleteDuplicates(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* pre = head, *back = NULL, *adj = NULL;
	bool isHeadFirst = false;
	bool loop = false;
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* newHead = (ListNode*)(malloc(sizeof(ListNode)));
	newHead->next = head;
	head = newHead;
	pre = head;
	while (pre)
	{
		loop = false;
		back = pre->next;
		while (back&&back->next)
		{
			if (back->next->val != back->val)
				break;

			back = back->next;
			loop = true;
		}
		if (loop)
			pre->next = back->next;
		else
		{
			pre->next = back;
			pre = back;
		}
	}
	head = head->next;
	return head;
}
/*
反转链表
*/
ListNode* reverseList(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* pre = head, *cursor = pre->next, *post = cursor->next;
	pre->next = NULL;
	while (post)
	{
		cursor->next = pre;
		pre = cursor;
		cursor = post;
		post = post->next;
	}
	cursor->next = pre;
	pre = cursor;
	return pre;
}

/*
是否为回文串
*/
bool isPalindrome(ListNode* head)
{
	if (head == NULL)
		return true;
	ListNode *cursor = head, *middle = head;
	while (cursor&&cursor->next)
	{
		middle = middle->next;
		cursor = cursor->next->next;
	}
	if (cursor)
		middle = middle->next;
	middle = reverseList(middle);
	while (head&&middle)
	{
		if (head->val != middle->val)
			return false;
		head = head->next;
		middle = middle->next;
	}
	return true;
}
string intParseStr(int num)
{
	//bool isNegative = num < 0 ? true : false;
	if (num == 0)
		return "0";
	int i, j = num;
	bool isNegative = num < 0 ? true : false;
	string s = isNegative ? "-" : "";
	bool isMaxPos = false;
	if (num == -(int)pow(2, 31))
	{
		num++;
		isMaxPos = true;
	}
	if (isNegative)
		j = -num;
	stack<char> numStack;
	int numCount = 0;
	while (j)
	{
		i = j % 10;
		j /= 10;
		numStack.push(i);
		numCount++;
	}
	while (!numStack.empty())
	{
		if (numCount == 1 && isMaxPos)
			s.append(1, numStack.top() + '1');
		else
			s.append(1, numStack.top() + '0');
		numCount--;
		numStack.pop();
	}

	return s;
}
int strParseInt(string s)
{
	bool isNegative = false;
	if (!s.substr(0, 1).compare("-"))
	{
		isNegative = true;
		s = s.substr(1);
	}
	int parseInt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		parseInt = parseInt * 10 + (s.at(i) - '0');
	}
	if (isNegative)
		parseInt = -parseInt;
	return parseInt;



}
TreeNode* createTree(vector<string> nums)
{
	int i = 0, j;
	vector<TreeNode*> treeNodes;
	TreeNode* treeNode;
	for (; i < nums.size(); i++)
	{
		if (!nums[i].compare("null"))
		{
			treeNode = NULL;
			treeNodes.push_back(treeNode);
			continue;
		}
		treeNode = (TreeNode*)(malloc(sizeof(TreeNode)));
		treeNode->val = strParseInt(nums[i]);
		treeNode->left = NULL;
		treeNode->right = NULL;
		treeNodes.push_back(treeNode);
	}
	for (i = 0; i < nums.size() / 2; i++)
	{
		j = 2 * i + 1;
		if (j < nums.size())
			treeNodes[i]->left = treeNodes[j];
		j++;
		if (j < nums.size())
			treeNodes[i]->right = treeNodes[j];
	}
	return treeNodes[0];
}
int removeDuplicates(int* nums, int numsSize)
{
	int count = 0;
	int duplicate = 0;
	int i = 0;
	int newArray[2000];
	for (; i < numsSize; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			if (duplicate)
			{
				duplicate = 1;
				continue;
			}
			else
			{
				duplicate = 1;
				newArray[count] = nums[i];
				count++;
				continue;
			}
		}
		duplicate = 0;
		newArray[count] = nums[i];
		count++;
	}
	for (i = 0; i < count; i++)
		nums[i] = newArray[i];
	return count;
}
char* longestCommonPrefix(char** strs, int strsSize)
{
	int i = 0, j = 0, minLength = 0x03ffffff;
	if (strs == NULL || *strs == NULL)
		return "";
	for (; i < strsSize; i++)
		minLength = min(minLength, (int)strlen(*(strs + i)));
	for (i = 0; i < minLength; i++)
	{
		for (j = 0; j < strsSize - 1; j++)
			if (*(*(strs + j) + i) == *(*(strs + j + 1) + i))
				continue;
			else
				break;
		if (j != strsSize - 1)
			break;
	}
	//   i--;
	*(*strs + i) = '\0';
	return  *strs;
}
char * getTail(char *head)
{
	if (*head == '\0' || *(head + 1) == '\0')
		return head;
	char *tail = NULL;;
	while (*head)
	{
		tail = head;
		head++;
	}
	return tail;
}
/*
非重复整数组合数目
*/
int getDistinctCombination(int n, int k)
{
	if (n == 0 || n == 1)
		return 1;
	int facN = 1, facK = 1;
	int i;
	for (i = n - k + 1; i <= n; i++)
		facN *= i;
	for (i = 1; i <= k; i++)
		facK *= i;
	return facN / facN;

}
int getDistinctPermutation(int n, int k)
{
	int i = 1, facK = 1;
	for (; i <= k; i++)
		facK *= i;
	return getDistinctCombination(n, k)*facK;


}
ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
{
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	ListNode * resHead = (ListNode*)(malloc(sizeof(ListNode)));
	ListNode *temp = resHead;
	temp->next = NULL;
	ListNode* temp1 = head1, *temp2 = head2;
	while (temp1&&temp2)
	{
		if (temp1->val < temp2->val)
		{
			temp->next = temp1;
			temp1 = temp1->next;
		}
		else
		{
			temp->next = temp2;
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	if (temp1)
		while (temp1)
		{
			temp->next = temp1;
			temp1 = temp1->next;
			temp = temp->next;
		}
	else if (temp2)
		while (temp2)
		{
			temp->next = temp2;
			temp2 = temp2->next;
			temp = temp->next;
		}
	return resHead->next;
}




