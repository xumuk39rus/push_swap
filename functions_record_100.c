/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_record.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:42:46 by jbashiri          #+#    #+#             */
/*   Updated: 2019/04/01 11:42:48 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	create_go_to_stack_a_part_three(t_union *var, int pos,
	int flag, int *pos_y)
{
	while (pos > 0)
	{
		if (pos == 1)
		{
			sb(var);
			pos--;
			continue ;
		}
		flag = 1;
		if (pos > 1)
			*pos_y = record_push_aplus(var, *pos_y, &pos, &flag);
		if (pos-- > 0)
		{
			if (flag == 100)
				rr(var);
			else
				rb(var);
		}
	}
	pa(var);
	return (1);
}

static int	create_go_to_stack_a_part_four(t_union *var, int pos,
	int flag, int *pos_y)
{
	pos = var->size_b - pos;
	while (pos > 0)
	{
		if (pos > 1)
			*pos_y = record_push_aplus(var, *pos_y, &pos, &flag);
		rrb(var);
		pos--;
	}
	pa(var);
	return (1);
}

static int	create_go_to_stack_a_part_two(t_union *var, int *pos_y)
{
	int		num;
	int		pos;
	int		flag;

	num = var->res[while_search_num_pos(var->res, var->size, var->a[0]) - 1];
	if (while_search(var->a, var->size_a, num))
		rra(var);
	else if (while_search(var->b, var->size_b, num))
	{
		pos = while_search_num_pos(var->b, var->size_b, num);
		flag = 0;
		if (var->size_b / 2 > pos)
			return (create_go_to_stack_a_part_three(var, pos, flag, pos_y));
		else
			return (create_go_to_stack_a_part_four(var, pos, flag, pos_y));
	}
	return (0);
}

static void	create_go_to_stack_a_part_five(t_union *var)
{
	if (var->a[0] > var->a[1])
		ss(var);
	else
		sb(var);
	pa(var);
}

void		create_go_to_stack_a(t_union *var)
{
	int		x;
	int		pos_y;
	int		size;

	x = 0;
	pos_y = 0;
	create_stack_res_a(var);
	size = last_med(var, 1) - 1;
	while (check_result_stack_a(var))
	{
		if (x <= size && var->b[0] == var->res[
			while_search_num_pos(var->res, var->size, var->a[0]) - 1])
		{
			pa(var);
			x++;
			continue ;
		}
		else if (x <= size && var->b[1] == var->res[
			while_search_num_pos(var->res, var->size, var->a[0]) - 1])
			create_go_to_stack_a_part_five(var);
		if (x <= size)
			x += create_go_to_stack_a_part_two(var, &pos_y);
	}
}
