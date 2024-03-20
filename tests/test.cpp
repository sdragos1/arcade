/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(nothing, nothing)
{
    std::string de = "test";
    cr_assert_str_eq(de.c_str(), "test");
}
