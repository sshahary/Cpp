/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:35:50 by sshahary          #+#    #+#             */
/*   Updated: 2024/04/03 10:25:59 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **argv)
{
	if (ac < 2)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	}
	for (int i = 1; argv[i] != NULL; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				argv[i][j] -= 32;
			std::cout<<argv[i][j];
		}
	}
	return (0);
}