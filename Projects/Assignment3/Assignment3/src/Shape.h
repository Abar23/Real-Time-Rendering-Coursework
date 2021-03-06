#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "GLM\glm.hpp"
#include "Mesh.h"

class Shape
{
public:
	/**
	 * Creates the mesh of the geometry that the vertices and indices define
	 * @param vertices
	 *		Vector of mesh vertices
	 * @param indices
	 *		Vector of indices
	 */
	Shape(std::vector<MeshVertex> vertices, std::vector<unsigned int> indices);

	virtual ~Shape();

	/**
	 * Draws the shape
	 * @param wireFrame
	 *		A boolean that determines whether the shape is drawn as a wire frame
	 *		or filled. True for wire fram and false for fill.
	 */
	void Draw(bool wireFrame);

	/**
	 * Set the model matrix of the shape
	 */
	glm::mat4 GetModelMatrix();

	/**
	 * Set the model matrix to the passed in matrix
	 * @param matrix
	 *		Pointer to the new matrix
	 */
	void SetModelMatrix(glm::mat4 *matrix);

	/**
	 * Sets the scale of the shape
	 * @param scale
	 *		Pointer to the scale vecotr
	 */
	void SetScale(glm::vec3 *scale);

	/**
	 * Apply global rotation to the shapes model matrix
	 * @param matrix
	 *		Pointer that contains rotational matrix to apply to the shape
	 */
	void RotateModelMatrixGlobally(glm::mat4 *matrix);

	/**
	 * Apply tranform matrix to shapes model matrix
	 * @param matrix
	 *		Pointer that contains tranform to apply to model matrix
	 */
	void UpdateModelMatrix(glm::mat4 *matrix);

	/**
	 * Returns the global rotational matrix that is being applied to the shapes model matrix
	 */
	glm::mat4 GetGlobalRotationMatrix();

	/**
	 * Set the x and z position of the shape
	 * @param position
	 *		Vector that contains the new x and z position for the shape
	 */
	void SetPositionXAndZPosition(glm::vec3 position);

protected:
	Mesh *mesh;
	glm::mat4 modelMatrix;
	glm::mat4 globalRotationMatrix;
};

#endif //SHAPE_H