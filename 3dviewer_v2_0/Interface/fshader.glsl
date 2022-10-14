#ifdef GL_ES
precision mediump int;
precision mediump float;
#endif

varying vec4 v_texcoord;

uniform vec4 a_texcoord;

uniform bool isDotsDraw;

void main()
{
    if (!isDotsDraw) {
        gl_FragColor = v_texcoord;
    } else {
        gl_FragColor = a_texcoord;
    }
}
