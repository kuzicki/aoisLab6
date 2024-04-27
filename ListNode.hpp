#pragma once

template<class KT, class T>
class List;

template<class KT, class T>
class ListNode {
public:
	ListNode(List<KT, T>* parentList, KT key, T data) : list(parentList),
		key(key), data(data) {
		isHead = false;
		prev = nullptr;
		next = nullptr;
	}

	void Remove() {

		if (prev) {
			prev->next = next;
		}
		if (next) {
			next->prev = prev;
		}
		if (isHead) {
			ListNode<KT, T>*& head = list->GetHead();
			if (next) {
				next->isHead = true;
				head = next;
			}
			else {
				head = nullptr;
			}

		}
		delete this;
	}

	T GetData() {
		return data;
	}

	void operator=(T newData) {
		data = newData;
	}

	T data;
	KT key;
	ListNode<KT, T>* next;
	ListNode<KT, T>* prev;
	bool isHead;
	List<KT, T>* list;
};