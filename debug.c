/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:05:52 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 18:05:59 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void ft_putmap(t_vector ***map)
{
    static int x;
    static int y;

    y = 0;
    while (map[y])
    {
        printf("Looping\n");
        x = 0;
        while (map[y][x])
        {
            if (map[y][x]->exist)
                printf("%i ", (int)map[y][x]->z);
            else
                printf(". ");
            x++;
        }
        printf("\n");
        y++;
    }
}

void ft_putmap2(t_vector ***map)
{
    int x;
    int y;

    y = 0;
    while (map[y])
    {
        printf("Looping\n");
        x = 0;
        while (map[y][x])
        {
            printf("Point %ix%i %s: X = %i, Y = %i, Z %i\n", y, x, (map[y][x]->exist == 1) ? "exist" : "doesn't exist", (int)map[y][x]->x, (int)map[y][x]->y, (int)map[y][x]->z);
            x++;
        }
        y++;
    }
}

void ft_checkmap(t_vector ***map)
{
    int x;
    int y;

    y = 0;
    while (map[y] && y < 1)
    {
        x = 0;
        while (map[y][x] && x < 1)
        {
            if (map[y][x]->exist)
                printf("%i ", (int)map[y][x]->z);
            else
                printf(". ");
            x++;
        }
        printf("\n");
        y++;
    }
}

void    ft_putmatrix(t_matrix m)
{
    printf("%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n\n", m.a , m.b , m.c , m.d , m.e , m.f , m.g , m.h , m.i , m.j , m.k , m.l , m.m , m.n , m.o , m.p);
}

void    ft_putvector(t_vector v)
{
    printf("%f %f %f %f\n", v.x, v.y, v.z, v.p);
}

void ft_putentities(t_entity *begin)
{
    static int i;

    i = 0;
    while (begin)
    {
        if (begin->size == 3)
        {
            printf("The element %i is a triangle, composed of three points :\n", i);
            printf("            Point A : X = %f, Y = %f, Z = %f\n", begin->a->x, begin->a->y, begin->a->z);
            printf("            Point B : X = %f, Y = %f, Z = %f\n", begin->b->x, begin->b->y, begin->b->z);
            printf("            Point C : X = %f, Y = %f, Z = %f\n\n", begin->c->x, begin->c->y, begin->c->z);
        }
        i++;
        begin = begin->next;
    }
}