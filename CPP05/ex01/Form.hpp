/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:12:54 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/28 14:43:26 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
	const std::string _name;
	bool _signature;
	const int _gradeToSign;
	const int _gradeToExecute;
	
	public:
	Form();
	Form(std::string name, const int gradeToSign, const int gradeToExecute);
	Form(const Form& copy);
	Form& operator=(const Form& copy);
	~Form();
	
	const std::string getName() const;
	bool getSignature() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat& bureaucrat);
	
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Form's grade too high.";
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Form's grade too low.";
		}
	};	
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif