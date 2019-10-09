/**
 * \file UMLDisplay.h
 *
 * \author Daniel Anderson
 *
 * Class that displays a single UML class
 */

#pragma once
#include <string>
#include <vector>

/**
 * Class that displays a UML object
 */
class CUMLDisplay
{
public:
	/// Setter for mName
	/// \param name The new value for mName
	void SetName(std::wstring name) { mName = name; }

	/// Getter for mName
	/// \returns The current vlaue of mName
	std::wstring GetName() { return mName; }

	/// Adds attribute to UMLPiece
	/// \param attribute The attribute being added
	void AddAttribute(std::wstring attribute) { mAttributes.push_back(attribute); }

	/// Adds operation to UMLPiece
	/// \param operation The operation being added
	void AddOperation(std::wstring operation) { mOperations.push_back(operation); }

	void Draw(Gdiplus::Graphics* graphics);

	/// TODO: Hit Test

private:
	std::wstring mName; ///< The class name of this UMLPiece
	std::vector<std::wstring> mAttributes; ///< The attributes this UMLPiece has, if any
	std::vector<std::wstring> mOperations; ///< The operations this UMLPiece has, if any
};

