#version 400 core
in vec4 ourColor;
in vec2 TexCoord;

out vec4 color;

// pixels da textura
uniform sampler2D tex1;
uniform sampler2D tex2;

uniform vec4 corColorizadora;

void main()
{
    //O comando texture é da própria GLSL, e busca a cor do fragmento com a coord de 
    //textura fornecida
    color = texture(tex1, TexCoord);

    vec4 colorMask = texture(tex2, TexCoord);

    // 1g) - Efeito Vignette
    color = mix(color, colorMask, colorMask.a);
    color = vec4(color.rgb, 1.0);
}
