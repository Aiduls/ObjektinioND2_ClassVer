#pragma once

#include <iostream>
#include <memory>
#include <algorithm>

//using namespace std;

template <class T> class Vector {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;

	// konstruktoriai
	Vector() { create(); } // create - uz atminties isskyrima
	explicit Vector(size_type n, const T& val = T{}) { create(n, val); }

	/// rule of three
	// copy konstruktorius
	Vector(const Vector& v) { create(v.begin(), v.end()); }

	// priskyrimo operatorius
	Vector& operator=(const Vector&);

	// destruktorius
	~Vector() { uncreate(); }

	// indeksavimas
	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }


	/// Metodai

	// push_back() realizacija
	void push_back(const T& element);

	// assign metodas
	T assign(int vectorSize, T element);

	// size() gavimas
	size_type size() const { return limit - data; }

	// Iteratoriu grazinimas
	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return limit; }
	const_iterator end() const { return limit; }

private:
	iterator data;	// pirmasis Vector elementas
	iterator avail; // pirmasis po paskutiniojo SUKONSTRUOTO Vector elementas
	iterator limit;	// pirmasis po paskutiniojo Vector elementas

	std::allocator<T> alloc; // objektas atminties valdymui

	// isskirti atminti (array) ir ja inicializuoti
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// sunaikinti elementu array ir atlaisvinti atminti
	void uncreate();

	// pagalbines funkcijos push_back realizacijai
	void grow();
	void unchecked_append(const T&);
};

template <class T> 
Vector<T>& Vector<T>::operator=(const Vector& rhs) {
	// patikriname, ar nelygu
	if (&rhs != this) {
		uncreate();		// atlaisviname sena this objekto atminti
		create(rhs.begin(), rhs.end()); // perkopijuojame elementus is rhs i lhs (this)
	}
	return *this;
}

template <class T> class allocator {
public:
	T* allocate(size_t);
	void deallocate(T*, size_t);
	void construct(T*, const T&);
	void destroy(T*);
};

// Nukopijuoja duota value i neinicializuota atminties lauka intervale [first, last)
template<class ForwardIt, class T>
void uninitialized_fill(ForwardIt first, ForwardIt last, const T& value);

// Nukopijuoja elementus is intervalo [first, last) i neinicializuota atminties lauka, kuris prasideda d_first
template<class InputIt, class ForwardIt>
ForwardIt uninitialized_copy(InputIt first, InputIt last, ForwardIt d_first);

template <class T> void Vector<T>::create() {
	data = avail = limit = nullptr; // vektorius be elementu - ptr i nesama elementa yra nullptr
}
template <class T> void Vector<T>::create(size_type n, const T& val) {
	data = alloc.allocate(n);			  // grazina ptr i array pirma elementa
	limit = avail = data + n;			  // sustato rodykles i vietas
	uninitialized_fill(data, limit, val); // inicializuoja elementus val reiksme
}
template <class T>
void Vector<T>::create(const_iterator i, const_iterator j) {
	data = alloc.allocate(j - i);					// isskirti vietos j-i elementams
	limit = avail = uninitialized_copy(i, j, data); // nukopijuoja elementus is intervalo
}

template <class T> void Vector<T>::uncreate() {
	if (data) {
		// sunaikinti (atbuline tvarka) sukonstruotus elementus
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);
		// atlaisvinti isskirta atminti. Turi buti data != nullptr
		alloc.deallocate(data, limit - data);
	}

	// reset'inam pointer'ius - Vector'ius tuscias
	data = limit = avail = nullptr;
}

template <class T> void Vector<T>::grow() {
	// dvigubai daugiau vietos, nei buvo
	size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

	// isskirti nauja vieta ir perkopijuoti egzistuojancius elementus
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = uninitialized_copy(data, avail, new_data);

	// atlaisvinti sena vieta
	uncreate();

	// reset'int rodykles i naujai isskirta vieta
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

// tariame, kad `avail` point'ina i isskirta, bet neinicializuota vieta
template <class T> void Vector<T>::unchecked_append(const T& val) {
	alloc.construct(avail++, val);
}

template <class T> T Vector<T>::assign(int size, T element) {
	if (size < 0) {
		throw std::out_of_range("Out of bounds");
	}
	else {
		uncreate();
		create(size, element);
	}
}

template <class T> void Vector<T>::push_back(const T& val) {
	if (avail == limit) 
		grow();				   // jei reikia, isskiriama vietos
	unchecked_append(val); // ideda nauja elementa
}