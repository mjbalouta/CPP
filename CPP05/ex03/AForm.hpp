/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:12:54 by mjoao-fr          #+#    #+#             */
/*   Updated: 2026/01/30 13:29:23 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
	const std::string _name;
	bool _signature;
	const int _gradeToSign;
	const int _gradeToExecute;
	
	protected:
	virtual void executeAction() const = 0; //because each form will execute a different action

	public:
 	AForm();
	AForm(std::string name, const int gradeToSign, const int gradeToExecute);
	AForm(const  AForm& copy);
	AForm& operator=(const AForm& copy);
	virtual ~AForm();
	
	const std::string getName() const;
	bool getSignature() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat& bureaucrat);
	void execute(Bureaucrat const & executor) const;
	
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

	class FormNotSignedException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "The form is not signed.";
		}
	};

	class FormNotFoundException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return "Form not found.";
		}
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif