# miniRT

### Library used
> -lmlx -framework OpenGL -framework AppKit

 &&
 
> minilibx_mms/libmlx.dylib

### how to run 
##### macOS
> $ make re && ./miniRT Scene/.._rt [--save]
##### linux
> make a little change on Makefile.
> change " -lmlx -framework OpenGL -framework AppKit libmlx.dylib " 

by

> " gcc -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit".

and dont forget the mlx_get_screen_size(...) (available only in minilibx_mms/libmlx.dylib)

### Norme 
> $ make norme

#

<p align="center">
  <img src="../images/1" alt="cylinder" title="Screenshot">
</p>

<p align="center">
  <img src="../images/2" alt="first" title="Screenshot">
</p>

<p align="center">
  <img src="../images/3" alt="first" title="Screenshot">
</p>
<p align="center">
  <img src="../images/4" alt="first" title="Screenshot">
</p>
<p align="center">
  <img src="../images/5" alt="first" title="Screenshot">
</p>
<p align="center">
  <img src="../images/6" alt="first" title="Screenshot">
</p>


