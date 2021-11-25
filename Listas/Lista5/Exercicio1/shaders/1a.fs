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

    //Exercício 1a da Lista 5
    color.g = color.r;
    color.b = color.r;

}
