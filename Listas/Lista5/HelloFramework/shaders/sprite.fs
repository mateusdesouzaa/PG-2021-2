#version 400 core
in vec4 ourColor;
in vec2 TexCoord;

out vec4 color;

// pixels da textura
uniform sampler2D tex1;

uniform vec4 corColorizadora;

void main()
{
    color = texture(tex1, TexCoord);

    //Exercício Lista 5 1 a)
    // Manter apenas a info do canal R
    //color.g = color.r;
    //color.b = color.r;

    //Exercicio 1 b)
    //float media = color.r * 0.2125 + color.g * 0.7154 + color.b * 0.0721;
    //color.r = media;
    //color.g = media;
    //color.b = media;

    //Exercicio 1 c)
    //color = color + corColorizadora;

}
