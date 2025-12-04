/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:08:24 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/12/04 22:17:29 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
		
	public:
		void setFirstName(const std::string &firstName);
		void setLastName(const std::string &lastName);
		void setNickname(const std::string &nickname);
		void setPhoneNumber(const std::string &phoneNumber);
		void setDarkestSecret(const std::string &darkestSecret);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
};