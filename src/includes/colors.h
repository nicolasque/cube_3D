/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:50:45 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/05 17:28:37 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

/* Regular text colors */
# define BLACK           "\033[0;30m"
# define RED             "\033[0;31m"
# define GREEN           "\033[0;32m"
# define YELLOW          "\033[0;33m"
# define BLUE            "\033[0;34m"
# define PURPLE          "\033[0;35m"
# define CYAN            "\033[0;36m"
# define WHITE           "\033[0;37m"

/* Bold text colors */
# define BOLD_BLACK      "\033[1;30m"
# define BOLD_RED        "\033[1;31m"
# define BOLD_GREEN      "\033[1;32m"
# define BOLD_YELLOW     "\033[1;33m"
# define BOLD_BLUE       "\033[1;34m"
# define BOLD_PURPLE     "\033[1;35m"
# define BOLD_CYAN       "\033[1;36m"
# define BOLD_WHITE      "\033[1;37m"

/* Underlined text colors */
# define UL_BLACK        "\033[4;30m"
# define UL_RED          "\033[4;31m"
# define UL_GREEN        "\033[4;32m"
# define UL_YELLOW       "\033[4;33m"
# define UL_BLUE         "\033[4;34m"
# define UL_PURPLE       "\033[4;35m"
# define UL_CYAN         "\033[4;36m"
# define UL_WHITE        "\033[4;37m"

/* Background colors */
# define BG_BLACK        "\033[40m"
# define BG_RED          "\033[41m"
# define BG_GREEN        "\033[42m"
# define BG_YELLOW       "\033[43m"
# define BG_BLUE         "\033[44m"
# define BG_PURPLE       "\033[45m"
# define BG_CYAN         "\033[46m"
# define BG_WHITE        "\033[47m"

/* Reset color */
# define RESET           "\033[0m"

#endif