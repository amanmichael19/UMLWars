/**
 * \file XMLReader.cpp
 *
 * \author Daniel Anderson
 */

#include "pch.h"
#include "XMLReader.h"

using namespace std;
using namespace xmlnode;

/// Name of file containing UML information
wstring filename = L"images/data/uml.xml";

/**
 * Loads the UML Data from the XML file
 */
void CXMLReader::Load()
{
	try
	{
		// Open the document to read
		shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

		// Once we know it is open, read data

		//
		// Traverse the children of the root
		// node of the XML document in memory!!!!
		//
		for (auto node : root->GetChildren())
		{
			// Loads the class data
			if (node->GetType() == NODE_ELEMENT && node->GetName() == L"class")
			{
				LoadClasses(node);
			}

			// Loads the inheritance data
			else if (node->GetType() == NODE_ELEMENT && node->GetName() == L"inheritance")
			{
				LoadInheritance(node);
			}

		}

	}
	catch (CXmlNode::Exception ex)
	{
		AfxMessageBox(ex.Message().c_str());
	}
}

/**
 * Loads UML class information from XML file
 * \param parentNode The "class" node in the XML file
 */
void CXMLReader::LoadClasses(const shared_ptr<CXmlNode>& parentNode)
{
	for (auto node : parentNode->GetChildren())
	{
		// Get the info on if name is bad
		auto bad = node->GetAttributeValue(L"bad", L"");

		// Loads names
		if (node->GetType() == NODE_ELEMENT && node->GetName() == L"name")
		{
			
			// Name is good
			if (bad == L"")
			{
				mNames.push_back(node->GetChild(0)->GetValue());
			}

			// Name is bad
			else
			{
				//Vector to be pushed back
				vector<wstring> badVector;

				// General case
				if (node->GetNumChildren() == 1)
				{
					badVector.push_back(node->GetChild(0)->GetValue());
				}

				// Edge case of missing name
				else
				{
					badVector.push_back(L"");
				}

				// Pushback reason why name is bad
				badVector.push_back(bad);

				// Pushback vector to member
				mBadNames.push_back(badVector);
			}

			continue;
		}

		// Loads attributes
		if (node->GetType() == NODE_ELEMENT && node->GetName() == L"attribute")
		{

			// Attribute is good
			if (bad == L"")
			{
				mAttributes.push_back(node->GetChild(0)->GetValue());
			}

			// Attribute is bad
			else
			{
				//Vector to be pushed back
				vector<wstring> badVector;

				// Pushback bad attribute
				badVector.push_back(node->GetChild(0)->GetValue());

				// Pushback reason why attribute is bad
				badVector.push_back(bad);

				// Pushback vector to member
				mBadAttributes.push_back(badVector);
			}

			continue;
		}

		// Loads operations
		if (node->GetType() == NODE_ELEMENT && node->GetName() == L"operation")
		{

			// Operation is good
			if (bad == L"")
			{
				mOperations.push_back(node->GetChild(0)->GetValue());
			}

			// Operation is bad
			else
			{
				//Vector to be pushed back
				vector<wstring> badVector;

				// Pushback bad attribute
				badVector.push_back(node->GetChild(0)->GetValue());

				// Pushback reason why attribute is bad
				badVector.push_back(bad);

				// Pushback vector to member
				mBadOperations.push_back(badVector);
			}

			continue;
		}
	}
}

/**
 * Loads UML inheritance information from XML file
 * \param parentNode The "inheritance" node in the XML file
 */
void CXMLReader::LoadInheritance(const shared_ptr<CXmlNode>& parentNode)
{
	for (auto node : parentNode->GetChildren())
	{
		// Get the info on if name is bad
		auto bad = node->GetAttributeValue(L"bad", L"");

		vector<wstring> inherit;

		// Loads inherits
		if (node->GetType() == NODE_ELEMENT && node->GetName() == L"inherit")
		{

			// Pushback base class
			inherit.push_back(node->GetAttributeValue(L"base", L""));

			// Pushback derived class
			inherit.push_back(node->GetAttributeValue(L"derived", L""));

			// Pushback direction, defaults to down
			inherit.push_back(node->GetAttributeValue(L"direction", L"up"));

			// Operation is good
			if (bad == L"")
			{
				// Pushback valid inherit
				mInherits.push_back(inherit);
			}

			// Operation is bad
			else
			{
				// Pushback bad reason
				inherit.push_back(bad);

				// Pushback invalid inherit
				mBadInherits.push_back(inherit);
			}

			continue;
		}
	}
}
