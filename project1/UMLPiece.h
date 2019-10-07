/**
 * \file UMLPiece.h
 *
 * \author Daniel Anderson
 *
 * Class that describes a single class of UML
 */

#pragma once
#include <vector>
#include <string>

/**
 * Class that descibes a single UML class object
 */
class CUMLPiece
{
public:
	/// Setter for mBad
	/// \param bad The new value for mBad
	void SetBad(std::wstring bad) { mBad = bad; }

	/// Getter for mBad
	/// \returns The current vlaue of mBad
	std::wstring GetBad() { return mBad; }

private:
	std::wstring mBad; ///< The reason, if any, why this UMLPiece is bad
	std::wstring mName; ///< The class name of this UMLPiece
	std::vector<std::wstring> mAttributes; ///< The attributes this UMLPiece has, if any
	std::vector<std::wstring> mOperations; ///< The operations this UMLPiece has, if any
};

