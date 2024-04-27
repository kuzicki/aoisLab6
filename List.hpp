#pragma once
#include "ListNode.hpp"

template<class KT, class T>
class List {
public:
	List() {
		head = nullptr;
	}

	void Add(KT key, T data) {
		ListNode<KT, T>* newNode = new ListNode<KT, T>(this, key, data);
		newNode->isHead = true;
		if (!head) {
			head = newNode;
			newNode->next = nullptr;
			return;
		}
		newNode->next = head;
		head->isHead = false;
		head->prev = newNode;
		head = newNode;
	}

	void Remove(KT key) {
		ListNode<KT, T>* iterNode = head;
		while (iterNode) {
			if (iterNode->key == key) {
				if (iterNode->prev) {
					iterNode->prev->next = iterNode->next;
				}
				if (iterNode->next) {
					iterNode->next->prev = iterNode->prev;
				}
				if (head == iterNode) {
					if (!iterNode->next) {
						head = iterNode->next;
					}
					else {
						head = nullptr;
					}
				}
				delete iterNode;
				return;
			}
			iterNode = iterNode->next;
		}
	}

	void Update(KT key, T newData) {
		ListNode<KT, T>* iterNode = head;
		while (iterNode) {
			if (iterNode->key == key) {
				iterNode->data = newData;
				return;
			}
			iterNode = iterNode->next;
		}
	}

	T GetData(KT key) {
		ListNode<KT, T>* iterNode = head;
		while (iterNode) {
			if (iterNode->key == key) {
				return iterNode->data;
			}
			iterNode = iterNode->next;
		}
	}

	ListNode<KT, T>* GetElement(KT key) {
		ListNode<KT, T>* iterNode = head;
		while (iterNode) {
			if (iterNode->key == key) {
				return iterNode;
			}
			iterNode = iterNode->next;
		}
		return nullptr;
	}

	~List() {
		ListNode<KT, T>* nodeToDelete;
		while (head) {
			nodeToDelete = head;
			head = head->next;
			delete nodeToDelete;
		}
	}

	ListNode<KT, T>*& GetHead() { return head; }

private:
	ListNode<KT, T>* head;
};