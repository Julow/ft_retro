/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HitBox.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 13:24:15 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/11 13:49:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITBOX_HPP
# define HITBOX_HPP

# include "ft_retro.hpp"

class	HitBox
{
public:
	HitBox(int x, int y, int width, int height);
	HitBox(HitBox const &src);
	virtual ~HitBox(void);

	bool				collide(HitBox const &box) const;

	HitBox				&operator=(HitBox const &rhs);

protected:
	int					_x;
	int					_y;
	int					_width;
	int					_height;

private:
	HitBox(void);
};

#endif
