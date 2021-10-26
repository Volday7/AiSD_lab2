#pragma once
#include <stdio.h>
#include <math.h>
#include <iostream>

template <class T>

class Polynom {
private:
	int n;
	struct node {
		int i;
		T coef;
		node* next;
	};
	struct dyn_node {
		node* head;
		node* tail;
	};
	dyn_node l;
public:
	Polynom<T>(int degree) {
		if (degree < 0) throw "Invalid degree";
		else {
			l.head = NULL;
			n = degree;
			for (int j = 0; j <= n; j++) {
				node* tmp = new node();
				tmp->coef = 1;
				tmp->i = n - j;
				tmp->next = NULL;
				if (l.head == NULL) l.head = tmp;
				else l.tail->next = tmp;
				l.tail = tmp;
			}
		}
	}

	T operator[](int index) {
		if ((index >= 0) && (index <= n)) {
			Polynom<T> copy(n);
			copy.l = l;
			for (int j = 0; j < fabs(n - index); j++)
				copy.l.head = copy.l.head->next;
			return copy.l.head->coef;
		}
		else throw "Invalid index";
	}

	void Set(T newcoef, int degree) {
		if ((degree >= 0) && degree <= n) {
			Polynom<T> copy(n);
			copy.l = l;
			Polynom<T> help(n);
			help.l = l;
			if (degree == n) {
				copy.l.head->coef = newcoef;
			}
			else {
				while (copy.l.head->i != degree) {
					help = copy;
					copy.l.head = copy.l.head->next;
				}
				if (newcoef != (T)0) {
					copy.l.head->coef = newcoef;
				}
				else {
					help.l.head->next = copy.l.head->next;
				}
			}
		}
		else throw "Invalid degree";
	}

	dyn_node GetL() noexcept {
		return l;
	}

	Polynom operator+(Polynom<T>& rhs) {
		if (n == rhs.n) {
			Polynom<T> res(n);
			res.l = l;
			Polynom<T> plus(rhs.n);
			plus.l = rhs.l;
			while (res.l.head != res.l.tail->next) {
				if (res.l.head->i == plus.l.head->i) {
					res.l.head->coef += plus.l.head->coef;
					res.l.head = res.l.head->next;
					plus.l.head = plus.l.head->next;
				}
				else res.l.head = res.l.head->next;
			}
		}
		else {
			int maxn = 0;
			if (n > rhs.n ? maxn = n : maxn = rhs.n);
			Polynom<T> res(maxn);
			if (n > rhs.n) {
				res.l = l;
				Polynom<T> plus(rhs.n);
				plus.l = rhs.l;
				while (res.l.head != res.l.tail->next) {
					if (res.l.head->i == plus.l.head->i) {
						res.l.head->coef += plus.l.head->coef;
						res.l.head = res.l.head->next;
						plus.l.head = plus.l.head->next;
					}
					else res.l.head = res.l.head->next;
				}
			}
			else {
				Polynom<T> plus(n);
				plus.l = l;
				*this = rhs;
				res.l = l;
				while (res.l.head != res.l.tail->next) {
					if (res.l.head->i == plus.l.head->i) {
						res.l.head->coef += plus.l.head->coef;
						res.l.head = res.l.head->next;
						plus.l.head = plus.l.head->next;
					}
					else res.l.head = res.l.head->next;
				}

			}
		}
		return *this;
	}

	Polynom operator-(Polynom<T>& rhs) {
		if (n == rhs.n) {
			Polynom<T> res(n);
			res.l = l;
			Polynom<T> plus(rhs.n);
			plus.l = rhs.l;
			while (res.l.head != res.l.tail->next) {
				if (res.l.head->i == plus.l.head->i) {
					res.l.head->coef -= plus.l.head->coef;
					res.l.head = res.l.head->next;
					plus.l.head = plus.l.head->next;
				}
				else res.l.head = res.l.head->next;
			}
		}
		else {
			int maxn = 0;
			if (n > rhs.n ? maxn = n : maxn = rhs.n);
			Polynom<T> res(maxn);
			if (n > rhs.n) {
				res.l = l;
				Polynom<T> plus(rhs.n);
				plus.l = rhs.l;
				while (res.l.head != res.l.tail->next) {
					if (res.l.head->i == plus.l.head->i) {
						res.l.head->coef -= plus.l.head->coef;
						res.l.head = res.l.head->next;
						plus.l.head = plus.l.head->next;
					}
					else res.l.head = res.l.head->next;
				}
			}
			else {
				Polynom<T> plus(n);
				plus.l = l;
				*this = rhs;
				res.l = l;
				while (res.l.head != res.l.tail->next) {
					if (res.l.head->i == plus.l.head->i) {
						res.l.head->coef -= plus.l.head->coef;
						res.l.head = res.l.head->next;
						plus.l.head = plus.l.head->next;
					}
					else res.l.head = res.l.head->next;
				}

			}
		}
		return *this;
	}

	Polynom operator*(T scalar) {
		Polynom<T> res(n);
		res.l = l;
		while (res.l.head != res.l.tail->next) {
			res.l.head->coef *= scalar;
			res.l.head = res.l.head->next;
		}
		return *this;
	}

	T Result(T x) {
		T result = 0;
		Polynom<T> res(n);
		res.l = l;
		while (res.l.head != res.l.tail->next) {
			result += res.l.head->coef * (T)pow(x, res.l.head->i);
			res.l.head = res.l.head->next;
		}
		return result;
	}

	void PrintPolynom() {
		Polynom<T> copy(n);
		copy.l = l;
		std::cout << "" << copy.l.head->coef << "*x^" << copy.l.head->i;
		copy.l.head = copy.l.head->next;
		while (copy.l.head != copy.l.tail->next) {
			if (copy.l.head->coef != (T)0) {
				std::cout << " + (" << copy.l.head->coef << ")*x^" << copy.l.head->i<<"";
			}
			copy.l.head = copy.l.head->next;
		}
	}

	std::ostream& operator<<(std::ostream& out) noexcept {
		return out;
	}
};


