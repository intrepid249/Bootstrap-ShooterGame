#pragma once

/** With help from Sebastian Toy*/
template <class K, class V>
class TreeMap {
public:
	struct PairNode {
		PairNode(K _first, V _second = V()) : first(_first), second(_second) {}

		K first;
		V second;
	};

	struct TreeNode {
		TreeNode(PairNode *_pair) : m_pair(_pair) {}

		K getFirst() { return m_pair->first; }
		V& getSecond() { return m_pair->second; }

		// Check if there is a valid left-hand node
		bool hasValidLeft() {
			if (m_left)
				return !m_left->visited;
			return false;
		}
		// Check if there is a valid right-hand node
		bool hasValidRight() {
			if (m_right)
				return !m_right->visited;
			return false;
		}
		// See if there's any unvisited children at any of the visited parents
		TreeNode *getFamilyParent() {
			TreeNode *currentParent = m_parent;

			while (currentParent) {
				// A parent with unvisited children still exists, not at the end
				if (currentParent->hasValidLeft() || currentParent->hasValidRight())
					return currentParent;
				currentParent = currentParent->m_parent;
			}
			return nullptr;
		}

		PairNode *m_pair = nullptr;
		TreeNode *m_parent = nullptr, *m_left = nullptr, *m_right = nullptr;
		bool visited = false;
	};

	struct TreeIterator {
		TreeIterator(TreeNode *_ptr) : m_ptr(_ptr) {}

		K& getFirst() { return m_ptr->getFirst(); }

		/** Climb up current node's parents until the at the root node*/
		TreeNode *getRoot() {
			TreeNode *rootNode = this->m_ptr;
			while (rootNode->m_parent)
				rootNode = rootNode->m_parent;
			return rootNode;
		}
		
		/** Reset visited status of all tree nodes so the tree can be traversed again*/
		void resetTraversal(TreeNode *_node) {
			if (_node) {
				// Recursively destroy left sub-tree
				resetTraversal(_node->m_left);

				// Set node to unvisited
				_node->visited = false;

				// Recursively destroy right sub-tree
				resetTraversal(_node->m_right);
			}
		}

		PairNode& operator *() {
			return *(m_ptr->m_pair);
		}

		// Prefix operator
		TreeIterator& operator++() {
			// 1. node has unvisited left child, move to it
			if (m_ptr->hasValidLeft()) {
				m_ptr->m_left->visited = true;
				m_ptr = m_ptr->m_left;
				return *this;
			}

			// 2. node has unvisited left child, move to it
			if (m_ptr->hasValidRight()) {
				m_ptr->m_right->visited = true;
				m_ptr = m_ptr->m_right;
				return *this;
			}

			/// 3. Node has no valid children move to unvisited parent or next valid child
			TreeNode *currentParent = m_ptr->m_parent;

			// Find first unvisited parent
			while (currentParent) {
				if (!currentParent->visited) {
					currentParent->visited = true;
					m_ptr = currentParent;
					return *this;
				}
				currentParent = currentParent->m_parent;
			}

			// Definitely no parent, but there might be unvisited children
			TreeNode *familyParent = m_ptr->getFamilyParent(); // Find parent with unvisited children
			if (familyParent) {
				*this = ++TreeIterator(familyParent); // Use recursion to set iterator to valid child
				return *this;
			}

			/// 4. Node is at the end. It has no more unvisited parents AND no more unvisited children
			resetTraversal(getRoot());
			m_ptr = nullptr;

			return *this;
		}

		// Postfix
		TreeIterator operator++(int) {
			TreeIterator result(*this);
			++(*this);
			return result;
		}

		// Check for sentinal node
		bool operator != (TreeIterator _iter) {
			return m_ptr != _iter.m_ptr;
		}

		TreeNode *m_ptr = nullptr;
	};

	TreeMap() = default;
	~TreeMap() { 
		clear(); 
	}

	TreeIterator begin() { return TreeIterator(getFirstNode()); }
	TreeIterator end() { return TreeIterator(nullptr); }

	/** Get the currently left-most element in binary tree*/
	TreeNode *getFirstNode() {
		if (!m_rootNode) return nullptr;

		TreeNode *currentNode = m_rootNode;
		while (currentNode->m_left) {
			currentNode = currentNode->m_left;
		}
		currentNode->visited = true;
		return currentNode;
	}

	void clear() {
		if (m_rootNode)
			recurDestroy(m_rootNode);
	}

	// Add a pair to the map and sort it into the binary tree
	void Insert(PairNode *_pair) {
		TreeNode *targetParent = nullptr;
		TreeNode *newNode = new TreeNode(_pair);

		// Binary Tree is empty, set root node
		if (m_rootNode == nullptr) {
			m_rootNode = newNode;
			return;
		}

		// Search starts at root of tree
		TreeNode *currentParent = m_rootNode;

		// Find the target parent with position for new child
		while (currentParent) {
			targetParent = currentParent;
			// There are duplicate keys, insert aborted
			if (_pair->first == currentParent->getFirst()) {
				// Take resposibility of dynamically allocated memory and free up memory for unused nodes
				delete newNode;
				delete _pair;
				return;
			}

			// Move to right-child if key is greater, left if key is smaller
			if (_pair->first > currentParent->getFirst())
				currentParent = currentParent->m_right;
			else
				currentParent = currentParent->m_left;
		}

		// Set new node relative to found parent
		newNode->m_parent = targetParent;
		if (_pair->first > targetParent->getFirst())
			targetParent->m_right = newNode;
		else
			targetParent->m_left = newNode;
	}

	/** Search for matching key. Returns iterator to end if no match found*/
	PairNode *find(const K _key) {
		// Iterate through the entire tree
		for (auto iter = begin(); iter != end(); ++iter) {
			if (iter.m_ptr->getFirst() == _key) {// If the matching key is found
				iter.resetTraversal(m_rootNode);
				return iter.m_ptr->m_pair;
			}
		}

		// No key found
		return nullptr;
	}

	V& operator [] (const K &_key) {
		PairNode *iter = find(_key);
		if (iter)
			return (*iter).second;

		return insertDefault(_key)->second;
	}

private:
	PairNode* insertDefault(const K &_key) {
		PairNode *newNode = new PairNode(_key);
		Insert(newNode);
		return newNode;
	}

	// Recursion to destroy entire tree and clean up allocated memory
	void recurDestroy(TreeNode *_node) {
		// Nothing left in branch
		if (_node == nullptr) return;

		// Recursively destroy left branch
		if (_node->m_left)
			recurDestroy(_node->m_left);
		// Recursively destroy right branch
		if (_node->m_right)
			recurDestroy(_node->m_right);

		// Clean up current node
		delete _node->m_pair;
		_node->m_pair = nullptr;
		delete _node;
		_node = nullptr;
	}

	TreeNode *m_rootNode = nullptr;
};