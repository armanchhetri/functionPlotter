#version 330 core
out vec4 FragColor;
//in vec3 ourColor;
//in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;
//uniform sampler2D texture1;
//uniform sampler2D texture2;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 cameraPos;
 
float specularStrength = 10.0f;

void main()
{
	//FragColor = mix(texture(texture1, TexCoords),texture(texture2, TexCoords),0);
	float ambientStrength=0.1;
	vec3 ambColor=ambientStrength*lightColor;
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);  

	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	vec3 viewDir = normalize(cameraPos-FragPos);
	vec3 reflectDir = reflect(-lightDir , norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrength * spec * lightColor; 
	vec3 result=(specular+ambColor+diffuse)*objectColor;
	FragColor = vec4(objectColor, 1.0f);
}