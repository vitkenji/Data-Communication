#pragma once
#include <iostream>

namespace Math
{
	template <typename T>
	class Coordinate
	{
	public:
		T x;
		T y;

		Coordinate(T x, T y);
		Coordinate();
		~Coordinate();

		Coordinate<T> operator + (Coordinate<T> other);
		Coordinate<T> operator - (Coordinate<T> other);
		Coordinate<T> operator * (Coordinate<T> other);
		Coordinate<T> operator / (Coordinate<T> other);
		Coordinate<T> operator * (double scalar);
		Coordinate<T> operator / (double scalar);

		void operator = (Coordinate<T> other);
		void operator += (Coordinate<T> other);
		void operator -= (Coordinate<T> other);
		void operator *= (double scalar);
		void operator /= (double scalar);
	};

	typedef Coordinate<unsigned int> CoordinateU;
	typedef Coordinate<float> CoordinateF;
	typedef Coordinate<double> CoordinateD;
	typedef Coordinate<int> CoordinateI;

	template<typename T>
	Coordinate<T>::Coordinate(T x, T y)
	{
		this->x = x;
		this->y = y;
	}

	template<typename T>
	Coordinate<T>::Coordinate()
	{
		this->x = 0;
		this->y = 0;
	}

	template<typename T>
	Coordinate<T>::~Coordinate()
	{

	}

	template<typename T>
	Coordinate<T> Coordinate<T>::operator + (Coordinate<T> other)
	{
		return (Coordinate<T>(this->x + other.x, this->y + other.y));
	}

	template<typename T>
	Coordinate<T> Coordinate<T>::operator - (Coordinate<T> other)
	{
		return (Coordinate<T>(this->x - other.x, this->y - other.y));
	}

	template<typename T>
	Coordinate<T> Coordinate<T>::operator * (Coordinate<T> other)
	{
		return (Coordinate<T>(this->x * other.x, this->y * other.y));
	}

	template<typename T>
	Coordinate<T> Coordinate<T>::operator / (Coordinate<T> other)
	{
		if (other.x != 0 && other.y != 0)
		{
			return (Coordinate<T>(this->x / other.x, this->y / other.y));
		}
		else
		{
			std::cout << "Error: cannot divide by 0" << std::endl;
			return;
		}
	}

	template<typename T>
	Coordinate<T> Coordinate<T>::operator * (double scalar)
	{
		return (Coordinate<T>(this->x * scalar, this->y * scalar));
	}

	template<typename T>
	Coordinate<T> Coordinate<T>::operator / (double scalar)
	{
		if (scalar != 0)
		{
			return (Coordinate<T>(this->x / scalar, this->y / scalar));
		}
		else
		{
			std::cout << "Error: cannot divide by 0" << std::endl;
			return;
		}
	}

	template<typename T>
	void Coordinate<T>::operator = (Coordinate<T> other)
	{
		this->x = other.x;
		this->y = other.y;
	}

	template<typename T>
	void Coordinate<T>::operator += (Coordinate<T> other)
	{
		this->x += other.x;
		this->y += other.y;
	}

	template<typename T>
	void Coordinate<T>::operator -= (Coordinate<T> other)
	{
		this->x -= other.x;
		this->y -= other.y;
	}

	template<typename T>
	void Coordinate<T>::operator *= (double scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
	}

	template<typename T>
	void Coordinate<T>::operator /= (double scalar)
	{
		if (scalar != 0)
		{
			this->x /= scalar;
			this->y /= scalar;
		}
		else { std::cout << "Error: cannot divide by 0" << std::endl; }
	}

}