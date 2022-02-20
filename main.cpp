#include <bits/stdc++.h>
using namespace std;

// 構造体
struct Node {
    int val;
    Node* next;
    Node(int x) {
        this->val = x;
        this->next = NULL;
    }
};

class MyLinkedList {
   public:
    // head アドレスメモ
    Node* head;
    int size = 0;

    MyLinkedList() {}

    int get(int index) {
        // 例外
        if (index >= size) return -1;

        // index まで進む
        auto cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        // メンバーを作成
        Node* node = new Node(val);
        size++;

        // 空なら
        if (!head) {
            head = node;
            return;
        }

        // 追加 & head 更新
        node->next = head;
        head = node;
    }

    void addAtTail(int val) {
        // メンバーを作成
        Node* node = new Node(val);
        size++;

        // 空なら
        if (!head) {
            head = node;
            return;
        }

        // tail まで進む
        auto cur = head;
        if (cur) {
            while (cur->next) cur = cur->next;
        }

        // list に追加
        cur->next = node;
    }

    void addAtIndex(int index, int val) {
        // 例外
        if (index >= size) return;

        // メンバーを作成
        Node* node = new Node(val);
        size++;

        // 頭なら
        if (index == 0) {
            node->next = head;
            head = node;
            return;
        }

        // index まで進む
        auto cur = head;
        for (int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
    }

    void deleteAtIndex(int index) {
        if (size <= index) return;
        size--;
        if (index == 0) {
            head = head->next;
            return;
        }

        // index 直前まで進む
        auto cur = head;
        for (int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }
};

void solve() {
    /**
     * Your MyLinkedList object will be instantiated and called as such:
     * MyLinkedList* obj = new MyLinkedList();
     * int param_1 = obj->get(index);
     * obj->addAtHead(val);
     * obj->addAtTail(val);
     * obj->addAtIndex(index,val);
     * obj->deleteAtIndex(index);
     */
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(10);
    cout << obj->get(0) << endl;
    obj->addAtTail(3);
    cout << obj->get(1) << endl;
    cout << obj->get(2) << endl;
    obj->addAtIndex(1, 20);
    cout << obj->get(0) << endl;
    cout << obj->get(1) << endl;
    cout << obj->get(2) << endl;
    obj->deleteAtIndex(1);
    cout << obj->get(1) << endl;
}

int main() {
    solve();
    return 0;
}
