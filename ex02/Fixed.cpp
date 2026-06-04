/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:39:20 by afournie          #+#    #+#             */
/*   Updated: 2026/06/04 11:52:37 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	fixed_point = 0;
}

Fixed::Fixed(const int number)
{
	fixed_point = number << fractionnal;
}

Fixed::Fixed(const float number)
{
	fixed_point = roundf(number * (1 << fractionnal));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::~Fixed()
{
	return ;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	this->fixed_point = other.fixed_point;
	return (*this);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->fixed_point + other.fixed_point);
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->fixed_point - other.fixed_point);
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->fixed_point * other.fixed_point) >> fractionnal);
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->fixed_point << fractionnal) / other.fixed_point);
	return (result);
}

Fixed& Fixed::operator++()
{
	fixed_point += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	fixed_point += 1;
	return tmp;
}

Fixed& Fixed::operator--()
{
	fixed_point -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	fixed_point -= 1;
	return tmp;
}

int Fixed::getRawBits(void) const
{
	return (this->fixed_point);
}

void Fixed::setRawBits(int raw)
{
	this->fixed_point = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)fixed_point / (1 << fractionnal));
}

int Fixed::toInt( void ) const
{
	return (fixed_point >> fractionnal);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->fixed_point > other.fixed_point);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->fixed_point < other.fixed_point);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->fixed_point >= other.fixed_point);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->fixed_point <= other.fixed_point);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->fixed_point == other.fixed_point);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->fixed_point != other.fixed_point);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}
