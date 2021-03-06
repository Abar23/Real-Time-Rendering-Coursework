#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include "GLM\glm.hpp"
#include "Shape.h"
#include "Mesh.h"
#include "Texture.h"

#define NUM_FACES 6

class Cube : public Shape
{
public:
	/**
	 * Creates a cube primitive
	 * @param faceSubdivisions
	 *		Triagulates each face into an nxn grid
	 * @param position
	 *		The initial position of the object
	 */
	Cube(unsigned int faceSubdivisions, glm::vec3 position);
	
	~Cube();

	/**
	 * Render the cube using the same texture for all faces
	 * @param texture
	 *		Pointer to the desired texture to be drawn on the cube
	 * @param shader
	 *		Pointer to the active shader
	 */
	void DrawCubeWithTexture(Texture *texture, Shader *shader);


	/**
	 * Render the cube using the same texture for all faces
	 * @param texture
	 *		Pointer to the desired texture to be drawn on the cube
	 * @param shader
	 *		Pointer to the active shader
	 */
	void DrawCubeWithTextureArray(std::vector<Texture *> textures, Shader *shader);

private:
	/**
	 * Sets all vertices of each face that comprises the cube
	 * @param faceSubdivisions
	 *		Triagulates each face into an nxn grid
	 * @param color
	 *		The color of the object
	 */
	static std::vector<MeshVertex> SetAllFaceVertices(unsigned int faceSubdivisions);

	/**
	 * Sets all indices of each face that comprises the cube
	 * @param faceSubdivisions
	 *		Triagulates each face into an nxn grid
	 */
	static std::vector<unsigned int> SetAllFaceIndices(unsigned int faceSubdivisions);

	/**
	 * Generates the vertices of a single face based upon the 
	 * face subdivisions, the starting point of the face, and 
	 * two vector directions that indicate how the face should
	 * be constructed
	 * @param vertices
	 *		A pointer to the vector object storing the vertices of the cube
	 * @param vertices
	 *		A pointer to the vector object storing the vertices of the cube
	 * @param x
	 *		The x position of the face
	 * @param y
	 *		The y position of the face
	 * @param z
	 *		The z position of the face
	 * @param xDirectionOuter
	 *		The x direction for the outer vector that controls column vertices
	 * @param yDirectionOuter
	 *		The y direction for the outer vector that controls column vertices
	 * @param zDirectionOuter
	 *		The z direction for the outer vector that controls column vertices
	 * @param xDirectionInner
	 *		The x direction for the outer vector that controls row vertices
	 * @param yDirectionInner
	 *		The y direction for the outer vector that controls row vertices
	 * @param zDirectionInner
	 *		The z direction for the outer vector that controls row vertices
	 * @param faceSubdivisions
	 *		Triagulates each face into an nxn grid
	 */
	static void CreateFaceVertices(
		std::vector<MeshVertex> *vertices, 
		float x, float y, float z,
		float xDirectionOuter, float yDirectionOuter, float zDirectionOuter,
		float xDirectionInner, float yDirectionInner, float zDirectionInner, 
		unsigned int faceSubdivisions);
};

#endif //CUBE_H