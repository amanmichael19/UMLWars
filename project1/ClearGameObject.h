/**
 * \file ClearGameObject.h
 *
 * \author Funakoshi Silva
 *
 * 
 */


#pragma once
#include "GameObject.h"
#include <vector>
#include <string>
#include <memory>
#include "UMLPiece.h"

class CClearGameObject : public	CGameObject
{
public:

	/// ClearGameObject constructor
		/// \param game
	CClearGameObject(CGame* game);


	/// default constructor disabled
		CClearGameObject() = delete;

	/// default copy constructor disabled
		CClearGameObject(const CClearGameObject&) = delete;

		/// to clear object after left the screen
		void clear(CUMLPiece m, CGame* game);

	





};

