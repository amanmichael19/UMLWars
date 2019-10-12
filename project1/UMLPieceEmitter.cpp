/**
 * \file UMLPieceEmitter.cpp
 *
 * \author Daniel Anderson
 */

#include "pch.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "UMLPieceEmitter.h"

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

/// Maximum value for x direction
const double MAX_X = 5;

/// Minimum vlaue for x direction
const double MIN_X = 1;

/// Maximum value for y direction
const double MAX_Y = 5;

/// Minimum value for y direction
const double MIN_Y = 1;

/// First threshold to decrease handicap
const int HANDICAP_THRESHOLD_ONE = 5;

/// Second threshold to decrease handicap
const int HANDICAP_THRESHOLD_TWO = 10;

/// Third threshold to decrease handicap
const int HANDICAP_THRESHOLD_THREE = 15;

/// Fourth threshold to decrease handicap
const int HANDICAP_THRESHOLD_FOUR = 20;

/// Fifth threshold to decrease handicap
const int HANDICAP_THRESHOLD_FIVE = 25;

/**
 * CUMLPieceEmitter Constructor
 * \param game The game this emitter is part of
 */
CUMLPieceEmitter::CUMLPieceEmitter(CGame* game)
{
	// Set mGame based on argument
	mGame = game;

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
 * Emits a new CUMLClass object
 * \returns A smart pointer to the newly created CUMLPiece object
 */
shared_ptr<CUMLPiece> CUMLPieceEmitter::EmitPiece()
{
	// Chance to create inherited instead of class starts at 0%
	// And moves up to 50% over time
	if (((rand() % 10) + mHandicap) < 4)
	{
		// Make inherited
		return EmitInherited();
	}
	
	// Prepare direction values
	double x = (rand() / (double)RAND_MAX) * MAX_X + (MAX_X - MIN_X);
	double y = (rand() / (double)RAND_MAX) * MAX_Y + (MAX_Y - MIN_Y);
	double vectorLength = sqrt((x*x + y*y));
	x = x / vectorLength;
	y = y / vectorLength;

	// Create new CUMLClass object
	shared_ptr<CUMLClass> newPiece = make_shared<CUMLClass>(mGame,x,y,mPieceSpeed);

	// Create UMLDisplay for Class object
	shared_ptr<CUMLDisplay> newDisplay = make_shared<CUMLDisplay>();

	int numAttributes; // Number of attributes to add to display
	int numOperations; // Number of operations to add to display

	// Decide if new UML object is bad or not, starts at 100% bad, goes to 50% as time progresses
	// Increases probability in 10% increments
	if (((rand() % 10) + mHandicap) > 4)
	{
		// Make bad UML
		int badValue = rand() % 3;
		int badIndex;

		switch (badValue)
		{
			case 0: // Bad Name
				badIndex = rand() % (mBadNames.size());

				// Set bad name and bad
				newDisplay->SetName(mBadNames[badIndex]->GetName());
				newPiece->SetBad(mBadNames[badIndex]->GetBad());

				// Decide number of attributes and operations to add
				numAttributes = rand() % 4;
				numOperations = rand() % 4;
				
				// Finish creating display
				CreateDisplay(newDisplay,false,numAttributes,numOperations);

				break;

			case 1: // Bad Attribute
				badIndex = rand() % (mBadAttributes.size());

				// Set bad attribute and bad
				newDisplay->AddAttribute(mBadAttributes[badIndex]->GetAttribute());
				newPiece->SetBad(mBadAttributes[badIndex]->GetBad());

				// Decide number of additional attributes and operations to add
				numAttributes = rand() % 3;
				numOperations = rand() % 4;

				// Finish creating display
				CreateDisplay(newDisplay, false, numAttributes, numOperations);

				break;

			case 2: // Bad Operation
				badIndex = rand() % (mBadOperations.size());

				// Set bad operation and bad
				newDisplay->AddOperation(mBadOperations[badIndex]->GetOperation());
				newPiece->SetBad(mBadOperations[badIndex]->GetBad());

				// Decide number of attributes and additional operations to add
				numAttributes = rand() % 4;
				numOperations = rand() % 3;

				// Finish creating display
				CreateDisplay(newDisplay, false, numAttributes, numOperations);

				break;
		}
	}

	else
	{
		numAttributes = rand() % 4;
		numOperations = rand() % 4;

		CreateDisplay(newDisplay, true, numAttributes, numOperations);
	}

	// Set CUMLClass object's display value to new CUMLDisplay object
	newPiece->SetDisplay(newDisplay);

	// Increment the counter for total UMLPieces emitted
	IncrementEmitted();

	return newPiece;
}

/**
 * Creates the contents of a CUMLDisplay object
 * \param display The CUMLDisplay object being finished
 * \param name True if name needs to be set
 * \param attributes Number of attributes to add
 * \param operations Number of Operations to add
 */
void CUMLPieceEmitter::CreateDisplay(shared_ptr<CUMLDisplay> display, bool name, int attributes, int operations)
{
	// Set name if needed
	if (name)
	{
		display->SetName(mNames[rand() % mNames.size()]->GetName());
	}

	// Set attributes if needed
	if (attributes > 0)
	{
		// Shuffle Attributes
		random_shuffle(mAttributes.begin(), mAttributes.end());

		// Add attributes
		for (int i = 0; i < attributes; i++)
		{
			display->AddAttribute(mAttributes[i]->GetAttribute());
		}
	}

	//Set operations if needed
	if (operations > 0)
	{
		// Shuffle Operations
		random_shuffle(mOperations.begin(), mOperations.end());

		// Add attributes
		for (int i = 0; i < operations; i++)
		{
			display->AddOperation(mOperations[i]->GetOperation());
		}
	}
}

/**
 * Increment Emitted counter and update handicap if needed
 */
void CUMLPieceEmitter::IncrementEmitted()
{
	// Increment total emitted counter
	mTotalEmitted++;

	// Decrease handicap at various point thresholds
	switch (mTotalEmitted)
	{
		case HANDICAP_THRESHOLD_ONE:
			mHandicap--;
			break;
		
		case HANDICAP_THRESHOLD_TWO:
			mHandicap--;
			break;
		
		case HANDICAP_THRESHOLD_THREE:
			mHandicap--;
			break;
		
		case HANDICAP_THRESHOLD_FOUR:
			mHandicap--;
			break;
		
		case HANDICAP_THRESHOLD_FIVE:
			mHandicap--;
			break;
	}
}

/**
 * Create a CUMLPiece object that has an inheritance relationship
 * \returns A smart pointer to the newly created CUMLInherited Object
 */
shared_ptr<CUMLPiece> CUMLPieceEmitter::EmitInherited()
{

	// Prepare direction values
	double x = (rand() / (double)RAND_MAX) * MAX_X + (MAX_X - MIN_X);
	double y = (rand() / (double)RAND_MAX) * MAX_Y + (MAX_Y - MIN_Y);
	double vectorLength = sqrt((x * x + y * y));
	x = x / vectorLength;
	y = y / vectorLength;

	// Create new CUMLInherited object
	shared_ptr<CUMLInherited> newPiece = make_shared<CUMLInherited>(mGame, x, y, mPieceSpeed);

	// Create UMLDisplay for Base
	shared_ptr<CUMLDisplay> newBase = make_shared<CUMLDisplay>();

	// Create UMLDisplay for Derived
	shared_ptr<CUMLDisplay> newDerived = make_shared<CUMLDisplay>();


	// Decide if new UML object is bad or not, starts at 100% bad, goes to 50% as time progresses
	// Increases probability in 10% increments
	if (((rand() % 10) + mHandicap) > 4) // Make bad UML
	{
		// Select bad Inherit
		int badIndex = rand() % (mBadInherits.size());

		// Set appropriate values
		newPiece->SetBad(mBadInherits[badIndex]->GetBad());
		newPiece->SetArrowDirection(mBadInherits[badIndex]->GetBad());
		newBase->SetName(mBadInherits[badIndex]->GetBase());
		newDerived->SetName(mBadInherits[badIndex]->GetDerived());
	}

	else // Make good UML
	{
		// Select good Inherit
		int goodIndex = rand() % (mInherits.size());

		// Set appropriate values
		newPiece->SetArrowDirection(mInherits[goodIndex]->GetDirection());
		newBase->SetName(mInherits[goodIndex]->GetBase());
		newDerived->SetName(mInherits[goodIndex]->GetDerived());
	}

	// Create Base Display
	int numAttributes = rand() % 4; // Number of attributes to add to display
	int numOperations = rand() % 4; // Number of operations to add to display
	CreateDisplay(newBase, false, numAttributes, numOperations);

	// Create Derived Display 
	numAttributes = rand() % 4;
	numOperations = rand() % 4;
	CreateDisplay(newDerived, false, numAttributes, numOperations);

	// Set displays for new piece
	newPiece->SetBaseDisplay(newBase);
	newPiece->SetDerivedDisplay(newDerived);

	// Increment the total count of pieces emitted
	IncrementEmitted();

	return newPiece;
}
