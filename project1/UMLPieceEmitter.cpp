/**
 * \file UMLPieceEmitter.cpp
 *
 * \author Daniel Anderson
 */

#include "pch.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "UMLPieceEmitter.h"

using std::srand;
using std::time;
using std::shared_ptr;
using std::make_shared;

/**
 * CUMLPieceEmitter Constructor
 */
CUMLPieceEmitter::CUMLPieceEmitter()
{
	// Seeds random for emitter
	srand(unsigned(time(0)));

	// Create a XMLReader object and have it load in the UML data
	CXMLReader reader;
	reader.Load();

	// Set member variables based on results of reader's load
	mNames = reader.GetNames();
	mBadNames = reader.GetBadNames();
	mAttributes = reader.GetAttributes();
	mBadAttributes = reader.GetBadAttributes();
	mOperations = reader.GetOperations();
	mBadOperations = reader.GetBadOperations();
	mInherits = reader.GetInherits();
	mBadInherits = reader.GetBadInherits();
}

/**
 * Emits a new CUMLPiece object
 * \returns A smart pointer to the newly created CUMLPiece object
 */
shared_ptr<CUMLPiece> CUMLPieceEmitter::CreateUMLPiece()
{
	// TODO: Decide between creating a new single or inherited UML object
	// CreateInheritedUMLPiece()

	// Create new single UML object
	shared_ptr<CUMLPiece> new_piece = make_shared<CUMLPiece>();

	// Decide if new UML object is bad or not, starts at 100% bad, goes to 50% as time progresses
	// Increases probability in 10% increments
	if (((rand() % 10) + mHandicap) > 4)
	{
		// Make bad UML
		// TODO: Decide which element is going to be 'bad'
	}

	else
	{
		// Make good UML
	}

	// Increment the counter for total UMLPieces emitted
	mTotalEmitted++;

	return new_piece;
}
