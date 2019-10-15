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
		CPenHandler(CGame* game, double xlocaton, double ylocation);

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

	private:
		/// pen image
		std::shared_ptr<Gdiplus::Bitmap> mPenImage;
		/// pen ownded by the handler
		std::shared_ptr<CRedPen> mPen;
		/// game member variable
		CGame* mGame;
		/// the x center of the player to be used as origin for pen
		double mXOrigin = 0.0;
		/// the y center of the player to be used as origin for pen
		double mYOrigin = 0.0;
		/// initial load x location
		double mLoadX = 0.0;
		/// initial load y location
		double mLoadY = 0.0;
		/// offset x from player image center
		const double mXOffset = 29.0;
		/// offset y from player image center
		const double mYOffset = 54.0;
		/// boolean to indicate pen on hand
		bool mOnHand = true;


};

