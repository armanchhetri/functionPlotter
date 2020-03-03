#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
//layout (location = 1) in vec3 aColor;
//layout (location = 2) in vec2 aTexCoords;

//out vec3 ourColor;
//out vec2 TexCoords;
out vec3 Normal;
out vec3 FragPos;
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	gl_Position = proj*view*model * vec4(aPos, 1.0f);
	//gl_Position = vec4(aPos, 1.0f);
	//ourColor = aColor;
	//TexCoords= aTexCoords;
	FragPos = vec3(model * vec4(aPos, 1.0));
	//Normal = mat3(transpose(inverse(model))) * aNormal;  
	Normal = aNormal;  

}