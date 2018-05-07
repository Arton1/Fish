#pragma once
#include "Object.h"
#include <vector>
#include <algorithm>

template <class T = sf::Drawable >
class DrawableGroup : public T
{
protected:
	std::vector<T*> children;
public:
	int getSize();
	void pop_back();
	void add(T *newComponent);
	void remove(T *componentInstance);
	bool remove(int index);
	T& getComponent(int index);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	DrawableGroup() {};
	virtual ~DrawableGroup();
};

template<class T>
DrawableGroup<T>::~DrawableGroup()
{
	for (int i = 0; i < children.size(); i++)
		delete children[i];
}

template<class T>
void DrawableGroup<T>::add(T *newComponent)
{
	children.push_back(newComponent);
}

template<class T>
void DrawableGroup<T>::remove(T * componentInstance)
{
	std::vector<Drawable*>::iterator itr = find(children.begin(), children.end(), componentInstance);
	if (itr != children.end())
	{
		children.erase(itr);
	}
}

template<class T>
bool DrawableGroup<T>::remove(int index)
{
	if (index > children.size())
		return false;
	std::vector<T*>::iterator itr;
	itr = children.begin();
	itr = itr + index;
	children.erase(itr);
	return true;
}

template<class T>
T& DrawableGroup<T>::getComponent(int index)
{
	return *children[index];
}

template<class T>
void DrawableGroup<T>::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < children.size(); i++) {
		target.draw(*children[i]);
	}
}
template<class T>
int DrawableGroup<T>::getSize() {
	return children.size();
}

template<class T>
inline void DrawableGroup<T>::pop_back()
{
	children.pop_back();
}
