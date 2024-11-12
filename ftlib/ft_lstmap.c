/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle_saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:01:34 by tle_saut          #+#    #+#             */
/*   Updated: 2024/11/12 19:11:38 by tle_saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_lst = NULL; // Nouvelle liste chaînée (résultat)
    t_list *new_node = NULL; // Nouveau nœud à ajouter dans la nouvelle liste
    t_list *temp = lst; // Pointeur pour parcourir la liste d'origine

    // Parcourir toute la liste d'origine
    while (temp != NULL)
    {
        // Créer un nouveau nœud
        new_node = malloc(sizeof(t_list));
        if (new_node == NULL) // Si l'allocation échoue
        {
            // Si un nœud ne peut pas être alloué, on libère la mémoire de la nouvelle liste déjà créée
            while (new_lst != NULL)
            {
                temp = new_lst->next;
                del(new_lst->content); // Appel de del pour libérer les données du nœud
                free(new_lst); // Libération du nœud
                new_lst = temp;
            }
            return NULL; // Retourner NULL en cas d'erreur d'allocation
        }

        // Appliquer la fonction f sur le contenu du nœud
        new_node->content = f(temp->content);
        new_node->next = NULL;

        // Ajouter le nouveau nœud à la nouvelle liste
        if (new_lst == NULL)
            new_lst = new_node; // Si la liste est vide, le premier élément devient la tête
        else
        {
            t_list *last = new_lst;
            while (last->next != NULL)
                last = last->next;
            last->next = new_node; // Ajouter le nœud à la fin de la nouvelle liste
        }

        // Passer au nœud suivant de la liste d'origine
        temp = temp->next;
    }

    return new_lst; // Retourner la nouvelle liste
}
