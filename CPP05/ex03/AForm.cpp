/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:40:57 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/28 15:02:16 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() 
: _name("Default"), _signature(false), _gradeToSign(150), _gradeToExecute(150) 
{}

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute)
: _name(name), _signature(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToExecute > 150 || _gradeToSign > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& copy) 
: _name(copy._name), _signature(copy._signature), _gradeToSign(copy._gradeToSign), 
_gradeToExecute(copy._gradeToExecute) {}

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
		_signature = copy._signature;
	return *this;
}

AForm::~AForm() {}

const std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSignature() const
{
	return (_signature);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_signature = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	else if (this->_signature == false)
		throw AForm::FormNotSignedException();
	executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << (f.getSignature() ? " is signed" : " is not signed");
	return os;
}