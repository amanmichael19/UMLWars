/**
 * \file XMLReader.h
 *
 * \author Daniel Anderson
 *
 * Class that reads the XML data
 * for the UMLPieces at game start
 */

#pragma once
#include <memory>
#include "XmlNode.h"
#include <string>
#include <vector>

/**
 * Class that reads the UML's XML data
 */
class CXMLReader
{
public:
	void Load();

	
	///Getter for valid names
	///\returns Vector of valid names
	std::vector<std::wstring> GetNames() { return mNames; };

	///Getter for invalid names
	///\returns Vector of invalid names
	std::vector<std::vector<std::wstring>> GetBadNames() { return mBadNames; };

	///Getter for valid attributes
	///\returns Vector of valid attributes
	std::vector<std::wstring> GetAttributes() { return mAttributes; };

	/// Getter for invalid attributes
	///\returns Vector of invalid attributes
	std::vector<std::vector<std::wstring>> GetBadAttributes() { return mBadAttributes; };

	/// Getter for valid operations
	///\returns Vector of valid operations
	std::vector<std::wstring> GetOperations() { return mOperations; };

	/// Getter for invalid operations
	///\returns Vector of invalid operations
	std::vector<std::vector<std::wstring>> GetBadOperations() { return mBadOperations; };

	/// Getter for valid inherits
	///\returns Vector of valid inherits
	std::vector<std::vector<std::wstring>> GetInherits() { return mInherits; };

	/// Getter for invalid inherits
	///\returns Vector of invalid inherits
	std::vector<std::vector<std::wstring>> GetBadInherits() { return mBadInherits; };

private:
	void LoadClasses(const std::shared_ptr<xmlnode::CXmlNode>& parentNode);
	void LoadInheritance(const std::shared_ptr<xmlnode::CXmlNode>& parentNode);

	std::vector<std::wstring> mNames; ///< Vector containing valid class names
	std::vector<std::vector<std::wstring>> mBadNames; ///< Vector containing invalid class names with reasons

	std::vector<std::wstring> mAttributes; ///< Vector containing valid class attributes
	std::vector<std::vector<std::wstring>> mBadAttributes; ///< Vector containing invalid class attributes with reasons

	std::vector<std::wstring> mOperations; ///< Vector containing valid class operations
	std::vector<std::vector<std::wstring>> mBadOperations; ///< Vector containing invalid class operations with reasons

	std::vector<std::vector<std::wstring>> mInherits; ///< Vector containing valid inherits
	std::vector<std::vector<std::wstring>> mBadInherits; ///< Vector containing invalid inherits with reasons
};

