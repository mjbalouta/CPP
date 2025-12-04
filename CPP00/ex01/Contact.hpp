/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:08:24 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/12/04 19:44:33 by mjoao-fr         ###   ########.fr       */
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
		void setFirstName(std::string &firstName);
		void setLastName(std::string &lastName);
		void setNickname(std::string &nickname);
		void setPhoneNumber(std::string &phoneNumber);
		void setDarkestSecret(std::string &darkestSecret);

		void getFirstName() const;
		void getLastName() const;
		void getNickname() const;
		void getPhoneNumber() const;
		void getDarkestSecret() const;
};