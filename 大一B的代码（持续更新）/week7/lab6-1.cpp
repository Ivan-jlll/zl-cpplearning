#include <iostream>
using namespace std;

// ��������������
struct Node
{
	double value;
	Node *next{ nullptr };
};

void printList(Node *head);                // ��ӡ����
void dropList(Node *head);                 // �������
int get_len(Node *head);                   // ��ȡ������
void concatList(Node *head1, Node *head2); // ���ڶ����������ӵ���һ������β��
void shiftList(Node *&head, int n);        // ѭ������ n λ
void printNode(Node *pNode);               // ��ӡ��������
void rm_node(Node *&head, int idx);        // ��������ɾ�����
void push(Node *&head, Node *pNode);       // �����ѹ������
Node *pop(Node *&head);                    // ����ͷ���
Node *pop(Node *&head, int idx);           // ���� idx λ�õĽ��
Node *fetch(Node *head, int idx);          // ��ȡ idx λ�õĽ��
Node *fetch_prev(Node *head, int idx);     // ��ȡ idx λ�ý���ǰ�����
Node *fetch_last(Node *head);              // ��ȡβ���
Node *search(Node *head, double x);        // ����ֵ���ҽ��

int main()
{
	// ����������
	Node *head = nullptr;

	Node *aNode;

	// ��ӽ��
	for (int i = 10; i >= 0; --i)
	{
		aNode = new Node; // �����½��
		aNode->value = i; // �洢ֵ
		push(head, aNode);
	}
	printList(head);                             // ���: 0 1 2 3 4 5 6 7 8 9 10
	cout << "Length: " << get_len(head) << endl; // �����Length: 11

	// ����ָ��λ�ý��
	printNode(pop(head, 7)); // ���: 7
	printList(head);         // ���: 0 1 2 3 4 5 6 8 9 10

	// ���ֵΪ6�Ľ���̵�ֵ
	cout << search(head, 6)->next->value << endl; // ���: 8

	// �������
	printNode(pop(head)); // ���: 0
	printList(head);      // ���: 1 2 3 4 5 6 8 9 10

	// �Ƴ����
	rm_node(head, 7);
	printList(head); // ���: 1 2 3 4 5 6 8 10

	// ��ȡָ��λ�õĽ��
	printNode(fetch(head, 2));  // ���: 3
	printNode(fetch(head, 6));  // ���: 8
	printNode(fetch(head, 10)); // ���: Invalid node

	// ��ȡβ���
	printNode(fetch_last(head)); // ���: 10

	// �½��б�
	Node *head2 = nullptr;

	// ��ӽ��
	for (int i = 3; i >= 0; --i)
	{
		aNode = new Node;      // �����½��
		aNode->value = i * 10; // �洢ֵ
		push(head2, aNode);
	}
	printList(head2); // ���: 0 10 20 30

	// ��������
	concatList(head, head2);
	printList(head); // ���: 1 2 3 4 5 6 8 10 0 10 20 30

	// ��������
	shiftList(head, 3);
	printList(head); // ���: 4 5 6 8 10 0 10 20 30 1 2 3

	// ��������
	shiftList(head, -4);
	printList(head); // ���: 30 1 2 3 4 5 6 8 10 0 10 20

	// ɾ���б�
	dropList(head); // ���: List has been DROPPED!
	return 0;
}


void printList(Node *head)
{
	Node *pCur = head;
	while (pCur)
	{
		cout << pCur->value << ' ';
		pCur = pCur->next;
	}
	cout << endl;
	return;
}

int get_len(Node *head)
{
	Node *pCur = head;
	if (!head)
		return 0;
	int len = 1;
	while (pCur->next)
	{
		pCur = pCur->next;
		++len;
	}
	return len;
}

void printNode(Node *pNode)
{
	if (pNode)
		cout << pNode->value << endl;
	else 
		cout << "Invalid node" << endl;
}

Node *fetch(Node *head, int idx) {
	Node *pCur = head;
	if (idx > get_len(head)) { 
		pCur = nullptr; return pCur; 
	}
	for (int i = 0; i < idx; i++) {
		pCur = pCur->next;
	}
	return pCur;
}

Node *fetch_prev(Node *head, int idx)
{
	if (idx <= 0)
		return nullptr;
	return fetch(head, idx - 1);
}

Node *fetch_last(Node *head) {
	Node *pCur = head;
	int pp = get_len(head);
	for (int i = 0;i < pp - 1 ; i++) {
		pCur = pCur->next;
	}
	return pCur;
}

void rm_node(Node *&head, int idx)
{
	delete pop(head, idx);
	return;
}

void concatList(Node *head1, Node *head2)
{
	fetch_last(head1)->next = head2;
	return;
}

void push(Node *&head, Node *pNode) {
	pNode->next = head;
	head = pNode;
}

void dropList(Node *head) {
	Node *pCur = head;
	
	while (pCur != nullptr) {
		Node *pTemp = pCur->next;
		delete pCur;
		pCur = nullptr;
		pCur = pTemp;
	}
	cout << "List has been DROPPED!\n";
}

void shiftList(Node *&head, int n) {
	Node *pCur = head;
	
	int len;
	len = get_len(head);
	if (n > 0) {
		for (int i = 1; i <= n; i++) {
			pCur = pCur->next;
		}
		Node *pPre = fetch_prev(head, n);
		Node *pLast = fetch_last(head);
		pLast->next = head;
		pPre->next = nullptr;
		head = pCur;
	}
	else {
		for (int i = 1; i <=len + n; i++) {
			pCur = pCur->next;
		}
		Node *pPre = fetch_prev(head, len + n);
		Node *pLast = fetch_last(head);
		pLast->next = head;
		pPre->next = nullptr;
		head = pCur;
	}
}

Node *pop(Node *&head) {
	Node *pCur = head;
	head = head->next;
	return pCur;
}

Node *pop(Node *&head, int idx) {
	Node *pCur = fetch(head, idx);
	Node *pPre = fetch_prev(head, idx);
	pPre->next = pCur->next;
	return pCur;
}

Node *search(Node *head, double x) {
	Node *pCur = head;
	while (pCur->value != x) {
		pCur = pCur->next;
	}
	return pCur;
}