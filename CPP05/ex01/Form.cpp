/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:40:57 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/28 14:31:03 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() 
: _name("Default"), _signature(false), _gradeToSign(150), _gradeToExecute(150) 
{}

Form::Form(std::string name, const int gradeToSign, const int gradeToExecute)
: _name(name), _signature(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToExecute > 150 || _gradeToSign > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& copy) 
: _name(copy._name), _signature(copy._signature), _gradeToSign(copy._gradeToSign), 
_gradeToExecute(copy._gradeToExecute) {}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
		_signature = copy._signature;
	return *this;
}

Form::~Form() {}

const std::string Form::getName() const
{
	return (_name);
}

bool Form::getSignature() const
{
	return (_signature);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_signature = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << (f.getSignature() ? " is signed" : " is not signed");
	return os;
}