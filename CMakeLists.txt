cmake_minimum_required(VERSION 3.15)
project(fdf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(libft)
#include_directories(minilibx)
include_directories(minilibx_macos)
#include_directories(minilibx_mms_20191025_beta)


add_executable(fdf
        libft/bonus.c
        libft/ft_atoi.c
        libft/ft_atoiar.c
        libft/ft_bzero.c
        libft/ft_cleanmem.c
        libft/ft_degree.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_itoa2.c
        libft/ft_lenint.c
        libft/ft_lenint2.c
        libft/ft_lstadd.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_mod.c
        libft/ft_mult2.c
        libft/ft_multi.c
        libft/ft_printf.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_revers.c
        libft/ft_root.c
        libft/ft_splitt.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcount.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdow.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strjoin1.c
        libft/ft_strjoin2.c
        libft/ft_strjoin3.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strlen2.c
        libft/ft_strlen3.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strndup.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_strup.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/ft_unletter.c
        libft/get_next_line.c
        libft/libft.h
        libft/obr.c
        libft/obr2.c
        libft/obr3.c
        libft/tip_f.c
        libft/tip_ff.c
        libft/tip_i_d.c
        libft/tip_o.c
        libft/tip_p.c
        libft/tip_s_c.c
        libft/tip_u.c
        libft/tip_x.c
        minilibx_macos/libmlx.a

#        minilibx/test/main.c
#        minilibx/test/new_win.c
#        minilibx/mlx.h
#        minilibx/mlx_clear_window.c
#        minilibx/mlx_destroy_image.c
#        minilibx/mlx_destroy_window.c
#        minilibx/mlx_expose_hook.c
#        minilibx/mlx_flush_event.c
#        minilibx/mlx_get_color_value.c
#        minilibx/mlx_get_data_addr.c
#        minilibx/mlx_hook.c
#        minilibx/mlx_init.c
#        minilibx/mlx_int.h
#        minilibx/mlx_int_anti_resize_win.c
#        minilibx/mlx_int_do_nothing.c
#        minilibx/mlx_int_get_visual.c
#        minilibx/mlx_int_param_event.c
#        minilibx/mlx_int_set_win_event_mask.c
#        minilibx/mlx_int_str_to_wordtab.c
#        minilibx/mlx_int_wait_first_expose.c
#        minilibx/mlx_key_hook.c
#        minilibx/mlx_lib_xpm.c
#        minilibx/mlx_loop.c
#        minilibx/mlx_loop_hook.c
#        minilibx/mlx_mouse_hook.c
#        minilibx/mlx_new_image.c
#        minilibx/mlx_new_window.c
#        minilibx/mlx_pixel_put.c
#        minilibx/mlx_put_image_to_window.c
#        minilibx/mlx_rgb.c
#        minilibx/mlx_string_put.c
#        minilibx/mlx_xpm.c
#        minilibx_macos/font.c
#        minilibx_macos/mlx.h
#        minilibx_macos/mlx_init_loop.m
#        minilibx_macos/mlx_int.h
#        minilibx_macos/mlx_int_str_to_wordtab.c
#        minilibx_macos/mlx_new_image.m
#        minilibx_macos/mlx_new_window.h
#        minilibx_macos/mlx_new_window.m
#        minilibx_macos/mlx_rgb.c
#        minilibx_macos/mlx_shaders.c
#        minilibx_macos/mlx_xpm.c
#        minilibx_mms_20191025_beta/font.c
#        minilibx_mms_20191025_beta/mlx.h
#        minilibx_mms_20191025_beta/mlx_png.c
#        minilibx_mms_20191025_beta/mlx_rgb.c
#        minilibx_mms_20191025_beta/mlx_string_put.c
#        minilibx_mms_20191025_beta/mlx_xpm.c
        fdf.c
        fdf.h
        ft_cw.c
        main.c)
