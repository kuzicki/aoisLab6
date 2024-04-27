#pragma once
#include "List.hpp"
#include <stdexcept>
#include <array>

template <class KT, class T, size_t Size>
class HashTable {
public:
	HashTable() {
		_size = Size;
	}

	void Add(KT key, T data) {
		int index = hashFunction(key);
		table[index].Add(key, data);
	}

	void Remove(KT key) {
		int index = hashFunction(key);
		table[index].Remove(key);
	}

	void Update(KT key, T newData) {
		int index = hashFunction(key);
		table[index].Update(key, newData);
	}

	ListNode<KT, T>& operator[](KT key) {
		int index = hashFunction(key);
		ListNode<KT, T>* node = table[index].GetElement(key);
		if (node == nullptr) {
			throw std::runtime_error("No such element");
		}
		return *node;
	}
private:
	size_t hashFunction(const KT& key) {
		return std::hash<KT>{}(key) % _size;
	}
	size_t _size;
	std::array<List<KT, T>, Size> table;
};