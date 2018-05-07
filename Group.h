#pragma once
#include <memory>
#include <vector>

template <class T>
class Group
{
protected:
	std::vector<std::unique_ptr<T>> children;
public:
	int getSize();
	void pop_back();
	void add(T *newComponent);
//	void add(std::unique_ptr<T> &newComponent);
	void remove(T *componentInstance);
	bool remove(int index);
	T& get(int index);
	virtual ~Group() = 0 {};
};


template<class T>
void Group<T>::add(T *newComponent)
{
	children.emplace_back(newComponent);
}

/*
template<class T>
void Group<T>::add(std::unique_ptr<T>& newComponent)
{
children.push_back(newComponent);
}
*/

template<class T>
void Group<T>::remove(T * componentInstance)
{
	std::vector<std::unique_ptr<T>>::iterator itr;
	for (itr = children.begin(); itr != children.end(); itr++)
		if (itr.get() == componentInstance)
			children.erase(itr);
}

template<class T>
bool Group<T>::remove(int index)
{
	if (index > children.size())
		return false;
	std::vector<std::unique_ptr<T>>::iterator itr;
	itr = children.begin();
	itr = itr + index;
	children.erase(itr);
	return true;
}

template<class T>
T& Group<T>::get(int index)
{
	return children[index].get();
}

template<class T>
int Group<T>::getSize() {
	return children.size();
}

template<class T>
void Group<T>::pop_back()
{
	children.pop_back();
}
