*This project has been created as part of the 42 curriculum by hammeah*

<font size="5">Description</font>

The goal of this project is to create beautiful Mandelbrot and Julia's fractol using the MiniLibX API.
The library included basic necessary tools to open a window, create image and deal wih keyboard and mouse events.

Fractals are mathematical sets that exhibit a repeating pattern at every scale.  
The **Mandelbrot set** is defined in the complex plane where the point c is include in the function Fc(z) = z² + c

We start with : Z(o) = 0
and we iterate with Z(n + 1) = Z²(n) + c

The **Julia set** is also defined with the same formula

<font size="5">Instruction</font>

You can launch the program with the following command for the Mandelbrot set :

**1 - cd fractol/**

**2 - make** 

**3 - ./fractol mandelbrot**


| Keys/Mouse    | Description |
| ---------- | ------- |
|    ▲       | Move up the fractol    |
|    ▼       | Move down the fractol  |
|    ◄       | Move left the fractol  |
|    ►       | Move right the fractol |
|    +       | Increase the iteration nb |
|    -       | Decrease the iteration nb |
|  Sroll up  | zomm    |
|  Sroll down| unzoom  |


<font size="5">Ressources</font>

https://www.youtube.com/watch?v=ANLW1zYbLcs&list=PLdqJJidIgFEgvD5_TztJKklaHxMDtoHfL

https://fr.wikipedia.org/wiki/Ensemble_de_Mandelbrot

https://complexe.jimdofree.com/des-fractales-2d-g%C3%A9n%C3%A9r%C3%A9es-informatiquement-gr%C3%A2ce-au-logiciel-xaos/l-ensemble-de-julia/

AI was use for debbuging problem and generated the color defines in C.