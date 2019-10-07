/**
 * \file UMLPieceEmitter.h
 *
 * \author Daniel Anderson
 *
 * Class that creates and emits new UMLPieces into the game area
 */

#pragma once
#include "XMLReader.h"
#include "UMLPiece.h"
#include "Game.h"

/**
 * Class that emits UMLPieces
 */
class CUMLPieceEmitter
{
public:
	CUMLPieceEmitter();

	std::shared_ptr<CUMLPiece> CreateUMLPiece();
	//void CreateInheritedUMLPiece();

private:
	std::vector<std::shared_ptr<CUMLName>> mNames; ///< Vector containing valid class names
	std::vector<std::shared_ptr<CUMLName>> mBadNames; ///< Vector containing invalid class names with reasons

	std::vector<std::shared_ptr<CUMLAttribute>> mAttributes; ///< Vector containing valid class attributes
	std::vector<std::shared_ptr<CUMLAttribute>> mBadAttributes; ///< Vector containing invalid class attributes with reasons

	std::vector<std::shared_ptr<CUMLOperation>> mOperations; ///< Vector containing valid class operations
	std::vector<std::shared_ptr<CUMLOperation>> mBadOperations; ///< Vector containing invalid class operations with reasons

	std::vector<std::shared_ptr<CUMLInheritance>> mInherits; ///< Vector containing valid inherits
	std::vector<std::shared_ptr<CUMLInheritance>> mBadInherits; ///< Vector containing invalid inherits with reasons

	std::shared_ptr<CGame> mGame; ///< The game this emitter is part of

	int mHandicap = 5; ///< The rate that the amount of bad UML is artificially increased
	int mTotalEmitted = 0; ///< The total number of UMLPieces that have been emitted this game
};

