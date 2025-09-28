#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T>
class Array
{
private:
	T *array;
	unsigned int len;

public:
	Array() : array(new T[0]), len(0) {};

	Array(unsigned int n) : array(new T[n]), len(n) {};

	Array(Array const &o) : array(new T[o.len]), len(o.len)
	{
		for (unsigned int i = 0; i < o.len; i++)
			this->array[i] = o.array[i];
	}

	Array &operator=(Array const &rhs)
	{
		if (this != rhs)
		{
			if (this->array != NULL)
				delete[] this->array;
			this->len = rhs.len;
			this->array = new T[rhs.len];
			for (unsigned int i = 0; i < rhs.len; i++)
				this->array[i] = rhs.array[i];
		}
		return (*this);
	}

	~Array()
	{
		if (this->array != NULL)
			delete[] this->array;
	};

	T &operator[](unsigned int i)
	{
		if (i < this->len)
			return this->array[i];
		else
			throw OutOfBounds();
	}

	class OutOfBounds : public std::exception
	{
		const char *what() const throw()
		{
			return ("Out Of Bounds");
		}
	};

	unsigned int size() const { return this->len; }
};

#endif
