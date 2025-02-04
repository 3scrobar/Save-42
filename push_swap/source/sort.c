

#include "push_swap.h"

void    sort_two(t_swap *lst)
{
    if (lst->value > lst->chain->value)
        sa(lst);
}

void    sort_three_lsta(t_swap *lst)
{
    int first;
    int second;
    int third;

    first = lst->value;
    second = lst->chain->value;
    third = lst->chain->chain->value;
    if (first > second && first > third)
        ra(lst);
    else if (first < second && first > third)
        rra(lst);
    else if (first < second && first < third && second > third)
        sa(lst);
}

void    sort_three_lstb(t_swap *lst)
{
    int first;
    int second;
    int third;

    first = lst->value;
    second = lst->chain->value;
    third = lst->chain->chain->value;
    if (first > second && first > third)
        rb(lst);
    else if (first < second && first > third)
        rrb(lst);
    else if (first < second && first < third && second > third)
        sb(lst);
}
