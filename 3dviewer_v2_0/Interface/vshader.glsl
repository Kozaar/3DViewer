#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

uniform mat4 mvp_matrix;

attribute vec4 a_position;
attribute vec4 a_texcoord;

varying vec4 v_texcoord;

void main()
{
    gl_Position = mvp_matrix * a_position;

    v_texcoord = a_texcoord;
}
