/**
 * \file PenHandler.h
 *
 * \author Amanuel
 *
 * 
 */

#pragma once
#include <memory>

class CGame;
class CRedPen;

/**
 * class implementing pen handler and emitter
 */
class CPenHandler
{
	public:
		/// constructor
		CPenHandler(CGame* game, double xLocation, double yLocation);

		/// default constructor disabled
		CPenHandler() = delete;

		/// default copy constructor disabled
		CPenHandler(const CPenHandler&) = delete;

		/// Load/Reload pen 
		void LoadPen() {};

		/// fire pen
		void FirePen(double mouseX, double mouseY);
		/// set pen angle
		void OnMouseMove(double angle);
		///onHand bool
		bool OnHand();

	private:
		/// pen image
		std::shared_ptr<Gdiplus::Bitmap> mPenImage;
		/// pen ownded by the handler
		std::shared_ptr<CRedPen> mPen;
		/// game member variable
		CGame* mGame;
		
};

