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
 
float specularStrength = 2.0f;

void main()
{
	//FragColor = mix(texture(texture1, TexCoords),texture(texture2, TexCoords),0);
	float ambientStrength=0.1;
	vec3 ambColor=ambientStrength*lightColor;
	//vec3 norm = normalize(Normal);
	//vec3 norm ={-0.6,0.9,-0.6};
	vec3 norm =7.5*Normal;
	vec3 lightDir = normalize(lightPos - FragPos);  
	float diff = max(dot(norm, lightDir), 0.4);
	vec3 diffuse = diff * lightColor;
	vec3 viewDir = normalize(cameraPos-FragPos);
	vec3 reflectDir = reflect(-lightDir , norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrength * spec * lightColor; 
	vec3 change =(abs(FragPos.y))* objectColor;
	
	vec3 result=(ambColor+diffuse+specular)*objectColor;
	FragColor = vec4(result, 1.0f);
//	if(FragPos.y<0.0f){
//	FragColor = vec4(result, 1.0f);
//	}
//	else{
//	FragColor = vec4(result, 1.0f);
//	}
	
}