void main()
{
	float shift=1.0;
//	float tmp=gl_Vertex.x/2;
	if(mod(gl_Vertex.x,2.0)==0.0)
		shift=gl_Vertex.x/2.0;
//	if(gl_Vertex.x>gl_Vertex.y)
//		shift=-1;

	float at=atan(gl_Vertex.x/gl_Vertex.y);
	gl_Position=vec4(gl_Vertex.x,gl_Vertex.y*sin(at),gl_Vertex.zw);
	gl_Position=gl_ModelViewProjectionMatrix*gl_Position;

	gl_FrontColor=vec4(sin(gl_Position.x),sin(gl_Position.y),sin(gl_Position.z),1.0);
	gl_BackColor=vec4(1.0,1.0,1.0,1.0)-gl_Color;
}
