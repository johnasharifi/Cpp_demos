#pragma once

template <typename T> 
class BinaryTree {
private:
	int quantity = 0;
	T item;
	BinaryTree* node1 = NULL;
	BinaryTree* node2 = NULL;

public:
	BinaryTree<T>(T _v) {
		item = _v;
		quantity++;
	}

	void Insert(T _v) {
		if (item == _v) {
			quantity++;
		}
		if (_v < item) {
			if (node1 == NULL)
				node1 = new BinaryTree<T>(_v);
			else node1->Insert(_v);
		}
		if (_v > item) {
			if (node2 == NULL)
				node2 = new BinaryTree<T>(_v);
			else node2->Insert(_v);
		}
	}

	void FreeMem() {
		if (node1 != NULL) node1->FreeMem();
		if (node2 != NULL) node2->FreeMem();
		delete(node1);
		delete(node2);
	}

	T GetMin() {
		if (node1 != NULL)
			return(node1->GetMin());
		return(item);
	}

	T GetMax() {
		if (node2 != NULL)
			return(node2->GetMax());
		return(item);
	}
};