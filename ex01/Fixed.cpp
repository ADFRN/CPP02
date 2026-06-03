/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:39:20 by afournie          #+#    #+#             */
/*   Updated: 2026/06/03 12:02:56 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_point = 0;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point = number << fractionnal;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point = roundf(number * (1 << fractionnal));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	this->fixed_point = other.fixed_point;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point);
}

void Fixed::setRawBits(int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
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
